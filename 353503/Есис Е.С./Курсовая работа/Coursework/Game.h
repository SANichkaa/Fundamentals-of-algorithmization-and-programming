#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>

#include "Hero.h"
#include "Enemy.h"
#include "Properties.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QSize sizeOfScreen, QGraphicsView *parent = nullptr);
    void displayMainMenu();
    size_t destroyesEnemies = 0;

protected:
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void Start();

private:
    void emergeFromOtherEnd();
    void removeEnemyOnCapture();
    void DisplayEnemies();
    QSize getRandomPos();
    Enemy* createNewEnemy();

    QSize screenSize;
    Hero* hero = nullptr;
    size_t enemies = maxEnemies;
    QGraphicsScene *scene;

};

#endif // GAME_H
