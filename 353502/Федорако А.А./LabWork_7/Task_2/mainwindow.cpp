#include "mainwindow.h"
#include "ui_mainwindow.h"

#define LN \
  { std::cout << __LINE__ << std::endl; }
#define DEB(x) \
  { std::cout << #x << "=(" << (x) << ") "; }

static std::string ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\",
                   ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-",
                   ch_ddia_hor = "/-", ch_ver_spa = "| ";

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  tree = new BST();
  ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::consoleOutput(
    Node* node, bool high, std::vector<std::string> const& lpref,
    std::vector<std::string> const& cpref,
    std::vector<std::string> const& rpref, bool root, bool left,
    std::shared_ptr<std::vector<std::vector<std::string>>> lines) {
  if (!node)
    return;
  typedef std::vector<std::string> VS;
  auto VSCat = [](VS const& a, VS const& b) {
    auto r = a;
    r.insert(r.end(), b.begin(), b.end());
    return r;
  };
  if (root)
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
  if (root) {
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

void MainWindow::on_pushButton_clicked() {
  int key = ui->spinBox->value();
  QString value = ui->lineEdit->text();
  tree->insert(tree->root, key, value);
  consoleOutput(tree->root);
  setTableTree();
  ui->labelOutput->clear();
}

void MainWindow::on_pushButton_2_clicked() {
  int key = ui->spinBox->value();
  tree->remove(tree->root, key);
  setTableTree();
  consoleOutput(tree->root);
  ui->labelOutput->clear();
}

void MainWindow::on_pushButton_3_clicked() {
  int key = ui->spinBox->value();
  if (tree->select(tree->root, key)) {
    ui->labelOutput->setText(tree->select(tree->root, key)->value);
  }
}

void MainWindow::on_pushButton_4_clicked() {
  setTableWidget(tree->directTraversal(tree->root));
  ui->labelOutput->clear();
}

void MainWindow::on_pushButton_5_clicked() {
  setTableWidget(tree->reverceTraversal(tree->root));
  ui->labelOutput->clear();
}

void MainWindow::on_pushButton_6_clicked() {
  setTableWidget(tree->simmetricalTraversal(tree->root));
  ui->labelOutput->clear();
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

void MainWindow::setTableTree() {
  ui->treeWidget->clear();
  QVector<QPair<int, int>> array = tree->directTraversalTree(tree->root);
  if (array.size()) {
    QTreeWidgetItem* root = new QTreeWidgetItem(ui->treeWidget);
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
      i++
    }
  }
}

void MainWindow::on_pushButton_8_clicked() {
  int symbolsSize = QRandomGenerator::global()->bounded(MIN_RANDOM_LINE_SIZE, MAX_RANDOM_LINE_SIZE);
  QString line = "";
  while (symbolsSize--) {
    line += SYMBOLS[QRandomGenerator::global()->bounded(0, SIZE_ALPHABET)];
  }
  tree->insert(tree->root, QRandomGenerator::global()->bounded(0, MAX_VALUE_RANDOM_NUMBER), line);
  consoleOutput(tree->root);
  setTableTree();
  ui->labelOutput->clear();
}
