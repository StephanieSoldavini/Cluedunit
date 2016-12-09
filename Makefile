SRCDIR = src/
PROGDIR = bin/
INCDIR = include/
BUILDDIR = build/

OS = $(shell uname)

VPATH = $(SRCDIR)
CC = clang
CFLAGS = -MMD -g -Wall -pedantic -ansi -I$(SRCDIR) -I$(INCDIR)

ifeq ($(OS),Linux)
	CFLAGS += -D_XOPEN_SOURCE=500
endif

PROG = $(PROGDIR)out
SRC = location.c ascii.c main.c player.c llist.c
OBJ = $(patsubst %.c,$(BUILDDIR)%.o,$(SRC))
DEP = $(patsubst %.c,$(BUILDDIR)%.d,$(SRC))

TEST = $(PROGDIR)test
TESTSRC = test.c

PYTHON = python3
PYPRG = genBoard.py
PYPRGOUT = $(INCDIR)boardGraph.h

.PHONY: all clean

all: $(PROG) 

$(BUILDDIR)%.o : %.c | $(BUILDDIR) $(PYPRGOUT)
	$(COMPILE.c) -o $@ $<

$(PROG): $(OBJ) | $(PROGDIR)
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $(PROG)

$(TEST): $(TESTSRC) | $(PROGDIR)
	$(CC) $(CFLAGS) $(TESTSRC) -o $(TEST)

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
