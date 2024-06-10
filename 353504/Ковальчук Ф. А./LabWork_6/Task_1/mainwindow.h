#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Plant.h>

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

private slots:


    void on_nextButton_clicked();

    void on_pushInputButton_clicked();

    void on_mBox_clicked();

    void on_fBox_clicked();

    void on_tBox_clicked();

private:
    Ui::MainWindow *ui;
    Plant plantInit;
    Plant plantFields;
    Plant plantKeyboard;
    Plant* pPlant;
    Plant refPlant;

    int plantIndex = -1;
};
#endif // MAINWINDOW_H
