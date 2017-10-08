CC = gcc
CFLAGS = -Wall -Wextra -std=gnu11 -ggdb -O0
LDLIBS = -lncursesw
ifeq ($(shell uname -s), Darwin)
	LDFLAGS = -L/usr/local/opt/ncurses/lib
endif

OBJECTS = utils.o snake.o responsive.o linked-list.o position.o direction.o game.o
EXECUTABLES = snake tester

default: clean snake

debug-memory: default
	valgrind --leak-check=full -v ./snake

debug-gdb: default
	gdb snake

# implicit rule for %.o
# $(CC) $(CPPFLAGS) $(CFLAGS) -c $@

# snake main
# has nothing to do with snake.o !!
snake: ${OBJECTS}
	$(CC) main.c $^ $(LDFLAGS) $(LDLIBS) -o $@

tester: tester.c ${OBJECTS}

objects: ${OBJECTS}

clean-objects:
	touch ${OBJECTS} && rm ${OBJECTS}

clean-executables:
	touch ${EXECUTABLES} && rm ${EXECUTABLES}

clean: clean-objects clean-executables
