#ifndef ORDER_H
#define ORDER_H
#include <QString>

class Order
{
public:
    Order(const QString& text = "", double price = 0.0, int tableNum = 0) : text(text), price(price), tableNum(tableNum)
    {}
    QString getText() const { return text; }
    double getPrice() const { return price; }
    int getTableNum() const {return tableNum;}
    static bool compareByPrice(const Order* a, const Order* b) {return a->price > b->price;}
private:
    QString text;
    double price;
    int tableNum;
};

#endif // ORDER_H
