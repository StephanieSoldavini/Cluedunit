#include "dictionary.h"

static void deleteDictNode(dictNode *dNode);
static void dictNodeToString(dictNode *dNode, char *buffer, unsigned int buffLen);

static int default_compare(void *a, void *b, size_t aSize, size_t bSize)
{
    if (aSize == bSize) {
        return memcmp(a, b, aSize);
    } else {
        return -1;
    }
}

static uint32_t default_hash(void *a, size_t len)
{
    char *key = a;
    uint32_t hash = 0;
    uint32_t i = 0;

    for(hash = i = 0; i < len; ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

dictionary *newDictionary(int initSize, hashFunc hash, compareFunc compare)
{
    dictionary* newDict = malloc(sizeof(dictionary));
    if (newDict == NULL) {
        fprintf(stderr, "%s:%d: Failed to malloc.\n", __FILE__, __LINE__);
        exit(99); /*TODO standardize exit codes*/
    }
    newDict->buckets = calloc(initSize, sizeof(dictNode));
    if (newDict->buckets == NULL) {
        fprintf(stderr, "%s:%d: Failed to calloc.\n", __FILE__, __LINE__);
        exit(99); /*TODO standardize exit codes*/
    }
    newDict->maxSize = initSize;
    newDict->occupied = 0;
    newDict->hashFunc = hashFunc;
    return newDict;
}

void deleteDictionary(dictionary *dict)
{
    dictionaryClear(dict);
    free(dict->buckets);
    dict->buckets = NULL;
    free(dict);
    dict = NULL;
}

void dictionaryClear(dictionary *dict)
{
    int i;
    for (i = 0; i < dict->maxSize; ++i) {
        if (dict->buckets[i] != NULL) {
            deleteDictNode(dict->buckets[i]);
            dict->buckets[i] = NULL; /* should already be NULL, but just in case..*/
        }
    }
}

void dictionaryAdd(dictionary *dict, dictNode *node)
{
    int index = node->hash % dict->maxSize;
    if (dict->buckets[index] == NULL) {
        dict->buckets[index] = node; 
    } else {
        node->next = dict->buckets[index];
        dict->buckets[index] = node;
    }
}

void deleteDictNode(dictNode *dNode)
{
    if (dNode->next != NULL) {
        deleteDictNode(dNode->next);
    }
    /*free(dNode);*/
    dNode->next = NULL;
    dNode->hash = 0;
}

void dictionaryToString(dictionary *dict, char *buffer, unsigned int buffLen)
{
    int i;
    buffer[0] = '\0'; /* clear buffer string */
    for (i = 0; i < dict->maxSize; ++i) {
        if (dict->buckets[i] != NULL){
            char nodeBuff[64]; /* TODO standardize size */
            fflush(stdout); 
            dictNodeToString(dict->buckets[i], nodeBuff, sizeof(nodeBuff));
            strncat(buffer, nodeBuff, buffLen);
        }
    }
}

void dictNodeToString(dictNode *dNode, char *buffer, unsigned int buffLen)
{
    snprintf(buffer, buffLen, "This is a dictNode.\n");
}
