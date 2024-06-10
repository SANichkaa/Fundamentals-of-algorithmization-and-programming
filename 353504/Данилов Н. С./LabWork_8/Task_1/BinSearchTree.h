#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H
#include <QString>
#include <QVector>
#include "node.h"
#include<QMessageBox>
class bst{
    //fields
    node * root=nullptr;

    //methods
    node * find_(node *v,int key)
    {
        if(v==nullptr)
        {
            return nullptr;
        }

        if(v->key==key)
        {
            return v;
        }

        if(v->key>key)
        {
            return find_(v->left,key);
        }
        return find_(v->right,key);
    }

    void add(node *&v,int key, QString str)
    {
        if(v==nullptr)
        {
            v=new node(key,str);
            // if(root==nullptr)
            //     root=v;
            return;
        }

        if(v->key>=key)
        {
            add(v->left,key,str);
            return;
        }
        add(v->right,key,str);
    }

    void del(node *&v, node * pred, bool left, int key)
    {
        if(v==nullptr)
            return;

        if(v->key==key)
        {
            //Leave
            if(v->left==v->right&&v->left==nullptr)
            {
                delete v;

                if(pred==nullptr)
                {
                    root=nullptr;
                    return;
                }

                if(left)
                {
                    pred->left=nullptr;
                }
                else
                    pred->right=nullptr;

                return;
            }

            //No left subtree
            if(v->left==nullptr)
            {
                //Delete v -> exist only right subtree
                if(pred==nullptr)// root
                {
                    root=v->right;
                }
                else
                if(left)
                {
                    pred->left=v->right;
                }
                else
                    pred->right=v->right;

                delete v;
                return;
            }
            //No right subtree
            if(v->right==nullptr)
            {
                //Delete v -> exist only left subtree
                if(pred==nullptr)// root
                {
                    root=v->left;
                }
                else
                    if(left)
                    {
                        pred->left=v->left;
                    }
                    else
                        pred->right=v->left;

                delete v;
                return;
            }

            //Move leave
            node *leave=v->right;
            while(leave->left!=nullptr)
                leave=leave->left;

            v->key=leave->key;
            v->str=leave->str;
            del(v,v->right,false,leave->key);//old version delete
            return;
        }


        if(v->key<=key)
            del(v->left,v,true,key);
        else
            del(v->right,v,false,key);
    }

    int height(node *&v)
    {
        if(v==nullptr)
            return 0;
        return std::max(height(v->left),height(v->right))+1;
    }

    void bal(node *&v)
    {
        if(v==nullptr)return;
        qDebug()<<v;
        qDebug()<<height(v->left)<<" "<<height(v->right);
        int delta=height(v->left)-height(v->right);
        if(delta>=2)
        {
            if(height(v->left->left)>=height(v->left->right))//Just R
                RRotate(v);
            else //LR
            {
                LRotate(v->left);
                RRotate(v);

            }

        }else
        if(delta<=-2)
        {
            if(height(v->right->right)>=height(v->right->left))//Just R
                LRotate(v);
            else //LR
            {
                RRotate(v->right);
                LRotate(v);

            }

        }
        bal(v->left);
        bal(v->right);
    }

    void RRotate(node*&v)
    {
        node *tmp=v->left;
        v->left=tmp->right;
        tmp->right=v;
        v=tmp;
    }

    void LRotate(node*&v)
    {
        node *tmp=v->right;
        v->right=tmp->left;
        tmp->left=v;
        v=tmp;
    }

    void delTree(node *&v )
    {
        if(v==nullptr)return;

        delTree(v->left);
        v->left=nullptr;
        delTree(v->right);
        v->right=nullptr;
        if(root==v)
        {
        delete v;
        root=nullptr;
        }
        else delete v;
        v=nullptr;
    }

    void del_parent(int key,node *&v)
    {
        if(v==nullptr)
        {
            return;
        }
        if(v->left!=nullptr&&v->left->key==key)
        {
            v->left=nullptr;
            return;
        }
        if(v->right!=nullptr&&v->right->key==key)
        {
            v->right=nullptr;
            return;
        }

        if(v->key<key)
        {
            del_parent(key,v->left);
        }else
        del_parent(key,v->right);
    }
    void prefOrder(node * &v, QString& way)
    {
        if(v==nullptr)return;
        way+=QString::fromStdString("{"+std::to_string(v->key))+", "+v->str+"}\n";
        prefOrder(v->left,way);
        prefOrder(v->right,way);
    }

    void infOrder(node *& v, QString& way)
    {
        if(v==nullptr)return;

        infOrder(v->left,way);
        way+=QString::fromStdString("{"+std::to_string(v->key))+", "+v->str+"}\n";
        infOrder(v->right,way);
    }

    void postfOrder(node *& v, QString& way)
    {
        if(v==nullptr)return;

        postfOrder(v->left,way);

        postfOrder(v->right,way);
        way+=QString::fromStdString("{"+std::to_string(v->key))+", "+v->str+"}\n";
    }

    node* lca(node *&v,int key1,int key2) //common vertical for 2 keys
    {

        if(v==nullptr) return nullptr;
        qDebug()<<"*"<<v<<" "<<v->key;
        if(v->key>key1&&v->key>key2)
            return lca(v->left,key1,key2);
        if(v->key<key1&&v->key<key2)
            return lca(v->right,key1,key2);
        return v;
    }
public:
    bst(){}

    void fill(QVector<std::pair<int,QString>>data)
    {
        for(auto& i:data)
            add(root,i.first,i.second);
        bal(root);
    }

    void insert(int key, QString str)
    {
        add(root, key, str);
        //balance();
    }

    void clear()
    {
        delTree(root);
    }

    void remove(int key)
    {
        del(root,nullptr,false,key);
        //balance();
    }

    std::pair<QString,bool> find(int key)
    {
        node *v=find_(root,key);
        if(v==nullptr)
        {
            return {"Not found",false};
        }
        return {v->str,true};
    }

    QString traverse(int type)
    {
        QString res;
        switch(type)
        {
        case -1:
            prefOrder(root,res);
            break;
        case 0:
            infOrder(root,res);
            break;
        case 1:
            postfOrder(root,res);
            break;
        }
        return res;
    }

    void removeSubtree(int key)
    {
        node * v=find_(root,key);
        if(v)
        {
            del_parent(key,root);
            delTree(v);

        }
    }

    void removeBranch(int key)
    {
        node * v=find_(root,key);
        if(v)
        {
            delTree(v);
        }
    }

    void insertAt(int key, QString str, node *& place)
    {
        if(place==nullptr)
        {
            QMessageBox::warning(nullptr,"Error","You can`t insert in this position");
            return;
        }
        add(place,key,str);
    }

    void insertBranch(node *&branch, int key_in_pos)
    {
        insertSubtree(branch,key_in_pos);
    }

    void insertSubtree(node *&subtree, int key_in_pos)
    {
        node * v=find_(root,key_in_pos);
        if(v)
        {
            if (v->left == nullptr) v->left = subtree;
            else if (v->right == nullptr) v->right = subtree;
        }
    }

    node* LCA(int k1,int k2)
    {
        //qDebug()<<root;
        if(k1==k2)
        {
            return find_(root,k1);
        }
        return lca(root,k1,k2);
    }

    void balance()
    {
        bal(root);
    }

    node * getRoot()
    {
        return root;
    }

    void getVerts(node *v,QStringList &list)
    {
        if(v==nullptr)return;

        getVerts(v->left,list);
        list.push_back(QString::number(v->key));
        getVerts(v->right,list);
    }
};



#endif // BINSEARCHTREE_H
