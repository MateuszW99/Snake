#include "Menu.h"
#include <QDebug>

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
    emit startGameButtonClicked();
}
