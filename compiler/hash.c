// Felipe Gonzalez, Renan Drabach

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

#define SIZE 1000

unsigned long hashf(char *key) {
    unsigned long hash = 5381;
    int c;
    while (c = *key++) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

HASH_NODE *table[SIZE];

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

void hashInsert(char *key, int value) {
    unsigned long idx = hashf(key) % SIZE;
    HASH_NODE *n = calloc(1, sizeof(HASH_NODE));
    n->key = calloc(1, strlen(key)+1);
    strcpy(n->key, key);
    n->value = value;
    n->next = table[idx];
    table[idx] = n;
}

void hashPrint() {
    HASH_NODE *n;
    int i;
    for (i = 0; i < SIZE; i++) {
        n = table[i];
        while (n != 0) {
            printf("%s %d\n", n->key, n->value); 
            n = n->next;
        }
    }
}


