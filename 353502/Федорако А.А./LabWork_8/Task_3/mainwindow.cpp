#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::setTableTree() {
  ui->treeWidget->clear();

  QVector<QPair<Color, QPair<int, int>>> array =
      tree->directTraversalTree(tree->root);
  if (array.size()) {
    QTreeWidgetItem* root = new QTreeWidgetItem(ui->treeWidget);
    root->setText(0, QString::number(array[0].second.second));

    QStack<QPair<QTreeWidgetItem*, int>> stack;
    stack.push({root, array[0].second.second});
    for (int i = 1; i < array.size(); i++) {
      while (array[i].second.first != stack.top().second) {
        stack.pop();
      }
      QTreeWidgetItem* item = new QTreeWidgetItem(stack.top().first);
      item->setText(0, QString::number(array[i].second.second));
      item->setForeground(
          0, array[i].first == Color::Black ? QBrush(Qt::black) : QBrush(Qt::red));
      stack.push({item, array[i].second.second});
    }
    ui->treeWidget->expandAll();
  }
}

void MainWindow::on_pushButton_clicked() {
  tree->insert(ui->spinBox_2->value(), ui->lineEdit_2->text());
  setTableTree();
}

void MainWindow::on_pushButton_2_clicked() {
  int symbolsSize = QRandomGenerator::global()->bounded(MIN_RANDOM_LINE_SIZE, MAX_RANDOM_LINE_SIZE);
  QString line = "";
  while (symbolsSize--) {
    line += SYMBOLS[QRandomGenerator::global()->bounded(0, SIZE_ALPHABET)];
  }
  tree->insert(QRandomGenerator::global()->bounded(0, MAX_VALUE_RANDOM_NUMBER), line);
  setTableTree();
  ui->labelOutput->clear();
}

void MainWindow::on_pushButton_3_clicked() {
  tree->remove(ui->spinBox_2->value());
  setTableTree();
}

void MainWindow::on_pushButton_4_clicked() {
  if (tree->find(ui->spinBox_2->value())) {
    QString value = tree->find(ui->spinBox_2->value())->value;
    ui->labelOutput->setText(value);
  }
}

void MainWindow::on_pushButton_5_clicked() {
  tree->clear();
  setTableTree();
}
