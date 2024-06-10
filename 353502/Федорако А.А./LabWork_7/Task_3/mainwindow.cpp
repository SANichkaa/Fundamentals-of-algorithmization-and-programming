#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  table = new CustomHashTable<QString>(NUMBER_HASH_TABLE_SIZE);
  ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
  ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
  ui->tableWidget_3->horizontalHeader()->setStretchLastSection(true);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::setRandTable() {
  int size = QRandomGenerator::global()->bounded(MINIMUM_NUMBER_RANDOM_ELEMENT,
                                                 MAXIMUM_NUMBER_RANDOM_ELEMENT);
  while (size--) {
    int symbolsSize = QRandomGenerator::global()->bounded(LINE_MINIMUM_SIZE,
                                                          LINE_MAXIMUM_SIZE);
    QString line = "";
    while (symbolsSize--) {
      line += SYMBOLS[QRandomGenerator::global()->bounded(0, SIZE_ALPHABET)];
    }
    table->add(QRandomGenerator::global()->bounded(MINIMUM_RANDOM_KEY,
                                                   MAXIMUM_RANDOM_KEY),
               line);
  }
}

void MainWindow::on_pushButton_clicked() {
  setRandTable();
  showFirstTable();
  showSecondTable();
  showThirdTable();
}

void MainWindow::showFirstTable() {
  ui->tableWidget->setRowCount(0);
  for (int i = 0; i < table->size(); i++) {
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    QTableWidgetItem* secondItem = new QTableWidgetItem;
    QVector<QString> value = table->toVector()[i].toVector();
    QString result;
    for (QString line : value) {
      result += line + " ";
    }
    secondItem->setText(result);
    ui->tableWidget->setItem(i, 0, secondItem);
  }
}

void MainWindow::showSecondTable() {
  ui->tableWidget_2->setRowCount(0);
  for (int i = 0; i < table->size() / 2; i++) {
    ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
    QTableWidgetItem* secondItem = new QTableWidgetItem;
    QVector<QString> value = table->toVector()[i].toVector();
    QString result;
    for (QString line : value) {
      result += line + " ";
    }
    secondItem->setText(result);
    ui->tableWidget_2->setItem(i, 0, secondItem);
  }
}

void MainWindow::showThirdTable() {
  ui->tableWidget_3->setRowCount(0);
  for (int i = table->size() / 2, t = 0; i < table->size(); i++, t++) {
    ui->tableWidget_3->insertRow(ui->tableWidget_3->rowCount());
    QTableWidgetItem* secondItem = new QTableWidgetItem;
    QVector<QString> value = table->toVector()[i].toVector();
    QString result;
    for (QString line : value) {
      result += line + " ";
    }
    secondItem->setText(result);
    ui->tableWidget_3->setItem(t, 0, secondItem);
  }
}
