#include "Hero.h"

#include <QGraphicsScene>


Hero::Hero(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    DisplayHero();

}

void Hero::DisplayHero() {
    QPixmap oPixmap(":/images/Hero.png");
    setPixmap(oPixmap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
}
