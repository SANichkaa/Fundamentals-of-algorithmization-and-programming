#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , pPlant(new Plant)
{
    ui->setupUi(this);
    on_nextButton_clicked();

    plantInit = Plant();
    plantFields = Plant();
    plantKeyboard = Plant();
    refPlant = Plant();
}

void MainWindow::on_nextButton_clicked()
{
    if(plantIndex == 4){
        plantIndex = 0;
    }
    else{
        plantIndex++;
    }
    Plant* tmpPlant;
    switch(plantIndex){
    case 0:
        tmpPlant = &plantInit;
        break;
    case 1:
        tmpPlant = &plantFields;
        break;
    case 2:
        tmpPlant = &plantKeyboard;
        break;
    case 3:
        tmpPlant = pPlant;
        break;
    case 4:
        tmpPlant = &refPlant;
        break;
    }

    ui->nameEdit->setText(tmpPlant->name[plantIndex]);
    ui->flowersNumBox->setValue(tmpPlant->flowersNum[plantIndex]);
    ui->daysBox->setValue(tmpPlant->daysOfGrowing);
    ui->heightBox->setValue(tmpPlant->height);

    switch (tmpPlant->plantGender) {
    case 'M':

        ui->mBox->setCheckState(Qt::CheckState::Checked);
        ui->fBox->setCheckState(Qt::CheckState::Unchecked);
        ui->tBox->setCheckState(Qt::CheckState::Unchecked);
        break;
    case 'F':
        ui->mBox->setCheckState(Qt::CheckState::Unchecked);
        ui->fBox->setCheckState(Qt::CheckState::Checked);
        ui->tBox->setCheckState(Qt::CheckState::Unchecked);
        break;
    case 'T':
        ui->mBox->setCheckState(Qt::CheckState::Unchecked);
        ui->fBox->setCheckState(Qt::CheckState::Unchecked);
        ui->tBox->setCheckState(Qt::CheckState::Checked);
        break;
    default:
        tmpPlant->plantGender = 'M';
        ui->mBox->setCheckState(Qt::CheckState::Checked);
        ui->fBox->setCheckState(Qt::CheckState::Unchecked);
        ui->tBox->setCheckState(Qt::CheckState::Unchecked);
        break;
    }

    ui->growingBox->setCheckState(tmpPlant->isFlowering ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
}

MainWindow::~MainWindow()
{
    delete pPlant;
    delete ui;
}

void MainWindow::on_pushInputButton_clicked()
{
    int inpDaysOfGrowing = ui->daysBox->value();
    double inpHeight = ui->heightBox->value();
    char inpPlantGender;
    if(ui->mBox->isChecked()){
        inpPlantGender = 'M';
    }
    if(ui->fBox->isChecked()){
        inpPlantGender = 'F';
    }
    if(ui->tBox->isChecked()){
        inpPlantGender = 'T';
    }
    Plant::flowersNum[plantIndex] = ui->flowersNumBox->value();
    bool inpIsFlowering = ui->growingBox->isChecked();

    Plant* tmpPlant = nullptr;
    switch (plantIndex) {
    case 0:
        plantInit = Plant(inpDaysOfGrowing, inpHeight, inpPlantGender, inpIsFlowering);
        tmpPlant = &plantInit;
        break;
    case 1:
        plantFields = Plant();
        plantFields.daysOfGrowing = inpDaysOfGrowing;
        plantFields.height = inpHeight;
        plantFields.plantGender = inpPlantGender;
        plantFields.isFlowering = inpIsFlowering;
        tmpPlant = &plantFields;
        break;
    case 2:
        plantKeyboard = Plant(inpDaysOfGrowing, inpHeight, inpPlantGender, inpIsFlowering);
        tmpPlant = &plantKeyboard;
        break;
    case 3:
        pPlant->daysOfGrowing = inpDaysOfGrowing;
        pPlant->height = inpHeight;
        pPlant->plantGender = inpPlantGender;
        pPlant->isFlowering = inpIsFlowering;
        tmpPlant = pPlant;
        break;
    case 4:
        Plant& ref = refPlant;
        ref.daysOfGrowing = inpDaysOfGrowing;
        ref.height = inpHeight;
        ref.plantGender = inpPlantGender;
        ref.isFlowering = inpIsFlowering;
        tmpPlant = &ref;
        break;
    }

    ui->textEdit->setText("Name: " + Plant::name[plantIndex] + " | " + "Flowers count: "
                          + QString::number(Plant::flowersNum[plantIndex]) + " | " + tmpPlant->plantToString());
}




void MainWindow::on_mBox_clicked()
{
    ui->fBox->setCheckState(Qt::CheckState::Unchecked);
    ui->tBox->setCheckState(Qt::CheckState::Unchecked);
}


void MainWindow::on_fBox_clicked()
{
    ui->mBox->setCheckState(Qt::CheckState::Unchecked);
    ui->tBox->setCheckState(Qt::CheckState::Unchecked);
}


void MainWindow::on_tBox_clicked()
{
    ui->fBox->setCheckState(Qt::CheckState::Unchecked);
    ui->mBox->setCheckState(Qt::CheckState::Unchecked);
}

