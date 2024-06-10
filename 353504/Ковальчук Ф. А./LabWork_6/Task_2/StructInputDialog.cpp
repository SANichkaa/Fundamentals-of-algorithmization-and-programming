#include "StructInputDialog.h"
#include "ui_StructInputDialog.h"

StructInputDialog::StructInputDialog(QWidget *parent, Plant* pPlant) :
    QDialog(parent), ui(new Ui::StructInputDialog),
    pPlant(pPlant)
{
    ui->setupUi(this);
    ui->lineEdit->setMaxLength(15);
}

StructInputDialog::~StructInputDialog()
{
    delete ui;
}

void StructInputDialog::on_buttonBox_accepted()
{
    QString name = ui->lineEdit->text();
    for (int i = 0; i < name.length() && i < 15; ++i)
    {
        pPlant->name[i] = name.at(i).toLatin1();
    }

    pPlant->name[15] = 0;

    pPlant->daysOfGrowing = ui->DaysGrows->value();
    pPlant->height = ui->Height->value();
    pPlant->isFlowering = ui->Cvetet->isChecked();
    close();
}

