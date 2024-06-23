#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Button: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    //constructors
    Button(QString name, QGraphicsItem* parent = nullptr);

    //public methods(events)
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
signals:
    void clicked();


private:
    QGraphicsTextItem* text;
};

#endif // BUTTON_H

