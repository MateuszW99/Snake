#pragma once
#include "Board.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Board* board;
    MainWindow *ui;
};
