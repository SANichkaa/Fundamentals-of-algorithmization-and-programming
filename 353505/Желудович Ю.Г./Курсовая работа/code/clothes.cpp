#include "clothes.h"
#include "ui_clothes.h"

Clothes::Clothes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Clothes)
{
    ui->setupUi(this);

    connect(this, SIGNAL(updateClothesSignal()), Character::GetInstance(), SLOT(updateChanges()));


    ui->healthBar->setValue(Character::GetInstance()->getHealth());
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());

//    if (Character::GetInstance()->getClothing() == "Кеды, шорты и майка") {
//        ui->pushButton->setEnabled(false);
//        ui->pushButton->hide();
//        ui->pushButton_2->setEnabled(false);
//    }

    connect(Character::GetInstance(), SIGNAL(updateHealth()), this, SLOT(updateHealth()));
    connect(Character::GetInstance(), SIGNAL(updateHappiness()), this, SLOT(updateHappiness()));

}


Clothes::~Clothes()
{
    delete ui;
}


void Clothes::on_pushButton_8_clicked()
{
    emit(OpenMainWindow());
    close();
}

void Clothes::updateHealth()
{
    ui->healthBar->setValue(Character::GetInstance()->getHealth());
}

void Clothes::updateHappiness() {
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());
}



void Clothes::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton->hide();
    ui->pushButton_2->setEnabled(true);

    Character::GetInstance()->setClothing("Кеды, шорты и майка");

    emit updateClothesSignal();
}


void Clothes::on_pushButton_2_clicked()
{
    ui->pushButton->show();
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->hide();
    ui->pushButton_3->setEnabled(true);
    Character::GetInstance()->setClothing("Джинсы, кроссовки и майка");
    emit updateClothesSignal();
}


void Clothes::on_pushButton_3_clicked()
{
    ui->pushButton_2->show();
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_3->hide();
    ui->pushButton_4->setEnabled(true);
    Character::GetInstance()->setClothing("Дешевая одежда с рынка");
    emit updateClothesSignal();
}


void Clothes::on_pushButton_4_clicked()
{
    ui->pushButton_3->show();
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_4->hide();
    ui->pushButton_5->setEnabled(true);
    Character::GetInstance()->setClothing("Ботинки, штаны, свитер");
    emit updateClothesSignal();
}


void Clothes::on_pushButton_5_clicked()
{
    ui->pushButton_4->show();
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_5->hide();
    ui->pushButton_6->setEnabled(true);
    Character::GetInstance()->setClothing("Новая одежда");
    emit updateClothesSignal();
}


void Clothes::on_pushButton_6_clicked()
{
    ui->pushButton_5->show();
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_6->hide();
    Character::GetInstance()->setClothing("Костюм с галстуком");
    emit updateClothesSignal();
}
