#include "ellips.h"

Ellips::Ellips(QPointF point_first)
{
    point1=point_first;
    point2=point1;
}

QString Ellips::Perim()
{
    return QString::fromStdString(std::to_string(2*acos(-1)*sqrt((pow(point2.x()-point1.x(), 2)+pow(point2.y()-point1.y(), 2))/2)));
}

QString Ellips::Plohchad()
{
    return QString::fromStdString(std::to_string(acos(-1)*qAbs(point2.x()-point1.x())*qAbs(point2.y()-point1.y())));
}

QString Ellips::Zenter_mass()
{
    zenter_mass_x=(point2.x()+point1.x())/2;
    zenter_mass_y=(point2.y()+point1.y())/2;

    return QString::fromStdString(std::to_string(zenter_mass_x)+';'+std::to_string(zenter_mass_y));

}

void Ellips::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawEllipse(point1.x(), point1.y(), point2.x()-point1.x(), point2.y()-point1.y());

}
