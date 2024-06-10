#ifndef REVERCEITERATOR_H
#define REVERCEITERATOR_H

template <typename T>
class ReverceIterator {
  T* it;

 public:
  ReverceIterator(T* first) : it(first) {}

  T& operator+(int n) { return *(it - n); }

  T& operator-(int n) { return *(it + n); }

  T& operator++() { return *it--; }

  T& operator--() { return *it++; }

  T& operator*() { return *it; }

  int distance(ReverceIterator<T>& other) { return it - other.it; }
};

#endif  // REVERCEITERATOR_H
