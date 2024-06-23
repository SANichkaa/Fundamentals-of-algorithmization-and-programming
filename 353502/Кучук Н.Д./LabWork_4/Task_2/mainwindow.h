#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sorting.h"
#include <QtCharts>
#include <QTimer>
#include <QElapsedTimer>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);
    void sortData();
    void updateChart();
    void generateList();

private:
    Ui::MainWindow *ui;
    QList<int> *list {new QList<int>};
    Sorting *sort;

    QChartView *chartView;
    QChart *chart;
    QBarSet *barSet;
    QTimer *timer{new QTimer(this)};
    QElapsedTimer *elapsedTimer{new QElapsedTimer()};


};
#endif // MAINWINDOW_H
