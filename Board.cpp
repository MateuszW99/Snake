#include "Board.h"
#include <QtDebug>
#include <QMessageBox>

Board::Board(int gameTime, int snakeLength)
{
    scene = new QGraphicsScene();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);
    setFixedSize(Data::width, Data::height);
    setSceneRect(0, 0, Data::width, Data::height);

    controller = new Controller{scene, nullptr, gameTime, snakeLength};

    QPixmap background{ "C:\\Users\\elekr\\OneDrive\\Studia\\obiektowe\\Snake\\download.jpg" };
    scene->setBackgroundBrush(background.scaled(width(), height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

    show();
}

Board::~Board()
{
    delete controller;
    delete scene;
}


















