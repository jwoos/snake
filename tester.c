#include <unistd.h>
#include <time.h>
#include <ncurses.h>

#include "global.h"
#include "linked-list.h"
#include "menu.h"
#include "main.h"


int main(int argc, char* argv[]) {
	int randData = 10;
	ListNode* node = listNodeConstruct(&randData, NULL, NULL);
	List* list = listConstruct(node);
	listPush(list, &randData);

	listPrint(list);
}
