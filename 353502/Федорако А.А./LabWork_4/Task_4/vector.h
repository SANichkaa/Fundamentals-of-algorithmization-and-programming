#ifndef VECTOR_H
#define VECTOR_H

#include <cstdint>
#include <cstdio>
#include <stdexcept>
#include "iterator.h"
#include "reverceiterator.h"

template <typename T>
class Vector {

 private:
  T* _array = nullptr;
  size_t _size = 0;
  size_t _capacity = 1;

 public:
  using iterator = Iterator<T>;
  using reverceIterator = ReverceIterator<T>;
  using constIterator = Iterator<const T>;
  Vector() : _array(nullptr), _size(0), _capacity(1) {}

  Vector(size_t n) { resize(n); }

  Vector(Vector<T>& vector) {
    _size = vector._size;
    _capacity = vector._capacity;
    _array = reinterpret_cast<T*>(new char[_size * sizeof(T)]);
    for (size_t i = 0; i < _size; i++) {
      new (_array + i) T(vector[i]);
    }
  }

  ~Vector() {
    for (size_t i = 0; i < _size; i++) {
      (_array + i)->~T();
    }
    delete[] reinterpret_cast<char*>(_array);
    _array = nullptr;
    _capacity = 0;
    _size = 0;
  }

  //assign +
  void assign(size_t number, T value) {
    clear();
    resize(number, value);
  }
  void assign(iterator begin, iterator end) {
    resize(begin.distance(end));
    size_t i = 0;
    for (iterator it = begin; it != end; ++it, i++) {
      _array[i] = *it;
    }
  }

  //at +
  const T& at(size_t i) {
    if (i >= _size)
      throw std::out_of_range("");
    return _array[i];
  }

  //back +
  T& back() { return _array[_size - 1]; }

  //begin +
  iterator begin() { return iterator(_array); }

  //capacity +
  size_t capacity() { return _capacity; }

  //cbegin +
  constIterator cbegin() const { return constIterator(_array); }

  //clear +
  void clear() { resize(0); }

  //data +
  T* data() {
    if (empty()) {
      return nullptr;
    }
    return _array;
  }

  //emplace +
  iterator emplace(iterator it, T& value) {
    size_t length = it.distance(begin());
    resize(_size + 1);
    for (size_t i = length; i < _size; i++) {
      _array[i + 1] = T(_array[i]);
    }
    _array[length] = value;
    return iterator(begin() + length);
  }

  //emplace_back +
  void emplace_back(T& value) {
    if (_capacity == _size) {
      reserve(2 * _size);
    }
    _array[_size] = value;
    _size++;
  }

  //empty +
  bool empty() { return (_size ? false : true); }

  //end +
  iterator end() { return iterator(_array + _size); }

  //erase +
  iterator erace(iterator it) {
    size_t length = it.distanse(begin());
    for (size_t i = length; i < _size - 1; i++) {
      _array[i] = T(_array[i + 1]);
    }
    resize(_size - 1);
    return iterator(begin() + length);
  }
  iterator erace(iterator start, iterator end) {
    size_t length = start.distanse(begin());
    size_t distance = end.distance(start());
    for (size_t i = length; i < _size - 1; i++) {
      _array[i + 1] = T(_array[i + distance]);
    }
    resize(_size - distance);
    return iterator(begin() + length);
  }

  //front +
  T& front() { return _array; }

  //insert +
  iterator insert(iterator it, T& value) {
    size_t length = it.distance(begin());
    resize(_size + 1);
    for (size_t i = length; i < _size; i++) {
      _array[i + 1] = T(_array[i]);
    }
    _array[length] = value;
    return iterator(begin() + length);
  }

  //max_size +
  long long max_size() { return INT64_MAX / sizeof(T); }

  //pop_back +
  void pop_back() {
    _size--;
    (_array + _size)->~T();
  }

  //push_back +
  void push_back(T value) {
    if (_capacity <= _size) {
      reserve(2 * _size);
    }
    new (_array + _size) T(value);
    _size++;
  }

  //rbegin +
  reverceIterator rbegin() { return reverceIterator(_array); }

  //rend +
  reverceIterator rend() { return reverceIterator(_array + _size); }

  //reserve +
  void reserve(size_t n) {
    if (n <= _capacity) {
      return;
    }
    T* temp = reinterpret_cast<T*>(new char[n * sizeof(T)]);
    for (size_t i = 0; i < _size; i++) {
      new (temp + i) T(_array[i]);
    }
    for (size_t i = 0; i < _size; i++) {
      (_array + i)->~T();
    }
    delete[] reinterpret_cast<char*>(_array);
    _array = temp;
    _capacity = n;
  }

  //resize +
  void resize(size_t n, const T& value = T()) {
    if (n > _capacity)
      reserve(n);
    for (size_t i = _size; i < n; i++) {
      new (_array + i) T(value);
    }
    _size = n;
  }

  //size +
  size_t size() const { return _size; }

  //swap +
  void swap(Vector<T> arr) {
    T* temp = arr;
    arr = _array;
    _array = arr;
    delete[] temp;
  }

  //operator[]
  T& operator[](size_t i) { return _array[i]; }
  const T& operator[](size_t i) const { return _array[i]; }
};

#endif  // VECTOR_H
