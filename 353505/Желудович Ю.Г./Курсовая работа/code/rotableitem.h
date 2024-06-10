#ifndef ROTABLEITEM_H
#define ROTABLEITEM_H

#include <QObject>
#include <QGraphicsItem>

class RotableItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation NOTIFY rotationChanged)

public:
    explicit RotableItem(QGraphicsItem *item, QObject *parent = nullptr);

    qreal rotation() const;
    void setRotation(qreal rotation);

signals:
    void rotationChanged();

private:
    QGraphicsItem *m_item;
    qreal m_rotation;
};

#endif // ROTABLEITEM_H
