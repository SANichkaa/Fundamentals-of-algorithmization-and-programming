#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sort = new Sorting();



    // sort->printList(list);
    barSet = new QBarSet("aboba", this);
    *barSet << 100;
    QBarSeries *barSeries = new QBarSeries(this);
    barSeries->append(barSet);
    chart = new QChart();
    chart->addSeries(barSeries);
    QStringList categories;
    for (int i = 0; i < 100; ++i){
        categories << QString:: number(i);
    }
    QBarCategoryAxis *AxisX = new QBarCategoryAxis(this);
    AxisX->append(categories);
    QValueAxis *AxisY = new QValueAxis(this);
    chart->addAxis(AxisX, Qt::AlignBottom);
    barSeries->attachAxis(AxisX);
    chart->addAxis(AxisY, Qt::AlignLeft);
    barSeries->attachAxis(AxisY);
    ui->horizontalLayout->addWidget(new QChartView(chart, this));
    connect(timer, &QTimer::timeout, this, &MainWindow::updateChart);
    generateList();
    connect(ui->sortButton, &QPushButton::clicked, this, &MainWindow::sortData);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::generateList);

    //sort->heapSort(list);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateList()
{
    timer->stop();
    barSet->remove(0, barSet->count());
    list->clear();
    for (int i = 0; i < 100; ++i){
        int n = rand() % 101;
        list->append(n);
        *barSet << n;
    }
}

void MainWindow::sortData()
{
    timer->start(1);
    qint64 elapsedTime;
    switch(ui->sortComboBox->currentIndex()){
    case 0:
        elapsedTimer->start();
        sort->heapSort(list);
        elapsedTime = elapsedTimer->elapsed();
        break;
    case 1:
        elapsedTimer->start();
        sort->quickSort(list, 0, list->size() - 1);
        elapsedTime = elapsedTimer->elapsed();
        break;
    case 2:
        elapsedTimer->start();
        sort->mergeSort(list, 0, list->size() - 1);
        elapsedTime = elapsedTimer->elapsed();
        break;
    }
    ui->time->setText(QString::number(elapsedTime));
    timer->stop();

}

void MainWindow::updateChart()
{
    barSet->remove(0, barSet->count());
    for(int i = 0; i < list->size(); ++i){
        *barSet << (*list)[i];
    }
}



void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    bool ok;
    int m = ui->lineEdit->text().toInt(&ok);
    if(ok){
        int num = sort->binSearch(list, m);
        ui->num->setText(QString::number(num));
        int binPow =  sort->binPow(num, list->size(), m);
        ui->binPow->setText(QString::number(binPow));
    }
    else if(ui->lineEdit->text() ==""){
        ui->num->setText("");
        ui->binPow->setText("");
    }
    else{
        ui->num->setText("Invalid input");
        ui->binPow->setText("");
    }
}

