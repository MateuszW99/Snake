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

    void setLength(int value) { snakeLength = value; }
    int getLength() const;

    void setTime(int value) { time = value; }
    int getTime() const;

signals:
    void startGame() const;
    void quitGame() const;

private slots:
    void on_startGameButton_clicked();
    void on_quitGameButton_clicked();

private:
    Ui::Menu ui;

    int time;
    int snakeLength;
};
