/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QPushButton *Pause_PushButton;
    QPushButton *Up_PushButton;
    QPushButton *Next_PushButton;
    QPushButton *Fast_PushButton;
    QPushButton *Low_PushButton;
    QPushButton *Volume_PushButton;
    QLabel *label_2;
    QPushButton *Table_PushButton;
    QTextEdit *Song_TextEdit;
    QTextEdit *Get_Time_Length_TextEdit;
    QTextEdit *Get_Time_Pos_TextEdit;
    QProgressBar *ProgressBar;
    QPushButton *Mule_PushButton;
    QPushButton *List_Song_PushButton;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *Like_Listwidget_PushButton;
    QPushButton *Like_PushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(682, 455);
        Widget->setStyleSheet(QLatin1String("Widget{\n"
"border-image: url(:/new/prefix1/picture/11.png);\n"
"}"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 70, 211, 231));
        label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/picture/1.png);"));
        Pause_PushButton = new QPushButton(Widget);
        Pause_PushButton->setObjectName(QStringLiteral("Pause_PushButton"));
        Pause_PushButton->setGeometry(QRect(290, 310, 61, 51));
        Pause_PushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/picture/play.png);"));
        Up_PushButton = new QPushButton(Widget);
        Up_PushButton->setObjectName(QStringLiteral("Up_PushButton"));
        Up_PushButton->setGeometry(QRect(210, 310, 61, 51));
        Up_PushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/picture/up.png);"));
        Next_PushButton = new QPushButton(Widget);
        Next_PushButton->setObjectName(QStringLiteral("Next_PushButton"));
        Next_PushButton->setGeometry(QRect(370, 310, 61, 51));
        Next_PushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/picture/next.png);"));
        Fast_PushButton = new QPushButton(Widget);
        Fast_PushButton->setObjectName(QStringLiteral("Fast_PushButton"));
        Fast_PushButton->setGeometry(QRect(460, 310, 51, 51));
        Fast_PushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/picture/fast.png);"));
        Low_PushButton = new QPushButton(Widget);
        Low_PushButton->setObjectName(QStringLiteral("Low_PushButton"));
        Low_PushButton->setGeometry(QRect(130, 310, 51, 51));
        Low_PushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/picture/low.png);"));
        Volume_PushButton = new QPushButton(Widget);
        Volume_PushButton->setObjectName(QStringLiteral("Volume_PushButton"));
        Volume_PushButton->setGeometry(QRect(530, 320, 51, 41));
        Volume_PushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/picture/volume.png);"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(370, 180, 131, 101));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/picture/2.png);"));
        Table_PushButton = new QPushButton(Widget);
        Table_PushButton->setObjectName(QStringLiteral("Table_PushButton"));
        Table_PushButton->setGeometry(QRect(70, 330, 41, 31));
        Table_PushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/picture/no_show.png);"));
        Song_TextEdit = new QTextEdit(Widget);
        Song_TextEdit->setObjectName(QStringLiteral("Song_TextEdit"));
        Song_TextEdit->setGeometry(QRect(560, 210, 101, 61));
        Song_TextEdit->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/picture/song.png);\n"
"background-repeat:no-repeat;              \n"
"background-position:center;              \n"
""));
        Song_TextEdit->setFrameShape(QFrame::NoFrame);
        Get_Time_Length_TextEdit = new QTextEdit(Widget);
        Get_Time_Length_TextEdit->setObjectName(QStringLiteral("Get_Time_Length_TextEdit"));
        Get_Time_Length_TextEdit->setGeometry(QRect(460, 260, 51, 51));
        Get_Time_Length_TextEdit->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/picture/8.png);\n"
"background-repeat:no-repeat;              \n"
"background-position:center;     "));
        Get_Time_Pos_TextEdit = new QTextEdit(Widget);
        Get_Time_Pos_TextEdit->setObjectName(QStringLiteral("Get_Time_Pos_TextEdit"));
        Get_Time_Pos_TextEdit->setGeometry(QRect(130, 260, 51, 51));
        Get_Time_Pos_TextEdit->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/picture/7.png);\n"
