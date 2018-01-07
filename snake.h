#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H


#include <locale.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#include "direction.h"
#include "linked-list.h"
#include "position.h"
#include "global.h"


typedef struct Snake {
	struct List* body;
	struct Direction* direction;
	bool modified;
} Snake;

Snake* snakeConstruct();

void snakeDeconstruct(Snake*);

bool snakeCheckBoundary(Snake*);

void snakeRender(Snake*);

bool snakeAdvance(Snake*);


#endif
