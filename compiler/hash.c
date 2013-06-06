// Felipe Gonzalez, Renan Drabach

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

unsigned long hashf(char *key) {
    unsigned long hash = 5381;
    int c;
    while (c = *key++) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

void hashInit() {
    int i;
    for (i = 0; i < SIZE; i++) {
        table[i] = 0;
    }
}

HASH_NODE* hashFind(char *key) {
    unsigned long idx = hashf(key) % SIZE;
    HASH_NODE *n = table[idx];
    while (n) {
        if (strncmp(key, n->key, MAX_KEYLEN) == 0) {
            return n;
        } 
        n = n->next;
    }
    return NULL;
}

HASH_NODE* hashInsert(char *key, int value) {
    HASH_NODE *n;
    if (n = hashFind(key)) return n;
    n = calloc(1, sizeof(HASH_NODE));
    n->key = calloc(1, strlen(key)+1);
    strcpy(n->key, key);
    unsigned long idx = hashf(key) % SIZE;
    n->value = value;
    n->next = table[idx];
    table[idx] = n;
    return n;
}

void hashPrint() {
    printf("\n");
    HASH_NODE *n;
    int i;
    for (i = 0; i < SIZE; i++) {
        n = table[i];
        while (n != 0) {
            printf("key: %s, \tvalue: %d, \tdata_type: %d\n", n->key, n->value, n->data_type); 
            n = n->next;
        }
    }
}


