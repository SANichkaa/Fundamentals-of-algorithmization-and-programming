#ifndef SQUART_H
#define SQUART_H

#include <QGraphicsItem>
#include <QPoint>
#include <QPainter>
#include <QObject>
#include "rectic.h"

class Squart : public Rectic
{
public:
    explicit Squart(QPointF point_first);
    QString Perim() override;
    QString Plohchad() override;
    QString Zenter_mass() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    double zenter_mass_x, zenter_mass_y;
};

#endif // SQUART_H
