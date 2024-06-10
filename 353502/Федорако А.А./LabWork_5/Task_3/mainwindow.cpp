#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  bitset = new BitSet(BITSET_SIZE);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText(QString::number(bitset->all()));
}

void MainWindow::on_pushButton_2_clicked() {
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText(QString::number(bitset->any()));
}

void MainWindow::on_pushButton_3_clicked() {
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText(QString::number(bitset->count()));
}

void MainWindow::on_pushButton_4_clicked() {
  ui->plainTextEdit->clear();
  bitset->flip();
}

void MainWindow::on_pushButton_5_clicked() {
  ui->plainTextEdit->clear();
  bitset->flip(ui->spinBox_2->value());
}

void MainWindow::on_pushButton_6_clicked() {
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText(QString::number(bitset->none()));
}

void MainWindow::on_pushButton_7_clicked() {
  ui->plainTextEdit->clear();
  bitset->reset();
}

void MainWindow::on_pushButton_8_clicked() {
  ui->plainTextEdit->clear();
  bitset->reset(ui->spinBox_2->value());
}

void MainWindow::on_pushButton_9_clicked() {
  ui->plainTextEdit->clear();
  bitset->set();
}

void MainWindow::on_pushButton_10_clicked() {
  ui->plainTextEdit->clear();
  bitset->set(ui->spinBox_2->value());
}

void MainWindow::on_pushButton_13_clicked() {
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText(QString::number(bitset->size()));
}

void MainWindow::on_pushButton_12_clicked() {
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText(
      QString::number(bitset->test(ui->spinBox_2->value())));
}

void MainWindow::on_pushButton_11_clicked() {
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText(bitset->to_string());
}

void MainWindow::on_pushButton_14_clicked() {
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText(QString::number(bitset->to_ullong()));
}

void MainWindow::on_pushButton_15_clicked() {
  ui->plainTextEdit->clear();
  ui->plainTextEdit->appendPlainText(QString::number(bitset->to_ulong()));
}
