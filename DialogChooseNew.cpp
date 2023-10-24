#include "DialogChooseNew.h"
#include "ui_DialogChooseNew.h"
#include <QButtonGroup>
#include <QRadioButton>
#include<QDebug>
DialogChooseNew::DialogChooseNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChooseNew)
{
    ui->setupUi(this);


    // 创建按钮组
    QButtonGroup* group = new QButtonGroup(parent);

    // 将三个单选按钮加入按钮组
    group->addButton(ui->radioButton);
    group->addButton(ui->radioButton2);
    group->addButton(ui->radioButton3);
    group->addButton(ui->radioButton4);
    // 设置按钮组为排他模式，即同一时间只能选中一个按钮
    group->setExclusive(true);

}

DialogChooseNew::~DialogChooseNew()
{
    delete ui;
}

void DialogChooseNew::on_buttonBox_accepted()
{
    qDebug()<<"accept";
    if(ui->radioButton->isChecked())
    {
        emit sigChosen("yt");
    }
    else if(ui->radioButton2->isChecked())
    {
        emit sigChosen("yr");
    }
    else    if(ui->radioButton3->isChecked())
    {
        emit sigChosen("fhh");
    }
    else    if(ui->radioButton4->isChecked())
    {
        emit sigChosen(ui->lineEdit->text(),false);
    }


}
