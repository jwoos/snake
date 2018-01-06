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

// add stuff for item timer handler
void itemTimerHandler(int sig, siginfo_t* si, void* userContext) {
	signal(sig, SIG_IGN);
}
