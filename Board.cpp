#include "Board.h"
#include <QtDebug>
#include <QMessageBox>

Board::Board(QObject* parent)
{
    /*scene = new QGraphicsScene();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);
    setFixedSize(Data::width, Data::height);
    setSceneRect(0, 0, Data::width, Data::height);

    controller = new Controller{scene, parent};

    QPixmap background{ "C:\\Users\\elekr\\OneDrive\\Studia\\obiektowe\\Snake\\download.jpg" };
    scene->setBackgroundBrush(background.scaled(width(), height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));*/
    this->hide();

    menu = new Menu();

    menu->show();
}

Board::~Board()
{
    delete controller;
    delete scene;
    delete menu;
}


















