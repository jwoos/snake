#include <stdlib.h>
#include <signal.h>

#include "game.h"


int main(int argc, char* argv[]) {
	ncursesSetup();

	gamePreSetup();
	gameSetup();
	gamePostSetup();

	Snake* snake = Config.snake;

	int ch;
	bool boundaryOkay = true;
	bool statusOkay = true;
	DirectionOrientation orientation;

	while (boundaryOkay && statusOkay) {
		clear();
		ch = getch();

		box(stdscr, 0, 0);
		snakeRender(snake);

		orientation = parseInput(ch);
		directionSet(snake -> direction, orientation);

		if (snake -> direction -> orientation == DIRECTION_ORIENTATION_NONE) {
			break;
		}

		statusOkay = snakeAdvance(snake);

		refresh();
		boundaryOkay = snakeCheckBoundary(snake);

		nanosleep(&Config.timespec, NULL);
	}

	gameEndScreen();

	ncursesTeardown();
	gamePreTeardown();
	gameTeardown();
	gamePostTeardown();

	printf("test\n");

	return 0;
}
