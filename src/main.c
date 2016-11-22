#include <stdlib.h>
#include <stdio.h>
#include "location.h"
#include "boardGraph.h"
#include "ascii.h"

int main(int argc, char *argv[])
{
    int i;
    char buffer[256];
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
    goTo(stdout, 5, 5, 0);
    printf("hi");
    goTo(stdout, 10, 15, 0);
    printf("lol");
    goTo(stdout, 50, 0, 1);
    /*
    locationToString(&room, buffer, sizeof(buffer));
    printf("%s: %s\n", room.room, buffer);
    for (i = 0; i < 4; i ++) {
        locationToString(room.adj[i], buffer, sizeof(buffer));
        printf("%s D%d: %s\n", room.room, i, buffer);
    }
    */
    return 0;
}
