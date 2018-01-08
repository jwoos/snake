#ifndef SNAKE_GLOBAL_H
#define SNAKE_GLOBAL_H


#include <stdbool.h>
#include <time.h>

#include "snake.h"
#include "vector.h"


#define MOVE_UNIT 1

#define TIMESPEC_SEC 0
#define TIMESPEC_NANOSEC 100000000 // 0.1 second

#define SNAKE_BODY "■"
#define ITEM_BODY "·"


struct Config {
	uint32_t minX;
	uint32_t minY;
	uint32_t maxX;
	uint32_t maxY;

	struct Snake* snake;
	struct timespec timespec;

	timer_t itemTimer;

	bool debug;

	uint8_t** board;
} Config;


#endif
