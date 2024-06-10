#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
  srand(time(NULL));
  scene = new QGraphicsScene(this);
  ui->graphicsView->setScene(scene);
  array = getRandArr(SIZE_RANDOM_ARRAY);
  showArray(array);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::interpolationSort(QVector<int>& arr) {
  int start = 0;
  int size = arr.size();
  int min = arr.at(0);
  int max = arr.at(0);

  for (int i = 1; i < size; i++) {
    if (arr[i] < min) {
      min = arr[i];
    } else if (arr[i] > max) {
      max = arr[i];
    }
  }
  if (min != max) {
    QVector<QVector<int>> array(size);
    int interpolation = 0;

    for (int i = 0; i < size; i++) {
      interpolation =
          qAbs((int)((double)arr.at(i) - min) / (max - min) * (size - 1));
      array[interpolation].push_back(arr.at(i));
    }

    for (int i = 0; i < size; i++) {
      if (array[i].size() > 1) {
        interpolationSort(array[i]);
      }
      for (int t = 0; t < array[i].size(); t++) {
        arr[start++] = array[i][t];
        changeElementArrayShow(this->array);
      }
    }
  }
}

void MainWindow::changeElementArrayShow(QVector<int> arr) {
  if (temp != array) {
    QCoreApplication::processEvents();
    showArray(arr);
    scene->update();
    QThread::usleep(SLEEP_TIME);
    temp = array;
  }
}

QVector<int> MainWindow::getRandArr(int size) {
  QVector<int> result;
  for (int i = 0; i < size; i++) {
    result.push_back(std::rand() % MAX_NUMBER + 1);
  }
  return result;
}

void MainWindow::showArray(QVector<int> arr) {
  QCoreApplication::processEvents();
  scene->clear();
  for (int i = 0; i < arr.size(); i++) {
    QGraphicsRectItem* rectItem =
        new QGraphicsRectItem(i * 20, -100, 20, -arr[i]);
    rectItem->setBrush(QBrush(Qt::red));
    rectItem->setPos(12, 12);
    scene->addItem(rectItem);
  }
}

void MainWindow::on_pushButton_2_clicked() {
  interpolationSort(array);
}

void MainWindow::on_pushButton_clicked() {
  array = getRandArr(SIZE_RANDOM_ARRAY);
  showArray(array);
}
