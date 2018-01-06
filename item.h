#ifndef SNAKE_ITEM_H
#define SNAKE_ITEM_H


#include <signal.h>

#include "global.h"
#include "position.h"


extern List* items;


typedef struct Item {
	Position* position;
} Item;


Item* itemConstruct(Position*);

void itemDeconstruct(Item*);

void itemTimerHandler(int, siginfo_t*, void*);


#endif

