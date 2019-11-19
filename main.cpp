//#include "mainwindow.h"
#include "Board.h"
#include <QApplication>
#include <QLabel>
#include <QDebug>
#include <random>

int main(int argc, char *argv[])
{
    qsrand(time(NULL));
    QApplication app(argc, argv);
    Board* window = new Board();
    window->show();
    return app.exec();
}
