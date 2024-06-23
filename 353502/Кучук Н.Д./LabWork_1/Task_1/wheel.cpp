#include "wheel.h"
#include <QPainter>

Wheel::Wheel(QGraphicsItem *parent) : QGraphicsObject(parent), rotationAngle(0) {
    radius = 100;
    numSpokes = 12;

    outerCircle = QRectF(-radius, -radius, 2 * radius, 2 * radius);

    double angleDelta = 2 * M_PI / numSpokes;

    for (int i = 0; i < numSpokes; ++i) {
        double angle = i * angleDelta;
        double x1 = radius * cos(angle);
        double y1 = radius * sin(angle);
        double x2 = radius * cos(angle + M_PI);
        double y2 = radius * sin(angle + M_PI);
        spokes.append(QLineF(x1, y1, x2, y2));
    }
}

QRectF Wheel::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(-radius - penWidth / 2, -radius - penWidth / 2,
                  2 * radius + penWidth, 2 * radius + penWidth);
}

void Wheel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setBrush(Qt::gray);
    painter->drawEllipse(outerCircle);

    painter->setPen(QPen(Qt::black, 2));
    for (const auto &spoke : spokes) {
        painter->drawLine(spoke);
    }
}

void Wheel::advance(int step) {
    if (!step)
        return;
    rotationAngle += 3;
    setRotation(rotationAngle);
}
