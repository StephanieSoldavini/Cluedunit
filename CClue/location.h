#include <stdlib.h>
#include <stdio.h>

typedef struct room {
    char *name;
} room;

typedef struct location {
    room *rm;
    int col;
    int row;
    struct location *adj[4];
} location;

void locationToString( location *loc, char *buffer, unsigned int buffLen );
