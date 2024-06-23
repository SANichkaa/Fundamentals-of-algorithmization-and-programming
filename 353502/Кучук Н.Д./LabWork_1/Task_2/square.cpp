#include "square.h"
#include <QPainter>

Square::Square(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Square::~Square()
{

}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));
    qreal x1, x2, y1, y2;
    x1 = endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x();
    x2 = qAbs(endPoint().x() - startPoint().x());
    y1 = endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y();
    y2 = qAbs(endPoint().y() - startPoint().y());

    QRectF rect(x1, y1, x2, y2);

    painter->drawRect(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

