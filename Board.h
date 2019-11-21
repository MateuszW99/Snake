#pragma once
#include <QGraphicsView>
#include <QGraphicsObject>
#include <QWidget>
#include <QVector>
#include <QMainWindow>
#include "Snake.h"
#include "Fruit.h"
#include <QTimer>
#include <QGraphicsItem>
#include "Controller.h"

class Board : public QGraphicsView
{
    Q_OBJECT
public:
    Board();
    ~Board()
    {
        delete scene;
    }

private:
    QGraphicsScene* scene;

    QVector<Fruit*> Fruits;

    Controller* controller;

};
