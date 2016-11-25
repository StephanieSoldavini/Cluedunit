#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "location.h"
#include "boardGraph.h"
#include "ascii.h"
#include "player.h"

#define OUTSTREAM stdout

void init()
{
    /* Print out board */
    FILE *boardf = fopen("data/board.txt", "r");
    if (boardf == NULL) {
        printf("Error\n");
    } else {
        system("clear");
        printBoard(OUTSTREAM, boardf);
    }
    fclose(boardf);

    /* Seed random number generator */
    srand(time(NULL));

    /* Turn of terminal I/O processing */
    system("/bin/stty raw -echo");

    printToHomeRow(OUTSTREAM, "Welcome to CLUE. Press a key to continue.");
    getchar();
}

void cleanup()
{
    goToHomeRow(OUTSTREAM);
    system("/bin/stty cooked echo");
}

int main(int argc, char *argv[])
{
    int c;
    player *plum = newPlayer("Plum", PlumHome, PURPLE);
    init();
    do {
        int diceRoll = (rand() % 6) + 1;
        printToHomeRow(OUTSTREAM, "You rolled a %d.", diceRoll);
        do {
            printToTile(OUTSTREAM, plum->loc.row, plum->loc.col, "Pl");
            c = getchar();
            printToTile(OUTSTREAM, plum->loc.row, plum->loc.col, "x ");
            plum->loc = *(move(&plum->loc, inputToDirection(c)));
            diceRoll--;
        } while (diceRoll > 0 && c != 'q');
    } while (c != 'q');
    cleanup();
    deletePlayer(plum);
    return 0;
}
