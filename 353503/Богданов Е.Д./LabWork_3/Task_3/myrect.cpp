#include "myrect.h"

MyRect::MyRect(QGraphicsRectItem* rect) : myrect(rect) {}

QRectF MyRect::boundingRect() const { return myrect->boundingRect(); }

void MyRect::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                   QWidget* widget) {
  myrect->paint(painter, option, widget);
}
