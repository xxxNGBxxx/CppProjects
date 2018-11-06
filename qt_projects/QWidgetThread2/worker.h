#ifndef WORKER_H
#define WORKER_H

#include <QtWidgets>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    void run();
signals:

public slots:
};

#endif // WORKER_H
