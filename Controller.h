#pragma once
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Snake.h"
#include "Fruit.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(QGraphicsScene*);
    ~Controller();

    static int fruitsNumber;

public slots:
    void SpawnFruit();
    void MoveSnake();

private:
    QGraphicsScene* gameScene;
    Snake* snake;
    QTimer* snakeTimer;
    QTimer* fruitTimer;
};
