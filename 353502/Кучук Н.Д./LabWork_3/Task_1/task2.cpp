#include "task2.h"
#include "ui_task2.h"

Task2::Task2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task2)
{
    ui->setupUi(this);
}

Task2::~Task2()
{
    delete ui;
}

int Task2::ackermann(int m, int n)
{
    if (m == 0) {
        return n + 1;
    }
    if (n == 0) {
        return ackermann(m - 1, 1);
    }
    return ackermann(m - 1, ackermann(m, n - 1));
}

void Task2::on_pushButton_clicked()
{
    bool ok1, ok2;
    int m = ui->lineEdit->text().toInt(&ok1);
    int n = ui->lineEdit_2->text().toInt(&ok2);

    if (ok1 && ok2 && m < 4) {
        QString binaryRepresentation = QString::number(ackermann(m, n));
        ui->label->setText("Result: " + binaryRepresentation);
    } else {
        ui->label->setText("Invalid input!");
    }
}

