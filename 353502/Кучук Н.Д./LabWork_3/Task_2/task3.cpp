#include "task3.h"
#include "ui_task3.h"

Task3::Task3(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task3)
{
    ui->setupUi(this);
}

Task3::~Task3()
{
    delete ui;
}

int Task3::countDigits(int n)
{
    if (n == 0) return 0;
    return 1 + countDigits(n / 10);
}

int Task3::reverseNumber(int n, int numDigits)
{
    if (n == 0) return 0;
    int lastDigit = n % 10;
    return lastDigit * std::pow(10, numDigits - 1) + reverseNumber(n / 10, numDigits - 1);
}

int Task3::reverseNumber(int n)
{
    int numDigits = countDigits(n);
    return reverseNumber(n, numDigits);
}

void Task3::on_pushButton_clicked()
{
    QString inputText = ui->lineEdit->text();
    bool ok;
    int number = inputText.toInt(&ok);

    if (ok) {
        QString binaryRepresentation = QString::number(reverseNumber(number));
        ui->answer->setText("Result: " + binaryRepresentation);
    } else {
        ui->answer->setText("Invalid input!");
    }
}

