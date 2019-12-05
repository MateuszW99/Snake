#pragma once
#include "Board.h"
#include "Menu.h"
#include <QObject>

class Game : public QObject
{
    Q_OBJECT
public:
    Game();
    ~Game();

public slots:
    void startGame();

private:
    Board* board = nullptr;
    Menu* menu = nullptr;
};
