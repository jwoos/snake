#include "game.h"


void ncursesSetup() {
	// set locale to support wide character
	setlocale(LC_CTYPE, "");

	// start ncurses
	initscr();
	clear();

	/* pass EVERYTHING as keycodes, even ignoring signals
	 * disables buffering and prints directly
	 */
	raw();

	// Take non alphanumeric keys
	keypad(stdscr, TRUE);

	// don't echo while getting input
	noecho();

	// no delay
	nodelay(stdscr, TRUE);

	// don't show cursor
	curs_set(FALSE);
}

void ncursesTeardown() {
	// clear to end of line
	clrtoeol();

	// clean up ncurses
	endwin();
}

void gameSetup() {
	Config.minX = 0;
	Config.minY = 0;
	getmaxyx(stdscr, Config.maxY, Config.maxX);

	// quarter of a second
	Config.timespec.tv_sec = 0;
	Config.timespec.tv_nsec = 250000000;

	box(stdscr, 0, 0);
	Config.snake = snakeConstruct();
}

void gameTeardown() {

}

Direction parseInput(int ch) {
	Direction direction;

	switch (ch) {
		case 'w':
		case KEY_UP: {
			direction.x = 0;
			direction.y = -1;
			break;
		}

		case 's':
		case KEY_DOWN: {
			direction.x = 0;
			direction.y = 1;
			break;
		}

		case 'd':
		case KEY_RIGHT: {
			direction.x = 1;
			direction.y = 0;
			break;
		}

		case 'a':
		case KEY_LEFT: {
			direction.x = -1;
			direction.y = 0;
			break;
		}

		// quit
		case 113: {
			direction.x = 0;
			direction.y = 0;
			break;
		}

		default: {
			break;
		}
	}

	return direction;
}

int validateMove(Position* position, Direction* direction) {
	if (!direction -> x && !direction -> y) {
		return -1;
	}

	if ((position -> y == 1 && direction -> y == -1) || (position -> y == Config.maxY - 1 && direction -> y == 1)) {
		return 0;
	} else if ((position -> x == 1 && direction -> x == -1) || (position -> x == Config.maxX - 1 && direction -> x == 1)) {
		return 0;
	}

	return 1;
}

void gameEndScreen() {
	Position* position = Config.snake -> body -> head -> data;
	nodelay(stdscr, FALSE);
	refresh();
	mvprintw(1, 1, "x: %d y: %d", position -> x, position -> y);
	mvprintw(2, 1, "max x: %d max y: %d", Config.maxX, Config.maxY);
	mvprintw(3, 1, "Press any key to quit");
	getch();
}
