#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "threadfirst.h"
#include "worker.h"
#include <QThread>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;
protected:

    QTextEdit* text;
    QPushButton* btnRight;
    QPushButton* btnLeft;
    ThreadFirst* thread1;
    QThread* thread2;
};

#endif // MAINWINDOW_H
