#include <stdlib.h>
#include <stdio.h>

typedef struct room {
    char *name;
} room;

typedef struct location {
    room *rm_p;
    int col;
    int row;
} location;

location *newLocation( int col, int row, room *rm_p );
void deleteLocation( location *loc_p );
void locationToString( location *loc_p, char *buffer, unsigned int buffLen );
