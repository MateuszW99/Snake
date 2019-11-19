#include "Snake.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QTimer>
#include "Constants.h"
#include "Fruit.h"
#include <QVector>
using namespace Data;

SnakePart::~SnakePart() {}

Snake::Snake() : xDirection{xVelocity}, yDirection{0}
{
    head = new SnakePart();
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
