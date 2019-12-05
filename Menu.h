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

    void setLength(int value) { ui.lengthLine->text() = QString::number(value); }
    int getLength() const { return ui.lengthLine->text().toInt(); }

    void setTime(int value) { ui.timerLine->text() = QString::number(value); }
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
