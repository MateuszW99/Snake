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
    snake->Setup();

    //scene->addItem(fruit);
    //fruit->Spawn();

    connect(spawnTimer, SIGNAL(timeout()), this, SLOT(SpawnFruit()));
    spawnTimer->start(Data::FruitSpawnTime);

    connect(snakeTimer, SIGNAL(timeout()), this, SLOT(MoveSnake()));
    snakeTimer->start(Data::SnakeLatencySpeed);

}



void Board::SpawnFruit()
{
    if(Fruits.count() >= Data::MaxFruitNumber)
    {
        return;
    }


    int x = qrand()% (Data::width - 10) + 10;
    int y = qrand()% (Data::height - 10) + 10;
    Fruit* fruit = new Fruit(x, y);
    scene->addItem(fruit);
}

void Board::MoveSnake()
{
    if(WallHit())
    {
        qDebug() << "Timer stopped";
        snakeTimer->stop();
    }

    CheckCollision();

    snake->setPos(snake->x() + snake->GetXDirection(), snake->y() + snake->GetYDirection());
    //qDebug() << snake->pos();
    snake->setFocus();
}

void Board::CheckCollision()
{
    for(auto i = 0; i < Fruits.count(); ++i)
    {
        //qDebug() << Fruits[i]->pos();
        /*if(ComparePositions(Fruits[i]->x(), Fruits[i]->y(), snake->x(), snake->y()))
        {
            qDebug() << "Fruit met";
        }*/
        if(snake->pos() == Fruits[i]->pos())
        {
            qDebug() << "Fruit met";
        }
    }
}

bool Board::ComparePositions(const double fX, const double fY, const double sX, const double sY) const
{
   return true;
}

bool Board::WallHit()
{
    if(snake->x() > Data::width/2|| x() < -Data::width/2|| y() > Data::height/2 || y() < -Data::height/2)
    {
        qDebug() << "Wall hit";
        return true;
    }
    return false;
}






















