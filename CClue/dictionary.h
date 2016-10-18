#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "llist.h"

/*
typedef struct dictNode {
    struct dictNode *next;
    int hash;
} dictNode;

typedef struct dictionary{
    dictNode **array;
    int maxSize;
    int occupied;
    int (*hashFunc)(void *key);
} dictionary;

#define get_hash_entry(ptr, type, member)\
    ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))
*/

typedef int (*compareFunc)(void *a, void *b);
typedef uint32_t (*hashFunc)(void *key);

typedef struct dictionary {
    LinkedLists *buckets;
    compareFunc compare;
    hashFunc hash;
    size_t maxSize;
    size_t occupied;
} dictionary;

typedef struct dictNode {
    void *key;
    void *data;
    uint32_t hash;
} dictNode;

typedef int (*dictionary_traverse_cb)(dictNode *node);

dictionary *newDictionary(int initSize, hashFunc hash, compareFunc compare);
void deleteDictionary(dictionary *dict);

void dictionaryClear(dictionary *dict);

void *dictionaryFind(dictionary *dict, void *key);
int dictionaryAdd(dictionary *dict, void *key, void *value);
void *dictionaryRemove(dictionary* dict, void *key);

int dictionaryTraverse(dictionary *dict, dictionary_traverse_cb traverse_cb);

void dictionaryToString(dictionary *dict, char *buffer, unsigned int buffLen);



