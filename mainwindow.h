#pragma once
#include <QMainWindow>
//#include <QGraphicsScene>
//#include <QGraphicsView>
//#include <QGraphicsRectItem>
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
