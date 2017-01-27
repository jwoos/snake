CC = gcc
ARGS = -Wall -std=gnu11 -ggdb -O0
LIB = -lncurses

ALL = utils.o main.o
EXECUTABLES = tester snake

default: clean-snake snake

test: clean-tester tester

debug: default
	valgrind --leak-check=full -v ./snake

# shell main
snake: ${ALL}
	${CC} ${ARGS} $@.c ${ALL} -o $@ ${LIB}

# separate compilation point for testing reasons
tester: ${ALL}
	${CC} ${ARGS} $@.c ${ALL} -o $@

utils.o:
	${CC} ${ARGS} -c utils.c

main.o:
	${CC} ${ARGS} -c main.c

objects: ${ALL}

clean-tester: clean-objects
	rm tester

clean-snake: clean-objects
	rm snake

clean-objects:
	rm ${ALL}

clean-executables:
	rm ${EXECUTABLES}

clean: clean-objects clean-executables