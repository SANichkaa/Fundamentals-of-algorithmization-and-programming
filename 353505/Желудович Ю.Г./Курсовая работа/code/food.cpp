#include "food.h"
#include "ui_food.h"

Food::Food(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Food)
{
    ui->setupUi(this);

    connect(this, SIGNAL(updateFoodSignal()), Character::GetInstance(), SLOT(updateChanges()));


    connect(Character::GetInstance(), SIGNAL(updateHealth()), this, SLOT(updateHealth()));
    connect(Character::GetInstance(), SIGNAL(updateHappiness()), this, SLOT(updateHappiness()));

    ui->healthBar->setValue(Character::GetInstance()->getHealth());
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());

}

Food::~Food()
{
    delete ui;
}

void Food::on_pushButton_8_clicked()
{
    emit OpenMainWindow();
    close();
}

void Food::updateHealth()
{
    ui->healthBar->setValue(Character::GetInstance()->getHealth());
}

void Food::updateHappiness() {
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());
}

void Food::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton->hide();
    ui->pushButton_2->setEnabled(true);
    Character::GetInstance()->setFood("Бесплатная еда на работе");
    emit updateFoodSignal();
}


void Food::on_pushButton_2_clicked()
{
    ui->pushButton->show();
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->hide();
    ui->pushButton_3->setEnabled(true);
    Character::GetInstance()->setFood("Бургер и бесплатная еда на работе");
    emit updateFoodSignal();
}


void Food::on_pushButton_3_clicked()
{
    ui->pushButton_2->show();
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_3->hide();
    ui->pushButton_4->setEnabled(true);
    Character::GetInstance()->setClothing("Бургер, картошка фри и газировка");
    emit updateFoodSignal();
}


void Food::on_pushButton_4_clicked()
{
    ui->pushButton_3->show();
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_4->hide();
    ui->pushButton_5->setEnabled(true);
    Character::GetInstance()->setFood("Фастфуд из супермаркета");
    emit updateFoodSignal();
}


void Food::on_pushButton_5_clicked()
{
    ui->pushButton_4->show();
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_5->hide();
    ui->pushButton_6->setEnabled(true);
    Character::GetInstance()->setFood("Дешевое кафе");
    emit updateFoodSignal();
}


void Food::on_pushButton_6_clicked()
{
    ui->pushButton_5->show();
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_6->hide();
    ui->pushButton_7->setEnabled(true);
    Character::GetInstance()->setFood("Домашняя еда");
    emit updateFoodSignal();
}


void Food::on_pushButton_7_clicked()
{
    ui->pushButton_6->show();
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_7->hide();
    Character::GetInstance()->setFood("Еда в дорогом ресторане");
    emit updateFoodSignal();
}

