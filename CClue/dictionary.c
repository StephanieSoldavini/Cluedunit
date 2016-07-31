#include "dictionary.h"

dictionary *newDictionary(int initSize, int (*hashFunc_p)(void *key_p))
{
    dictionary* newDict_p = malloc(sizeof(dictionary));
    if (newDict_p == NULL) {
        fprintf(stderr, "%s:%d: Failed to malloc.\n", __FILE__, __LINE__);
        exit(99); /*TODO standardize exit codes*/
    }
    newDict_p->array = malloc(initSize * sizeof(dictNode));
    if (newDict_p->array == NULL) {
        fprintf(stderr, "%s:%d: Failed to malloc.\n", __FILE__, __LINE__);
        exit(99); /*TODO standardize exit codes*/
    }
    newDict_p->maxSize = initSize;
    newDict_p->occupied = 0;
    newDict_p->hashFunc_p = hashFunc_p;
    return newDict_p;
}

void deleteDictionary(dictionary *dict)
{
    free(dict->array);
    dict->array = NULL;
    free(dict);
    dict = NULL;
}

void dictionaryClear(dictionary *dict, int keySize)
{
    int i;
    for (i = 0; i < dict->maxSize; ++i) {
        deleteDictNode(dict->array[i]->next);
    }
}

void deleteDictNode(dictNode *dNode)
{
    if (dNode->next != NULL) {
        deleteDictNode(dNode->next);
    }
    free(dNode);
    dNode = NULL;
}
