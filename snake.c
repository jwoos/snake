#include "snake.h"


bool snakeCheckBoundary(Snake* snake) {
	Position* p = snake -> head -> data;
	bool okay = true;

	// it hit top or left
	if (p -> y <= Config.minY || p -> y >= Config.maxY) {
		okay = false;
	} else if (p -> x <= Config.minX || p -> x >= Config.maxX) {
		okay = false;
	}

	return okay;
}
