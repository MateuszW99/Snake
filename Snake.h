#pragma once
#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>
#include "Constants.h"
#include <QVector>


struct SnakePart : public QGraphicsRectItem
{
public:
    SnakePart() : next{nullptr}
    {
    }

    virtual ~SnakePart();

    SnakePart* next;
};

class Snake : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Snake();
    ~Snake();

    void Setup();
    void EatFruit();
    void AddTail();
    bool WallHit();

    int GetXDirection() const { return xDirection; }
    int GetYDirection() const { return yDirection; }

public slots:
    //void Move();

private:
    //QTimer* timer;
    SnakePart* head;

    int xDirection;
    int yDirection;
    void keyPressEvent(QKeyEvent*);
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();

    //void CheckCollision();
    //bool ComparePositions(const double, const double, const double, const double) const;
};

