#include "heaplist.h"
#include <queue>
#include <stdexcept>

void HeapList::insert(int value) {
    auto newNode = std::make_shared<Node>(value);
    if (!root) {
        root = newNode;
    } else {
        std::queue<std::shared_ptr<Node>> q;
        q.push(root);
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            if (!current->left) {
                current->left = newNode;
                newNode->parent = current;
                break;
            } else if (!current->right) {
                current->right = newNode;
                newNode->parent = current;
                break;
            } else {
                q.push(current->left);
                q.push(current->right);
            }
        }
    }
    heapifyUp(newNode);
}

int HeapList::extractMax() {
    if (isEmpty()) {
        throw std::runtime_error("Heap is empty");
    }
    int maxValue = root->value;
    auto lastNode = getLastNode();
    if (lastNode == root) {
        root.reset();
    } else {
        root->value = lastNode->value;
        removeLastNode();
        heapifyDown(root);
    }
    return maxValue;
}

bool HeapList::isEmpty() const {
    return !root;
}

void HeapList::heapifyUp(std::shared_ptr<Node> node) {
    while (node->parent.lock() && node->value > node->parent.lock()->value) {
        std::swap(node->value, node->parent.lock()->value);
        node = node->parent.lock();
    }
}

void HeapList::heapifyDown(std::shared_ptr<Node> node) {
    while (node->left) {
        auto largest = node->left;
        if (node->right && node->right->value > node->left->value) {
            largest = node->right;
        }
        if (node->value > largest->value) break;
        std::swap(node->value, largest->value);
        node = largest;
    }
}

std::shared_ptr<HeapList::Node> HeapList::getLastNode() const {
    if (!root) return nullptr;
    std::queue<std::shared_ptr<Node>> q;
    q.push(root);
    std::shared_ptr<Node> last;
    while (!q.empty()) {
        last = q.front();
        q.pop();
        if (last->left) q.push(last->left);
        if (last->right) q.push(last->right);
    }
    return last;
}

void HeapList::removeLastNode() {
    if (!root) return;
    std::queue<std::shared_ptr<Node>> q;
    q.push(root);
    std::shared_ptr<Node> last, parent;
    while (!q.empty()) {
        parent = q.front();
        q.pop();
        if (parent->left) q.push(parent->left);
        if (parent->right) q.push(parent->right);
        last = parent;
    }
    if (last == parent->left) {
        parent->left.reset();
    } else {
        parent->right.reset();
    }
}
