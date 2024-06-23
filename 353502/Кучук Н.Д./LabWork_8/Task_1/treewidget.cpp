#include "treewidget.h"
#include <QPainter>
#include <QPaintEvent>

TreeWidget::TreeWidget(QWidget* parent) : QWidget(parent), tree(nullptr) {}

void TreeWidget::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter painter(this);
    if (tree != nullptr) {
        drawTree(&painter, tree->getRoot(), width() / 2, 50, 100);
    }
}

void TreeWidget::drawTree(QPainter* painter, TreeNode* node, int x, int y, int hSpacing) {
    if (node == nullptr) return;

    painter->drawEllipse(x - 15, y - 15, 30, 30);
    painter->drawText(x - 10, y + 5, QString::number(node->value));

    if (node->left != nullptr) {
        painter->drawLine(x, y, x - hSpacing, y + 50);
        drawTree(painter, node->left, x - hSpacing, y + 50, hSpacing / 2);
    }
    if (node->right != nullptr) {
        painter->drawLine(x, y, x + hSpacing, y + 50);
        drawTree(painter, node->right, x + hSpacing, y + 50, hSpacing / 2);
    }
}
