#include <stdio.h>
#include "dictionary.h"
#include "location.h"

typedef struct dictEntry {
    location *key;
    location **value;
    dictNode node;
} dictEntry;

int myHash(void *key_p)
{
    return ((location*)key_p)->row * 31 + ((location*)key_p)->col * 31;
}


int main(int argc, char *argv[])
{
    dictionary *myDict = newDictionary(30, &myHash); 
    deleteDictionary(myDict);
    return 0;
}
