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

void errorExit(char* msg) {
	perror(msg);
	exit(EXIT_FAILURE);
}
