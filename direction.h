#ifndef SNAKE_DIRECTION_H
#define SNAKE_DIRECTION_H


#include <stdlib.h>


/* On a terminal:
 * for x positive is right while negative is left
 * for y positive is DOWN while negative is up
 */
#define DIRECTION_RIGHT 1
#define DIRECTION_LEFT -1
#define DIRECTION_UP -1
#define DIRECTION_DOWN 1
#define DIRECTION_NONE 0


typedef struct Direction {
	int x;
	int y;
} Direction;

Direction* constructDirection(int, int);

void deconstructDirection(Direction*);


#endif
