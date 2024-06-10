#include "rotableitem.h"

RotableItem::RotableItem(QGraphicsItem *item, QObject *parent)
    : QObject(parent), m_item(item), m_rotation(0)
{
}

qreal RotableItem::rotation() const
{
    return m_rotation;
}

void RotableItem::setRotation(qreal rotation)
{
    if (m_rotation == rotation)
        return;

    m_rotation = rotation;
    m_item->setRotation(rotation);
    emit rotationChanged();
}
