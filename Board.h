#pragma once
#include <QGraphicsView>
#include <QWidget>
#include <QMainWindow>
#include "Controller.h"

class Board : public QGraphicsView
{
    Q_OBJECT
public:
    Board(int, int);
    ~Board();

private:
    QGraphicsScene* scene = nullptr;
    Controller* controller = nullptr;
};
