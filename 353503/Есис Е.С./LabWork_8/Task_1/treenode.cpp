#include "treenode.h"

//добавление узла
TreeNode *Add(int x, TreeNode *tree) {
    if (tree==NULL) {
        tree = new TreeNode();
        tree->field = x;
        tree->left = NULL;
        tree->right = NULL;
    }
    else if (x < tree->field) {
        tree->left = Add(x, tree->left);
    } else {
        tree->right = Add(x, tree->right);
    }
    return tree;
}


//нахождение наименьшего узла в правом поддереве
TreeNode *FindMin(TreeNode *tree) {
    if (tree==NULL) {
        return NULL;
    }
    while (tree->left != NULL) {
        tree = tree->left;
    }
    return tree;
}


//удаление узла по его значению
TreeNode *Remove(int x, TreeNode *tree) {
    if (tree==NULL) {
        return NULL;
    } else if (x < tree->field) {
        tree->left = Remove(x, tree->left);
    } else if (x > tree->field) {
        tree->right = Remove(x, tree->right);
    } else {
        if(tree->left==NULL && tree->right==NULL) {
            delete tree;
        } else if (tree->left==NULL) {
            TreeNode *temp = tree;
            tree = tree->right;
            delete temp;
        } else if (tree->right==NULL) {
            TreeNode *temp = tree;
            tree = tree->left;
            delete temp;
        } else {
            TreeNode *temp = FindMin(tree->right);
            tree->field = temp->field;
            tree->right = Remove(temp->field, tree->right);
        }
    }
    return tree;
}


//поиск узла по значению
TreeNode *Find(int x, TreeNode *tree) {
    if (tree==NULL || tree->field==x) {
        return tree;
    } if (x < tree->field) {
        return Find(x, tree->left);
    } else {
        return Find(x, tree->right);
    }
}

//вставка поддерева;
void InsertSubTree(TreeNode *tree, TreeNode *sub_tree) {
    if(sub_tree==NULL) {
        return;
    } else if (tree==NULL) {
        tree = sub_tree;
    } else {
        if (sub_tree->field < tree->field) {
            InsertSubTree(tree->left, sub_tree);
        } else {
            InsertSubTree(tree->right, sub_tree);
        }
    }
}


//удаление поддерева
void DeleteSubTree(TreeNode *tree) {
    if (tree!=NULL) {
        DeleteSubTree(tree->left);
        DeleteSubTree(tree->right);
        delete tree;
    } else {
        return;
    }
}

//количество узлов в поддереве
int CountNodes(TreeNode *tree) {
    if (tree==NULL) {
        return 0;
    }
    return 1 + CountNodes(tree->left) + CountNodes(tree->right);
}


//вставка элемента в определенную позицию;
TreeNode* InsertAtPosition(int x, int position, TreeNode *tree) {
    if (tree==NULL) {
        if(position==1) {
            return new TreeNode;
        } else {
            return NULL;
        }
        int leftSubTreeSize = CountNodes(tree->left);
        if (position <= leftSubTreeSize + 1) {
            tree->left = InsertAtPosition(x, position, tree->left);
        } else {
            tree->right = InsertAtPosition(x, position - leftSubTreeSize - 1, tree->right);
        }
    }
    return tree;
}


//поиск наименьшего общего предка для двух узлов
TreeNode* FindLCA(int x1, int x2, TreeNode *tree) {
    if (tree==NULL || tree->field==x1 || tree->field==x2) {
        return tree;
    }
    TreeNode *leftLCA = FindLCA(x1, x2, tree->left);
    TreeNode *rightLCA = FindLCA(x1, x2, tree->right);
    if (leftLCA && rightLCA) {
        return tree;
    }
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// заполнение бинарного дерева случайными числами
TreeNode *FillTreeWithRandomNumbers(TreeNode* tree, int count, int minValue, int maxValue) {
    std::srand(std::time(0)); // Инициализация генератора случайных чисел
    for (int i = 0; i < count; i++) {
        int x = minValue + std::rand() % (maxValue - minValue + 1);
        tree = Add(x, tree);
    }
    return tree;
}


// void treeToString(TreeNode* tree, QString& result, int indent = 0) {
//     if (tree != nullptr) {
//         if (tree->right) {
//             treeToString(tree->right, result, indent + 4);
//         }
//         if (indent) {
//             result += QString(" ").repeated(indent);
//         }
//         if (tree->right) {
//             result += " /\n" + QString(" ").repeated(indent);
//         }
//         result += QString::number(tree->field) + "\n";
//         if (tree->left) {
//             result += QString(" ").repeated(indent) + " \\\n";
//             treeToString(tree->left, result, indent + 4);
//         }
//     }
// }

void treeToString(TreeNode* root, std::string& str){
    if (root == NULL)
        return;

    str += std::to_string(root->field) + '0';
    if (!root->left && !root->right)
        return;
    str.push_back('(');
    treeToString(root->left, str);
    str.push_back(')');
    if (root->right) {
        str.push_back('(');
        treeToString(root->right, str);
        str.push_back(')');
    }
}

#define COUNT 10

void print2DUtil(TreeNode* root, int space, std::string& s)
{
    // Base case
    if (root == NULL)
        return;
    int sp = space;
    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space, s);

    // Print current node after space
    // count
    s += '\n';
    for (int i = COUNT; i < space; i++)
        if (i < sp) {
            s += " ";
        } else {
            s += "|";
        }

    s += std::to_string(root->field) + "\n";

    // Process left child
    print2DUtil(root->left, space, s);
}


void printBT(const std::string& prefix, const TreeNode* node, bool isLeft, std::string& s)
{
    if( node != nullptr )
    {
        s += prefix;

        s += (isLeft ? "├──" : "└──" );

        // print the value of the node
        s += std::to_string(node->field) + "\n";

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true, s);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false, s);
    }
}

