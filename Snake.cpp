#include "Snake.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QTimer>
#include "Constants.h"
#include "Fruit.h"
#include <QVector>
#include <QList>

using namespace Data;


Snake::Snake() : xDirection{xVelocity}, yDirection{0}
{
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QPainterPath Snake::shape() const
{
    QPainterPath p;
    p.setFillRule(Qt::WindingFill);
    p.addEllipse(QPointF(0, 0), Data::snakeSize, Data::snakeSize);
    return p;
}

QRectF Snake::boundingRect() const
{
    return QRectF(QPointF(0 - Data::snakeSize, 0 - Data::snakeSize), QPointF(0 + Data::snakeSize, 0 + Data::snakeSize));
}

void Snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), QColor(20, 155, 55));
    painter->restore();
}

void Snake::keyPressEvent(QKeyEvent* keyEvent)
{
    switch (keyEvent->key()) {
    case Qt::Key_Left:
    {
        //qDebug() << "Left";
        MoveLeft();
        break;
    }
    case Qt::Key_Right:
    {
        //qDebug() << "Right";
        MoveRight();
        break;
    }
    case Qt::Key_Up:
    {
        //qDebug() << "Up";
        MoveUp();
        break;
    }
     case Qt::Key_Down:
    {
        //qDebug() << "Down";
        MoveDown();
        break;
    }
    }
}

bool Snake::WallHit()
{
    if(x() > Data::width|| x() < -Data::width|| y() > Data::height || y() < -Data::height)
    {
        qDebug() << "Wall hit";
        return true;
    }
    return false;
}

void Snake::CheckCollision()
{
    QList<QGraphicsItem*> collision = collidingItems();
    for(auto item : collision)
    {
        //snake->eat()
    }

}

void Snake::MoveLeft()
{
    xDirection = -1 * xVelocity;
    yDirection = 0;
}

void Snake::MoveRight()
{
    xDirection = xVelocity;
    yDirection = 0;
}

void Snake::MoveUp()
{
    xDirection = 0;
    yDirection = -1 * yVelocity;
}

void Snake::MoveDown()
{
    xDirection = 0;
    yDirection = yVelocity;
}
