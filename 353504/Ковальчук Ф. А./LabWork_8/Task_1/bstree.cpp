#include "bstree.h"

template<typename T>
void BSTree<T>::add(long key, const T &val) {
    root = addRec(root, key, val);
}

template<typename T>
bool BSTree<T>::find(long key) {
    return findRec(root, key);
}

template<typename T>
void BSTree<T>::remove(long key) {
    root = removeRec(root, key);
}

template<typename T>
QVector<long> BSTree<T>::inOrderTraverse() {
    QVector<long> keys;
    inOrderTraverseRec(root, keys);
    return keys;
}

template<typename T>
QVector<long> BSTree<T>::preOrderTraverse() {
    QVector<long> keys;
    preOrderTraverseRec(root, keys);
    return keys;
}

template<typename T>
QVector<long> BSTree<T>::postOrderTraverse() {
    QVector<long> keys;
    postOrderTraverseRec(root, keys);
    return keys;
}

template<typename T>
void BSTree<T>::insertSubtree(Node<T> *subtreeRoot) {
    if (subtreeRoot == nullptr) {
        return;
    }
    insertSubtreeRec(subtreeRoot);
}

template<typename T>
void BSTree<T>::removeSubtree(Node<T> *subtreeRoot) {
    if (subtreeRoot == nullptr) {
        return;
    }
    removeSubtreeRec(subtreeRoot);
}

template<typename T>
Node<T>* BSTree<T>::findLowestCommonAncestor(long key1, long key2) {
    return findLowestCommonAncestorRec(root, key1, key2);
}

template<typename T>
Node<T>* BSTree<T>::getRoot() {
    return root;
}

template<typename T>
Node<T>* BSTree<T>::addRec(Node<T> *node, long key, const T &val) {
    if (node == nullptr) {
        return new Node<T>(key, val);
    }

    if (key < node->key) {
        node->left = addRec(node->left, key, val);
    } else if (key > node->key) {
        node->right = addRec(node->right, key, val);
    }

    return node;
    }

template<typename T>
    bool BSTree<T>::findRec(Node<T> *node, long key) {
    if (node == nullptr)
        return false;

    if (key == node->key)
        return true;
    else if (key < node->key)
        return findRec(node->left, key);
    else
        return findRec(node->right, key);
}

template<typename T>
Node<T>* BSTree<T>::removeRec(Node<T> *node, long key) {
    if (node == nullptr)
        return nullptr;

    if (key < node->key) {
        node->left = removeRec(node->left, key);
    } else if (key > node->key) {
        node->right = removeRec(node->right, key);
    } else {
        if (node->left == nullptr) {
            Node<T> *temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node<T> *temp = node->left;
            delete node;
            return temp;
        }

        Node<T> *temp = findMin(node->right);
        node->key = temp->key;
        node->data = temp->data;
        node->right = removeRec(node->right, temp->key);
    }

    return node;
}

template<typename T>
Node<T>* BSTree<T>::findMin(Node<T> *node) {
    while (node->left != nullptr)
        node = node->left;

    return node;
}

template<typename T>
void BSTree<T>::inOrderTraverseRec(Node<T> *node, QVector<long> &keys) {
    if (node != nullptr) {
        inOrderTraverseRec(node->left, keys);
        keys.push_back(node->key);
        inOrderTraverseRec(node->right, keys);
    }
}

template<typename T>
void BSTree<T>::preOrderTraverseRec(Node<T> *node, QVector<long> &keys) {
    if (node != nullptr) {
        keys.append(node->key);
        preOrderTraverseRec(node->left, keys);
        preOrderTraverseRec(node->right, keys);
    }
}

template<typename T>
void BSTree<T>::postOrderTraverseRec(Node<T> *node, QVector<long> &keys) {
    if (node != nullptr) {
        postOrderTraverseRec(node->left, keys);
        postOrderTraverseRec(node->right, keys);
        keys.append(node->key);
    }
}

template<typename T>
void BSTree<T>::removeSubtreeRec(Node<T> *subtreeRoot) {
    remove(subtreeRoot->key);
    if (subtreeRoot->right)
        removeSubtreeRec(subtreeRoot->right);
    if (subtreeRoot->left)
        removeSubtreeRec(subtreeRoot->left);
}

template<typename T>
void BSTree<T>::insertSubtreeRec(Node<T> *subtreeRoot) {
    add(subtreeRoot->key, subtreeRoot->data);
    if (subtreeRoot->right)
        insertSubtreeRec(subtreeRoot->right);
    if (subtreeRoot->left)
        insertSubtreeRec(subtreeRoot->left);
}

template<typename T>
Node<T>* BSTree<T>::findLowestCommonAncestorRec(Node<T> *node, long key1, long key2) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->key > key1 && node->key > key2) {
        return findLowestCommonAncestorRec(node->left, key1, key2);
    }

    if (node->key < key1 && node->key < key2) {
        return findLowestCommonAncestorRec(node->right, key1, key2);
    }

    return node;
}

template class BSTree<QString>;

