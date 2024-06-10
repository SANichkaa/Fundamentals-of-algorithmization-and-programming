#include "mainwindow.h"

#include "ui_mainwindow.h"

struct Home
{
  int howManyPeoples;
  double ploshad;
  char index;
  char street[8];
  int ploshadRooms[10];

};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  Home& home = *new Home;
  home.howManyPeoples = 7;
  home.ploshad = 9,57;
  home.index = 'd';
  home.street[0] = 'N';
  home.street[1] = 'i';
  home.street[2] = 'g';
  home.street[3] = 'g';
  home.street[4] = 'e';
  home.street[5] = 'r';
  home.street[6] = 's';
  home.street[7] = '\0';

  qDebug()<<QString::number(home.howManyPeoples)<<"|"<<QString::number(home.ploshad)<<"|"<<home.street;

  for(int y= 0;10>y;y++){
    home.ploshadRooms[y] = y+1;
    qDebug()<<QString::number(home.ploshadRooms[y])<<" ";
  }

}

MainWindow::~MainWindow() { delete ui; }
