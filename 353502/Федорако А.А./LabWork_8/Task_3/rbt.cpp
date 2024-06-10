#include <exception>

#include "rbt.h"

Color RBT::getColor(Node* node) {
  if (node == nullptr) {
    return Color::Black;
  }
  return node->color;
}

void RBT::setColor(Node*& node, Color color) {
  if (node == nullptr) {
    return;
  }
  node->color = color;
}

void RBT::insert(int key, QString value) {
  Node* node = new Node;
  node->key = key;
  node->value = value;
  root = insertNode(root, node);
  fixInsertRBT(root, node);
}

Node* RBT::insertNode(Node*& root, Node*& node) {
  if (root == nullptr) {
    return node;
  }

  if (node->key == root->key) {
    return node;
  }
  if (node->key < root->key) {
    root->left = insertNode(root->left, node);
    root->left->parent = root;
  } else {
    root->right = insertNode(root->right, node);
    root->right->parent = root;
  }

  return root;
}

void RBT::rotateLeft(Node*& root, Node*& node) {
  Node* rightChild = node->right;
  node->right = rightChild->left;

  if (node->right != nullptr) {
    node->right->parent = node;
  }

  rightChild->parent = node->parent;

  if (node->parent == nullptr) {
    root = rightChild;
  } else if (node == node->parent->left) {
    node->parent->left = rightChild;
  } else {
    node->parent->right = rightChild;
  }

  rightChild->left = node;
  node->parent = rightChild;
}

void RBT::rotateRight(Node*& root, Node*& node) {
  Node* leftChild = node->left;
  node->left = leftChild->right;

  if (node->left != nullptr) {
    node->left->parent = node;
  }

  leftChild->parent = node->parent;

  if (node->parent == nullptr) {
    root = leftChild;
  } else if (node == node->parent->left) {
    node->parent->left = leftChild;
  } else {
    node->parent->right = leftChild;
  }

  leftChild->right = node;
  node->parent = leftChild;
}

void RBT::fixInsertRBT(Node*& root, Node*& node) {
  Node* parent = nullptr;
  Node* grandparent = nullptr;
  while (node != root && getColor(node) == Color::Red &&
         getColor(node->parent) == Color::Red) {
    parent = node->parent;
    grandparent = parent->parent;
    if (parent == grandparent->left) {
      Node* uncle = grandparent->right;
      if (getColor(uncle) == Color::Red) {
        setColor(uncle, Color::Black);
        setColor(parent, Color::Black);
        setColor(grandparent, Color::Red);
        node = grandparent;
      } else {
        if (node == parent->right) {
          rotateLeft(root, parent);
          node = parent;
          parent = node->parent;
        }
        rotateRight(root, grandparent);
        Color color = grandparent->color;
        grandparent->color = parent->color;
        parent->color = color;
        node = parent;
      }
    } else {
      Node* uncle = grandparent->left;
      if (getColor(uncle) == Color::Red) {
        setColor(uncle, Color::Black);
        setColor(parent, Color::Black);
        setColor(grandparent, Color::Red);
        node = grandparent;
      } else {
        if (node == parent->left) {
          rotateRight(root, parent);
          node = parent;
          parent = node->parent;
        }
        rotateLeft(root, grandparent);
        Color color = grandparent->color;
        grandparent->color = parent->color;
        parent->color = color;
        node = parent;
      }
    }
  }
  setColor(root, Color::Black);
}

int RBT::deleteCase1(Node*& root, Node*& node) {
  if (node == nullptr) {
    return 1;
  }

  if (node == root) {
    if (node->left == nullptr && node->right == nullptr) {
      delete root;
      root = nullptr;
      return 1;
    }
    Node* current = root;
    root = root->left != nullptr ? root->left : root->right;
    setColor(root, Color::Black);
    root->parent = nullptr;
    delete current;
    return 1;
  }

  return 0;
}

int RBT::deleteCase2(Node*& root, Node*& node) {
  Node* child = node->left != nullptr ? node->left : node->right;

  if (node == node->parent->left) {
    node->parent->left = child;
    if (child != nullptr) {
      child->parent = node->parent;
    }
    setColor(child, Color::Black);
    delete node;
  } else if (node == node->parent->right) {
    node->parent->right = child;
    if (child != nullptr) {
      child->parent = node->parent;
    }
    setColor(child, Color::Black);
    delete node;
  }
}

int RBT::deleteCase3(Node*& root, Node*& sibling, Node*& parent,
                     Node*& pointer) {
  sibling = parent->right;
  if (getColor(sibling) == Color::Red) {
    setColor(sibling, Color::Black);
    setColor(parent, Color::Red);
    rotateLeft(root, parent);
  } else if (getColor(sibling) != Color::Red) {
    if (getColor(sibling->left) == Color::Black &&
        getColor(sibling->right) == Color::Black) {
      setColor(sibling, Color::Red);
      if (getColor(parent) == Color::Red) {
        setColor(parent, Color::Black);
      } else if (getColor(parent) != Color::Red) {
        setColor(parent, Color::Black);
      }
      pointer = parent;
    } else if (getColor(sibling->left) != Color::Black ||
               getColor(sibling->right) != Color::Black) {
      if (getColor(sibling->right) == Color::Black) {
        setColor(sibling->left, Color::Black);
        setColor(sibling, Color::Red);
        rotateRight(root, sibling);
        sibling = parent->right;
      }
      setColor(sibling, parent->color);
      setColor(parent, Color::Black);
      setColor(sibling->right, Color::Black);
      rotateLeft(root, parent);
      //break;
      return 1;
    }
  }
  return 0;
}

