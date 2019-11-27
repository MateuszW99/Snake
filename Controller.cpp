#include "Controller.h"
#include "Constants.h"
#include "Fruit.h"
#include <QDebug>
#include <QFlags>
#include <QMessageBox>
#include <QApplication>

int Controller::fruitsNumber = 0;

Controller::Controller(QGraphicsScene* scene, QObject* parent) : QObject{ parent }, gameScene { scene }, snake { new Snake(scene) }
{
    scene->addItem(snake);
    scene->installEventFilter(this);

    fruitTimer = new QTimer();
    connect(fruitTimer, SIGNAL(timeout()), this, SLOT(spawnFruit()));

    snakeTimer = new QTimer;
    connect(snakeTimer, SIGNAL(timeout()), this, SLOT(moveSnake()));

    startTimers();
}

Controller::~Controller()
{
    delete snakeTimer;
    delete snake;
    delete fruitTimer;
}

void Controller::moveSnake()
{
    checkCollisions();
    snake->move();
    snake->setFocus();
}

void Controller::startTimers() const
{
    fruitTimer->start(Data::FruitSpawnTime);
    snakeTimer->start(Data::snakeLatencySpeed);
}

void Controller::stopTimers() const
{
    fruitTimer->stop();
    snakeTimer->stop();
}



void Controller::checkCollisions()
{
    if(checkWallCollision()) // hitting a wall means losing the game
    {
        snake->goThroughWall();
    }
    if(checkSnakeCollision())
    {
        stopGame();
    }
    checkItemCollision();
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

void Controller::stopGame()
{
    stopTimers();

    QMessageBox::StandardButton reply{ QMessageBox::question(nullptr, "You lost", "Do you want try again?",
                                                             QMessageBox::Yes | QMessageBox::No) };
    if (reply == QMessageBox::Yes)
    {
        restartGame();
    }
    if(reply == QMessageBox::No)
    {
        quitGame();
    }
}

void Controller::restartGame()
{
    gameScene->clear();
    fruitsNumber = 0;
    snake = new Snake(gameScene);
    gameScene->addItem(snake);
    startTimers();
}

void Controller::quitGame() const
{
    QApplication::quit();
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

