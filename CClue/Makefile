CC = clang
CFLAGS = -g -Wall -pedantic -ansi
PROGDIR = out/
PROG = out
SRC = main.c dictionary.c location.c
TEST = test
TESTSRC = test.c
PYTHON = python3

all: $(PROG)

$(PROG): $(SRC)
	mkdir -p $(PROGDIR)
	$(CC) $(CFLAGS) $(SRC) -o $(PROGDIR)$(PROG)

$(TEST): $(TESTSRC)
	mkdir -p $(PROGDIR)
	$(CC) $(CFLAGS) $(TESTSRC) -o $(PROGDIR)$(TEST)

board:
	$(PYTHON) genBoard.py

clean: 
	-rm -rf $(PROGDIR)