int RBT::deleteCase4(Node*& root, Node*& sibling, Node*& parent,
                     Node*& pointer) {
  sibling = parent->left;
  if (getColor(sibling) == Color::Red) {
    setColor(sibling, Color::Black);
    setColor(parent, Color::Red);
    rotateRight(root, parent);
  } else if (getColor(sibling) == Color::Black) {
    if (getColor(sibling->left) == Color::Black &&
        getColor(sibling->right) == Color::Black) {
      setColor(sibling, Color::Red);
      if (getColor(parent) == Color::Red) {
        setColor(parent, Color::Black);
      } else if (getColor(parent) == Color::Black) {
        setColor(parent, Color::Black);
      }
      pointer = parent;
    } else if (getColor(sibling->left) != Color::Black ||
               getColor(sibling->right) != Color::Black) {
      if (getColor(sibling->left) == Color::Black) {
        setColor(sibling->right, Color::Black);
        setColor(sibling, Color::Red);
        rotateLeft(root, sibling);
        sibling = parent->left;
      }
      setColor(sibling, parent->color);
      setColor(parent, Color::Black);
      setColor(sibling->left, Color::Black);
      rotateRight(root, parent);
      return 1;
    }
  }
  return 0;
}

void RBT::fixDeleteRBT(Node*& root, Node*& node) {
  //node == root || node == nullptr.
  if (deleteCase1(root, node) == 1) {
    return;
  }

  if (getColor(node) == Color::Red || getColor(node->left) == Color::Red ||
      getColor(node->right) == Color::Red) {
    deleteCase2(root, node);
  } else if (getColor(node) != Color::Red &&
             getColor(node->left) != Color::Red &&
             getColor(node->right) != Color::Red) {
    Node* sibling = nullptr;
    Node* parent = nullptr;
    Node* pointer = node;
    setColor(pointer, Color::Black);
    while (pointer != root && getColor(pointer) == Color::Black) {
      parent = pointer->parent;
      if (pointer == parent->left) {
        if (deleteCase3(root, sibling, parent, pointer) == 1) {
          break;
        }

      } else if (pointer != parent->left) {
        if (deleteCase4(root, sibling, parent, pointer) == 1) {
          break;
        }
      }
    }

    if (node == node->parent->left) {
      node->parent->left = nullptr;
    } else if (node == node->parent->right) {
      node->parent->right = nullptr;
    }
    delete node;
    setColor(root, Color::Black);
  }
}

void RBT::clear() {
  clear(root);
}
Node* RBT::deleteNode(Node*& root, int key) {
  if (root == nullptr) {
    return root;
  }

  if (key < root->key) {
    return deleteNode(root->left, key);
  }

  if (key > root->key) {
    return deleteNode(root->right, key);
  }

  if (root->left == nullptr || root->right == nullptr) {
    return root;
  }

  Node* temp = min(root->right);
  root->key = temp->key;
  return deleteNode(root->right, temp->key);
}

void RBT::remove(int key) {
  Node* node = deleteNode(root, key);
  fixDeleteRBT(root, node);
}

Node* RBT::min() {
  return min(root);
}

Node* RBT::min(Node*& node) {
  Node* pointer = node;

  while (pointer->left != nullptr) {
    pointer = pointer->left;
  }

  return pointer;
}

Node* RBT::find(Node* node, int key) {
  if (node == nullptr) {
    return nullptr;
  }

  if (node->key == key) {
    return node;
  }

  if (node->key > key) {
    return find(node->left, key);
  }

  return find(node->right, key);
}

Node* RBT::find(int key) {
  return find(root, key);
}

void RBT::clear(Node*& node) {
  if (node == nullptr) {
    return;
  }

  clear(node->left);
  clear(node->right);

  delete node;
  node = nullptr;
}

QVector<int> RBT::directTraversal(Node* node) {
  QVector<int> result;
  if (node == nullptr) {
    return result;
  }
  result.push_back(node->key);
  result.append(directTraversal(node->left));
  result.append(directTraversal(node->right));
  return result;
}

QVector<QPair<Color, QPair<int, int>>> RBT::directTraversalTree(Node* node,
                                                                Node* parent) {
  QVector<QPair<Color, QPair<int, int>>> result;
  if (node == nullptr) {
    return result;
  }
  if (node == root) {
    result.push_back(QPair<Color, QPair<int, int>>(
        node->color, QPair<int, int>(-1, node->key)));
  } else {
    result.push_back(QPair<Color, QPair<int, int>>(
        node->color, QPair<int, int>(parent->key, node->key)));
  }
  result.append(directTraversalTree(node->left, node));
  result.append(directTraversalTree(node->right, node));
  return result;
}
