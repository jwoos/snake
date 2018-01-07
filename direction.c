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
	DirectionOrientation original = direction -> orientation;

	// not allowed to turn opposite
	if (abs(original + dir) != 1 || original == DIRECTION_ORIENTATION_NONE || dir == DIRECTION_ORIENTATION_NONE) {
		direction -> orientation = dir;
		direction -> status = DIRECTION_STATUS_OKAY;
	}
}

DirectionOrientation directionGet(Direction* const dir) {
	return dir -> orientation;
}
