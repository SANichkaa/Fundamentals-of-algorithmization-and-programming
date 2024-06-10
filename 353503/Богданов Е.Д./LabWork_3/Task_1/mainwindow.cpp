#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::recursia(qlonglong var) {
  if (var == 1) {
    int_bin += "1";
  } else if (var == 0) {
    int_bin += "0";
  } else {
    recursia(var / 2);
    int_bin += QString::number(var % 2);
  }
}

void MainWindow::recursia(double var) {
  const int max_cheker = 20;

  var *= 2;

  if (cheker == max_cheker) {  // if(cheker == max_cheker) doing nothing
  } else if (var > 1) {
    var -= 1;
    double_bin += "1";
    cheker++;
    recursia(var);
  } else if (var < 1) {
    double_bin += "0";
    cheker++;
    recursia(var);
  } else {
    double_bin += "1";
    cheker = max_cheker;
  }
}

void MainWindow::on_lineEdit_returnPressed() {
  if (!ui->lineEdit->displayText().isEmpty()) {
    QString var_string = ui->lineEdit->text();
    double var = var_string.toDouble();
    int_bin.clear();
    double_bin.clear();

    if (var_string.indexOf('.') == -1 and var_string.indexOf(',') == -1 or
        var_string.indexOf('.') == var_string.size() - 1 or
        var_string.indexOf(',') == var_string.size() - 1) {
      qlonglong var1 = var;

      recursia(qAbs(var1));

      if (var_string[0] == QChar('-')) {
        int_bin.insert(0, '-');
      }

      ui->label->setText(int_bin);
      ui->label->adjustSize();

    } else if ((var_string.indexOf('.') == 1 or
                var_string.indexOf(',') == 1) and
               var_string[0] == QChar('0')) {
      recursia(qAbs(var));

      if (var_string[0] == QChar('-')) {
        double_bin.insert(0, '-');
      }
      ui->label->setText(double_bin);
      ui->label->adjustSize();
    }

    else {
      qlonglong var1 = var;

      var = qAbs(var - var1);

      recursia(qAbs(var1));

      recursia(var);

      if (var_string.at(0) == QChar('-')) {
        int_bin.insert(0, '-');
      }

      QString str = int_bin + "." + double_bin;
      ui->label->setText(str);
      ui->label->adjustSize();
    }
  }
}
