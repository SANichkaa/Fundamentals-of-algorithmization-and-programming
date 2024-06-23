#ifndef HERO_H
#define HERO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Hero : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Hero(QGraphicsItem *parent = nullptr);
    bool condision = false;

private:
    void DisplayHero();
};

#endif // HERO_H
