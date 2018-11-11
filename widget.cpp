#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    money_=0;
    ui->setupUi(this);
}

widget::~widget()
{
    delete ui;
}

void widget::setControl()
{
    ui->lcdNumber->display(money_);
    ui->pbCoffee->setEnabled(money_>=100);
    ui->pbTea->setEnabled(money_>=150);
    ui->pbCola->setEnabled(money_>=200);

}

void widget::on_pb500_clicked()
{
    money_+=500;
    setControl();
}

void widget::on_pb100_clicked()
{
    money_+=100;
    setControl();
}

void widget::on_pb50_clicked()
{
    money_+=50;
    setControl();
}

void widget::on_pb10_clicked()
{
    money_+=10;
    setControl();
}

void widget::on_pbCoffee_clicked()
{
    money_-=100;
    setControl();
}

void widget::on_pbTea_clicked()
{
    money_-=150;
    setControl();
}

void widget::on_pbCola_clicked()
{
    money_-=200;
    setControl();
}

void widget::on_pbReset_clicked()
{
    int c_500=money_/500;
    money_-=c_500*500;
    int c_100=money_/100;
    money_-=c_100*100;
    int c_50=money_/50;
    money_-=c_50*50;
    int c_10=money_/10;
    money_-=c_10*10;
    setControl();
    QMessageBox::information(this,"Reset",QString("500: %1\n100: %2\n50: %3\n10: %4\n").arg(c_500).arg(c_100).arg(c_50).arg(c_10));
}
