#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "location.h"
#include "boardGraph.h"
#include "ascii.h"
#include "player.h"
#include "card.h"

void init()
{
    /*FILE *boardf = fopen("data/board.txt", "r");*/

    system("clear");
    fprintf(OUTSTREAM, "Welcome to CLUEDUNIT.\n"
            "Copyright (C) 2016 Stephanie Soldavini and Andrew Ramsey\n"
            "This program comes with ABSOLUTELY NO WARRANTY;\n"
            "This is free software, and you are welcome to redistribute it\n"
            "under certain conditions; See LICENSE for details\n"
            "Press enter to continue.");
    getchar();

    /* Print out board */
    /*
    if (boardf == NULL) {
        printf("Error, board data file not found.\n");
    } else {
        system("clear");
        printBoard(OUTSTREAM, boardf);
    }
    fclose(boardf);
    */
    printBoard(OUTSTREAM, NULL);

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
    clearToEnd(OUTSTREAM);

    /* Turn on terminal I/O processing */
    CURSOR_ON(OUTSTREAM);
    ECHO_ON;
}

int main(int argc, char *argv[])
{
    int c;
    int numHumans, numComps, totalPlayers;
    int numCompsAssigned = 0;
    int numCardsEach;
    int i, j;
    struct card candlestickCard;
    struct card libraryCard;
    struct card plumCard;
    struct card conservatoryCard;
    struct card whiteCard;
    struct card mustardCard;
    player *plum    = newPlayer("Prof.", "Plum",   &PlumHome,       PURPLE);
    player *peacock = newPlayer("Mrs.", "Peacock", &PeacockHome,    BLUE);
    player *scarlet = newPlayer("Miss", "Scarlet", &ScarletHome,    RED);
    player *mustard = newPlayer("Col.", "Mustard", &MustardHome,    YELLOW);
    player *green   = newPlayer("Mr.", "Green",    &GreenHome,      GREEN);
    player *white   = newPlayer("Mrs.", "White",   &WhiteHome,      WHITE);
    player *players[6];
    players[0] = scarlet;
    players[1] = mustard;
    players[2] = white;
    players[3] = green;
    players[4] = peacock;
    players[5] = plum;
    init();

    /* Choose players */
   
    ECHO_ON;
    CURSOR_ON(OUTSTREAM);
    
    printToHomeRow(OUTSTREAM, "How many human players are there? ");
    numHumans = getDigit();
    printToHomeRow(OUTSTREAM, "There are %d human players.", numHumans);
    getchar();

    for (j = 0; j < numHumans; j++) {
        printToHomeRow(OUTSTREAM, "Player %d, what character will you play?\n", j+1);
        for (i = 0; i < 6; i++) {
            if (players[i]->playing == 0) {
                fprintf(OUTSTREAM, "%d: %s\n", i, players[i]->name); /* TODO shifts board up*/
            }
        }
        c = getDigit();
        players[c]->playing = 1;
        players[c]->human = 1;
    }

    printToHomeRow(OUTSTREAM, "How many computer players are there? ");
    numComps = getDigit();
    for (i = 0; i < 6; i++) {
        if (players[i]->playing == 0 && players[i]->human == 0) {
            players[i]->playing = 1;
            numCompsAssigned++;
        }
        if (numCompsAssigned >= numComps) {
            break;
        }
    }

    printToHomeRow(OUTSTREAM, "There are %d computer players.", numComps);
    getchar();

    totalPlayers = numComps + numHumans; 
    numCardsEach = NUMCARDS / totalPlayers;

    if (totalPlayers > 6) {
        fprintf(OUTSTREAM, "Error: too many players");
    }
    
    /* TODO temporary fix for the board shifting up */
    system("clear");
    printBoard(OUTSTREAM, NULL);

    CURSOR_OFF(OUTSTREAM);
    ECHO_OFF;

    for (i = 0; i < 6; i++) {
        if (players[i]->playing) {
            placePlayers(players[i]);
        }
    } 

    libraryCard.name = "library";
    candlestickCard.name = "candlestick";
    plumCard.name = "plum";
    conservatoryCard.name = "conservatory";
    whiteCard.name = "white";
    mustardCard.name = "mustard";
    plum->heldCards[0] = &candlestickCard;
    plum->heldCards[1] = &libraryCard;
    plum->heldCards[2] = &plumCard;
    plum->heldCards[3] = &conservatoryCard;
    plum->heldCards[4] = &whiteCard;
    plum->heldCards[5] = &mustardCard;
    printHeldCards(plum, 6);
        
    do {
        for (i = 0; i < 6; i++) {
            if (players[i]->playing) {
                takeTurn(players[i]);
                printToHomeRow(OUTSTREAM, "Turn finished. Press q to quit or another key to continue. ");
                if(getchar() == 'q') {
                    break;
                }
            }
        } 
        if(getchar() == 'q') {
            break;
        }
    } while (1); /* TODO end condition */
    cleanup();
    deletePlayer(plum);
    return 0;
}
