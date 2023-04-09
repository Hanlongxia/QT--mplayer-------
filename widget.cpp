#include "widget.h"
#include "ui_widget.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <dirent.h>
#include <signal.h>
#include <QIcon>
#include<list>
#include<cstring>
#include<vector>
#include<algorithm>
#include <QDebug>
class Mplayer
{
public:
    int fd_cmd;
    int fd[2];
    int pause_flag;//暂停状态
    QList<QString> list;
    vector<int> music_num_like; //我喜欢的列表

    //int song_num;//歌曲总数
    int play_cur;//歌单数量索引
    pthread_t pth1, pth2, pth3;//线程，全局
    pthread_mutex_t mutex;
    int flag;//是否切换歌曲的标志位
    int num;//一个普通int变量
    char *str_next[128];//指针数组存储歌曲名-下一首用
    char *str_up[128];//指针数组存储歌曲名-上一首用

    char *buf_time ;//保存当前歌曲实时时间的变量
    char *buf_time2;
    int volume_cur;//音量

    volatile  int pos_t;//获得歌曲文件当前位置时间
    int len_t;//文件总时长
    int mute_flag;//静音开关。1：静音；0：取消静音

    char buf_song_name[128];//播放歌曲并返回歌曲名

    int play_cur_old;//上一首

    Mplayer()
    {
        buf_time = NULL;
        buf_time2=NULL;
        buf_song_name[127] = NULL;
        pause_flag = 0;
        play_cur = 0;
        play_cur_old = -1;
        num = 0;
        str_next[127] = { 0};
        str_up[128]= { 0};
        volume_cur = 0;
        len_t= 0;
        mute_flag= 0;
        pos_t = 0;
        len_t = 0;
        flag=0;

    }
}widget;

struct Mysong
{
    char *song[128];//存放歌曲字段的数组
    int song_num;
    int time_num;
};
Mysong mysong;

class Mysong_list//线程3中检索歌词文件使用的类，包含时间、歌词
{
public:
    int time;
    char *str;
    Mysong_list()
    {
        time = 0;
        str = new char[128]();
    }

    Mysong_list(int num, char *str_lrc)
    {
        this->time = num;
        str = new char[128];
        strcpy(str, str_lrc);
    }

    ~Mysong_list()
    {

    }
};


//-----------------------另外三个文件的类指针，为了给这三个文件发信号--------------------------------//
extern Volume * volume_a = NULL;
extern TableWidget * tablewidget_a = NULL;
extern Song_listTable * song_list = NULL;
extern Like_listwidget * like_list = NULL;


//--------------------------------发送线程命令-发送到命名管道-----------------------------------------------------//
void *send_cb(void *arg)
{    
    widget.pause_flag = 1;//程序运行，进入线程，播放状态，就进行时间获取打印

    while(1)
    {
        if( widget.pause_flag == 1)
        {
            pthread_mutex_lock(&widget.mutex);//上锁,保险起见
            write(widget.fd_cmd, "get_time_length\n", strlen("get_time_length\n"));
            pthread_mutex_unlock(&widget.mutex);//解锁
        }
        usleep(200*1000);                                                   //延时200ms

        if( widget.pause_flag == 1)
        {
            pthread_mutex_lock(&widget.mutex);//上锁,保险起见
            write(widget.fd_cmd, "get_time_pos\n", strlen("get_time_pos\n"));
            pthread_mutex_unlock(&widget.mutex);//解锁
        }
        usleep(200*1000);                                                   //延时200ms

    }
}


