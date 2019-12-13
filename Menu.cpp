#include "Menu.h"
#include "Constants.h"

Menu::Menu(QWidget *parent)
{
    ui.setupUi(this);
}

Menu::~Menu()
{
}

int Menu::getTime() const
{
    return time;
}

int Menu::getLength() const
{
    return snakeLength;
}

void Menu::on_startGameButton_clicked()
{
    snakeLength = ui.lengthLine->text().isEmpty() ? Data::defaultSnakeLength : ui.lengthLine->text().toInt();
    time = ui.timerLine->text().isEmpty() ? Data::defaultGameTime : ui.timerLine->text().toInt();
    emit startGame();
}

void Menu::on_quitGameButton_clicked()
{
    emit quitGame();
}
