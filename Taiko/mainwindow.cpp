#include "mainwindow.h"
#include "ui_mainwindow.h"
#include   <QPushButton>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QDesktopWidget>
#include <QGraphicsScene>
#include     <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include  <QGraphicsView>
#include   <QGraphicsItem>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setObjectName("menu");
    this->setGeometry(600,150,640,512);
    this->setStyleSheet("#menu{border-image: url(:/new/prefix1/8787.jpg)}");
    quit=new QPushButton("",this);
    start=new QPushButton((""),this);
    start->setGeometry(250,15,150,150);
    quit->setGeometry(430,445, 87, 81);
    this->quit->setObjectName("menuquit");
    this->start->setObjectName("menustart");
    this->start->setStyleSheet("#menustart{border-image: url(:/new/prefix1/start.png)}");
    this->quit->setStyleSheet("#menuquit{border-image: url(:/new/prefix1/quit.png)}");
    quit-> connect(quit,SIGNAL(clicked()),this,SLOT(close()));
    start->connect(start,SIGNAL(clicked(bool)),this,SLOT(setgame(bool)));
    judge=1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setgame(bool){
    if(judge==1){
    delete quit;
    delete start;
    setStyleSheet("");
    judge--;
    }
    view = new QGraphicsView(this);
    setCentralWidget(view);
    Scene=new QGraphicsScene;
     view->setFixedSize(640,512);
    view->setScene(Scene);
    Scene->setSceneRect(0,0,640,490);

    QPixmap imagebk;
    imagebk.load(":/new/prefix1/bg_clear.png");
    imagebk=imagebk.scaled(680,520, Qt::KeepAspectRatio);
    gamebk=new  QGraphicsPixmapItem;
    gamebk->setPixmap(imagebk);
    Scene->addItem(gamebk);

    QPixmap line;
    line.load(":/new/prefix1/sfieldbg.png");
    line=line.scaled(512*2.45,62*2.45, Qt::KeepAspectRatio);
    gameline=new QGraphicsPixmapItem;
    gameline->setPos(0,122);
    gameline->setPixmap(line);
    Scene->addItem(gameline);
    ////////////////////////////////////////////////////
    QPixmap imgdrum(":/new/prefix1/drum.png");
    imgdrum=imgdrum.scaled(188,120);
    drum=new QGraphicsPixmapItem();
    drum->setPixmap(imgdrum);
    drum->setPos(0,140);
    Scene->addItem(drum);
    ///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
    int  place=640;
    qsrand(QDateTime::currentDateTime ().toTime_t ());
    int decide;
    for(int i=0;i<9;i++){
        whichisbomb[i]=0;
    }
    for(int i=0;i<9;i++){
         qsrand(QDateTime::currentDateTime ().toTime_t ());
         decide=qrand()%6;
        if(decide==5){
          whichisbomb[i]=1;
          qsrand(QDateTime::currentDateTime ().toTime_t ());
          int n=qrand()%4+1;
          place=place+70*n;
           source[i].load(":/new/prefix1/bomb.png");
          source[i]=source[i].scaled(72,82,Qt::IgnoreAspectRatio);
          image[i]=new QGraphicsPixmapItem();
          image[i]->setPixmap(source[i]);
          image[i]->setPos(place,150);
          Scene->addItem(image[i]);
        }
        else{
            qsrand(QDateTime::currentDateTime ().toTime_t ());
            int n=qrand()%4+1;
             place=place+70*n;
           source[i].load(":/new/prefix1/22323.png");
           source[i]=source[i].scaled(80,80,Qt::IgnoreAspectRatio);
           image[i]=new QGraphicsPixmapItem();
           image[i]->setPixmap(source[i]);
         image[i]->setPos(place,150);
           Scene->addItem(image[i]);
        }
        firstplace[i]=place;
    }
    last=firstplace[8];
    current=0;
    countsec=new QTimer;
    countsec->connect(countsec,SIGNAL(timeout()),this,SLOT(changeclock()));
    countsec->start(1000);
    ///////////////////////////////////////////////////////////////////////////////////
    change=new QTimer;
    change->connect(change,SIGNAL(timeout()),this,SLOT(movepicture()));
    change->start(3);
   //////////////////////////////////////////////////
    QPixmap img(":/new/prefix1/clock.png");
    img=img.scaled(130,100);
    clockimg=new QGraphicsPixmapItem();
    clockimg->setPixmap(img);
    clockimg->setPos(493,20);
    Scene->addItem(clockimg);
    /////////////////////////////////////////////////
    totaltime=30;
    clock=new QLabel(this);
    QString Str="Total time:\n       ";
    Str=Str+QString::number(totaltime);
    clock->setText(Str);
    clock->setFont(QFont("Time",12,QFont::Bold));
    clock->setGeometry(522,58,100,50);
    clock->show();
    ////////////////////////////////////////////////
    Score=new QLabel(this);
    yourscore=0;
    QString score="Score:";
    score=score+QString::number(yourscore);
    Score->setText(score);
    Score->setFont(QFont("Time",25,QFont::Bold));
    Score->setGeometry(10,-10,150,100);
    Score->show();
}

