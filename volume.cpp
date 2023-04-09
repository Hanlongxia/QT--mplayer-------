#include "volume.h"
#include "ui_volume.h"

Volume::Volume(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Volume)
{
    ui->setupUi(this);

    //一、【滑动条】的数值，反应到【spinBox】中
    //发送一个【信号】，有参信号函数【valueChanged】
    //当前页面控件的构造函数
    connect(ui->verticalSlider, &QSlider::valueChanged, this, &Volume::Setvalform_verticalSlider);




    //二、【spinBox】的数值，反应到滑动条上
    //使用函数指针，操作重载的函数【valueChanged】
    //信号是可以重载的
    //槽函数也是可以进行重载的，如果咱们建立连接的时候，出现冲突
    //会报错，怎么消除错误
    void (QSpinBox:: *p)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, p, this, &Volume::Setvalform_spinBox);

}

Volume::~Volume()
{
    delete ui;
}

void Volume::Setvalform_spinBox(int a)
{
    ui->verticalSlider->setValue(a);
    emit this->volume_signals_verticalSlider(a);
}

void Volume::Setvalform_verticalSlider(int a)
{
    ui->spinBox->setValue(a);
    emit this->volume_signals_verticalSlider(a);
}
