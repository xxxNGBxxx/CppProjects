#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{

}

void Worker::run(){
QTimer* timer = new QTimer;

connect(QThread::currentThread(),&QThread::finished,timer,&QTimer::deleteLater);

connect(timer,&QTimer::timeout,this,[](){
    qDebug().noquote() << 'b';
});

timer->start(100);

}
