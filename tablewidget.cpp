#include "tablewidget.h"
#include "ui_tablewidget.h"

struct Table
{
    char *str_next[128];
    QList<QString> list;
    int num;
}table;


void read_dir_table(char *path)
{
    DIR *dir = opendir(path);
    if(dir == NULL)
    {
        perror("NULL");
    }
    else
    {
        struct dirent *entry;
        while( (entry = readdir(dir)) != 0)
        {
            if(strstr(entry->d_name, ".mp3"))
            {
               table.list.append(QString(entry->d_name));
            //   printf("%s\n", entry->d_name);//所有歌曲名打印
            }
        }
    }
}



TableWidget::TableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableWidget)
{
    ui->setupUi(this);

    //转换一下，不然read_dir_table改行报：警告： 不建议使用从字符串常量到‘char*’的转换
    char *buf = (char *)"./music";


    //检索目录下所有文件
    read_dir_table(buf);
    table.num = 0;
    for(; table.num < table.list.size() -1;  table.num++)
    {
        //把歌曲名，添加到表格中
        //at比 [ ]方括号的方式更快速、安全
        ui->listWidget->addItem(table.list.at(table.num));
    }


    //给主界面，widget界面发送 表格的行号
    //采用有参信号 模式
    connect(ui->listWidget, &QListWidget::currentRowChanged, this, [=](int a)
    {
        emit this->send_table_row(a);
    });

}

TableWidget::~TableWidget()
{
    delete ui;
}
