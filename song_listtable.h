#ifndef SONG_LISTTABLE_H
#define SONG_LISTTABLE_H

#include <QWidget>
#include "headr.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <QFile>
#include <QTableWidgetItem>
#include <QStringList>

#include <QList>
#include <QTableWidgetItem>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QModelIndex>

namespace Ui {
class Song_listTable;
}

class Song_listTable : public QWidget
{
    Q_OBJECT

public:
    explicit Song_listTable(QWidget *parent = 0);
    ~Song_listTable();

public slots:
    void Song_Listtable_01_Receive_The_widget_Response_Signal(char *);
    void Song_Listtable_02_Receive_The_widget_Response_Signal(int a);//接收发送过来的[---flag----]信号

private:
    Ui::Song_listTable *ui;
};

#endif // SONG_LISTTABLE_H
