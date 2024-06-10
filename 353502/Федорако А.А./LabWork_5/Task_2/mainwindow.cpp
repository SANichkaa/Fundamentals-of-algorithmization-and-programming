#include "mainwindow.h"
#include <QDebug>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  QString line = ui->lineEdit->text();
  CustomString string(line);
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText((QString)string.front());
}

void MainWindow::on_pushButton_2_clicked() {
  QString line = ui->lineEdit->text();
  CustomString string(line);
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText((QString)string.back());
}

void MainWindow::on_pushButton_3_clicked() {
  QString line = ui->lineEdit->text();
  int number = ui->spinBox->value();
  CustomString string(line);
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText((QString)string.at(number));
}

void MainWindow::on_pushButton_6_clicked() {
  QString line = ui->lineEdit->text();
  int number = ui->spinBox->value();
  CustomString string(line);
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText((QString)string[number]);
}

void MainWindow::on_pushButton_4_clicked() {
  QString line = ui->lineEdit->text();
  CustomString string(line);
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText(QString::number(string.size()));
}

void MainWindow::on_pushButton_5_clicked() {
  QString line = ui->lineEdit->text();
  CustomString string(line);
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText(QString::number(string.capacity()));
}

void MainWindow::on_pushButton_7_clicked() {
  QString line = ui->lineEdit->text();
  CustomString string(line);
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText(QString::number(string.empty()));
}

void MainWindow::on_pushButton_9_clicked() {
  QString line = ui->lineEdit->text();
  QString temp = ui->lineEdit_2->text();
  CustomString string(line);
  CustomString tempString(temp);
  string.swap(tempString);
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText(temp);
}
