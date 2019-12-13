#pragma once
#include <QGraphicsItem>

class Fruit : public QGraphicsItem
{
public:
    Fruit(qreal, qreal);

    QPainterPath shape() const; // Set the shape of food to circle
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};
