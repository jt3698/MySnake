#ifndef _FOOD_H
#define _FOOD_H

#include "coordinate.h"
#include "window.h"
#include <vector>

class Food
{
public:
    Coordinate where;

    Food(std::vector<std::vector<bool> > &blocked, Xwindow *window);
};

#endif // _SNAKE_H
