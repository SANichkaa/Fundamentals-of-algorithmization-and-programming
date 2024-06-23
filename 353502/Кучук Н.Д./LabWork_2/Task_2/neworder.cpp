#include "neworder.h"
#include "ui_neworder.h"

NewOrder::NewOrder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NewOrder)
{
    ui->setupUi(this);
}

NewOrder::~NewOrder()
{
    delete ui;
}

void NewOrder::loadOrder(QList<MenuItem *> *menuItems)
{
    this->menuItems = menuItems;
    QSet<QString> categories;
    ui->tableWidget->setRowCount(menuItems->size());
    for(auto i = 0; i < menuItems->size(); ++i) {
        MenuItem* item = (*menuItems)[i];
        OrderWidget *order = new OrderWidget(item);
        connect(order, &OrderWidget::addDishes, this, &NewOrder::addDishes);
        ui->tableWidget->setCellWidget(i, 0, order);
        ui->tableWidget->setRowHeight(i, 50);
        categories.insert(item->getCategory());
    }
    ui->menuComboBox->addItem("All");
    for (const QString &category : categories) {
        ui->menuComboBox->addItem(category);
    }
}

void NewOrder::addDishes(QString dishes, double price)
{
    ui->orderText->setText(ui->orderText->text() + dishes);
    this->price += price;
    ui->price->setText(QString::number(this->price));
}

void NewOrder::on_menuComboBox_currentTextChanged(const QString &arg1)
{
    ui->tableWidget->clearContents();
    int j = 0;
    for (auto i = 0; i < menuItems->size(); ++i){
        MenuItem* item = (*menuItems)[i];
        if(arg1 == "All" || arg1 ==item->getCategory()){
            if (j >= ui->tableWidget->rowCount()) {
                ui->tableWidget->insertRow(j);
            }
            OrderWidget *order = new OrderWidget(item);
            connect(order, &OrderWidget::addDishes, this, &NewOrder::addDishes);
            ui->tableWidget->setCellWidget(j, 0, order);
            ui->tableWidget->setRowHeight(j, 50);
            ++j;
        }
    }
    ui->tableWidget->setRowCount(j);
}


void NewOrder::on_pushButton_clicked()
{
    if(price != 0.0){
        emit addOrder(ui->orderText->text(), price, ui->tableNumber->value());
    }
    price = 0.0;
    ui->orderText->setText("");
    ui->price->setText(QString::number(this->price));
    this->hide();
}

