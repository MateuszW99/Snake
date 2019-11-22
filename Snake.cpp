#include <QDebug>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "Snake.h"
#include "Fruit.h"
#include "Controller.h"

using namespace Data;


Snake::Snake(QGraphicsScene* gameScene) : scene{ gameScene }, xDirection{ xVelocity }, yDirection{ 0 }
{
    //setFocus();
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
        moveLeft();
        break;
    }
    case Qt::Key_Right:
    {
        //qDebug() << "Right";
        moveRight();
        break;
    }
    case Qt::Key_Up:
    {
        //qDebug() << "Up";
        moveUp();
        break;
    }
     case Qt::Key_Down:
    {
        //qDebug() << "Down";
        moveDown();
        break;
    }
    }
}

bool Snake::wallHit()
{
    if(x() > Data::width|| x() < -Data::width|| y() > Data::height || y() < -Data::height)
    {
        qDebug() << "Wall hit";
        return true;
    }
    return false;
}

void Snake::checkCollision()
{
    QList<QGraphicsItem*> collision = collidingItems();
    for(auto item : collision)
    {
        scene->removeItem(item);
        Controller::fruitsNumber--;
        //snake->eat()
    }
}

void Snake::moveLeft()
{
    xDirection = -1 * xVelocity;
    yDirection = 0;
}

void Snake::moveRight()
{
    xDirection = xVelocity;
    yDirection = 0;
}

void Snake::moveUp()
{
    xDirection = 0;
    yDirection = -1 * yVelocity;
}

void Snake::moveDown()
{
    xDirection = 0;
    yDirection = yVelocity;
}
