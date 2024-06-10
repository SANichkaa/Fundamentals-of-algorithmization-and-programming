#ifndef SORT_H
#define SORT_H

#include <QVector>

class Sort {
 public:
  Sort();
  static QVector<int> MedianSort(QVector<int> arr);
  static void InsersionSort(QVector<int> arr);
};

#endif  // SORT_H
