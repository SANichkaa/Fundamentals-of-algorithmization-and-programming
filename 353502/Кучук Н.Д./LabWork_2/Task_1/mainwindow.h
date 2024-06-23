#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QListWidget>
#include "date.h"
#include "readfile.h"

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

public slots:
    void dateData(QString string);

private slots:
    void on_addData_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_dateEdit_userDateChanged(const QDate &date);

private:
    Ui::MainWindow *ui;
    QMessageBox msgBox;
    void infoUpdate(Date, Date);
    Date today;
    Date birthday;
    ReadFile *readFile;
    bool addData(QString);

};
#endif // MAINWINDOW_H
