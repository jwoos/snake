#include <stdlib.h>
#include <signal.h>

#include "game.h"


int main(int argc, char* argv[]) {
	ncursesSetup();
	gameSetup();

	int timerSignal = SIGRTMIN;

	Snake* snake = Config.snake;

	int ch;
	bool boundaryOkay = true;
	bool statusOkay = true;
	DirectionOrientation orientation;

	/*timer_t itemTimer = timerRegister(&timerSignal, )*/
	while (boundaryOkay && statusOkay) {
		clear();
		ch = getch();

		box(stdscr, 0, 0);
		snakeRender(snake);

		int originalOrientation = snake -> direction -> orientation;
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
	gameTeardown();

	return 0;
}
