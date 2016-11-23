#include <stdio.h>
#include "location.h"

void locationToString( const location *loc, char *buffer, unsigned int buffLen )
{
    if (loc == NULL) {
        snprintf(buffer, buffLen, "%s", "NULL");
    } else if (loc->room != NULL) {
        snprintf(buffer, buffLen, "%s", loc->room);
    } else {
        snprintf(buffer, buffLen, "(%d, %d)", loc->col, loc->row);
    }
}

const location* move( const location *loc, direction dir )
{
    int searchCol = loc->col;
    int searchRow = loc->row;
    int i;
    switch (dir) {
        case INC_COL:
            searchCol++;
            break;
        case DEC_COL:
            searchCol--;
            break;
        case INC_ROW:
            searchRow++;
            break;
        case DEC_ROW:
            searchRow--;
            break;
    }
    for (i = 0; i < 4; i++) {
        if (loc->adj[i] != NULL) {
            if ((loc->adj[i]->row == searchRow) && (loc->adj[i]->col == searchCol)) {
                return loc->adj[i];
            }
        }
    }
    return loc;
}
