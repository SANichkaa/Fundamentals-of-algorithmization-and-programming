#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QRandomGenerator>
#include <algorithm>
#include <QStack>
#include <functional>
#include <iostream>
#include <memory>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>
#include "BST.h"

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
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_4_clicked();
  void on_pushButton_5_clicked();
  void on_pushButton_6_clicked();
  void on_pushButton_8_clicked();

 private:
  BST* tree;
  const int SIZE_ALPHABET = 28;
  const int MIN_RANDOM_LINE_SIZE = 2;
  const int MAX_RANDOM_LINE_SIZE = 10;
  const int MAX_VALUE_RANDOM_NUMBER = 250;
  const char SYMBOLS[28] = "abcdefghijklmnopqrstuvwxyz";
  void consoleOutput(
      Node* node, bool high = true,
      std::vector<std::string> const& lpref = std::vector<std::string>(),
      std::vector<std::string> const& cpref = std::vector<std::string>(),
      std::vector<std::string> const& rpref = std::vector<std::string>(),
      bool root = true, bool left = true,
      std::shared_ptr<std::vector<std::vector<std::string>>> lines = nullptr);
  void setTableWidget(QVector<QPair<int, QString>> result);
  void setTableTree();
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
