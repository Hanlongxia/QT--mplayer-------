/********************************************************************************
** Form generated from reading UI file 'volume.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLUME_H
#define UI_VOLUME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Volume
{
public:
    QSlider *verticalSlider;
    QSpinBox *spinBox;

    void setupUi(QWidget *Volume)
    {
        if (Volume->objectName().isEmpty())
            Volume->setObjectName(QStringLiteral("Volume"));
        Volume->resize(66, 289);
        Volume->setStyleSheet(QLatin1String("#Volume{\n"
"background-image: url(:/new/prefix1/picture/6.png);\n"
"background-repeat:no-repeat;              \n"
"background-position:center;   \n"
"}"));
        verticalSlider = new QSlider(Volume);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(20, 80, 22, 160));
        verticalSlider->setOrientation(Qt::Vertical);
        spinBox = new QSpinBox(Volume);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(10, 50, 42, 22));

        retranslateUi(Volume);

        QMetaObject::connectSlotsByName(Volume);
    } // setupUi

    void retranslateUi(QWidget *Volume)
    {
        Volume->setWindowTitle(QApplication::translate("Volume", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Volume: public Ui_Volume {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUME_H
