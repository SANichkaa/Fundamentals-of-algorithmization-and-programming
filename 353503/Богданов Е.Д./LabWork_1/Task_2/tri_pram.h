#ifndef TRI_PRAM_H
#define TRI_PRAM_H

#include "poligonchik.h"

class Tri_pram : public Poligonchik
{
public:

    Tri_pram();
    explicit Tri_pram(QPointF point_first);
    QString Perim() override;
    QString Plohchad() override;
    QString Zenter_mass() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    double zenter_mass_x, zenter_mass_y;
};

#endif // TRI_PRAM_H
