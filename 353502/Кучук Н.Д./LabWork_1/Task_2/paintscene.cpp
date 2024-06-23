#include "paintscene.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"
#include "circle.h"
#include "hexagon.h"
#include "star5.h"
#include "star6.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{
    rotateTimer = new QTimer();

}

PaintScene::~PaintScene()
{

}

int PaintScene::typeFigure() const
{
    return m_typeFigure;
}

int PaintScene::toDo() const
{
    return m_toDo;
}

void PaintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}


void PaintScene::setToDo(const int type)
{
    m_toDo = type;
}


void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (selectedFigure != nullptr && m_typeFigure != LineType){
        tempFigure = dynamic_cast<Figure*>(selectedFigure);
        setCenterX(tempFigure->returnCenter().x());
        setCenterY(tempFigure->returnCenter().y());
        setSquare(tempFigure->square);
        setPerimeter(tempFigure->perimeter);
        emit centerXChanged();
        emit centerYChanged();
        emit squareChanged();
        emit perimeterChanged();

    }
    switch(m_toDo){
    case Paint:{
        switch (m_typeFigure){
        case LineType:{
            addLine(previousPoint.x(),
                    previousPoint.y(),
                    event->scenePos().x(),
                    event->scenePos().y(),
                    QPen(Qt::black,5,Qt::SolidLine,Qt::RoundCap));
            previousPoint = event->scenePos();
            break;
        }
        default:{
            tempFigure->setEndPoint(event->scenePos());
            tempFigure->updateCentre();
            this->update(QRectF(0,0,this->width(), this->height()));
        }
        }
        // this->
        break;
    }
    case Moving:{
        if (selectedFigure != nullptr){
            selectedFigure->setPos(event->scenePos() + start_move);
            selectedFigure->boundingRect();
        }
        break;
    }

    }
}


qreal PaintScene::centerX() const{
    return m_centerX;
}

qreal PaintScene::centerY() const{
    return m_centerY;
}

qreal PaintScene::perimeter() const{
    return m_perimeter;
}

qreal PaintScene::square() const{
    return m_square;
}

void PaintScene::setCenterX(qreal x){
    m_centerX = x;
}

void PaintScene::setCenterY(qreal y){
    m_centerY = y;
}


void PaintScene::setPerimeter(qreal perimeter){
    m_perimeter = perimeter;
}


void PaintScene::setSquare(qreal square){
    m_square = square;
}




void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    switch(m_toDo){
    case RotateRight:{
        disconnect(rotateTimer, &QTimer::timeout, this, &PaintScene::rotateFigure);
        rotateTimer->stop();
        break;
        }
    case RotateLeft:{
        disconnect(rotateTimer, &QTimer::timeout, this, &PaintScene::rotateFigure);
        rotateTimer->stop();
        break;
    }
    case SizePlus:{
        disconnect(rotateTimer, &QTimer::timeout, this, &PaintScene::scaleFigure);
        rotateTimer->stop();
        break;
    }
    case SizeMinus:{
        disconnect(rotateTimer, &QTimer::timeout, this, &PaintScene::scaleFigure);
        rotateTimer->stop();
        break;
    }
    }


    Q_UNUSED(event);
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch(m_toDo){
    case Paint:{
        switch (m_typeFigure) {
        case SquareType: {
            Square *item = new Square(event->scenePos());
            item->setPos(event->pos());
            item->setFigureID(countFigure);
            tempFigure = item;
            this->addItem(tempFigure);
            figureList.append(item);
            break;
        }
        case RombType: {
            Romb *item = new Romb(event->scenePos());
            item->setPos(event->pos());
            item->setFigureID(countFigure);
            tempFigure = item;
            this->addItem(tempFigure);
            figureList.append(item);
            break;
        }
        case CircleType: {
            Circle *item = new Circle(event->scenePos());
            item->setPos(event->pos());
            item->setFigureID(countFigure);
            tempFigure = item;
            this->addItem(tempFigure);
            figureList.append(item);
            break;
        }
        case TriangleType: {
            Triangle *item = new Triangle(event->scenePos());
            item->setPos(event->pos());
            item->setFigureID(countFigure);
            tempFigure = item;
            this->addItem(tempFigure);
            figureList.append(item);
            break;
        }
        case HexagonType: {
            Hexagon *item = new Hexagon(event->scenePos());
            item->setPos(event->pos());
            item->setFigureID(countFigure);
            tempFigure = item;
            this->addItem(tempFigure);
            figureList.append(item);
            break;
        }
        case Star5Type:{
            Star5 *item = new Star5(event->scenePos());
            item->setPos(event->pos());
            item->setFigureID(countFigure);
            tempFigure = item;
            this->addItem(tempFigure);
            figureList.append(item);
            break;
        }
        case Star6Type:{
            Star6 *item = new Star6(event->scenePos());
            item->setPos(event->pos());
            item->setFigureID(countFigure);
            tempFigure = item;
            this->addItem(tempFigure);
            figureList.append(item);
            break;
        }
        case LineType: {
            addEllipse(event->scenePos().x() - 5,
                       event->scenePos().y() - 5,
                       5,
                       5,
                       QPen(Qt::NoPen),
                       QBrush(Qt::black));
            previousPoint = event->scenePos();
            break;
        }
        }
        ++countFigure;
        this->clearSelection();
        selectedFigure = tempFigure;
        break;
    }
    case Moving:{
        selectedFigure = this->itemAt(event->scenePos(), QTransform());
        if(selectedFigure != nullptr){
            start_move = selectedFigure->pos() - event->scenePos();
        }
        tempFigure->move_startPoint = event->scenePos();
        break;
    }
    case RotateRight: {
        rotate = 1;
        selectedFigure = this->itemAt(event->scenePos(), QTransform());
        if(selectedFigure != nullptr){
            connect(rotateTimer, &QTimer::timeout, this, &PaintScene::rotateFigure);

            rotateTimer->start(20);
        }

        break;
    }
    case RotateLeft: {
        rotate = -1;
        selectedFigure = this->itemAt(event->scenePos(), QTransform());
        if(selectedFigure != nullptr){
            connect(rotateTimer, &QTimer::timeout, this, &PaintScene::rotateFigure);
            rotateTimer->start(20);
            }
        break;
        }
    case SizePlus:{
            rotate = 2;
        selectedFigure = this->itemAt(event->scenePos(), QTransform());
        if(selectedFigure != nullptr){
            connect(rotateTimer, &QTimer::timeout, this, &PaintScene::scaleFigure);
            rotateTimer->start(20);
        }
        break;
        }
    case SizeMinus:{
        rotate = -2;
        selectedFigure = this->itemAt(event->scenePos(), QTransform());
        if(selectedFigure != nullptr){
            connect(rotateTimer, &QTimer::timeout, this, &PaintScene::scaleFigure);
            rotateTimer->start(20);
        }
        break;
        }

    }
}


void PaintScene:: rotateFigure(){
    selectedFigure->advance(rotate);
}

void PaintScene:: scaleFigure(){
    selectedFigure->advance(rotate);
}
