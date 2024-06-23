#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    task1 = new Task1();
    task2 = new Task2();
    task3 = new Task3();
    task4 = new Task4();
    task5 = new Task5();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_task1_clicked()
{
    task1->show();
}


void MainWindow::on_task2_clicked()
{
    task2->show();
}


void MainWindow::on_task3_clicked()
{
    task3->show();
}


void MainWindow::on_task4_clicked()
{
    task4->show();
}


void MainWindow::on_task5_clicked()
{
    task5->show();
}

