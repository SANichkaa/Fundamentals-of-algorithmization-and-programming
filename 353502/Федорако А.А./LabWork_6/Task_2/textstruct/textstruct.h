#ifndef TEXTSTRUCT_H
#define TEXTSTRUCT_H

#include <QDebug>
#include <QString>
#include <fstream>
#include <iostream>
#include <sstream>

class TextStruct {
 public:
  TextStruct();
  void addText(QString text);
  QString getText();
  const QString FILE_NAME = "ФедоракоЛаб20_1.txt";
};

#endif  // TEXTSTRUCT_H
