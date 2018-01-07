#ifndef SNAKE_DIRECTION_H
#define SNAKE_DIRECTION_H


#include <stdlib.h>


/* On a terminal:
 * for x positive is right while negative is left
 * for y positive is DOWN while negative is up
 */
typedef enum DirectionOrientation {
	DIRECTION_ORIENTATION_LEFT=-2,
	DIRECTION_ORIENTATION_UP=-1,
	DIRECTION_ORIENTATION_NONE=0,
	DIRECTION_ORIENTATION_RIGHT=1,
	DIRECTION_ORIENTATION_DOWN=2
} DirectionOrientation;

// errors
typedef enum DirectionStatus {
	DIRECTION_STATUS_OKAY,
	DIRECTION_STATUS_ERROR,
	DIRECTION_STATUS_ABORT,
	DIRECTION_STATUS_EXIT
} DirectionStatus;

typedef struct Direction {
	DirectionOrientation orientation;
	DirectionStatus status;
} Direction;

Direction* directionConstruct(DirectionOrientation);

void directionDeconstruct(Direction*);

DirectionOrientation directionGet(Direction* const);

void directionSet(Direction* const, const DirectionOrientation);


#endif
