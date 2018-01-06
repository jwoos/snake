#ifndef SNAKE_TIMING_H
#define SNAKE_TIMING_H


#include <signal.h>
#include <unistd.h>

#include "utils.h"


timer_t timerRegister(uint64_t, void (*handler)(int, siginfo_t*, void*));

void timerDeregister(timer_t);


#endif
