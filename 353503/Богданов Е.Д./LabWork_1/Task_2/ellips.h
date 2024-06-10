#ifndef ELLIPS_H
#define ELLIPS_H

#include "poligonchik.h"

class Ellips : public Poligonchik
{

public:
    explicit Ellips(QPointF point_first);
    QString Perim() override;
    QString Plohchad() override;
    QString Zenter_mass() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    double zenter_mass_x, zenter_mass_y;
};

#endif // ELLIPS_H
