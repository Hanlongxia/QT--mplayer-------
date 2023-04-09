/********************************************************************************
** Form generated from reading UI file 'like_listwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIKE_LISTWIDGET_H
#define UI_LIKE_LISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Like_listwidget
{
public:
    QListWidget *listWidget;

    void setupUi(QWidget *Like_listwidget)
    {
        if (Like_listwidget->objectName().isEmpty())
            Like_listwidget->setObjectName(QStringLiteral("Like_listwidget"));
        Like_listwidget->resize(253, 325);
        listWidget = new QListWidget(Like_listwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 1, 256, 331));

        retranslateUi(Like_listwidget);

        QMetaObject::connectSlotsByName(Like_listwidget);
    } // setupUi

    void retranslateUi(QWidget *Like_listwidget)
    {
        Like_listwidget->setWindowTitle(QApplication::translate("Like_listwidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Like_listwidget: public Ui_Like_listwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIKE_LISTWIDGET_H
