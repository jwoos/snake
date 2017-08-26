#ifndef SNAKE_GLOBAL_H
#define SNAKE_GLOBAL_H


#include "main.h"


struct Config {
	uint32_t minX;
	uint32_t minY;
	uint32_t maxX;
	uint32_t maxY;

	struct Position* position;
	struct Direction* direction;
	struct Snake* snake;
} Config;


#endif
