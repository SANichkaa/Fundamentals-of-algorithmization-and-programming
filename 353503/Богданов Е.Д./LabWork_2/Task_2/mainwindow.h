#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QListWidget>
#include <QString>
#include "compitem.h"

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
  void on_pushButton_6_clicked();

  void on_pushButton_2_clicked();

  void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

  void on_listWidget_itemClicked(QListWidgetItem *item);

  void on_pushButton_clicked();

  void on_pushButton_3_clicked();

  void on_radioButton_clicked(bool checked);

  void on_pushButton_5_clicked();

  void on_pushButton_4_clicked();

  void on_checkBox_2_clicked();

  void on_checkBox_3_clicked();

  void on_checkBox_clicked();

private:
  Ui::MainWindow *ui;
  QString way_to_file;
  QVector<CompItem> Items;
};
#endif  // MAINWINDOW_H
