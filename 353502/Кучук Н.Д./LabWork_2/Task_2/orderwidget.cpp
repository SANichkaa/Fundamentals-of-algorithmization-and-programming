#include "orderwidget.h"
#include "ui_orderwidget.h"

OrderWidget::OrderWidget(MenuItem * item, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OrderWidget)
{
    ui->setupUi(this);
    ui->name->setText(item->getName());
    ui->price->setText(QString::number(item->getPrice()));
    totalPrice = item->getPrice();
    this->item = item;

}

OrderWidget::~OrderWidget()
{
    delete ui;
}

void OrderWidget::on_pushButton_clicked()
{
    QString order = QString("%1 (%2); ").arg(item->getName(), QString::number(ui->spinBox->value()));
    item->increaseOrdersNum(ui->spinBox->value());
    emit addDishes(order,  totalPrice * ui->spinBox->value());
    ui->spinBox->setValue(1);
}

