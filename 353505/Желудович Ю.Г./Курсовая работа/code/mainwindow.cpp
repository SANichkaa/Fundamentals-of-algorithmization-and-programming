#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    start_page = new StartPage();
    character = Character::GetInstance();

    connect(start_page, &StartPage::newGameStarted, this, &MainWindow::Start_new_game);
    connect(start_page, &StartPage::gameLoaded, this, &MainWindow::Load_game);

    start_page -> show();

    clothesWindow = new Clothes();
    connect(clothesWindow, &Clothes::OpenMainWindow , this, &MainWindow::OpenWindow);

    happinessWindow = new Happiness();
    connect(happinessWindow, &Happiness::OpenMainWindow , this, &MainWindow::OpenWindow);

    healthWindow = new Health();
    connect(healthWindow, &Health::OpenMainWindow , this, &MainWindow::OpenWindow);

    housingWindow = new Housing();
    connect(housingWindow, &Housing::OpenMainWindow, this, &MainWindow::OpenWindow);

    relationshipWindow = new Relationship();
    connect(relationshipWindow, &Relationship::OpenMainWindow, this, &MainWindow::OpenWindow);

    transportWindow = new Transport();
    connect(transportWindow, &Transport::OpenMainWindow, this, &MainWindow::OpenWindow);

    foodWindow = new Food();
    connect(foodWindow, &Food::OpenMainWindow, this, &MainWindow::OpenWindow);

    jobWindow = new Job();
    connect(jobWindow, &Job::OpenMainWindow, this, &MainWindow::OpenWindow);

    casinoWindow = new Casino();
    connect(casinoWindow, &Casino::OpenMainWindow, this, &MainWindow::OpenWindow);

    connect(Character::GetInstance(), SIGNAL(updateHealth()), this, SLOT(updateHealth()));
    connect(Character::GetInstance(), SIGNAL(updateHappiness()), this, SLOT(updateHappiness()));
    connect(Character::GetInstance(), SIGNAL(updateMoney()), this, SLOT(updateMoney()));
    connect(Character::GetInstance(), SIGNAL(updateAge()), this, SLOT(updateAge()));
    connect(Character::GetInstance(), SIGNAL(updateJob()), this, SLOT(updateJob()));
    connect(Character::GetInstance(), SIGNAL(updateClothes()), this, SLOT(updateClothes()));
    connect(Character::GetInstance(), SIGNAL(updateHousing()), this, SLOT(updateHousing()));
    connect(Character::GetInstance(), SIGNAL(updateFood()), this, SLOT(updateFood()));
    connect(Character::GetInstance(), SIGNAL(updateRelationship()), this, SLOT(updateRelationship()));
    connect(Character::GetInstance(), SIGNAL(updateTransport()), this, SLOT(updateTransport()));
    connect(Character::GetInstance(), SIGNAL(updateIncome()), this, SLOT(updateIncome()));
    connect(Character::GetInstance(), SIGNAL(updateExpenses()), this, SLOT(updateExpenses()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Load_game(){
    ui->healthBar->setValue(Character::GetInstance()->getHealth());
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());
    ui->moneyLabel->setText(QString::number(Character::GetInstance()->getMoney())+" $");
    ui->ageLabel->setText(QString::number(Character::GetInstance()->getAge()) + " лет");
    ui->jobLabel->setText("Должность: " + QString(Character::GetInstance()->getJob()));
    ui->clothesLabel->setText("Одежда: " + QString(Character::GetInstance()->getClothing()));
    ui->foodLabel->setText("Питание: " + QString(Character::GetInstance()->getFood()));
    ui->housingLabel->setText("Жилье: " + QString(Character::GetInstance()->getHousing()));
    ui->transportLabel->setText("Транспорт: " + QString(Character::GetInstance()->getTransport()));
    ui->relationshipLabel->setText("Семейное положение: " + QString(Character::GetInstance()->getRelationship()));
    ui->incomeLabel->setText("Доход в месяц: " + QString::number(Character::GetInstance()->getMonthlyIncome()) + " $");
    ui->expensesLabel->setText("Расходы в месяц: " + QString::number(Character::GetInstance()->getMonthlyExpenses()) + " $");

    show();
    start_page -> hide();
}

void MainWindow::Start_new_game(){
    Load_game();

    show();
    start_page -> hide();
}
void MainWindow::on_findClothes_clicked()
{
    clothesWindow->show();
    hide();
}

void MainWindow::OpenWindow(){
    character -> saveCharacterData();
    show();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    QPoint widgetPos = ui->happinessBar->pos();
    int width = ui->happinessBar->width();


    int height = ui->happinessBar->height();

    int x = event->pos().x();
    int y = event->pos().y();

    if(x >= widgetPos.x() && x <= (widgetPos.x() + width))
    {

        if(y >= widgetPos.y() + 90 && y <= (widgetPos.y() + height + 90) )
        {
            happinessWindow->show();
            hide();
        }
    }

    QPoint widgetPos_2 = ui->healthBar->pos();
    int width_2 = ui->healthBar->width();


    int height_2 = ui->healthBar->height();

    int x_2 = event->pos().x();
    int y_2 = event->pos().y();

    if(x_2 >= widgetPos_2.x() && x_2 <= (widgetPos_2.x() + width_2))
    {

        if(y_2 >= widgetPos_2.y() + 90 && y_2 <= (widgetPos_2.y() + height_2 + 90) )
        {
            healthWindow->show();
            hide();
        }
    }
}


void MainWindow::on_findWork_clicked()
{
    jobWindow->show();
    hide();
}


void MainWindow::on_findHousing_clicked()
{
    housingWindow->show();
    hide();
}


void MainWindow::on_findTransport_clicked()
{
    transportWindow->show();
    hide();
}


void MainWindow::on_findRelationship_clicked()
{
    relationshipWindow->show();
    hide();
}


void MainWindow::on_findFood_clicked()
{
    foodWindow->show();
    hide();
}

void MainWindow::updateHealth()
{
    ui->healthBar->setValue(Character::GetInstance()->getHealth());
    character -> saveCharacterData();

    checkGameOver();
    healthReminder();
}

void MainWindow::updateHappiness() {
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());
    character -> saveCharacterData();

    checkGameOver();
    happinessReminder();
}

