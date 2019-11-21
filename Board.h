#pragma once
#include <QGraphicsView>
#include <QGraphicsObject>
#include <QWidget>
#include <QVector>
#include <QMainWindow>
#include "Snake.h"
#include "Fruit.h"
#include <QTimer>
#include <QGraphicsItem>

class Board : public QGraphicsView
{
    Q_OBJECT
public:
    Board();
    ~Board()
    {
        delete scene;
        delete snake;
        delete spawnTimer;
        delete snakeTimer;
        // delete fruits
    }

public slots:
    void SpawnFruit();
    void MoveSnake();

private:
    QGraphicsScene* scene;
    Snake* snake;
    QTimer* spawnTimer;
    QTimer* snakeTimer;
    QVector<Fruit*> Fruits;

    bool WallHit();
    void CheckCollision();
    bool ComparePositions(const double, const double, const double, const double) const;

};
