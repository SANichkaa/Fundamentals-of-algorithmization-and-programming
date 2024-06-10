#ifndef RECTIC_H
#define RECTIC_H

#include "poligonchik.h"

class Rectic : public Poligonchik
{
public:
    Rectic();
    explicit Rectic(QPointF point_firs);
    QString Perim() override;
    QString Plohchad() override;
    QString Zenter_mass() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    double zenter_mass_x{}, zenter_mass_y{};
};

#endif // RECTIC_H