void MainWindow::updateMoney() {
    ui->moneyLabel->setText(QString::number(Character::GetInstance()->getMoney())+" $");
    if(Character::GetInstance()->getMoney() <= 0) {
        Character::GetInstance()->setMoney(0);

    }
    character -> saveCharacterData();

    checkGameOver();
}

void MainWindow::updateAge() {
    ui->ageLabel->setText(QString::number(Character::GetInstance()->getAge())+ " лет");
    character -> saveCharacterData();
    checkGameOver();
}

void MainWindow::updateJob() {
    ui->jobLabel->setText("Должность: " + QString(Character::GetInstance()->getJob()));
    character -> saveCharacterData();
}

void MainWindow::updateClothes() {
    qDebug() << character -> getClothing();

    ui->clothesLabel->setText("Одежда: " + QString(Character::GetInstance()->getClothing()));

    qDebug() << character -> getClothing();

    character -> saveCharacterData();
}

void MainWindow::updateFood() {
    ui->foodLabel->setText("Питание: " + QString(Character::GetInstance()->getFood()));
    character -> saveCharacterData();
}

void MainWindow::updateHousing() {
    ui->housingLabel->setText("Жилье: " + QString(Character::GetInstance()->getHousing()));
    character -> saveCharacterData();
}

void MainWindow::updateTransport() {
    ui->transportLabel->setText("Транспорт: " + QString(Character::GetInstance()->getTransport()));
    character -> saveCharacterData();
}

void MainWindow::updateRelationship() {
    ui->relationshipLabel->setText("Семейное положение: " + QString(Character::GetInstance()->getRelationship()));
    character -> saveCharacterData();
}

void MainWindow::updateIncome() {
    ui->incomeLabel->setText("Доход в месяц: " + QString::number(Character::GetInstance()->getMonthlyIncome()) + " $");
    character -> saveCharacterData();
}

void MainWindow::updateExpenses() {
    ui->expensesLabel->setText("Расходы в месяц: " + QString::number(Character::GetInstance()->getMonthlyExpenses()) + " $");
    character -> saveCharacterData();
}

void MainWindow::happinessReminder() {
    if (Character::GetInstance()->getHappiness() >= 30) {
        countHappiness = 0;
    }
    if (countHappiness == 0 && Character::GetInstance()->getHappiness() < 30) {
        QMessageBox::information(nullptr, "Мало счастья!", "У вашего персонажа низкий уровень счастья, ему очень грустно!");
        countHappiness++;
    }
}

void MainWindow::healthReminder() {
    if (Character::GetInstance()->getHealth() >= 20) {
        countHealth = 0;
    }
    if (countHealth == 0 &&  Character::GetInstance()->getHealth() < 20) {
        QMessageBox::information(nullptr, "Мало здоровья!", "У вашего персонажа низкий уровень здоровья, так и умереть можно!");
        countHealth++;
    }

}

void MainWindow::checkGameOver() {

    if (Character::GetInstance()->getHealth() == 0) {
        QMessageBox::information(nullptr, "Игра завершена!", "У вашего персонажа закончилось здоровье.");
        QCoreApplication::quit();
    }

    if (Character::GetInstance()->getHappiness() == 0) {
        QMessageBox::information(nullptr, "Игра завершена!", "У вашего персонажа закончилось счастье.");
        QCoreApplication::quit();
    }

    if (Character::GetInstance()->getMoney() == 0) {
        QMessageBox::information(nullptr, "Игра завершена!", "У вашего персонажа закончились деньги.");
        QCoreApplication::quit();
    }

    if (Character::GetInstance()->getAge() == 50) {
        QMessageBox::information(nullptr, "Игра завершена!", "Ваш персонаж умер от старости.");
        QCoreApplication::quit();
    }
}


void MainWindow::on_playCasino_clicked()
{
    casinoWindow->show();
    hide();
}
