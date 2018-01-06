#ifndef SNAKE_ITEM_H
#define SNAKE_ITEM_H


#include "position.h"


typedef struct Item {
	Position* position;
} Item;


Item* itemConstruct(Position*);

void itemDeconstruct(Item*);


#endif

