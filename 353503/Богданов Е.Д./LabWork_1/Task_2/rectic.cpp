#include "rectic.h"

Rectic::Rectic() = default;

Rectic::Rectic(QPointF point_first1)
{
    point1=point_first1;
    point2 = point1;

}

void Rectic::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QRectF rect(point2.x()>point1.x() ? point1.x() : point2.x(),
                point2.y()>point1.y() ? point1.y() : point2.y(),
                qFabs(point2.x()-point1.x()), qFabs(point2.y()-point1.y()));
    painter->drawRect(rect);

}

QString Rectic::Perim()
{
    return QString::fromStdString(std::to_string(2*(qFabs(point2.x()-point1.x())+qFabs(point2.y()-point1.y()))));
}

QString Rectic::Plohchad()
{
    return QString::fromStdString(std::to_string(qAbs(point2.x()-point1.x())*qAbs(point2.y()-point1.y())));
}

QString Rectic::Zenter_mass()
{
    zenter_mass_x = (point2.x()+point1.x())/2;
    zenter_mass_y = (point2.y()+point1.y())/2;

    return QString::fromStdString(std::to_string(zenter_mass_x)+';'+std::to_string(zenter_mass_y));
}







