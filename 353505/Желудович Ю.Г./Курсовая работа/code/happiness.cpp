#include "happiness.h"
#include "ui_happiness.h"

Happiness::Happiness(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Happiness)
{
    ui->setupUi(this);

    connect(Character::GetInstance(), SIGNAL(updateHealth()), this, SLOT(updateHealth()));
    connect(Character::GetInstance(), SIGNAL(updateHappiness()), this, SLOT(updateHappiness()));
    connect(this, SIGNAL(updateHappinessSignal()), Character::GetInstance(), SLOT(updateChanges()));

    ui->healthBar->setValue(Character::GetInstance()->getHealth());
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());

    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
}

Happiness::~Happiness()
{
    delete ui;
}

void Happiness::on_pushButton_8_clicked()
{
    emit(OpenMainWindow());
    close();
}

void Happiness::updateHealth()
{
    ui->healthBar->setValue(Character::GetInstance()->getHealth());
}

void Happiness::updateHappiness() {
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());
    while (Character::GetInstance()->getHappiness() == 100) {
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        break;
    }
    if (Character::GetInstance()->getHappiness() < 100) {
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
    }
}

void Happiness::on_pushButton_2_clicked()
{
    if (Character::GetInstance()->getMoney() > 3) {
            Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() - 3);
            Character::GetInstance()->setHappiness(Character::GetInstance()->getHappiness() + 3);
            if(Character::GetInstance()->getHappiness() > 100) {
                Character::GetInstance()->setHappiness(100);
            }
            emit updateHappiness();
            emit updateHappinessSignal();
    }
    else {
        QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}


void Happiness::on_pushButton_3_clicked()
{
    if (Character::GetInstance()->getMoney() > 9) {
            Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() - 9);
            Character::GetInstance()->setHappiness(Character::GetInstance()->getHappiness() + 5);
            if(Character::GetInstance()->getHappiness() > 100) {
                Character::GetInstance()->setHappiness(100);
            }
            emit updateHappinessSignal();
            emit updateHappiness();
    }
    else {
        QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}


void Happiness::on_pushButton_4_clicked()
{
    if (Character::GetInstance()->getMoney() > 20) {
            Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() - 20);
            Character::GetInstance()->setHappiness(Character::GetInstance()->getHappiness() + 7);
            if(Character::GetInstance()->getHappiness() > 100) {
                Character::GetInstance()->setHappiness(100);
            }
            emit updateHappiness();
            emit updateHappinessSignal();
    }
    else {
        QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}


void Happiness::on_pushButton_5_clicked()
{
    if (Character::GetInstance()->getMoney() > 50) {
            Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() - 50);
            Character::GetInstance()->setHappiness(Character::GetInstance()->getHappiness() + 10);
            if(Character::GetInstance()->getHappiness() > 100) {
                Character::GetInstance()->setHappiness(100);
            }
            emit updateHappiness();
            emit updateHappinessSignal();
    }
    else {
        QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}


void Happiness::on_pushButton_6_clicked()
{
    if (Character::GetInstance()->getMoney() > 80) {
            Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() - 80);
            Character::GetInstance()->setHappiness(Character::GetInstance()->getHappiness() + 13);
            if(Character::GetInstance()->getHappiness() > 100) {
                Character::GetInstance()->setHappiness(100);
            }
            emit updateHappiness();
            emit updateHappinessSignal();
    }
    else {
        QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}


void Happiness::on_pushButton_7_clicked()
{
    if (Character::GetInstance()->getMoney() > 200) {
            Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() - 200);
            Character::GetInstance()->setHappiness(Character::GetInstance()->getHappiness() + 18);
            if(Character::GetInstance()->getHappiness() > 100) {
                Character::GetInstance()->setHappiness(100);
            }
            emit updateHappiness();
            emit updateHappinessSignal();
    }
    else {
        QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}


void Happiness::on_pushButton_9_clicked()
{
    if (Character::GetInstance()->getMoney() > 1000) {
            Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() - 1000);
            Character::GetInstance()->setHappiness(Character::GetInstance()->getHappiness() + 32);
            if(Character::GetInstance()->getHappiness() > 100) {
                Character::GetInstance()->setHappiness(100);
            }
            emit updateHappiness();
            emit updateHappinessSignal();
    }
    else {
        QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}

