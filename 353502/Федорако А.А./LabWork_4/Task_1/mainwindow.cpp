#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->spinBox->setMaximum(SPIN_BOX_MAXIMUM_VALUE);
}

void MainWindow::setRandomElements(long* arr, long size) {
  for (long i = 0; i < size; i++) {
    arr[i] = QRandomGenerator::global()->bounded(0, MOD);
  }
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  srand(time(nullptr));

  ui->pushButton->setEnabled(false);

  long size = ui->spinBox->value();
  long* arr = new long[size];
  setRandomElements(arr, size);
  {
    LogDuration ld("Cортировка кучей");
    Sort::heapSort(arr, size);
    ui->label_3->setText(ld.result());
  }
  {
    LogDuration ld("Быстрая сортировка");
    Sort::quickSort(arr, size);
    ui->label_4->setText(ld.result());
  }
  {
    LogDuration ld("Сортировка слиянием");
    Sort::mergeSort(arr, 0, size);
    ui->label_5->setText(ld.result());
  }
  ui->pushButton->setEnabled(true);

  delete[] arr;
  arr = nullptr;
}
