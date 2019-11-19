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
    QPainterPath p;
    p.addEllipse(QPointF(Data::FruitSize / 2, Data::FruitSize / 2), Data::FruitSize, Data::FruitSize);
    return p;
}

QRectF Fruit::boundingRect() const
{
    return QRectF(-Data::FruitSize / 2, -Data::FruitSize / 2, Data::FruitSize * 2, Data::FruitSize * 2 );
}

void Fruit::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::red);

    painter->restore();
}


