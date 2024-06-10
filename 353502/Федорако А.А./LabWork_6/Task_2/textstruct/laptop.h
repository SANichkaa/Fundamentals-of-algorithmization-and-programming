#ifndef LAPTOP_H
#define LAPTOP_H

#include <QDebug>
#include <QString>

class Laptop {
 public:
  Laptop();
  ~Laptop() = default;
  void setYear(int yearConstruction);
  void setStatusWork(bool statusWork);
  void setPrice(double price);
  void setGrade(char grade);
  int getYearConstruction();
  bool getStatusWork();
  double getPrice();
  char getGrade();
  QString toString();
  const int YEAR_CREATION_FIRST_LAPTOP = 1981;

 private:
  char delimiter = ' ';
  int yearConstruction;
  bool statusWork;
  double price;
  char grade;  // from A to F
  const QVector<char> OPERATION_SYSTEMS = {'L', 'W', 'M'};
  const QVector<double> DIAGONAL_SIZES = {10.6, 11.1, 11.6, 12.1, 13.1, 13.3,
                                          14.0, 14.1, 14.5, 15.0, 15.1, 15.6,
                                          16.0, 16.4, 17.0, 17.1, 17.3, 18.4};
};

#endif  // LAPTOP_H
