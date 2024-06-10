#ifndef EUGHT_STAR_H
#define EUGHT_STAR_H

#include "poligonchik.h"

class Eught_star : public Poligonchik
{
public:
    explicit Eught_star(QPointF point_first);
    QString Perim() override;
    QString Plohchad() override;
    QString Zenter_mass() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    double perim = 0, ploshad = 0, first_inpoint_x, first_inpoint_y, last_inpoint_x, last_inpoint_y,
           zentr_mass_x, zentr_mass_y, rebro;
};

#endif // EUGHT_STAR_H
