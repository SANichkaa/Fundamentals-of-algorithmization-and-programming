#include "relationship.h"
#include "ui_relationship.h"

Relationship::Relationship(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Relationship)
{
    ui->setupUi(this);

    connect(this, SIGNAL(updateRelationshipSignal()), Character::GetInstance(), SLOT(updateChanges()));


    connect(Character::GetInstance(), SIGNAL(updateHealth()), this, SLOT(updateHealth()));
    connect(Character::GetInstance(), SIGNAL(updateHappiness()), this, SLOT(updateHappiness()));

    ui->healthBar->setValue(Character::GetInstance()->getHealth());
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());

}

Relationship::~Relationship()
{
    delete ui;
}

void Relationship::on_pushButton_8_clicked()
{
    emit(OpenMainWindow());
    close();
}

void Relationship::updateHealth()
{
    ui->healthBar->setValue(Character::GetInstance()->getHealth());
}

void Relationship::updateHappiness() {
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());
}

void Relationship::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton->hide();
    ui->pushButton_2->setEnabled(true);
    Character::GetInstance()->setRelationship("Девушка");
    emit updateRelationshipSignal();
}


void Relationship::on_pushButton_2_clicked()
{
    ui->pushButton->show();
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->hide();
    ui->pushButton_3->setEnabled(true);
    Character::GetInstance()->setRelationship("Жена");
    emit updateRelationshipSignal();
}


void Relationship::on_pushButton_3_clicked()
{
    ui->pushButton_2->show();
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_3->hide();
    ui->pushButton_4->setEnabled(true);
    Character::GetInstance()->setRelationship("Жена + ребенок");
    emit updateRelationshipSignal();
}


void Relationship::on_pushButton_4_clicked()
{
    ui->pushButton_3->show();
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_4->hide();
    Character::GetInstance()->setRelationship("Жена + 2 ребенка");
    emit updateRelationshipSignal();
}

