#ifndef MENUITEM_H
#define MENUITEM_H
#include <QString>
#include <readfile.h>

class MenuItem {
public:
    MenuItem(const QString& name = "", const QString& category = "", double price = 0.0)
        : name(name), category(category), price(price) {}

    QString getName() const { return name; }
    QString getCategory() const { return category; }
    double getPrice() const { return price; }
    int getOrdersNum() const {return ordersNum;}
    void increaseOrdersNum(int n){ ordersNum += n;}
    static bool compareByOrders(const MenuItem* a, const MenuItem* b) {return a->ordersNum > b->ordersNum;}
private:
    QString name;
    QString category;
    double price;
    int ordersNum = 0;
};
#endif // MENUITEM_H
