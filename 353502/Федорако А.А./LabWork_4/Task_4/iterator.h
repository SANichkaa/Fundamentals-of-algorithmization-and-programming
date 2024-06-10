#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
class Iterator {
  T* iterator;

 public:
  Iterator(T* first) : iterator(first) {}

  T& operator+(int number) { return *(iterator + number); }

  T& operator-(int number) { return *(iterator - number); }

  T& operator++() { return *iterator++; }

  T& operator--() { return *iterator--; }

  T& operator*() { return *iterator; }

  bool operator!=(Iterator x) { return iterator != x; }

  int distance(Iterator<T>& other) { return iterator - other.it; }
};

#endif  // ITERATOR_H
