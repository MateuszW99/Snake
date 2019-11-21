#pragma once
#include <QGraphicsItem>
#include <QKeyEvent>
#include "Constants.h"
#include <QVector>
#include <QPainter>

class Snake : public QGraphicsItem
{
public:
    Snake();

    QPainterPath shape() const;
    QRectF boundingRect() const; // Rectangle bouding the shape of food
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    void EatFruit();
    void AddTail();

    bool WallHit();
    void CheckCollision();

    int GetXDirection() const { return xDirection; }
    int GetYDirection() const { return yDirection; }

private:
    int xDirection;
    int yDirection;

    void keyPressEvent(QKeyEvent*);

    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();

};

