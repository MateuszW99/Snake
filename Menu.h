#pragma once
#include <QObject>
#include <QWidget>
#include "ui_Menu.h"



class Menu : public QWidget
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

private:
    Ui::Menu ui;
};
