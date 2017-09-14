#include "direction.h"


Direction* directionConstruct(DirectionDirection dir) {
	Direction* direction = malloc(sizeof *direction);

	direction -> x = x;
	direction -> y = y;
	direction -> status = DIRECTION_STATUS_OKAY;

	return direction;
}

void directionDeconstruct(Direction* direction) {
	free(direction);
	direction = NULL;
}

void directionSetX(Direction* direction, const DirectionDirection newX) {
	direction -> y = DIRECTION_NONE;
	direction -> x = newX;
}

void directionSetY(Direction* direction, const newY) {
	direction -> x = DIRECTION_NONE;
	direction -> y = newY;
}

void directionSet(Direction* direction, const DirectionDirection dir) {
	switch (dir) {
		case DIRECTION_LEFT:
			direction -> directionSetX()
	}
}

int directionValidate(const Direction* const direction) {
	return 0;
}
