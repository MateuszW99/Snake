#include "Menu.h"
#include <QDebug>
#include "Constants.h"

Menu::Menu(QWidget *parent)
{
    ui.setupUi(this);
}

Menu::~Menu()
{
    //delete menu;
}

//Menu::



void Menu::on_startGameButton_clicked()
{
    if(getTime() <= 0)
    {
        setTime(Data::defaultGameTime);
    }
    if(getLength() <= 0)
    {
        setLength(Data::defaultSnakeLength);
    }
    emit startGame();
}

void Menu::on_quitGameButton_clicked()
{
    emit quitGame();
;}
