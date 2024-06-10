#include "poligonchik.h"

Poligonchik::Poligonchik() = default;

QRectF Poligonchik::boundingRect() const
{
    return {point1.x()>point2.x() ? point2.x() : point1.x(), point1.y()>point2.y() ? point2.y() : point1.y()
                  , qFabs(point2.x()-point1.x()), qFabs(point2.y()-point1.y())};
}

void Poligonchik::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

QString Poligonchik::Perim()
{
    return "--";
}

QString Poligonchik::Plohchad()
{
    return "--";
}

QString Poligonchik::Zenter_mass()
{
    return "--";
}

