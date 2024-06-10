#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->dateTimeEditYear->setMinimumDate(QDate::currentDate().addDays(
      -NUMBER_DAY_IN_YEAR *
      (NOW_YEAR - Laptop::YEAR_CREATION_FIRST_LAPTOP + 1)));
  ui->dateTimeEditYear->setMaximumDate(QDate::currentDate().addDays(0));
  ui->dateTimeEditYear->setDisplayFormat("yyyy");
  ui->spinBoxActive->setRange(0, 1);
  ui->doubleSpinBoxPrice->setRange(0, SPIN_BOX_MAX_VALUE);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  ui->label->clear();
  bool isCorrect = true;
  Laptop laptop;
  laptop.setPrice(ui->doubleSpinBoxPrice->value());
  laptop.setStatusWork(ui->spinBoxActive->value());
  if (getEditGrade() != '\0') {
    laptop.setGrade(getEditGrade());
  } else {
    isCorrect = false;
    showWarning("Некорректное значение оценки");
  }
  laptop.setYear(ui->dateTimeEditYear->date().year());
  if (isCorrect) {
    ui->label->setText(QString::number(laptop.getPrice()) + SEPARATION_SIGN +
                       (laptop.getGrade()) + SEPARATION_SIGN +
                       QString::number(laptop.getYearConstruction()) +
                       SEPARATION_SIGN +
                       QString::number(laptop.getStatusWork()));
  }
}

char MainWindow::getEditGrade() {
  QString line = (ui->lineEditGrade->text());
  if (line.size() == 1 && line[0].toLatin1() >= 'A' &&
      line[0].toLatin1() <= 'F') {
    return line[0].toLatin1();
  }
  return '\0';
}

void MainWindow::on_pushButton_2_clicked() {
  ui->label->clear();
  bool isCorrect = true;
  Laptop laptop;
  laptop.setPrice(ui->doubleSpinBoxPrice->value());
  laptop.setStatusWork(ui->spinBoxActive->value());
  if (getEditGrade() != '\0') {
    laptop.setGrade(getEditGrade());
  } else {
    isCorrect = false;
    showWarning("Некорректное значение оценки");
  }
  laptop.setYear(ui->dateTimeEditYear->date().year());
  if (isCorrect) {
    ui->label->setText(QString::number(laptop.getPrice()) + SEPARATION_SIGN +
                       (laptop.getGrade()) + SEPARATION_SIGN +
                       QString::number(laptop.getYearConstruction()) +
                       SEPARATION_SIGN +
                       QString::number(laptop.getStatusWork()));
  }
}

void MainWindow::on_pushButton_3_clicked() {
  Laptop* laptop = new Laptop();
  ui->label->clear();
  bool isCorrect = true;
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
    ui->label->setText(QString::number(laptop->getPrice()) + SEPARATION_SIGN +
                       (laptop->getGrade()) + SEPARATION_SIGN +
                       QString::number(laptop->getYearConstruction()) +
                       SEPARATION_SIGN +
                       QString::number(laptop->getStatusWork()));
  }
}

void MainWindow::showWarning(const QString& message) {
  QMessageBox::warning(this, "Ошибка", message);
}

void MainWindow::on_pushButton_4_clicked() {
  Laptop laptop;
  ui->label->clear();
  bool isCorrect = true;
  (&laptop)->setPrice(ui->doubleSpinBoxPrice->value());
  (&laptop)->setStatusWork(ui->spinBoxActive->value());
  if (getEditGrade() != '\0') {
    (&laptop)->setGrade(getEditGrade());
  } else {
    isCorrect = false;
    showWarning("Некорректное значение оценки");
  }
  (&laptop)->setYear(ui->dateTimeEditYear->date().year());
  if (isCorrect) {
    ui->label->setText(
        QString::number((&laptop)->getPrice()) + SEPARATION_SIGN +
        ((&laptop)->getGrade()) + SEPARATION_SIGN +
        QString::number(laptop.getYearConstruction()) + SEPARATION_SIGN +
        QString::number((&laptop)->getStatusWork()));
  }
}
