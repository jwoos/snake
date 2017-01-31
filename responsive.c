#include "responsive.h"

int* getMaxSize() {
	int* max = malloc(sizeof(int) * 2);

	getmaxyx(stdscr, max[1], max[0]);

	// values start from 0 so there seems to be an off by one
	max[1] = max[1] - 1;
	max[0] = max[0] - 1;

	return max;
}

// TODO finish implementing
int getCenter(int x, int y) {
	int* max = {0, 0};

	if (!x || !y) {
		max = getMaxSize();
	} else if (x && y) {
		max[0] = x;
		max[1] = y;
	}
}

int* center() {}
