#ifndef _SNAKE_H
#define _SNAKE_H

#include "coordinate.h"
#include "direction.h"
#include "food.h"
#include "window.h"
#include <deque>
#include <vector>

class Snake
{
    int length;
    std::deque<Coordinate> body;
    bool readyToGrow;
    Direction direction;
    std::vector<std::vector<bool> > &blocked;

public:
    Snake(Coordinate head, std::vector<std::vector<bool> > &blocked, Xwindow *window);

    // Return
    // 0 - Blocked move
    // 1 - Successful move, no food
    // 2 - Successful move with food
    int moveForward(Xwindow *window, Food &food);

    void changeDirection(Direction dir);
};

#endif // _SNAKE_H
