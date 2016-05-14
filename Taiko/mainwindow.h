#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include  <QFont>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QDesktopWidget>
#include <QGraphicsScene>
#include  <QGraphicsView>
#include   <QGraphicsItem>
#include    <QImage>
#include     <QGraphicsPixmapItem>
#include    <QComboBox>
#include    <QListWidget>
#include    <QTimer>
#include    <QTime>
#include      <QtCore/QCoreApplication>
#include       <QKeyEvent>
#include         "mydialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
        QGraphicsScene* Scene;
        QPixmap source[9];
        QGraphicsPixmapItem  *image[9];
        QGraphicsPixmapItem * gamebk;
        QGraphicsPixmapItem* gameline;
        QTimer * change;
        QTimer* countsec;
        QLabel * clock;
        QLabel* Score;
        QGraphicsPixmapItem * clockimg;
        QGraphicsPixmapItem*  drum;
        QGraphicsView  *view ;
private slots:
    void setgame(bool);
      void movepicture();
      void changeclock();
      void restartgame();
private:
    Ui::MainWindow *ui;
    QPushButton *quit;
    QPushButton *start;
    int firstplace[9];
    int whichisbomb[9];
    int totaltime;
    int yourscore;
    int judge;
    int moveplace;
    int last;
    int current;
    void keyPressEvent(QKeyEvent *keyevent);
    myDialog *final;
};

#endif // MAINWINDOW_H
