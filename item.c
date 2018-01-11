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

void itemAdd(uint8_t** itemBoard, Vector* items, Snake* snake) {
	uint64_t x = randomNumber(1, Config.maxX - 1);
	uint64_t y = randomNumber(1, Config.maxY - 1);

	if (itemBoard[y][x] == 0) {
		Vector* body = snake -> body;

		for (uint32_t i = 0; i < body -> size; i++) {
			Position* pos = vectorGet(body, i);
			if (pos -> x == x && pos -> y == y) {
				itemAdd(itemBoard, items, snake);
			}
		}

		Position* item = positionConstruct(x, y);
		vectorPush(items, item);
		itemBoard[y][x] = 1;
	} else {
		itemAdd(itemBoard, items, snake);
	}
}

void itemRender(Vector* items) {
	Position* position;
	for (uint64_t i = 0; i < items -> size; i++) {
		position = vectorGet(items, i);
		mvprintw(position -> y, position -> x, ITEM_BODY);
	}
}

void itemTimerHandler(int sig, siginfo_t* si, void* userContext) {
	Config.sigCount++;
	itemAdd(Config.board, Config.items, Config.snake);
}
