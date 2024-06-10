#ifndef TEXTARRAY_H
#define TEXTARRAY_H

#include <QDebug>
#include <QString>
#include <fstream>
#include <iostream>
#include <sstream>

class TextArray {
 public:
  TextArray();
  void addText(QString text);
  QString getText();
  const QString FILE_NAME = "ФедоракоЛаб20_0.txt";
};

#endif  // TEXTARRAY_H
