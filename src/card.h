#ifndef __CARD_H__
#define __CARD_H__

/* The card will keep track of some data by itself
 * name: String representation of the card
 * heldBy: who did it get dealt to (TODO: Should this be a variable, not a pointer)
 * seenBy: List of players that have seen it
 */
typedef struct card {
    char *name;
    player *heldBy;
    player *seenBy;
} card;

newCard(char *name);

#endif /* __CARD_H__ */
