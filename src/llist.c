#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

/* initialize the linked list data structure
 * listPtr: pointer to the linked list to create
 */
void initLinkedList(linkedLists *listPtr) 
{
    listPtr->numElements = 0;
    listPtr->topPtr = NULL;
}

/* adds a node to the front of the list.
 * listPtr: pointer to the linked list to add to
 * elementStructs *dataPtr: pointer to the data to add to the list
 * errors: prints to stderr and exits
 */
void addToLinkedList(linkedLists *listPtr, elementStructs *dataPtr) 
{
    elementStructs *tempElementPtr = malloc(sizeof(elementStructs));
    linkedListNodes *tempNodePtr = malloc(sizeof(linkedListNodes));

    if (NULL == tempNodePtr || NULL == tempElementPtr) {
        fprintf(stderr, "error: malloc failed on line %d in %s.\n", __LINE__, __FILE__);
        exit(MALLOC_ERROR);
    }

    /* copy passed data into a new space */
    memcpy(tempElementPtr, dataPtr, sizeof(elementStructs));
    
    /* assign data to new node */
    tempNodePtr->elementPtr = tempElementPtr;

    /* rearrange pointers to add new node to list */
    tempNodePtr->next = listPtr->topPtr;
    if (NULL != listPtr->topPtr) {
        listPtr->topPtr->previous = tempNodePtr;
    } 
    listPtr->topPtr = tempNodePtr;
    tempNodePtr->previous = NULL;
    listPtr->numElements ++;
}	

/* removes a node from the front of the list and returns a pointer to the node
 * removed. on empty lists should return a NULL pointer.
 * listPtr: pointer to the linked list to remove from
 * returns: pointer to the node removed or NULL for none
 */
elementStructs *removeFromLinkedList(linkedLists *listPtr) 
{
    elementStructs *returnElemPtr;
    if (NULL == listPtr->topPtr) {
        returnElemPtr = NULL;
    } else {
        returnElemPtr = listPtr->topPtr->elementPtr;
        if (listPtr->numElements == 1) {
            free(listPtr->topPtr);
            listPtr->topPtr = NULL;
        } else {
            /* rearrange pointers and free old node */
            listPtr->topPtr = listPtr->topPtr->next;
            free(listPtr->topPtr->previous);
            listPtr->topPtr->previous = NULL;
        }
        listPtr->numElements --;
    }
    return returnElemPtr;
}

/* de-allocates the linked list and resets the struct fields (in the header) 
 * to indicate that the list is empty.
 * listPtr: pointer to the linked list to destroy
 */
void destroyLinkedList(linkedLists *listPtr) 
{
    int notdone = 1; /*once 0, loop ends*/
    elementStructs *elementPtr;
    while (notdone) { /* destroy elements until there are no more */
        elementPtr = removeFromLinkedList(listPtr);
        if (NULL == elementPtr){
            notdone = 0;
        } else {
            free(elementPtr);
        }
    } 
}

/* Returns the length of the linked list
 * listPtr: list to check
 * returns: Length of list
 */
int getListLen(linkedLists *listPtr)
{
    return listPtr->numElements;
}

/* Looks at, but does not remove, the top element in the list
 * listPtr: pointer to the linked list to look at
 * returns: pointer to the node looked at or NULL for none
 */
elementStructs *peekAtLinkedList(linkedLists *listPtr) 
{
    if (NULL == listPtr->topPtr) {
        return NULL;
    } else {
        return listPtr->topPtr->elementPtr;
    }
}
