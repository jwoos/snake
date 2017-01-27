#include <ncurses.h>

int main(int argc, char* argv[]) {
	// start ncurses
	initscr();

	/* pass EVERYTHING as keycodes, even ignoring signals
	 * disables buffering
	 */
	raw();

	// Take non alphanumeric keys
	keypad(stdscr, TRUE);

	// don't echo while getting input
	noecho();

	// get user input
	int ch = getch();
	if (ch == KEY_UP) {
		printw("Up arrow pressed");
	} else {
		printw("The pressed key is: ");
		attron(A_BOLD);
		printw("%c", ch);
		attroff(A_BOLD);
	}
	refresh();

	getch();

	// clean up ncurses
	endwin();

	return 0;
}
