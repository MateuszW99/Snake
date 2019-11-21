#pragma once
#include <QColor>

namespace Data {
    // Window
    constexpr int width = 800;
    constexpr int height = 600;
    // Snake
    constexpr int snakeSize = 10;
    constexpr qreal snakeRadius = 3.0;
    constexpr int yVelocity = 4;
    constexpr int xVelocity = 4;
    constexpr int FruitSpawnTime = 2500;
    constexpr int SnakeLatencySpeed = 50;    
    //Fruit
    constexpr int maxFruitNumber = 3;
    constexpr int fruitSize = 10;
    constexpr qreal fruitRadius = 3.0;
}
