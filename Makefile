VPATH = src
CC = clang
INC = include/
CFLAGS = -g -Wall -pedantic -ansi -Isrc -I$(INC)
PROGDIR = out/
PROG = out
SRC = main.c location.c
OBJ = $(patsubst %.c,%.o,$(SRC))
PYPRGOUT = $(INC)boardGraph.h
TEST = test
TESTSRC = test.c
PYTHON = python3
PYPRG = genBoard.py

.PHONY: all depend
all: $(PROG)

depend: .depend

.depend: $(SRC) $(PYPRGOUT)
	-rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ -MF ./.depend;

-include .depend

$(PROG): $(PYPRGOUT) $(OBJ) depend
	mkdir -p $(PROGDIR)
	$(CC) $(OBJ) -o $(PROGDIR)$(PROG)

$(TEST): $(TESTSRC)
	mkdir -p $(PROGDIR)
	$(CC) $(CFLAGS) $(TESTSRC) -o $(PROGDIR)$(TEST)

$(PYPRGOUT): $(PYPRG)
	mkdir -p $(INC)
	$(PYTHON) $^

clean: 
	-rm -rf $(PROGDIR)
	-rm -rf $(PYPRGOUT)
	-rm -rf *.o
