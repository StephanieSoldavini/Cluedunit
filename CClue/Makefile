CC = clang
CFLAGS = -g -Wall -pedantic -ansi
PROGDIR = out/
PROG = out
SRC = main.c dictionary.c location.c
TEST = test
TESTSRC = test.c

$(PROG): $(SRC)
	mkdir -p $(PROGDIR)
	$(CC) $(CFLAGS) $(SRC) -o $(PROGDIR)$(PROG)

$(TEST): $(TESTSRC)
	mkdir -p $(PROGDIR)
	$(CC) $(CFLAGS) $(TESTSRC) -o $(PROGDIR)$(TEST)

clean: 
	-rm -rf $(PROGDIR)
