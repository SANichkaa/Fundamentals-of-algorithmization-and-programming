#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include "binaryheaparray.h"
#include "binaryheaplist.h"

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

  BinaryHeapArray* heapArray;
  BinaryHeapList* heapList;

 private slots:
  void on_pushButton_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_4_clicked();
  void on_pushButton_5_clicked();
  void on_pushButton_6_clicked();
  void on_pushButton_2_clicked();

 private:
  Ui::MainWindow* ui;
  void showBinaryHeap();
  QString getText(QVector<int> arr);
  QString getText1(QVector<int> arr);
  const int MAX_RANDOM_NUMBER = 100;
  const int HEAP_ARRAY_SIZE = 16;
};
#endif  // MAINWINDOW_H
