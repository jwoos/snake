#include "item.h"


uint8_t** itemConstruct(void) {
	uint8_t** itemBoard = malloc(sizeof(uint8_t*) * Config.maxY);
	for (uint64_t i = 0; i < Config.maxY; i++) {
		itemBoard[i] = calloc(Config.maxX, sizeof(uint8_t));
	}

	return itemBoard;
}

void itemDeconstruct(uint8_t** itemBoard) {
	for (uint64_t i = 0; i < Config.maxY; i++) {
		free(itemBoard[i]);
	}
	free(itemBoard);
}

void itemAdd(uint8_t** itemBoard) {
	uint64_t x = randomNumber(1, Config.maxX - 1);
	uint64_t y = randomNumber(1, Config.maxY - 1);

	// TODO handle collision with snake
	if (itemBoard[y][x] == 0) {
		Config.board[y][x] = 1;
	} else {
		itemAdd(itemBoard);
	}
}

// add stuff for item timer handler
void itemTimerHandler(int sig, siginfo_t* si, void* userContext) {
	itemAdd(Config.board);
}
