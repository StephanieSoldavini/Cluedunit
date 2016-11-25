#ifndef __CARD_H__
#define __CARD_H__

typedef struct card {
    char *name;
} card;

card *newCard(char *name);

#endif /* __CARD_H__ */
