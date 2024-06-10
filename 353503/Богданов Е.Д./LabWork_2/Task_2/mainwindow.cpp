#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_6_clicked() { exit(0); }

void MainWindow::on_pushButton_2_clicked() {
  QFileDialog dialog(this);

  const int n5 = 5;

  way_to_file = dialog.getOpenFileName(this, "сюда не надо смотреть",
                                       "/home/evgen/Lab2", "*.txt");


  QFile file(way_to_file);

  if (file.exists() and file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    file.seek(0);

    while (!file.atEnd()) {
      CompItem item;

      for (int i = 0; n5 >= i; i++) {
        item.Set_Vector(file.readLine());
      }

      Items.push_back(item);

      QListWidgetItem *list_item = new QListWidgetItem;

      list_item->setText(Items.last().Get_Vector()[2]);
      ui->listWidget->insertItem(ui->listWidget->count(), list_item);
    }
  }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item) {
  int number = ui->listWidget->row(item);

  delete ui->listWidget->takeItem(number);

  Items.remove(number);

  ui->listWidget->clear();

  for (auto &Item : Items) {
    QListWidgetItem *list_item = new QListWidgetItem;

    list_item->setText(Item.Get_Vector()[2]);
    ui->listWidget->insertItem(ui->listWidget->count(), list_item);
  }
  QFile file(way_to_file);

  if (file.exists() and file.open(QIODevice::ReadWrite | QIODevice::Text)) {
    file.seek(file.size());

    file.resize(0);

    for (auto &Item : Items) {
      QTextStream stream(&file);
      stream << Item.Get_Vector()[0] << Item.Get_Vector()[1]
             << Item.Get_Vector()[2] << Item.Get_Vector()[3]
             << Item.Get_Vector()[4]
             << Item.Get_Vector()[Item.Get_Vector().size() - 1];
    }
  }
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item) {
  int number = ui->listWidget->row(item);

  ui->label_9->setText(Items[number].Get_Vector()[0]);
  ui->label_10->setText(Items[number].Get_Vector()[1]);
  ui->label_11->setText(Items[number].Get_Vector()[2]);
  ui->label_12->setText(Items[number].Get_Vector()[3]);
  ui->label_13->setText(Items[number].Get_Vector()[4]);
  ui->label_14->setText(
      Items[number].Get_Vector()[Items[number].Get_Vector().size() - 1]);
}

void MainWindow::on_pushButton_clicked() {
  if (ui->lineEdit->displayText().isEmpty() or
      ui->lineEdit_2->displayText().isEmpty() or
      ui->lineEdit_3->displayText().isEmpty() or
      ui->lineEdit_4->displayText().isEmpty() or
      ui->lineEdit_5->displayText().isEmpty() or
      ui->lineEdit_6->displayText().isEmpty()) {
    ui->label_15->setText("No");
  } else {
    if (ui->lineEdit->text() == "Видеокарта" or
        ui->lineEdit->text() == "Процессор" or
        ui->lineEdit->text() == "Блок питания" or
        ui->lineEdit->text() == "Материнская плата" or
        ui->lineEdit->text() == "Оперативная память" or
        ui->lineEdit->text() == "Монитор") {
      if (ui->lineEdit_5->text().toDouble() > 0) {
      }

      QFile file(way_to_file);

      if (file.exists() and file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << ui->lineEdit->text() << "\n"
               << ui->lineEdit_2->text() << "\n"
               << ui->lineEdit_3->text() << "\n"
               << ui->lineEdit_4->text() << "\n"
               << ui->lineEdit_5->text() << "\n"
               << ui->lineEdit_6->text() << "\n";
      }

      CompItem item;

      item.Set_Vector(ui->lineEdit->text());
      item.Set_Vector(ui->lineEdit_2->text());
      item.Set_Vector(ui->lineEdit_3->text());
      item.Set_Vector(ui->lineEdit_4->text());
      item.Set_Vector(ui->lineEdit_5->text());
      item.Set_Vector(ui->lineEdit_6->text());

      Items.push_back(item);

      QListWidgetItem *list_item = new QListWidgetItem;

      list_item->setText(QString::number(Items.size()));
      ui->listWidget->insertItem(ui->listWidget->count(), list_item);

    } else {
      ui->label_15->setText("No");
    }
  }
}

