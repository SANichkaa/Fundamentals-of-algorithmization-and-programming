#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "binarysearchtree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_insertBranchButton_clicked();
    void on_deleteBranchButton_clicked();
    void on_findLCAButton_clicked();
    void on_traverseButton_clicked();
    void updateTraversal(QString traversal);

private:
    Ui::MainWindow* ui;
    BinarySearchTree* bst;
};

#endif // MAINWINDOW_H
