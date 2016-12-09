#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "location.h"
#include "llist.h"

#define MAX_ROLL 6
#define MAX_NAME 8 /* Peacock + 1 */
#define MAX_ABBR 3 /* Pl, Wh, etc + 1*/


typedef enum {RED, GREEN, YELLOW, BLUE, PURPLE, WHITE, DEFAULT} color;

typedef struct player {
    char name[MAX_NAME];
    char abbr[MAX_ABBR];
    const location *loc;
    linkedLists locHistory;
    struct card *heldCards;
    int roll;
    color playerColor;
} player;

player *newPlayer(char *name, const location *home, color playerColor);
void deletePlayer(player *playerToRemove);
int roll(player *playerRolling);
int movesMade(player *playerMoving);

#endif /* __PLAYER_H__ */
