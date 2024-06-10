#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->graphicsView->setScene(&scene);

  table16 = new HashTable<QString>(FIRST_TABLE_SIZE);
  table64 = new HashTable<QString>(SECOND_TABLE_SIZE);
  table128 = new HashTable<QString>(THIRD_TABLE_SIZE);
  table2048 = new HashTable<QString>(FOURTH_TABLE_SIZE);

  connect(ui->pushButton, &QPushButton::clicked, this,
          &MainWindow::updateSchedule);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::fillPartTable(HashTable<QString>* table, int size) {
  size *= SIZE_FACTOR;
  while (size--) {
    int symbolsSize = QRandomGenerator::global()->bounded(MIN_RANDOM_LINE_SIZE,
                                                          MAX_RANDOM_LINE_SIZE);
    QString line = "";
    while (symbolsSize--) {
      line += SYMBOLS[QRandomGenerator::global()->bounded(0, SIZE_ALPHABET)];
    }
    table->add(QRandomGenerator::global()->bounded(0, MAX_RANDOM_NUMBER_VALUE),
               line);
  }
}

int MainWindow::getTime(HashTable<QString>* table) {
  QElapsedTimer timer;
  timer.start();

  int number = SIZE_CHECK_TABLE_ELEMENT;
  while (number--) {
    table->find(
        QRandomGenerator::global()->bounded(0, MAX_RANDOM_NUMBER_VALUE));
  }

  return timer.elapsed();
}

void MainWindow::showSchedule(int* time) {
  scene.clear();
  QGraphicsRectItem* arrItem[4] = {
      new QGraphicsRectItem(QRectF(0, 0, 150, -time[0] * 1.5)),
      new QGraphicsRectItem(QRectF(160, 0, 150, -time[1] * 1.5)),
      new QGraphicsRectItem(QRectF(320, 0, 150, -time[2] * 1.5)),
      new QGraphicsRectItem(QRectF(480, 0, 150, -time[3] * 1.5))};

  for (int i = 0; i < 4; i++) {
    arrItem[i]->setBrush(Qt::red);
    scene.addItem(arrItem[i]);
  }
  scene.update();
}

void MainWindow::updateSchedule() {
  fillPartTable(table16, FIRST_TABLE_SIZE);
  fillPartTable(table64, SECOND_TABLE_SIZE);
  fillPartTable(table128, THIRD_TABLE_SIZE);
  fillPartTable(table2048, FOURTH_TABLE_SIZE);

  int time[4] = {getTime(table16), getTime(table64), getTime(table128),
                 getTime(table2048)};
  qDebug() << time[0] << time[1] << time[2] << time[3];

  showSchedule(time);
}
