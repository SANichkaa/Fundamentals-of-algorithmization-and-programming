#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include "figure.h"



class PaintScene : public QGraphicsScene
{
    Q_OBJECT
    // Свойство текущего типа используемой фигуры
    Q_PROPERTY(int typeFigure
                   READ typeFigure WRITE setTypeFigure
                       NOTIFY typeFigureChanged)
    Q_PROPERTY(int toDo
                   READ toDo WRITE setToDo
                       NOTIFY toDoChanged)
    Q_PROPERTY(qreal centerX
                   READ centerX WRITE setCenterX
                       NOTIFY centerXChanged)
    Q_PROPERTY(qreal centerY
                   READ centerY WRITE setCenterY
                       NOTIFY centerYChanged)
    Q_PROPERTY(qreal square
                   READ square WRITE setSquare
                       NOTIFY squareChanged)
    Q_PROPERTY(qreal perimeter
                   READ perimeter WRITE setPerimeter
                       NOTIFY perimeterChanged)

public:
    explicit PaintScene(QObject *parent = 0);
    ~PaintScene();
    int typeFigure() const;                 // Возвращение текущего типа
    int toDo() const;
    void setTypeFigure(const int type);
    void setToDo (const int type);    // Установка текущего типа
    qreal centerX() const;
    qreal centerY() const;
    qreal square() const;
    qreal perimeter() const;
    void setCenterX(qreal);
    void setCenterY(qreal);
    void setPerimeter(qreal);
    void setSquare(qreal);


    // Перечисление типов используемых фигур
    enum FigureTypes {
        SquareType,
        RombType,
        TriangleType,
        CircleType,
        HexagonType,
        LineType,
        Star5Type,
        Star6Type
    };
    enum ToDo {
        Paint,
        RotateLeft,
        RotateRight,
        Moving,
        SizePlus,
        SizeMinus
    };
    // int toDo;
    int countFigure = 0;
    QList<Figure*> figureList;

signals:
    void typeFigureChanged();
    void toDoChanged();          // Сигнал об изменении типа текущей фигуры
    void centerXChanged();
    void centerYChanged();
    void perimeterChanged();
    void squareChanged();
private:
    /* Объект для временного хранения рисуемой фигуры
     * Является объектом базового класса для всех трёх типов фигур в примере
     * */
    Figure *tempFigure;
    QGraphicsItem *selectedFigure;
    int m_typeFigure;
    int m_toDo;
    QPointF start_move, end_move;
    QTimer *rotateTimer;
    qreal m_centerX, m_centerY, m_square, m_perimeter;
    QPointF previousPoint;

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void rotateFigure();
    void scaleFigure();
    int rotate = 1;
    bool zoomScale;

};

#endif // PAINTSCENE_H
