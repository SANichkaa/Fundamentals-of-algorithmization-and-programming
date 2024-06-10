#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->spinBox->setMaximum(SPIN_BOX_MAXIMUM_VALUE);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::setRandomElements(QVector<int>& arr, long size) {
  for (long i = 0; i < size; i++) {
    arr[i] = QRandomGenerator::global()->bounded(0, MOD);
  }
}

QString MainWindow::outputLineArray(QVector<int> arr, long size) {
  QString result = "";
  for (int i = 0; i < size; i++) {
    result += QString::number(arr[i]) + " ";
  }
  return result;
}

void MainWindow::on_pushButton_clicked() {
  int size = ui->spinBox->value();
  QVector<int> arr(size);

  setRandomElements(arr, size);

  ui->plainTextEdit->appendPlainText(outputLineArray(arr, size));

  Sort::MedianSort(arr);

  ui->plainTextEdit_2->appendPlainText(outputLineArray(arr, size));
}
