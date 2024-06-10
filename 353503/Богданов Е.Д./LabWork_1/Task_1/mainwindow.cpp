#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_gosolder = new GoSolder();
    ui->graphicsView->setScene(m_gosolder);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(!start){

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_scene()));
    timer->start(500);
    start = 1;

    }

}

void MainWindow::update_scene()
{
    if(step==10){

    timer->stop();
    m_gosolder->turn(step, x, y);
    ui->graphicsView->setScene(m_gosolder);
    f_on = 1;

    }
    else {

    step++;
    shadow^=1;
    m_gosolder->move(step, x, y, shadow);
    ui->graphicsView->setScene(m_gosolder);

    }
}

void MainWindow::on_pushButton_2_clicked()
{

    if(f_on){

        m_gosolder->press_f(step, x, y);
        ui->graphicsView->setScene(m_gosolder);


    }


}







void MainWindow::on_pushButton_3_clicked()
{
    exit(0);
}




