#include <utility>

#include "scenka.h"

Scenka::Scenka(QObject *parent)
    : QGraphicsScene{parent}
{}

void Scenka::updateRect()
{
    this->update(point_first.x() > point_last.x() ? point_last.x() : point_first.x(),
                 point_first.y() > point_last.y() ? point_last.y() : point_first.y(),
                 qFabs(point_last.x() - point_first.x()),
                 qFabs(point_last.y() - point_first.y()));
}

void Scenka::Set_figura(QString str)
{
    figura = std::move(str);
}

void Scenka::Set_Zentr_mass(QString zenter)
{
    Zentr_mass = std::move(zenter);
}

void Scenka::Set_Perim(QString perim)
{
    Perim = std::move(perim);
}

void Scenka::Set_Ploshad(QString ploshad)
{
    Ploshad = std::move(ploshad);
}

QString Scenka::Get_Zentr_mass()
{
    return Zentr_mass;
}

QString Scenka::Get_Perim()
{
    return Perim;
}

QString Scenka::Get_Ploshad()
{
    return Ploshad;
}

void Scenka::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (figura == "Squart") {
        Squart *m_squart = new Squart(event->scenePos());
        m_squart->setPos(event->pos());
        squart = m_squart;
        this->addItem(squart);

    } else if (figura == "Rect") {
        Rectic *m_rectic = new Rectic(event->scenePos());
        m_rectic->setPos(event->pos());
        rect = m_rectic;
        this->addItem(rect);

    } else if (figura == "Triangul_pram") {
        Tri_pram *m_tri_pram = new Tri_pram(event->scenePos());
        m_tri_pram->setPos(event->pos());
        tri_pram = m_tri_pram;
        this->addItem(tri_pram);

    } else if (figura == "Triangul_ravn_bedr") {
        Tri_ravn_bedr *m_tri_ravn_bedr = new Tri_ravn_bedr(event->scenePos());
        m_tri_ravn_bedr->setPos(event->pos());
        tri_ravn_bedr = m_tri_ravn_bedr;
        this->addItem(tri_ravn_bedr);

    } else if (figura == "Triangul_ravn_stor") {
        Tri_ravn_stor *m_tri_ravn_stor = new Tri_ravn_stor(event->scenePos());
        m_tri_ravn_stor->setPos(event->pos());
        tri_ravn_stor = m_tri_ravn_stor;
        this->addItem(tri_ravn_stor);

    } else if (figura == "Fife_star") {
        Fife_star *m_fife_star = new Fife_star(event->scenePos());
        m_fife_star->setPos(event->pos());
        fife_star = m_fife_star;
        this->addItem(fife_star);

    } else if (figura == "Eught_star") {
        Eught_star *m_eught_star = new Eught_star(event->scenePos());
        m_eught_star->setPos(event->pos());
        eught_star = m_eught_star;
        this->addItem(eught_star);

    } else if (figura == "Six_star") {
        Six_star *m_six_star = new Six_star(event->scenePos());
        m_six_star->setPos(event->pos());
        six_star = m_six_star;
        this->addItem(six_star);

    } else if (figura == "Ellips") {
        Ellips *m_ellips = new Ellips(event->scenePos());
        m_ellips->setPos(event->pos());
        ellips = m_ellips;
        this->addItem(ellips);

    } else if (figura == "Krug") {
        Krug *m_krug = new Krug(event->scenePos());
        m_krug->setPos(event->pos());
        krug = m_krug;
        this->addItem(krug);

    }

    else if (figura == "Move") {
        point_for_move = event->scenePos();

        QList<QGraphicsItem *> foundItems = this->items(
            QPolygonF() << QPointF(event->scenePos().x() - 1, event->scenePos().y() + 1)
                        << QPointF(event->scenePos().x() - 1, event->scenePos().y() - 1)
                        << QPointF(event->scenePos().x() + 1, event->scenePos().y() - 1)
                        << QPointF(event->scenePos().x() + 1, event->scenePos().y() + 1));

        if (!foundItems.isEmpty()) {
            Item = foundItems[0];
            move = true;
        }

    }

    else if (figura == "Resize") {
        QList<QGraphicsItem *> foundItems = this->items(
            QPolygonF() << QPointF(event->scenePos().x(), event->scenePos().y())
                        << QPointF(event->scenePos().x(), event->scenePos().y())
                        << QPointF(event->scenePos().x(), event->scenePos().y())
                        << QPointF(event->scenePos().x(), event->scenePos().y()));

        if (!foundItems.isEmpty()) {
            Item = foundItems.first();
            resize = true;
        }

    }

    else if (figura == "Deleter") {
        QList<QGraphicsItem *> foundItems = this->items(
            QPolygonF() << QPointF(event->scenePos().x(), event->scenePos().y())
                        << QPointF(event->scenePos().x(), event->scenePos().y())
                        << QPointF(event->scenePos().x(), event->scenePos().y())
                        << QPointF(event->scenePos().x(), event->scenePos().y()));

        if (!foundItems.isEmpty()) {
            delete foundItems.first();
        }
    }

    else if (figura == "Povorot") {
        QList<QGraphicsItem *> foundItems = this->items(
            QPolygonF() << QPointF(event->scenePos().x(), event->scenePos().y())
                        << QPointF(event->scenePos().x(), event->scenePos().y())
                        << QPointF(event->scenePos().x(), event->scenePos().y())
                        << QPointF(event->scenePos().x(), event->scenePos().y()));

        if (!foundItems.isEmpty()) {
            Item = foundItems.first();
            rotation = true;
        }
    }

    this->update(QRectF(0, 0, this->width(), this->height()));
}

