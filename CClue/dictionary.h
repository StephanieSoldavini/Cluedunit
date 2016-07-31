#include <stdlib.h>
#include <stdio.h>

typedef struct dictNode {
    struct dictNode *next;
} dictNode;

typedef struct dictionary{
    dictNode **array;
    int maxSize;
    int occupied;
    int (*hashFunc_p)(void *key_p);
} dictionary;

#define get_hash_entry(ptr, type, member)\
    ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

dictionary *newDictionary(int initSize, int (*hashFunc_p)(void *key_p));
void deleteDictionary(dictionary *dict);
void dictionaryClear(dictionary *dict, int keySize);
void *dictionaryFind(dictionary *dict, void *key_p);
void dictionaryAdd(dictionary *dict, dictNode *node);

void deleteDictNode(dictNode *dNode);


