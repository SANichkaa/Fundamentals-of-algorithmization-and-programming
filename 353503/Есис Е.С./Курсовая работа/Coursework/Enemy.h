#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Enemy : public QObject, public QGraphicsPixmapItem
{
public:
    Enemy(QGraphicsItem *parent = nullptr);

private:
    void DisplayEnemy();
};

#endif // ENEMY_H
