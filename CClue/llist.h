#ifndef _LLIST_H_
#define _LLIST_H_
/******************************************************************************
 * Linked Lists Module public interface - LinkedLists.n
 * Revised: 2/27/2015
 ******************************************************************************/
#define MAX_STR_LEN         (256)
/* error codes */
#define MALLOC_ERROR        (-99)
#define CALLOC_ERROR        (-100)
#define REALLOC_ERROR       (-101)
#define STR_LENGTH_ERROR    (100)

/******************************************************************************
 * Modify structure ElementStructs to suit your application
 ******************************************************************************/
typedef struct {
    /* Application Specific Definitions */
    void *payload;
} ElementStructs;

/**************  Nothing else in the module needs to be modified *************/

/******************************************************************************
 * struct for linked list nodes, contains user information and link pointers.
 * The "ElementStructs" typemark must be defined based on specific needs of the
 * application.
 ******************************************************************************/
typedef struct LinkedListNodes {
    /* The user information field */
    ElementStructs *ElementPtr;
    /* Link pointers */
    struct LinkedListNodes *Next;
    struct LinkedListNodes *Previous;
} LinkedListNodes;

/*********************************************************************************
 * struct for linked list "header", keeps a counter of the size of the linked list
 **********************************************************************************/
typedef struct LinkedLists {
    /* Number of elements in the list */
    int NumElements;
    /* Pointer to the front of the list of elements, possibly NULL */
    struct LinkedListNodes *FrontPtr;
    /* Pointer to the end of the list of elements, possibly NULL */
    struct LinkedListNodes *BackPtr;
} LinkedLists;

/******************************************************************************
  Function prototypes 
 ******************************************************************************/
void InitLinkedList(LinkedLists *ListPtr);
void AddToFrontOfLinkedList(LinkedLists *ListPtr, ElementStructs *DataPtr);
void AddToBackOfLinkedList(LinkedLists *ListPtr, ElementStructs *DataPtr);
ElementStructs *RemoveFromFrontOfLinkedList(LinkedLists *ListPtr);
ElementStructs *RemoveFromBackOfLinkedList(LinkedLists *ListPtr);
void DestroyLinkedList(LinkedLists *ListPtr);
ElementStructs *SearchList(LinkedLists *ListPtr, char *String);
#endif /* _LLIST_H_ */
