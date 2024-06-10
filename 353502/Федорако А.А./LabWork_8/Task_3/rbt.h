#ifndef RBT_H
#define RBT_H

#include <QString>
#include <QVector>

enum class Color { Red, Black };

struct Node {
  int key;
  QString value;
  Color color = Color::Red;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
};

class RBT {
 private:
  //siblin - братья, parent - отец, root - корень,
  void rotateLeft(Node*& root, Node*& node);
  void rotateRight(Node*& root, Node*& node);
  void fixInsertRBT(Node*& root, Node*& node);
  void fixDeleteRBT(Node*& root, Node*& node);
  Node* insertNode(Node*& root, Node*& node);
  Node* deleteNode(Node*& root, int key);
  int deleteCase1(Node*& root, Node*& node);
  int deleteCase2(Node*& root, Node*& node);
  int deleteCase3(Node*& root, Node*& sibling, Node*& parent, Node*& pointer);
  int deleteCase4(Node*& root, Node*& sibling, Node*& parent, Node*& pointer);
  int deleteCase5(Node*& root, Node*& node);
  Color getColor(Node* node);
  void setColor(Node*& node, Color color);
  Node* min(Node*& node);
  Node* find(Node* node, int key);
  void clear(Node*& node);

 public:
  Node* root = nullptr;
  void clear();
  void insert(int key, QString value);
  void remove(int key);
  Node* min();
  Node* find(int key);
  QVector<int> directTraversal(Node* node);
  QVector<QPair<Color, QPair<int, int>>> directTraversalTree(
      Node* node, Node* parent = nullptr);
};

#endif  // RBT_H
