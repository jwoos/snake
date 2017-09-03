#include "game.h"


void renderBox() {
	box(stdscr, 0, 0);
}

void parseInput(int ch) {
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

		// quit
		case 113: {
			break;
		}

		default: {
			break;
		}
	}
}

int validateMove(Position* position, Direction* direction) {
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
