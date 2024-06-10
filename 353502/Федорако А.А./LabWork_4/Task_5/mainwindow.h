#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include "pair.h"
#include "vector.h"

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

 private:
  Pair<Vector<int>, Vector<Pair<int, double>>> pair;
  void setFirstMatrix();
  void setSecondMatrix();
  Ui::MainWindow* ui;
  const int SIZE_MATRIX = 12;
  const double FIRST_NUMBER = 12.12;
  const int SECOND_NUMBER = 10;
  const double THIRD_NUMBER = 15.15;
  const int SECOND_TABLE_COLUMB_WIDTH = 213;
};
#endif  // MAINWINDOW_H
