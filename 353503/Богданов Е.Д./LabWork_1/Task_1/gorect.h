#ifndef GORECT_H
#define GORECT_H

#include <QGraphicsView>
#include <QGraphicsScene>

class GoRect : public QGraphicsScene
{

public:

    GoRect();
    virtual void move(int step, int x, int y, bool shadow);

};

#endif // GORECT_H
