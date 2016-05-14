#include "mydialog.h"
#include "ui_mydialog.h"
#include <QLabel>
#include <QListWidgetItem>
myDialog::myDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myDialog)
{
    ui->setupUi(this);
    this->setObjectName("final");
    this->setGeometry(650,200,500,350);
    this->setStyleSheet("#final{border-image: url(:/new/prefix1/final.jpg)}");
    restart=new QPushButton("",this);
    exit=new QPushButton("",this);
    restart->setGeometry(420,-10,80,80);
    exit->setGeometry(400,100,100,100);
    restart->setObjectName("restart");
    exit->setObjectName("exit");
    restart->setObjectName("restart");
    restart->setStyleSheet("#restart{border-image: url(:/new/prefix1/restart.png)}");
    exit->setStyleSheet("#exit{border-image: url(:/new/prefix1/quit.png)}");
    ////////////////////////////////////////
    Score=new QLabel(this);
    Score->setFont(QFont("Time",25,QFont::Bold));
    Score->setGeometry(15,-5,200,100);
    Score->show();

}

myDialog::~myDialog()
{
    delete ui;
}
