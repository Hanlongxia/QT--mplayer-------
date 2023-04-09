#ifndef LIKE_LISTWIDGET_H
#define LIKE_LISTWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QString>

namespace Ui {
class Like_listwidget;
}

class Like_listwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Like_listwidget(QWidget *parent = 0);
    ~Like_listwidget();

public slots:
    void Rec_Widget_Send_LikeSong(char *str);

    void send_list_Text();

signals:
    void send_LikeSong_list_Text_changed(char *buf);

private:
    Ui::Like_listwidget *ui;
};

#endif // LIKE_LISTWIDGET_H
