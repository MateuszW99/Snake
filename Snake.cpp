#include "Snake.h"
#include <QDebug>
#include <QGraphicsScene>
#include "IControl.h"
#include <QTimer>
#include "Constants.h"

using namespace Data;

SnakePart::~SnakePart() {}

Snake::Snake() : xDirection{xVelocity}, yDirection{0}
{
    head = new SnakePart();
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(Move()));
    timer->start(20);
}

Snake::~Snake()
{
    delete head;
}

void Snake::Setup()
{
    setRect(width/2, height/2, 20, 20); // Set the starting point to the middle of the window and rect size to 20x20
    setBrush(QColor(0, 0, 204, 150));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

bool Snake::WallHit()
{
    //qDebug() << x() << ", " << y();
    if(x() > width/2|| x() < -width/2|| y() > height/2 || y() < -height/2)
    {
        qDebug() << "Wall hit";
        return true;
    }
    return false;
}

void Snake::Move()
{
    setPos(x() + xDirection, y() + yDirection);
    setFocus();
    qDebug() << x() << ", " << y();
    if(WallHit())
    {
        qDebug() << "Timer stopped";
        timer->stop();
    }  
}

void Snake::keyPressEvent(QKeyEvent* keyEvent)
{
    switch (keyEvent->key()) {
    case Qt::Key_Left:
    {
        qDebug() << "Left";
        MoveLeft();
        break;
    }
    case Qt::Key_Right:
    {
        qDebug() << "Right";
        MoveRight();
        break;
    }
    case Qt::Key_Up:
    {
        qDebug() << "Up";
        MoveUp();
        break;
    }
     case Qt::Key_Down:
    {
        qDebug() << "Down";
        MoveDown();
        break;
    }
    }
}

void Snake::MoveLeft()
{
    xDirection = -1 * xVelocity;
    yDirection = 0;
}

void Snake::MoveRight()
{
    xDirection = xVelocity;
    yDirection = 0;
}

void Snake::MoveUp()
{
    xDirection = 0;
    yDirection = -1 * yVelocity;
}

void Snake::MoveDown()
{
    xDirection = 0;
    yDirection = yVelocity;
}
