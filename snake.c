#include <unistd.h>
#include <time.h>
#include <ncurses.h>

#include "global.h"
#include "menu.h"
#include "main.h"

int main(int argc, char* argv[]) {
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
	getmaxyx(stdscr, Config.maxX, Config.maxX);

	renderBox();

	/* On a terminal:
	 * for x positive is right while negative is left
	 * for y positive is DOWN while negative is up
	 */
	struct Direction* direction = malloc(sizeof *direction);
	direction -> x = 1;
	direction -> y = 0;

	struct Position* position = malloc(sizeof *position);
	position -> x = 1;
	position -> y = 1;

	Config.position = position;
	Config.direction = direction;

	// quarter of a second
	struct timespec t = {.tv_sec = 0, .tv_nsec = 250000000};
	int ch;
	int run = 0;

	while (run > -1) {
		clear();
		ch = getch();

		run = parseInput(ch);

		renderBox();
		mvprintw(position -> y, position -> x, ".");
		/*mvprintw(position -> y, position -> x, "■");*/
		refresh();

		nanosleep(&t, NULL);
	}

	nodelay(stdscr, FALSE);
	refresh();
	mvprintw(1, 1, "x: %d y: %d", position -> x, position -> y);
	mvprintw(2, 1, "Press any key to quit");
	getch();

	/*mvprintw(0, 0, "x: %d y: %d", maxX, maxY);*/
	/*wborder(stdscr, '|', '|', '-', '-', '+', '+', '+', '+');*/

	/*menu();*/

	// clear to end of line
	clrtoeol();

	// clean up ncurses
	endwin();

	return 0;
}
