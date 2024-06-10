#ifndef BINSTRUCT_H
#define BINSTRUCT_H

#include <QDebug>
#include <QString>
#include <fstream>
#include <iostream>
#include <sstream>
#include "./textstruct/laptop.h"

class BinStruct {
 public:
  BinStruct();
  void addData(Laptop data);
  QString getText();
  const QString FILE_NAME = "ФедоракоЛаб20_2.bin";
};

#endif  // BINSTRUCT_H
