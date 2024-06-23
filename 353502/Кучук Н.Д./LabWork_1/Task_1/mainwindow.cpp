#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    scene = new QGraphicsScene();
    Wheel *wheel = new Wheel();
    scene->addItem(wheel);
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(scene);
    timer = new QTimer();
    timer2 = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);
    connect(timer2, &QTimer::timeout, [&](){scene->advance();});

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimer()
{

}

void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->setText("ПОСТАВЬТЕ ОЦЕНКУ И МЫ МИРНО РАЗОЙДЕМСЯ");
    timer2->start(10);
}

// Квадрат
void MainWindow::on_pushButton_2_clicked()
{
     ui->textBrowser->setText("");
    timer2->stop();
}
