#ifndef CUSTOMHASHTABLE_H
#define CUSTOMHASHTABLE_H

#include "hashtable.h"

template <typename T>
class CustomHashTable : public HashTable<T> {
 public:
  CustomHashTable(int size) : HashTable<T>(size) {}
};

#endif  // CUSTOMHASHTABLE_H
