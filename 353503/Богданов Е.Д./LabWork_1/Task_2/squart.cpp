#include "squart.h"


Squart::Squart(QPointF point_first)
{
    point1=point_first;
    point2 = point1;
}

void Squart::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawRect(point2.x()>point1.x() ? point1.x() : point2.x(),
                      point2.y()>point1.y() ? point1.y() : point2.y(),
                      qFabs(point2.y()-point1.y()), qFabs(point2.y()-point1.y()));
}

QString Squart::Perim()
{
    return QString::fromStdString(std::to_string(4*qFabs(point2.x()-point1.x())));
}

QString Squart::Plohchad()
{
    return QString::fromStdString(std::to_string(pow(point2.y()-point1.y(), 2)));
}

QString Squart::Zenter_mass()
{
    zenter_mass_x = (point2.y()+point1.y())/2;
    zenter_mass_y = zenter_mass_x;

    return QString::fromStdString(std::to_string(zenter_mass_x)+';'+std::to_string(zenter_mass_y));
}
