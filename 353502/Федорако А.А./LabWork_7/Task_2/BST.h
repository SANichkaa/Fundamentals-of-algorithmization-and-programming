#ifndef BST_H
#define BST_H

#include <QDebug>
#include <QPair>
#include <QString>
#include <QVector>

struct Node {
  int key;
  QString value;
  unsigned char height;
  Node* left;
  Node* right;
  Node(int key, QString value) {
    this->key = key;
    this->value = value;
    left = right = nullptr;
    height = 1;
  }
};

class BST {
 public:
  Node* root = nullptr;
  BST();
  unsigned char height(Node* node);
  int bfactor(Node* node);
  void fixHeight(Node* node);
  void rotateRight(Node*& node);
  void rotateLeft(Node*& node);
  void balance(Node*& node);
  void insert(Node*& node, int key, QString value);
  Node* findMin(Node* node);
  void remove(Node*& node, int key);
  Node* removeMin(Node* node);
  Node* select(Node* node, int key);
  int getNumberElementTwoChildren(Node* node);
  QVector<QPair<int, QString>> directTraversal(Node* node);
  QVector<QPair<int, int>> directTraversalTree(Node* node,
                                               Node* parent = nullptr);
  QVector<QPair<int, QString>> reverceTraversal(Node* node);
  QVector<QPair<int, QString>> simmetricalTraversal(Node* node);
};

#endif  // BST_H
