#ifndef TAC_HEADER
#define TAC_HEADER

#include <stdlib.h>
#include <stdio.h>

//#include "hash.h"
#include "astree.h"

#define TAC_SYMBOL          1
#define TAC_SUM             2
#define TAC_SUB             3
#define TAC_MUL             4
#define TAC_DIV             5
#define TAC_COPY            6
#define TAC_BEGINFUN        7
#define TAC_ENDFUN          8
#define TAC_IF              9
#define TAC_LABEL           10
#define TAC_SYMBOL_TEMPORARY 11
#define TAC_SYMBOL_LABEL    12
#define TAC_JUMP            13
#define TAC_EQ		14
#define TAC_NE	15
#define TAC_GE	16
#define TAC_LE	17
#define TAC_GT	18
#define TAC_LT	19
#define TAC_OUTPUT 20
#define TAC_INPUT 21
#define TAC_RETURN 22
#define TAC_AND 23
#define TAC_OR 24
#define TAC_LOOP 25
#define TAC_ACCESS_VET 26
#define TAC_ATR_VET 27
#define TAC_FUN_CALL 28

#define TAC_MOV 29
#define TAC_JZ 30

#define TAC_SYMBOL_LIT 31
#define TAC_VAR 32
#define TAC_VET 33
#define TAC_VET_SIZE 34
#define TAC_LIST_VAL 35
#define TAC_JJ 36

typedef struct tac_node
{
    int type;
    HASH_NODE* target;
    HASH_NODE* op1;
    HASH_NODE* op2;
    struct tac_node* prev;
    struct tac_node* next;
}TAC;

TAC* tac_create(int type, HASH_NODE* target, HASH_NODE* op1, HASH_NODE* op2);
void tac_print_single(TAC* tac);
void tac_print_all(TAC* tac);

void tac_print_all_reverse(TAC* tac);

TAC* tac_join(TAC* list1, TAC* list2);
TAC* tac_reverse(TAC* tac);

TAC* genCode(AST* node);

TAC* make_binary_operation(TAC *code0, TAC *code1, int opType);
TAC* make_if_then(TAC *code0, TAC *code1, TAC *code2);
TAC* make_loop(TAC *code0, TAC *code1);

void print_vectCode(TAC* code0,TAC* code1,TAC* code2,TAC* code3);

#endif
