#include "Board.h"
#include "Constants.h"

Board::Board()
{
    snake = new Snake();
    scene = new QGraphicsScene();


    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);
    setFixedSize(Data::width, Data::height);
    setSceneRect(0, 0, width(), height());

    scene->addItem(snake);
    snake->Setup();



}
