#include "Fruit.h"
#include <QGraphicsView>
#include "Constants.h"

Fruit::Fruit()
{
    //timer = new QTimer();
    //connect(timer, SIGNAL(timeout()), this, SLOT(Spawn()));
    //timer->start(Data::FruitSpawnTime);
    //////////
    //setRect(RandomWidth(), RandomHeight(), 20, 20); // Set the fruit to a rand point and its size to 10x10
    //setBrush(QColor(240, 20, 20, 150));
}

Fruit::~Fruit()
{
    //delete timer;
}

int Fruit::RandomWidth() const
{
    return rand()%(Data::width);
}

int Fruit::RandomHeight() const
{
    return rand()%(Data::height);
}


void Fruit::Spawn()
{
    setRect(RandomWidth(), RandomHeight(), 20, 20); // Set the fruit to a rand point and its size to 10x10
    setBrush(QColor(240, 20, 20, 150));
}
