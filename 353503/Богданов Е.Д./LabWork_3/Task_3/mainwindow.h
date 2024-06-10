#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QTimer>

#include "myrect.h"
#include "scena.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;
 private slots:
  void on_lineEdit_returnPressed();

  void update_info();

  void on_pushButton_3_clicked();

  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_spinBox_editingFinished();

 private:
  Ui::MainWindow *ui;
  Scena *scene;
  QTimer *timer;
  int steps = 0;
  int n;
  QGraphicsRectItem* tower1;
  QGraphicsRectItem* tower2;
  QGraphicsRectItem* tower3;
};
#endif  // MAINWINDOW_H
