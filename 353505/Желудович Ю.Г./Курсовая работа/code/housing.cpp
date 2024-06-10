#include "housing.h"
#include "ui_housing.h"

Housing::Housing(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Housing)
{
    ui->setupUi(this);

    connect(this, SIGNAL(updateHousingSignal()), Character::GetInstance(), SLOT(updateChanges()));


    connect(Character::GetInstance(), SIGNAL(updateHealth()), this, SLOT(updateHealth()));
    connect(Character::GetInstance(), SIGNAL(updateHappiness()), this, SLOT(updateHappiness()));

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

Housing::~Housing()
{
    delete ui;
}

void Housing::on_pushButton_8_clicked()
{
    emit(OpenMainWindow());
    close();
}

void Housing::updateHealth()
{
    ui->healthBar->setValue(Character::GetInstance()->getHealth());
}

void Housing::updateHappiness() {
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());
}


void Housing::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton->hide();
    ui->pushButton_2->setEnabled(true);
    Character::GetInstance()->setHousing("Общежитие");
    emit updateHousingSignal();
}

void Housing::on_pushButton_2_clicked()
{
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->hide();
    ui->pushButton_3->setEnabled(true);
    ui->pushButton->show();
    Character::GetInstance()->setHousing("Отдельная комната");
    emit updateHousingSignal();
}

void Housing::on_pushButton_3_clicked()
{
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_3->hide();
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_2->show();
    Character::GetInstance()->setHousing("Дешевые апартаменты");
    emit updateHousingSignal();
}

void Housing::on_pushButton_4_clicked()
{
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_4->hide();
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_3->show();
    Character::GetInstance()->setHousing("Апартаменты среднего класса");
    emit updateHousingSignal();
}

void Housing::on_pushButton_5_clicked()
{
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_5->hide();
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_4->show();
    Character::GetInstance()->setHousing("Комфортные апартаменты");
    emit updateHousingSignal();
}

void Housing::on_pushButton_6_clicked()
{
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_6->hide();
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_5->show();
    Character::GetInstance()->setHousing("Комфортная квартира в центре города");
    emit updateHousingSignal();
}

void Housing::on_pushButton_7_clicked()
{
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_7->hide();
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_6->show();
    Character::GetInstance()->setHousing("Маленький дом за городом");
    emit updateHousingSignal();
}

void Housing::on_pushButton_9_clicked()
{
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_9->hide();
    ui->pushButton_7->show();
    Character::GetInstance()->setHousing("Средний дом на окраине города");
    emit updateHousingSignal();
}

