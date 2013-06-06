#include <stdio.h>
#include "sem.h"

void declarations(AST *n) {
    if (!n) return;
    
    if (n->type == AST_DEC_VAR || n->type == AST_DEC_PTR || n->type == AST_DEC_VET || n->type == AST_DEC_FUN || n->type == AST_DEC_LOC_VAR || n->type == AST_DEC_LOC_PTR) {
        if (n->symbol) {
            if (n->symbol->value != SYMBOL_IDENTIFIER) fprintf(stderr, "%d> %s already declared.\n", n->line, n->symbol->key); 
            if (n->type == AST_DEC_VAR) {
                n->symbol->value = SYMBOL_SCALAR;
                if (n->children[0]->type == AST_BOOL && n->children[1]->symbol->data_type != L_BOOL) {
                    fprintf(stderr, "%d> %s should be boolean.\n", n->line, n->children[1]->symbol->key);
                } else if ((n->children[0]->type == AST_WORD || n->children[0]->type == AST_BYTE) && (n->children[1]->symbol->data_type != L_INT && n->children[1]->symbol->data_type != L_CHAR)) {
                    fprintf(stderr, "%d> %s should be integer or character.\n", n->line, n->children[1]->symbol->key);
                }
            }
            if (n->type == AST_DEC_PTR) {
                n->symbol->value = SYMBOL_POINTER;
                if (n->children[0]->type == AST_BOOL && n->children[1]->symbol->data_type != L_BOOL) {
                    fprintf(stderr, "%d> %s should be boolean.\n", n->line, n->children[1]->symbol->key);
                } else if ((n->children[0]->type == AST_WORD || n->children[0]->type == AST_BYTE) && (n->children[1]->symbol->data_type != L_INT && n->children[1]->symbol->data_type != L_CHAR)) {
                    fprintf(stderr, "%d> %s should be integer or character.\n", n->line, n->children[1]->symbol->key);
                }
            }
            if (n->type == AST_DEC_VET) n->symbol->value = SYMBOL_VECTOR;
            if (n->type == AST_DEC_FUN) n->symbol->value = SYMBOL_FUNCTION;
            if (n->type == AST_DEC_LOC_VAR) {
                n->symbol->value = SYMBOL_SCALAR;
                if (n->children[0]->type == AST_BOOL && n->children[1]->symbol->data_type != L_BOOL) {
                    fprintf(stderr, "%d> %s should be boolean.\n", n->line, n->children[1]->symbol->key);
                } else if ((n->children[0]->type == AST_WORD || n->children[0]->type == AST_BYTE) && (n->children[1]->symbol->data_type != L_INT && n->children[1]->symbol->data_type != L_CHAR)) {
                    fprintf(stderr, "%d> %s should be integer or character.\n", n->line, n->children[1]->symbol->key);
                }
            }
            if (n->type == AST_DEC_LOC_PTR) {
                n->symbol->value = SYMBOL_POINTER;
                if (n->children[0]->type == AST_BOOL && n->children[1]->symbol->data_type != L_BOOL) {
                    fprintf(stderr, "%d> %s should be boolean.\n", n->line, n->children[1]->symbol->key);
                } else if ((n->children[0]->type == AST_WORD || n->children[0]->type == AST_BYTE) && (n->children[1]->symbol->data_type != L_INT && n->children[1]->symbol->data_type != L_CHAR)) {
                    fprintf(stderr, "%d> %s should be integer or character.\n", n->line, n->children[1]->symbol->key);
                }
            }
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

int isOP(AST *n) {
    if (n->type != AST_DIV && n->type != AST_MUL && n->type != AST_SUM && n->type != AST_SUB &&
        n->type != AST_LT && n->type != AST_GT && n->type != AST_LE && n->type != AST_GE &&
        n->type != AST_EQ && n->type != AST_NE && n->type != AST_AND && n->type != AST_OR)
        return 0;
    return 1;
}

int isOPAR(AST *n) {
    if (n->type != AST_DIV && n->type != AST_MUL && n->type != AST_SUM && n->type != AST_SUB)
        return 0;
    return 1;
}

int isOPBOOL(AST *n) {
    if (n->type != AST_LT && n->type != AST_GT && n->type != AST_LE && n->type != AST_GE &&
        n->type != AST_EQ && n->type != AST_NE && n->type != AST_AND && n->type != AST_OR)
        return 0;
    return 1;
}

int isNC(AST *n) {
    if (n->symbol->data_type != L_INT && n->symbol->data_type != L_CHAR && 
        n->symbol->data_type != AST_BYTE && n->symbol->data_type != AST_WORD) 
        return 0;
    return 1;
}

int isB(AST *n) {
    if (n->symbol->data_type != L_BOOL && n->symbol->data_type != AST_BOOL)
        return 0;
    return 1;
}

void datatypes(AST *n) {
    if (!n) return;

    if (n->type == AST_VET || n->type == AST_ATR_VET) {
        if (!isOPAR(n->children[0])) {
            if (n->children[0]->type == AST_SYMBOL || n->children[0]->type == AST_SYMBOL_LIT || n->children[0]->type == AST_VET) {
                if (isB(n->children[0]) || n->children[0]->symbol->value == SYMBOL_POINTER) {
                    fprintf(stderr, "%d> index of %s shouldn't be boolean or pointer.\n", n->line, n->symbol->key); 
                }
            } else fprintf(stderr, "%d> invalid operator type.\n", n->line);
        }

    } else if (n->type == AST_AND || n->type == AST_OR) {
        if (!isOPBOOL(n->children[0])) {
            if (n->children[0]->type == AST_SYMBOL || n->children[0]->type == AST_SYMBOL_LIT || n->children[0]->type == AST_VET) {
                if (!isB(n->children[0])) {
                    fprintf(stderr, "%d> %s should be boolean.\n", n->line, n->children[0]->symbol->key);
                }
            } else fprintf(stderr, "%d> invalid operator type.\n", n->line);
        }

        if (!isOPBOOL(n->children[1])) {
            if (n->children[1]->type == AST_SYMBOL || n->children[1]->type == AST_SYMBOL_LIT || n->children[1]->type == AST_VET) {
                if (!isB(n->children[1])) {
                    fprintf(stderr, "%d> %s should be boolean.\n", n->line, n->children[1]->symbol->key);
                }
            } else fprintf(stderr, "%d> invalid operator type.\n", n->line);
        }

    } else if (n->type == AST_LE || n->type == AST_GE || n->type == AST_LT || n->type == AST_GT) {
        if (!isOPAR(n->children[0])) {
            if (n->children[0]->type == AST_SYMBOL || n->children[0]->type == AST_SYMBOL_LIT || n->children[0]->type == AST_VET) {
                if (!isNC(n->children[0])) {
                    fprintf(stderr, "%d> %s should be integer or character.\n", n->line, n->children[0]->symbol->key);
                }
            } else fprintf(stderr, "%d> invalid operator type.\n", n->line);
        }

        if (!isOPAR(n->children[1])) {
            if (n->children[1]->type == AST_SYMBOL || n->children[1]->type == AST_SYMBOL_LIT || n->children[1]->type == AST_VET) {
                if (!isNC(n->children[0])) {
                    fprintf(stderr, "%d> %s should be integer or character.\n", n->line, n->children[1]->symbol->key);
                }
            } else fprintf(stderr, "%d> invalid operator type.\n", n->line);
        }

    } else if (n->type == AST_EQ || n->type == AST_NE) {
        if (!isOP(n->children[0])) {
            if (n->children[0]->type == AST_SYMBOL || n->children[0]->type == AST_SYMBOL_LIT || n->children[0]->type == AST_VET) {
                if (n->children[0]->symbol->value == SYMBOL_FUNCTION || n->children[0]->symbol->value == SYMBOL_VECTOR) {
                    fprintf(stderr, "%d> %s shouldn't function or vector.\n", n->line, n->children[0]->symbol->key);
                }
            } else fprintf(stderr, "%d> invalid operator type.\n", n->line);
        }

        if (!isOP(n->children[1])) {
            if (n->children[1]->type == AST_SYMBOL || n->children[1]->type == AST_SYMBOL_LIT || n->children[1]->type == AST_VET) {
                if (n->children[1]->symbol->value == SYMBOL_FUNCTION || n->children[1]->symbol->value == SYMBOL_VECTOR) {
                    fprintf(stderr, "%d> %s shouldn't be a function or vector.\n", n->line, n->children[1]->symbol->key);
                }
            } else fprintf(stderr, "%d> invalid operator type.\n", n->line);
        }

    } else if (n->type == AST_SUB || n->type == AST_DIV || n->type == AST_MUL) {
        if (!isOPAR(n->children[0])) {
            if (n->children[0]->type == AST_SYMBOL || n->children[0]->type == AST_SYMBOL_LIT || n->children[0]->type == AST_VET) {
                //fprintf(stderr, "%d\n", n->children[0]->symbol->value);
                if (!isNC(n->children[0])) {
                        fprintf(stderr, "%d> %s should be an integer or character.\n"); 
                }
            } else fprintf(stderr, "%d> invalid operator type.\n", n->line);
        }

        if (!isOPAR(n->children[1])) {
            if (n->children[1]->type == AST_SYMBOL || n->children[1]->type == AST_SYMBOL_LIT || n->children[1]->type == AST_VET) {
                //fprintf(stderr, "%d\n", n->children[1]->symbol->value);
                if (!isNC(n->children[1])) {
                    fprintf(stderr, "%d> %s should be an integer or character.\n"); 
                }
            } else fprintf(stderr, "%d> invalid operator type.\n", n->line);
        }
    }

    int i;
    for (i = 0; i < 4; i++) datatypes(n->children[i]);
}
