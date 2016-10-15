/******************************************************************************
 An student framework implementation of doubly linked lists that holds 
 elements containing a 256 character string and a sequence number.
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

/******************************************************************************
 Initialize the linked list data structure

 Where: LinkedLists *ListPtr - Pointer to the linked list to create
 Returns: nothing
 Errors: none
******************************************************************************/
void InitLinkedList(LinkedLists *ListPtr) 
{
    ListPtr->NumElements = 0;
    ListPtr->FrontPtr = NULL;
    ListPtr->BackPtr = NULL;
}

/******************************************************************************
 Adds a node to the front of the list.
 
 Where: LinkedLists *ListPtr    - Pointer to the linked list to add to
        ElementStructs *DataPtr - Pointer to the data to add to the list
 Returns: nothing
 Errors: Prints to stderr and exits
******************************************************************************/
void AddToFrontOfLinkedList(LinkedLists *ListPtr, ElementStructs *DataPtr) 
{
    ElementStructs *tempElementPtr = malloc(sizeof(ElementStructs));
    LinkedListNodes *tempNodePtr = malloc(sizeof(LinkedListNodes));

    if (NULL == tempNodePtr || NULL == tempElementPtr) {
        fprintf(stderr, "Error: malloc failed on line %d in %s.\n", __LINE__, __FILE__);
        exit(MALLOC_ERROR);
    }

    /* Copy passed data into a new space */
    memcpy(tempElementPtr, DataPtr, sizeof(ElementStructs));
    
    /* Assign data to new node */
    tempNodePtr->ElementPtr = tempElementPtr;

    /* Rearrange pointers to add new node to list */
    tempNodePtr->Next = ListPtr->FrontPtr;
    if (NULL != ListPtr->FrontPtr) {
        ListPtr->FrontPtr->Previous = tempNodePtr;
    } else {
        ListPtr->BackPtr = tempNodePtr;
    }
    ListPtr->FrontPtr = tempNodePtr;
    tempNodePtr->Previous = NULL;
    ListPtr->NumElements ++;
}	

/******************************************************************************
 Adds a node to the back of the list.

 Where: LinkedLists *ListPtr    - Pointer to the linked list to add to
        ElementStructs *DataPtr - Pointer to the data to add to the list
 Returns: nothing
 Errors: Prints to stderr and exits
******************************************************************************/
void AddToBackOfLinkedList(LinkedLists *ListPtr, ElementStructs *DataPtr) 
{	
    ElementStructs *tempElementPtr = malloc(sizeof(ElementStructs));
    LinkedListNodes *tempNodePtr = malloc(sizeof(LinkedListNodes));

    if (NULL == tempNodePtr || NULL == tempElementPtr) {
        fprintf(stderr, "Error: malloc failed on line %d in %s.\n", __LINE__, __FILE__);
        exit(MALLOC_ERROR);
    }

    /* Copy passed data into a new space */
    memcpy(tempElementPtr, DataPtr, sizeof(ElementStructs));
    
    /* Assign data to new node */
    tempNodePtr->ElementPtr = tempElementPtr;

    /* Rearrange pointers to add new node to list */
    tempNodePtr->Previous = ListPtr->BackPtr;
    if (NULL != ListPtr->BackPtr){
        ListPtr->BackPtr->Next = tempNodePtr;
    } else {
        ListPtr->FrontPtr = tempNodePtr;
    }
    ListPtr->BackPtr = tempNodePtr;
    tempNodePtr->Next = NULL;
    ListPtr->NumElements ++;
}

/******************************************************************************
 Removes a node from the front of the list and returns a pointer to the node
 removed. On empty lists should return a NULL pointer.

 Where: LinkedLists *ListPtr    - Pointer to the linked list to remove from
 Returns: Pointer to the node removed or NULL for none
 Errors: none
******************************************************************************/
ElementStructs *RemoveFromFrontOfLinkedList(LinkedLists *ListPtr) 
{
    ElementStructs *returnElemPtr;
    if (NULL == ListPtr->FrontPtr) {
        returnElemPtr = NULL;
    } else {
        returnElemPtr = ListPtr->FrontPtr->ElementPtr;
        if (ListPtr->FrontPtr == ListPtr->BackPtr) { /* if one element */
            free(ListPtr->FrontPtr);
            ListPtr->BackPtr = NULL;
            ListPtr->FrontPtr = NULL;
        } else {
            /* Rearrange pointers and free old node */
            ListPtr->FrontPtr = ListPtr->FrontPtr->Next;
            free(ListPtr->FrontPtr->Previous);
            ListPtr->FrontPtr->Previous = NULL;
        }
        ListPtr->NumElements --;
    }
    return returnElemPtr;
}

/******************************************************************************
 Removes a node from the back of the list and returns a pointer to the node
 removed. On empty lists should return a NULL pointer.

 Where: LinkedLists *ListPtr    - Pointer to the linked list to remove from
 Returns: Pointer to the node removed or NULL for none
 Errors: none
******************************************************************************/
ElementStructs *RemoveFromBackOfLinkedList(LinkedLists *ListPtr) 
{
    ElementStructs *returnElemPtr;
    if (NULL == ListPtr->BackPtr) {
        returnElemPtr = NULL;
    } else {
        returnElemPtr = ListPtr->BackPtr->ElementPtr;
        if (ListPtr->FrontPtr == ListPtr->BackPtr) { /* if one element */
            free(ListPtr->FrontPtr);
            ListPtr->BackPtr = NULL;
            ListPtr->FrontPtr = NULL;
        } else {
            /* Rearrange pointers and free old node */
            ListPtr->BackPtr = ListPtr->BackPtr->Previous;
            free(ListPtr->BackPtr->Next);
            ListPtr->BackPtr->Next = NULL;
        }
        ListPtr->NumElements --;
    }
    return returnElemPtr;
}

/******************************************************************************
 De-allocates the linked list and resets the struct fields (in the header) 
 to indicate that the list is empty.

 Where: LinkedLists *ListPtr    - Pointer to the linked list to destroy
 Returns: nothing
 Errors: none
******************************************************************************/
void DestroyLinkedList(LinkedLists *ListPtr) 
{
    int notdone = 1; /*once 0, loop ends*/
    ElementStructs *elementPtr;
    while (notdone) { /* destroy elements until there are no more */
        elementPtr = RemoveFromFrontOfLinkedList(ListPtr);
        if (NULL == elementPtr){
            notdone = 0;
        } else {
            free(elementPtr);
        }
    } 
}

/******************************************************************************
 Searches the linked list for a provided word. If found, returns the pointer
 to the element struct. If not found, returns a NULL pointer
 
 Where: LinkedLists *ListPtr - Pointer to the linked list to search
        char *String         - Pointer to the string to search
 Returns: Pointer to the element if found, NULL otherwise
 Errors: none
 * ***************************************************************************/
/* this is irrelevant?
ElementStructs *SearchList(LinkedLists *ListPtr, char *String) 
{
    ElementStructs *returnElemPtr = NULL;
    LinkedListNodes *frontCursor = ListPtr->FrontPtr;
    int notdone = 1; 

    while (notdone){
*/        /* compare front cursor to string */
/*        if (0 == strcmp(frontCursor->ElementPtr->String, String)){
            returnElemPtr = frontCursor->ElementPtr;
            notdone = 0;
        } else {
            frontCursor = frontCursor->Next;
        }
    }
    return returnElemPtr;
}
*/
