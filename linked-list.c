#include "linked-list.h"


List* listConstruct(ListNode* node) {
	List* list = malloc(sizeof *list);

	if (!node) {
		list -> head = NULL;
		list -> tail = NULL;
		list -> size = 0;
	} else {
		list -> head = node;
		list -> tail = node;
		list -> size = 1;
	}

	return list;
}

void listDeconstruct(List* list) {
	ListNode* current = list -> head;

	while (current != list -> tail) {
		ListNode* next = current -> next;
		free(current);

		current = next;
	}

	free(list);
	list = NULL;
}

ListNode* listNodeConstruct(void* data, ListNode* next) {
	ListNode* node = malloc(sizeof *node);

	node -> data = data;
	node -> next = next;
	next -> prev = NULL;

	return node;
}

void listNodeDeconstruct(ListNode* node) {
	ListNode* previous = node -> previous;
	ListNode* next = node -> next;

	previous -> next = next;
	next -> previous = previous

	free(node -> data);
	free(node);
}
