#include "binaryheaparray.h"

int BinaryHeapArray::getSize() const
{
    return size_;
}

int BinaryHeapArray::getCapacity() const
{
    return capacity_;
}

void BinaryHeapArray::resize()
{
    if(size_+1>=capacity_)
    {
        capacity_<<=1;
        auto newHeap = std::make_unique<int[]>(capacity_);

        for (int i = 0; i <= size_; i++) {
            newHeap[i] = heap[i];
        }

        heap = std::move(newHeap);
    }
}

void BinaryHeapArray::shiftUp(int index)//Throw up. If our vert < father
{
    while (heap[index] > heap[(index - 1) / 2]) {
        std::swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void BinaryHeapArray::shiftDown(int i)
{
    int left,right,j;
    while (2 * i + 1 < size_)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        j = left;
        if (right < size_ && heap[right]> heap[left])
            j = right;
        if (heap[i] >= heap[j])
            break;
        std::swap(heap[i], heap[j]);
        i = j;
    }
}

BinaryHeapArray::BinaryHeapArray()
{
    heap=std::make_unique<int[]>(1);
    capacity_=1;
    size_=0;
}


void BinaryHeapArray::insert(int key)
{
    resize();
    heap[size_++]=key;
    shiftUp(size_-1);
}

std::pair<int,bool> BinaryHeapArray::extractMax()
{
    if (size_ == 0) return {0,false};
    int max = heap[0];
    heap[0] = heap[size_ - 1];
    size_--;
    shiftDown(0);
    return {max,1};
}

void BinaryHeapArray::clear()
{
    size_=0;
}

bool BinaryHeapArray::empty()
{
    return size_==0;
}

