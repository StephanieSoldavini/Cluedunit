CC = clang
CFLAGS = -g -Wall -pedantic -ansi
PROG = out
SRC = main.c dictionary.c location.c
TEST = test
TESTSRC = test.c

$(PROG): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(PROG)

$(TEST): $(TESTSRC)
	$(CC) $(CFLAGS) $(TESTSRC) -o $(TEST)
