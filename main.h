#ifndef SNAKE_MAIN_H
#define SNAKE_MAIN_H


#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
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
	struct Position* positions;
} Snake;

void renderBox();

int parseInput(int);

bool checkBoundary(struct Position);

void renderSnake(uint32_t, uint32_t, uint32_t);

#endif
