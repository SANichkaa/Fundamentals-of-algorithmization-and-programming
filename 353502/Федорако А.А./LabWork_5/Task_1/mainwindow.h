#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QElapsedTimer>
#include <QKeyEvent>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QTimer>
#include <QVector>
#include <iostream>
#include "fileprocessing.h"
#include "keyboard.h"

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
  void on_pushButton_65_clicked();
  void updateLabel();
  void setNewKeyboard(int index, bool isShift = false, bool isCaps = false);
  void updateTime();
  void start();
  void updateText(int number);
  void finish();

 private:
  Ui::MainWindow* ui;
  QVector<int> arrayNumberKeyboardSymbols;
  QVector<QPushButton*> arrayButtons;
  QVector<QString> getEnglishKeyboard();
  int getNumberButton(int code);
  void setArrayButton();
  FileProcessing* file;
  void setArrayNumberKeyboardSymbols();
  void setColorButtons();
  QString text;
  QString textEnglish;
  QString textFrance;
  QString textGerman;
  QString textRussian;
  QString textHerbew;
  void setTextAllLanguages();
  bool isCapsPress = false;
  void keyPressEvent(QKeyEvent* event) override;
  void keyReleaseEvent(QKeyEvent* event) override;
  int keyboardIndex;
  int correctSymbol;
  int uncorrectSymbol;
  double getPersent();
  QTimer* updateTimer;
  QTimer* timer;
  QTime time;
  int find(QVector<int> arr, int value);
  void setColorButton(int index);
  bool isWork;

  const int TIMER_FREEZE = 10;
  const int FONT_SIZE = 24;
  const double DENOMINATOR_SIZE = 1000.0;
  const unsigned int NUMBER_CAPSLOCK = 66;
  const unsigned int FIRST_NUMBER_SHIFT = 50;
  const unsigned int SECOND_NUMBER_SHIFT = 62;
  const double PERCENT_NUMBER = 100;
  const QVector<int> RED_COLOR_KEYS = {0, 1, 14, 15, 28, 29, 41, 42};
  const QVector<int> BLUE_COLOR_KEYS = {2, 16, 30, 43};
  const QVector<int> ORANGE_COLOR_KEYS = {3, 17, 31, 44};
  const QVector<int> YELLOW_COLOR_KEYS = {4, 18, 32, 45, 5, 19, 33, 46};
  const QVector<int> MAGENTA_COLOR_KEYS = {7, 21, 35, 48, 6, 20, 34, 47};
  const QVector<int> GREY_COLOR_KEYS = {8, 22, 36, 49};
  const QVector<int> CYAN_COLOR_KEYS = {9, 23, 37, 50};
  const QVector<int> PINK_COLOR_KEYS = {10, 11, 12, 13, 24, 25, 26,
                                        27, 38, 39, 40, 51, 52};
};
#endif  // MAINWINDOW_H
