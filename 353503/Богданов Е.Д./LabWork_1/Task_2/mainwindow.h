#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include <QGraphicsItemGroup>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QResizeEvent>
#include "scenka.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:

    void TimerSlot();

    void Dannie();

    void on_Rect_triggered();

    void on_Squart_triggered();

    void on_Triangl_pram_triggered();

    void on_Triangl_ravn_bedr_triggered();

    void on_Triangl_ravn_stor_triggered();

    void on_Fife_star_triggered();

    void on_Six_star_triggered();

    void on_Eught_star_triggered();

    void on_Deleter_triggered();

    void on_Ellips_triggered();

    void on_pushButton_clicked();

    void on_Resize_triggered();

    void on_Move_triggered();

    void on_Krug_triggered();

    void on_action_triggered();

private:
    //void resizeEvent(QResizeEvent *event);

    Ui::MainWindow *ui;
    Scenka* scenka;
    QTimer* timer;
    QTimer* timer_dannie;



};
#endif // MAINWINDOW_H
