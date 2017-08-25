#include "main.h"

void renderBox() {
	box(stdscr, '|', '-');
}

void parseInput(int ch) {
	struct Direction direction = Config.direction;
	struct Position position = Config.position;

	switch (ch) {
		case 'w':
		case KEY_UP: {
			direction.x = 0;
			direction.y = -1;
			break;
		}

		case 's':
		case KEY_DOWN: {
			direction.x = 0;
			direction.y = 1;
			break;
		}

		case 'd':
		case KEY_RIGHT: {
			direction.x = 1;
			direction.y = 0;
			break;
		}

		case 'a':
		case KEY_LEFT: {
			direction.x = -1;
			direction.y = 0;
			break;
		}

		case 113: {
			run = FALSE;
			break;
		}

		default: {
			break;
		}
	}

	if (direction.x) {
		position.x += direction.x;
	} else if (direction.y) {
		position.y += direction.y;
	}

	if ((position.y == 1 && direction.y == -1) || (position.y == Config.maxY - 1 && direction.y == 1)) {
		break;
	} else if ((position.x == 1 && direction.x == -1) || (position.x == Config.maxX - 1 && direction.x == 1)) {
		break;
	}
}

bool checkBoundary(struct Position p) {

}

void renderSnake(uint32_t length, uint32_t x, uint32_t y) {

}
