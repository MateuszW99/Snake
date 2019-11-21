#include "Board.h"
#include "Constants.h"
#include <QtDebug>
#include <cmath>
#include <random>


Board::Board()
{
    snake = new Snake();
    scene = new QGraphicsScene();
    spawnTimer = new QTimer();
    snakeTimer = new QTimer();

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);
    setFixedSize(Data::width, Data::height);
    setSceneRect(0, 0, Data::width, Data::height);

    scene->addItem(snake);
    snake->setPos(Data::width / 2, Data::height / 2);
    //scene->addItem(fruit);
    //fruit->Spawn();
    snake->setFocus();
    connect(spawnTimer, SIGNAL(timeout()), this, SLOT(SpawnFruit()));
    spawnTimer->start(Data::FruitSpawnTime);

    connect(snakeTimer, SIGNAL(timeout()), this, SLOT(MoveSnake()));
    snakeTimer->start(Data::SnakeLatencySpeed);

}



void Board::SpawnFruit()
{
    if(Fruits.count() >= Data::maxFruitNumber)
    {
        return;
    }


    int x = qrand() % (Data::width - 10) + 10;
    int y = qrand() % (Data::height - 10) + 10;
    Fruit* fruit = new Fruit(x, y);
    scene->addItem(fruit);
}
// TODO: food eating

void Board::MoveSnake()
{
    if(snake->WallHit())
    {
        qDebug() << "Timer stopped";
        snakeTimer->stop();
    }

    snake->CheckCollision();
    snake->setPos(snake->x() + snake->GetXDirection(), snake->y() + snake->GetYDirection());
    qDebug() << snake->pos();
    snake->setFocus();
}

