void MainWindow::on_pushButton_3_clicked() {
  QVector<CompItem> mass;
  double size = Items.size(), max = 0, iterator = 0;

  for (int i = 0; size > i; i++) {
    for (int y = 0; Items.size() > y; y++) {
      if (Items[y].Get_Vector()[4].toDouble() >= max) {
        max = Items[y].Get_Vector()[4].toDouble();

        iterator = y;
      }
    }

    mass.push_back(Items[iterator]);
    Items.remove(iterator);
    max = 0;
  }

  Items = mass;

  ui->listWidget->clear();

  for (auto &Item : Items) {
    QListWidgetItem *list_item = new QListWidgetItem;

    list_item->setText(Item.Get_Vector()[2]);
    ui->listWidget->insertItem(ui->listWidget->count(), list_item);
  }
}

void MainWindow::on_radioButton_clicked(bool checked) {
  if (checked == false) {
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);

  } else {
    ui->checkBox->setChecked(true);
    ui->checkBox_2->setChecked(true);
    ui->checkBox_3->setChecked(true);
  }
}

void MainWindow::on_pushButton_5_clicked() {
  if (!ui->lineEdit_8->displayText().isEmpty()) {
    ui->listWidget->clear();

    QVector<CompItem> mass;
    QString str = ui->lineEdit_8->text();
    if (ui->checkBox->isChecked()) {
      for (int y = 0;Items.size()>y;y++) {
        QString str1 = Items[y].Get_Vector()[2];
        str1.remove(str1.size()-1, 1);
        if (str1 == str) {
          mass.push_back(Items[y]);
        }
      }
    }

    if (ui->checkBox_2->isChecked()) {
      for (int y = 0;Items.size()>y;y++) {
        QString str1 = Items[y].Get_Vector()[1];
        str1.remove(str1.size()-1, 1);
        if (str1 == str) {
          mass.push_back(Items[y]);
        }
      }
    }

    if (ui->checkBox_3->isChecked()) {
      for (int y = 0;Items.size()>y;y++) {
        QString str1 = Items[y].Get_Vector()[0];
        str1.remove(str1.size()-1, 1);
        if (str1 == str) {
          mass.push_back(Items[y]);
        }
      }
    }

    for (int y = 0;mass.size()>y;y++) {
      QListWidgetItem *list_item = new QListWidgetItem;
      list_item->setText(mass[y].Get_Vector()[2]);
      ui->listWidget->insertItem(ui->listWidget->count(), list_item);
    }
  }

}

void MainWindow::on_pushButton_4_clicked()
{
    ui->listWidget->clear();

  for (auto &Item : Items) {
    QListWidgetItem *list_item = new QListWidgetItem;

    list_item->setText(Item.Get_Vector()[2]);
    ui->listWidget->insertItem(ui->listWidget->count(), list_item);
  }

}


void MainWindow::on_checkBox_2_clicked()
{
  if(ui->checkBox->isChecked()==true and ui->checkBox_3->isChecked()==true and ui->checkBox_2->isChecked()==true){
    ui->radioButton->setChecked(true);

  }
  else {

    ui->radioButton->setChecked(false);
  }
}


void MainWindow::on_checkBox_3_clicked()
{
  if(ui->checkBox->isChecked()==true and ui->checkBox_3->isChecked()==true and ui->checkBox_2->isChecked()==true){
    ui->radioButton->setChecked(true);

  }  else {

    ui->radioButton->setChecked(false);
  }
}


void MainWindow::on_checkBox_clicked()
{
  if(ui->checkBox->isChecked()==true and ui->checkBox_3->isChecked()==true and ui->checkBox_2->isChecked()==true){
    ui->radioButton->setChecked(true);

  }  else {

    ui->radioButton->setChecked(false);
  }
}

