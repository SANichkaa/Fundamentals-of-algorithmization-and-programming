#ifndef SCENKA_H
#define SCENKA_H

#include <QCursor>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QObject>
#include <QPolygonF>
#include <QString>
#include "ellips.h"
#include "eught_star.h"
#include "fife_star.h"
#include "krug.h"
#include "rectic.h"
#include "six_star.h"
#include "squart.h"
#include "tri_pram.h"
#include "tri_ravn_bedr.h"
#include "tri_ravn_stor.h"

class Scenka : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Scenka(QObject *parent = nullptr);

    void updateRect();

    void Set_figura(QString str);

    void Set_Zentr_mass(QString zenter);
    void Set_Perim(QString perim);
    void Set_Ploshad(QString ploshad);

    QString Get_Zentr_mass();
    QString Get_Perim();
    QString Get_Ploshad();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *e) override;

private:
    QPointF point_first, point_last, point_for_move, point_naklon;
    QGraphicsItem *Item;
    QGraphicsItem *item_povorot;
    Rectic *rect;
    Squart *squart;
    Tri_pram *tri_pram;
    Tri_ravn_bedr *tri_ravn_bedr;
    Tri_ravn_stor *tri_ravn_stor;
    Fife_star *fife_star;
    Eught_star *eught_star;
    Six_star *six_star;
    Ellips *ellips;
    Krug *krug;
    Poligonchik *m_poligonchik;
    QString Zentr_mass = "--";
    QString Perim = "--";
    QString Ploshad = "--";
    QString figura = "-";
    double ygol = 0;
    bool rotation = false, resize = false, move = false;
};

#endif // SCENKA_H
