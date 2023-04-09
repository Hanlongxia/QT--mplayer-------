#include "like_listwidget.h"
#include "ui_like_listwidget.h"

Like_listwidget::Like_listwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Like_listwidget)
{
    ui->setupUi(this);
                                                                                                                                                                        //只能返回文本信息
    connect(ui->listWidget, &QListWidget::itemClicked, this, &Like_listwidget::send_list_Text);            //点赞是随机的，不能再返回行号，歌曲的顺序是按照行号排列的，

}

Like_listwidget::~Like_listwidget()
{
    delete ui;
}

void Like_listwidget::Rec_Widget_Send_LikeSong(char *str)
{
    //QListWidgetItem *p = new QListWidgetItem(str);                                                                //会一直新增行，重复之前添加的文本(X)
    //ui->listWidget->insertItem(0 , p);

    /*-------------遍历所有item 如果没有重复 则增加------------*/
    int row=0;
    QString line;
    while(row<(ui->listWidget->count()))
    {
        line=ui->listWidget->item(row)->text();
        if(str==line)
            return;                                                                                                                                  //行不做增加，只会覆盖掉之前添加过的文本，不影响

        row++;
    }
    ui->listWidget->insertItem(row , new QListWidgetItem(str));                                                 //把文本（字符串）转换成Item项目模式，指定行，插入(√)

}

void Like_listwidget::send_list_Text()
{
    QString str;
    str = ui->listWidget->currentItem()->text();                                                                              //鼠标选中某行的内容
    QByteArray  str2;                                                                                                                         //这个转换再想利用QString的构造函数则不行了，还需要借助QByteArray类来进行转换：
    str2.append(str);
    const char *str3 = str2.data();
    char * myCharStr = const_cast<char *>(str3);

    emit this->send_LikeSong_list_Text_changed(myCharStr);
}
