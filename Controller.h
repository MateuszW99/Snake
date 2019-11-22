#pragma once
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QVector>
#include "Snake.h"
#include "Fruit.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(QGraphicsScene*);
    ~Controller();

public slots:
    void SpawnFruit();
    void MoveSnake();

private:
    QGraphicsScene* gameScene;
    Snake* snake;
    QTimer* snakeTimer;
    QTimer* fruitTimer;
    QVector<Fruit*> Fruits;
};
