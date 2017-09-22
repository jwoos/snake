#include <stdlib.h>

#include "game.h"


int main(int argc, char* argv[]) {
	ncursesSetup();
	gameSetup();

	Snake* snake = Config.snake;
	Position* position = snake -> body -> head -> data;

	int ch;
	bool boundaryOkay = true;
	DirectionOrientation orientation;

	while (boundaryOkay) {
		clear();
		ch = getch();

		box(stdscr, 0, 0);
		snakeRender(snake);

		orientation = parseInput(ch);
		directionSet(Config.snake -> direction, orientation);

		if (Config.snake -> direction -> orientation == DIRECTION_ORIENTATION_NONE) {
			break;
		}
		/*
		 *if (directionValidate(snake -> body -> head -> data, &orientation) == -1) {
		 *    break;
		 *}
		 */

		switch (orientation) {
			case DIRECTION_ORIENTATION_DOWN:
			case DIRECTION_ORIENTATION_UP:
				position -> y += max(min(MOVE_UNIT, orientation), -MOVE_UNIT);
				break;

			case DIRECTION_ORIENTATION_RIGHT:
			case DIRECTION_ORIENTATION_LEFT:
				position -> x += max(min(MOVE_UNIT, orientation), -MOVE_UNIT);
				break;

			default:
				// there was an error let's get out
				boundaryOkay = false;
		}

		refresh();
		boundaryOkay = snakeCheckBoundary(snake);

		nanosleep(&Config.timespec, NULL);
	}

	gameEndScreen();

	ncursesTeardown();
	gameTeardown();

	return 0;
}
