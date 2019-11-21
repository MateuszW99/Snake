#pragma once
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include "Snake.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(QGraphicsScene*, Snake*);
    ~Controller();

public slots:
    void SpawnFruit();
    void MoveSnake();

private:
    QGraphicsScene* gameScene;
    Snake* snake;
    QTimer* snakeTimer;
    QTimer* fruitTimer;
};
