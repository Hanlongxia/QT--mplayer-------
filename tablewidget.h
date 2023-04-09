#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include <sys/types.h>
#include <dirent.h>

namespace Ui {
class TableWidget;
}

class TableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TableWidget(QWidget *parent = 0);
    ~TableWidget();

signals:
    void send_table_row(int a);//负责发送表格点击到的行号给主页面

private:
    Ui::TableWidget *ui;
};

#endif // TABLEWIDGET_H
