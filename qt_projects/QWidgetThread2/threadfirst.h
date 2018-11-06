#ifndef THREADFIRST_H
#define THREADFIRST_H

#include <QThread>
#include <QtWidgets>

class ThreadFirst : public QThread
{
    Q_OBJECT
public:
    ThreadFirst(QObject* parent = nullptr);
    ~ThreadFirst() override = default;
    void run() override;
};

#endif // THREADFIRST_H
