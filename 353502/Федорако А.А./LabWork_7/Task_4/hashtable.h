#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QDebug>
#include <QPair>
#include <QRandomGenerator>
#include <QVector>
#include <chrono>

template <typename T>

class HashTable {
 private:
  QVector<QPair<int, T>> table;
  int _capacity = 1;
  int _size = 0;
  const int MAX_RANDOM = pow(10, 9);
  const double RESIZE_CONDITION = 0.75;
  int hash(int x) {
    int random = QRandomGenerator::global()->bounded(0, MAX_RANDOM);
    return (x ^= random) % _capacity;
  }

 public:
  HashTable(int size) : _capacity(size) { table.resize(size); }
  void add(int key, T data) {
    int code = hash(key);
    if (table[code].first == NULL) {
      table[code] = QPair<int, T>(key, data);
      _size++;
    } else {
      if (RESIZE_CONDITION * _size > _capacity) {
        _capacity *= 2;
        resize();
      }

      int number = code;

      while (number < _capacity && table[number].first != 0) {
        number++;
      }
      if (number != _capacity) {
        table[number] = QPair<int, T>(key, data);
        _size++;
        return;
      } else {
        number = 0;
        while (number < code && table[number].first != NULL) {
          number++;
        }
        if (number == code) {
          return;
        } else {
          table[number] = QPair<int, T>(key, data);
          _size++;
          return;
        }
      }
    }
  }

  void resize() {
    QVector<QPair<int, T>> temp(_capacity);
    std::swap(temp, table);
    for (QPair<int, T> element : temp) {
      add(element.first, element.second);
    }
  }

  void remove(int key) {
    int code = hash(key);
    if (table[code].first == key) {
      table[code] = NULL;
      _size--;
    } else {
      int number = code;
      while (number < _capacity && table[number].first != key) {
        number++;
      }
      if (number == _capacity) {
        number = 0;
        while (number < code && table[number].first != key) {
          number++;
        }
        if (number == code) {
          return;
        } else {
          table[number] = NULL;
          _size--;
        }
      } else {
        table[number] = NULL;
        _size--;
      }
    }
  }

  T find(int key) {
    int code = hash(key);
    if (table[code].first == key) {
      return table[code].second;
    } else {
      int number = code;
      while (number < _capacity && table[number].first != key) {
        number++;
      }
      if (number == _capacity) {
        number = 0;
        while (number < code && table[number].first != key) {
          number++;
        }
        if (number == code) {
          return NULL;
        } else {
          return table[number].second;
        }
      } else {
        return table[number].second;
      }
    }
  }
  int capacity() { return _capacity; }
  int size() { return _size; }
  QVector<QPair<int, T>> toVector() { return table; }
};

#endif  // HASHTABLE_H
