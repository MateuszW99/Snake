#include "Controller.h"
#include "Constants.h"
#include "Fruit.h"
#include <QDebug>

int Controller::fruitsNumber = 0;

Controller::Controller(QGraphicsScene* scene) : gameScene { scene }, snake { new Snake(scene) }
{
    scene->addItem(snake);
    snake->setFocus();
    snake->setPos(Data::width / 2, Data::height / 2);

    fruitTimer = new QTimer();
    connect(fruitTimer, SIGNAL(timeout()), this, SLOT(spawnFruit()));
    fruitTimer->start(Data::FruitSpawnTime);

    snakeTimer = new QTimer;
    connect(snakeTimer, SIGNAL(timeout()), this, SLOT(moveSnake()));
    snakeTimer->start(Data::SnakeLatencySpeed);
}

Controller::~Controller()
{
    delete snakeTimer;
    delete snake;
    delete fruitTimer;
}

void Controller::moveSnake()
{
    if(checkWallCollision()) // hitting a wall means losing the game
    {
        snakeTimer->stop();
        return;
    }

    checkItemCollision();

    snake->setPos(snake->x() + snake->getXDirection(), snake->y() + snake->getYDirection());
    //qDebug() << snake->pos();
    snake->setFocus();
}

void Controller::spawnFruit()
{
    if(checkFruitsNumber()) // If there are more fruits than Data::maxFruitNumber, don't add a new one
    {
        return;
    }
    gameScene->addItem(new Fruit(qrand() % (Data::width - 10) + 10, qrand() % (Data::height - 10) + 10));
    fruitsNumber++;
}

bool Controller::checkWallCollision() const
{
    if(snake->wallHit())
    {
        return true;
    }
    return false;
}

void Controller::checkItemCollision() const
{
    snake->checkCollision();
}

bool Controller::checkFruitsNumber() const
{
    if(fruitsNumber >= Data::maxFruitNumber)
    {
        return true;
    }
    return false;
}



