#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cstdlib> // для rand()
#include <ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::displayQueue(QListWidget *QueueListWidget,const Queue &queue) {
    QueueListWidget->clear();
    for (int i = 0; i < queue.GetSize(); ++i) {
        int num = queue.peek(i);
        QueueListWidget->addItem(QString::number(num));
    }
}

void MainWindow::minMax()
{

}










/*
10.Создать две двухсвязные очереди из случайных целых чисел. Вместо
элементов первой очереди, заключенных между максимальным и
минимальным, вставить вторую очередь.

*/

void MainWindow::on_pushButton_clicked()
{
    queue1.clearing();
    queue1.FillQueueRandomly(ui->spinBox->value());
    displayQueue(ui->listWidget, queue1);

    queue2.clearing();
    queue2.FillQueueRandomly(ui->spinBox->value());
    displayQueue(ui->listWidget_2, queue2);
}


void MainWindow::on_pushButton_2_clicked()
{
    queue1.FillQueueRandomly(ui->spinBox->value());
    displayQueue(ui->listWidget, queue1);
}


void MainWindow::on_pushButton_3_clicked()
{
    queue2.FillQueueRandomly(ui->spinBox->value());
    displayQueue(ui->listWidget_2, queue2);
}


void MainWindow::on_pushButton_5_clicked()
{
    queue1.pop_front();
    displayQueue(ui->listWidget, queue1);
}


void MainWindow::on_pushButton_4_clicked()
{
    queue2.pop_front();
    displayQueue(ui->listWidget_2, queue2);
}


void MainWindow::on_pushButton_6_clicked()
{
    queue1.insertDeque(ui->listWidget_3, queue1,queue2);
   // displayQueue(ui->listWidget_3, queue1);
}

