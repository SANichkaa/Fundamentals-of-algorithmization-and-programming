#include "startpage.h"
#include <QMessageBox>
#include "character.h"

StartPage::StartPage(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *newGameButton = new QPushButton("НОВАЯ ИГРА", this);
    newGameButton->setFixedSize(880, 200);
    QPushButton *loadButton = new QPushButton("ЗАГРУЗИТЬ ИГРУ", this);
    loadButton->setFixedSize(880, 200);

    layout->addWidget(newGameButton);
    layout->addWidget(loadButton);

    setWindowTitle("Меню игры");
    resize(900, 800);

    connect(loadButton, &QPushButton::clicked, this, &StartPage::loadGame);
    connect(newGameButton, &QPushButton::clicked, this, &StartPage::newGame);
}

void StartPage::loadGame() {
    Character *character = Character::GetInstance();

    if (character->loadCharacterData()) {
        character->loadCharacterData();
        QMessageBox::information(this, "Загрузка игры", "Данные персонажа успешно загружены.");
        emit gameLoaded();
    }
    else {
        QMessageBox::warning(this, "Загрузка игры", "Не удалось загрузить данные персонажа.");
    }
}

void StartPage::newGame() {
    Character *character = Character::GetInstance();

    character->setAge(18);
    character->setHealth(100);
    character->setHappiness(100);
    character->setMoney(1000);
    character->setMonthlyIncome(0);
    character->setMonthlyExpenses(0);
    character->setJob("Нет");
    character->setRelationship("Нет");
    character->setClothing("Нет");
    character->setFood("Нет");
    character->setHousing("Нет");
    character->setTransport("Нет");

    if (character->saveCharacterData()) {
        character->saveCharacterData();
        QMessageBox::information(this, "Новая игра", "Данные нового персонажа успешно сохранены.");
        emit newGameStarted();
    } else {
        QMessageBox::warning(this, "Новая игра", "Не удалось сохранить данные нового персонажа.");
    }
}
