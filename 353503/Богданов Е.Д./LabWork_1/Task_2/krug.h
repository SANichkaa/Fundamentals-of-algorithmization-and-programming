#ifndef KRUG_H
#define KRUG_H

#include "poligonchik.h"

class Krug : public Poligonchik
{
public:
    explicit Krug(QPointF point_first);
    QString Perim() override;
    QString Plohchad() override;
    QString Zenter_mass() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    double r;
    double zenter_mass_x, zenter_mass_y;
};

#endif // KRUG_H
