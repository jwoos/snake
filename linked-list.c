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
	free(node -> data);
	free(node);
	node = NULL;
}


void listPush(List* list, void* data) {
	ListNode* tail = list -> tail;

	ListNode* newElem = listNodeInitialize(data, NULL);

	tail -> next = newElem;
	newElem -> previous = tail;
	list -> tail = newElem;
	list -> size++;
}

ListNode* listPop(List* list) {
	ListNode* tail = list -> tail;
	ListNode* current = tail -> previous;

	previous -> next = NULL;
	tail -> previous = NULL;

	list -> tail = current;
	list -> size--;

	return tail;
}

ListNode* listGet(List* list, int index) {
	if (index < 0 || index >= list -> size) {
		printf("Element not found at index %d - outside of range\n", index);
		return NULL;
	}

	if (index <= (list -> size) / 2) {
		ListNode* node = list -> head;

		int i = 0;
		while (i < index) {
			if (node != NULL) {
				i++;
				node = node -> next;
			} else {
				printf("Element not found at index %d outside of range\n", index);
				return NULL;
			}
		}
	} else {
		ListNode* node = list -> tail;

		int i = list -> size - 1;
		while (i > index) {
			if (node != NULL) {
				i--;
				node = node -> previous;
			} else {
				printf("Element not found at index %d outside of range\n", index);
				return NULL;
			}
		}
	}

	return node;
}

void listSet(List* list, int index, void* newData) {
	ListNode* atIndex = listGetElement(list, index);

	if (atIndex == NULL) {
		printf("Not setting - aborting...\n");
		return;
	}

	free(atIndex -> data);
	atIndex -> data = newData;
}

void listInsert(List* list, int index, void* newData) {
	ListNode* previous = listGetElement(list, index - 1);
	ListNode* newNode = listNodeInitialize(newData, previous -> next);
	ListNode* next = previous -> next;

	newNode -> previous = previous;

	previous -> next = newNode;
	next -> previous = newNode;

	list -> size++;
}

void listDelete(List* list, int index) {
	ListNode* previous = listGetElement(list, index - 1);
	ListNode* temp = previous -> next;
	ListNode* next = temp -> next;

	previous -> next = next;
	next -> previous = previous

	listNodeDeconstruct(temp);
	list -> size--;
}

void listClear(List* list) {
	ListNode* current = list -> head;

	while (current != NULL) {
		ListNode* next = current -> next;
		listNodeDeconstruct(current);

		current = next;
	}

	list -> head = NULL;
	list -> tail = NULL;
	list -> size = 0;
}
