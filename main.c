#include "main.h"

void renderBox() {
	box(stdscr, 0, 0);
}

int parseInput(int ch) {
	struct Direction* direction = Config.direction;
	struct Position* position = Config.position;

	switch (ch) {
		case 'w':
		case KEY_UP: {
			direction -> x = 0;
			direction -> y = -1;
			break;
		}

		case 's':
		case KEY_DOWN: {
			direction -> x = 0;
			direction -> y = 1;
			break;
		}

		case 'd':
		case KEY_RIGHT: {
			direction -> x = 1;
			direction -> y = 0;
			break;
		}

		case 'a':
		case KEY_LEFT: {
			direction -> x = -1;
			direction -> y = 0;
			break;
		}

		case 113: {
			return -1;
			break;
		}

		default: {
			break;
		}
	}

	if (direction -> x) {
		position -> x += direction -> x;
	} else if (direction -> y) {
		position -> y += direction -> y;
	}

	if ((position -> y == 1 && direction -> y == -1) || (position -> y == Config.maxY - 1 && direction -> y == 1)) {
		return 0;
	} else if ((position -> x == 1 && direction -> x == -1) || (position -> x == Config.maxX - 1 && direction -> x == 1)) {
		return 0;
	}

	return 1;
}

bool checkBoundary(struct Position* p) {
	bool okay = true;

	// it hit top or left
	if (p -> y <= Config.minY || p -> y >= Config.maxY) {
		okay = false;
	} else if (p -> x <= Config.minX || p -> x >= Config.maxX) {
		okay = false;
	}

	return okay;
}

void renderSnake(uint32_t length, uint32_t x, uint32_t y) {

}
