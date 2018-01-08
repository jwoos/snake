#ifndef SNAKE_TIMING_H
#define SNAKE_TIMING_H


#include <signal.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

#include "global.h"
#include "utils.h"


timer_t timerRegister(int, uint64_t, void (*handler)(int, siginfo_t*, void*));

void timerDeregister(timer_t);


#endif
