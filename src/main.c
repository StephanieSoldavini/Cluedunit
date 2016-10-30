#include <stdlib.h>
#include <stdio.h>
#include "location.h"
#include "boardGraph.h"

int main(int argc, char *argv[])
{
    int i;
    char buffer[256];
    const location room = Ballroom;
    locationToString(&room, buffer, sizeof(buffer));
    printf("%s: %s\n", room.room, buffer);
    for (i = 0; i < 4; i ++) {
        locationToString(room.adj[i], buffer, sizeof(buffer));
        printf("%s D%d: %s\n", room.room, i, buffer);
    }
    return 0;
}
