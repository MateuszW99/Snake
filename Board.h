#pragma once
#include <QGraphicsView>
#include <QWidget>
#include <QMainWindow>
#include "Menu.h"
#include "Controller.h"

class Board : public QGraphicsView
{
    Q_OBJECT
public:
    Board(QObject* = nullptr);
    ~Board();

private:
    QGraphicsScene* scene = nullptr;
    Menu* menu = nullptr;
    Controller* controller = nullptr;
};
