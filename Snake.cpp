#include <QDebug>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "Snake.h"
#include "Fruit.h"
#include "Controller.h"
#include <typeinfo>

Snake::Snake(QGraphicsScene* gameScene)
    : head{ Data::width / 2, Data::height / 2 }, scene{ gameScene },
      xDirection{ Data::velocity }, yDirection{ 0 },
      toGrow { 5 }
{
    direction = Data::Direction::Right;
}


QPainterPath Snake::shape() const
{
    QPainterPath painterPath;
    painterPath.setFillRule(Qt::WindingFill);
    painterPath.addEllipse(QPointF{0, 0}, Data::snakeSize, Data::snakeSize); // Snake's head is set to be an ellipse

    for(auto point : tail) // Shape the tail
    {
        QPointF node = mapFromScene(point);
        painterPath.addEllipse(QPointF(node.x(), node.y()), Data::snakeSize * 0.9, Data::snakeSize * 0.9); // Snake nodes are set to be smaller than the head
    }

    return painterPath;
}

QRectF Snake::boundingRect() const
{
    qreal minX = head.x();
    qreal minY = head.y();
    qreal maxX = head.x();
    qreal maxY = head.y();

    for(auto point : tail) {
        maxX = point.x() > maxX ? point.x() : maxX;
        maxY = point.y() > maxY ? point.y() : maxY;
        minX = point.x() < minX ? point.x() : minX;
        minY = point.y() < minY ? point.y() : minY;
    }

    QPointF topLeft = mapFromScene(QPointF(minX, minY));
    QPointF bottomRight = mapFromScene(QPointF(maxX, maxY));

    return QRectF(QPointF(topLeft.x() - Data::snakeSize, topLeft.y() - Data::snakeSize),
                  QPointF(bottomRight.x() - topLeft.x() + Data::snakeSize, bottomRight.y() - topLeft.y() + Data::snakeSize));
}

void Snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), QColor(20, 155, 55));
    painter->restore();
}

void Snake::move()
{

    // Move the head forward
    updateHead();
    // Move the body nodes forward
    updateTail();
    // Move snake's shape forward
    setPos(head);
}

void Snake::goThroughWall()
{
    switch(direction)
    {
    case Data::Direction::Left:
        {
           head.setX(Data::width);
           setPos(head.x(), y());
           break;
        }
    case Data::Direction::Right:
        {
           head.setX(0);
           setPos(head.x(), y());
           break;
        }
    case Data::Direction::Up:
        {
           head.setY(Data::height);
           setPos(x(), head.y());
           break;
        }
    case Data::Direction::Down:
        {
           head.setY(0);
           setPos(x(), head.y());
           break;
        }
    }
}

void Snake::eatFruit(QGraphicsItem* item)
{
    toGrow++;
    scene->removeItem(item);
    Controller::fruitsNumber--;
    if(tail.count() % 4 == 0 && Data::velocity <= Data::maxSpeed)
    {
        Data::velocity++;
    }
}

bool Snake::wallHit()
{
    if(head.x() >= Data::width || head.x() <= 0 || head.y() >= Data::height || head.y() <= 0)
    {
        return true;
    }
    return false;
}

void Snake::checkCollision()
{
    QList<QGraphicsItem*> collision = collidingItems();
    for(auto item : collision)
    {
        if(Fruit* fruit = dynamic_cast<Fruit*>(item)) // If snake's colliding with a fruit, let snake eat it
        {
            eatFruit(item);
        }
    }
}

void Snake::moveLeft()
{
    xDirection = -Data::velocity;
    yDirection = 0;
    direction = Data::Direction::Left;
    updateHead();
}

void Snake::moveRight()
{
    xDirection = Data::velocity;
    yDirection = 0;
    direction = Data::Direction::Right;
    updateHead();
}

void Snake::moveUp()
{
    xDirection = 0;
    yDirection = -Data::velocity;
    direction = Data::Direction::Up;
    updateHead();
}

void Snake::moveDown()
{
    xDirection = 0;
    yDirection = Data::velocity;
    direction = Data::Direction::Down;
    updateHead();
}

bool Snake::intersects() const
{
    return tail.contains(head) ? true : false;
}

void Snake::updateHead()
{
    head.setX(head.x() + xDirection);
    head.setY(head.y() + yDirection);
}

void Snake::updateTail()
{
    if(toGrow > 0)
    {
        toGrow--;
    }
    else
    {
        if(!tail.isEmpty())
        {
            tail.removeFirst();
        }
    }

    tail.push_back(QPointF{ x(), y() });
}
