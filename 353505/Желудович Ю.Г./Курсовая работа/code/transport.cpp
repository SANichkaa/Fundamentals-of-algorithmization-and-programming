#include "transport.h"
#include "ui_transport.h"

Transport::Transport(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Transport)
{
    ui->setupUi(this);

    connect(this, SIGNAL(updateTransportSignal()), Character::GetInstance(), SLOT(updateChanges()));


    connect(Character::GetInstance(), SIGNAL(updateHealth()), this, SLOT(updateHealth()));
    connect(Character::GetInstance(), SIGNAL(updateHappiness()), this, SLOT(updateHappiness()));

    ui->healthBar->setValue(Character::GetInstance()->getHealth());
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());

}

Transport::~Transport()
{
    delete ui;
}

void Transport::on_pushButton_8_clicked()
{
    emit(OpenMainWindow());
    close();
}

void Transport::updateHealth()
{
    ui->healthBar->setValue(Character::GetInstance()->getHealth());
}

void Transport::updateHappiness() {
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());
}

void Transport::on_pushButton_clicked()
{
    if (Character::GetInstance()->getMoney() > 1300) {
    ui->pushButton->setEnabled(false);
    ui->pushButton->hide();
    ui->pushButton_2->setEnabled(true);
    Character::GetInstance()->setTransport("40-летняя машина");
    emit updateTransportSignal();
    }
    else {
        QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}


void Transport::on_pushButton_2_clicked()
{
    if(Character::GetInstance()->getMoney() > 3500) {
    ui->pushButton->show();
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->hide();
    ui->pushButton_3->setEnabled(true);
    Character::GetInstance()->setTransport("30-летняя машина");
    Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() + 1300);
    emit updateTransportSignal();
}
else {
    QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
}
}


void Transport::on_pushButton_3_clicked()
{
    if(Character::GetInstance()->getMoney() > 7000) {
    ui->pushButton_2->show();
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_3->hide();
    ui->pushButton_4->setEnabled(true);
    Character::GetInstance()->setTransport("10-летняя машина");
    Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() + 3500);
    emit updateTransportSignal();
    }
    else {
        QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }

}


void Transport::on_pushButton_4_clicked()
{
    if(Character::GetInstance()->getMoney() > 13000) {
    ui->pushButton_3->show();
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_4->hide();
    ui->pushButton_5->setEnabled(true);
    Character::GetInstance()->setTransport("Б/у машина");
    Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() + 7000);
    emit updateTransportSignal();
    }
    else {
        QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}


void Transport::on_pushButton_5_clicked()
{
    if(Character::GetInstance()->getMoney() > 15000) {
    ui->pushButton_4->show();
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_5->hide();
    ui->pushButton_6->setEnabled(true);
    Character::GetInstance()->setTransport("Новая машина");
    Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() + 13000);
    emit updateTransportSignal();
    }
    else {
        QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}


void Transport::on_pushButton_6_clicked()
{
    if(Character::GetInstance()->getMoney() > 22000) {
    ui->pushButton_5->show();
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_6->hide();
    Character::GetInstance()->setTransport("Пикап");
    Character::GetInstance()->setMoney(Character::GetInstance()->getMoney() + 15000);
    emit updateTransportSignal();
    }
    else {
        QMessageBox::information(nullptr, "Недостаточно денег!", "Недостаточно денег для списания.");
    }
}