void Scenka::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (figura == "Squart") {
        squart->point2 = event->scenePos();
        m_poligonchik = squart;
    }

    else if (figura == "Rect") {
        rect->point2 = event->scenePos();
        Perim = rect->Perim();
        Ploshad = rect->Plohchad();
        Set_Zentr_mass(rect->Zenter_mass());
    }

    else if (figura == "Triangul_pram") {
        tri_pram->point2 = event->scenePos();
        m_poligonchik = tri_pram;
    }

    else if (figura == "Triangul_ravn_bedr") {
        tri_ravn_bedr->point2 = event->scenePos();
        m_poligonchik = tri_ravn_bedr;
    }

    else if (figura == "Triangul_ravn_stor") {
        tri_ravn_stor->point2 = event->scenePos();
        m_poligonchik = tri_ravn_stor;
    }

    else if (figura == "Fife_star") {
        fife_star->point2 = event->scenePos();
        m_poligonchik = fife_star;
    }

    else if (figura == "Eught_star") {
        eught_star->point2 = event->scenePos();
        m_poligonchik = eught_star;
    }

    else if (figura == "Six_star") {
        six_star->point2 = event->scenePos();
        m_poligonchik = six_star;
    }

    else if (figura == "Ellips") {
        ellips->point2 = event->scenePos();
        m_poligonchik = ellips;
    }

    else if (figura == "Move" && move) {
        Item->setPos(event->scenePos() - point_for_move);
    }

    else if (figura == "Krug") {
        krug->point2 = event->scenePos();
        m_poligonchik = krug;
    }

    else if (figura == "Resize" && resize) {
        m_poligonchik = dynamic_cast<Poligonchik *>(Item);
        m_poligonchik->point2 = event->scenePos();
    }

    else if (figura == "Povorot" && rotation) {
        item_povorot = Item;
    }

    Set_Perim(m_poligonchik->Perim());
    Set_Ploshad(m_poligonchik->Plohchad());
    Set_Zentr_mass(m_poligonchik->Zenter_mass());

    updateRect();

    this->update(QRectF(0, 0, this->width(), this->height()));
}

void Scenka::keyPressEvent(QKeyEvent *e)
{
    //Для лютого экспириенса и уничтожения глаз и здравого смысла предлагаю запускать код, который находится в комментариях ниже

    if(e->key()==Qt::Key_Left && rotation){

        ygol+=2;
        item_povorot->setTransformOriginPoint(QCursor::pos());
        item_povorot->setRotation(ygol);
        updateRect();
        this->update(QRectF(0, 0, this->width(), this->height()));


    }

    else if(e->key()==Qt::Key_Right && rotation){

        ygol-=2;
        item_povorot->setTransformOriginPoint(QCursor::pos());
        item_povorot->setRotation(ygol);
        updateRect();
        this->update(QRectF(0, 0, this->width(), this->height()));

    }

    /*
    QRectF gran = item_povorot->boundingRect();
    QPointF center = gran.center();

    if (e->key() == Qt::Key_Left && rotation) {
        ygol -= 2;
        item_povorot->setTransformOriginPoint(center);
        item_povorot->setRotation(ygol);
        updateRect();
        this->update(QRectF(0, 0, this->width(), this->height()));

    }

    else if (e->key() == Qt::Key_Right && rotation) {
        ygol += 2;
        item_povorot->setTransformOriginPoint(center);
        item_povorot->setRotation(ygol);
        updateRect();
        this->update(QRectF(0, 0, this->width(), this->height()));
    }
*/
}
