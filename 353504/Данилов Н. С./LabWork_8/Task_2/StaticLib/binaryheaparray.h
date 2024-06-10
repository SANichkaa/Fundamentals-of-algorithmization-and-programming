#ifndef BINARYHEAPARRAY_H
#define BINARYHEAPARRAY_H
#include <memory>
class BinaryHeapArray
{
    std::unique_ptr<int[]> heap;
    int capacity_=1,size_=0;
    void resize();
    void shiftUp(int);
    void shiftDown(int);
public:
    BinaryHeapArray();
    void insert(int key);
    std::pair<int,bool> extractMax();
    void clear();
    bool empty();
    int getSize() const;
    int getCapacity() const;
};

#endif // BINARYHEAPARRAY_H
