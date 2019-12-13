#pragma once
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QElapsedTimer>
#include "Snake.h"
#include "Fruit.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(QGraphicsScene*, QObject* parent, int, int);
    ~Controller() override;

    static int fruitsNumber; // Holds the value of current number of fruits on the board
    static int score;

public slots:
    void spawnFruit();
    void moveSnake();

private:
    QGraphicsScene* gameScene = nullptr;
    Snake* snake = nullptr;
    QElapsedTimer* gameTimer = nullptr;
    QTimer* snakeTimer = nullptr;
    QTimer* fruitTimer = nullptr;
    int gameTime;
    int snakeLength;

    void startTimers() const;
    void stopTimers() const;
    void restartGame(); // Spawn a new snake
    void stopGame(); // When snake eats itself, show message
    void quitGame() const;

    void checkCollisions(); // Call all the checking functions
    bool checkWallCollision() const;  // Returns true whenever snake hits a wall
    bool checkSnakeCollision() const; // Returns true whenever snake eats itself
    void checkItemCollision() const; // Gather items which snake's colliding with
    bool checkFruitsNumber() const; // Returns true if there are more than Data::maxFruitNumber on the board

    QString gameEndMessage() const;

    void keyPressEvent(QKeyEvent*); // Get input from the player
    bool eventFilter(QObject *watched, QEvent *event) override;
};
