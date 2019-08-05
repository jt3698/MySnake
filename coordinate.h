#ifndef _COORDINATE_H
#define _COORDINATE_H

#include "direction.h"
#include <vector>

struct Coordinate
{
    int X,Y;

    Coordinate(int X,int Y);
    bool moveTo(Direction dir, std::vector<std::vector<bool> > &blocked); // Return if Crash or Not
};

#endif // _COORDINATE_H
