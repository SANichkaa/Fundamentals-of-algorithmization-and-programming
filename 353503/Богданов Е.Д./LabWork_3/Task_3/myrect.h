#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsObject>
#include <QPropertyAnimation>

class MyRect : public QGraphicsObject
{
public:
  explicit MyRect(QGraphicsRectItem *rect);
  QRectF boundingRect() const override;
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget = nullptr) override;
private:
  QGraphicsRectItem* myrect;

};

#endif // MYRECT_H
