#include "position.h"


Position* constructPosition(int x, int y) {
	Position* position = malloc(sizeof *position);

	position -> x = x;
	position -> y = y;

	return position;
}

void deconstructPosition(Position* position) {
	free(position);
	position = NULL;
}
