#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), date_class(new Date()) {
  ui->setupUi(this);
  ui->Today->setText(date_class->Today());
  ui->Vchera->setText(date_class->PreviousDay());
  ui->NextDay->setText(date_class->NextDay());
  ui->visokosni->setText(date_class->IsLeap() ? "ыгы" : "нет");
  ui->week->setText(
      QString::fromStdString(std::to_string(date_class->WeekNumber())));
  ui->Birthday->setText(date_class->DaysTillYourBithday("27.09.2024"));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  try {
    QString date1, date2;

    if(ui->lineEdit->displayText().isEmpty() or ui->lineEdit_2->displayText().isEmpty()) {
      throw "NO";
    }

    date1 = ui->lineEdit->text();
    date2 = ui->lineEdit_2->text();

    QString date1_day;
    date1_day.append(date1[0]);
    date1_day.append(date1[n1]);

    date1.remove(0, n3);

    QString date1_month;
    date1_month.append(date1[0]);
    date1_month.append(date1[n1]);

    date1.remove(0, n3);

    QString date1_year;
    date1_year = date1;

    QString date2_day;
    date2_day.append(date2[0]);
    date2_day.append(date2[n1]);

    date2.remove(0, n3);

    QString date2_month;
    date2_month.append(date2[0]);

    date2_month.append(date2[n1]);

    date2.remove(0, n3);

    QString date2_year;
    date2_year = date2;

    date1 = date1_day + '.' + date1_month + '.' + date1_year;
    date2 = date2_day + '.' + date2_month + '.' + date2_year;

    int day1 = date1_day.toInt(), day2 = date2_day.toInt(),
        month1 = date1_month.toInt(), month2 = date2_month.toInt(),
        year1 = date1_year.toInt(), year2 = date2_year.toInt();

    if (day1 > 0 or day2 > 0 or month1 > 0 or month2 > 0 or year1 > 0 or
        year2 > 0) {
      if ((day1 < n28 or
           day1 <= n31 and
               (month1 == n1 or month1 == n3 or month1 == n5 or month1 == n7 or
                month1 == n8 or month1 == n10 or month1 == n12)) or
          (day1 <= n30 and month1 != n2) or
          (day1 <= n29 and month1 == n2 and year1 % 4 == 0) or
          (day1 <= n28 and month1 == n2)) {
        if ((day2 < n28 or
             day2 <= n31 and (month2 == n1 or month2 == n3 or month2 == n5 or
                              month2 == n7 or month2 == n8 or month2 == n10 or
                              month2 == n12)) or
            (day2 <= n30 and month2 != n2) or
            (day2 <= n29 and month2 == n2 and year2 % 4 == 0) or
            (day2 <= n28 and month2 == n2)) {
          ui->Duration->setText(date_class->Duration(date1, date2));
        } else {
          throw "N0";
        }

      } else {
        throw "N0";
      }
    } else {
      throw "N0";
    }

  } catch (const char *error_message) {
    ui->Duration->setText(error_message);
  }
}

void MainWindow::on_pushButton_2_clicked() {
  QFileDialog dialog(this);

  way_to_file = dialog.getOpenFileName(this, "сюда не надо смотреть",
                                       "/home/evgen/text", "*.txt");

  ui->label->setText(way_to_file);

  QFile file(way_to_file);

  if (file.exists() and file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    file_open = true;

    file.seek(0);

    while (!file.atEnd()) {
      mass_str.push_back(file.readLine());
      size++;
    }

    for (int i = 0; size > i; i++) {
      mass_str[i].remove(mass_str[i].size() - 1, 1);
    }

    ui->tableWidget->setRowCount(size);

    ui->tableWidget->setColumnCount(2);

    for (int i = 0; size > i; i++) {
      QTableWidgetItem *str = new QTableWidgetItem(mass_str[i]);
      ui->tableWidget->setItem(i, 0, str);
    }

    for (int i = 0; size > i; i++) {
      ui->tableWidget->resizeColumnsToContents();
      ui->tableWidget->resizeRowsToContents();

      QTableWidgetItem *str = new QTableWidgetItem(
          date_class->Duration(date_class->GetToday(), mass_str[i]));
      ui->tableWidget->setItem(i, 1, str);
    }
  }
}

