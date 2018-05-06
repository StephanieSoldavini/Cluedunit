#ifndef __CARD_H__
#define __CARD_H__

/* is the extrapolatable from somewhere?*/
#define NUMCARDS (21)
#define MAX_CARDS (NUMCARDS/(3))

typedef struct card {
    char *name;
} card;

card *newCard(char *name);

#endif /* __CARD_H__ */
