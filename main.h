#ifndef SNAKE_MAIN_H
#define SNAKE_MAIN_H

#include <ncurses.h>
#include <stdint.h>

typedef struct {
	int x;
	int y;
} Position;

typedef struct {
	int x;
	int y;
} Direction;

typedef struct {
	Position* positions;
} Snake;

void renderBox();

bool checkBoundary(Position);

void renderSnake(uint32_t, uint32_t, uint32_t);

#endif
