#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include <functional>
#include <iostream>

#include "binaryoperation.h"
#include "number.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  bool check_equals(const Expression *left, const Expression *right);
  ~MainWindow() override;

 private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
