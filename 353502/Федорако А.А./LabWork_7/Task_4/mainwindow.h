#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QElapsedTimer>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QRandomGenerator>
#include "hashtable.h"

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
  HashTable<QString>* table16;
  HashTable<QString>* table64;
  HashTable<QString>* table128;
  HashTable<QString>* table2048;
  QGraphicsScene scene;

 private:
  void updateSchedule();
  void showSchedule(int* time);
  void fillPartTable(HashTable<QString>* table, int size);
  int getTime(HashTable<QString>* table);
  Ui::MainWindow* ui;

  const char SYMBOLS[28] = "abcdefghijklmnopqrstuvwxyz ";
  const int SIZE_ALPHABET = 28;
  const int MIN_RANDOM_LINE_SIZE = 2;
  const int MAX_RANDOM_LINE_SIZE = 10;
  const int FIRST_TABLE_SIZE = 16;
  const int SECOND_TABLE_SIZE = 64;
  const int THIRD_TABLE_SIZE = 128;
  const int FOURTH_TABLE_SIZE = 2048;
  const double SIZE_FACTOR = 0.6;
  const int SIZE_CHECK_TABLE_ELEMENT = 5096;
  const int MAX_RANDOM_NUMBER_VALUE = 5000;
};
#endif  // MAINWINDOW_H
