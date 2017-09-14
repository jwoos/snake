#ifndef SNAKE_DIRECTION_H
#define SNAKE_DIRECTION_H


#include <stdlib.h>


/* On a terminal:
 * for x positive is right while negative is left
 * for y positive is DOWN while negative is up
 */
typedef enum DirectionDirection {
	DIRECTION_LEFT=-2,
	DIRECTION_UP=-1,
	DIRECTION_NONE 0,
	DIRECTION_RIGHT=1,
	DIRECTION_DOWN=2
} DirectionDirection;

// errors
typedef enum DirectionStatus {
	DIRECTION_STATUS_OKAY,
	DIRECTION_STATUS_ERROR,
	DIRECTION_STATUS_ABORT,
	DIRECTION_STATUS_EXIT
} DirectionStatus;

typedef struct Direction {
	DirectionDirection x;
	DirectionDirection y;
	DirectionStatus status;
} Direction;

Direction* directionConstruct(int, int);

void directionDeconstruct(Direction*);

void directionSetX(Direction*, const int);

void directionSetY(Direction*, const int);

void directionSetRaw(Direction* const, const int, const int);

int directionValidate(const Direction* const);


#endif
