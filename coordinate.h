#ifndef _COORDINATE_H
#define _COORDINATE_H

#include "direction.h"
#include <vector>

struct Coordinate
{
    int X,Y;

    Coordinate(int X = 0, int Y = 0);
    bool moveTo(Direction dir, std::vector<std::vector<bool> > &blocked); // Return if Crash or Not

	bool operator==(const Coordinate &other) const;
};

#endif // _COORDINATE_H
