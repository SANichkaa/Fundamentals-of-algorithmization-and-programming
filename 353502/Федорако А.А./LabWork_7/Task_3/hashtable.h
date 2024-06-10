#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QDebug>
#include <QPair>
#include <QRandomGenerator>
#include <QVector>
#include "stack.h"

template <typename T>

class HashTable {
 protected:
  QVector<Stack<T>> table;
  int capacity = 1;
  int hash(int x) { return capacity / 2 + (x % capacity); }

 public:
  HashTable(int size) : capacity(size) { table.resize(size); }
  void add(int key, T data) {
    qDebug() << capacity << hash(key);
    table[hash(key)].push(data);
  }
  void remove(int key) { table[hash(key)].pop(); }
  T read(int key) { return table[hash(key)].peek; }
  int size() { return capacity; }
  QVector<Stack<T>> toVector() { return table; }
};

#endif  // HASHTABLE_H
