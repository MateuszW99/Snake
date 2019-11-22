#pragma once
#include <QGraphicsView>
#include <QWidget>
#include <QMainWindow>
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
    QGraphicsScene* scene = nullptr;
    Controller* controller = nullptr;
};
