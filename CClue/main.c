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
    char buffer[256];
    dictionary *myDict = newDictionary(30, &myHash); 
    location *loc1 = newLocation(1, 2, NULL);
    dictEntry loc1Node;
    dictNode loc1DictNode;
    loc1Node.key = loc1;
    loc1Node.value = &loc1;
    loc1Node.node = loc1DictNode;
    loc1DictNode.next = NULL;
    loc1DictNode.hash = myHash(loc1Node.key);
    dictionaryAdd(myDict, &loc1DictNode);
    dictionaryToString(myDict, buffer, sizeof(buffer));
    deleteDictionary(myDict);
    printf("Finished ToString\n");
    printf("%s\n", buffer);
    printf("Hey something happened.\n");
    return 0;
}
