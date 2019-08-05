#ifndef _GRID_H
#define _GRID_H

#include "food.h"
#include "snake.h"
#include "window.h"
#include "direction.h"
#include <vector>

class Grid
{
    int sizing;
    Snake *snake;
    Food *curFood;
    std::vector<std::vector<bool> > blocked;
    Xwindow *window;

public:
    Grid(int n);
    bool update(bool changed, Direction direction);
	~Grid();
};

#endif // _GRID_H
