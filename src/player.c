#include <string.h>
#include <stdlib.h>
#include "player.h"

/* Creates a new player. Call deletePlayer when finished
 * name: String of the character, ie Mustard, Scarlet, Plum, etc
 * home: Where the player starts
 * returns: struct with details filled in. If name is empty, malloc failed
 */
player *newPlayer(char *name, const location *home, color playerColor)
{
    player *newPlayer = malloc(sizeof(player));
    if (newPlayer == NULL) {
        strncpy(newPlayer->name, "", MAX_NAME);
    }
    else {
        strncpy(newPlayer->name, name, MAX_NAME);
    }

    strncpy(newPlayer->abbr, name, MAX_ABBR);
    newPlayer->abbr[MAX_ABBR-1] = '\0'; /* Want to make it a C string */
    newPlayer->loc = home;
    initLinkedList(&newPlayer->locHistory);
    newPlayer->playerColor = playerColor;
    newPlayer->heldCards = NULL;
    return newPlayer;
}

/* Call after player is done
 * playerToRemove: Player that is finished. Will have name set to empty string
 */
void deletePlayer(player *playerToRemove)
{
    destroyLinkedList(&playerToRemove->locHistory); /* Clear the list */
    free(playerToRemove);
    playerToRemove = NULL;
}

/* Rolls the dice for the player
 * playerRolling: who's turn is it
 * returns: Value of the roll
 */
int roll(player *playerRolling)
{
    destroyLinkedList(&playerRolling->locHistory); /* Clear the list */
    initLinkedList(&playerRolling->locHistory); /* TODO: A clear list would be nice */
    playerRolling->roll = (rand() % 6) + 1;
    return playerRolling->roll;
}

/* How far has the player moved this turn
 * movingPlayer: Person who is moving
 * returns: Number of moves made
 */
int movesMade(player *movingPlayer)
{
    /* TODO: Should player interact with llist or just location */
    return getListLen(&movingPlayer->locHistory);
}
