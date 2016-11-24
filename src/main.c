#include <stdlib.h>
#include <stdio.h>
#include "location.h"
#include "boardGraph.h"
#include "ascii.h"

int main(int argc, char *argv[])
{
    int c;
    location const *playerLoc = &PlumHome;
    /*
    const location room = Ballroom;
    */
    FILE *boardf = fopen("data/board.txt", "r");
    if (boardf == NULL) {
        printf("Error\n");
    } else {
        printBoard(stdout, boardf);
    }
    fclose(boardf);
    goTo(stdout, 50, 0, 1);
    /*
    locationToString(&room, buffer, sizeof(buffer));
    printf("%s: %s\n", room.room, buffer);
    for (i = 0; i < 4; i ++) {
        locationToString(room.adj[i], buffer, sizeof(buffer));
        printf("%s D%d: %s\n", room.room, i, buffer);
    }
    */
    system("/bin/stty raw");
    /*
    int i = 0;
    fgets(buffer, sizeof(buffer), stdin);
    */
    do {
        goTo(stdout, playerLoc->row, playerLoc->col, 0);
        fprintf(stdout, "x");
        goTo(stdout, 50, 0, 1);
        c = getchar();
        playerLoc = move(playerLoc, inputToDirection(c));
    } while (c != 'q');
    goTo(stdout, playerLoc->row, playerLoc->col, 0);
    fprintf(stdout, "Pl");
    goTo(stdout, 50, 0, 1);
    system("/bin/stty cooked");
    return 0;
}
