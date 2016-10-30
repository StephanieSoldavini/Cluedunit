CC = clang
CFLAGS = -g -Wall -pedantic -ansi
PROGDIR = out/
PROG = out
SRC = main.c location.c
OBJ = $(patsubst %.c,%.o,$(SRC))
PYPRGOUT = boardGraph.h
HDR = $(PYPRGOUT) location.h
TEST = test
TESTSRC = test.c
PYTHON = python3
PYPRG = genBoard.py

.PHONY: all
all: $(PROG)


depend: .depend
.depend: $(SRC)
	-rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ -MF ./.depend;

include .depend

$(PROG): $(PYPRGOUT) $(OBJ) depend
	mkdir -p $(PROGDIR)
	$(CC) $(OBJ) -o $(PROGDIR)$(PROG)

$(TEST): $(TESTSRC)
	mkdir -p $(PROGDIR)
	$(CC) $(CFLAGS) $(TESTSRC) -o $(PROGDIR)$(TEST)

$(PYPRGOUT): $(PYPRG)
	$(PYTHON) $(PYPRG)

clean: 
	-rm -rf $(PROGDIR)
	-rm -rf $(PYPRGOUT)
	-rm -rf *.o
