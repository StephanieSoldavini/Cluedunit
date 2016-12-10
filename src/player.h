#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "location.h"
#include "card.h"
#include "ascii.h"

#define MAX_ROLL 6
#define MAX_NAME 13 /* Peacock + 1 */

typedef struct player {
    char name[MAX_NAME];
    location loc;
    char locHistory[MAX_ROLL+1]; /* Null termination */
    card *heldCards;
} player;

player *newPlayer(char *name, location home, color playerColor);
void deletePlayer(player *playerToRemove);

#endif /* __PLAYER_H__ */
