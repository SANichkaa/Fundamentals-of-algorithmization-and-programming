#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  QString data = ui->textEdit->toPlainText();
  QStringList strList = data.split(QRegExp("[\\n]"), QString::SkipEmptyParts);
  textParagraph.addText(data);
}

void MainWindow::on_pushButton_2_clicked() {
  ui->plainTextEdit->setPlainText(textParagraph.getText());
}

void MainWindow::on_pushButton_3_clicked() {
  QString data = ui->textEdit->toPlainText();
  QStringList strList = data.split(QRegExp("[\\n]"), QString::SkipEmptyParts);
  textArray.addText(data);
}

void MainWindow::on_pushButton_4_clicked() {
  ui->plainTextEdit->setPlainText(textArray.getText());
}

void MainWindow::on_pushButton_5_clicked() {
  bool isCorrect = true;
  Laptop* laptop = new Laptop();
  laptop->setPrice(ui->doubleSpinBoxPrice->value());
  laptop->setStatusWork(ui->spinBoxActive->value());
  if (getEditGrade() != '\0') {
    laptop->setGrade(getEditGrade());
  } else {
    isCorrect = false;
    showWarning("Некорректное значение оценки");
  }
  laptop->setYear(ui->dateTimeEditYear->date().year());
  if (isCorrect) {
    textStruct.addText(laptop->toString());
  }
}

void MainWindow::on_pushButton_6_clicked() {
  ui->plainTextEdit->setPlainText(textStruct.getText());
}

char MainWindow::getEditGrade() {
  QString line = (ui->lineEditGrade->text());
  if (line.size() == 1 && line[0].toLatin1() >= 'A' &&
      line[0].toLatin1() <= 'F') {
    return line[0].toLatin1();
  }
  return '\0';
}

void MainWindow::showWarning(const QString& message) {
  QMessageBox::warning(this, "Ошибка", message);
}

void MainWindow::on_pushButton_7_clicked() {
  bool isCorrect = true;
  Laptop* laptop = new Laptop();
  laptop->setPrice(ui->doubleSpinBoxPrice->value());
  laptop->setStatusWork(ui->spinBoxActive->value());
  if (getEditGrade() != '\0') {
    laptop->setGrade(getEditGrade());
  } else {
    isCorrect = false;
    showWarning("Некорректное значение оценки");
  }
  laptop->setYear(ui->dateTimeEditYear->date().year());
  if (isCorrect) {
    binStruct.addData(*laptop);
  }
}

void MainWindow::on_pushButton_8_clicked() {
  binStruct.getText();
}
