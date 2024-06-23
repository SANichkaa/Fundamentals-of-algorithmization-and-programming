#ifndef ORDERWIDGET_H
#define ORDERWIDGET_H

#include <QWidget>
#include "MenuItem.h"

namespace Ui {
class OrderWidget;
}

class OrderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OrderWidget(MenuItem*, QWidget *parent = nullptr);
    ~OrderWidget();

private slots:
    void on_pushButton_clicked();

signals:
    void addDishes(QString, double);

private:
    Ui::OrderWidget *ui;
    double totalPrice;
    MenuItem* item;
};

#endif // ORDERWIDGET_H
