#ifndef SNAKE_LINKED_LIST_H
#define SNAKE_LINKED_LIST_H


#include <stdlib.h>
#include <stdbool.h>


typedef struct List {
	struct List* head;
	struct List* tail;
	uint32_t size;
} List;

typedef struct ListNode {
	struct ListNode* next;
	struct ListNode* previous;
	void* data;
} ListNode;

List* listConstruct(ListNode*);

void listDeconstruct(List*);

ListNode* listNodeConstruct(void*, ListNode*);

void listNodeDeconstruct(ListNode*);

#endif
