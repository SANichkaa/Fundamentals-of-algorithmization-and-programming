#include "bst.h"

TreeNode* BST::add(TreeNode* node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }
    if (value < node->value) {
        node->left = add(node->left, value);
    } else if (value > node->value) {
        node->right = add(node->right, value);
    }
    return node;
}

TreeNode* BST::find(TreeNode* node, int value) {
    if (node == nullptr || node->value == value) {
        return node;
    }
    if (value < node->value) {
        return find(node->left, value);
    } else {
        return find(node->right, value);
    }
}

TreeNode* BST::remove(TreeNode* node, int value) {
    if (node == nullptr) return node;
    if (value < node->value) {
        node->left = remove(node->left, value);
    } else if (value > node->value) {
        node->right = remove(node->right, value);
    } else {
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }

        TreeNode* temp = minValueNode(node->right);
        node->value = temp->value;
        node->right = remove(node->right, temp->value);
    }
    return node;
}

TreeNode* BST::minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

void BST::traverse(TreeNode* node, ostream& out) {
    if (node == nullptr) return;
    traverse(node->left, out);
    out << node->value << " ";
    traverse(node->right, out);
}

TreeNode* BST::lowestCommonAncestor(TreeNode* node, int v1, int v2) {
    if (node == nullptr) return nullptr;
    if (node->value > v1 && node->value > v2) {
        return lowestCommonAncestor(node->left, v1, v2);
    }
    if (node->value < v1 && node->value < v2) {
        return lowestCommonAncestor(node->right, v1, v2);
    }
    return node;
}

void BST::add(int value) {
    root = add(root, value);
}

void BST::remove(int value) {
    root = remove(root, value);
}

TreeNode* BST::find(int value) {
    return find(root, value);
}

void BST::traverse(ostream& out) {
    traverse(root, out);
    out << endl;
}

TreeNode* BST::lowestCommonAncestor(int v1, int v2) {
    return lowestCommonAncestor(root, v1, v2);
}
