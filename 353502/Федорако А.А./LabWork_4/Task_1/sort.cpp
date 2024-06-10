#include "sort.h"

Sort::Sort() {}

void Sort::heapSort(long* arr, long size) {
  long* array = new long[size];
  for (long i = 0; i < size; i++) {
    array[i] = arr[i];
  }
  for (long i = size / 2 - 1; i >= 0; i--)
    heapify(array, size, i);

  for (long i = size - 1; i > 0; i--) {
    std::swap(array[0], array[i]);
    heapify(array, i, 0);
  }
}

void Sort::heapify(long* arr, long size, long i) {
  long largest = i;
  long l = 2 * i + 1;
  long r = 2 * i + 2;
  if (l < size && arr[l] > arr[largest])
    largest = l;

  if (r < size && arr[r] > arr[largest]) {
    largest = r;
  }

  if (largest != i) {
    std::swap(arr[i], arr[largest]);
    heapify(arr, size, largest);
  }
}

void Sort::quickSort(long* arr, long size) {
  long result = 0;
  long* array = new long[size];
  for (long i = 0; i < size; i++) {
    array[i] = arr[i];
  }
  long i = 0;
  long j = size - 1;
  long mid = array[size / 2];
  do {
    while (array[i] < mid) {
      i++;
    }
    while (array[j] > mid) {
      j--;
    }
    if (i <= j) {
      std::swap(array[i], array[j]);
      result++;
      i++;
      j--;
    }
  } while (i <= j);

  if (j > 0) {
    quickSort(&array[i], j + 1);
  }
  if (i < size) {
    quickSort(&array[i], size - i);
  }
}

void Sort::merge(long* arr, long left, long mid, long right) {
  long n1 = mid - left + 1;
  long n2 = right - mid;

  long* leftArr = new long[n1];
  long* rightArr = new long[n2];

  for (long i = 0; i < n1; i++)
    leftArr[i] = arr[left + i];
  for (long j = 0; j < n2; j++)
    rightArr[j] = arr[mid + 1 + j];

  long i = 0;
  long j = 0;
  long k = left;

  while (i < n1 && j < n2) {
    if (leftArr[i] <= rightArr[j]) {
      arr[k] = leftArr[i];
      i++;
    } else {
      arr[k] = rightArr[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = rightArr[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = rightArr[j];
    j++;
    k++;
  }
  delete[] leftArr;
  delete[] rightArr;
}

void Sort::mergeSort(long* arr, long left, long right) {
  if (left < right) {
    long mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

void Sort::mergeSort(long* arr, long size) {
  mergeSort(arr, 0, size);
}
