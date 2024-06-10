#ifndef MAP_H
#define MAP_H

#include "rbt.h"

class Map {
  RBT tree;

  Map(){};

  void insert(int key, QString value) { tree.insert(key, value); }

  QString find(int key) {
    Node* node = tree.find(key);
    if (node) {
      return node->value;
    }
    throw "Element with this key is not found";
  }

  void erase(int key) { tree.remove(key); }

  void clear() { return tree.clear(); }
};

#endif  // MAP_H
