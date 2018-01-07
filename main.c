#include <stdlib.h>
#include <signal.h>

#include "game.h"


int main(int argc, char* argv[]) {
	ncursesSetup();
	gameSetup();

	int timerSignal = SIGRTMIN;

	Snake* snake = Config.snake;
	Position* position = snake -> body -> head -> data;

	int ch;
	bool boundaryOkay = true;
	DirectionOrientation orientation;

	/*timer_t itemTimer = timerRegister(&timerSignal, )*/
	while (boundaryOkay) {
		clear();
		ch = getch();

		box(stdscr, 0, 0);
		snakeRender(snake);

		int originalOrientation = Config.snake -> direction -> orientation;
		orientation = parseInput(ch);
		directionSet(Config.snake -> direction, orientation);

		if (Config.snake -> direction -> orientation == DIRECTION_ORIENTATION_NONE) {
			break;
		}

		List* body = snake -> body;
		ListNode* current = body -> head;
		while (current != NULL) {
			if (snake -> modified && current == snake -> body -> tail) {
				snake -> modified = false;
				break;
			}

			position = current -> data;
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

			current = current -> next;
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
