#include "Controller.h"
#include <QMessageBox>
#include <QApplication>
#include "Constants.h"
#include "Fruit.h"

int Controller::fruitsNumber = 0;
int Controller::score = 0;

Controller::Controller(QGraphicsScene* scene, QObject* parent, int time, int length)
          : QObject{ parent }, gameScene { scene }, snake { new Snake(scene, length) },
            gameTime{ time * 60000 }, snakeLength{ length }
{
    scene->addItem(snake);
    scene->installEventFilter(this);
    fruitTimer = new QTimer();
    connect(fruitTimer, SIGNAL(timeout()), this, SLOT(spawnFruit()));

    snakeTimer = new QTimer();
    connect(snakeTimer, SIGNAL(timeout()), this, SLOT(moveSnake()));

    gameTimer = new QElapsedTimer();

    startTimers();
}

Controller::~Controller()
{
    delete snake;
    delete snakeTimer;
    delete gameTimer;
    delete fruitTimer;
}

void Controller::moveSnake()
{
    if(gameTimer->elapsed() >= gameTime)
    {
        stopGame();
    }
    checkCollisions();
    snake->move();
    snake->setFocus();
}

void Controller::startTimers() const
{
    gameTimer->start();
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

    QMessageBox::StandardButton reply{ QMessageBox::question(nullptr, "You lost", gameEndMessage(),
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
    fruitsNumber = 0;
    score = 0;
    gameScene->clear();
    snake = new Snake(gameScene, snakeLength);
    gameScene->addItem(snake);
    startTimers();
}

void Controller::quitGame() const
{
    QApplication::quit();
}

QString Controller::gameEndMessage() const
{
    QString message;
    message.append("Score: ");
    message.append(QString::number(score * 10));
    message.append("\nPlay again?");
    return message;
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

