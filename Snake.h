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

    void eatFruit(); // Remove a fruit from the scene after colliding with it
    void addTail();

    bool wallHit(); // Determine if snake hit a wall
    void checkCollision(); // Collect items snake's colliding with

    int getXDirection() const { return xDirection; }
    int getYDirection() const { return yDirection; }

    void move(); // Move snake and its tail

    QPointF getHead() { return head; }
    void moveLeft(); // Set xDirection to -xDirection and yDirection to 0
    void moveRight(); // Set xDireciton to +xDirection and yDirection to 0
    void moveUp(); // Set yDirection to -yDirection and xDirection to 0
    void moveDown(); // Set yDirection to +yDirection and xDirection to 0

private:
    QPointF head;
    QVector<QPointF> tail; // Store all the exisiting points of snake's tail
    QGraphicsScene* scene = nullptr;
    int xDirection;
    int yDirection;
    int snakeLength;
    int toGrow;

    void updateHead();
    void updateTail();

};

