#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QFileDialog>
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
  void listFoldersAndFiles(const QString &path, QTextStream &stream, int &totalFolders, int &totalFiles);

 private slots:
  void on_pushButton_clicked();

 private:
  Ui::MainWindow *ui;
  QString way_to_papka;
};
#endif  // MAINWINDOW_H
