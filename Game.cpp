#include "Game.h"
#include <QDebug>
Game::Game()
    : menu{ new Menu() }
{
    connect(menu, &Menu::startGameButtonClicked, this, &Game::startGame);
    menu->show();
    //qDebug() << x;
}

Game::~Game()
{
    delete board;
    delete menu;
}

void Game::startGame()
{

    qDebug() << "signal received";
    menu->close();
    board = new Board();
}
