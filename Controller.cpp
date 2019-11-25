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
    snakeTimer->start(Data::SnakeLatencySpeed); 
}

Controller::~Controller()
{
    delete snakeTimer;
    delete snake;
    delete fruitTimer;
}

void Controller::moveSnake()
{
    if(checkWallCollision()) // hitting a wall means losing the game
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
    if(snake->wallHit())
    {
        return true;
    }
    return false;
}

void Controller::checkItemCollision() const
{
    snake->checkCollision();
}

bool Controller::checkFruitsNumber() const
{
    if(fruitsNumber >= Data::maxFruitNumber)
    {
        return true;
    }
    return false;
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
        if(snake->getXDirection() <= 0)
        {
            snake->moveLeft();
        }
        break;
    }
    case Qt::Key_Right:
    {
        if(snake->getXDirection() >= 0)
        {
            snake->moveRight();
        }
        break;
    }
    case Qt::Key_Up:
    {
        if(snake->getYDirection() <= 0)
        {
            snake->moveUp();
        }
        break;
    }
    case Qt::Key_Down:
    {
        if(snake->getYDirection() >= 0)
        {
            snake->moveDown();
        }
        break;
    }
    }
}

