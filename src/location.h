#ifndef __LOCATION_H__
#define __LOCATION_H__

#include <stdlib.h>
#include <stdio.h>

typedef enum {INC_COL, DEC_COL, INC_ROW, DEC_ROW} direction; 

typedef struct room {
    char *name;
} room;

typedef struct location {
    const char *room;
    int row;
    int col;
    const struct location *adj[4];
} location;

void locationToString( const location *loc, char *buffer, unsigned int buffLen );
const location* move( const location *loc, direction dir );

#endif /* __LOCATION_H__ */
