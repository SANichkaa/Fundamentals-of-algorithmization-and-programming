#include "task1.h"
#include "ui_task1.h"

Task1::Task1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task1)
{
    ui->setupUi(this);
}

Task1::~Task1()
{
    delete ui;
}

void Task1::on_pushButton_clicked()
{
    QString inputText = ui->lineEdit->text();
    bool ok;
    int number = inputText.toInt(&ok);

    if (ok) {
        QString binaryRepresentation = decimalToBinary(number);
        ui->answer->setText("Result: " + binaryRepresentation);
    } else {
        ui->answer->setText("Invalid input!");
    }
}

QString Task1::decimalToBinary(int n)
{
    if (n == 0) return "0";
    if (n == 1) return "1";
    return decimalToBinary(n / 2) + QString::number(n % 2);
}

