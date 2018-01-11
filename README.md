# Snake
Snake in C using ncurses.

## Build
**This is only supported on Linux.**

Clone the repository and `cd` into it. Then run `make` to compile the program. That should generate a binary `snake`.

## Run
`./snake` to run as a full build or `./snake <ANY_ARGUMENT>` to run as debug (will show some useful debugging information at game end).

For example:
```bash
# this will put it into debug mode
./snake 1
```

## How to play
Classic game of snake. Control with arrow keys and quit with `q` anytime. It's game over when you run into a wall or yourself!
