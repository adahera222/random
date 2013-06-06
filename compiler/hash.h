// Felipe Gonzalez, Renan Drabach

// reference: http://blog.2of1.org/2011/07/11/simple-c-hashtable-code/

#define MAX_KEYLEN 100
#define SIZE 1000
#define SYMBOL_UNDEFINED 0
#define SYMBOL_LIT_INTEGER 1
#define SYMBOL_LIT_FLOATING 2
#define SYMBOL_LIT_TRUE 3
#define SYMBOL_LIT_FALSE 4
#define SYMBOL_LIT_CHAR 5
#define SYMBOL_LIT_STRING 6
#define SYMBOL_IDENTIFIER 7
#define SYMBOL_SCALAR 8 
#define SYMBOL_POINTER 9
#define SYMBOL_VECTOR 10
#define SYMBOL_FUNCTION 11
#define DT_INT 12
#define DT_BOOL 13
#define DT_CHAR 14
#define DT_STR 15

typedef struct hash_node {
    char *key;
    int value;
    int data_type;
    struct hash_node *next;
} HASH_NODE;

HASH_NODE *table[SIZE];

void hashInit();
HASH_NODE* hashInsert(char *key, int value);
HASH_NODE* hashFind(char *key);
void hashPrint();
