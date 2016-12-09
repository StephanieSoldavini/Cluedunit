#ifndef __LOCATION_H__
#define __LOCATION_H__

struct player; /* Forward declare player struct for header */

typedef enum {INC_COL, DEC_COL, INC_ROW, DEC_ROW, BACK, STAY} direction; 

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
void move( struct player *movingPlayer, direction dir );

#endif /* __LOCATION_H__ */
