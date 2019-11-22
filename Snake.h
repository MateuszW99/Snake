#pragma once
#include <QGraphicsItem>
#include <QKeyEvent>
#include "Constants.h"
#include <QPainter>

class Snake : public QGraphicsItem
{
public:
    Snake(QGraphicsScene*);

    QPainterPath shape() const; // Set the shape of snake to circle
    QRectF boundingRect() const; // Set a rectangle to be the bouding shape of snake
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    void eatFruit();
    void addTail();

    bool wallHit(); // Determine if snake hit a wall
    void checkCollision(); // Collect items snake's colliding with

    int getXDirection() const { return xDirection; }
    int getYDirection() const { return yDirection; }


    void moveLeft(); // Set xDirection to -xDirection and yDirection to 0
    void moveRight(); // Set xDireciton to +xDirection and yDirection to 0
    void moveUp(); // Set yDirection to -yDirection and xDirection to 0
    void moveDown(); // Set yDirection to +yDirection and xDirection to 0

private:
    QGraphicsScene* scene = nullptr;
    int xDirection;
    int yDirection;

    void keyPressEvent(QKeyEvent*);
};

