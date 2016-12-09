#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "location.h"
#include "boardGraph.h"
#include "ascii.h"
#include "player.h"

void init()
{
    FILE *boardf = fopen("data/board.txt", "r");

    system("clear");
    fprintf(OUTSTREAM, "Welcome to CLUE.\n"
            "Copyright (C) 2016 Stephanie Soldavini and Andrew Ramsey\n"
            "This program comes with ABSOLUTELY NO WARRANTY;\n"
            "This is free software, and you are welcome to redistribute it\n"
            "under certain conditions; See LICENSE for details\n"
            "Press enter to continue.");
    getchar();

    /* Print out board */
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
    ECHO_OFF;
    CURSOR_OFF(OUTSTREAM);
}

void cleanup()
{
    /* Go to home row so new prompt doesn't print in the middle of the board */
    goToHomeRow(OUTSTREAM);

    /* Turn on terminal I/O processing */
    CURSOR_ON(OUTSTREAM);
    ECHO_ON;
}

int main(int argc, char *argv[])
{
    int c;
    player *plum = newPlayer("Plum", &PlumHome, PURPLE);
    int numHumans;
    init();

    /* Choose players */
    printToHomeRow(OUTSTREAM, "How many human players are there? ");
    numHumans = getPlayerInput();
    printToHomeRow(OUTSTREAM, "There are %d human players.", numHumans);
    getchar();
    placePlayers(plum);
        
    do {
        takeTurn(plum);
        printToHomeRow(OUTSTREAM, "Turn finished. Press q to quit or another key to continue. ");
        c = getchar();
    } while (c != 'q');
    cleanup();
    deletePlayer(plum);
    return 0;
}
