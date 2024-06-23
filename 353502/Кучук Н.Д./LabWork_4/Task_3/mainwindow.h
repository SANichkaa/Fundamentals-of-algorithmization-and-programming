#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QList<int> list;
    QList<double> output;
    double medianOfThree(const QList<int>& triplet);
    double meanOfSubset(const QList<int>& subset);
    QList<double> findMedians(const QList<int>& a);
};
#endif // MAINWINDOW_H
