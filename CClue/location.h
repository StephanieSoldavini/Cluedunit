#include <stdlib.h>
#include <stdio.h>

typedef enum {INC_COL, DEC_COL, INC_ROW, DEC_ROW} direction; 

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
location* move( location *loc, direction dir );
