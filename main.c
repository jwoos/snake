#include <unistd.h>
#include <time.h>
#include <ncurses.h>

#include "direction.h"
#include "global.h"
#include "linked-list.h"
#include "menu.h"
#include "snake.h"
#include "position.h"

int main(int argc, char* argv[]) {
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

	Config.minX = 0;
	Config.minY = 0;
	getmaxyx(stdscr, Config.maxY, Config.maxX);

	// quarter of a second
	Config.timespec.tv_sec = 0;
	Config.timespec.tv_nsec = 250000000;

	renderBox();

	Direction* direction = directionConstruct(DIRECTION_RIGHT, DIRECTION_NONE);
	Position* position = positionConstruct(1, 1);
	ListNode* head = listNodeConstruct(position, NULL, NULL);
	List* positions = listConstruct(head);

	int ch;
	bool boundaryOkay = true;
	int run = 0;

	while (run > -1 && boundaryOkay) {
		clear();
		ch = getch();

		run = parseInput(ch);

		renderBox();
		mvprintw(position -> y, position -> x, "■");
		refresh();

		nanosleep(&Config.timespec, NULL);
		boundaryOkay = checkBoundary(position);
	}

	nodelay(stdscr, FALSE);
	refresh();
	mvprintw(1, 1, "x: %d y: %d", position -> x, position -> y);
	mvprintw(2, 1, "max x: %d max y: %d", Config.maxX, Config.maxY);
	mvprintw(3, 1, "Press any key to quit");
	getch();

	// clear to end of line
	clrtoeol();

	// clean up ncurses
	endwin();

	free(position);
	free(direction);

	return 0;
}
