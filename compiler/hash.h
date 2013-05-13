// Felipe Gonzalez, Renan Drabach

// reference: http://blog.2of1.org/2011/07/11/simple-c-hashtable-code/

#define MAX_KEYLEN 100

typedef struct hash_node {
    char *key;
    int value;
    struct hash_node *next;
} HASH_NODE;

void hashInit();
HASH_NODE* hashInsert(char *key, int value);
HASH_NODE* hashFind(char *key);
void hashPrint();
