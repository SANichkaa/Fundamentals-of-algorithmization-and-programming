#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

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
  void recursia(qlonglong var);
  void recursia(double var);

private slots:
  void on_lineEdit_returnPressed();
private:
  Ui::MainWindow *ui;
  QString int_bin, double_bin;
  int cheker=0;
};
#endif  // MAINWINDOW_H
