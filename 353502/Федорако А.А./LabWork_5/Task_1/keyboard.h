#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QDebug>
#include <QString>
#include <QVector>

class Keyboard {
 public:
  Keyboard();
  static QVector<QString> getEnglishKeyboard(bool isShift, bool isCaps);
  static QVector<QString> getGermanKeyboard(bool isShift, bool isCaps);
  static QVector<QString> getRussianKeyboard(bool isShift, bool isCaps);
  static QVector<QString> getFranchKeyboard(bool isShift, bool isCaps);
  static QVector<QString> getHebrewKeyboard(bool isShift, bool isCaps);
};

#endif  // KEYBOARD_H
