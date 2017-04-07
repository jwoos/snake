#include <unistd.h>
#include <ncurses.h>

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

	int minX = 0;
	int minY = 0;
	int maxX;
	int maxY;

	getmaxyx(stdscr, maxY, maxX);
	box(stdscr, '|', '-');

	int direction[] = {1, 0};
	int position[] = {1, 1};
	bool run = TRUE;
	int ch;

	while (run) {
		clear();
		ch = getch();

		switch (ch) {
			case KEY_UP: {
				direction[0] = 0;
				direction[1] = -1;
				break;
			}

			case KEY_DOWN: {
				direction[0] = 0;
				direction[1] = 1;
				break;
			}

			case KEY_RIGHT: {
				direction[0] = 1;
				direction[1] = 0;
				break;
			}

			case KEY_LEFT: {
				direction[0] = -1;
				direction[1] = 0;
				break;
			}

			case 113: {
				run = FALSE;
				break;
			}

			default: {
				break;
			}
		}

		if (direction[0]) {
			position[0] += direction[0];
		} else if (direction[1]) {
			position[1] += direction[1];
		}

		if ((position[1] == 1 && direction[1] == -1) || (position[1] == maxY - 1 && direction[1] == 1)) {
			break;
		} else if ((position[0] == 1 && direction[0] == -1) || (position[0] == maxX - 1 && direction[0] == 1)) {
			break;
		}

		box(stdscr, '|', '-');
		mvprintw(position[1], position[0], "o");
		refresh();
		sleep(1);
		/*nanosleep(1000000);*/
	}

	nodelay(stdscr, FALSE);
	refresh();
	mvprintw(0, 0, "x: %d y: %d", position[0], position[1]);
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
