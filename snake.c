#include "snake.h"


Snake* snakeConstruct() {
	Snake* snake = malloc(sizeof *snake);

	Direction* direction = directionConstruct(DIRECTION_ORIENTATION_RIGHT);
	Position* position = positionConstruct(1, 1);
	ListNode* head = listNodeConstruct(position, NULL, NULL);
	List* positions = listConstruct(head);

	snake -> body = positions;
	snake -> direction = direction;
	snake -> modified = false;

	return snake;
}

void snakeDeconstruct(Snake* snake) {
	directionDeconstruct(snake -> direction);
	listDeconstruct(snake -> body, positionDeconstruct);
	free(snake);
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

void snakeAdd(Snake* snake) {
	List* body = snake -> body;
	Position* tail = body -> tail -> data;
	listPush(body, positionConstruct(tail -> x, tail -> y));
	snake -> modified = true;
}

void snakeRender(Snake* snake) {
	ListNode* current = snake -> body -> head;
	while (current != NULL) {
		Position* position = current -> data;
		mvprintw(position -> y, position -> x, SNAKE_BODY);
		current = current -> next;
	}
}
