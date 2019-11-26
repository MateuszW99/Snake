#include "Controller.h"
#include "Constants.h"
#include "Fruit.h"
#include <QDebug>
#include <QFlags>

int Controller::fruitsNumber = 0;

Controller::Controller(QGraphicsScene* scene, QObject* parent) : QObject{ parent }, gameScene { scene }, snake { new Snake(scene) }
{
    scene->addItem(snake);
    scene->installEventFilter(this);

    fruitTimer = new QTimer();
    connect(fruitTimer, SIGNAL(timeout()), this, SLOT(spawnFruit()));
    fruitTimer->start(Data::FruitSpawnTime);

    snakeTimer = new QTimer;
    connect(snakeTimer, SIGNAL(timeout()), this, SLOT(moveSnake()));
    snakeTimer->start(Data::snakeLatencySpeed);
}

Controller::~Controller()
{
    delete snakeTimer;
    delete snake;
    delete fruitTimer;
}

void Controller::moveSnake()
{
    if(checkWallCollision() || checkSnakeCollision()) // hitting a wall means losing the game
    {
        snakeTimer->stop();
        return;
    }

    checkItemCollision();

    snake->move();

    //qDebug() << snake->head->pos();
    snake->setFocus();
}


void Controller::spawnFruit()
{
    if(checkFruitsNumber()) // If there are more fruits than Data::maxFruitNumber, don't add a new one
    {
        return;
    }
    gameScene->addItem(new Fruit(qrand() % (Data::width - 10) + 10, qrand() % (Data::height - 10) + 10));
    fruitsNumber++;
}

bool Controller::checkWallCollision() const
{
    return snake->wallHit() ? true : false;
}

bool Controller::checkSnakeCollision() const
{
    return snake->intersects() ? true : false;
}

void Controller::checkItemCollision() const
{
    snake->checkCollision();
}

bool Controller::checkFruitsNumber() const
{
    return fruitsNumber >= Data::maxFruitNumber ? true : false;
}

bool Controller::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
            keyPressEvent(dynamic_cast<QKeyEvent*>(event));
            return true;
    }
    else
    {
        return QObject::eventFilter(watched, event);
    }
}


void Controller::keyPressEvent(QKeyEvent* keyEvent)
{
    switch (keyEvent->key()) {
    case Qt::Key_Left:
    {
        if(snake->getXDirection() <= 0 && snake->getDirection() != Data::Direction::Left)
        {
            snake->moveLeft();
        }
        break;
    }
    case Qt::Key_Right:
    {
        if(snake->getXDirection() >= 0 && snake->getDirection() != Data::Direction::Right)
        {
            snake->moveRight();
        }
        break;
    }
    case Qt::Key_Up:
    {
        if(snake->getYDirection() <= 0 && snake->getDirection() != Data::Direction::Up)
        {
            snake->moveUp();
        }
        break;
    }
    case Qt::Key_Down:
    {
        if(snake->getYDirection() >= 0 && snake->getDirection() != Data::Direction::Down)
        {
            snake->moveDown();
        }
        break;
    }
    }
}

