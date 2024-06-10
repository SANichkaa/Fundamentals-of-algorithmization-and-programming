#include "tri_ravn_stor.h"

Tri_ravn_stor::Tri_ravn_stor(QPointF point_first)
{
    point1=point_first;
    point2 = point1;
}

QString Tri_ravn_stor::Perim()
{
    return QString::fromStdString(std::to_string(3*sqrt(qAbs(point2.y()-point1.y())*qAbs(point2.x()-point1.x()))));
}

QString Tri_ravn_stor::Plohchad()
{
    return QString::fromStdString(std::to_string(qAbs(point2.y()-point1.y())*qAbs(point2.x()-point1.x())*sqrt(3)/4));

}

QString Tri_ravn_stor::Zenter_mass()
{
    zenter_mass_x = point1.x();
    zenter_mass_y = point1.y()-point2.y()*2/3;

    return QString::fromStdString(std::to_string(zenter_mass_x)+';'+std::to_string(zenter_mass_y));
}

void Tri_ravn_stor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    double d = sqrt(pow(point2.x()-point1.x(), 2) + pow(point2.y()-point1.y(), 2));
    double h = d*sqrt(3)/2;
    QPolygon pol;
    pol<<QPoint(point1.x(), point1.y())<<QPoint(point1.x()+d/2, point1.y()+h)<<QPoint(point1.x()-d/2, point1.y()+h);
    painter->drawPolygon(pol);

}
