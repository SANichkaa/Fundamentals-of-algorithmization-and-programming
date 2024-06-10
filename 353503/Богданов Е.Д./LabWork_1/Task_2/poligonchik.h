#ifndef POLIGONCHIK_H
#define POLIGONCHIK_H

#include <QGraphicsItem>
#include <QPoint>
#include <QPainter>
#include <QObject>
#include <QPolygon>
#include <string>

class Poligonchik : public QGraphicsItem
{
public:
    Poligonchik();
    explicit Poligonchik(QPointF point_first);
    virtual QString Perim();
    virtual QString Plohchad();
    virtual QString Zenter_mass();
    QPointF point1, point2;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // POLIGONCHIK_H
