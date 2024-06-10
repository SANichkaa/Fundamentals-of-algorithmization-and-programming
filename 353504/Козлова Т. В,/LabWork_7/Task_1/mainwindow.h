#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "circledeque.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void addPathToImage();
    void addName();

private slots:
    void on_prevButton_2_clicked();

    void on_nextButton_2_clicked();

    void on_autoButton_2_clicked();

    void updateAuto();

private:
    Ui::MainWindow *ui;
    CircleDeque<QString> pathToImage;
    CircleDeque<QString> name;
    CircleDeque<QString>::iterator iterImage;
    CircleDeque<QString>::iterator iterName;
    QTimer *autoTimer;
};
#endif // MAINWINDOW_H