"background-repeat:no-repeat;              \n"
"background-position:center;  "));
        ProgressBar = new QProgressBar(Widget);
        ProgressBar->setObjectName(QStringLiteral("ProgressBar"));
        ProgressBar->setGeometry(QRect(170, 370, 341, 21));
        ProgressBar->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/picture/processBar1.png);\n"
"background-repeat:no-repeat;              \n"
"background-position:center;              "));
        ProgressBar->setMaximum(100);
        ProgressBar->setValue(0);
        ProgressBar->setTextDirection(QProgressBar::TopToBottom);
        Mule_PushButton = new QPushButton(Widget);
        Mule_PushButton->setObjectName(QStringLiteral("Mule_PushButton"));
        Mule_PushButton->setGeometry(QRect(610, 110, 51, 41));
        Mule_PushButton->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/picture/mule.png);\n"
"background-repeat:no-repeat;              \n"
"background-position:center;              "));
        List_Song_PushButton = new QPushButton(Widget);
        List_Song_PushButton->setObjectName(QStringLiteral("List_Song_PushButton"));
        List_Song_PushButton->setGeometry(QRect(620, 160, 41, 41));
        List_Song_PushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/picture/list_song.png);"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 270, 251, 31));
        label_4->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/picture/18.png);            \n"
"background-position:center; "));
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setFrameShadow(QFrame::Plain);
        label_4->setMidLineWidth(0);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(560, 10, 131, 71));
        label_5->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/picture/17.png);\n"
"background-repeat:no-repeat;              \n"
"background-position:center;  "));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(-40, 410, 121, 81));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/picture/28.png);"));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(-80, -20, 201, 161));
        label_6->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/picture/27.png);"));
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(420, 160, 101, 101));
        label_7->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/picture/23.png);"));
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(540, 370, 151, 151));
        label_8->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/picture/26.png);"));
        Like_Listwidget_PushButton = new QPushButton(Widget);
        Like_Listwidget_PushButton->setObjectName(QStringLiteral("Like_Listwidget_PushButton"));
        Like_Listwidget_PushButton->setGeometry(QRect(620, 280, 41, 41));
        Like_Listwidget_PushButton->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/picture/like2.png);\n"
"background-repeat:no-repeat;              \n"
"background-position:center;    "));
        Like_PushButton = new QPushButton(Widget);
        Like_PushButton->setObjectName(QStringLiteral("Like_PushButton"));
        Like_PushButton->setGeometry(QRect(610, 330, 51, 41));
        Like_PushButton->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/picture/zan.png);\n"
"background-repeat:no-repeat;              \n"
"background-position:center;   "));
        Pause_PushButton->raise();
        Up_PushButton->raise();
        Next_PushButton->raise();
        Fast_PushButton->raise();
        Low_PushButton->raise();
        Volume_PushButton->raise();
        Song_TextEdit->raise();
        Get_Time_Length_TextEdit->raise();
        Get_Time_Pos_TextEdit->raise();
        label->raise();
        label_2->raise();
        ProgressBar->raise();
        Mule_PushButton->raise();
        List_Song_PushButton->raise();
        label_4->raise();
        label_5->raise();
        Table_PushButton->raise();
        label_3->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        Like_Listwidget_PushButton->raise();
        Like_PushButton->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label->setText(QString());
        Pause_PushButton->setText(QString());
        Up_PushButton->setText(QString());
        Next_PushButton->setText(QString());
        Fast_PushButton->setText(QString());
        Low_PushButton->setText(QString());
        Volume_PushButton->setText(QString());
        label_2->setText(QString());
        Table_PushButton->setText(QString());
        ProgressBar->setFormat(QString());
        Mule_PushButton->setText(QString());
        List_Song_PushButton->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_3->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        Like_Listwidget_PushButton->setText(QString());
        Like_PushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
