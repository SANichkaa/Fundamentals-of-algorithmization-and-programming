#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
    ui->median->clear();
    list.clear();
    output.clear();
    QString text = ui->lineEdit->text();
    QStringList listText = text.split(' ');
    for (const QString& str : listText) {
        bool ok;
        int m = str.toInt(&ok);
        if(ok){
            list.append(m);
        }
    }
    output = findMedians(list);
    for(int i = 0; i < output.size(); ++i){
        ui->median->setText(ui->median->text() + QString::number(output[i]) + " ");
    }
}

double MainWindow::medianOfThree(const QList<int> &triplet)
{
    QList<int> sortedTriplet = triplet;
    std::sort(sortedTriplet.begin(), sortedTriplet.end());
    return sortedTriplet[1];
}

double MainWindow::meanOfSubset(const QList<int> &subset)
{
    double sum = std::accumulate(subset.begin(), subset.end(), 0.0);
    return sum / subset.size();
}

QList<double> MainWindow::findMedians(const QList<int> &a)
{
    QList<double> b;
    int n = a.size();

    for (int i = 0; i < n; i += 3) {
        if (i + 2 < n) {
            QList<int> triplet = {a[i], a[i + 1], a[i + 2]};
            double median = medianOfThree(triplet);
            b.append(median);
        } else {
            QList<int> subset = a.mid(i);
            double mean = meanOfSubset(subset);
            b.append(mean);
        }
    }

    return b;
}

