#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Queue.h"

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QListWidget>

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
    void pop_front();
    void randomNambers();
    void displayQueue(QListWidget *listWidget,const Queue &queue);
    void minMax();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    Queue queue1;
    Queue queue2;
    Queue queue3;

};
#endif // MAINWINDOW_H