//----------------------------------------------发送歌曲时间的线程----------------------------------------------//
void *recv_cb(void *arg)
{

    Widget *p = (Widget*)arg;

    char buf[128] = "";
    while(1)
    {
        memset(buf, 0, sizeof(buf));//重置一下数据缓冲器
        read(widget.fd[0], buf, sizeof(buf));
        if(buf == NULL)
        {
            qDebug() << "================buf  null===================";
        }
        else
        {
            if(strstr(buf, "ANS_LENGTH"))
            {
                sscanf(buf, "%*[^=]=%d", &widget.len_t);
                char s[26] = "";
                sprintf(s, "%02d : %02d", widget.len_t/60, widget.len_t%60);

                //把线程信息，发送到进程中
                //发送歌曲总时间
               if(widget.pos_t != widget.len_t)
               {
                   emit p->send_time_len(s);
               }


            }
            //memset(s, 0, sizeof(s));

            if(strstr(buf, "ANS_TIME_POSITION"))
            {
                sscanf(buf, "%*[^=]=%d", &widget.pos_t);

                char ss[26] = "";
                sprintf(ss, "%02d : %02d", widget.pos_t/60, widget.pos_t%60);



                //把线程信息，发送到进程中
                //发送当前歌曲时间
                if(widget.pos_t  !=  widget.len_t)
                {
                    p->ui->ProgressBar->setValue( (widget.pos_t*1.0/widget.len_t) *100);
                    emit p->send_time_pos(ss);

                    if(widget.len_t  - widget.pos_t == 5)
                    {
                        /*****单曲结束自动下一首******/
                        emit p->Next_song_signal();
                    }
                }
            }

            //memset(ss, 0, sizeof(ss));
        }

    }
    sleep(1);
}


//----------------------------------------------发送歌词到文本编辑框，这里先发送歌词信号到父进程----------------------------------------------//
void *callback_3(void *arg)
{
   Widget *p = (Widget*)arg;
   while(1)
   {        
        char *buff;
        buff = (char *)malloc(128);
        strcpy(buff,widget.str_next[widget.play_cur]);
        char *str1 = strtok(buff, "."); //xxx.mp3，只保留.之前的字符
        char *buf_1 = strcat(str1, ".lrc");


        //拼接路径
        char *filename;
        filename = (char *)malloc(strlen("./lyrics/")+strlen(str1)+1);  //堆区分配路径内存大小
        strcpy( filename ,"./lyrics/");
        strcat(filename, buf_1);    //切割好的歌词拼接到歌词文件后面，方便打开对应歌词文本
        qDebug() <<"-----filename-----|| %s ||-" << filename;


     //------------------------打开[filename]路径下歌词文件 ---------------------//
        FILE *fp;
        fp = fopen(filename, "r+");
        if(fp==NULL)
        {
            printf("没有该文件\n");        
        }
        else{

            int len = 0;
            char *arr = NULL;
            char *buf[128] = {NULL};//指针数字
            int count = 0;


            fseek(fp, 0, SEEK_END);
            len = ftell(fp);
            rewind(fp);

            arr = (char *)malloc(sizeof(char) * (len +1));
            fread(arr, len, 1, fp);
            if(arr == NULL)
            {
                perror("arr=null");
                fclose(fp);
            }
            fclose(fp);


            buf[count]= (char *)malloc(sizeof(char) * 256);
                buf[count] = strtok(arr, "\r\n");
                while(buf[count] != NULL)
                {
                    count++;
                    buf[count] = strtok(NULL, "\r\n");
                }
                int rows = count;//行号统计


        #if 1
                vector<Mysong_list> qvec;
                int i = 0;
                //从第五行开始打印歌词和时间，一行一行拷贝
                for(i = 4; i < rows; i++)
                {
                    char *str_lrc = buf[i];

                    if('[' == *str_lrc)
                    {
                        int m = 0;
                        int s = 0;
                        int num[128] = {0};//存放时间
                        int *Pnum = num;//定义一个指针存放数组首地址，达到对数组元素地址的操作

                        sscanf(str_lrc, "[%d:%d", &m, &s);
                        *(Pnum++) = m*60 + s;

                        str_lrc = str_lrc + 10;
                        while('[' == *str_lrc)
                        {
                            sscanf(str_lrc, "[%d:%d", &m, &s);
                            *(Pnum++) = m*60 + s;
                            str_lrc = str_lrc + 10;

                        }
                        Pnum = num;

                        if( strlen(str_lrc)!=0 )
                        {
                             qvec.push_back(Mysong_list(*Pnum, str_lrc));
                        }
                    }
                }
    #endif
                while(1)
                {
                         sleep(1);
                        for(vector<Mysong_list>::iterator it = qvec.begin(); it != qvec.end(); it++ )
                        {

                                if( widget.pos_t==(*it).time )
                                {
                                     p->ui->label_4->setText((*it).str);
                                     emit p->send_list((*it).str);
                                }
                        }

                        //歌曲切换，歌词也会变化
                        //采用标志位，作为切歌的判定
                        //标志位置为1，说明点击了上、下首歌曲的按键
                        if(widget.flag==1)
                        {
                               //切歌之后，标志位置为0，清空之前用到过的东西
                               widget.flag=0;

                               //歌曲切换后，清空list表格和主界面显示歌词的标签
                               //以及存储歌词信息的容器也清理
                               p->ui->label_4->clear();
                               p->Send_flag(widget.flag);
                               qvec.clear();
                               break;
                        }

                }
        }
        //printf("---^^^^^^----\n");
        sleep(1);
   }
   sleep(1);
}


