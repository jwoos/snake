#include "direction.h"


Direction* constructDirection(int x, int y) {
	Direction* direction = malloc(sizeof *direction);

	direction -> x = x;
	direction -> y = y;

	return direction;
}

void deconstructDirection(Direction* direction) {
	free(direction);
	direction = NULL;
}
