#pragma once
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QPainter>
#include <QVector>
#include "Constants.h"

class Snake : public QGraphicsItem
{
public:
    Snake(QGraphicsScene*);
    ~Snake() {}

    QPainterPath shape() const; // Set the shape of snake to circle
    QRectF boundingRect() const; // Set a rectangle to be the bouding shape of snake
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);


    bool intersects() const; // Return true if snake eats itself
    bool wallHit(); // Determine if snake hit a wall
    void checkCollision(); // Collect items snake's colliding with

    int getXDirection() const { return xDirection; }
    int getYDirection() const { return yDirection; }

    void move(); // Move snake and its tail

    QPointF getHead() const { return head; }

    void moveLeft(); // Set xDirection to -xDirection and yDirection to 0
    void moveRight(); // Set xDireciton to +xDirection and yDirection to 0
    void moveUp(); // Set yDirection to -yDirection and xDirection to 0
    void moveDown(); // Set yDirection to +yDirection and xDirection to 0

    Data::Direction getDirection() const { return direction; }

private:
    QPointF head;
    QVector<QPointF> tail; // Store all the exisiting points of snake's tail
    QGraphicsScene* scene = nullptr;
    Data::Direction direction;
    int xDirection;
    int yDirection;
    int snakeLength;
    int toGrow;

    void eatFruit(QGraphicsItem*); // Remove a fruit from the scene after colliding with it and enlong snake

    void updateHead();
    void updateTail();

    QPainterPath painter;
};