void read_dir(char *path)
{
    DIR *dir = opendir(path);
    if(dir == NULL)
    {
        perror("NULL");
    }
    else
    {
        struct dirent *entry;
        widget.num = 0;
        while( (entry = readdir(dir)) != 0)
        {
            if(strstr(entry->d_name, ".mp3"))
            {            
               widget.list.append(QString(entry->d_name));
            }
        }
        //在这里直接把全部歌曲名都放到统一的指针数组中
        //下一首、上一首共用一个指针数组
        for(; widget.num < widget.list.size() -1;  widget.num++)
        {
           widget.str_next[widget.num]=(char*)malloc(128);//拷贝的时候，这是个指针数组，需要为其中的每个指针分配空间！！！
           strcpy( widget.str_next[widget.num], widget.list.at(widget.num).toUtf8().data());
        }

    }
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{   
   read_dir("./music");

    int ret = pipe(widget.fd);//无名管道
    if(ret==0)
    {
           // printf("fd[0]===%d:fd[1]===%d:\n",widget.fd[0],widget.fd[1]);
    }

    int ref = mkfifo("./fifo_cmd", 0666);//有名管道
    if(ref == 0)
    {
     //   printf("有名管道ok\n");
    }




    pid_t pid = fork();//父子进程
    this->pid = pid;
    if(pid < 0)
    {
        perror("error");
    }
    else if(pid == 0)
    {
        ::close(widget.fd[0]);//关闭读管道标识符,mplayer只需要向管道中写

        //父进程中的线程，不停的给 "fifo_cmd" 有名管道写数据
        //把标准输出 1 与 无名管道的写端 fd[1],绑定到一起
       dup2(widget.fd[1], 1);//重定向：将写入到终端的数据，写入到无命名管道
       execlp("mplayer"," mplayer ", "-slave", "-quiet","-idle","-input", "file=./fifo_cmd",\
                    "./music/sad_or_happy.mp3", NULL);
    }
    else
    {

        pthread_mutex_init(&widget.mutex, NULL);                                       //初始化一个互斥锁

        pthread_create(&widget.pth1, NULL, send_cb, (void *)this);
        pthread_create(&widget.pth2, NULL, recv_cb, (void *)this);
        pthread_create(&widget.pth3, NULL, callback_3, (void *)this);


        pthread_detach(widget.pth1);//分离函数调用,不会阻塞在线程那里
        pthread_detach(widget.pth2);
        pthread_detach(widget.pth3);

        ui->setupUi(this);
        this->volume_a = new Volume;
        this->tablewidget_a = new TableWidget;
        this->song_list = new Song_listTable;
        this->like_list = new Like_listwidget;


        //::close(widget.fd[1]);
        widget.fd_cmd = open("./fifo_cmd", O_RDWR);
        if(widget.fd_cmd < 0)
        {
            perror("widget.fd_cmd < 0");
        }

        //进入就获取一下当前歌曲名,显示在Song_TextEdit编辑框中
        ui->Song_TextEdit->setText(QString(widget.str_next[widget.play_cur]));

        //静音按键
        connect(ui->Mule_PushButton, &QPushButton::clicked, this, &Widget::Mule);

        //隐藏歌词界面
        connect(ui->List_Song_PushButton, &QPushButton::clicked, this, &Widget::Show_hide_List_Song);

        //connect(ui->ProgressBar, &QPushButton::clicked, this, &Widget::Pause_slots);

        //暂停播放器按键
        connect(ui->Pause_PushButton, &QPushButton::clicked, this, &Widget::Pause_slots);

        //下一首播放器按键
        connect(ui->Next_PushButton, &QPushButton::clicked, this, &Widget::Next_slots);

        //上一首播放器按键
        connect(ui->Up_PushButton, &QPushButton::clicked, this, &Widget::Up_slots);

        //显示、隐藏音量条副界面
        connect(ui->Volume_PushButton, &QPushButton::clicked, this, &Widget::Show_Hide);

        //音量--滑动条控制（由volume滑动条界面发送音量数值信号）?
        connect(this->volume_a, &Volume::volume_signals_verticalSlider, this, &Widget::rec_volume1);

        //显示、隐藏放置歌曲名副界面的表格
        connect(ui->Table_PushButton, &QPushButton::clicked, this, &Widget::Show_hide_table);

        //表格行号--点击当前表格发送的行信号
        connect(this->tablewidget_a, &TableWidget::send_table_row, this, &Widget::rec_table_row);

        //接收线程2中，发出的歌词总时间的信号、当前歌词时间信号
        connect(this, &Widget::send_time_pos, this, &Widget::rec_time_pos);
        connect(this, &Widget::send_time_len, this, &Widget::rec_time_len);

        //切歌的同时，给【歌曲列表cpp】发送'歌词'的字符串信号  \  当前歌曲标志位信号
        connect(this, &Widget::send_list,  this->song_list,  &Song_listTable::Song_Listtable_01_Receive_The_widget_Response_Signal);
        connect(this, &Widget::Send_flag, this->song_list, &Song_listTable::Song_Listtable_02_Receive_The_widget_Response_Signal);

        //滑动条剩余3秒，自动切换下一首
        connect(this, &Widget::Next_song_signal, this, &Widget::Rec_Next_song_signal);

        //快进
        connect(ui->Fast_PushButton, &QPushButton::clicked, this, &Widget::fast_speed_Song);
        //快退
        connect(ui->Low_PushButton, &QPushButton::clicked, this, &Widget::fast_backward_Song);

        //显示、隐藏，喜欢列表控件
        connect(ui->Like_Listwidget_PushButton, &QPushButton::clicked, this,  &Widget::Show_hide_Like_list);

        //点赞
        connect(ui->Like_PushButton, &QPushButton::clicked, this, &Widget::Give_a_like);
        //发送喜欢的歌曲名信号 给 显示喜欢歌曲的;list列表
        connect(this, &Widget::send_like_song, this->like_list,  &Like_listwidget::Rec_Widget_Send_LikeSong);
        //表格行号--点击当前喜欢歌曲的 list 列表发送的[文本]信号
        connect(this->like_list, &Like_listwidget::send_LikeSong_list_Text_changed, this, &Widget::Rec_like_listwidget_send_text);

    }





}

Widget::~Widget()
{
    printf("mplayer kill !!!");
    pthread_mutex_destroy(&widget.mutex);                                          //删除互斥锁
    kill(pid, 9);
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)//设置主体窗口的背景图片
{

    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/new/prefix1/picture/19.png"),QRect());		//传入资源图片路径
}

//---------------------------------------------------------------------------所有槽函数实现----------------------------------------------------------------------------//
void Widget::Pause_slots()
{
    if(widget.pause_flag == 1)
    {
        pthread_mutex_lock(&widget.mutex);                                              //上锁,保险起见
        write(widget.fd_cmd, "pause\n", strlen("pause\n"));
        pthread_mutex_unlock(&widget.mutex);                                          //解锁

        //设置按键图片
        ui->Pause_PushButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/picture/pause.png);border:none;color:rgb(255, 255, 255);}");
        //暂停状态改变
        widget.pause_flag = 0;
    }
    else
    {
        pthread_mutex_lock(&widget.mutex);                                              //上锁,保险起见
        write(widget.fd_cmd, "pause\n", strlen("pause\n"));
        pthread_mutex_unlock(&widget.mutex);                                          //解锁

        ui->Pause_PushButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/picture/play.png);border:none;color:rgb(255, 255, 255);}");
        widget.pause_flag = 1;
    }
}

