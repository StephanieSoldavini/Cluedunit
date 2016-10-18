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

location *newLocation( int col, int row, room *rm );
void deleteLocation( location *loc );
void locationToString( location *loc, char *buffer, unsigned int buffLen );
