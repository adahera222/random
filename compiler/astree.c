#include "astree.h"
#include "scanner.h"
#include <stdio.h>
#include <stdlib.h>

FILE *yyout;

AST* astCreate(int type, HASH_NODE *symbol, AST *s0, AST *s1, AST *s2, AST *s3) {
    AST *n = calloc(1, sizeof(AST));
    n->type = type;
    n->symbol = symbol;
    n->line = getLineNumber();
    n->children[0] = s0;
    n->children[1] = s1;
    n->children[2] = s2;
    n->children[3] = s3;
    return n;
}

void astPrint(AST *node, int level) {
    if (node == 0) return;
    int i;
    for (i = 0; i < level; i++) printf("  ");
    astPrintNode(node);
    for (i = 0; i < 4; i++) astPrint(node->children[i], level+1);
}

void astPrintFile(AST *node) {
    if (node == 0) return;

    switch(node->type) {
        case AST_LIST_DEC:
            astPrintFile(node->children[0]);
            astPrintFile(node->children[1]);
            break;

        case AST_DEC:
            astPrintFile(node->children[0]);
            break;

        case AST_DEC_VAR:
            astPrintFile(node->children[0]);
            fprintf(yyout, " %s:", node->symbol->key);
            astPrintFile(node->children[1]);
            fprintf(yyout, ";\n");
            break;

        case AST_DEC_PTR:
            astPrintFile(node->children[0]);
            fprintf(yyout, " $%s:", node->symbol->key);
            astPrintFile(node->children[1]);
            fprintf(yyout, ";\n");
            break;

        case AST_DEC_VET:
            astPrintFile(node->children[0]);
            fprintf(yyout, " %s[", node->symbol->key);
            astPrintFile(node->children[1]);
            fprintf(yyout, "]");
            if (node->children[2] != 0) {
                fprintf(yyout, ":");
                astPrintFile(node->children[2]);
            } 
            fprintf(yyout, ";\n");
            break;

        case AST_VET:
            fprintf(yyout, "%s[", node->symbol->key);
            astPrintFile(node->children[0]);
            fprintf(yyout, "]");
            break;

        case AST_WORD: fprintf(yyout, "word"); break;
        case AST_BYTE: fprintf(yyout, "byte"); break;
        case AST_BOOL: fprintf(yyout, "bool"); break;
        case AST_SYMBOL: fprintf(yyout, "%s", node->symbol->key); break;
        case AST_SYMBOL_LIT: fprintf(yyout, "%s", node->symbol->key); break;
        case AST_VET_SIZE: fprintf(yyout, "%s", node->symbol->key); break;
        case AST_LIT: astPrintFile(node->children[0]); break;

        case AST_LIST_VAL:
            astPrintFile(node->children[0]);
            fprintf(yyout, " ");
            astPrintFile(node->children[1]);
            break;

        case AST_DEC_FUN:
            astPrintFile(node->children[0]);
            fprintf(yyout, " %s(", node->symbol->key);
            astPrintFile(node->children[1]);
            fprintf(yyout, ")\n");
            astPrintFile(node->children[2]);
            astPrintFile(node->children[3]);
            fprintf(yyout, "\n");
            break;

        case AST_DEC_LOC_VAR:
            astPrintFile(node->children[0]);
            fprintf(yyout, " %s:", node->symbol->key);
            astPrintFile(node->children[1]);
            fprintf(yyout, ";\n");
            break;

        case AST_DEC_LOC_PTR:
            astPrintFile(node->children[0]);
            fprintf(yyout, " $%s:", node->symbol->key);
            astPrintFile(node->children[1]);
            fprintf(yyout, ";\n");
            break;

        case AST_LIST_DEC_LOC:
            astPrintFile(node->children[0]);
            astPrintFile(node->children[1]);
            break;

        case AST_DEC_PARAM:
            astPrintFile(node->children[0]);
            fprintf(yyout, " %s", node->symbol->key);
            break;

        case AST_LIST_DEC_PARAM:
            astPrintFile(node->children[0]);
            astPrintFile(node->children[1]);
            break;

        case AST_LIST_DEC_PARAM_SEP:
            fprintf(yyout, ", ");
            astPrintFile(node->children[0]);
            break;

        case AST_COMMAND: 
            astPrintFile(node->children[0]); 
            break;

        case AST_ATR:
            fprintf(yyout, "%s = ", node->symbol->key);
            astPrintFile(node->children[0]);
            break;

        case AST_ATR_VET:
            fprintf(yyout, "%s[", node->symbol->key);
            astPrintFile(node->children[0]);
            fprintf(yyout, "] = ");
            astPrintFile(node->children[1]);
            break;

        case AST_INPUT:
            fprintf(yyout, "input ");
            astPrintFile(node->children[0]);
            break;

        case AST_OUTPUT:
            fprintf(yyout, "output ");
            astPrintFile(node->children[0]);
            break;

        case AST_RETURN:
            fprintf(yyout, "return");
            if (node->children[0] != 0) {
                fprintf(yyout, " ");
                astPrintFile(node->children[0]);
            }
            break;

        case AST_CALL:
            fprintf(yyout, "%s(", node->symbol->key);
            astPrintFile(node->children[0]);
            fprintf(yyout, ")");
            break;

        case AST_CALL_EMPTY:
            fprintf(yyout, "%s()", node->symbol->key);
            break;

        case AST_BLOCO:
            fprintf(yyout, "{\n");
            astPrintFile(node->children[0]);
            fprintf(yyout, "\n}");
            break;

        case AST_LIST_COM:
            astPrintFile(node->children[0]); 
            astPrintFile(node->children[1]);
            break;

        case AST_LIST_COM_SEP:
            astPrintFile(node->children[0]);
            fprintf(yyout, ";\n");
            break;

        case AST_IF:
            fprintf(yyout, "\nif (");
            astPrintFile(node->children[0]);
            fprintf(yyout, ")\nthen ");
            astPrintFile(node->children[1]);
            if (node->children[2] != 0) {
                fprintf(yyout, "\nelse ");
                astPrintFile(node->children[2]);
            }
            break;

        case AST_LOOP:
            fprintf(yyout, "loop (");
            astPrintFile(node->children[0]);
            fprintf(yyout, ")\n");
            astPrintFile(node->children[1]);
            break;

        case AST_REF: fprintf(yyout, "&%s", node->symbol->key); break;
        case AST_DEREF: fprintf(yyout, "*%s", node->symbol->key); break;

        case AST_MUL:
            fprintf(yyout, "(");
            astPrintFile(node->children[0]);
            fprintf(yyout, "*");
            astPrintFile(node->children[1]);
            fprintf(yyout, ")");
            break;

        case AST_DIV:
            fprintf(yyout, "(");
            astPrintFile(node->children[0]);
            fprintf(yyout, "/");
            astPrintFile(node->children[1]);
            fprintf(yyout, ")");
            break;

        case AST_SUM:
            fprintf(yyout, "(");
            astPrintFile(node->children[0]);
            fprintf(yyout, "+");
            astPrintFile(node->children[1]);
            fprintf(yyout, ")");
            break;

        case AST_SUB:
            fprintf(yyout, "(");
            astPrintFile(node->children[0]);
            fprintf(yyout, "-");
            astPrintFile(node->children[1]);
            fprintf(yyout, ")");
            break;

        case AST_LT:
            fprintf(yyout, "(");
            astPrintFile(node->children[0]);
            fprintf(yyout, "<");
            astPrintFile(node->children[1]);
            fprintf(yyout, ")");
            break;

        case AST_GT:
            fprintf(yyout, "(");
            astPrintFile(node->children[0]);
            fprintf(yyout, ">");
            astPrintFile(node->children[1]);
            fprintf(yyout, ")");
            break;

        case AST_LE:
            fprintf(yyout, "(");
            astPrintFile(node->children[0]);
            fprintf(yyout, "<=");
            astPrintFile(node->children[1]);
            fprintf(yyout, ")");
            break;

        case AST_GE:
            fprintf(yyout, "(");
            astPrintFile(node->children[0]);
            fprintf(yyout, ">=");
            astPrintFile(node->children[1]);
            fprintf(yyout, ")");
            break;

        case AST_EQ:
            fprintf(yyout, "(");
            astPrintFile(node->children[0]);
            fprintf(yyout, "==");
            astPrintFile(node->children[1]);
            fprintf(yyout, ")");
            break;

        case AST_NE:
            fprintf(yyout, "(");
            astPrintFile(node->children[0]);
            fprintf(yyout, "!=");
            astPrintFile(node->children[1]);
            fprintf(yyout, ")");
            break;

        case AST_AND:
            fprintf(yyout, "(");
            astPrintFile(node->children[0]);
            fprintf(yyout, "&&");
            astPrintFile(node->children[1]);
            fprintf(yyout, ")");
            break;

        case AST_OR:
            fprintf(yyout, "(");
            astPrintFile(node->children[0]);
            fprintf(yyout, "||");
            astPrintFile(node->children[1]);
            fprintf(yyout, ")");
            break;

        case AST_PAREN:
            fprintf(yyout, "(");
            astPrintFile(node->children[0]);
            fprintf(yyout, ")");
            break;

        case AST_FUN: astPrintFile(node->children[0]); break;

        case AST_LIST_PARAM:
            astPrintFile(node->children[0]);
            astPrintFile(node->children[1]);
            break;

        case AST_LIST_PARAM_SEP:
            astPrintFile(node->children[0]);
            fprintf(yyout, ", ");
            break;

        default: break;
    }
}

