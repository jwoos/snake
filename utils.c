#include "utils.h"


// TODO implement
char* formatBlock(char* original, int height) {
	return original;
}

int min(int a, int b) {
	return a > b ? b : a;
}

int max(int a, int b) {
	return a > b ? a : b;
}

uint64_t randomNumber(uint64_t a, uint64_t b) {
	uint64_t random = rand();
	return a + random % ((b + 1) - a);
}

void errorExit(char* msg) {
	perror(msg);
	exit(EXIT_FAILURE);
}
