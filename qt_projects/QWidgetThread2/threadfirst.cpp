#include "threadfirst.h"

ThreadFirst::ThreadFirst(QObject* parent)
    : QThread(parent)
{

}


void ThreadFirst::run(){

    QTimer* timer = new QTimer;

    connect(this,&ThreadFirst::finished,timer,&QTimer::deleteLater);

    connect(timer,&QTimer::timeout,this,[](){
        qDebug().noquote() << 'a';
    });

    timer->start(100);

    exec();
}
