#ifndef VOLUME_H
#define VOLUME_H

#include <QWidget>
#include <QSpinBox>
namespace Ui {
class Volume;
}

class Volume : public QWidget
{
    Q_OBJECT

public:
    explicit Volume(QWidget *parent = 0);
    ~Volume();

    //int Getvalform();
    void Setvalform_spinBox(int a);//获取到Box盒子中的数值
    void Setvalform_verticalSlider(int a);//获取到滑动条的数值

signals:
    void volume_signals_verticalSlider(int a);//发送滑动条数值到主页面。作为音量数值


private:
    Ui::Volume *ui;
};

#endif // VOLUME_H
