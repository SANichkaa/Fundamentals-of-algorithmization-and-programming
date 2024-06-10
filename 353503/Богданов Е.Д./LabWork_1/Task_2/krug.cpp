#include "krug.h"

Krug::Krug(QPointF point_first)
{
    point1=point_first;
    point2=point1;
}

QString Krug::Perim()
{
    return QString::fromStdString(std::to_string(2*acos(-1)*r));
}

QString Krug::Plohchad()
{
    return QString::fromStdString(std::to_string(acos(-1)*r*r));
}

QString Krug::Zenter_mass()
{
    zenter_mass_x = point1.x()+r;
    zenter_mass_y = point1.y()+r;

    return QString::fromStdString(std::to_string(zenter_mass_x)+';'+std::to_string(zenter_mass_y));
}

void Krug::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    r = point2.x()-point1.x()>point2.y()-point1.y() ? point2.x()-point1.x() : point2.y()-point1.y();

    painter->drawEllipse(point1.x(), point1.y(), r, r);

}
