#include <stdio.h>
#include "location.h"
#include "player.h"
#include "llist.h"

/* Converts a location variable to a string location
 * loc: location to be converted
 * buffer: string output
 * buffLen: length of buffer
 */
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

/* Based on the current location and a direction, calculate a new location
 * movingPlayer: Person who is moving
 * dir: Direction to move
 * returns: Direction player moved in
 */
direction move( player *movingPlayer, direction dir )
{
    const location *loc = movingPlayer->loc;
    int searchCol = loc->col;
    int searchRow = loc->row;
    direction backwards;
    int i;
    elementStructs historyNode;
    /* If the player has moved already */
    if (getListLen(&movingPlayer->locHistory)) {
        /* If they want to go backwards TODO: Combine with above */
       if (dir == peekAtLinkedList(&movingPlayer->locHistory)->backwards || dir == BACK) {
           movingPlayer->loc = removeFromLinkedList(&movingPlayer->locHistory)->loc;
           return BACK; /* Don't do anything else */
       } 
    }
    switch (dir) {
        case INC_COL:
            searchCol++;
            backwards = DEC_COL;
            break;
        case DEC_COL:
            searchCol--;
            backwards = INC_COL;
            break;
        case INC_ROW:
            searchRow++;
            backwards = DEC_ROW;
            break;
        case DEC_ROW:
            searchRow--;
            backwards = INC_ROW;
            break;
        case STAY:
        default:
            break;
    }
    for (i = 0; i < 4; i++) {
        if (loc->adj[i] != NULL) {
            if ((loc->adj[i]->row == searchRow) && (loc->adj[i]->col == searchCol)) {
                /* Store some info about where the player is now */
                historyNode.loc = movingPlayer->loc;
                historyNode.backwards = backwards;
                movingPlayer->loc = loc->adj[i];
                addToLinkedList(&movingPlayer->locHistory, &historyNode);
                return dir;
            }
        }
    }
    return STAY;
}

/* Where was the player last. Note that this is destructive to locHistory
 * movingPlayer: player of interest
 * returns: players previous location, or NULL if that doesn't exist 
 */
const location *getPrevLoc(struct player *movingPlayer)
{
    elementStructs *prevLoc = removeFromLinkedList(&movingPlayer->locHistory);
    if (NULL != prevLoc) {
        return prevLoc->loc;
    } else {
        return NULL;
    }
}
