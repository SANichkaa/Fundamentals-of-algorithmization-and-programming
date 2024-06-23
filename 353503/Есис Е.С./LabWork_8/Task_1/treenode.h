#ifndef TREENODE_H
#define TREENODE_H

#include <cstdlib>
#include <ctime>
#include <QString>
#include <QTextEdit>

//узел дерева
struct TreeNode {
    int field;
    struct TreeNode *left;
    struct TreeNode *right;
};

TreeNode *FillTreeWithRandomNumbers(TreeNode* tree, int count, int minValue, int maxValue);
void treeToString(TreeNode* tree, std::string& result);
void print2DUtil(TreeNode* root, int space, std::string& s);
void printBT(const std::string& prefix, const TreeNode* node, bool isLeft, std::string& s);
TreeNode *Add(int x, TreeNode *tree);
TreeNode *Remove(int x, TreeNode *tree);
TreeNode *FindMin(TreeNode *tree);
TreeNode *Find(int x, TreeNode *tree);
void InsertSubTree(TreeNode *tree, TreeNode *sub_tree);
TreeNode* InsertAtPosition(int x, int position, TreeNode *tree);
int CountNodes(TreeNode *tree);
TreeNode* FindLCA(int x1, int x2, TreeNode *tree);

#endif // TREENODE_H
