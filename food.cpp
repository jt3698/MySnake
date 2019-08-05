#include "food.h"
#include "window.h"
#include <random>

Food::Food(std::vector<std::vector<bool> > &blocked, Xwindow *window) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1,blocked.size()-1); // define the range

    int X = distr(eng);
    int Y = distr(eng);
    while (blocked[Y][X]) {
        X = distr(eng);
        Y = distr(eng);
    }

    where = Coordinate(X, Y);
    window->fillRectangle(X*7, Y*7, 7, 7, 4);
}
