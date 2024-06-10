#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scenka(new Scenka())
    , timer(new QTimer())
    , timer_dannie(new QTimer())
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scenka);

    const int time = 100;

    connect(timer, SIGNAL(timeout()), this, SLOT(TimerSlot()));
    timer->start(time);

    connect(timer_dannie, SIGNAL(timeout()), this, SLOT(Dannie()));
    timer_dannie->start(time);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TimerSlot()
{
    timer->stop();
    scenka->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
}

void MainWindow::Dannie()
{
    ui->Perimetr->setText(scenka->Get_Perim());
    ui->Plohad->setText(scenka->Get_Ploshad());
    ui->Zenter_mass->setText(scenka->Get_Zentr_mass());
}

void MainWindow::on_Rect_triggered()
{
    scenka->Set_figura("Rect");
}

void MainWindow::on_Squart_triggered()
{
    scenka->Set_figura("Squart");
}

void MainWindow::on_Triangl_pram_triggered()
{
    scenka->Set_figura("Triangul_pram");
}

void MainWindow::on_Triangl_ravn_bedr_triggered()
{
    scenka->Set_figura("Triangul_ravn_bedr");
}

void MainWindow::on_Triangl_ravn_stor_triggered()
{
    scenka->Set_figura("Triangul_ravn_stor");
}

void MainWindow::on_Fife_star_triggered()
{
    scenka->Set_figura("Fife_star");
}

void MainWindow::on_Six_star_triggered()
{
    scenka->Set_figura("Six_star");
}

void MainWindow::on_Eught_star_triggered()
{
    scenka->Set_figura("Eught_star");
}

void MainWindow::on_Deleter_triggered()
{
    scenka->Set_figura("Deleter");
}

void MainWindow::on_Ellips_triggered()
{
    scenka->Set_figura("Ellips");
}

void MainWindow::on_pushButton_clicked()
{
    exit(0);
}

void MainWindow::on_Resize_triggered()
{
    scenka->Set_figura("Resize");
}

void MainWindow::on_Move_triggered()
{
    scenka->Set_figura("Move");
}

void MainWindow::on_Krug_triggered()
{
    scenka->Set_figura("Krug");
}

void MainWindow::on_action_triggered()
{
    scenka->Set_figura("Povorot");
}
