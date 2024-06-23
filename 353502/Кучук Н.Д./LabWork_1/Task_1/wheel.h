#ifndef WHEEL_H
#define WHEEL_H

#include <QGraphicsObject>

class Wheel : public QGraphicsObject {
    Q_OBJECT

public:
    Wheel(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int step) override;

private:
    qreal rotationAngle;
    QRectF outerCircle;
    QVector<QLineF> spokes;
    qreal radius;
    int numSpokes;
};

#endif // WHEEL_H
