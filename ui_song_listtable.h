/********************************************************************************
** Form generated from reading UI file 'song_listtable.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONG_LISTTABLE_H
#define UI_SONG_LISTTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Song_listTable
{
public:
    QListWidget *listWidget;

    void setupUi(QWidget *Song_listTable)
    {
        if (Song_listTable->objectName().isEmpty())
            Song_listTable->setObjectName(QStringLiteral("Song_listTable"));
        Song_listTable->resize(290, 288);
        listWidget = new QListWidget(Song_listTable);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 291, 291));
        listWidget->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/13.png);"));
        listWidget->setFrameShape(QFrame::NoFrame);

        retranslateUi(Song_listTable);

        QMetaObject::connectSlotsByName(Song_listTable);
    } // setupUi

    void retranslateUi(QWidget *Song_listTable)
    {
        Song_listTable->setWindowTitle(QApplication::translate("Song_listTable", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Song_listTable: public Ui_Song_listTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONG_LISTTABLE_H