void MainWindow::movepicture(){
    qsrand(QDateTime::currentDateTime ().toTime_t ());
    for(int i=0;i<9;i++){
        firstplace[i]= firstplace[i]-1;
        image[i]->setPos(firstplace[i],150);
    }
    last=last-1;
    for(int i=0;i<9;i++){
        if(firstplace[i]<-60){
            int decide;
            qsrand(QDateTime::currentDateTime ().toTime_t ());
            decide=qrand()%6;
            if(decide==5){
                qsrand(QDateTime::currentDateTime ().toTime_t ());
                int n=qrand()%4+1;
                last=last+70*n;
                //moveplace=firstplace[last]+90*n;
                source[current].load(":/new/prefix1/bomb.png");
                source[current]=source[current].scaled(72,82,Qt::IgnoreAspectRatio);
                image[current]->setPixmap(source[current]);
                 image[current]->setPos(last,150);
                 whichisbomb[current]=1;
            }
            else{
                 qsrand(QDateTime::currentDateTime ().toTime_t ());
                int n=qrand()%4+1;
                last=last+70*n;
                 //moveplace=firstplace[last]+90*n;
                 source[current].load(":/new/prefix1/22323.png");
                 source[current]=source[current].scaled(80,80,Qt::IgnoreAspectRatio);
                 image[current]->setPixmap(source[current]);
                 image[current]->setPos(last,150);
                 whichisbomb[current]=0;
            }
            firstplace[current]=last;
            current++;
            if(current>8){
                current=0;
            }
        }
    }
}
void MainWindow::changeclock(){
    QString Str="Total time:\n       ";
    Str=Str+QString::number(totaltime);
    clock->setText(Str);
   //clock->setGeometry(518,76,100,50);
   clock->show();
    --totaltime;
   if(totaltime<0){
       change->stop();
       countsec->stop();
         final=new myDialog(this);
         QString finalscore="Final Score:\n";
         finalscore=finalscore+QString::number(yourscore);
         final->Score->setText(finalscore);
         final->restart->connect(final->restart,SIGNAL(clicked()),this,SLOT(restartgame()));
         final->exit->connect(final->exit,SIGNAL(clicked()),this,SLOT(close()));
        final->show();
   }
}
void MainWindow::keyPressEvent(QKeyEvent *keyevent){
         if(keyevent->key() == Qt::Key_A&&totaltime>0){                             //////RIGHT
            for(int i=0;i<9;i++){
                if(whichisbomb[i]==0){
                if(25<firstplace[i]&&firstplace[i]<90){
                    int decide;
                    qsrand(QDateTime::currentDateTime ().toTime_t ());
                    decide=qrand()%6;
                    if(decide==5){
                        qsrand(QDateTime::currentDateTime ().toTime_t ());
                        int n=qrand()%4+1;
                        last=last+70*n;
                       // moveplace=firstplace[last]+90*n;
                        source[current].load(":/new/prefix1/bomb.png");
                        source[current]=source[current].scaled(72,82,Qt::IgnoreAspectRatio);
                        image[current]->setPixmap(source[current]);
                         image[current]->setPos(last,150);
                         whichisbomb[current]=1;
                    }
                    else{
                        qsrand(QDateTime::currentDateTime ().toTime_t ());
                        int n=qrand()%4+1;
                        last=last+70*n;
                         //moveplace=firstplace[last]+90*n;
                         source[current].load(":/new/prefix1/22323.png");
                         source[current]=source[current].scaled(80,80,Qt::IgnoreAspectRatio);
                         image[current]->setPixmap(source[current]);
                         image[current]->setPos(last,150);
                         whichisbomb[current]=0;
                    }
                    firstplace[current]=last;
                    current++;
                    if(current>8){
                        current=0;
                    }
                       yourscore++;
                       QString score="Score:";
                       score=score+QString::number(yourscore);
                       Score->setText(score);
                       Score->setFont(QFont("Time",25,QFont::Bold));
                       Score->setGeometry(10,-10,150,100);
                        Score->show();
            }
            }
             }
}
         if(keyevent->key()==Qt::Key_D&&totaltime>0){                             //////BOMB
             for(int i=0;i<9;i++){
                  if(whichisbomb[i]==1){
                 if(25<firstplace[i]&&firstplace[i]<80){
                     int decide;
                     qsrand(QDateTime::currentDateTime ().toTime_t ());
                     decide=qrand()%6;
                     if(decide==5){
                        qsrand(QDateTime::currentDateTime ().toTime_t ());
                         int n=qrand()%4+1;
                         last=last+70*n;
                         //moveplace=firstplace[last]+90*n;
                         source[current].load(":/new/prefix1/bomb.png");
                         source[current]=source[current].scaled(72,82,Qt::IgnoreAspectRatio);
                         image[current]->setPixmap(source[current]);
                          image[current]->setPos(last,150);
                          whichisbomb[current]=1;
                     }
                     else{
                         qsrand(QDateTime::currentDateTime ().toTime_t ());
                         int n=qrand()%4+1;
                          last=last+70*n;
                         // moveplace=firstplace[last]+90*n;
                          source[current].load(":/new/prefix1/22323.png");
                          source[current]=source[current].scaled(80,80,Qt::IgnoreAspectRatio);
                          image[current]->setPixmap(source[current]);
                          image[current]->setPos(last,150);
                          whichisbomb[current]=0;
                     }
                     firstplace[current]=last;
                     current++;
                     if(current>8){
                         current=0;
                     }
                     int a;
                     a=qrand()%5;
                     if(a==1){
                         yourscore=yourscore+5;
                     }
                     else{
                     yourscore--;
                     }
                     QString score="Score:";
                     score=score+QString::number(yourscore);
                     Score->setText(score);
                     Score->setFont(QFont("Time",25,QFont::Bold));
                     Score->setGeometry(10,-10,150,100);
                      Score->show();
                 }
                  }
                    }
                 }
}

void MainWindow::restartgame(){
   ////////////////////////////////////////////// //final->close();
    delete final->restart;
     delete final->exit;
     delete final->Score;
     delete final;
    delete gamebk;
    delete gameline;
   delete drum;
    for(int i=0;i<9;i++){
        delete image[i];
    }
    delete countsec;
    delete change;
   delete clockimg;
   delete clock;
   delete Score;
   delete Scene;
     delete view;
    setgame(true);

}







