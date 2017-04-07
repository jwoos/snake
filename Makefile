CC = gcc
CFLAGS = -Wall -std=gnu11 -ggdb -O0 -D_XOPEN_SOURCE -D_POSIX_C_SOURCE
LDLIBS = -lncurses

OBJECTS = utils.o main.o menu.o responsive.o about.o
EXECUTABLES = tester snake

default: clean-snake snake

test: clean-tester tester

debug: default
	valgrind --leak-check=full -v ./snake

# shell main
snake: snake.c ${OBJECTS}

# separate compilation point for testing reasons
tester: tester.c ${OBJECTS}

objects: ${OBJECTS}

%.o: %.c
	${CC} ${ARGS} -c $^ -o $@

clean-tester: clean-objects
	touch tester && rm tester

clean-snake: clean-objects
	touch snake && rm snake

clean-objects:
	touch ${OBJECTS} && rm ${OBJECTS}

clean-executables:
	rm ${EXECUTABLES}

clean: clean-objects clean-executables
