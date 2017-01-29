#include "menu.h"

char* menuChoices[] = {
	"Option 1",
	"Option 2",
	"Option 3",
	"Option 4"
};

int menuChoicesCount = sizeof(menuChoices) / sizeof(char*);

void printMenu(WINDOW* menuWindow, int highlight) {
	int x = 2;
	int y = 2;
	box(menuWindow, 0, 0);

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

	int WIDTH = 30;
	int HEIGHT = 10;

	int startx = (80 - WIDTH) / 2;
	int starty = (24 - HEIGHT) / 2;

	WINDOW* menuWindow = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menuWindow, true);
	mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
	refresh();

	printMenu(menuWindow, highlight);
	while (1) {
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

			default: {
				mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", ch, ch);
				refresh();
				break;
			}
		}

		printMenu(menuWindow, highlight);
		if (choice != 0) {
			break;
		}
	}
}
