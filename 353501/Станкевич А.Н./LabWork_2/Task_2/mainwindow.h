#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include "patient.h"
QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int cnt2;
    Patient *patient = new Patient[100];
    QFile file;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updatetable();

public slots:


    void on_button_2_clicked();

    void on_findbyamountbutton_2_clicked();

    void on_selectfilebutton_2_clicked();

    void on_cancell_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
