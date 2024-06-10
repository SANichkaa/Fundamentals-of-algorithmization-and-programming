#include "bst.h"
#include <QPair>

BST::BST() {}
void BST::insert(int key, QString value) {
  insert(root, key, value);
}

void BST::insert(Node*& node, int key, QString value) {
  if (!node) {
    node = new Node(key, value);
  } else if (node->key == key) {
    qDebug() << "Incorrect input";
    return;
  } else if (node->key > key) {
    insert(node->left, key, value);
  } else {
    insert(node->right, key, value);
  }
}

void BST::remove(int key) {
  remove(root, key);
}

void BST::remove(Node*& node, int key) {
  if (!node) {
    qDebug() << "Incorrect input";
    return;
  } else if (node->key > key) {
    remove(node->left, key);
  } else if (node->key < key) {
    remove(node->right, key);
  } else {
    if (!node->left && !node->right) {
      delete node;
      node = nullptr;
    } else if (node->left && node->right) {
      Node* q = node->left;
      Node* r = node->right;
      delete node;
      if (!r) {
        node = q;
        return;
      }
      Node* min = findMin(r);
      min->right = deleteMin(r);
      min->left = q;
      node = min;
    } else if (node->left) {
      Node* ptr = node->left;
      delete node;
      node = ptr;
    } else {
      Node* ptr = node->right;
      delete node;
      node = ptr;
    }
  }
}

BST::Node* BST::findMin(Node* node) {
  return node->left ? findMin(node->left) : node;
}

BST::Node* BST::deleteMin(Node* node) {
  if (!node->left) {
    return node->right;
  }
  node->left = deleteMin(node->left);
  return node;
}

int BST::size() {
  return size(root);
}

int BST::size(Node* node) {
  int result = 0;
  if (node) {
    result++;
    result += size(node->left);
    result += size(node->right);
  }
  return result;
}

QString BST::select(int key) {
  return select(root, key);
}

BST::Node* BST::selectNode(Node* node, int key) {
  if (!node) {
    return nullptr;
  }
  if (node->key == key || (node->left && node->left->key == key) ||
      (node->right && node->right->key == key)) {
    return node;
  } else if (node->key > key) {
    return selectNode(node->left, key);
  } else {
    return selectNode(node->right, key);
  }
}

QString BST::select(Node* node, int key) {
  if (!node) {
    return "";
  }
  if (node->key == key) {
    return node->value;
  } else if (node->key > key) {
    return select(node->left, key);
  } else {
    return select(node->right, key);
  }
}

//прямой обход дерева
QVector<QPair<int, QString>> BST::directTraversal() {
  return directTraversal(root);
}

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

void BST::removeTree(BST* tree) {
  QVector<QPair<int, QString>> result = tree->directTraversal();
  for (QPair<int, QString> element : result) {
    remove(element.first);
  }
}

QVector<QPair<int, int>> BST::directTraversalTree(Node* node, Node* parent) {
  QVector<QPair<int, int>> result;
  if (!node) {
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

void BST::insertTree(BST* tree) {
  QVector<QPair<int, QString>> result = tree->directTraversal();
  for (QPair<int, QString> element : result) {
    insert(element.first, element.second);
  }
}

void BST::clear() {
  clear(root);
  qDebug() << "root = " << (root == nullptr);
}

void BST::clear(Node*& node) {
  if (node) {
    clear(node->left);
    clear(node->right);
    delete node;
    node = nullptr;
  }
}

void BST::removeBranch(int key) {
  Node* find = selectNode(root, key);
  if (find && find == root && key == root->key) {
    clear();
  } else if (find) {
    if (find->key == key) {
      clear(find);
    } else if (find->left && find->left->key == key) {
      clear(find->left);
    } else if (find->right && find->right->key == key) {
      clear(find->right);
    }
  }
}
