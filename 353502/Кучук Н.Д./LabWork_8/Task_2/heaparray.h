#ifndef HEAP_ARRAY_H
#define HEAP_ARRAY_H

#include <vector>

class HeapArray {
public:
    void insert(int value);
    int extractMax();
    bool isEmpty() const;

private:
    std::vector<int> data;
    void heapifyUp(int index);
    void heapifyDown(int index);
};

#endif // HEAP_ARRAY_H
