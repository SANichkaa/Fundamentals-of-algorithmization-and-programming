#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    tree.add(12);
    tree.add(15);
    treeWidget = new TreeWidget(this);
    treeWidget->setTree(&tree);
    treeWidget->show();
    ui->treeLayout->addWidget(treeWidget);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addButton_clicked() {
    qDebug() << 1;
    int value = ui->valueInput->text().toInt();
    tree.add(value);
    treeWidget->update();
}

void MainWindow::on_removeButton_clicked() {
    int value = ui->valueInput->text().toInt();
    tree.remove(value);
    treeWidget->update();
}

void MainWindow::on_findButton_clicked() {
    int value = ui->valueInput->text().toInt();
    TreeNode* node = tree.find(value);
    if (node) {
        ui->statusLabel->setText("Node found: " + QString::number(node->value));
    } else {
        ui->statusLabel->setText("Node not found");
    }
}
