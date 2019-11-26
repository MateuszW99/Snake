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
    Controller(QGraphicsScene*, QObject* parent);
    ~Controller() override;

    static int fruitsNumber; // Holds a value of current number of fruits on the board

public slots:
    void spawnFruit();
    void moveSnake();

private:
    QGraphicsScene* gameScene = nullptr;
    Snake* snake = nullptr;
    QTimer* snakeTimer = nullptr;
    QTimer* fruitTimer = nullptr;

    bool checkWallCollision() const;  // Returns true whenever snake hits a wall
    bool checkSnakeCollision() const; // Returns true whenever snake eats itself
    void checkItemCollision() const; // Gather items which snake's colliding with
    bool checkFruitsNumber() const; // Returns true if there are more than Data::maxFruitNumber on the board

    void keyPressEvent(QKeyEvent*);
    bool eventFilter(QObject *watched, QEvent *event) override;
};
