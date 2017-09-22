#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H


#include <unistd.h>
#include <time.h>
#include <ncurses.h>

#include "direction.h"
#include "global.h"
#include "linked-list.h"
#include "menu.h"
#include "snake.h"
#include "position.h"
#include "utils.h"


void ncursesSetup();

void ncursesTeardown();

void gameSetup();

void gameTeardown();

DirectionOrientation parseInput(DirectionOrientation);

int validateMove(const Position* const position, const Direction* const direction);

void gameEndScreen();


#endif
