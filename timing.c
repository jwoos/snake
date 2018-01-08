#include "timing.h"


timer_t timerRegister(int* sig, uint64_t nanoseconds, void (*handler)(int, siginfo_t*, void*)) {
	timer_t timerid;
	struct sigevent sev;
	struct itimerspec its;
	struct sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);

	if (sigaction(*sig, &sa, NULL) < 0) {
		errorExit("sigaction");
	}

	sev.sigev_notify = SIGEV_SIGNAL;
	sev.sigev_signo = *sig;
	sev.sigev_value.sival_ptr = &timerid;
	if (timer_create(CLOCK_REALTIME, &sev, &timerid) < 0) {
		errorExit("timer_create");
	}

	its.it_value.tv_sec = nanoseconds / 1000000000;
	its.it_value.tv_nsec = nanoseconds % 1000000000;
	its.it_interval.tv_sec = its.it_value.tv_sec;
	its.it_interval.tv_nsec = its.it_value.tv_nsec;
	if (timer_settime(timerid, 0, &its, NULL) < 0) {
		errorExit("timer_settime");
	}

	*sig += 1;

	return timerid;
}

void timerDeregister(timer_t timerid) {
	if (timerid == NULL) {
		printf("what\n");
		exit(0);
	}
	if (timer_delete(timerid) < 0) {
		errorExit("timer_delete");
	}
}
