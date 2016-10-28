CC = clang
CFLAGS = -g -Wall -pedantic -ansi
PROGDIR = out/
PROG = out
SRC = main.c location.c
PYPRGOUT = boardGraph.h
HDR = $(PYPRGOUT) location.h
TEST = test
TESTSRC = test.c
PYTHON = python3
PYPRG = genBoard.py

all: $(PROG)

$(PROG): $(SRC) $(HDR)
	mkdir -p $(PROGDIR)
	$(CC) $(CFLAGS) $(SRC) -o $(PROGDIR)$(PROG)

$(TEST): $(TESTSRC)
	mkdir -p $(PROGDIR)
	$(CC) $(CFLAGS) $(TESTSRC) -o $(PROGDIR)$(TEST)

$(PYPRGOUT): $(PYPRG)
	$(PYTHON) $(PYPRG)

clean: 
	-rm -rf $(PROGDIR)
