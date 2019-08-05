#include "coordinate.h"

Coordinate::Coordinate(int X, int Y)
        : X(X), Y(Y) {}

bool Coordinate::moveTo(Direction dir, std::vector<std::vector<bool> > &blocked) {
    if (dir == Direction::N) {
            if (blocked[Y-1][X]) return false;
            Y--;
            return true;
    }
    if (dir == Direction::E) {
            if (blocked[Y][X+1]) return false;
            X++;
            return true;
    }
    if (dir == Direction::W) {
            if (blocked[Y][X-1]) return false;
            X--;
            return true;
    }
    if (dir == Direction::S) {
            if (blocked[Y+1][X]) return false;
            Y++;
            return true;
    }
	
    return true;
}

bool Coordinate::operator==(const Coordinate &other) const {
	return (other.X == X && other.Y == Y);
}
