#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QTableWidget>
#include "customhashtable.h"

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
  HashTable<QString>* table;
 private slots:
  void on_pushButton_clicked();

 private:
  const char SYMBOLS[28] = "abcdefghijklmnopqrstuvwxyz ";
  const int LINE_MINIMUM_SIZE = 2;
  const int LINE_MAXIMUM_SIZE = 10;
  const int MINIMUM_RANDOM_KEY = -50;
  const int MAXIMUM_RANDOM_KEY = 50;
  const int SIZE_ALPHABET = 28;
  const int MINIMUM_NUMBER_RANDOM_ELEMENT = 10;
  const int MAXIMUM_NUMBER_RANDOM_ELEMENT = 40;
  const int NUMBER_HASH_TABLE_SIZE = 100;
  void showFirstTable();
  void showSecondTable();
  void showThirdTable();
  void setRandTable();
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
