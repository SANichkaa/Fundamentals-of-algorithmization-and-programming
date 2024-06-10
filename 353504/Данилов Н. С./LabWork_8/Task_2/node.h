#ifndef NODE_H
#define NODE_H
#include <memory>
struct node
{
    int val;
    std::weak_ptr<node>parent;
    std::shared_ptr<node>left,right;

    node(int val)
    {
        this->val=val;
    }
};
#endif // NODE_H
