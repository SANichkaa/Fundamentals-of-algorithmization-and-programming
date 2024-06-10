#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QTableWidget>
#include "queue.h"

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
  Queue<int>* firstQueue = new Queue<int>();
  Queue<int>* secondQueue = new Queue<int>();
  Queue<int>* thirdQueue = new Queue<int>();
 private slots:
  void on_pushButtonPop_clicked();
  void on_pushButtonPush_clicked();
  void on_pushButton_clicked();

 private:
  void setQueueRandomElements(Queue<int>* queue);
  int getIndexMinElement(QVector<int> arr);
  int getIndexMaxElement(QVector<int> arr);
  void setTableWidget(QTableWidget* widget, Queue<int>* queue);
  bool buttonState;
  const int MAX_RANDOM_VALUE_QUEUE = 200;
  const int MIN_RANDOM_VALUE_SIZE_QUEUE = 10;
  const int MAX_RANDOM_VALUE_SIZE_QUEUE = 25;
  const QString FIRST_BUTTON_STATE = "Генерация списков из случайных значений";
  const QString SECOND_BUTTON_STATE = "Объединение списков";
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
