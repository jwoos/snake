CC = gcc
CFLAGS = -Wall -std=gnu11 -ggdb -O0 -D_XOPEN_SOURCE -D_POSIX_C_SOURCE
LDLIBS = -lncurses

OBJECTS = utils.o main.o responsive.o
EXECUTABLES = snake

default: clean-snake snake

debug: default
	valgrind --leak-check=full -v ./snake

# shell main
snake: snake.c ${OBJECTS}

objects: ${OBJECTS}

clean-snake: clean-objects
	touch snake && rm snake

clean-objects:
	touch ${OBJECTS} && rm ${OBJECTS}

clean-executables:
	rm ${EXECUTABLES}

clean: clean-objects clean-executables
