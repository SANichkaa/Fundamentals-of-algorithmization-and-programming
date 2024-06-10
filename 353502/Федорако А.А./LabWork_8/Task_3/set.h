#ifndef SET_H
#define SET_H

#include "rbt.h"

class Set {
  RBT tree;

  Set(){};

  void insert(int key) { tree.insert(key, ""); }

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

#endif  // SET_H
