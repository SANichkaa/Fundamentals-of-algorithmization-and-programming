#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    Node(long key, const T &val) : key(key), data(val), left(nullptr), right(nullptr) {}
    Node* left;
    Node* right;
    long long key;
    T data;
};

#endif // NODE_H
