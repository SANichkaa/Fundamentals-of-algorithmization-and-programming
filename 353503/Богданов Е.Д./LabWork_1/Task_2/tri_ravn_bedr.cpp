#include "tri_ravn_bedr.h"

Tri_ravn_bedr::Tri_ravn_bedr(QPointF point_first)
{
    point1=point_first;
    point2 = point1;
}

QString Tri_ravn_bedr::Perim()
{
    return QString::fromStdString(std::to_string(2*sqrt(qAbs(point2.x()-point1.x())*qAbs(point2.y()-point1.y()))+2*qAbs(point2.x()-point1.x())));
}

QString Tri_ravn_bedr::Plohchad()
{
    return QString::fromStdString(std::to_string(qAbs(point2.x()-point1.x())*qAbs(point2.y()-point1.y())));
}

QString Tri_ravn_bedr::Zenter_mass()
{
    zenter_mass_x = point1.x();
    zenter_mass_y = point2.y()+point1.y()/3;

    return QString::fromStdString(std::to_string(zenter_mass_x)+';'+std::to_string(zenter_mass_y));
}

void Tri_ravn_bedr::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon pol;
    pol<<QPoint(point1.x(), point1.y())<<QPoint(point2.x(), point2.y())<<QPoint(2*point1.x() - point2.x(), point2.y());
    painter->drawPolygon(pol);

}
