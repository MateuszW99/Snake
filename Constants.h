#pragma once
#include <QObject>

namespace Data {
    // Window
    constexpr int width = 800;
    constexpr int height = 600;
    // Snake
    constexpr int snakeSize = 10;
    constexpr qreal snakeRadius = 3.0;
    static int velocity = 4;
    constexpr int snakeLatencySpeed = 50;
    constexpr int maxSpeed = 12;
    enum Direction
    {
        Left, Right, Up, Down
    };

    //Fruit
    constexpr int FruitSpawnTime = 3000;
    constexpr int maxFruitNumber = 4;
    constexpr int fruitSize = 10;
    constexpr qreal fruitRadius = 3.0;
}
