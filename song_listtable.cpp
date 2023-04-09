#include "song_listtable.h"
#include "ui_song_listtable.h"
#include <QDebug>
#include <algorithm>
#include <deque>
#include <vector>
#include <ctime>
#include <QQueue>
#include <QVector>
#include <iostream>
using namespace std;





Song_listTable::Song_listTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Song_listTable)
{

    ui->setupUi(this);
}

Song_listTable::~Song_listTable()
{
    delete ui;
}

void Song_listTable::Song_Listtable_02_Receive_The_widget_Response_Signal(int a)
{
    if(a == 0)
    {
        ui->listWidget->clear();
    }
}
void Song_listTable::Song_Listtable_01_Receive_The_widget_Response_Signal(char *str)
{
    printf("==[song_listtable]===========%s\n",str);
    ui->listWidget->insertItem(0 , new QListWidgetItem(str));

}






