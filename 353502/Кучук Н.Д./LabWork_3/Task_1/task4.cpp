#include "task4.h"
#include "ui_task4.h"

Task4::Task4(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task4)
{
    ui->setupUi(this);
    hanoi(1, 'A', 'C', 'B');
}

Task4::~Task4()
{
    delete ui;
}

void Task4::moveDisk(int n, char fromPeg, char toPeg)
{
    QString a;
    a = QString("Переместить диск %1 со стержня %2 на стержень %3\n").arg(n).arg(fromPeg).arg(toPeg);
    ui->listWidget->addItem(a);


}

void Task4::hanoi(int n, char fromPeg, char toPeg, char auxPeg)
{
    if (n == 1) {
        moveDisk(n, fromPeg, toPeg); // Базовый случай: перемещаем один диск
        return;
    }

    hanoi(n - 1, fromPeg, auxPeg, toPeg); // Перемещаем n-1 дисков на вспомогательный стержень
    moveDisk(n, fromPeg, toPeg);          // Перемещаем последний диск на целевой стержень
    hanoi(n - 1, auxPeg, toPeg, fromPeg);
}

void Task4::on_spinBox_valueChanged(int arg1)
{
    ui->listWidget->clear();
     hanoi(arg1, 'A', 'C', 'B');
}

