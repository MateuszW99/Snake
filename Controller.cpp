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
    connect(fruitTimer, SIGNAL(timeout()), this, SLOT(SpawnFruit()));
    fruitTimer->start(Data::FruitSpawnTime);

    snakeTimer = new QTimer;
    connect(snakeTimer, SIGNAL(timeout()), this, SLOT(MoveSnake()));
    snakeTimer->start(Data::SnakeLatencySpeed);
}

Controller::~Controller()
{
    delete snakeTimer;
    delete snake;
    delete fruitTimer;
}

void Controller::MoveSnake()
{
    if(snake->WallHit())
    {
        //qDebug() << "Timer stopped";
        snakeTimer->stop();
        return;
    }

    snake->CheckCollision();
    snake->setPos(snake->x() + snake->GetXDirection(), snake->y() + snake->GetYDirection());
    //qDebug() << snake->pos();
    snake->setFocus();
}


void Controller::SpawnFruit()
{
    if(fruitsNumber >= Data::maxFruitNumber)
    {
        return;
    }

    int x = qrand() % (Data::width - 10) + 10;
    int y = qrand() % (Data::height - 10) + 10;
    Fruit* fruit = new Fruit(x, y);
    gameScene->addItem(fruit);
    fruitsNumber++;
}

