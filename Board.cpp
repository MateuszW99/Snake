#include "Board.h"
#include "Constants.h"
#include <QtDebug>
#include <cmath>
#include <random>

Board::Board()
{
    scene = new QGraphicsScene();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);
    setFixedSize(Data::width, Data::height);
    setSceneRect(0, 0, Data::width, Data::height);
    controller = new Controller{scene};
}


















