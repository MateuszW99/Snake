#include "Board.h"
#include "Constants.h"
#include <QtDebug>
#include <math.h>

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
    setSceneRect(0, 0, width(), height());

    scene->addItem(snake);
    snake->Setup();

    //scene->addItem(fruit);
    //fruit->Spawn();

    connect(spawnTimer, SIGNAL(timeout()), this, SLOT(SpawnFruit()));
    spawnTimer->start(Data::FruitSpawnTime);

    connect(snakeTimer, SIGNAL(timeout()), this, SLOT(MoveSnake()));
    snakeTimer->start(Data::SnakeLatencySpeed);

    /*if(timer->isActive())
    {
        qDebug() << "timer started";
    }*/
}



void Board::SpawnFruit()
{
    if(Fruits.count() >= Data::MaxFruitNumber)
    {
        return;
    }
    Fruits.push_back(new Fruit{});
    scene->addItem(Fruits.last());
    Fruits.last()->Spawn();
    //qDebug() << "Owoc: " << Fruits.last()->x() << ", " << Fruits.last()->y();
}

void Board::MoveSnake()
{
    snake->setFocus();
    CheckCollision();
    if(WallHit())
    {
        qDebug() << "Timer stopped";
        snakeTimer->stop();
    }
    snake->setPos(snake->x() + snake->GetXDirection(), snake->y() + snake->GetYDirection());
}

void Board::CheckCollision()
{
    for(auto i = 0; i < Fruits.count(); ++i)
    {
        if(ComparePositions(Fruits[i]->x(), Fruits[i]->y(), snake->x(), snake->y()))
        {
            qDebug() << "Fruit met";
        }
    }
}

bool Board::ComparePositions(const double fX, const double fY, const double sX, const double sY) const
{
    if(fX == sX && fY == sY)
    {
qDebug() << "Pos compared";
        return true;
    }

    return false;
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






















