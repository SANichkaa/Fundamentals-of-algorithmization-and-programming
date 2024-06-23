#include "figure.h"
#include <QPainter>


Figure::Figure(QPointF point, QObject *parent) :
    QObject(parent), QGraphicsItem(),  rotationAngle(0), scaleZoom(1)
{
    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    connect(this, &Figure::pointChanged, this, &Figure::updateRomb);
}

Figure::~Figure()
{

}

int Figure::id = 0;


QRectF Figure::boundingRect() const
{

    return QRectF((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 50,
                  (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 50,
                  qAbs(endPoint().x() - startPoint().x()) + 100,
                  qAbs(endPoint().y() - startPoint().y()) + 100);
    //return {0, 0, 2000, 2000};
}

void Figure::updateRomb()
{
    this->update((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                 (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                 qAbs(endPoint().x() - startPoint().x()) + 10,
                 qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::setStartPoint(const QPointF point)
{
    m_startPoint = mapFromScene(point);
    emit pointChanged();
}

void Figure::setEndPoint(const QPointF point)
{
    m_endPoint = mapFromScene(point);
    updateCentre();
    findPerimeter();
    findSquare();
    emit pointChanged();
    emit centerChanged();
}

QPointF Figure::startPoint() const
{
    return m_startPoint;
}

QPointF Figure::endPoint() const
{
    return m_endPoint;
}


void Figure::updateCentre()
{
    this->center={(endPoint().x()+startPoint().x())/2,(endPoint().y()+startPoint().y())/2};
    this->setTransformOriginPoint(center);

    emit centerChanged();
}

void Figure::setFigureID(int num)
{
    this->figureID = num;
}


int Figure:: readFigureID()
{
    return this->figureID;
}

QPointF Figure:: returnCenter(){
    return mapToScene(center);
}


void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::id = this->figureID;
}

void Figure::advance(int step) {
    if (!step)
        return;
    else if(step == 1){
        rotationAngle += 1;
        this->setRotation(rotationAngle);
    }
    else if (step == -1){
        rotationAngle -= 1;
        this->setRotation(rotationAngle);
    }
    else if (step == 2){
        scaleZoom += 0.01;
        this->setScale(scaleZoom);
        findPerimeter();
        findSquare();
    }
    else if (step == -2){
        scaleZoom -= 0.01;
        if (scaleZoom <= 0.3){
            scaleZoom = 0.3;
        }
        this->setScale(scaleZoom);
        findPerimeter();
        findSquare();
    }

}

void Figure:: setZoom(bool toDo){

}


void Figure::findSquare() {
    if (points.size() > 2) {
        square = 0;
        square += points[0].y() * points[points.size() - 1].x() - points[0].x() * points[points.size() - 1].y();
        for (int i = 0; i < points.size() - 1; i++) {
            square += points[i].x() * points[i + 1].y() - points[i].y() * points[i + 1].x();
        }
        square = qAbs(square) / 2;
    }
}

void Figure::findPerimeter() {
    perimeter = 0;
    if (points.size() > 2) {
        for (int i = 0; i < points.size() - 1; i++) {
            perimeter += qSqrt((points[i].y() - points[i + 1].y()) * (points[i].y() - points[i + 1].y()) +
                               (points[i].x() - points[i + 1].x()) * (points[i].x() - points[i + 1].x()));
        }

        perimeter += qSqrt(
            (points[0].y() - points[points.size() - 1].y()) * (points[0].y() - points[points.size() - 1].y()) +
            (points[0].x() - points[points.size() - 1].x()) * (points[0].x() - points[points.size() - 1].x()));
    }
}


