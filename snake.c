#include "snake.h"


Snake* snakeConstruct() {
	Snake* snake = malloc(sizeof *snake);

	Direction* direction = directionConstruct(DIRECTION_ORIENTATION_RIGHT);
	Position* position = positionConstruct(1, 1);
	ListNode* head = listNodeConstruct(position, NULL, NULL);
	List* positions = listConstruct(head);

	snake -> body = positions;
	snake -> direction = direction;

	return snake;
}

void snakeDeconstruct(Snake* snake) {
	directionDeconstruct(snake -> direction);
	listClear(snake -> body);
	listDeconstruct(snake -> body);
	free(snake);
	snake = NULL;
}

bool snakeCheckBoundary(Snake* snake) {
	Position* p = snake -> body -> head -> data;
	bool okay = true;

	// it hit top or left
	if (p -> y <= Config.minY || p -> y >= Config.maxY) {
		okay = false;
	} else if (p -> x <= Config.minX || p -> x >= Config.maxX) {
		okay = false;
	}

	return okay;
}

void snakeRender(Snake* snake) {
	Position* position = snake -> body -> head -> data;
	mvprintw(position -> y, position -> x, "■");
}
