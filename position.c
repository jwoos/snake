#include "position.h"


Position* positionConstruct(int x, int y) {
	Position* position = malloc(sizeof *position);

	position -> x = x;
	position -> y = y;

	return position;
}

void positionDeconstruct(Position* position) {
	free(position);
	position = NULL;
}

void positionIncrementX(Position* position) {
	position -> x++;
}

void positionIncrementY(Position* position) {
	position -> y++;
}
