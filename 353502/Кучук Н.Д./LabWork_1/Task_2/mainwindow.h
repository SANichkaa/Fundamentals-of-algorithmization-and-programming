#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>
#include "paintscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    PaintScene *scene;
    QTimer *timer;
    QTimer *rotateTimer;


private:
    void resizeEvent(QResizeEvent * event);
    void btnEnabled(bool);

private slots:
    void slotTimer();
    void updateXBrowser();
    void updateYBrowser();
    void updatePerimeter();
    void updateSquare();
    void on_rombusBtn_clicked();
    void on_squareBtn_clicked();
    void on_circleBtn_clicked();
    void on_triangleBtn_clicked();
    void on_hexagonBtn_clicked();
    void on_star1Btn_clicked();
    void on_star2Btn_clicked();
    void on_lineBtn_clicked();
    void on_movingBtn_clicked();
    void on_rotateRightBtn_clicked();
    void on_rotateLeftBtn_clicked();
    void on_sizePlusBtn_clicked();
    void on_sizeMinusBtn_clicked();
    void on_clearBtn_clicked();
};

#endif // MAINWINDOW_H
