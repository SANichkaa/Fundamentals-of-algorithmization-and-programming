#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include "bst.h"

class TreeWidget : public QWidget {
    Q_OBJECT

private:
    BST* tree;

protected:
    void paintEvent(QPaintEvent* event) override;

public:
    TreeWidget(QWidget* parent = nullptr);
    void setTree(BST* tree) { this->tree = tree; }
    void drawTree(QPainter* painter, TreeNode* node, int x, int y, int hSpacing);
};

#endif // TREEWIDGET_H
