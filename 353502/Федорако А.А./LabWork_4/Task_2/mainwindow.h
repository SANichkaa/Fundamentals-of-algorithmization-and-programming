#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QThread>
#include <QTime>

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
  void on_pushButton_2_clicked();
  void on_pushButton_clicked();

 private:
  QVector<int> array;
  QVector<int> temp;
  void interpolationSort(QVector<int>& arr);
  QVector<int> getRandArr(int size);
  QGraphicsScene* scene;
  Ui::MainWindow* ui;
  void showArray(QVector<int> arr);
  void changeElementArrayShow(QVector<int> arr);
  const int SLEEP_TIME = 50000;
  const int MAX_NUMBER = 400;
  const int SIZE_RANDOM_ARRAY = 39;
};
#endif  // MAINWINDOW_H
