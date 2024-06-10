#ifndef BINARYHEAPARRAY_H
#define BINARYHEAPARRAY_H

#include <QDebug>
#include <QVector>
#include <memory>

class BinaryHeapArray {

  std::unique_ptr<int[]> _data;
  int _size;
  int _capacity;

  void resize() {
    std::unique_ptr<int[]> temp =
        std::unique_ptr<int[]>(new int[_capacity * 2]);
    for (int i = 0; i < _capacity; i++) {
      temp[i] = _data[i];
    }
    for (int i = _capacity; i < 2 * _capacity; i++) {
      temp[i] = -1;
    }
    _data = std::move(temp);
    setCorrectInfoOutput(_capacity);
    _capacity *= 2;
  }

 public:
  BinaryHeapArray(int capacity) : _capacity(capacity), _size(0) {
    _data = std::unique_ptr<int[]>(new int[_capacity]);
    setCorrectInfoOutput(0);
  }

  int heapSize() { return _size; }

  void add(int value) {
    if (_size + 1 == _capacity) {
      resize();
    }

    _data[_size] = value;
    int i = _size;
    int parent = (i - 1) / 2;

    while (i > 0 && _data[parent] < _data[i]) {
      int temp = _data[i];
      _data[i] = _data[parent];
      _data[parent] = temp;
      i = parent;
      parent = (i - 1) / 2;
    }

    _size++;
  }

  int size() { return _size; }

  int max() {
    if (_size) {
      return _data[0];
    } else {
      throw "Binary heap is empty";
    }
  }

  void removeMax() {
    if (_size == 0) {
      return;
    }

    std::swap(_data[0], _data[_size - 1]);
    _size--;

    int i = 0;
    while (true) {
      int leftChild = 2 * i + 1;
      int rightChild = 2 * i + 2;
      int largest = i;

      if (leftChild < _size && _data[leftChild] > _data[largest]) {
        largest = leftChild;
      }
      if (rightChild < _size && _data[rightChild] > _data[largest]) {
        largest = rightChild;
      }

      if (largest != i) {
        std::swap(_data[i], _data[largest]);
        i = largest;
      } else {
        break;
      }
    }

    _data[_size] = -1;
  }

  void setCorrectInfoOutput(int start) {
    while (start++ < _capacity) {
      _data[start] = -1;
    }
  }
  QVector<int> getKeys() {
    QVector<int> result;
    for (int i = 0; i < _capacity; ++i) {
      result.append(_data[i]);
    }
    return result;
  }
};

#endif  // BINARYHEAPARRAY_H
