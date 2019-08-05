#include "snake.h"

Snake::Snake(Coordinate head, std::vector<std::vector<bool> > &blocked, Xwindow *window)
    : blocked(blocked) {
    length = 5;
    for (int i = 1; i <= length; i++) {
        body.push_back(head);
        blocked[head.Y][head.X] = true;
        window->fillRectangle(head.X*7, head.Y*7, 7, 7, 0);
        if (!head.moveTo(Direction::W, blocked)) break;
    }
    readyToGrow = false;
    direction = Direction::E;
}

void Snake::changeDirection(Direction dir) {
    if (direction == Direction::N) {
        if (dir == Direction::S) return;
        direction = dir;
    }

    if (direction == Direction::E) {
        if (dir == Direction::W) return;
        direction = dir;
    }

    if (direction == Direction::W) {
        if (dir == Direction::E) return;
        direction = dir;
    }

    if (direction == Direction::S) {
        if (dir == Direction::N) return;
        direction = dir;
    }
}

int Snake::moveForward(Xwindow *window, Food &food) {
    Coordinate head = body.front();
    Coordinate tail = body.back();

    if (!head.moveTo(direction, blocked)) return 0;

    if (!readyToGrow) {
        window->fillRectangle(tail.X*7, tail.Y*7, 7, 7, 1);
        body.pop_back();
        blocked[tail.Y][tail.X] = false;
        length--;
    }
    readyToGrow = false;

    body.push_front(head);
    blocked[head.Y][head.X] = true;
    window->fillRectangle(head.X*7, head.Y*7, 7, 7, 0);
    length++;

    if (food.where == head) {
        readyToGrow = true;
        return 2;
    }

    return 1;
}
