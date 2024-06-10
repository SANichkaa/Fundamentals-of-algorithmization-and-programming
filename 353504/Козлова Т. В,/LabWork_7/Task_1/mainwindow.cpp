#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , iterImage(pathToImage.begin())
    , iterName(name.begin())
    , autoTimer(new QTimer(this))
{
    ui->setupUi(this);
    addPathToImage();
    addName();
    connect(autoTimer, &QTimer::timeout, this, &MainWindow::updateAuto);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPathToImage()
{
    pathToImage.push_back("QLabel { image: url(:/new/img/img/bavarskaya.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/img/chicken-bomboni.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/img/krevetki.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/img/polovinki.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/img/sirnaya.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/img/vetchina.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/img/zhulien.jpg);}");
    //pathToImage.push_back("QLabel { image: url(:/new/img/image/Gorbachev.jpg);}");
}

void MainWindow::addName()
{
    name.push_back("Баварская");
    name.push_back("Чикен-Бомбони");
    name.push_back("Креветки со сладким чили");
    name.push_back("Пицца из половинок");
    name.push_back("Сырная");
    name.push_back("Ветчина и огурчики");
    name.push_back("Жюльен");
    //name.push_back("М.С.Горбачёв");
}

void MainWindow::on_prevButton_2_clicked()
{
    --iterImage;
    //--iterDate;
    --iterName;
    ui->nameLabel_3->setStyleSheet(*iterImage);
    ui->nameLabel_2->setText(*iterName);
}

void MainWindow::on_nextButton_2_clicked()
{
    ++iterImage;
    ++iterName;
    ui->nameLabel_3->setStyleSheet(*iterImage);
    ui->nameLabel_2->setText(*iterName);
}

void MainWindow::on_autoButton_2_clicked()
{
    (ui->autoButton_2->isChecked()) ? autoTimer->start(ui->spinBox_2->value()) : autoTimer->stop();
}

void MainWindow::updateAuto()
{
    ++iterImage;
    ++iterName;
    ui->nameLabel_3->setStyleSheet(*iterImage);
    ui->nameLabel_2->setText(*iterName);
}
