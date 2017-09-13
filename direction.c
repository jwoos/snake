#include "direction.h"


Direction* directionConstruct(int x, int y) {
	Direction* direction = malloc(sizeof *direction);

	direction -> x = x;
	direction -> y = y;

	return direction;
}

void directionDeconstruct(Direction* direction) {
	free(direction);
	direction = NULL;
}


void directionSetX(Direction* direction, int newX) {
	direction -> y = DIRECTION_NONE;
	direction -> x = newX;
}

void directionSetY(Direction* direction, int newY) {
	direction -> x = DIRECTION_NONE;
	direction -> y = newY;
}

void directionSetRaw(Direction* const direction) {
}

int directionValidate(const Direction* const direction) {
	return 0;
}
