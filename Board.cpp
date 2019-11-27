#include "Board.h"
#include "Constants.h"
#include <QtDebug>
#include <cmath>
#include <random>

Board::Board(QObject* parent)
{
    scene = new QGraphicsScene();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);
    setFixedSize(Data::width, Data::height);
    setSceneRect(0, 0, Data::width, Data::height);
    controller = new Controller{scene, parent};

    QPixmap background{ "C:\\Users\\elekr\\OneDrive\\Studia\\obiektowe\\Snake\\download.jpg" };
    scene->setBackgroundBrush(background.scaled(width(), height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}


















