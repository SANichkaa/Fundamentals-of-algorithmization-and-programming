#include "BST.h"
#include <QPair>

BST::BST() {}

unsigned char BST::height(Node* node) {
  return node ? node->height : 0;
}

int BST::bfactor(Node* node) {
  return height(node->right) - height(node->left);
}

void BST::fixHeight(Node* node) {
  unsigned char left = height(node->left);
  unsigned char right = height(node->right);
  node->height = (left > right ? left : right) + 1;
}

void BST::rotateRight(Node*& node) {
  Node* temp = node->left;
  node->left = temp->right;
  temp->right = node;
  fixHeight(node);
  fixHeight(temp);
  node = temp;
}

void BST::rotateLeft(Node*& node) {
  Node* temp = node->right;
  node->right = temp->left;
  temp->left = node;
  fixHeight(node);
  fixHeight(temp);
  node = temp;
}

void BST::balance(Node*& node) {
  fixHeight(node);
  if (bfactor(node) == 2) {
    if (bfactor(node->right) < 0) {
      rotateRight(node->right);
    }
    rotateLeft(node);
  } else if (bfactor(node) == -2) {
    if (bfactor(node->left) > 0) {
      rotateLeft(node->left);
    }
    rotateRight(node);
  }
}

void BST::insert(Node*& node, int key, QString value) {
  if (!node) {
    node = new Node(key, value);
    return;
  }
  if (key == node->key) {
    balance(node);
    return;
  }
  if (key < node->key) {
    insert(node->left, key, value);
  } else {
    insert(node->right, key, value);
  }
  balance(node);
}

Node* BST::findMin(Node* node) {
  return node->left ? findMin(node->left) : node;
}

void BST::remove(Node*& node, int k) {
  if (!node) {
    return;
  } else if (k < node->key) {
    remove(node->left, k);
    balance(node);
  } else if (k > node->key) {
    remove(node->right, k);
    balance(node);
  } else {
    Node* left = node->left;
    Node* right = node->right;
    delete node;
    if (!right) {
      node = left;
      return;
    }
    Node* min = findMin(right);
    min->right = removeMin(right);
    min->left = left;
    balance(min);
    node = min;
  }
}

Node* BST::select(Node* node, int key) {
  if (!node) {
    return nullptr;
  }
  if (!node->key) {
    return nullptr;
  }
  if (node->key == key) {
    return node;
  }
  if (key > node->key) {
    return select(node->right, key);
  }
  return select(node->left, key);
}

Node* BST::removeMin(Node* node) {
  if (node->left == 0) {
    return node->right;
  }
  node->left = removeMin(node->left);
  balance(node);
  return node;
}

//прямой обход дерева
QVector<QPair<int, QString>> BST::directTraversal(Node* node) {
  QVector<QPair<int, QString>> result;
  if (node == nullptr) {
    return result;
  }
  result.push_back(QPair<int, QString>(node->key, node->value));
  result.append(directTraversal(node->left));
  result.append(directTraversal(node->right));
  return result;
}

QVector<QPair<int, int>> BST::directTraversalTree(Node* node, Node* parent) {
  QVector<QPair<int, int>> result;
  if (node == nullptr) {
    return result;
  }
  if (node == root) {
    result.push_back(QPair<int, int>(-1, node->key));
  } else {
    result.push_back(QPair<int, int>(parent->key, node->key));
  }
  result.append(directTraversalTree(node->left, node));
  result.append(directTraversalTree(node->right, node));
  return result;
}

//обратный обход дерева
QVector<QPair<int, QString>> BST::reverceTraversal(Node* node) {
  QVector<QPair<int, QString>> result;
  if (node == nullptr) {
    return result;
  }
  result.append(reverceTraversal(node->left));
  result.append(reverceTraversal(node->right));
  result.push_back(QPair<int, QString>(node->key, node->value));
  return result;
}

QVector<QPair<int, QString>> BST::simmetricalTraversal(Node* node) {
  QVector<QPair<int, QString>> result;
  if (node == nullptr) {
    return result;
  }
  result.append(simmetricalTraversal(node->left));
  result.push_back(QPair<int, QString>(node->key, node->value));
  result.append(simmetricalTraversal(node->right));
  return result;
}

int BST::getNumberElementTwoChildren(Node* node) {
  int result = 0;
  if (node && node->left && node->right) {
    result++;
  }
  if (node && node->left) {
    result += getNumberElementTwoChildren(node->left);
  }
  if (node && node->right) {
    result += getNumberElementTwoChildren(node->right);
  }
  return result;
}
