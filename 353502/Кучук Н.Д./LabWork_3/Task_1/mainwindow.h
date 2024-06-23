#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <task1.h>
#include <task2.h>
#include <task3.h>
#include <task4.h>
#include <task5.h>
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
    void on_task1_clicked();

    void on_task2_clicked();

    void on_task3_clicked();

    void on_task4_clicked();

    void on_task5_clicked();

private:
    Ui::MainWindow *ui;
    Task1 *task1;
    Task2 *task2;
    Task3 *task3;
    Task4 *task4;
    Task5 *task5;
};
#endif // MAINWINDOW_H
