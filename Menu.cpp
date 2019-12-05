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

int Menu::getTime()
{
    if(ui.timerLine->text().isEmpty() || getTime() <= 0)
    {
        setTime(Data::defaultGameTime);
    }
    return time;
}

int Menu::getLength()
{
    if(ui.lengthLine->text().isEmpty() || getLength() <= 0)
    {
        setLength(Data::defaultSnakeLength);
    }
    return snakeLength;
}


void Menu::on_startGameButton_clicked()
{
    emit startGame();
}

void Menu::on_quitGameButton_clicked()
{
    emit quitGame();
;}