void MainWindow::on_pushButton_3_clicked() { exit(0); }

void MainWindow::on_pushButton_4_clicked() {
  try {
    if (!file_open and ui->lineEdit_3->displayText().isEmpty()) {
      throw "NO";
    }

    QString date1 = ui->lineEdit_3->text();

    QString date1_day;
    date1_day.append(date1[0]);
    date1_day.append(date1[n1]);

    date1.remove(0, n3);

    QString date1_month;
    date1_month.append(date1[0]);
    date1_month.append(date1[n1]);

    date1.remove(0, n3);

    QString date1_year;
    date1_year = date1;

    date1 = date1_day + '.' + date1_month + '.' + date1_year;

    int day1 = date1_day.toInt(), month1 = date1_month.toInt(),
        year1 = date1_year.toInt();
    if (day1 > 0 or month1 > 0 or year1 > 0) {
      if ((day1 < n28 or
           day1 <= n31 and
               (month1 == n1 or month1 == n3 or month1 == n5 or month1 == n7 or
                month1 == n8 or month1 == n10 or month1 == n12)) or
          (day1 <= n30 and month1 != n2) or
          (day1 <= n29 and month1 == n2 and year1 % 4 == 0) or
          (day1 <= n28 and month1 == n2)) {
        size++;
        mass_str.push_back(date1);
        ui->tableWidget->setRowCount(size);
        QTableWidgetItem *item = new QTableWidgetItem(date1);
        ui->tableWidget->setItem(size - 1, 0, item);
        QTableWidgetItem *str = new QTableWidgetItem(
            date_class->Duration(date_class->GetToday(), date1));
        ui->tableWidget->setItem(size - 1, 1, str);

        QFile file(way_to_file);

        file.seek(file.size());

        if (file.exists() and file.open(QIODevice::Append | QIODevice::Text)) {
          QTextStream stream(&file);
          stream << date1 + "\n";
        }

      } else {
        throw "N0";
      }

    } else {
      throw "N0";
    }
  }

  catch (const char *error_message) {
    ui->lineEdit_3->setText(error_message);
  }
}

void MainWindow::on_pushButton_5_clicked() {
  try {
    if (!file_open or ui->lineEdit_4->displayText().isEmpty()) {
      throw "NO";
    }

    QString str = ui->lineEdit_4->text();

    if(str.toInt() < 1 or str.toInt() > size){
      throw "NO";
    }

    mass_str.remove(str.toInt() - 1, 1);
    size--;

    ui->tableWidget->setRowCount(size);

    ui->tableWidget->setColumnCount(2);

    for (int i = 0; size > i; i++) {
      QTableWidgetItem *str = new QTableWidgetItem(mass_str[i]);
      ui->tableWidget->setItem(i, 0, str);
    }

    for (int i = 0; size > i; i++) {
      ui->tableWidget->resizeColumnsToContents();
      ui->tableWidget->resizeRowsToContents();

      QTableWidgetItem *str = new QTableWidgetItem(
          date_class->Duration(date_class->GetToday(), mass_str[i]));
      ui->tableWidget->setItem(i, 1, str);
    }

    QFile file(way_to_file);

    file.seek(file.size());

    file.resize(0);

    if (file.exists() and file.open(QIODevice::ReadWrite | QIODevice::Text)) {
      for (int i = 0; size > i; i++) {
        QTextStream stream(&file);
        stream <<mass_str[i]+"\n";
      }
    }

  } catch (const char *error_message) {
    ui->lineEdit_4->setText(error_message);
  }
}
