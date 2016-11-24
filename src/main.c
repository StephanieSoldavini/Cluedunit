#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "location.h"
#include "boardGraph.h"
#include "ascii.h"

#define OUTSTREAM stdout

void init()
{
    /* Print out board */
    FILE *boardf = fopen("data/board.txt", "r");
    if (boardf == NULL) {
        printf("Error\n");
    } else {
        printBoard(OUTSTREAM, boardf);
    }
    fclose(boardf);

    /* Seed random number generator */
    srand(time(NULL));

    /* Turn of terminal I/O processing */
    system("/bin/stty raw");
}

void cleanup()
{
    system("/bin/stty cooked");
}

int main(int argc, char *argv[])
{
    int c;
    location const *playerLoc = &PlumHome;
    init();
    goTo(OUTSTREAM, 50, 0, 1);
    do {
        int diceRoll = (rand() % 6) + 1;
        goTo(OUTSTREAM, 50, 0, 1);
        fprintf(OUTSTREAM, "You rolled a %d.", diceRoll);
        do {
            goTo(OUTSTREAM, playerLoc->row, playerLoc->col, 0);
            fprintf(OUTSTREAM, "x");
            c = getchar();
            playerLoc = move(playerLoc, inputToDirection(c));
            diceRoll--;
        } while (diceRoll > 0 || c != 'q');
        goTo(OUTSTREAM, playerLoc->row, playerLoc->col, 0);
        fprintf(OUTSTREAM, "Pl");
    } while (c != 'q');
    goTo(OUTSTREAM, 50, 0, 1);
    cleanup();
    return 0;
}
