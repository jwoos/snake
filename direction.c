#include "direction.h"


Direction* directionConstruct(DirectionOrientation dir) {
	Direction* direction = malloc(sizeof *direction);

	directionSet(direction, dir);

	return direction;
}

void directionDeconstruct(Direction* direction) {
	free(direction);
}

void directionSet(Direction* const direction, const DirectionOrientation dir) {
	direction -> orientation = dir;
	direction -> status = DIRECTION_STATUS_OKAY;
}

DirectionOrientation directionGet(Direction* const dir) {
	return dir -> orientation;
}

int directionValidate(const Direction* const Direction) {
	return 0;
}
