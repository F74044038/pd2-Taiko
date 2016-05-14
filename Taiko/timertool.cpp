#include "timertool.h"
#include   <QtCore>


Timertool::Timertool()
{
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timetool));
    timer->start(1000);
}
void Timertool::timetool(){

}
