#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QGraphicsProxyWidget>


class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF startPoint
                   READ startPoint WRITE setStartPoint
                       NOTIFY pointChanged)
    Q_PROPERTY(QPointF endPoint
                   READ endPoint WRITE setEndPoint
                       NOTIFY pointChanged)
public:
    explicit Figure(QPointF point, QObject *parent = 0);
    ~Figure();
    static int id;
    QPointF startPoint() const;
    QPointF endPoint() const;
    QPointF center;
    void setStartPoint(const QPointF point);
    void setEndPoint(const QPointF point);
    int readFigureID();
    void setFigureID(int n);
    void advance(int step) override;
    void setZoom(bool toDo);
    void updateCentre();
    int toDo;
    QPointF move_startPoint;
    QPointF move_endPoint;
    QPointF returnCenter();
    void findPerimeter();
    void findSquare();
    qreal perimeter = 0;
    qreal square = 0;
    // virtual qreal Square();
    // virtual qreal Perimeter();

signals:
    void pointChanged();
    void centerChanged();
    void clicked(Figure *rect);
protected:
    QVector<QPointF> points;


private:
    int figureID;
    QPointF m_startPoint;
    QPointF m_endPoint;
    qreal rotationAngle;
    qreal scaleZoom;
    QRectF boundingRect() const;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;


public slots:
    void updateRomb();
};

#endif // FIGURE_H