void astPrintNode(AST *node) {
    if (node == 0) return;

    printf("AST(");
    switch(node->type) {
        case AST_LIST_DEC: printf("Global Declarations"); break;
        case AST_DEC: printf("Declaration"); break;
        case AST_DEC_VAR: printf("Variable Declaration"); break;
        case AST_DEC_PTR: printf("Pointer Declaration"); break;
        case AST_WORD: printf("Word"); break;
        case AST_BYTE: printf("Byte"); break;
        case AST_BOOL: printf("Bool"); break;
        case AST_SYMBOL: printf("Symbol"); break;
        case AST_DEC_VET: printf("Vector Declaration"); break;
        case AST_VET_SIZE: printf("Vector Size"); break;
        case AST_LIT: printf("Literal");
        case AST_LIST_VAL: printf("List"); break;
        case AST_DEC_FUN: printf("Function Declaration"); break;
        case AST_LIST_DEC_LOC: printf("Local Declarations"); break;
        case AST_LIST_DEC_PARAM: printf("Parameter List Declarations"); break;
        case AST_DEC_PARAM: printf("Parameter Declaration"); break;
        case AST_COMMAND: printf("Command"); break;
        case AST_ATR: printf("Attribution"); break;
        case AST_INPUT: printf("Input"); break;
        case AST_OUTPUT: printf("Output"); break;
        case AST_RETURN: printf("Return"); break;
        case AST_CALL: printf("Function Call"); break;
        case AST_BLOCO: printf("Bloco"); break;
        case AST_LIST_COM: printf("Command List"); break;
        case AST_IF: printf("If"); break;
        case AST_LOOP: printf("Loop"); break;
        case AST_DEREF: printf("Dereference"); break;
        case AST_REF: printf("Reference"); break;
        case AST_MUL: printf("*"); break;
        case AST_DIV: printf("/"); break;
        case AST_SUM: printf("+"); break;
        case AST_SUB: printf("-"); break;
        case AST_LT: printf("<"); break;
        case AST_GT: printf(">"); break;
        case AST_LE: printf("<="); break;
        case AST_GE: printf(">="); break;
        case AST_EQ: printf("=="); break;
        case AST_NE: printf("!="); break;
        case AST_AND: printf("&&"); break;
        case AST_OR: printf("||"); break;
        case AST_PAREN: printf("()"); break;
        case AST_FUN: printf("Function"); break;
        case AST_LIST_PARAM: printf("Parameter List"); break;
        default: printf("None"); break;
    }

    if (node->symbol != 0) printf(", %s", node->symbol->key);
    printf(");\n");
}
