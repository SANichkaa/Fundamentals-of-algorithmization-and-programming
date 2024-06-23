#include "Game.h"
#include "Hero.h"
#include "Properties.h"
#include "Button.h"

#include <QWidget>
#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <random>
#include <QMessageBox>

Game::Game(QSize sizeOfScreen, QGraphicsView *parent)
    : QGraphicsView(parent),
    screenSize(sizeOfScreen)
{
    scene = new QGraphicsScene();
    setScene(scene);

    scene->setSceneRect(0,0,screenSize.width(),screenSize.height());
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Game::displayMainMenu()
{
    //create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Brotato"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    //create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton, &Button::clicked, this, &Game::Start);

    scene->addItem(playButton);

    //create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton, &Button::clicked, this, &Game::close);
    scene->addItem(quitButton);
}

void Game::Start() {
    scene->clear();
    setBackgroundBrush(QBrush(QImage(":/images/Background.jpg")));

    hero = new Hero();
    hero->setPos(screenSize.width() / 2, screenSize.height() / 2);
    hero->setFocus();
    scene->addItem(hero);

    DisplayEnemies();
}

void Game::keyPressEvent(QKeyEvent *event) {
    if ( hero == nullptr) return;

    switch (event->key()) {
    case Qt::Key_Up : {
        emergeFromOtherEnd();
        removeEnemyOnCapture();
         hero->setPos( hero->x() ,  hero->y() - speed);
        break;
    }
    case Qt::Key_Down: {
        emergeFromOtherEnd();
        removeEnemyOnCapture();
         hero->setPos( hero->x() ,  hero->y() + speed);
        break;
    }
    case Qt::Key_Left: {
        removeEnemyOnCapture();
        if(hero->condision){
         hero->setPixmap( hero->pixmap().transformed(QTransform().scale(-1, 1)));
             hero->condision = false;
        }
         hero->setPos( hero->x() - speed,  hero->y());
        break;
    }
    case Qt::Key_Right: {
        removeEnemyOnCapture();

        if(! hero->condision){
             hero->setPixmap( hero->pixmap().transformed(QTransform().scale(-1, 1)));
             hero->condision = true;
        }
         hero->setPos( hero->x() + speed ,  hero->y());
        break;
        }
    }
}

void Game::emergeFromOtherEnd() {
    int xCoordinate =  hero->x();
    int yCoordinate =  hero->y();

    if (xCoordinate < 0 && yCoordinate >= 0) {
        // went off from left side
         hero->setPos(screenSize.width(),  hero->y());
    }
    else if (xCoordinate >=0 && yCoordinate < 0) {
        // went off from top side
         hero->setPos( hero->x(), screenSize.height());
    } else if (xCoordinate >= screenSize.width() \
               && yCoordinate >=0 \
               && yCoordinate < screenSize.height()) {
        // went off from right side
         hero->setPos(0,  hero->y());
    } else if (yCoordinate >= screenSize.height() \
               && xCoordinate >= 0 \
               && xCoordinate < screenSize.width()) {
        //went off from bottom side
         hero->setPos( hero->x(), 0);
    }
}

void Game::DisplayEnemies() {
    for (auto i = 0; i < maxEnemies; i++) {
        scene->addItem(createNewEnemy());
    }
}

QSize Game::getRandomPos() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dsWidth(0, screenSize.width() - 50);
    std::uniform_int_distribution<int> dsHeight(0, screenSize.height() - 50);
    int x = dsWidth(mt);
    int y = dsHeight(mt);
    QSize *size = new QSize(x,y);
    return *size;
}

void Game::removeEnemyOnCapture() {
    for (auto const item :  hero->collidingItems()) {
        Enemy* enemy = dynamic_cast<Enemy*>(item);
        if (enemy != nullptr) {
            scene->removeItem(enemy);
            destroyesEnemies++;
            std::srand(time(nullptr));
            long long random = destroyesEnemies % 10 - rand() % 10;
            if(random < 1) random = 1;
            for(auto i = random ; i > 0; --i){
                enemies++;
                scene->addItem(createNewEnemy());
            }
            if(destroyesEnemies > 15)
                QMessageBox::information(nullptr, "Сообщение", "You killed 15 enemies and win! ");

        }
    }
}

Enemy* Game::createNewEnemy() {
    Enemy* newEnemy = new Enemy();
    QSize pos = getRandomPos();
    newEnemy->setPos(pos.width(), pos.height());
    newEnemy->setFocus();
    return newEnemy;
}
