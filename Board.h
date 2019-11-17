#pragma once
#include <QGraphicsView>
#include <QGraphicsObject>
#include "Snake.h"
#include <QWidget>
class Board : public QGraphicsView
{
public:
    Board();


private:
    QGraphicsScene* scene;
    Snake* snake;

};
