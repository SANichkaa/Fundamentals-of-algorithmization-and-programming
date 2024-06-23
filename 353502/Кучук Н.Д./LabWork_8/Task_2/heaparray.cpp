#include "heaparray.h"

void HeapArray::insert(int value) {
    data.push_back(value);
    heapifyUp(data.size() - 1);
}

int HeapArray::extractMax() {
    if (isEmpty()) {
        //throw std::runtime_error("Heap is empty");
    }
    int maxValue = data[0];
    data[0] = data.back();
    data.pop_back();
    heapifyDown(0);
    return maxValue;
}

bool HeapArray::isEmpty() const {
    return data.empty();
}

void HeapArray::heapifyUp(int index) {
    while (index > 0 && data[index] > data[(index - 1) / 2]) {
        std::swap(data[index], data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void HeapArray::heapifyDown(int index) {
    int size = data.size();
    while (2 * index + 1 < size) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        if (leftChild < size && data[leftChild] > data[largest]) {
            largest = leftChild;
        }
        if (rightChild < size && data[rightChild] > data[largest]) {
            largest = rightChild;
        }
        if (largest == index) break;
        std::swap(data[index], data[largest]);
        index = largest;
    }
}
