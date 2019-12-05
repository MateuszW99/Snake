#include <QApplication>
#include <random>
#include "Game.h"

int main(int argc, char *argv[])
{
    qsrand(time(NULL));

    QApplication app(argc, argv);


    Game* window = new Game();

    return app.exec();
}
