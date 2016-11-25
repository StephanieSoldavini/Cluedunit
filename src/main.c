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

    printToHomeRow(OUTSTREAM, "Welcome to CLUE. Press a key to continue.");
    getchar();
}

void cleanup()
{
    goToHomeRow(OUTSTREAM);
    system("/bin/stty cooked");
}

int main(int argc, char *argv[])
{
    int c;
    location const *playerLoc = &PlumHome;
    init();
    do {
        int diceRoll = (rand() % 6) + 1;
        printToHomeRow(OUTSTREAM, "You rolled a %d.", diceRoll);
        do {
            printToTile(OUTSTREAM, playerLoc->row, playerLoc->col, "Pl");
            c = getchar();
            printToTile(OUTSTREAM, playerLoc->row, playerLoc->col, "x ");
            playerLoc = move(playerLoc, inputToDirection(c));
            diceRoll--;
        } while (diceRoll > 0 && c != 'q');
    } while (c != 'q');
    cleanup();
    return 0;
}
