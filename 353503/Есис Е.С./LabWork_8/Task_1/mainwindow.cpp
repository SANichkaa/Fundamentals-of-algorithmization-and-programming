#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "treenode.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_create_BinTree, &QPushButton::clicked, this, &MainWindow::on_pushButton_create_BinTree_clicked);
    connect(ui->pushButton_add, &QPushButton::clicked, this, &MainWindow::on_pushButton_add_clicked);
    // connect(ui->pushButton_remove, &QPushButton::clicked, this, &MainWindow::on_pushButton_remove_clicked);
    connect(ui->pushButton_find, &QPushButton::clicked, this, &MainWindow::on_pushButton_find_clicked);
    // connect(ui->pushButton_insert_subTree, &QPushButton::clicked, this, &MainWindow::on_pushButton_insert_subTree_clicked);
    // connect(ui->pushButton_insert_at_position, &QPushButton::clicked, this, &MainWindow::on_pushButton_insert_at_position_clicked);
    connect(ui->pushButton_find_LCA, &QPushButton::clicked, this, &MainWindow::on_pushButton_find_LCA_clicked);

}


void MainWindow::on_pushButton_create_BinTree_clicked()
{
    tree = nullptr;

    tree = FillTreeWithRandomNumbers(tree, 10, 1, 100);
    std::string treeStr;

    // treeToString(tree, treeStr);
    print2DUtil(tree, 0, treeStr);
    // printBT("", tree, false, treeStr);


    ui->textEdit->setText(QString::fromStdString(treeStr));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_add_clicked()
{
    tree = Add(ui->spinBox_add->value(), tree);

    std::string treeStr;
    print2DUtil(tree, 0, treeStr);
    ui->textEdit->setText(QString::fromStdString(treeStr));
}


// void MainWindow::on_pushButton_remove_clicked()
// {
//     tree = Remove(ui->spinBox_add->value(), tree);

//     std::string treeStr;
//     print2DUtil(tree, 0, treeStr);
//     ui->textEdit->setText(QString::fromStdString(treeStr));
// }


void MainWindow::on_pushButton_find_clicked()
{
    tree = Find(ui->spinBox_add->value(), tree);

    std::string treeStr;
    print2DUtil(tree, 0, treeStr);
    ui->textEdit->setText(QString::fromStdString(treeStr));
}


// void MainWindow::on_pushButton_insert_subTree_clicked()
// {
//     tree = InsertSubTree(tree, sub_tree);

//     std::string treeStr;
//     print2DUtil(tree, 0, treeStr);
//     ui->textEdit->setText(QString::fromStdString(treeStr));
// }


// void MainWindow::on_pushButton_insert_at_position_clicked()
// {
//     tree = InsertAtPosition(ui->spinBox_add->value(),ui->spinBox_position->value(),tree);

//     std::string treeStr;
//     print2DUtil(tree, 0, treeStr);
//     ui->textEdit->setText(QString::fromStdString(treeStr));
// }


void MainWindow::on_pushButton_find_LCA_clicked()
{
    tree = FindLCA(ui->spinBox_add->value(), ui->spinBox_position->value(), tree);

    std::string treeStr;
    print2DUtil(tree, 0, treeStr);
    ui->textEdit->setText(QString::fromStdString(treeStr));
}