void Widget::Next_slots()
{
    widget.flag=1;

    if(widget.play_cur == widget.list.size() - 1)
    {
        //当前歌曲数，最后一首就归0，从头开始
        widget.play_cur = 0;
    }
    else
    {
        //当前歌曲数，没到最后一首就++
        widget.play_cur++;
    }

    sprintf(widget.buf_song_name, "loadfile ./music/%s\n", widget.str_next[widget.play_cur]);

    //切歌后，歌名显示在TextEdit文本表格中
    ui->Song_TextEdit->setText(QString(widget.str_next[widget.play_cur]));

    pthread_mutex_lock(&widget.mutex);                                              //上锁,保险起见
    write(widget.fd_cmd, widget.buf_song_name, strlen(widget.buf_song_name));
    pthread_mutex_unlock(&widget.mutex);                                          //解锁


    if(widget.pause_flag == 0)
    {
        //播放开始了，暂停状态变成播放状态 1
        ui->Pause_PushButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/picture/play.png);border:none;color:rgb(255, 255, 255);}");
        widget.pause_flag = 1;
    }
}

void Widget::Up_slots()
{
    widget.flag=1;

    if(widget.play_cur == 0)
    {
        widget.play_cur = widget.list.size() -1;
    }
    else
    {
        widget.play_cur--;
    }

    char buf_up[128] = "";
    sprintf(buf_up, "loadfile ./music/%s\n", widget.str_next[widget.play_cur]);
    //切歌后，歌名显示在TextEdit文本表格中
    ui->Song_TextEdit->setText(QString(widget.str_next[widget.play_cur]));

    pthread_mutex_lock(&widget.mutex);                                              //上锁,保险起见
    write(widget.fd_cmd, buf_up, strlen(buf_up));
    pthread_mutex_unlock(&widget.mutex);                                          //解锁

    if(widget.pause_flag == 0)
    {
        //播放开始了，暂停状态变成播放状态 1
        ui->Pause_PushButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/picture/play.png);border:none;color:rgb(255, 255, 255);}");
        widget.pause_flag = 1;
    }


}

