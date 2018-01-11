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
#include "vector.h"


typedef struct Snake {
	Vector* body;
	Direction* direction;
	bool modified;
} Snake;


Snake* snakeConstruct();

void snakeDeconstruct(Snake*);

bool snakeCheckBoundary(Snake*);

void snakeAdd(Snake*);

void snakeRender(Snake*);

bool snakeAdvance(Snake*);

void snakeConsume(Snake*, Vector*, uint8_t**);


#endif
