#include "hash.h"

#define AST_LIST_DEC 1
#define AST_DEC 2
#define AST_DEC_VAR 3
#define AST_DEC_PTR 4
#define AST_WORD 5
#define AST_BYTE 6
#define AST_BOOL 7
#define AST_SYMBOL 8
#define AST_DEC_VET 9
#define AST_LIST_VAL 10
#define AST_DEC_FUN 11
#define AST_LIST_DEC_LOC 12
#define AST_LIST_DEC_PARAM 13
#define AST_DEC_PARAM 14
#define AST_COMMAND 15
#define AST_ATR 16
#define AST_INPUT 17
#define AST_OUTPUT 18
#define AST_RETURN 19
#define AST_CALL 20
#define AST_BLOCO 21
#define AST_LIST_COM 22
#define AST_IF 23
#define AST_LOOP 24
#define AST_DEREF 25
#define AST_REF 26
#define AST_MUL 27
#define AST_DIV 28
#define AST_SUM 29
#define AST_SUB 30
#define AST_LT 31
#define AST_GT 32
#define AST_LE 33
#define AST_GE 34
#define AST_EQ 35
#define AST_NE 36
#define AST_AND 37
#define AST_OR 38
#define AST_FUN 39
#define AST_LIST_PARAM 40
#define AST_VEC_SIZE 41
#define AST_LIT 42
#define AST_PAREN 43
#define AST_LIST_DEC_PARAM_SEP 44
#define AST_LIST_COM_SEP 45
#define AST_LIST_PARAM_SEP 46
#define AST_DEC_LOC_VAR 47
#define AST_CALL_EMPTY 48
#define AST_EMPTY 49
#define AST_ATR_IF 50

typedef struct astree_node {
    int type;
    HASH_NODE *symbol;
    struct astree_node *children[4];
} AST;

AST* astCreate(int type, HASH_NODE *symbol, AST *s0, AST *s1, AST *s2, AST *s3);
void astPrint(AST *node, int level);
void astPrintNode(AST *node);
