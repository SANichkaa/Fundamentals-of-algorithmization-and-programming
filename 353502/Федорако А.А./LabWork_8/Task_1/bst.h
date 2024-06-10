#ifndef BST_H
#define BST_H

#include <QDebug>
#include <QRandomGenerator>
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

class BST {

 public:
  struct Node {
    int key;
    QString value;
    Node* left;
    Node* right;
    Node(int key, QString value) {
      this->key = key;
      this->value = value;
      left = right = nullptr;
    }
  };

  Node* root = nullptr;

  BST();

  void insert(int key, QString value);

  void insert(Node*& node, int key, QString value);

  void remove(int key);

  void remove(Node*& node, int key);

  Node* findMin(Node* node);

  Node* deleteMin(Node* node);

  int size();

  int size(Node* node);

  QString select(int key);

  QString select(Node* node, int key);

  Node* selectNode(Node* node, int key);

  QVector<QPair<int, QString>> directTraversal();

  QVector<QPair<int, QString>> directTraversal(Node* node);

  QVector<QPair<int, int>> directTraversalTree(Node* node,
                                               Node* parent = nullptr);

  void insertTree(BST* tree);

  void removeTree(BST* tree);

  void clear();

  void clear(Node*& root);

  void removeBranch(int key);
};

#endif  // BST_H
