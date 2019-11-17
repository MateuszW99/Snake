#pragma once

#include <QImage>
#include <vector>
#include <QPoint>
#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>
#include "Constants.h"



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

    void AddTail();
    bool WallHit();

public slots:
    void Move();

private:
    //QGraphicsScene* sceneWalls;
    QTimer* timer;
    SnakePart* head;
    int xDirection;
    int yDirection;
    void keyPressEvent(QKeyEvent*);

    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
};

