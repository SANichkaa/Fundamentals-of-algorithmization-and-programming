#include "fife_star.h"

Fife_star::Fife_star(QPointF point_first)
{
    point1 = point_first;
    point2 = point1;
}

QString Fife_star::Perim()
{
    return QString::fromStdString(std::to_string(perim));
}

QString Fife_star::Plohchad()
{
    return QString::fromStdString(std::to_string(ploshad));
}

QString Fife_star::Zenter_mass()
{
    return QString::fromStdString(std::to_string(zentr_mass_x) + ';' + std::to_string(zentr_mass_y));
}

void Fife_star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(*option)
    Q_UNUSED(*widget)

    const int koef_outerRadius = 13;
    const int koef_innerRadius = 5;

    int outerRadius = koef_outerRadius * sqrt(qFabs(point2.x() - point1.x()));
    int innerRadius = koef_innerRadius * sqrt(qFabs(point2.x() - point1.x()));

    perim = 0;
    ploshad = 0;

    const int kolvo_yglov = 5;
    const int kolvo_treug = 10;

    const int last_point = 4;

    const double pi = acos(-1);
    const double angleStep = 2 * pi / kolvo_yglov;
    const double startAngle = pi / 2;

    QVector<QPoint> points;

    for (int i = 0; i < kolvo_yglov; ++i) {
        double angle = startAngle + i * angleStep;
        int outerX = point1.x() + outerRadius * qCos(angle);
        int outerY = point1.y() - outerRadius * qSin(angle);
        int innerX = point1.x() + innerRadius * qCos(angle + angleStep / 2);
        int innerY = point1.y() - innerRadius * qSin(angle + angleStep / 2);

        points.append(QPoint(outerX, outerY));
        points.append(QPoint(innerX, innerY));

        perim += sqrt(pow(innerX - outerX, 2) + pow(innerY - outerY, 2));

        if (i == 0) {
            first_inpoint_x = innerX;
            first_inpoint_y = innerY;
            rebro = sqrt(pow(innerX - outerX, 2) + pow(innerY - outerY, 2));
        }

        if (i == last_point) {
            last_inpoint_x = innerX;
            last_inpoint_y = innerY;
        }
    }

    double storona = sqrt(pow(last_inpoint_x - first_inpoint_x, 2)
                          + pow(last_inpoint_y - first_inpoint_y, 2));

    double polyperim = perim / 2;

    ploshad = kolvo_treug
              * sqrt(polyperim * (polyperim - rebro) * (polyperim - rebro) * (polyperim - storona));

    zentr_mass_x = (last_inpoint_x + first_inpoint_x) / 2;

    zentr_mass_y = last_inpoint_y + sqrt(rebro * rebro - storona * storona / 4);

    painter->drawPolygon(QPolygon(points));
}
