#include "star6.h"
#include <QPainter>

Star6::Star6(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Star6::~Star6()
{

}

void Star6::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    int n = 6;
    QPolygonF polygon;
    points.resize(n * 2);
    qreal xp = startPoint().x(),
        xn = endPoint().x(),
        yp = startPoint().y(),
        yn = endPoint().y();


    qreal max = qMax(qAbs(xp - xn), qAbs(yp - yn));
    xp > xn ? xn = xp - max : xn = xp + max;
    yp > yn ? yn = yp - max : yn = yp + max;


    qreal b = (xn - xp) / 2,
        a = (yn - yp) / 2;

    qreal xc = (xp + xn) / 2,
        yc = (yp + yn) / 2;


    for (int i = 0; i < n; i++) {
        QPointF p_out, p_in;
        p_out = {
            xc - b * qSin(2 * M_PI / n * i),
            yc - a * qCos(2 * M_PI / n * i)
        };

        p_in = {
            xc - b / 2 * qSin(2 * M_PI / n * i + M_PI / n),
            yc - a / 2 * qCos(2 * M_PI / n * i + M_PI / n)
        };
        points[i * 2] = p_out;
        points[i * 2 + 1] = p_in;
    }

    for (auto point: points) {
        QPoint q = {(int) point.x(), (int) point.y()};
        polygon << q;
    }


    painter->drawPolygon(polygon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
