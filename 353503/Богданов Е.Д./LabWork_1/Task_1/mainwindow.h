#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGridLayout>
#include <QTimer>
#include "gosolder.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void update_scene();
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:

    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    GoSolder* m_gosolder;
    QTimer* timer;
    bool f_on = 0, start = 0, shadow = 0;
    int step = 0, x = -240, y = -200;

};
#endif // MAINWINDOW_H
