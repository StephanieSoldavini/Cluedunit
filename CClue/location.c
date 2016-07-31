#include "location.h"

location *newLocation( int col, int row, room *rm_p )
{
    location *loc_p = malloc(sizeof(location));
    loc_p->col = col;
    loc_p->row = row;
    loc_p->rm_p = rm_p;
    return loc_p;
}

void deleteLocation( location *loc_p )
{
    if (loc_p->rm_p != NULL) {
        /* TODO deleteRoom(rm_p);*/
    }
    free(loc_p);
}

void locationToString( location *loc_p, char *buffer, unsigned int buffLen )
{
    if (loc_p->rm_p != NULL) {
        snprintf(buffer, buffLen,
                "(%d, %d)", loc_p->col, loc_p->row);
    } else {
        snprintf(buffer, buffLen,
                "%s", loc_p->rm_p->name);
    }
}
