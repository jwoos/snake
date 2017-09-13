#ifndef SNAKE_GLOBAL_H
#define SNAKE_GLOBAL_H


#include <time.h>

#include "snake.h"


struct Config {
	uint32_t minX;
	uint32_t minY;
	uint32_t maxX;
	uint32_t maxY;

	struct Snake* snake;
	struct timespec timespec;
} Config;


#endif
