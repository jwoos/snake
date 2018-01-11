#include <stdlib.h>
#include <signal.h>

#include "game.h"


int main(int argc, char* argv[]) {
	if (argc > 1) {
		Config.debug = true;
	} else {
		Config.debug = false;
	}

	// ncurses gets set up
	gamePreSetup();
	gameSetup();
	gamePostSetup();

	Snake* snake = Config.snake;

	int ch;
	bool okay = true;

	while (okay) {
		clear();
		ch = getch();

		box(stdscr, 0, 0);
		snakeRender(snake);
		itemRender(Config.items);

		directionSet(snake -> direction, parseInput(ch));

		if (snake -> direction -> orientation == DIRECTION_ORIENTATION_NONE) {
			break;
		}

		okay = snakeAdvance(snake);

		refresh();
		okay = snakeCheckBoundary(snake);

		nanosleep(&Config.timespec, NULL);
	}

	// show statistics before they're gone
	gamePreTeardown();
	gameTeardown();
	// ncurses gets torn down
	gamePostTeardown();

	return 0;
}
