#include "Enemy.h"
#include "Properties.h"

#include <random>

Enemy::Enemy(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    DisplayEnemy();
}

void Enemy::DisplayEnemy() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dsEnemy(minEnemySize, maxEnemySize);
    srand(time(nullptr));
    size_t i = rand() % 3 + 1;
    QString pathEnemy = QString(":/images/Enemy%1.png").arg(i);
    QPixmap oPixmap(pathEnemy);
    int size = dsEnemy(mt);
    setPixmap(oPixmap.scaled(QSize(size, size), Qt::KeepAspectRatio));
}
