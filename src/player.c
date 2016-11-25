#include <string.h>
#include "player.h"
#include "ascii.h"

/* Creates a new player. Call deletePlayer when finished
 * name: String of the character, ie Mustard, Scarlet, Plum, etc
 * home: Where the player starts
 * playerColor: One of the color enum
 * returns: struct with details filled in. If name is empty, malloc failed
 */
player *newPlayer(char *name, location home, color playerColor)
{
    player *newPlayer = malloc(sizeof(player));
    if (newPlayer == NULL) {
        strncpy(newPlayer->name, "", MAX_NAME);
    }
    else {
        strncpy(newPlayer->name, name, MAX_NAME);
    }
    strncpy(newPlayer->locHistory, "", MAX_ROLL);
    newPlayer->loc = home;
    newPlayer->heldCards = NULL;
    return newPlayer;
}

/* Call after player is done
 * playerToRemove: Player that is finished. Will have name set to empty string
 */
void deletePlayer(player *playerToRemove)
{
    free(playerToRemove);
    playerToRemove = NULL;
}
