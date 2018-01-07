#include "snake.h"


Snake* snakeConstruct() {
	Snake* snake = malloc(sizeof *snake);

	Direction* direction = directionConstruct(DIRECTION_ORIENTATION_RIGHT);
	Position* position = positionConstruct(1, 1);
	Vector* body = vectorConstruct(16);
	vectorPush(body, position);

	snake -> body = body;
	snake -> direction = direction;

	return snake;
}

void snakeDeconstruct(Snake* snake) {
	directionDeconstruct(snake -> direction);
	vectorDeconstruct(snake -> body, positionDeconstruct);
	free(snake);
}

bool snakeCheckBoundary(Snake* snake) {
	Position* p = vectorGet(snake -> body, 0);
	bool okay = true;

	// it hit top or left
	if (p -> y <= Config.minY || p -> y >= Config.maxY) {
		okay = false;
	} else if (p -> x <= Config.minX || p -> x >= Config.maxX) {
		okay = false;
	}

	return okay;
}

void snakeAdd(Snake* snake) {
	Vector* body = snake -> body;
	Position* tail = vectorGet(body, body -> size - 1);
	vectorPush(body, positionConstruct(tail -> x, tail -> y));
}

void snakeRender(Snake* snake) {
	Position* current;

	for (uint64_t i = 0 ; i < snake -> body -> size; i++) {
		current = vectorGet(snake -> body, i);
		mvprintw(current -> y, current -> x, SNAKE_BODY);
	}
}

// FIXME it should set backwards so as not to propagate one value
bool snakeAdvance(Snake* snake) {
	bool okay = true;

	Vector* body = snake -> body;

	Position* current = NULL;
	Position* previous = NULL;

	for (int i = body -> size - 1; i >= 0; i--) {
		current = vectorGet(body, i);

		if (previous != NULL) {
			previous -> x = current -> x;
			previous -> y = current -> y;
		}

		previous = current;
	}

	Position* headPosition = vectorGet(body, 0);
	DirectionOrientation orientation = snake -> direction -> orientation;
	switch (orientation) {
		case DIRECTION_ORIENTATION_DOWN:
		case DIRECTION_ORIENTATION_UP:
			headPosition -> y += max(min(MOVE_UNIT, orientation), -MOVE_UNIT);
			break;

		case DIRECTION_ORIENTATION_RIGHT:
		case DIRECTION_ORIENTATION_LEFT:
			headPosition -> x += max(min(MOVE_UNIT, orientation), -MOVE_UNIT);
			break;

		default:
			okay = false;
	}

	return okay;
}
