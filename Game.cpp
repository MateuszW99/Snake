#include "Game.h"

Game::Game()
    : menu{ new Menu() }
{
    connect(menu, &Menu::startGame, this, &Game::startGame);
    connect(menu, &Menu::quitGame, this, &Game::quitGame);
    menu->show();
}

Game::~Game()
{
    delete board;
    delete menu;
}

void Game::startGame()
{
    menu->close();
    board = new Board(menu->getTime(), menu->getLength());
}

void Game::quitGame()
{
    QApplication::quit();
}
