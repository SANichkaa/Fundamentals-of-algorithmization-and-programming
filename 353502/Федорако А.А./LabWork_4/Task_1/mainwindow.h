#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QWidget>
#include <iostream>
#include "algorithm.h"
#include "logduration.h"
#include "sort.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_clicked();

 private:
  Ui::MainWindow* ui;
  void setRandomElements(long* arr, long size);
  const long SPIN_BOX_MAXIMUM_VALUE = 100000;
  const long MOD = 100000;
};
#endif  // MAINWINDOW_H
