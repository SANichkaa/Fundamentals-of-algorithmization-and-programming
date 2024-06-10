#ifndef BINARYHEAPLIST_H
#define BINARYHEAPLIST_H

#include <QDebug>
#include <QVector>
#include <algorithm>
#include <memory>

struct Node {
  int _key;
  std::weak_ptr<Node> parent;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;
  Node(int key) : _key(key) {}
};

class BinaryHeapList {
 private:
  std::shared_ptr<Node> root;
  int _size = 0;

  QVector<int> getKeys(std::shared_ptr<Node> node) {
    QVector<int> result;
    if (node) {
      result.push_back(node->_key);
      result += getKeys(node->left);
      result += getKeys(node->right);
    }
    return result;
  }

  void heapifyDown(std::shared_ptr<Node> node) {
    if (!node) {
      return;
    }
    if (node->right && node->right->_key > node->_key) {
      std::swap(node->_key, node->right->_key);
      heapifyDown(node->right);
    } else if (node->left && node->left->_key > node->_key) {
      std::swap(node->_key, node->left->_key);
      heapifyDown(node->left);
    }
  }

  void heapifyUp(std::shared_ptr<Node> node) {
    if (!node || !node->parent.lock()) {
      return;
    } else if (node->_key > node->parent.lock()->_key) {
      std::swap(node->_key, node->parent.lock()->_key);
      heapifyUp(node->parent.lock());
    }
  }

 public:
  BinaryHeapList() : _size(0), root(nullptr) {}

  ~BinaryHeapList() {}

  void add(int key) {
    QVector<bool> path;
    int temp = _size + 1;
    while (temp > 1) {
      path.push_back(temp % 2 == 1);
      temp /= 2;
    }
    std::shared_ptr<Node> node = root;
    for (int i = path.size() - 1; i > 0; i--) {
      node = path[i] ? node->right : node->left;
    }
    if (!node) {
      root = std::make_shared<Node>(key);
      _size++;
      return;
    }
    std::shared_ptr<Node> ptr = path[0] ? node->right : node->left;
    ptr = std::make_shared<Node>(key);
    ptr->parent = node;
    heapifyUp(ptr);
    _size++;
  }

  int max() {
    if (root) {
      return root->_key;
    } else {
      throw "Binary heap is empty";
    }
  }

  void removeMax() {
    if (!root) {
      return;
    }
    if (_size == 1) {
      root.reset();
      _size--;
      return;
    }
    QVector<bool> path;
    int number = _size;
    while (number > 1) {
      path.push_back(number % 2 == 1);
      number /= 2;
    }
    std::shared_ptr<Node> node = root;
    for (int i = path.size() - 1; i >= 0; i--) {
      (!path[i]) ? node = node->left : node = node->right;
    }
    int temp = root->_key;
    root->_key = node->_key;
    node->_key = temp;
    path[0] ? node->parent.lock()->right.reset()
            : node->parent.lock()->left.reset();
    node.reset();
    heapifyDown(root);
    _size--;
  }

  bool empty() { return _size == 0; }

  QVector<int> getKeys() { return getKeys(root); }

  int size() { return _size; }
};

#endif  // BINARYHEAPLIST_H
