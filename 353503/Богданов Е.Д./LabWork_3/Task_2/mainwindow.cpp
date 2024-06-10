#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

qlonglong MainWindow::Akerman(int m, int n) {
  if (cheker != INT16_MAX) {
    cheker++;
  }
  if (cheker == INT16_MAX) {
    return 0;
  } else if (m == 0) {
    return n + 1;
  } else if (n == 0) {
    return Akerman(m - 1, 1);
  } else {
    return Akerman(m - 1, Akerman(m, n - 1));
  }
}

void MainWindow::on_lineEdit_returnPressed() {
  if (ui->lineEdit_2->text().toInt() >= 0 and
      ui->lineEdit->text().toInt() >= 0 and
      !ui->lineEdit->displayText().isEmpty() and
      !ui->lineEdit_2->displayText().isEmpty()) {
    result =
        Akerman(ui->lineEdit->text().toInt(), ui->lineEdit_2->text().toInt());
    if (cheker != INT16_MAX) {
      ui->label->setText(QString::number(result));
      ui->label->adjustSize();
    }
    else{
      ui->label->setText("много");
    }
  }
}

void MainWindow::on_lineEdit_2_returnPressed() {
  if (ui->lineEdit_2->text().toInt() >= 0 and
      ui->lineEdit->text().toInt() >= 0 and
      !ui->lineEdit->displayText().isEmpty() and
      !ui->lineEdit_2->displayText().isEmpty()) {
    result =
        Akerman(ui->lineEdit->text().toInt(), ui->lineEdit_2->text().toInt());

    if (cheker != INT16_MAX) {
      ui->label->setText(QString::number(result));
      ui->label->adjustSize();
    }
    else{
      ui->label->setText("много");
    }
  }
}
