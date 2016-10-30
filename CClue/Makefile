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

.PHONY: all
all: $(PROG)

# Convert each .c file to a .o file
.c.o: 
	echo "compile $<"
	$(CC) $(CFLAGS) -c $<

depend: .depend
.depend: $(SRC)
	-rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ -MF  ./.depend;
include .depend

$(PROG): $(PYPRGOUT) $(SRC)
	mkdir -p $(PROGDIR)
	$(CC) $(CFLAGS) $(SRC) -o $(PROGDIR)$(PROG)

$(TEST): $(TESTSRC)
	mkdir -p $(PROGDIR)
	$(CC) $(CFLAGS) $(TESTSRC) -o $(PROGDIR)$(TEST)

$(PYPRGOUT): $(PYPRG)
	$(PYTHON) $(PYPRG)

clean: 
	-rm -rf $(PROGDIR)
	-rm $(PYPRGOUT)
