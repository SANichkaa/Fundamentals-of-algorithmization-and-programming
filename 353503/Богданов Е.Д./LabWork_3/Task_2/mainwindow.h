#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
  qlonglong Akerman(int m, int n);

 private slots:
  void on_lineEdit_returnPressed();

  void on_lineEdit_2_returnPressed();

 private:
  Ui::MainWindow *ui;
  qlonglong result;
  short cheker=0;
};
#endif  // MAINWINDOW_H
