#include "Fruit.h"
#include <QGraphicsView>
#include "Constants.h"
#include <random>
#include <QDebug>

Fruit::Fruit(qreal x, qreal y)
{
    setPos(x, y);
}

QPainterPath Fruit::shape() const
{
    QPainterPath painterPath;
    painterPath.addEllipse(QPointF(Data::fruitSize / 2, Data::fruitSize / 2), Data::fruitSize, Data::fruitSize);
    return painterPath;
}

QRectF Fruit::boundingRect() const
{
    return QRectF{ -Data::fruitSize / 2, -Data::fruitSize / 2, Data::fruitSize * 2, Data::fruitSize * 2 };
}

void Fruit::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), QColor{ 240, 168, 44});
    painter->restore();
}


