#include "tri_pram.h"

Tri_pram::Tri_pram() = default;
Tri_pram::Tri_pram(QPointF point_first)
{
    point1=point_first;
    point2 = point1;
}

QString Tri_pram::Perim()
{
    return QString::fromStdString(std::to_string(qAbs(point2.y()-point1.y())+qAbs(point2.x()-point1.x())+sqrt(qAbs(point2.x()-point1.x())*qAbs(point2.y()-point1.y()))));
}

QString Tri_pram::Plohchad()
{
    return QString::fromStdString(std::to_string((qAbs(point2.y()-point1.y())*qAbs(point2.x()-point1.x()))/2));
}

QString Tri_pram::Zenter_mass()
{
    zenter_mass_x = point1.x()+point2.x()/3;
    zenter_mass_y = point2.y()+point1.y()/3;

    return QString::fromStdString(std::to_string(zenter_mass_x)+';'+std::to_string(zenter_mass_y));
}

void Tri_pram::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPolygon pol;
    pol<<QPoint(point1.x(), point1.y())<<QPoint(point2.x(),point2.y())<<QPoint(point1.x(), point2.y());
    painter->drawPolygon(pol);
}
