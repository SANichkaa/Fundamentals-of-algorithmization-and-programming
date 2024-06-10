#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
  ui->spinBox->setMaximum(MAX_VALUE_RANDOM_NUMBER);
  ui->spinBox_3->setMaximum(MAX_VALUE_RANDOM_NUMBER);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  int key = ui->spinBox->value();
  QString value = ui->lineEdit->text();
  tree->insert(key, value);
  ui->labelOutput->clear();
  setTableTree(ui->treeWidget, tree);
  consoleOutput(tree->root);
}

void MainWindow::on_pushButton_2_clicked() {
  int key = ui->spinBox->value();
  tree->remove(key);
  setTableTree(ui->treeWidget, tree);
  consoleOutput(tree->root);
  ui->labelOutput->clear();
}

void MainWindow::on_pushButton_3_clicked() {
  int key = ui->spinBox->value();
  if (tree->select(key) != "") {
    ui->labelOutput->setText(tree->select(tree->root, key));
  }
}

void MainWindow::setTableTree(QTreeWidget* widget, BST* tree) {
  widget->clear();
  QVector<QPair<int, int>> array = tree->directTraversalTree(tree->root);
  if (array.size()) {
    QTreeWidgetItem* root = new QTreeWidgetItem(widget);
    root->setText(0, QString::number(array[0].second));
    QStack<QPair<QTreeWidgetItem*, int>> stack;
    stack.push(QPair<QTreeWidgetItem*, int>(root, array[0].second));
    int i = 1;
    while (i < array.size()) {
      while (array[i].first != stack.top().second) {
        stack.pop();
      }
      QTreeWidgetItem* item = new QTreeWidgetItem(stack.top().first);
      item->setText(0, QString::number(array[i].second));
      stack.push(QPair<QTreeWidgetItem*, int>(item, array[i].second));
      i++;
    }
  }
  widget->expandAll();
}

void MainWindow::consoleOutput(
    BST::Node* node, bool high, std::vector<std::string> const& lpref,
    std::vector<std::string> const& cpref,
    std::vector<std::string> const& rpref, bool ro, bool left,
    std::shared_ptr<std::vector<std::vector<std::string>>> lines) {
  if (!node)
    return;
  typedef std::vector<std::string> VS;
  auto VSCat = [](VS const& a, VS const& b) {
    auto r = a;
    r.insert(r.end(), b.begin(), b.end());
    return r;
  };
  if (ro)
    lines = std::make_shared<std::vector<VS>>();
  if (node->left)
    consoleOutput(node->left, high,
                  VSCat(lpref, high ? VS({" ", " "}) : VS({" "})),
                  VSCat(lpref, high ? VS({ch_ddia, ch_ver}) : VS({ch_ddia})),
                  VSCat(lpref, high ? VS({ch_hor, " "}) : VS({ch_hor})), false,
                  true, lines);
  auto sval = std::to_string(node->key);
  size_t sm =
      left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);
  for (size_t i = 0; i < sval.size(); ++i)
    lines->push_back(VSCat(i < sm    ? lpref
                           : i == sm ? cpref
                                     : rpref,
                           {std::string(1, sval[i])}));
  if (node->right)
    consoleOutput(node->right, high,
                  VSCat(rpref, high ? VS({ch_hor, " "}) : VS({ch_hor})),
                  VSCat(rpref, high ? VS({ch_rddia, ch_ver}) : VS({ch_rddia})),
                  VSCat(rpref, high ? VS({" ", " "}) : VS({" "})), false, false,
                  lines);
  if (ro) {
    VS out;
    for (size_t l = 0;; ++l) {
      bool last = true;
      std::string line;
      for (size_t i = 0; i < lines->size(); ++i)
        if (l < (*lines).at(i).size()) {
          line += lines->at(i)[l];
          last = false;
        } else
          line += " ";
      if (last) {
        break;
      }
      out.push_back(line);
    }
    for (size_t i = 0; i < out.size(); ++i)
      std::cout << out[i] << std::endl;
  }
  std::cout << "\n";
}

void MainWindow::on_pushButton_8_clicked() {
  int symbolsSize = QRandomGenerator::global()->bounded(MIN_RANDOM_LINE_SIZE,
                                                        MAX_RANDOM_LINE_SIZE);
  QString line = "";
  while (symbolsSize--) {
    line += SYMBOLS[QRandomGenerator::global()->bounded(0, SIZE_ALPHABET)];
  }
  tree->insert(tree->root,
               QRandomGenerator::global()->bounded(0, MAX_VALUE_RANDOM_NUMBER),
               line);
  consoleOutput(tree->root);
  setTableTree(ui->treeWidget, tree);
  ui->labelOutput->clear();
}

void MainWindow::on_pushButton_5_clicked() {
  tree->insertTree(helpTree);
  consoleOutput(tree->root);
  setTableTree(ui->treeWidget, tree);
  ui->labelOutput->clear();
  helpTree->clear();
  setTableTree(ui->treeWidget_2, helpTree);
}

void MainWindow::setTableWidget(QVector<QPair<int, QString>> result) {
  ui->tableWidget->setRowCount(0);
  for (int i = 0; i < result.size(); i++) {
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    QTableWidgetItem* firstItem = new QTableWidgetItem;
    firstItem->setText(QString::number(result[i].first));
    ui->tableWidget->setItem(i, 0, firstItem);
    QTableWidgetItem* secondItem = new QTableWidgetItem;
    secondItem->setText(result[i].second);
    ui->tableWidget->setItem(i, 1, secondItem);
  }
  ui->labelOutput->clear();
}

void MainWindow::on_pushButton_10_clicked() {
  int symbolsSize = QRandomGenerator::global()->bounded(MIN_RANDOM_LINE_SIZE,
                                                        MAX_RANDOM_LINE_SIZE);
  QString line = "";
  while (symbolsSize--) {
    line +=
        SYMBOLS[QRandomGenerator::global()->bounded(0, MAX_RANDOM_LINE_SIZE)];
  }
  helpTree->insert(
      QRandomGenerator::global()->bounded(0, MAX_VALUE_RANDOM_NUMBER), line);
  consoleOutput(helpTree->root);
  setTableTree(ui->treeWidget_2, helpTree);
  ui->labelOutput->clear();
}

void MainWindow::on_pushButton_9_clicked() {
  int key = ui->spinBox_3->value();
  QString value = ui->lineEdit_3->text();
  helpTree->insert(key, value);
  ui->labelOutput->clear();
  setTableTree(ui->treeWidget_2, helpTree);
  consoleOutput(helpTree->root);
}

void MainWindow::on_pushButton_4_clicked() {
  setTableWidget(tree->directTraversal(tree->root));
  ui->labelOutput->clear();
}

void MainWindow::on_pushButton_11_clicked() {
  int key = ui->spinBox_3->value();
  helpTree->remove(key);
  setTableTree(ui->treeWidget_2, helpTree);
  consoleOutput(helpTree->root);
  ui->labelOutput->clear();
}

void MainWindow::on_pushButton_6_clicked() {
  tree->removeTree(helpTree);
  consoleOutput(tree->root);
  setTableTree(ui->treeWidget, tree);
  ui->labelOutput->clear();
  helpTree->clear();
  setTableTree(ui->treeWidget_2, helpTree);
}

void MainWindow::on_pushButton_7_clicked() {
  tree->removeBranch(ui->spinBox->value());
  setTableTree(ui->treeWidget, tree);
  consoleOutput(tree->root);
}
