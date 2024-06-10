#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    upd();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::upd()
{
    if(bha.empty())
        ui->em->setText("True");
    else
        ui->em->setText("False");
    if(bhl.empty())
        ui->em2->setText("True");
    else
        ui->em2->setText("False");
}

void MainWindow::on_pushButton_2_clicked()
{
    bha.insert(ui->spinBox->value());
    bhl.insert(ui->spinBox->value());
    upd();
}



void MainWindow::on_pushButton_3_clicked()
{
    bha.clear();
    bhl.clear();
    upd();
}


void MainWindow::on_pushButton_clicked()
{
    std::pair<int,bool>a=bha.extractMax();

    if(a.second==true)
    {
        ui->max->setText(QString::number(a.first));
    }
    else
        ui->max->setText("NOT FOUND");
    a=bhl.get_max();

    if(a.second==true)
    {
        ui->max2->setText(QString::number(a.first));
    }
    else
        ui->max2->setText("NOT FOUND");
    upd();

}

