#ifndef NODE_H
#define NODE_H
struct node
{
    int key;
    QString str;
    node * left=nullptr;
    node * right=nullptr;
    node(int key, QString s){this->key=key;str=s;}
};
#endif // NODE_H
