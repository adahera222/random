#include <stdio.h>
#include "astree.h"

void fparams(AST *n);
void freturn(AST *n, int type);

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
            if (n->type == AST_DEC_FUN) {
                n->symbol->value = SYMBOL_FUNCTION;
                freturn(n, n->symbol->data_type);
            }
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
            else if (n->symbol->value == SYMBOL_FUNCTION) fparams(n);
        }
    }

    int i;
    for (i = 0; i < 4; i++) usage(n->children[i]);
}

int getExpressionType(AST *n) {
    if (!n) return 0;
    if (n->symbol) return n->symbol->data_type; 
    if (n->type == AST_LT || n->type == AST_GT || n->type == AST_LE || n->type == AST_GE &&
        n->type == AST_EQ || n->type == AST_NE || n->type == AST_AND || n->type == AST_OR)
        return AST_BOOL;
    if (n->type == AST_SUB || n->type == AST_DIV || n->type == AST_MUL)
        return AST_WORD;
    int t1, t2;
    t1 = getExpressionType(n->children[0]);
    t2 = getExpressionType(n->children[1]);
    if ((t1 == L_INT || t1 == L_CHAR || t1 == AST_WORD || t1 == AST_BYTE || t1 == L_STR) && (t2 == L_INT || t2 == L_CHAR || t2 == AST_WORD || t2 == AST_BYTE || t2 == L_STR)) return AST_WORD;
    if ((t1 == L_BOOL || t1 == AST_BOOL) && (t2 == L_BOOL || t2 == AST_BOOL)) return AST_BOOL;
}

void freturn(AST *n, int type) {
    if (!n) return;
    if (n->type == AST_RETURN) {
        int t = getExpressionType(n->children[0]);
        if (type == L_INT || type == L_CHAR || type == AST_WORD || type == AST_BYTE || type == L_STR) {
            if (t != L_INT && t != L_CHAR && t != AST_WORD && t != AST_BYTE && t != L_STR)
                fprintf(stderr, "%d> wrong return type.\n", n->line);
        } else if (type == L_BOOL || type == AST_BOOL) {
            if (t != L_BOOL && t != AST_BOOL)
                fprintf(stderr, "%d> wrong return type.\n", n->line);
        }
    }

    int i;
    for (i = 0; i < 4; i++) freturn(n->children[i], type);
}

void lparams(AST *n, AST *dec_params, AST *call_params) {
    if (dec_params == 0 && call_params == 0) return;
    if ((dec_params == 0 && call_params != 0) || (dec_params != 0 && call_params == 0)) {
        fprintf(stderr, "%d> invalid number of parameters on %s function call.\n", n->line, n->symbol->key);
        return;
    }

    if ((dec_params->children[1]) && (call_params->children[1])) {
        int type = getExpressionType(call_params->children[1]);
        if ((dec_params->children[1]->symbol->data_type == L_INT || dec_params->children[1]->symbol->data_type == L_CHAR || 
             dec_params->children[1]->symbol->data_type == AST_WORD || dec_params->children[1]->symbol->data_type == AST_BYTE) && 
           (type != AST_WORD && type != AST_BYTE && type != L_INT && type != L_CHAR)) {
            fprintf(stderr, "%d> %s should be word or byte.\n", n->line, call_params->children[1]->symbol->key);
        }
        else if ((dec_params->children[1]->symbol->data_type == L_BOOL || dec_params->children[1]->symbol->data_type == AST_BOOL) && 
                (type != AST_BOOL && type != L_BOOL)) {
            fprintf(stderr, "%d> %s should be boolean.\n", n->line, call_params->children[1]->symbol->key);
        }
    }

    lparams(n, dec_params->children[0], call_params->children[0]);
}

void fparams(AST *n) {
    if (!n) return;

    if (n->type == AST_CALL_EMPTY) {
        if (n->symbol->params->type != AST_EMPTY) {
            fprintf(stderr, "%d> missing parameters on %s function call.\n", n->line, n->symbol->key);
        }
    } else if (n->type == AST_CALL) {
        if (n->symbol->params->type != AST_EMPTY) {
            lparams(n, n->symbol->params, n->children[0]);
        }
    }
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
        n->symbol->data_type != AST_BYTE && n->symbol->data_type != AST_WORD && n->symbol->data_type != L_STR) 
        return 0;
    return 1;
}

int isB(AST *n) {
    if (n->symbol->data_type != L_BOOL && n->symbol->data_type != AST_BOOL && n->symbol->data_type != L_STR)
        return 0;
    return 1;
}

int sumType(AST *n) {
    if (!n) return 0;
    if (n->symbol) {
        return n->symbol->value;
    }
    if (n->type == AST_LT || n->type == AST_GT || n->type == AST_LE || n->type == AST_GE &&
        n->type == AST_EQ || n->type == AST_NE || n->type == AST_AND || n->type == AST_OR)
        return 0;
    if (n->type == AST_SUB || n->type == AST_DIV || n->type == AST_MUL) {
        int t1, t2;
        t1 = sumType(n->children[0]);
        t2 = sumType(n->children[1]);
        if ((t1 != SYMBOL_LIT_INTEGER && t1 != SYMBOL_LIT_CHAR) ||
            (t2 != SYMBOL_LIT_INTEGER && t2 != SYMBOL_LIT_CHAR)) {
            fprintf(stderr, "%d> operation should be between integers or chars.\n", n->line);
            return 0;
        }
        else return SYMBOL_SCALAR;
    }
    
    if (n->type == AST_SUM) {
        int r1, r2;
        r1 = sumType(n->children[0]);
        r2 = sumType(n->children[1]);
        if ((r1 != SYMBOL_LIT_INTEGER && r1 != SYMBOL_LIT_CHAR && r1 != SYMBOL_SCALAR) && (r2 != SYMBOL_LIT_INTEGER && r2 != SYMBOL_LIT_CHAR && r2 != SYMBOL_SCALAR)) {
            fprintf(stderr, "%d> operation should be between integers/chars or pointers.\n", n->line);
            return 0;
        }
    }
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
                if (!isNC(n->children[0]) || n->children[0]->symbol->value == SYMBOL_POINTER) {
                    fprintf(stderr, "%d> %s should be an integer or character.\n", n->line, n->children[0]->symbol->key); 
                }
            } else fprintf(stderr, "%d> invalid operator type.\n", n->line);
        }

        if (!isOPAR(n->children[1])) {
            if (n->children[1]->type == AST_SYMBOL || n->children[1]->type == AST_SYMBOL_LIT || n->children[1]->type == AST_VET) {
                if (!isNC(n->children[1]) || n->children[1]->symbol->value == SYMBOL_POINTER) {
                    fprintf(stderr, "%d> %s should be an integer or character.\n", n->line, n->children[1]->symbol->key); 
                }
            } else fprintf(stderr, "%d> invalid operator type.\n", n->line);
        }

    } else if (n->type == AST_SUM) {
        sumType(n);
    }

    int i;
    for (i = 0; i < 4; i++) datatypes(n->children[i]);
}
