#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* add(TreeNode* node, int value);
    TreeNode* find(TreeNode* node, int value);
    TreeNode* remove(TreeNode* node, int value);
    TreeNode* minValueNode(TreeNode* node);
    void traverse(TreeNode* node, ostream& out);
    TreeNode* lowestCommonAncestor(TreeNode* node, int v1, int v2);

public:
    BST() : root(nullptr) {}
    void add(int value);
    void remove(int value);
    TreeNode* find(int value);
    void traverse(ostream& out);
    TreeNode* lowestCommonAncestor(int v1, int v2);
    TreeNode* getRoot() const { return root; }
};

#endif // BST_H
