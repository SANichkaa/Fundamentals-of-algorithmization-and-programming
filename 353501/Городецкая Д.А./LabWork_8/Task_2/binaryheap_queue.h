#ifndef BINARYHEAP_QUEUE_H
#define BINARYHEAP_QUEUE_H

#include <memory>

template<typename T>
class binaryheap_queue
{
private:
    struct Node
    {
        T value;
        std::weak_ptr<Node> parent;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        explicit Node(int64_t value)
            : value(value)
        {}
    };

    std::shared_ptr<Node> _root;
    size_t _size;

private:
    void sift_up(std::shared_ptr<Node> node);
    void sift_down(std::shared_ptr<Node> node);
    std::shared_ptr<Node> getLastNode();
    void removeLastNode();

public:
    binaryheap_queue();
    ~binaryheap_queue();

    void clear();
    void push(T value);
    T pop();
    T &max();
    size_t size();
    bool empty();
};

#endif // BINARYHEAP_QUEUE_H
