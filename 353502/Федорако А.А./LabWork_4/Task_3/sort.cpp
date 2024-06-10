#include "sort.h"

Sort::Sort() {}

QVector<int> Sort::MedianSort(QVector<int> arr) {
  QVector<int> temp;
  QVector<int> result;
  for (int i = 0; i < arr.size(); i++) {
    temp.push_back(arr[i]);
    if (temp.size() == 3) {
      InsersionSort(temp);
      result.push_back(temp[1]);
      temp.clear();
    }
  }
  if (temp.size() != 0) {
    int sum = 0;
    for (int i = 0; i < temp.size(); i++) {
      sum += temp[i];
    }
    result.push_back(sum / temp.size());
  }
  return result;
}

void Sort::InsersionSort(QVector<int> arr) {
  int t = 0;
  for (int i = 1; i < arr.size(); i++) {
    for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
      t++;
      int temp = arr[j - 1];
      arr[j - 1] = arr[j];
      arr[j] = temp;
    }
  }
}