void Widget::Show_Hide()
{
    static char flag = 0;
    if(0 == flag)
    {
        this->volume_a->hide();
        flag = 1;
    }
    else
    {
        this->volume_a->show();
        flag = 0;
    }
}

void Widget::Show_hide_table()
{
    static char flag = 0;
    if(0 == flag)
    {
        this->tablewidget_a->hide();
        //表格隐藏，修改一下控件 图片
        ui->Table_PushButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/picture/no_show.png);border:none;color:rgb(255, 255, 255);}");

        flag = 1;
    }
    else
    {
        this->tablewidget_a->show();
        ui->Table_PushButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/picture/eye_open.png);border:none;color:rgb(255, 255, 255);}");

        flag = 0;
    }
}

void Widget::Mule()
{
    if(widget.mute_flag == 0)
    {
        pthread_mutex_lock(&widget.mutex);                                              //上锁,保险起见
        write(widget.fd_cmd, "mute 1\n", strlen("mute 1\n"));
        pthread_mutex_unlock(&widget.mutex);                                          //解锁

        widget.mute_flag = 1;
    }
    else
    {
        pthread_mutex_lock(&widget.mutex);                                              //上锁,保险起见
        write(widget.fd_cmd, "mute 0\n", strlen("mute 0\n"));
        pthread_mutex_unlock(&widget.mutex);                                          //解锁

        widget.mute_flag = 0;
    }

    if(widget.pause_flag == 1)
    {
        pthread_mutex_lock(&widget.mutex);                                              //上锁,保险起见
        write(widget.fd_cmd, "pause\n", strlen("pause\n"));
        pthread_mutex_unlock(&widget.mutex);                                          //解锁
    }
}

void Widget::Show_hide_List_Song()
{
    static char flag = 0;
    if(0 == flag)
    {
        this->song_list->hide();
        flag = 1;
    }
    else
    {
        this->song_list->show();
        flag = 0;
    }
}

void Widget::rec_volume1(int a)
{
    widget.volume_cur = a;//直接拿信号发送过来的int值就行
                          //无需做大小判断，因为滑动条最大就是100，最小0，不会超过临界点

    char str[128] = "";
    sprintf(str, "volume %d 1\n", widget.volume_cur);

    pthread_mutex_lock(&widget.mutex);                                              //上锁,保险起见
    write(widget.fd_cmd, str, strlen(str));
    pthread_mutex_unlock(&widget.mutex);                                          //解锁


    if( widget.pause_flag == 0)
    {
        pthread_mutex_lock(&widget.mutex);                                              //上锁,保险起见
        write(widget.fd_cmd,"pause\n",strlen("pause\n"));
        pthread_mutex_unlock(&widget.mutex);                                          //解锁

        widget.pause_flag = 1;
        ui->Pause_PushButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/picture/play.png);border:none;color:rgb(255, 255, 255);}");

    }
}

