#include "responsive.h"

int* getMaxSize() {
	int* max = malloc(sizeof(int) * 2);

	getmaxyx(stdscr, max[1], max[0]);

	// values start from 0 so there seems to be an off by one
	max[1] = max[1] - 1;
	max[0] = max[0] - 1;

	return max;
}

int center(int availableSize, int size) {
	int start = (availableSize - size) / 2;
	return start;
}
