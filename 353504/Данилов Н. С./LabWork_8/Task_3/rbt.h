#ifndef RBT_H
#define RBT_H
#include<memory>
template<typename T, typename T1> class RBT
{
protected:

    struct node
    {
        node* left;
        node*right;
        node*parent;
        bool red;
        T key;
        T1 val;
        node(node*p,node*l,node*r,bool col,T k,T1 v): parent(p), left(l), right(r), red(col), key(std::move(k)), val(std::move(v)) {}
    };

public:
    RBT()
    {
        root = nullptr;
    }
    node* insert(T key, T1 val)
    {
        //qDebug()<<root<<"!";
        qDebug()<<val;
        if(root==nullptr)
        {
            root=new node(nullptr, nullptr, nullptr, false, key, val);
            qDebug()<<root->val<<"!";
            return root;
            //return;
        }
        return insert(key,val,root);
    }
    void remove(T key)
    {
        node * tmp=findNode(key);
        if(tmp==nullptr)
            return;

        if(tmp->left!=nullptr&&tmp->right!=nullptr)
        {
            node *r=tmp->right;
            while(r->left!=nullptr)
                r=r->left;

            tmp->key=std::move(r->key);
            tmp->val=std::move(r->val);
            tmp=r;
        }
        if (tmp->left == nullptr && tmp->right != nullptr) {
            tmp->right->red = true;
            replaceWith(tmp, tmp->right);
            delete tmp;
            return;
        }

        if (tmp->right == nullptr && tmp->left != nullptr) {
            tmp->left->red = true;
            replaceWith(tmp, tmp->left);
            delete tmp;
            return;
        }
        if(tmp==root)
        {
            delete root;
            root=nullptr;
            return;
        }
        if(tmp->red==false)
        {
            replaceWith(tmp, nullptr);
            delete tmp;
            tmp=nullptr;
            return;
        }

        node * d=tmp;
        if(tmp->left != nullptr||tmp->right != nullptr)
        {
            throw "Can`t remove";
        }

        while(tmp->parent!=nullptr)
        {
            node * p=tmp->parent;
            bool left=(p->left==tmp);
            node *s;
            if(left)
                s=p->right;
            else
                s=p->left;
            if(!s->red)
            {
                p->red=false;
                s->red=true;

                if(left)
                    RotateLeft(p);
                else
                    RotateRight(p);
            }

            p=tmp->parent;
            left=(p->left==tmp);
            if(left)
                s=p->right;
            else
                s=p->left;

            bool blackS=(s->red) &&(s->left == nullptr || s->left->red) &&(s->right == nullptr || s->right->red);
            if(p->red&&blackS)
            {
                s->red=false;
                tmp=tmp->parent;
                continue;
            }
            else
                if(!p->red)
            {
                s->red=false;
                p->red=true;
                break;
            }

            p=tmp->parent;
            left=(p->left==tmp);
            if(left)
                s=p->right;
            else
                s=p->left;

            if(s->red)
            {
                if(left&&(s->right == nullptr || s->right->red) &&(s->left && s->left->red == false))
                {
                    s->red=false;
                    s->left->red=true;
                    RotateRight(s);
                }
                else
                    if(!left&&(s->left == nullptr || s->left->red) &&(s->right && s->right->red == false))
                    {
                        s->red=false;
                        s->left->red=true;
                        RotateLeft(s);
                    }
            }


            p=tmp->parent;
            left=(p->left==tmp);
            if(left)
                s=p->right;
            else
                s=p->left;

            s->red=p->red;
            p->red=1;

            if(left)
            {
                if(s->right)
                    s->right->red=1;
                RotateLeft(p);

            }
else
            {
                if(s->left)
                    s->left->red=1;
                RotateRight(p);
            }

        }

        node *p=d->parent;
        if(p)
        {
            if(p->left==d)
                p->left=nullptr;
            else
                p->right=nullptr;
        }
        delete d;
    }

    bool contains(T key)
    {
        return findNode(key)!=nullptr;
    }
    void clear()
    {
        clear(root);
        root=nullptr;
    }

    size_t size()
    {
        return Size(root);
    }

    class Iterator {
    protected:
        friend class RBT<T, T1>;
        Iterator(node *root) : cur(root) {
            if(!cur) return;
            while (cur->left != nullptr)
                cur = cur->left;
        }

    public:
        node *operator->() { return cur; }

        node &operator*() { return *cur; }

        Iterator &operator++() {
            if (!cur)
                return *this;

            if (cur->right != nullptr) {
                cur = cur->right;

                while (cur->left != nullptr)
                    cur = cur->left;
            } else {
                while (cur->parent != nullptr && cur->parent->right == cur) {
                    cur = cur->parent;
                }
                cur = cur->parent;
            }


            return *this;
        }

        bool operator==(const Iterator &other) {
            return cur == other.cur;
        }

        bool operator!=(const Iterator &other) { return !(*this == other); }

    protected:
        node *cur;
    };

    Iterator begin() { return Iterator(root); }
    Iterator end() { return Iterator(nullptr); }

protected:

    node * findNode(T key)
    {
        node *cur = root;
        while (cur != nullptr) {
            if (key == cur->key)
                return cur;
            if (key < cur->key)
                cur = cur->left;
            else
                cur = cur->right;
        }

        return nullptr;
    }

    node * grandparent(node *v)//parent parent
    {
        node *p=v->parent;
        if(p&&p->parent)
            return p->parent;
        return nullptr;
    }
    node * uncle(node *v)//sibling of parent
    {
        node *g=grandparent(v);
        if(g==nullptr)
            return g;
        if(v->parent==g->left)
            return g->right;
        return g->left;
    }
    node * sibling(node *v)
    {
        if(v->parent->left==v)
            return v->parent->right;
        return v->parent->left;
    }

    void RotateLeft(node *v)
    {
        node * r=v->right;
        r->parent=v->parent;
        if(v->parent!=nullptr)
        {
            if(v->parent->left==v)
            {
                v->parent->left=r;
            }
            else
                v->parent->right=r;
        }

        v->right=r->left;

        if(r->left!=nullptr)
            r->left->parent=v;

        v->parent=r;
        r->left=v;
    }
    void RotateRight(node *v)
    {
        struct node *left = v->left;

        left->parent = v->parent;
        if (v->parent != nullptr) {
            if (v->parent->left=v)
                v->parent->left = left;
            else
                v->parent->right = left;
        }

        v->left = left->right;
        if (left->right != nullptr)
            left->right->parent = v;

        v->parent = left;
        left->right = v;
    }

    node *insert(T key,T1 value,node *v)
    {
        qDebug()<<value;
        if(key==v->key)
            return v;
        if(key<v->key)
        {
            if(v->left==nullptr)
            {
                v->left=new node(v,nullptr,nullptr,true,key,value);
                InsCase1(v->left);
                return v->left;
            }
            else return insert(key,value,v->left);
        }
        else
        {
            if (v->right) return insert(key, value, v->right);
            else {
                v->right = new node(v, nullptr, nullptr, true, key, value);
                InsCase1(v->right);
                return v->right;
        }
        }
    }
    void InsCase1(node *v)
    {
        if(v->parent==nullptr)//root
            v->red=false;
        else
            InsCase2(v);
    }
    void InsCase2(node *v)
    {
        if(v->parent->red==false)
        {
            return;
        }
        InsCase3(v);
    }
    void InsCase3(node *v)
    {
        node *u=uncle(v);

        if(u&&u->red)
        {
            v->parent->red=u->red=false;
            node *g=grandparent(v);
            g->red=true;
            InsCase1(g);
        }
        else
            InsCase4(v);
    }
    void InsCase4(node *v)
    {
        node *g=grandparent(v);
        if(v==v->parent->right&&v->parent==g->left)
        {
            RotateLeft(v->parent);
            v=v->left;
        }
        else if(v==v->parent->left&&v->parent==g->right)
        {
            RotateRight(v->parent);
            v=v->right;
        }
        InsCase5(v);
    }
    void InsCase5(node *v)
    {
        node * g = grandparent(v);
        node * p = v->parent;
        p->red = false;
        g->red = true;

        if (v==p->left) {
            RotateRight(g);
        } else {
            RotateLeft(g);
        }
    }

    void replaceWith(node *from, node *to) {
        node *parent = from->parent;

        if (to) {
            to->parent = parent;
        }

        if (parent == nullptr) {
            root = to;
        } else {
            if (parent->left == from) {
                parent->left = to;
            } else {
                parent->right = to;
            }
        }
    }

    void clear(node *v)
    {
        if(v==nullptr)
            return;
        clear(v->left);
        clear(v->right);
        delete v;
        v=nullptr;
    }


    int Size(node* n) {
        if (n == nullptr) return 0;
        return 1 + Size(n->left) + Size(n->right);
    }
    //Field
    node *root=nullptr;
};

template <typename T, typename T1> class Map: public RBT<T, T1> {
    using RBT = RBT<T, T1>;
public:
    T1& operator[](const T& key) {
        auto t = RBT::findNode(key);
        if(t != nullptr) {
            return t->val;
        }
        return RBT::insert(key, T1())->val;
    }

    const T1 operator[](const T& key) const {
        return *this[key];
    }
};

template <typename T> class Set: public RBT<T, bool> {
    using RBT = RBT<T, bool>;
public:
    void insert(T&& val) {
        RBT::insert(val, false);
    }
};
#endif // RBT_H
