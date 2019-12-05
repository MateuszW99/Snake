#include "Game.h"
#include <QDebug>
Game::Game()
    : menu{ new Menu() }
{
    connect(menu, &Menu::startGame, this, &Game::startGame);
    connect(menu, &Menu::quitGame, this, &Game::quitGame);
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
    qDebug() << menu->getTime();
    menu->close();
    board = new Board();
}

void Game::quitGame()
{
    QApplication::quit();
}
