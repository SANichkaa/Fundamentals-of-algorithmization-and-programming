#ifndef BSTREE_H
#define BSTREE_H

#include <QVector>
#include "node.h"

template <typename T>
class BSTree {
public:
    BSTree() : root(nullptr) {}

    void add(long key, const T &val);
    bool find(long key);
    void remove(long key);

    QVector<long> inOrderTraverse();
    QVector<long> preOrderTraverse();
    QVector<long> postOrderTraverse();

    void insertSubtree(Node<T> *subtreeRoot);
    void removeSubtree(Node<T> *subtreeRoot);

    Node<T>* findLowestCommonAncestor(long key1, long key2);

    Node<T>* getRoot();

private:
    Node<T> *root;

    Node<T>* addRec(Node<T> *node, long key, const T &val);
    bool findRec(Node<T> *node, long key);
    Node<T>* removeRec(Node<T> *node, long key);

    Node<T>* findMin(Node<T> *node);

    void inOrderTraverseRec(Node<T> *node, QVector<long> &keys);
    void preOrderTraverseRec(Node<T> *node, QVector<long> &keys);
    void postOrderTraverseRec(Node<T> *node, QVector<long> &keys);

    void removeSubtreeRec(Node<T> *subtreeRoot);
    void insertSubtreeRec(Node<T> *subtreeRoot);

    Node<T>* findLowestCommonAncestorRec(Node<T> *node, long key1, long key2);
};

#endif // BSTREE_H
