#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::heapify(int arr[], int n, int i) {
  int largest = i;

  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
  {
    largest = left;
  }

  if (right < n && arr[right] > arr[largest])
  {
    largest = right;
  }

  if (largest != i) {
    std::swap(arr[i], arr[largest]);

    heapify(arr, n, largest);
  }
}

void MainWindow::heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    std::swap(arr[0], arr[i]);

    heapify(arr, i, 0);
  }
}

void MainWindow::printArray(int arr[], int n) {
  QString result;
  for (int i = 0; i < n; ++i) {
    result += QString::number(arr[i]) + " ";
  }

  ui->printArray->setText(result);
}

void MainWindow::qsortRecursive(int* mas, int size) {
  int i = 0;
  int j = size - 1;

  int mid = mas[size / 2];

  do {
    while (mas[i] < mid) {
      i++;
    }

    while (mas[j] > mid) {
      j--;
    }

    if (i <= j) {
      int tmp = mas[i];
      mas[i] = mas[j];
      mas[j] = tmp;

      i++;
      j--;
    }
  } while (i <= j);

  if (j > 0) {
    qsortRecursive(mas, j + 1);
  }
  if (i < size) {
    qsortRecursive(&mas[i], size - i);
  }
}

void MainWindow::merge(int array[], const int left, const int mid,
                       const int right) {
  int const subArrayOne = mid - left + 1;
  int const subArrayTwo = right - mid;

  auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

  for (auto i = 0; i < subArrayOne; i++) leftArray[i] = array[left + i];
  for (auto j = 0; j < subArrayTwo; j++) rightArray[j] = array[mid + 1 + j];

  auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
  int indexOfMergedArray = left;

  while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
    if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
      array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
      indexOfSubArrayOne++;
    } else {
      array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
      indexOfSubArrayTwo++;
    }
    indexOfMergedArray++;
  }

  while (indexOfSubArrayOne < subArrayOne) {
    array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
    indexOfSubArrayOne++;
    indexOfMergedArray++;
  }

  while (indexOfSubArrayTwo < subArrayTwo) {
    array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
    indexOfSubArrayTwo++;
    indexOfMergedArray++;
  }
  delete[] leftArray;
  delete[] rightArray;
}

void MainWindow::mergeSort(int array[], const int begin, const int end) {
  if (begin >= end) return;

  int mid = begin + (end - begin) / 2;
  mergeSort(array, begin, mid);
  mergeSort(array, mid + 1, end);
  merge(array, begin, mid, end);
}

void MainWindow::binsearch() {
  QString text = ui->textEdit->toPlainText();
  QStringList stringList = text.split(" ");
  int size = stringList.size();

  int* arr = new int[size];

  for (int i = 0; i < size; ++i) {
    arr[i] = stringList[i].toInt();
  }

  qsortRecursive(arr, size);

  int key = ui->textbin->toPlainText().toInt();
  bool flag = false;
  int l = 0;
  int r = 9;
  int mid;

  while ((l <= r) && (flag != true)) {
    mid = (l + r) / 2;

    if (arr[mid] == key) flag = true;
    if (arr[mid] > key)
      r = mid - 1;
    else
      l = mid + 1;
  }

  if (flag)
    ui->linebin->setText("Индекс элемента " + QString::number(key) +
                         " в массиве равен: " + QString::number(mid));

  else
    ui->linebin->setText("-1");
}

void MainWindow::on_pushButton_clicked() {
  QString text = ui->textEdit->toPlainText();
  QStringList stringList = text.split(" ");
  int size = stringList.size();

  int* arr = new int[size];

  for (int i = 0; i < size; ++i) {
    arr[i] = stringList[i].toInt();
  }

  int* arr2 = new int[size];
  for (int i = 0; i < size; i++) {
    arr2[i] = arr[i];
  }

  int* arr3 = new int[size];
  for (int i = 0; i < size; i++) {
    arr3[i] = arr[i];
  }

  redirection1(arr, size);
  redirection2(arr2, size);
  redirection3(arr2, size);

  delete[] arr;
}

void MainWindow::redirection1(int arr[], int size) {
  QElapsedTimer heap;
  heap.start();
  heapSort(arr, size);
  QString heapTimeString = QString::number(heap.nsecsElapsed()) + " ns";
  printArray(arr, size);

  ui->heapSort->setText(heapTimeString);
}

void MainWindow::redirection2(int arr[], int size) {
  QString result;
  for (int i = 0; i < size; ++i) {
    result += QString::number(arr[i]) + " ";
  }

  ui->lineEdit->setText(result);

  QElapsedTimer quick;
  quick.start();
  qsortRecursive(arr, size);
  QString quickTimeString = QString::number(quick.nsecsElapsed()) + " ns";

  ui->quickSort->setText(quickTimeString);
}

void MainWindow::redirection3(int arr[], int size) {
  QElapsedTimer merge;
  merge.start();
  mergeSort(arr, 0, size - 1);
  QString mergeTimeString = QString::number(merge.nsecsElapsed()) + " ns";
  ui->mergeSort->setText(mergeTimeString);
}

void MainWindow::on_buttonbin_clicked() { binsearch(); }
