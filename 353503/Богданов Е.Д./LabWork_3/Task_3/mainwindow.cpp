#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), scene(new Scena()) {
  ui->setupUi(this);

  scene->setBackgroundBrush(QColor(Qt::lightGray));
  ui->graphicsView->setScene(scene);



}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_lineEdit_returnPressed() {
  const int max_disks = 10;
  const int time_update = 100;

  if (ui->lineEdit->text().toInt() > 0 and
      ui->lineEdit->text().toInt() <= max_disks) {
    scene->clear();

    n = ui->lineEdit->text().toInt();
    scene->Go_To_Work(n);

    timer = new QTimer();
    timer->start(time_update);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_info()));
  }
}

void MainWindow::update_info() {

  if(scene->Get_hanoi_gotov()==true){

    ui->label->setText("Теперь можно");

    timer->stop();

  }

}

void MainWindow::on_pushButton_3_clicked() { exit(0); }


void MainWindow::on_pushButton_clicked()
{
  if(steps>=1){

    MyRect* item = scene->GetItems()[scene->GetPlan()[steps-1].number-1];
    scene->Move(item, scene->GetPlan()[steps-1].to_x, scene->GetPlan()[steps-1].from_x);
    steps--;
  }
}


void MainWindow::on_pushButton_2_clicked()
{
  if(steps<pow(2, n)){

    MyRect* item = scene->GetItems()[scene->GetPlan()[steps].number-1];
    scene->Move(item, scene->GetPlan()[steps].from_x, scene->GetPlan()[steps].to_x);
    steps++;

  }
}


void MainWindow::on_spinBox_editingFinished()
{
  if(ui->spinBox->text().toInt()>0 and ui->spinBox->text().toInt()<=10) { scene->SetSpeed(ui->spinBox->text().toInt()); }
}

