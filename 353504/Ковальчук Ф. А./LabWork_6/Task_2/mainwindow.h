#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <FileLoader.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void printMenu();
    void printChoice();

private slots:
    void on_pushButton_menu_clicked();


private:
    Ui::MainWindow *ui;
    FileLoader* pFileLoader;

    QString output;
};
#endif // MAINWINDOW_H
