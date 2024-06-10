#ifndef TRI_RAVN_BEDR_H
#define TRI_RAVN_BEDR_H

#include "tri_pram.h"

class Tri_ravn_bedr : public Tri_pram
{
public:
    explicit Tri_ravn_bedr(QPointF point_first);
    QString Perim() override;
    QString Plohchad() override;
    QString Zenter_mass() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    double zenter_mass_x, zenter_mass_y;
};

#endif // TRI_RAVN_BEDR_H
