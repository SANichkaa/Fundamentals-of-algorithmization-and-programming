#include "binaryheaplist.h"

std::shared_ptr<node> BinaryHeapList::get_free_node()
{
    std::queue<std::shared_ptr<node>> q;
    q.push(root);//Root != nullptr
    while (!q.empty())
    {
        auto v = q.front();
        q.pop();
        if (v->left == nullptr || v->right== nullptr)//Free node
            return v;

        q.push(v->left);
        q.push(v->right);
    }
    return nullptr;
}

void BinaryHeapList::shiftUp(std::shared_ptr<node> v)
{
    while (auto parent = v->parent.lock())
    {
        if (v->val <= parent->val) //All sorted
            return;
        std::swap(v->val, parent->val);
        v = parent;
    }
}

void BinaryHeapList::shiftDown(std::shared_ptr<node> v)
{
    while (v->left!=nullptr)
    {
        auto left=v->left;
        auto right=v->right;
        auto j=left;
        if(right&&right->val>left->val)
            j=right;
        if(v->val>=j->val)//all sorted
            return;
        std::swap(v->val,j->val);
        v=j;
    }
}

void BinaryHeapList::insert(int key)
{
    if(root==nullptr)
    {
        root=std::make_shared<node>(key);
        return;
    }
    auto v=get_free_node();
    //Create new node
    auto cur=std::make_shared<node>(key);
    cur->parent=v;
    if(v->left==nullptr)
        v->left=cur;
    else
        v->right=cur;

    shiftUp(cur);
}

std::shared_ptr<node> BinaryHeapList::get_last()
{
    std::queue<std::shared_ptr<node>> q;
    q.push(root);
    std::shared_ptr<node> last = nullptr;
    while (!q.empty()) {
        last = q.front();
        q.pop();
        if (last->left != nullptr) q.push(last->left);
        if (last->right != nullptr) q.push(last->right);
    }
    return last;
}

std::pair<int,bool> BinaryHeapList::get_max()
{
    if (root == nullptr) return {0,false};
    int max = root->val;
    if (root->left== nullptr && root->right== nullptr) {
        root = nullptr;
        return {max,1};
    }
    auto last= get_last();
    root->val = last->val;
    if (auto parent = last->parent.lock())//weak->shared
    {
        if (parent->right == last) {
            parent->right = nullptr;
        } else {
            parent->left = nullptr;
        }
    }
    shiftDown(root);
    return {max,1};
}

void BinaryHeapList::clear()
{
    cl(root);
}

void BinaryHeapList::cl(std::shared_ptr<node>& v)
{
    if(v==nullptr)
        return;
    cl(v->left);
    cl(v->right);
    v=v->left=v->right=nullptr;
}

bool BinaryHeapList::empty()
{
    return root == nullptr;
}
