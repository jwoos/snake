#ifndef SNAKE_ITEM_H
#define SNAKE_ITEM_H


#include <signal.h>
#include <stdio.h>

#include "global.h"
#include "position.h"
#include "utils.h"


uint8_t** itemConstruct(void);

void itemDeconstruct(uint8_t**);

void itemAdd(uint8_t**, Vector*);

void itemRender(Vector*);

void itemTimerHandler(int, siginfo_t*, void*);


#endif

