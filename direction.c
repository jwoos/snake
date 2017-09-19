#include "direction.h"


Direction* directionConstruct(DirectionOrientation dir) {
	Direction* direction = malloc(sizeof *direction);

	directionSet(direction, dir);

	return direction;
}

void directionDeconstruct(Direction* direction) {
	free(direction);
}

void directionSetX(Direction* direction, const DirectionOrientation newX) {
	direction -> y = DIRECTION_ORIENTATION_NONE;
	direction -> x = newX;
}

void directionSetY(Direction* direction, const DirectionOrientation newY) {
	direction -> x = DIRECTION_ORIENTATION_NONE;
	direction -> y = newY;
}

void directionSet(Direction* const direction, const DirectionOrientation dir) {
	switch (dir) {
		case DIRECTION_ORIENTATION_LEFT:
			directionSetX(direction, -1);
			break;

		case DIRECTION_ORIENTATION_RIGHT:
			directionSetX(direction, 1);
			break;

		case DIRECTION_ORIENTATION_UP:
			directionSetY(direction, -1);
			break;

		case DIRECTION_ORIENTATION_DOWN:
			directionSetY(direction, 1);
			break;

		case DIRECTION_ORIENTATION_NONE:
		default:
			break;
	}

	direction -> status = DIRECTION_STATUS_OKAY;
}

int directionValidate(const Direction* const Direction) {
	return 0;
}
