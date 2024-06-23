#include "hexagon.h"
#include <QPainter>
Hexagon::Hexagon(QPointF point, QObject *parent) :
    Figure(point,parent)
{

}

Hexagon::~Hexagon()
{

}

// Реализуем метод отрисовки
void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    points.resize(6);
    QPolygonF polygon;
    QPointF center = (startPoint() + endPoint()) / 2.0; // Центр шестиугольника
    double radius = (endPoint() - startPoint()).manhattanLength() / 2.0; // Радиус шестиугольника

    for(int i = 0; i < 6; ++i) {
        double angle = 60 * i; // Угол в градусах
        double x = center.x() + radius * cos(qDegreesToRadians(angle));
        double y = center.y() + radius * sin(qDegreesToRadians(angle));
        polygon << QPointF(x, y);
    }

    painter->drawPolygon(polygon);

}
