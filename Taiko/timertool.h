#ifndef TIMERTOOL_H
#define TIMERTOOL_H
#include<QtCore>
#include <QTime>
#include <QTimer>

class Timertool :public QObject
{
    Q_OBJECT
public:
    Timertool();
    QTimer* timer;
public slots:
    void timetool();
};

#endif // TIMERTOOL_H
