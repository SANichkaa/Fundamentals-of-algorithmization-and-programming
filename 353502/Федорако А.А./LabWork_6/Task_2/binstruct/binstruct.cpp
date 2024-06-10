#include "binstruct.h"
#include <fstream>
#include <iomanip>
#include <iostream>

BinStruct::BinStruct() {}

void BinStruct::addData(Laptop data) {
  std::ofstream file("ФедоракоЛаб20_2.bin", std::ios::binary | std::ios::app);
  if (file.is_open()) {
    file.write(reinterpret_cast<const char*>(&data), sizeof(data));
    qDebug() << "Информация успешно записана в файл " + FILE_NAME;
    file.close();
  } else {
    qDebug() << "Не удалось открыть файл для записи";
  }
}

QString BinStruct::getText() {
  QString result = "";
  std::ifstream file("ФедоракоЛаб20_2.bin", std::ios::binary);
  if (file.is_open()) {
    Laptop laptop;
    while (file.read(reinterpret_cast<char*>(&laptop), sizeof(laptop))) {
      result += QString::number(laptop.getPrice()) + " " + laptop.getGrade() +
                " " + laptop.getYearConstruction() + " " +
                laptop.getStatusWork() + "\n";
    }
  } else {
    qDebug() << "Не удалось открыть файл для чтения";
  }
  return result;
}
