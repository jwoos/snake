#ifndef SNAKE_GLOBAL_H
#define SNAKE_GLOBAL_H


#include <time.h>

#include "snake.h"


#define MOVE_UNIT 1
#define TIMESPEC_SEC 0
#define TIMESPEC_NANOSEC 100000000 // 0.1 second

struct Config {
	uint32_t minX;
	uint32_t minY;
	uint32_t maxX;
	uint32_t maxY;

	struct Snake* snake;
	struct timespec timespec;
} Config;


#endif
