#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <MenuItem.h>
#include <menu.h>
#include <readfile.h>
#include <neworder.h>
#include <order.h>
#include <algorithm>

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
    void on_menuButton_clicked();

    void on_newOrderButton_clicked();
    void on_sortButton_clicked();

    void on_saveButton_clicked();

public slots:
    void addOrder(QString, double, int);
private:
    Ui::MainWindow *ui;
    Menu *menu;
    NewOrder *order;
    QList<MenuItem*>* menuItems;
    QList<Order*>* orderLists;
    ReadFile *readFile;
    void loadMenu();
    void addWidgetOrder(Order*);
    void sortOrderd();
    void saveOrders();

signals:
    void loadMenuSignal(QList<MenuItem*>*);

};
#endif // MAINWINDOW_H
