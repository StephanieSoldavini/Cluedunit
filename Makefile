SRCDIR = src/
PROGDIR = bin/
INCDIR = include/
BUILDDIR = build/

VPATH = $(SRCDIR)
CC = clang
CFLAGS = -MMD -g -Wall -pedantic -ansi -I$(SRCDIR) -I$(INCDIR)
PROG = out
SRC = location.c main.c 
OBJ = $(patsubst %.c,$(BUILDDIR)%.o,$(SRC))
DEP = $(patsubst %.c,$(BUILDDIR)%.d,$(SRC))
PYPRGOUT = $(INCDIR)boardGraph.h
TEST = test
TESTSRC = test.c
PYTHON = python3
PYPRG = genBoard.py

.PHONY: all 
all: $(PROG) 

$(BUILDDIR)%.o : %.c | $(BUILDDIR) $(PYPRGOUT)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(PROG): $(OBJ) | $(PROGDIR)
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $(PROGDIR)$(PROG)

$(TEST): $(TESTSRC) | $(PROGDIR)
	$(CC) $(CFLAGS) $(TESTSRC) -o $(PROGDIR)$(TEST)

$(PYPRGOUT): $(PYPRG) | $(INCDIR)
	$(PYTHON) $^

$(SRCDIR):
	mkdir -p $(SRCDIR)

$(PROGDIR):
	mkdir -p $(PROGDIR)

$(INCDIR):
	mkdir -p $(INCDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)


clean: 
	-rm -rf $(PROGDIR)
	-rm -rf $(PYPRGOUT)
	-rm -rf $(BUILDDIR)

-include $(DEP)
