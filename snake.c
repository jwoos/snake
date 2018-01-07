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

// FIXME it should set backwards so as not to propagate one value
bool snakeAdvance(Snake* snake) {
	bool boundaryOkay = true;

	List* body = snake -> body;

	ListNode* current = body -> head -> next;
	ListNode* previous = body -> head;

	Position* currentPosition = current -> data;
	Position* previousPosition = previous -> data;

	while (current != NULL) {
		if (snake -> modified && current == snake -> body -> tail) {
			snake -> modified = false;
			break;
		}

		if (current == snake -> body -> tail) {
			positionDeconstruct(currentPosition);
		}

		currentPosition = previousPosition;

		previous = current;
		current = current -> next;
		currentPosition = current -> data;
		previousPosition = previous -> data;
	}

	DirectionOrientation orientation = snake -> direction -> orientation;
	Position* headPosition = body -> head -> data;
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
			boundaryOkay = false;
	}

	return boundaryOkay;
}
