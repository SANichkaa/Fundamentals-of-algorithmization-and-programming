#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QTreeWidget>
#include "bst.h"

#define LN \
  { std::cout << __LINE__ << std::endl; }
#define DEB(x) \
  { std::cout << #x << "=(" << (x) << ") "; }

static std::string ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\",
                   ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-",
                   ch_ddia_hor = "/-", ch_ver_spa = "| ";

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
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_4_clicked();
  void on_pushButton_5_clicked();
  void on_pushButton_6_clicked();
  void on_pushButton_7_clicked();
  void on_pushButton_8_clicked();
  void on_pushButton_9_clicked();
  void on_pushButton_10_clicked();
  void on_pushButton_11_clicked();

 private:
  Ui::MainWindow* ui;
  BST* tree = new BST();
  BST* helpTree = new BST();
  void setTableWidget(QVector<QPair<int, QString>> result);
  void setTableTree(QTreeWidget* widget, BST* tree);
  void consoleOutput(
      BST::Node* node, bool high = true,
      std::vector<std::string> const& lpref = std::vector<std::string>(),
      std::vector<std::string> const& cpref = std::vector<std::string>(),
      std::vector<std::string> const& rpref = std::vector<std::string>(),
      bool ro = true, bool left = true,
      std::shared_ptr<std::vector<std::vector<std::string>>> lines = nullptr);
  const char SYMBOLS[28] = "abcdefghijklmnopqrstuvwxyz";
  const int SIZE_ALPHABET = 28;
  const int MIN_RANDOM_LINE_SIZE = 2;
  const int MAX_RANDOM_LINE_SIZE = 10;
  const int MAX_VALUE_RANDOM_NUMBER = 250;
};
#endif  // MAINWINDOW_H
