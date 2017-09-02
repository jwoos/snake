#ifndef SNAKE_MAIN_H
#define SNAKE_MAIN_H


#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdint.h>

#include "direction.h"
#include "linked-list.h"
#include "position.h"
#include "global.h"


typedef struct Snake {
	struct List* positions;
	struct Direction* direction;
} Snake;

void renderBox();

int parseInput(Snake*, int);

bool checkBoundary(struct Position*);

void renderSnake(uint32_t, uint32_t, uint32_t);

#endif
