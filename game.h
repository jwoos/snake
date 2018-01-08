#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H


#include <unistd.h>
#include <time.h>
#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>

#include "direction.h"
#include "global.h"
#include "item.h"
#include "linked-list.h"
#include "menu.h"
#include "snake.h"
#include "position.h"
#include "timing.h"
#include "utils.h"


void ncursesSetup(void);

void ncursesTeardown(void);

void gamePreSetup(void);

void gameSetup(void);

void gamePostSetup(void);

void gamePreTeardown(void);

void gameTeardown(void);

void gamePostTeardown(void);

DirectionOrientation parseInput(DirectionOrientation);

void gameEndScreen(void);

void gameEndScreenDebug(void);


#endif
