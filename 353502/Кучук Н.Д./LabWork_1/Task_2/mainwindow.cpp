#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new PaintScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    timer = new QTimer();
    //rotateTimer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(200);
    connect(scene, &PaintScene::centerXChanged, this, &MainWindow::updateXBrowser);
    connect(scene, &PaintScene::centerYChanged, this, &MainWindow::updateYBrowser);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::updateXBrowser(){
    QString text = QString::number(scene->centerX(), 'f', 2);
    ui->centerX->setText(text);
    ui->Perimetr->setText("для отображения купите премиум");
    ui->Square->setText("для отображения купите премиум");
}

void MainWindow::updateYBrowser(){
    QString text = QString::number(scene->centerY(), 'f', 2);
    ui->centerY->setText(text);
}

void MainWindow::updatePerimeter(){
    QString text = QString::number(scene->perimeter(), 'f', 2);
    ui->centerY->setText(text);
}

void MainWindow::updateSquare(){
    QString text = QString::number(scene->square(), 'f', 2);
    ui->centerY->setText(text);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(200);
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_rombusBtn_clicked()
{
    btnEnabled(1);
    scene->setToDo(PaintScene::Paint);
    scene->setTypeFigure(PaintScene::RombType);
}

void MainWindow::on_circleBtn_clicked()
{
    btnEnabled(1);
    scene->setToDo(PaintScene::Paint);
    scene->setTypeFigure(PaintScene::CircleType);
}

void MainWindow::on_squareBtn_clicked()
{
    btnEnabled(1);
    scene->setToDo(PaintScene::Paint);
    scene->setTypeFigure(PaintScene::SquareType);
}

void MainWindow::on_star1Btn_clicked()
{
    btnEnabled(1);
    scene->setToDo(PaintScene::Paint);
    scene->setTypeFigure(PaintScene::Star5Type);
}


void MainWindow::on_star2Btn_clicked()
{
    btnEnabled(1);
    scene->setToDo(PaintScene::Paint);
    scene->setTypeFigure(PaintScene::Star6Type);
}


void MainWindow::on_triangleBtn_clicked()
{
    btnEnabled(1);
    scene->setToDo(PaintScene::Paint);
    scene->setTypeFigure(PaintScene::TriangleType);

}

void MainWindow:: on_hexagonBtn_clicked(){
    btnEnabled(1);
    scene->setToDo(PaintScene::Paint);
    scene->setTypeFigure(PaintScene::HexagonType);
}

void MainWindow:: on_lineBtn_clicked(){
    btnEnabled(0);
    scene->setToDo(PaintScene::Paint);
    scene->setTypeFigure(PaintScene::LineType);

}

void MainWindow:: on_movingBtn_clicked()
{
    scene->setToDo(PaintScene::Moving);
    QList<QGraphicsItem*> selectedItems = scene->selectedItems();
    for(auto i = selectedItems.begin(); i != selectedItems.end(); ++i ){
        //scene->removeItem(*i);
        qDebug() << *i;
    }

}

void MainWindow:: on_sizePlusBtn_clicked(){
    scene->setToDo(PaintScene:: SizePlus);
}

void MainWindow:: on_sizeMinusBtn_clicked(){
    scene->setToDo(PaintScene:: SizeMinus);
}

void MainWindow:: on_rotateRightBtn_clicked()
{
    scene->setToDo(PaintScene::RotateRight);
}

void MainWindow:: on_rotateLeftBtn_clicked()
{
    scene->setToDo(PaintScene::RotateLeft);
}

void MainWindow:: btnEnabled(bool enabled){
    if (scene->typeFigure() == PaintScene::LineType){
        QList<QGraphicsItem*> items = scene->items();
        qDeleteAll(items);
    }
    ui->rotateLeftBtn->setEnabled(enabled);
    ui->rotateRightBtn->setEnabled(enabled);
    ui->sizeMinusBtn->setEnabled(enabled);
    ui->sizePlusBtn->setEnabled(enabled);
    ui->movingBtn->setEnabled(enabled);
}

void MainWindow:: on_clearBtn_clicked(){
    QList<QGraphicsItem*> items = scene->items();
    qDeleteAll(items);
}




