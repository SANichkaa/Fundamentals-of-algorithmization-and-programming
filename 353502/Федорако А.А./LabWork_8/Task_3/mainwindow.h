#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QStack>
#include <QPair>
#include <QRandomGenerator>
#include <stack>
#include "rbt.h"

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
  RBT* tree = new RBT();
  void setTableTree();
 private slots:
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_4_clicked();
  void on_pushButton_5_clicked();

 private:
  Ui::MainWindow* ui;
  const int SIZE_ALPHABET = 28;
  const int MIN_RANDOM_LINE_SIZE = 2;
  const int MAX_RANDOM_LINE_SIZE = 10;
  const int MAX_VALUE_RANDOM_NUMBER = 250;
  const char SYMBOLS[28] = "abcdefghijklmnopqrstuvwxyz";
};
#endif  // MAINWINDOW_H
