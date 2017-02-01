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

	menu();

	// clear to end of line
	clrtoeol();

	// clean up ncurses
	endwin();

	return 0;
}
