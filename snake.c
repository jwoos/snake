#include <unistd.h>
#include <time.h>
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
	renderBox();

	/* On a terminal:
	 * for x positive is right while negative is left
	 * for y positive is DOWN while negative is up
	 */
	Direction direction = {.x = 1, .y = 0};
	Position position = {.x = 1, .y = 1};

	// quarter of a second
	struct timespec t = {.tv_sec = 0, .tv_nsec = 250000000};
	bool run = TRUE;
	int ch;

	while (run) {
		clear();
		ch = getch();

		switch (ch) {
			case KEY_UP: {
				direction.x = 0;
				direction.y = -1;
				break;
			}

			case KEY_DOWN: {
				direction.x = 0;
				direction.y = 1;
				break;
			}

			case KEY_RIGHT: {
				direction.x = 1;
				direction.y = 0;
				break;
			}

			case KEY_LEFT: {
				direction.x = -1;
				direction.y = 0;
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

		if (direction.x) {
			position.x += direction.x;
		} else if (direction.y) {
			position.y += direction.y;
		}

		if ((position.y == 1 && direction.y == -1) || (position.y == maxY - 1 && direction.y == 1)) {
			break;
		} else if ((position.x == 1 && direction.x == -1) || (position.x == maxX - 1 && direction.x == 1)) {
			break;
		}

		renderBox();
		mvprintw(position.y, position.x, "o");
		refresh();
		/*sleep(1);*/
		nanosleep(&t);
	}

	nodelay(stdscr, FALSE);
	refresh();
	mvprintw(1, 1, "x: %d y: %d", position.x, position.y);
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
