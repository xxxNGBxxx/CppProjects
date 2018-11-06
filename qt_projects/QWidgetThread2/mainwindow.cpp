#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , text(new QTextEdit)
    , btnRight(new QPushButton("stop"))
    , btnLeft(new QPushButton("start"))
    , thread1(new ThreadFirst)
    , thread2(new QThread)
{
    QGridLayout* grid = new QGridLayout;

    grid->setMargin(5);
    grid->setSpacing(5);
    grid->addWidget(text,0,0,1,2);
    grid->addWidget(btnLeft,1,0);
    grid->addWidget(btnRight,1,1);
    this->setLayout(grid);

    connect(btnLeft,&QPushButton::clicked,this,[this](){
    thread1->start();

    Worker* worker = new Worker;
    worker->moveToThread(thread2);

    connect(thread2, &QThread::finished,thread2,&QThread::deleteLater);

    connect(thread2, &QThread::started,worker,&Worker::run);

    thread2->start();
    });

    connect(btnRight,&QPushButton::clicked,this,[this](){
    thread1->quit();
    thread2->quit();
    });

}


