#ifndef SNAKE_POSITION_H
#define SNAKE_POSITION_H


#include <stdlib.h>


typedef struct Position {
	int x;
	int y;
} Position;

Position* constructPosition(int, int);

void deconstructPosition(Position*);


#endif
