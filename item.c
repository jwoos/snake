#include "item.h"


Item* itemConstruct(Position* position) {
	Item* item = malloc(sizeof(*item));

	item -> position = position;

	return item;
}

void itemDeconstruct(Item* item) {
	positionDeconstruct(item -> position);
	free(item);
}
