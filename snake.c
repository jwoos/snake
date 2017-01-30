#include <stdlib.h>
#include <ncurses.h>

#include "menu.h"
#include "responsive.h"

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

	int* max = getMaxSize();
	int MAX_X = max[0];
	int MAX_Y = max[1];

	free(max);

	mvprintw(MAX_Y - 1, MAX_X - 20, "x: %d y: %d", MAX_X, MAX_Y);
	refresh();
	getch();
	clear();

	menu();

	// clear to end of line
	clrtoeol();

	// clean up ncurses
	endwin();

	return 0;
}
