#include <stdlib.h>

#include "game.h"


int main(int argc, char* argv[]) {
	ncursesSetup();
	gameSetup();

	Snake* snake = Config.snake;
	Position* position = snake -> body -> head -> data;

	int ch;
	bool boundaryOkay = true;
	DirectionOrientation direction;

	while (boundaryOkay) {
		clear();
		ch = getch();

		box(stdscr, 0, 0);
		snakeRender(snake);

		direction = parseInput(ch);
		directionSet(Config.snake -> direction, direction);

		if (!Config.snake -> direction -> x && !Config.snake -> direction -> y) {
			break;
		}
		/*
		 *if (directionValidate(snake -> body -> head -> data, &direction) == -1) {
		 *    break;
		 *}
		 */

		if (direction.x) {
			position -> x += direction.x;
		} else if (direction.y) {
			position -> y += direction.y;
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
