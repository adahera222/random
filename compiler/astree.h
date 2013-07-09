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
#define AST_ATR_VET 17
#define AST_ATR_IF 18
#define AST_INPUT 19
#define AST_OUTPUT 20
#define AST_RETURN 21
#define AST_CALL 22
#define AST_BLOCO 23
#define AST_LIST_COM 24
#define AST_IF 25
#define AST_LOOP 26
#define AST_DEREF 27
#define AST_REF 28
#define AST_MUL 29
#define AST_DIV 30
#define AST_SUM 31
#define AST_SUB 32
#define AST_LT 33
#define AST_GT 34
#define AST_LE 35
#define AST_GE 36
#define AST_EQ 37
#define AST_NE 38
#define AST_AND 39
#define AST_OR 40
#define AST_FUN 41
#define AST_LIST_PARAM 42
#define AST_VET_SIZE 43
#define AST_LIT 44
#define AST_SYMBOL_LIT 45
#define AST_PAREN 46
#define AST_LIST_DEC_PARAM_SEP 47
#define AST_LIST_COM_SEP 48
#define AST_LIST_PARAM_SEP 49
#define AST_DEC_LOC_VAR 50
#define AST_DEC_LOC_PTR 51
#define AST_CALL_EMPTY 52
#define AST_EMPTY 53
#define AST_VET 54

typedef struct astree_node {
    int type;
    int line;
    HASH_NODE *symbol;
    struct astree_node *children[4];
} AST;

AST* astCreate(int type, HASH_NODE *symbol, AST *s0, AST *s1, AST *s2, AST *s3);
void astPrint(AST *node, int level);
void astPrintNode(AST *node);
