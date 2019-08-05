#include "grid.h"
Grid::Grid(int n) {
    sizing = n;
    window = new Xwindow(n*7, n*7);

    blocked.resize(n);
    for (int i = 0; i < n; i++) blocked[i].resize(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            window->fillRectangle(i*7, j*7, 7, 7, 1);

    for (int i = 0; i < n; i++) {
            blocked[i][0] = true;
            window->fillRectangle(0, i*7, 7, 7, 2);
            blocked[i][n-1] = true;
            window->fillRectangle((n-1)*7, i*7, 7, 7, 2);
    }
    for (int i = 0; i < n; i++) {
            blocked[0][i] = true;
            window->fillRectangle(i*7, 0, 7, 7, 2);
            blocked[n-1][i] = true;
            window->fillRectangle(i*7, (n-1)*7, 7, 7, 2);
    }

    snake = new Snake(Coordinate(10,10), blocked, window);
    curFood = new Food(blocked, window);
}

bool Grid::update(bool changed, Direction direction) {
	if (changed)
        snake->changeDirection(direction);

    int res = snake->moveForward(window, *curFood);
    if (res == 0) return false;

    if (res == 2) {
	    delete curFood;
	    curFood = new Food(blocked, window);
    }

    return true;
}

Grid::~Grid() {
	delete window;
	delete snake;
	delete curFood;
}
