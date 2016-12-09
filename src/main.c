#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "location.h"
#include "boardGraph.h"
#include "ascii.h"
#include "player.h"

#define OUTSTREAM stdout
#define INSTREAM stdin

void init()
{
    FILE *boardf = fopen("data/board.txt", "r");

    system("clear");
    fprintf(OUTSTREAM, "Welcome to CLUE.\n"
            "Copyright (C) 2016  Stephanie Soldavini and Andrew Ramsey\n"
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
    ECHO_ON;
    CURSOR_ON(OUTSTREAM);
    fscanf(INSTREAM, "%d", &numHumans);
    printToHomeRow(OUTSTREAM, "There are %d human players.", numHumans);
    getchar();
    CURSOR_OFF(OUTSTREAM);
    ECHO_OFF;
        
    do {
        roll(plum);
        do {
            printToHomeRow(OUTSTREAM, "You rolled a %d and have %d move(s) left", plum->roll, plum->roll-movesMade(plum));
            printToTile(OUTSTREAM, plum->loc->row, plum->loc->col, "Pl");
            c = getchar();
            printToTile(OUTSTREAM, plum->loc->row, plum->loc->col, "x ");
            move(plum, inputToDirection(c));
        } while (movesMade(plum) < plum->roll && c != 'q');
    } while (c != 'q');
    cleanup();
    deletePlayer(plum);
    return 0;
}
