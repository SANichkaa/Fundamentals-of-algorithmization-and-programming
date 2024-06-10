#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  Expression* sube = new BinaryOperation(new Number(2), '*', new Number(4));

  Expression* expr = new BinaryOperation(new Number(3), '+', sube);

  ui->label->setText(QString::number(expr->evaluate()));


  if(check_equals(sube, expr)){

    ui->label_2->setText("Yes");

  }
  else {

    ui->label_2->setText("No");

  }

  auto var = expr+1;

  auto number = var->evaluate();

  ui->label_2->setText(QString::number(number));

  delete expr;
}

bool MainWindow::check_equals(const Expression *left, const Expression *right)
{  

  if(*(int*)left==*(int*)right) {
    return true;
  }
  return false;


}

MainWindow::~MainWindow()
{
  delete ui;
}

