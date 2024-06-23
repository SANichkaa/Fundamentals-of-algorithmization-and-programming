#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "treenode.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE





// void dump4(TreeNode const * tree, bool high = true, std::vector<std::string> const & lpref = std::vector<std::string>(), std::vector<std::string> const & cpref = std::vector<std::string>(), std::vector<std::string> const & rpref = std::vector<std::string>(), bool root = true, bool left = true, std::shared_ptr<std::vector<std::vector<std::string>>> lines = nullptr) {
//     if (!tree) return;
//     typedef std::vector<std::string> VS;
//     auto VSCat = [](VS const & a, VS const & b){ auto r = a; r.insert(r.end(), b.begin(), b.end()); return r; };
//     if (root) lines = std::make_shared<std::vector<VS>>();
//     if (tree->left)
//         dump4(tree->left, high, VSCat(lpref, high ? VS({" ", " "}) : VS({" "})), VSCat(lpref, high ? VS({ch_ddia, ch_ver}) : VS({ch_ddia})), VSCat(lpref, high ? VS({ch_hor, " "}) : VS({ch_hor})), false, true, lines);
//     auto sval = std::to_string(tree->field);
//     size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);
//     for (size_t i = 0; i < sval.size(); ++i)
//         lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref : rpref, {std::string(1, sval[i])}));
//     if (tree->right)
//         dump4(tree->right, high, VSCat(rpref, high ? VS({ch_hor, " "}) : VS({ch_hor})), VSCat(rpref, high ? VS({ch_rddia, ch_ver}) : VS({ch_rddia})), VSCat(rpref, high ? VS({" ", " "}) : VS({" "})), false, false, lines);
//     if (root) {
//         VS out;
//         for (size_t l = 0;;++l) {
//             bool last = true;
//             std::string line;
//             for (size_t i = 0; i < lines->size(); ++i)
//                 if (l < (*lines).at(i).size()) {
//                     line += lines->at(i)[l];
//                     last = false;
//                 } else line += " ";
//             if (last) break;
//             out.push_back(line);
//         }
//         for (size_t i = 0; i < out.size(); ++i)
//             std::cout << out[i] << std::endl;
//     }
// }

// void printTree(TreeNode* tree, int indent = 0) {
//     if (tree != nullptr) {
//         if (tree->right) {
//             printTree(tree->right, indent + 4);
//         }
//         if (indent) {
//             std::cout << std::setw(indent) << ' ';
//         }
//         if (tree->right) std::cout << " /\n" << std::setw(indent) << ' ';
//         std::cout << tree->field << "\n ";
//         if (tree->left) {
//             std::cout << std::setw(indent) << ' ' << " \\\n";
//             printTree(tree->left, indent + 4);
//         }
//     }
// }





class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // TreeNode *Add(int x, TreeNode *tree);
    // TreeNode *FindMin(TreeNode *tree);
    // TreeNode *Remove(int x, TreeNode *tree);
    // TreeNode *Find(int x, TreeNode *tree);
    // void InsertSubTree(TreeNode *tree, TreeNode *sub_tree);
    // void DeleteSubTree(TreeNode *tree);
    // int CountNodes(TreeNode *tree);
    // TreeNode *InsertAtPosition(int x, int position, TreeNode *tree);
    // TreeNode *FindLCA(int x1, int x2, TreeNode *tree);
    // TreeNode *FillTreeWithRandomNumbers(TreeNode* tree, int count, int minValue, int maxValue);
    // void treeToString(TreeNode* tree, QString& result, int indent = 0);

    // private slots:


private slots:










    void on_pushButton_find_LCA_clicked();

private:
    Ui::MainWindow *ui;
    TreeNode *tree;
    void on_pushButton_create_BinTree_clicked();
    void on_pushButton_add_clicked();
    // void on_pushButton_remove_clicked();
    void on_pushButton_find_clicked();
    // void on_pushButton_insert_subTree_clicked();
    // void on_pushButton_insert_at_position_clicked();

};
#endif // MAINWINDOW_H
