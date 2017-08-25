#ifndef SNAKE_MAIN_H
#define SNAKE_MAIN_H


#include <ncurses.h>
#include <stdint.h>

#include "global.h"


struct Position {
	int x;
	int y;
} Position;

struct Direction {
	int x;
	int y;
} Direction;

struct Snake {
	Position* positions;
} Snake;

void renderBox();

void move(int);

bool checkBoundary(struct Position);

void renderSnake(uint32_t, uint32_t, uint32_t);

#endif
