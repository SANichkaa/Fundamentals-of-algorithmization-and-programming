#include "health.h"
#include "ui_health.h"

Health::Health(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Health)
{
    ui->setupUi(this);


    connect(Character::GetInstance(), SIGNAL(updateHealth()), this, SLOT(updateHealth()));
    connect(Character::GetInstance(), SIGNAL(updateHappiness()), this, SLOT(updateHappiness()));
    connect(this, SIGNAL(updateHealthSignal()), Character::GetInstance(), SLOT(updateChanges()));

    ui->healthBar->setValue(Character::GetInstance()->getHealth());
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());

    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);

}

Health::~Health()
{
    delete ui;
}

void Health::on_pushButton_8_clicked()
{
    emit(OpenMainWindow());
    close();
}

void Health::updateHealth()
{
    ui->healthBar->setValue(Character::GetInstance()->getHealth());

    while (Character::GetInstance()->getHealth() == 100) {
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        break;
    }
    if (Character::GetInstance()->getHealth() < 100) {
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
    }
}

void Health::updateHappiness() {
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());
}

void Health::on_pushButton_2_clicked()
{
    if (Character::GetInstance()->getMoney() > 5) {
            Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() - 5);
            Character::GetInstance()->setHealth(Character::GetInstance()->getHealth() + 4);
            if(Character::GetInstance()->getHealth() > 100) {
                Character::GetInstance()->setHealth(100);
            }
            emit updateHealth();
            emit updateHealthSignal();
    }
    else {
    QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}


void Health::on_pushButton_3_clicked()
{
    if (Character::GetInstance()->getMoney() > 30) {
            Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() - 30);
            Character::GetInstance()->setHealth(Character::GetInstance()->getHealth() + 7);
            if(Character::GetInstance()->getHealth() > 100) {
                Character::GetInstance()->setHealth(100);
            }
            emit updateHealth();
            emit updateHealthSignal();
    }
    else {
    QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}


void Health::on_pushButton_4_clicked()
{
    if (Character::GetInstance()->getMoney() > 100) {
            Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() - 100);
            Character::GetInstance()->setHealth(Character::GetInstance()->getHealth() + 9);
            if(Character::GetInstance()->getHealth() > 100) {
                Character::GetInstance()->setHealth(100);
            }
            emit updateHealth();
            emit updateHealthSignal();
    }
    else {
    QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}


void Health::on_pushButton_5_clicked()
{
    if (Character::GetInstance()->getMoney() > 500) {
            Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() - 500);
            Character::GetInstance()->setHealth(Character::GetInstance()->getHealth() + 15);
            if(Character::GetInstance()->getHealth() > 100) {
                Character::GetInstance()->setHealth(100);
            }
            emit updateHealth();
            emit updateHealthSignal();
    }
    else {
    QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}


void Health::on_pushButton_6_clicked()
{
    if (Character::GetInstance()->getMoney() > 1300) {
            Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() - 1300);
            Character::GetInstance()->setHealth(Character::GetInstance()->getHealth() + 29);
            if(Character::GetInstance()->getHealth() > 100) {
                Character::GetInstance()->setHealth(100);
            }
            emit updateHealth();
            emit updateHealthSignal();
    }
    else {
    QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}


void Health::on_pushButton_7_clicked()
{
    if (Character::GetInstance()->getMoney() > 2500) {
            Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() - 2500);
            Character::GetInstance()->setHealth(Character::GetInstance()->getHealth() + 40);
            if(Character::GetInstance()->getHealth() > 100) {
                Character::GetInstance()->setHealth(100);
            }
            emit updateHealth();
            emit updateHealthSignal();
    }
    else {
    QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}

