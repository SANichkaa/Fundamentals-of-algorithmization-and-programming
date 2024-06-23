#ifndef HEAP_LIST_H
#define HEAP_LIST_H

#include <memory>
#include <vector>

class HeapList {
public:
    void insert(int value);
    int extractMax();
    bool isEmpty() const;

private:
    struct Node {
        int value;
        std::weak_ptr<Node> parent;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        Node(int val) : value(val) {}
    };

    std::shared_ptr<Node> root;
    void heapifyUp(std::shared_ptr<Node> node);
    void heapifyDown(std::shared_ptr<Node> node);
    std::shared_ptr<Node> getLastNode() const;
    void removeLastNode();
};

#endif // HEAP_LIST_H