void Widget::rec_table_row(int a)
{
    widget.flag=1;
    widget.play_cur = a;
    char buf_up[128] = "";
    sprintf(buf_up, "loadfile ./music/%s\n", widget.str_next[widget.play_cur]);
    //切歌后，歌名显示在TextEdit文本表格中
    ui->Song_TextEdit->setText(QString(widget.str_next[widget.play_cur]));

    pthread_mutex_lock(&widget.mutex);                                              //上锁,保险起见
    write(widget.fd_cmd, buf_up, strlen(buf_up));
    pthread_mutex_unlock(&widget.mutex);                                          //解锁
}

void Widget::rec_time_pos(char *str)//歌词实时时间信号
{
    widget.buf_time = new char[128];
    strcpy(widget.buf_time, str);
    //把从线程接收的歌词时间信号显示到文本中
    ui->Get_Time_Pos_TextEdit->setText(QString(widget.buf_time));
}

void Widget::rec_time_len(char *str)
{
    //har *buf_time2 = NULL;
    widget.buf_time2 = str;
    ui->Get_Time_Length_TextEdit->setText(QString(widget.buf_time2));
}

void Widget::Rec_Next_song_signal()
{
    if(widget.play_cur == widget.list.size() -1 )
    {
        widget.play_cur = 0;
    }
    else
    {
        widget.play_cur++;
    }
    sprintf(widget.buf_song_name, "loadfile ./music/%s\n", widget.str_next[widget.play_cur]);

    pthread_mutex_lock(&widget.mutex);                                              //上锁,保险起见
    write(widget.fd_cmd, widget.buf_song_name, strlen(widget.buf_song_name));
    pthread_mutex_unlock(&widget.mutex);                                          //解锁


}

void Widget::fast_backward_Song()
{
    pthread_mutex_lock(&widget.mutex);                                              //上锁,保险起见
    write(widget.fd_cmd, "seek -10\n", strlen("seek -10\n"));
    pthread_mutex_unlock(&widget.mutex);                                          //解锁

    if(widget.pause_flag == 0)
    {
        //播放开始了，暂停状态变成播放状态 1
        ui->Pause_PushButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/picture/play.png);border:none;color:rgb(255, 255, 255);}");
        widget.pause_flag = 1;
    }
}

void Widget::fast_speed_Song()
{
    pthread_mutex_lock(&widget.mutex);                                              //上锁,保险起见
    write(widget.fd_cmd, "seek 10\n", strlen("seek 10\n"));
    pthread_mutex_unlock(&widget.mutex);                                          //解锁

    if(widget.pause_flag == 0)
    {
        //播放开始了，暂停状态变成播放状态 1
        ui->Pause_PushButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/picture/play.png);border:none;color:rgb(255, 255, 255);}");
        widget.pause_flag = 1;
    }
}

void Widget::Show_hide_Like_list()
{
    static char flag = 0;
    if(0 == flag)
    {
        this->like_list->hide();
        flag = 1;
    }
    else
    {
        this->like_list->show();
        flag = 0;
    }
}

void Widget::Give_a_like()
{
    char *str;
    str = new char[128];
    strcpy(str, widget.str_next[widget.play_cur]);

    emit this->send_like_song(str);
}

void Widget::Rec_like_listwidget_send_text(char *buf)
{
    widget.flag=1;
    char *buf_text;
    buf_text = new char[128];

    sprintf(buf_text, "loadfile ./music/%s\n", buf);
    //切歌后，歌名显示在TextEdit文本表格中
    ui->Song_TextEdit->setText(QString(buf));

    pthread_mutex_lock(&widget.mutex);                                              //上锁,保险起见
    write(widget.fd_cmd, buf_text, strlen(buf_text));
    pthread_mutex_unlock(&widget.mutex);                                          //解锁

}
