#include <QDebug>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "Snake.h"
#include "Fruit.h"
#include "Controller.h"
#include <typeinfo>

Snake::Snake(QGraphicsScene* gameScene)
    : head{Data::width / 2, Data::height / 2}, scene{ gameScene },
      xDirection{ Data::xVelocity }, yDirection{ 0 },
      toGrow { 0 }
{

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
    //QPointF lastHeadPosition{ head }; // Store the head position
    //qDebug() << lastHeadPosition;
    // Move the head forward
    updateHead();
    // Move the boyd forward


   if(toGrow > 0)
   {
       QPointF newNode;
       tail.push_back(newNode);
       toGrow--;
   }
   else
   {
       if(!tail.isEmpty())
       {
           tail.removeFirst();
           tail.push_back(head);
       }
   }

   setPos(head);
}

void Snake::eatFruit()
{
    toGrow++;
}

bool Snake::wallHit()
{
    if(x() > Data::width || x() < -Data::width || y() > Data::height || y() < -Data::height)
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
        if(Fruit* fruit = dynamic_cast<Fruit*>(item))
        {
            eatFruit();
            scene->removeItem(item);
            Controller::fruitsNumber--;
        }
    }

    // todo: self eating
}

void Snake::moveLeft()
{
    xDirection = -Data::xVelocity;
    yDirection = 0;
    updateHead();
}

void Snake::moveRight()
{
    xDirection = Data::xVelocity;
    yDirection = 0;
    updateHead();
}

void Snake::moveUp()
{
    xDirection = 0;
    yDirection = -Data::yVelocity;
    updateHead();
}

void Snake::moveDown()
{
    xDirection = 0;
    yDirection = Data::yVelocity;
    updateHead();
}

void Snake::updateHead()
{
    head.setX(head.x() + xDirection);
    head.setY(head.y() + yDirection);
}

void Snake::updateTailNode(QPointF& node)
{
    node.setX(node.x() + xDirection);
    node.setY(node.y() + yDirection);
}
