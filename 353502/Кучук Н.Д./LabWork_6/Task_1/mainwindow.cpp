#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Employee* empl = new Employee();
    empl->id = ui->spinBox->value();
    empl->salary = ui->doubleSpinBox->value();
    empl->grade = ui->lineEdit->text().toStdString().c_str()[0];
    strncpy(empl->name, ui->lineEdit_2->text().toStdString().c_str(), Employee::nameLength - 1);
    empl->name[Employee::nameLength - 1] = '\0';
    empl->isActive = ui->checkBox->isChecked();
    empl->scores[0] = ui->spinBox_2->value();
    empl->scores[1] = ui->spinBox_3->value();
    empl->scores[2] = ui->spinBox_4->value();
    QString employeeData = QString("ID: %1\nSalary: %2\nGrade: %3\nActive: %4\nName: %5\nScores: %6, %7, %8")
                               .arg(empl->id)
                               .arg(empl->salary)
                               .arg(empl->grade)
                               .arg(empl->isActive ? "Yes" : "No")
                               .arg(empl->name)
                               .arg(empl->scores[0])
                               .arg(empl->scores[1])
                               .arg(empl->scores[2]);
    ui->listWidget->addItem(employeeData);
}

