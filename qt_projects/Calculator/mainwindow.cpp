#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->pushButton_1,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->pushButton_4,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->pushButton_5,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->pushButton_6,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->pushButton_7,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->pushButton_8,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->pushButton_9,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->pushButton_plus_minus,&QPushButton::clicked,this,&MainWindow::operations);
    connect(ui->pushButton_percent,&QPushButton::clicked,this,&MainWindow::operations);
    connect(ui->pushButton_plus,&QPushButton::clicked,this,&MainWindow::math_operations);
    connect(ui->pushButton_mult,&QPushButton::clicked,this,&MainWindow::math_operations);
    connect(ui->pushButton_minus,&QPushButton::clicked,this,&MainWindow::math_operations);
    connect(ui->pushButton_div,&QPushButton::clicked,this,&MainWindow::math_operations);
    connect(ui->pushButton_exit,&QPushButton::clicked,this,&MainWindow::close);

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_div->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::digits_numbers(){
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(ui->label->text().contains('.') && button->text() == '0'){
        new_label = ui->label->text() + button->text();
    }
    else {
        all_numbers = (ui->label->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);
    }
    ui->label->setText(new_label);
}
void MainWindow::operations(){
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(button->text() == "+/-"){
        all_numbers = (ui->label->text().toDouble());
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->label->setText(new_label);
    }

    else if(button->text() == "%"){
        all_numbers = (ui->label->text().toDouble());
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->label->setText(new_label);
    }
}

void MainWindow::on_pushButton_dot_clicked(){
    if(!(ui->label->text().contains('.')))
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::on_pushButton_del_clicked(){
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_div->setChecked(false);
    ui->pushButton_mult->setChecked(false);

    ui->label->setText("0");
}

void MainWindow::on_pushButton_equal_clicked(){
    double label_number;
    QString new_label;
    num_second = ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        label_number = num_first + num_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked()){
        label_number = num_first - num_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_div->isChecked()){
        if(num_second == 0){
            ui->label->setText("0");
        }
        else{
            label_number = num_first / num_second;
            new_label = QString::number(label_number, 'g', 15);

            ui->label->setText(new_label);
        }
            ui->pushButton_div->setChecked(false);
    }

    else if(ui->pushButton_mult->isChecked()){
        label_number = num_first * num_second;
        new_label = QString::number(label_number, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_mult->setChecked(false);
    }
}

void MainWindow::math_operations(){
    QPushButton *button = (QPushButton *)sender();

    num_first = ui->label->text().toDouble();
    ui->label->setText("0");
    button->setChecked(true);
}
