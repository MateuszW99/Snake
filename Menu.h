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

    int getLength() const { return ui.lengthLine->text().toInt(); }
    int getTime() const { return ui.timerLine->text().toInt(); }

signals:
    void startGame() const;
    void quitGame() const;

private slots:
    void on_startGameButton_clicked();

    void on_quitGameButton_clicked();

private:
    Ui::Menu ui;
};
