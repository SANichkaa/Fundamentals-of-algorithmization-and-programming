#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  heapArray = new BinaryHeapArray(HEAP_ARRAY_SIZE);
  heapList = new BinaryHeapList();
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  int key = ui->spinBox->value();
  QString value = ui->lineEdit->text();
  heapArray->add(key);
  heapList->add(key);
  showBinaryHeap();
}

void MainWindow::showBinaryHeap() {
  QVector<int> arrHeapArray = heapArray->getKeys();
  QVector<int> arrHeapList = heapList->getKeys();

  ui->plainTextEdit->setPlainText(getText(arrHeapArray));
  ui->plainTextEdit_2->setPlainText(getText(arrHeapList));

  ui->label_5->clear();
  ui->label_6->clear();
}

QString MainWindow::getText(QVector<int> arr) {
  QString result = "";
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] != -1) {
      result += QString::number(arr[i]) + " ";
    } else {
      result += "- ";
    }
  }
  return result;
}

void MainWindow::on_pushButton_3_clicked() {
  ui->label_5->setText("Массив: " + QString::number(heapArray->max()));
  ui->label_6->setText("Список: " + QString::number(heapArray->max()));
}

void MainWindow::on_pushButton_4_clicked() {
  heapArray->removeMax();
  heapList->removeMax();
  showBinaryHeap();
}

void MainWindow::on_pushButton_5_clicked() {
  ui->label_5->setText("Массив: " + QString::number(heapArray->size()));
  ui->label_6->setText("Список: " + QString::number(heapArray->size()));
}

void MainWindow::on_pushButton_6_clicked() {
  int key = QRandomGenerator::global()->bounded(0, MAX_RANDOM_NUMBER);
  QString value = ui->lineEdit->text();
  heapArray->add(key);
  heapList->add(key);
  showBinaryHeap();
}

void MainWindow::on_pushButton_2_clicked() {}
