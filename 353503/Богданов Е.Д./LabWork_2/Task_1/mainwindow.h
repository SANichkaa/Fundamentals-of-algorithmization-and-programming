#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QTableWidget>
#include <QVector>
#include <string>

#include "date.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow() override;

 private slots:

  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_5_clicked();

private:
  Ui::MainWindow* ui;
  Date* date_class;
  QVector<QString> mass_str;
  QString way_to_file;
  int size = 0;
  bool file_open = false;

  enum months { n1 = 1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12 };

  enum days_in_month { n28 = 28, n29, n30, n31 };
};
#endif  // MAINWINDOW_H
