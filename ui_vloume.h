/********************************************************************************
** Form generated from reading UI file 'vloume.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VLOUME_H
#define UI_VLOUME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vloume
{
public:
    QSlider *verticalSlider;
    QSpinBox *spinBox;

    void setupUi(QWidget *vloume)
    {
        if (vloume->objectName().isEmpty())
            vloume->setObjectName(QStringLiteral("vloume"));
        vloume->resize(102, 288);
        verticalSlider = new QSlider(vloume);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(40, 40, 22, 160));
        verticalSlider->setOrientation(Qt::Vertical);
        spinBox = new QSpinBox(vloume);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(30, 210, 42, 22));

        retranslateUi(vloume);

        QMetaObject::connectSlotsByName(vloume);
    } // setupUi

    void retranslateUi(QWidget *vloume)
    {
        vloume->setWindowTitle(QApplication::translate("vloume", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class vloume: public Ui_vloume {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VLOUME_H
