#include <stdio.h>
#include "sem.h"

void declarations(AST *n) {
    if (!n) return;
    
    if (n->type == AST_DEC_VAR || n->type == AST_DEC_PTR || n->type == AST_DEC_VET || n->type == AST_DEC_FUN || n->type == AST_DEC_LOC_VAR || n->type == AST_DEC_LOC_PTR) {
        if (n->symbol) {
            if (n->symbol->value != SYMBOL_IDENTIFIER) fprintf(stderr, "%d> %s already declared.\n", n->line, n->symbol->key); 
            if (n->type == AST_DEC_VAR) { fprintf(stderr, "var: %d %s\n", n->symbol->value, n->symbol->key); n->symbol->value = SYMBOL_SCALAR; }
            if (n->type == AST_DEC_PTR) { fprintf(stderr, "ptr: %d %s\n", n->symbol->value, n->symbol->key); n->symbol->value = SYMBOL_POINTER; }
            if (n->type == AST_DEC_VET) { fprintf(stderr, "vet: %d %s\n", n->symbol->value, n->symbol->key); n->symbol->value = SYMBOL_VECTOR; }
            if (n->type == AST_DEC_FUN) { fprintf(stderr, "fun: %d %s\n", n->symbol->value, n->symbol->key); n->symbol->value = SYMBOL_FUNCTION; }
            if (n->type == AST_DEC_LOC_VAR) { fprintf(stderr, "dvar: %d %s\n", n->symbol->value, n->symbol->key); n->symbol->value = SYMBOL_SCALAR; }
            if (n->type == AST_DEC_LOC_PTR) { fprintf(stderr, "dptr: %d %s\n", n->symbol->value, n->symbol->key); n->symbol->value = SYMBOL_POINTER; }
        }
    } else {
        if (n->symbol) {
            if (n->symbol->value == SYMBOL_IDENTIFIER) fprintf(stderr, "%d> %s not previously declared.\n", n->line, n->symbol->key); 
        }
    }

    int i;
    for (i = 0; i < 4; i++) declarations(n->children[i]);
}

void usage(AST *n) {
    if (!n) return;

    if (n->symbol) {
        if (n->type == AST_SYMBOL || n->type == AST_ATR) {
            if (n->symbol->value == SYMBOL_VECTOR) fprintf(stderr, "%d> %s should be scalar, not vector.\n", n->line, n->symbol->key);
            else if (n->symbol->value == SYMBOL_FUNCTION) fprintf(stderr, "%d> %s should be scalar, not function.\n", n->line, n->symbol->key);
            else if (n->symbol->value != SYMBOL_SCALAR && n->symbol->value != SYMBOL_POINTER) fprintf(stderr, "%d> %s not previously declared.\n", n->line, n->symbol->key); 
        }

        else if (n->type == AST_VET || n->type == AST_ATR_VET) {
            if (n->symbol->value == SYMBOL_SCALAR) fprintf(stderr, "%d> %s should be vector, not scalar.\n", n->line, n->symbol->key);
            else if (n->symbol->value == SYMBOL_FUNCTION) fprintf(stderr, "%d> %s should be vector, not function.\n", n->line, n->symbol->key);
            else if (n->symbol->value == SYMBOL_POINTER) fprintf(stderr, "%d> %s should be vector, not pointer.\n", n->line, n->symbol->key);
            else if (n->symbol->value != SYMBOL_VECTOR) fprintf(stderr, "%d> %s not previously declared.\n", n->line, n->symbol->key);
        }

        else if (n->type == AST_CALL || n->type == AST_CALL_EMPTY) {
            if (n->symbol->value == SYMBOL_SCALAR) fprintf(stderr, "%d> %s should be function, not scalar.\n", n->line, n->symbol->key);
            else if (n->symbol->value == SYMBOL_VECTOR) fprintf(stderr, "%d> %s should be function, not vector.\n", n->line, n->symbol->key);
            else if (n->symbol->value == SYMBOL_POINTER) fprintf(stderr, "%d> %s should be function, not pointer.\n", n->line, n->symbol->key);
            else if (n->symbol->value != SYMBOL_FUNCTION) fprintf(stderr, "%d> %s not previously declared.\n", n->line, n->symbol->key);
            else if (n->symbol->value == SYMBOL_FUNCTION) { fprintf(stderr, "OK\n"); };
        }
    }

    int i;
    for (i = 0; i < 4; i++) usage(n->children[i]);
}

void datatypes(AST *n) {
    if (!n) return;

    if (n->type == AST_MUL || n->type == AST_DIV || n->type == AST_SUM || n->type == AST_SUB) {
        if (n->children[0]->type != AST_MUL && n->children[0]->type != AST_DIV && n->children[0]->type != AST_SUM && n->children[0]->type != AST_SUB) {
            if (n->children[0]->type == AST_SYMBOL || n->children[0]->type == AST_VET || n->children[0]->type == AST_LIT) {

            }
        }
    }
}
