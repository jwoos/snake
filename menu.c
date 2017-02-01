#include "menu.h"
#include "responsive.h"

char* menuChoices[] = {
	"Start",
	"Help",
	"About"
};

unsigned int menuChoicesCount = sizeof(menuChoices) / sizeof(char*);

void printMenu(WINDOW* menuWindow, int highlight) {
	int x = 2;
	int y = 2;

	for (int i = 0; i < menuChoicesCount; i++) {
		if (highlight == i + 1) {
			wattron(menuWindow, A_REVERSE);
			mvwprintw(menuWindow, y, x, "%s", menuChoices[i]);
			wattroff(menuWindow, A_REVERSE);
		} else {
			mvwprintw(menuWindow, y, x, "%s", menuChoices[i]);
		}
		y++;
	}

	wrefresh(menuWindow);
}

void menu() {
	int highlight = 1;
	int choice = 0;
	int ch;

	int* MAX = getMaxSize();

	int maxWidth = MAX[0];
	int maxHeight = MAX[1] - 20;

	free(MAX);

	int startx = center(maxWidth, MENU_WIDTH);
	int starty = center(maxHeight, MENU_HEIGHT) + 20;

	WINDOW* menuWindow = newwin(MENU_HEIGHT, MENU_WIDTH, starty, startx);
	keypad(menuWindow, true);
	mvprintw(5, center(maxWidth, 5), "SNAKE");
	refresh();

	printMenu(menuWindow, highlight);
	unsigned int cont = 1;
	while (cont) {
		ch = wgetch(menuWindow);
		switch (ch) {
			case KEY_UP: {
				if (highlight == 1) {
					highlight = menuChoicesCount;
				} else {
					highlight--;
				}
				break;
			}

			case KEY_DOWN: {
				if (highlight == menuChoicesCount) {
					highlight = 1;
				} else {
					highlight++;
				}
				break;
			}

			case 10:
			case KEY_ENTER: {
				choice = highlight;
				break;
			}

			case 113: {
				cont = 0;
			}

			default: {
				break;
			}
		}

		printMenu(menuWindow, highlight);

		if (choice != 0) {
			cont = 0;
		}
	}
}
