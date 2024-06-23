#ifndef NEWORDER_H
#define NEWORDER_H

#include <QWidget>
#include <MenuItem.h>
#include <orderwidget.h>

namespace Ui {
class NewOrder;
}

class NewOrder : public QWidget
{
    Q_OBJECT

public:
    explicit NewOrder(QWidget *parent = nullptr);
    ~NewOrder();
    QList<MenuItem*>* menuItems;

public slots:
    void loadOrder(QList<MenuItem*>* menuItems);
    void addDishes(QString, double);
private slots:
    void on_menuComboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::NewOrder *ui;
    double price = 0;

signals:
    void addOrder(QString, double, int);
};

#endif // NEWORDER_H
