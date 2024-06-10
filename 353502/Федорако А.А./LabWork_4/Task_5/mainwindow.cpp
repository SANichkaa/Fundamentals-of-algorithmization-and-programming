#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFirstMatrix();
  setSecondMatrix();
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::setFirstMatrix() {
  ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
  pair.first.assign(SIZE_MATRIX, SIZE_MATRIX);
  pair.first.push_back(FIRST_NUMBER);
  ui->tableWidget->setRowCount(pair.first.size());
  ui->tableWidget->setColumnCount(1);
  ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Столбец 1");
  for (int i = 0; i < pair.first.size(); ++i) {
    QTableWidgetItem* item =
        new QTableWidgetItem(QString::number(pair.first[i]));
    ui->tableWidget->setItem(i, 0, item);
  }
}

void MainWindow::setSecondMatrix() {
  ui->tableWidget_2->setColumnCount(2);
  ui->tableWidget_2->setColumnWidth(0, SECOND_TABLE_COLUMB_WIDTH);
  ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
  pair.second.assign(SIZE_MATRIX,
                     Pair<int, double>::make_pair(SECOND_NUMBER, THIRD_NUMBER));
  ui->tableWidget_2->setRowCount(pair.second.size());
  ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << "Столбец 1"
                                                             << "Cтолбец 2");
  for (int i = 0; i < pair.second.size(); ++i) {
    QTableWidgetItem* firstItem =
        new QTableWidgetItem(QString::number(pair.second[i].first));
    QTableWidgetItem* secondItem =
        new QTableWidgetItem(QString::number(pair.second[i].second));
    ui->tableWidget_2->setItem(i, 0, firstItem);
    ui->tableWidget_2->setItem(i, 1, secondItem);
  }
}
