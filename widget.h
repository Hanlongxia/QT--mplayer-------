#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "volume.h"
#include "tablewidget.h"
#include "song_listtable.h"
#include "like_listwidget.h"
#include <unistd.h>
#include "headr.h"
#include <algorithm>
#include <vector>
#include <ctime>
#include <iostream>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    Volume * volume_a;
    TableWidget * tablewidget_a;
    Song_listTable * song_list;
    Like_listwidget * like_list;

    void paintEvent(QPaintEvent *event);
    friend void *callback_3(void *arg);//线程设置为友元，让线程可以操作私有的【ui】中的控件
    friend void *recv_cb(void *arg);//线程设置为友元
    friend void *send_cb(void *arg);//线程设置为友元
public slots:
    void Pause_slots();
    void Next_slots();
    void Up_slots();
    void Show_Hide();//显示、隐藏音量条
    void Show_hide_table();//显示、隐藏放置歌曲名的表格
    void Mule();//静音
    void Show_hide_List_Song();//隐藏、显示歌词界面

    void rec_volume1(int a);//响应volume.cpp发送过来的音量数值信号
    void rec_table_row(int a);//响应table.cpp发送过来的行信号

    void rec_time_pos(char *str);//接收线程2中，发出的当前歌词时间信号
    void rec_time_len(char *str);//接收线程2中，发出的歌词总时间的信号

    void Rec_Next_song_signal();//接收滑动条快结束发送的下一首信号
    void fast_speed_Song();
    void fast_backward_Song();

    void Show_hide_Like_list();//隐藏、显示喜欢列表控件
    void Give_a_like();//点赞
    void Rec_like_listwidget_send_text(char *buf);//接收喜欢列表发送的歌曲文本信息

signals:
    void send_time_pos(char *str);//发送当前歌词时间的信号
    void send_time_len(char *str);//发送歌词总时间的信号

    void send_list(char *);//给【歌曲列表song_list.cpp】发送'歌词'的字符串信号

    void Send_flag(int a);//发送当前歌曲标志位信号--线程3[歌词打印]当中采用

    void Next_song_signal();
    void send_like_song(char *);//发送喜欢的歌曲名信号



private:
    Ui::Widget *ui;
    pid_t pid;

};

#endif // WIDGET_H
