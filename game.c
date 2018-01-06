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

	Config.board = malloc(sizeof(void*) * (Config.maxY - 2) * (Config.maxX - 2));

	Config.timespec.tv_sec = TIMESPEC_SEC;
	Config.timespec.tv_nsec = TIMESPEC_NANOSEC;

	box(stdscr, 0, 0);
	Config.snake = snakeConstruct();
}

void gameTeardown() {
	free(Config.board);
	snakeDeconstruct(Config.snake);
}

DirectionOrientation parseInput(int ch) {
	DirectionOrientation direction;

	switch (ch) {
		case 'w':
		case KEY_UP:
			direction = DIRECTION_ORIENTATION_UP;
			break;

		case 's':
		case KEY_DOWN:
			direction = DIRECTION_ORIENTATION_DOWN;
			break;

		case 'd':
		case KEY_RIGHT:
			direction = DIRECTION_ORIENTATION_RIGHT;
			break;

		case 'a':
		case KEY_LEFT:
			direction = DIRECTION_ORIENTATION_LEFT;
			break;

		// quit
		case 'q':
			direction = DIRECTION_ORIENTATION_NONE;
			break;

		default:
			direction = directionGet(Config.snake -> direction);
			break;
	}

	return direction;
}

int validateMove(const Position* const position, const Direction* const direction) {
	if (direction -> orientation == DIRECTION_ORIENTATION_NONE) {
		return -1;
	}

	if ((position -> y == 1 && direction -> orientation == DIRECTION_ORIENTATION_UP) || (position -> y == Config.maxY - 1 && direction -> orientation == DIRECTION_ORIENTATION_DOWN)) {
		return 0;
	} else if ((position -> x == 1 && direction -> orientation == DIRECTION_ORIENTATION_LEFT) || (position -> x == Config.maxX - 1 && direction -> orientation == DIRECTION_ORIENTATION_RIGHT)) {
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
