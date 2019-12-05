#pragma once
#include <QObject>
#include <QWidget>
#include <QLabel>
#include "ui_Menu.h"
#include <QPushButton>

class Menu : public QWidget
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

signals:
    void startGameButtonClicked();

private slots:
    void on_startGameButton_clicked();

private:
    Ui::Menu ui;
};
