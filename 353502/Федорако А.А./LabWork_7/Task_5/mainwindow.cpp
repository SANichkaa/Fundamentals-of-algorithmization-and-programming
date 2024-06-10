#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::showDeque() {
  ui->tableWidget->setRowCount(0);
  for (int temp : deque) {
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(QString::number(temp));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, item);
  }
}

void MainWindow::on_pushButton_clicked() {
  deque.push_back(ui->spinBox->value());
  ui->label->setText("Элемент успешно добавлен");
  showDeque();
}

void MainWindow::on_pushButton_2_clicked() {
  deque.push_front(ui->spinBox->value());
  ui->label->setText("Элемент успешно добавлен");
  showDeque();
}

void MainWindow::on_pushButton_3_clicked() {
  deque.pop_back();
  ui->label->setText("Элемент успешно удален");
  showDeque();
}

void MainWindow::on_pushButton_4_clicked() {
  deque.pop_front();
  ui->label->setText("Элемент успешно удален");
  showDeque();
}

void MainWindow::on_pushButton_5_clicked() {
  deque.clear();
  ui->label->setText("Структура успешно очищена");
  showDeque();
}

void MainWindow::on_pushButton_6_clicked() {
  ui->label->setText("Pазмер структуры равен " + QString::number(deque.size()));
}

void MainWindow::on_pushButton_7_clicked() {
  if (deque.isEmpty()) {
    ui->label->setText("Данная структура пуста");
  } else {
    ui->label->setText("Данная структура не пуста");
  }
}

void MainWindow::on_pushButton_8_clicked() {
  deque.push_back(QRandomGenerator::global()->bounded(0, MAX_RAND_VALUE));
  showDeque();
}

void MainWindow::on_pushButton_9_clicked() {
  deque.push_front(QRandomGenerator::global()->bounded(0, MAX_RAND_VALUE));
  showDeque();
}
