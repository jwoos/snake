#include <stdlib.h>

#include "game.h"


int main(int argc, char* argv[]) {
	ncursesSetup();
	gameSetup();

	Snake* snake = Config.snake;
	Position* position = snake -> body -> head -> data;

	int ch;
	bool boundaryOkay = true;
	Direction direction;

	while (boundaryOkay) {
		clear();
		ch = getch();

		snakeRender(snake);

		direction = parseInput(ch);
		if (validateMove(snake -> body -> head -> data, &direction) == -1) {
			break;
		}

		if (direction.x) {
			position -> x += direction.x;
		} else if (direction.y) {
			position -> y += direction.y;
		}

		box(stdscr, 0, 0);
		refresh();
		boundaryOkay = snakeCheckBoundary(snake);

		nanosleep(&Config.timespec, NULL);
	}

	gameEndScreen();

	ncursesTeardown();
	gameTeardown();

	return 0;
}
