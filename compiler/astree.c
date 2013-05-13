#include "astree.h"
#include <stdio.h>
#include <stdlib.h>

AST* astCreate(int type, HASH_NODE *symbol, AST *s0, AST *s1, AST *s2, AST *s3) {
    AST *n = calloc(1, sizeof(AST));
    n->type = type;
    n->symbol = symbol;
    n->children[0] = s0;
    n->children[1] = s1;
    n->children[2] = s2;
    n->children[3] = s3;
    return n;
}
