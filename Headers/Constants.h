#pragma once
#include <QObject>

namespace Data {
    // Window
    constexpr int defaultGameTime = 6;
    constexpr int width = 800;
    constexpr int height = 600;
    // Snake
    constexpr int defaultSnakeLength = 5;
    constexpr int snakeSize = 10;
    constexpr qreal snakeRadius = 3.0;
    static int velocity = 4;
    constexpr int snakeLatencySpeed = 20;
    constexpr int maxSpeed = 9;
    enum Direction
    {
        Left, Right, Up, Down
    };

    //Fruit
    constexpr int FruitSpawnTime = 200;
    constexpr int maxFruitNumber = 4;
    constexpr int fruitSize = 9;
    constexpr qreal fruitRadius = 3.0;
}
