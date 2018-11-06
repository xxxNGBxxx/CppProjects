#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double num_first;
    double  num_second;

private slots:
 void digits_numbers();
 void on_pushButton_dot_clicked();
 void operations();
 void on_pushButton_del_clicked();
 void on_pushButton_equal_clicked();
 void math_operations();
};


#endif // MAINWINDOW_H
