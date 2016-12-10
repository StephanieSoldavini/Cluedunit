#ifndef _LLIST_H_
#define _LLIST_H_

#include "location.h"

/* error codes */
#define MALLOC_ERROR        (-99)
#define CALLOC_ERROR        (-100)
#define REALLOC_ERROR       (-101)
#define STR_LENGTH_ERROR    (100)

typedef struct {
    const location *loc; /* This is the prev location, not the current */
    direction backwards; /* Opposite of how the player got there */
} elementStructs;

/**************  nothing else in the module needs to be modified *************/

/* struct for linked list nodes, contains user information and link pointers.
 * the "elementStructs" typemark must be defined based on specific needs of the
 * application.
 */
typedef struct linkedListNodes {
    /* the user information field */
    elementStructs *elementPtr;
    /* link pointers */
    struct linkedListNodes *next;
    struct linkedListNodes *previous;
} linkedListNodes;

/* struct for linked list "header", keeps a counter of the size of the linked list
 */
typedef struct linkedLists {
    /* number of elements in the list */
    int numElements;
    /* pointer to the front of the list of elements, possibly nULL */
    struct linkedListNodes *topPtr;
} linkedLists;

void initLinkedList(linkedLists *listPtr);
void addToLinkedList(linkedLists *listPtr, elementStructs *dataPtr);
elementStructs *removeFromLinkedList(linkedLists *listPtr);
void destroyLinkedList(linkedLists *listPtr);
int getListLen(linkedLists *listPtr);
elementStructs *peekAtLinkedList(linkedLists *listPtr);
#endif /* _LLIST_H_ */
