CC = gcc
CFLAGS = -Wall -std=gnu11 -ggdb -O0
LDLIBS = -lncursesw

OBJECTS = utils.o snake.o responsive.o linked-list.o position.o direction.o game.o
EXECUTABLES = snake tester

default: clean snake

debug: default
	valgrind --leak-check=full -v ./snake

# shell main
snake: main.c ${OBJECTS}

tester: tester.c ${OBJECTS}

objects: ${OBJECTS}

clean-objects:
	touch ${OBJECTS} && rm ${OBJECTS}

clean-executables:
	touch ${EXECUTABLES} && rm ${EXECUTABLES}

clean: clean-objects clean-executables
