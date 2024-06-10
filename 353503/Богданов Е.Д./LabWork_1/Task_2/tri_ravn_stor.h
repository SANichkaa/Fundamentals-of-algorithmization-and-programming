#ifndef TRI_RAVN_STOR_H
#define TRI_RAVN_STOR_H

#include "tri_ravn_bedr.h"

class Tri_ravn_stor : public Tri_pram
{
public:
    explicit Tri_ravn_stor(QPointF point_first);
    QString Perim() override;
    QString Plohchad() override;
    QString Zenter_mass() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    double zenter_mass_x, zenter_mass_y;
    double storona = sqrt(qAbs(point2.y()-point1.y())*qAbs(point2.x()-point1.x()));
};

#endif // TRI_RAVN_STOR_H
