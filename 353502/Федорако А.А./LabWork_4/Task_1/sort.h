#ifndef SORT_H
#define SORT_H

#include <algorithm>
#include <cmath>

class Sort {
 public:
  Sort();
  static void heapSort(long* arr, long size);
  static void quickSort(long* arr, long size);
  static void mergeSort(long* arr, long size);
  static void mergeSort(long* arr, long left, long right);

 private:
  static void heapify(long* arr, long size, long i);
  static void merge(long* arr, long start, long mid, long end);
};

#endif  // SORT_H
