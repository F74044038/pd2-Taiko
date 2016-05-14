#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("太鼓達人");
    w.setWindowIcon(QIcon(":/new/prefix1/123.jpeg"));
    w.setFixedHeight(512);
    w.setFixedWidth(640);
    w.show();

    return a.exec();
}
