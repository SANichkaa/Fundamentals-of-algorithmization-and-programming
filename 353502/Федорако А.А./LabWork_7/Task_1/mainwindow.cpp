#include "mainwindow.h"
#include <QDebug>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), buttonState(true), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
  ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
  ui->tableWidget_3->horizontalHeader()->setStretchLastSection(true);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButtonPop_clicked() {
  if (!firstQueue->isEmpty()) {
    firstQueue->pop();
    setTableWidget(ui->tableWidget, firstQueue);
  }
}

void MainWindow::on_pushButtonPush_clicked() {
  firstQueue->push(QRandomGenerator::global()->bounded(0, MAX_RANDOM_VALUE_QUEUE));
  setTableWidget(ui->tableWidget, firstQueue);
}

void MainWindow::on_pushButton_clicked() {
  if (buttonState) {
    setQueueRandomElements(secondQueue);
    setQueueRandomElements(thirdQueue);
  } else {
    QVector<int> firstArray = secondQueue->toVector();
    QVector<int> secondArray = thirdQueue->toVector();
    int indexMinElement = getIndexMinElement(firstArray);
    int indexMaxElement = getIndexMaxElement(firstArray);
    int indexMin = qMin(indexMinElement, indexMaxElement);
    int indexMax = qMax(indexMinElement, indexMaxElement);
    while (indexMax - 1 != indexMin) {
      secondQueue->deleteAtPosition(indexMin + 1);
      indexMax--;
    }
    for (int i = indexMin + 1, t = 0; thirdQueue->size(); i++, t++) {
      secondQueue->insertAtPosition(i, thirdQueue->pop());
    }
  }

  setTableWidget(ui->tableWidget_2, secondQueue);
  setTableWidget(ui->tableWidget_3, thirdQueue);

  buttonState = buttonState ? false : true;
  ui->pushButton->setText(buttonState ? FIRST_BUTTON_STATE
                                      : SECOND_BUTTON_STATE);
}

void MainWindow::setQueueRandomElements(Queue<int>* queue) {
  queue->clear();
  int size = QRandomGenerator::global()->bounded(MIN_RANDOM_VALUE_SIZE_QUEUE, MAX_RANDOM_VALUE_SIZE_QUEUE);
  while (size--) {
    queue->push(QRandomGenerator::global()->bounded(0, MAX_RANDOM_VALUE_QUEUE));
  }
}

void MainWindow::setTableWidget(QTableWidget* widget,
                                Queue<int>* queue) {
  QVector<int> result = queue->toVector();
  widget->setRowCount(0);
  for (int i = 0; i < result.size(); i++) {
    widget->insertRow(widget->rowCount());
    QTableWidgetItem* firstItem = new QTableWidgetItem;
    firstItem->setText(QString::number(result[i]));
    widget->setItem(i, 0, firstItem);
  }
}

int MainWindow::getIndexMinElement(QVector<int> arr) {
  if (arr.size()) {
    int number = 0;
    int value = arr[0];
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] < value) {
        number = i;
        value = arr[i];
      }
    }
    return number;
  }
  return -1;
}

int MainWindow::getIndexMaxElement(QVector<int> arr) {
  if (arr.size()) {
    int number = 0;
    int value = arr[0];
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] > value) {
        number = i;
        value = arr[i];
      }
    }
    return number;
  }
  return -1;
}
