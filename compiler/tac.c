#include "tac.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

FILE *yyout;
char functions[200][200][50];
char locals[200][200][50];
char symbols[200][50];
int n_symbols = 0;

TAC* tac_create(int type, HASH_NODE* target, HASH_NODE* op1, HASH_NODE* op2)
{
    TAC* tac;
    tac = (TAC*) calloc(1,sizeof(TAC));
    
    tac->type = type;
    tac->target = target;
    tac->op1 = op1;
    tac->op2 = op2;
    tac->next = 0;
    tac->prev = 0;
    
    //tac_print_one(tac);
    return tac;
}

void tac_print_one(TAC* tac)
{
    if(!tac) {
        fprintf(stderr, "print one tac null(0)\n");
        return;
    }
    printf("TAC(");
    switch(tac->type)
    {
        case TAC_SYMBOL: printf("TAC_SYMBOL");break;
        case TAC_SYMBOL_LIT: printf("TAC_SYMBOL_LIT");break;
        case TAC_VAR: printf("TAC_VAR");break;
        case TAC_LOC_VAR: printf("TAC_LOC_VAR");break;
        case TAC_VET: printf("TAC_VET");break;
        case TAC_VET_SIZE: printf("TAC_VET_SIZE");break;
        case TAC_SUM: printf("TAC_SUM");break;
        case TAC_SUB: printf("TAC_SUB");break;
        case TAC_MUL: printf("TAC_MUL");break;
        case TAC_DIV: printf("TAC_DIV");break;
        case TAC_BEGINFUN: printf("TAC_BEGINFUN");break;
        case TAC_ENDFUN: printf("TAC_ENDFUN");break;
		case TAC_COPY: printf("TAC_COPY");break;
		case TAC_EQ: printf("TAC_EQ");break;
		case TAC_NE: printf("TAC_NE");break;
		case TAC_GE: printf("TAC_GE");break;
		case TAC_LE: printf("TAC_LE");break;
		case TAC_GT: printf("TAC_GT");break;
		case TAC_LT: printf("TAC_LT");break;
		case TAC_IF: printf("TAC_IF");break;
		case TAC_OUTPUT: printf("TAC_OUTPUT");break;
		case TAC_INPUT: printf("TAC_INPUT");break;
		case TAC_RETURN: printf("TAC_RETURN");break;
		case TAC_AND: printf("TAC_AND");break;
		case TAC_OR: printf("TAC_OR");break;
		case TAC_LABEL: printf("TAC_LABEL");break;
		case TAC_JUMP: printf("TAC_JUMP");break;
		case TAC_ACCESS_VET: printf("TAC_ACCESS_VET");break;
		case TAC_ATR_VET: printf("TAC_ATR_VET");break;
		case TAC_FUN_CALL: printf("TAC_FUN_CALL");break;
        case TAC_FUN_CALL_PARAM: printf("TAC_FUN_CALL_PARAM");break;
        case TAC_PARAM: printf("TAC_PARAM");break;
		case TAC_LOOP: printf("TAC_LOOP");break;
        case TAC_MOV: printf("TAC_MOV");break;
        case TAC_JZ: printf("TAC_JZ");break;
        case TAC_JJ: printf("TAC_JJ");break;
        case TAC_DEC_PARAM: printf("TAC_DEC_PARAM");break;
        default: printf("tipo nao encontrado: %d", tac->type);break;
    }
    
    if (tac->target !=0)
        printf(", %s", tac->target->key);
    else printf(", null(0)");
    
    if (tac->op1 !=0)
        printf(", %s", tac->op1->key);
    else printf(", null(0)");
    
    if (tac->op2 !=0)
        printf(", %s", tac->op2->key);
    else printf(", null(0)");
    
    printf(")\n");
}

void tac_print_all(TAC* tac)
{
	TAC* print = tac;
    
    if(!print) {
        fprintf(stderr, "print all tac null(0)\n");
        return;
    }
    
	while (print) 
	{
		tac_print_one(print);
		print = print->next;
	}
}

void tac_print_all_reverse(TAC* tac)
{
	TAC* print = tac;
    
    if(!print) {
        fprintf(stderr, "print all tac null(0)\n");
        return;
    }
    
	while (print) 
	{
		tac_print_one(print);
        print = print->prev;
	}
}

//aula
TAC *tac_reverse(TAC *last)
{
    TAC *first = 0;
    
    if (last == 0)
        return 0;
    
    for (first = last; first->prev; first=first->prev) {
        first->prev->next = first;
    }
    
    return first;
}

//aula
TAC* tac_join(TAC* list1, TAC* list2)
{
    if (!list2)
        return list1;
    if (!list1)
        return list2;
    
    //TAC *aux = 0;
    TAC *aux;
	for (aux=list2; aux->prev; aux=aux->prev)
        ;//percorre até o início...
    
    aux->prev=list1;

    return list2;
}

int contains(char symbols[][50], char *key, int n) {
    int i = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(symbols[i], key) == 0) return 1;
    }
    return 0;
}

char *getValue(char fun[], char key[], int n) {
    int i = 0;
    int j = 0;
    int n_size = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(functions[i][0], fun) == 0) {
            for (j = 0; j < 50; j++) {
                if (strcmp(functions[i][j], "000") == 0) { n_size = j; }
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (strcmp(locals[i][0], fun) == 0) {
            for (j = 1; j < 50; j++) {
                if (strcmp(locals[i][j], key) == 0) { 
                    int p = 8+(n_size-1+j-1)*4;
                    char *str = malloc(50*sizeof(char));
                    sprintf(str, "%d", p);
                    strcat(str, "(%ebp)");
                    return str;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (strcmp(functions[i][0], fun) == 0) {
            for (j = 1; j < 50; j++) {
                if (strcmp(functions[i][j], key) == 0) { 
                    int p = 8+(j-1)*4;
                    char *str2 = malloc(50*sizeof(char));
                    sprintf(str2, "%d", p);
                    strcat(str2, "(%ebp)");
                    return str2; 
                }
            }
        }
    }
    char *str3 = malloc(50*sizeof(char));
    strcpy(str3, "_");
    strcat(str3, key);
    return str3;
}

void generateASM(TAC *list) {
    printf("\n\n");
    // Go over list once to find all literals, outputs and label them
    int n_output = 0;
    TAC *lit = list;
    while (lit) {
        switch (lit->type) {
            case TAC_SYMBOL_LIT: 
                if (!contains(symbols, lit->target->key, n_symbols)) {
                    if (isdigit((int)lit->target->key[0])) {
                        fprintf(yyout, ".data\n_%s: .long %s\n", lit->target->key, lit->target->key); 
                        strcpy(symbols[n_symbols], lit->target->key); 
                        n_symbols++;
                    } else if (lit->target->key[0] == '_') {
                        fprintf(yyout, ".data\n_%s: .long 0\n", lit->target->key); 
                        strcpy(symbols[n_symbols], lit->target->key); 
                        n_symbols++;
                    } else if (lit->target->key[0] == '\'') {
                        fprintf(yyout, ".data\n_%s: .long %d\n", lit->target->key, (int)lit->target->key[1]); 
                        strcpy(symbols[n_symbols], lit->target->key); 
                        n_symbols++;
                    } else if (lit->target->key[0] == 't' || lit->target->key[0] == 'T') {
                        fprintf(yyout, ".data\n_%s: .long 1\n", lit->target->key);
                        strcpy(symbols[n_symbols], lit->target->key); 
                        n_symbols++;
                    } else if (lit->target->key[0] == 'f' || lit->target->key[0] == 'F') {
                        fprintf(yyout, ".data\n_%s: .long 0\n", lit->target->key);
                        strcpy(symbols[n_symbols], lit->target->key); 
                        n_symbols++;
                    } else {
                        fprintf(yyout, ".data\n_%s: .long 0\n", lit->target->key);
                        strcpy(symbols[n_symbols], lit->target->key); 
                        n_symbols++;
                    }
                }
                break;
            case TAC_PARAM:
                if (lit->target) {
                    if (!contains(symbols, lit->target->key, n_symbols)) {
                        if (isdigit((int)lit->target->key[0])) {
                            fprintf(yyout, ".data\n_%s: .long %s\n", lit->target->key, lit->target->key); 
                            strcpy(symbols[n_symbols], lit->target->key); 
                            n_symbols++;
                        } else if (lit->target->key[0] == '_') {
                            fprintf(yyout, ".data\n_%s: .long 0\n", lit->target->key); 
                            strcpy(symbols[n_symbols], lit->target->key); 
                            n_symbols++;
                        } else if (lit->target->key[0] == '\'') {
                            fprintf(yyout, ".data\n_%s: .long %d\n", lit->target->key, (int)lit->target->key[1]); 
                            strcpy(symbols[n_symbols], lit->target->key); 
                            n_symbols++;
                        } else if (lit->target->key[0] == 't' || lit->target->key[0] == 'T') {
                            fprintf(yyout, ".data\n_%s: .long 1\n", lit->target->key);
                            strcpy(symbols[n_symbols], lit->target->key); 
                            n_symbols++;
                        } else if (lit->target->key[0] == 'f' || lit->target->key[0] == 'F') {
                            fprintf(yyout, ".data\n_%s: .long 0\n", lit->target->key);
                            strcpy(symbols[n_symbols], lit->target->key); 
                            n_symbols++;
                        } else {
                            fprintf(yyout, ".data\n_%s: .long 0\n", lit->target->key);
                            strcpy(symbols[n_symbols], lit->target->key); 
                            n_symbols++;
                        }
                    }
                }
                break;
            case TAC_LOC_VAR:
                if (lit->op1) {
                    if (!contains(symbols, lit->op1->key, n_symbols)) {
                        if (isdigit((int)lit->op1->key[0])) {
                            fprintf(yyout, ".data\n_%s: .long %s\n", lit->op1->key, lit->op1->key); 
                            strcpy(symbols[n_symbols], lit->op1->key); 
                            n_symbols++;
                        } else if (lit->op1->key[0] == '\'') {
                            fprintf(yyout, ".data\n_%s: .long %d\n", lit->op1->key, (int)lit->op1->key[1]); 
                            strcpy(symbols[n_symbols], lit->op1->key); 
                            n_symbols++;
                        } else if (lit->op1->key[0] == 't' || lit->op1->key[0] == 'T') {
                            fprintf(yyout, ".data\n_%s: .long 1\n", lit->op1->key);
                            strcpy(symbols[n_symbols], lit->op1->key); 
                            n_symbols++;
                        } else if (lit->op1->key[0] == 'f' || lit->op1->key[0] == 'F') {
                            fprintf(yyout, ".data\n_%s: .long 0\n", lit->op1->key);
                            strcpy(symbols[n_symbols], lit->op1->key); 
                            n_symbols++;
                        }
                    }
                }
                break;
            case TAC_INPUT:
                fprintf(yyout, "LC%d: .string \"%%d\"\n", n_output);
                n_output++;
                break;
            case TAC_OUTPUT:
                fprintf(yyout, "LC%d: .string \"%%d\\n\"\n", n_output); 
                n_output++;
                break;
            case TAC_SUM:
                if (!contains(symbols, lit->target->key, n_symbols)) {
                    fprintf(yyout, ".data\n_%s: .long 0\n", lit->target->key); 
                    strcpy(symbols[n_symbols], lit->target->key); 
                    n_symbols++;
                }
                break;
            case TAC_SUB:
                if (!contains(symbols, lit->target->key, n_symbols)) {
                    fprintf(yyout, ".data\n_%s: .long 0\n", lit->target->key); 
                    strcpy(symbols[n_symbols], lit->target->key); 
                    n_symbols++;
                }
                break;
            case TAC_DIV:
                if (!contains(symbols, lit->target->key, n_symbols)) {
                    fprintf(yyout, ".data\n_%s: .long 0\n", lit->target->key); 
                    strcpy(symbols[n_symbols], lit->target->key); 
                    n_symbols++;
                }
                break;
            case TAC_MUL:
                if (!contains(symbols, lit->target->key, n_symbols)) {
                    fprintf(yyout, ".data\n_%s: .long 0\n", lit->target->key); 
                    strcpy(symbols[n_symbols], lit->target->key); 
                    n_symbols++;
                }
                break;
            case TAC_FUN_CALL:
                if (!contains(symbols, lit->target->key, n_symbols)) {
                    fprintf(yyout, ".data\n_%s: .long 0\n", lit->target->key); 
                    strcpy(symbols[n_symbols], lit->target->key); 
                    n_symbols++;
                }
                break;
            case TAC_FUN_CALL_PARAM:
                if (!contains(symbols, lit->target->key, n_symbols)) {
                    fprintf(yyout, ".data\n_%s: .long 0\n", lit->target->key); 
                    strcpy(symbols[n_symbols], lit->target->key); 
                    n_symbols++;
                }
                break;
            case TAC_ACCESS_VET:
                if (!contains(symbols, lit->target->key, n_symbols)) {
                    fprintf(yyout, ".data\n_%s: .long 0\n", lit->target->key); 
                    strcpy(symbols[n_symbols], lit->target->key); 
                    n_symbols++;
                }
                break;
            default: break;
        }
        lit = lit->next;
    }

    // Find all function declarations and calls
    TAC *lit2 = list;
    int n_functions = 0;
    int n_size = 1;
    while (lit2) {
        switch (lit2->type) {
            case TAC_BEGINFUN:
                strcpy(functions[n_functions][0], lit2->target->key);
                strcpy(functions[n_functions][n_size], "000");
                n_size = 1;
                n_functions++;
                break;

            case TAC_DEC_PARAM:
                if (lit2->target) {
                    strcpy(functions[n_functions][n_size], lit2->target->key);
                    n_size++;
                }
                break;
        }
        lit2 = lit2->next;
    }

    TAC *lit3 = list;
    int n_f_locals = 0;
    int n_l_size = 1;
    while (lit3) {
        switch(lit3->type) {
            case TAC_ENDFUN:
                strcpy(locals[n_f_locals][0], lit3->target->key);
                n_l_size = 1;
                n_f_locals++;
                break;
            case TAC_LOC_VAR:
                if (lit3->target) {
                    strcpy(locals[n_f_locals][n_l_size], lit3->target->key);
                    strcpy(locals[n_f_locals][n_l_size+1], lit3->op1->key);
                    strcpy(locals[n_f_locals][n_l_size+2], "000");
                    n_l_size+=2;
                }
                break;
        }
        lit3 = lit3->next;
    }

    int max_params = -10000;
    int current_params = 0;
    int i, j;
    for (i = 0; i < n_functions; i++) {
        current_params = 0;
        for (j = 1; j < 200; j++) {
            if (strcmp(functions[i][j], "000") != 0) current_params++;
            else {
                if (current_params > max_params) max_params = current_params;
                break;
            }
        }
    }
    // fprintf(stderr, "%d\n", max_params);

    /*
    for (i = 0; i < n_functions; i++) {
        for (j = 0; j < 20; j++) {
            if (strcmp(functions[i][j], "000") != 0) fprintf(stderr, "%s\n", functions[i][j]);
            else break;
        }
    }

    for (i = 0; i < n_f_locals; i++) {
        for (j = 0; j < 20; j++) {
            if (strcmp(locals[i][j], "000") != 0) fprintf(stderr, "%s\n", locals[i][j]);
            else break;
        }
    }
    */

    // Go over list again with all literals set
    TAC *tac = list;
    n_output = 0;
    int cur_op = 0;
    int cur_param = 0;
    char cur_fun[50];
    char key[50];
    int compl = 0;
    int iforloop = 0;
    while (tac) {
        switch(tac->type)
        {
            case TAC_SYMBOL: break;
            case TAC_SYMBOL_LIT: break;
            case TAC_VAR: 
                if (!contains(symbols, tac->target->key, n_symbols)) {
                    if (isdigit((int)tac->op1->key[0])) {
                        fprintf(yyout, ".data\n_%s: .long %s\n", tac->target->key, tac->op1->key);
                        strcpy(symbols[n_symbols], tac->target->key); 
                        n_symbols++;
                    }
                    else if (tac->op1->key[0] == '\'') {
                        fprintf(yyout, ".data\n_%s: .long %d\n", tac->target->key, (int)tac->op1->key[1]);
                        strcpy(symbols[n_symbols], tac->target->key); 
                        n_symbols++;
                    }
                    else if (tac->op1->key[0] == 't' || tac->op1->key[0] == 'T') {
                        fprintf(yyout, ".data\n_%s: .long 1\n", tac->target->key);
                        strcpy(symbols[n_symbols], tac->target->key); 
                        n_symbols++;
                    }
                    else if (tac->op1->key[0] == 'f' || tac->op1->key[0] == 'F') {
                        fprintf(yyout, ".data\n_%s: .long 0\n", tac->target->key);
                        strcpy(symbols[n_symbols], tac->target->key); 
                        n_symbols++;
                    }
                }
                break;
            case TAC_VET:
                fprintf(yyout, ".data\n.comm _%s, %d\n", tac->target->key, atoi(tac->op1->key)*4);
                break;
            case TAC_SUM: 
                fprintf(yyout, "movl %s, %%edx\nmovl %s, %%eax\naddl %%eax, %%edx\nmovl %%edx, %s\n", 
                        getValue(cur_fun, tac->op1->key, n_functions), getValue(cur_fun, tac->op2->key, n_functions), getValue(cur_fun, tac->target->key, n_functions));
                break;
            case TAC_SUB: 
                fprintf(yyout, "movl %s, %%edx\nmovl %s, %%eax\nsubl %%eax, %%edx\nmovl %%edx, %s\n", 
                        getValue(cur_fun, tac->op1->key, n_functions), getValue(cur_fun, tac->op2->key, n_functions), getValue(cur_fun, tac->target->key, n_functions));
                break;
            case TAC_MUL:
                fprintf(yyout, "movl %s, %%edx\nmovl %s, %%eax\nimull %%eax, %%edx\nmovl %%edx, %s\n", 
                        getValue(cur_fun, tac->op1->key, n_functions), getValue(cur_fun, tac->op2->key, n_functions), getValue(cur_fun, tac->target->key, n_functions));
                break;
            case TAC_DIV: 
                fprintf(yyout, "movl _%s, %%edx\nmovl _%s, %%eax\nmovl %%eax, 28(%%esp)\ncltd\nidivl 28(%%esp)\nmovl %%edx, _%s\n", tac->op1->key, tac->op2->key, tac->target->key);
                break;
            case TAC_BEGINFUN: 
                if (strcmp(tac->target->key, "main")) {
                    fprintf(yyout, ".text\n.globl %s\n.type %s, @function\n%s:\npushl %%ebp\nmovl %%esp, %%ebp\n", tac->target->key, tac->target->key, tac->target->key);
                } else {
                    fprintf(yyout, ".text\n.globl main\n.type main, @function\nmain:\npushl %%ebp\nmovl %%esp, %%ebp\nandl $-16, %%esp\nsubl $%d, %%esp\n", 8+max_params*4);
                }
                strcpy(cur_fun, tac->target->key);
                break;
                
            case TAC_ENDFUN: 
                if (strcmp(tac->target->key, "main")) {
                    fprintf(yyout, "popl %%ebp\nret\n");
                } else {
                    fprintf(yyout, "leave\nret\n");
                }
                cur_param = 0;
                break;
            case TAC_PARAM: 
                if (tac->target) {
                    fprintf(yyout, "movl _%s, %%eax\nmovl %%eax, %d(%%esp)\n", tac->target->key, cur_param*4); 
                    cur_param++;
                }
                break;
            case TAC_DEC_PARAM:
                if (tac->target) {
                    cur_param++;
                }
                break;
            case TAC_LOC_VAR: 
                if (tac->target) {
                    fprintf(yyout, "movl _%s, %%eax\nmovl %%eax, %d(%%esp)\nmovl %%esp, %%ebp\n", tac->op1->key, 8+cur_param*4); 
                    cur_param+=2;
                }
                break;
            case TAC_COPY: printf("TAC_COPY");break;
            case TAC_EQ: 
                /*
                compl = atoi(tac->op2->key) - 1;
                strcpy(key, "");
                sprintf(key, "%d", compl);
                */
                fprintf(yyout, "movl %s, %%eax\nmovl %s, %%edx\ncmpl %%edx, %%eax\n", 
                        getValue(cur_fun, tac->op1->key, n_functions), getValue(cur_fun, tac->op2->key, n_functions));
                cur_op = TAC_EQ;
                break;
            case TAC_NE:
                fprintf(yyout, "movl %s, %%eax\nmovl %s, %%edx\ncmpl %%edx, %%eax\n", 
                        getValue(cur_fun, tac->op1->key, n_functions), getValue(cur_fun, tac->op2->key, n_functions));
                cur_op = TAC_NE;
                break;
            case TAC_GE: 
                fprintf(yyout, "movl %s, %%eax\nmovl %s, %%edx\ncmpl %%edx, %%eax\n", 
                        getValue(cur_fun, tac->op1->key, n_functions), getValue(cur_fun, tac->op2->key, n_functions));
                cur_op = TAC_GE;
                break;
            case TAC_LE: 
                fprintf(yyout, "movl %s, %%eax\nmovl %s, %%edx\ncmpl %%edx, %%eax\n", 
                        getValue(cur_fun, tac->op1->key, n_functions), getValue(cur_fun, tac->op2->key, n_functions));
                cur_op = TAC_LE;
                break;
            case TAC_GT: 
                fprintf(yyout, "movl %s, %%eax\nmovl %s, %%edx\ncmpl %%edx, %%eax\n", 
                        getValue(cur_fun, tac->op1->key, n_functions), getValue(cur_fun, tac->op2->key, n_functions));
                cur_op = TAC_GT;
                break;
            case TAC_LT: 
                fprintf(yyout, "movl %s, %%eax\nmovl %s, %%edx\ncmpl %%edx, %%eax\n", 
                        getValue(cur_fun, tac->op1->key, n_functions), getValue(cur_fun, tac->op2->key, n_functions));
                cur_op = TAC_LT;
                break;
            case TAC_IF: iforloop = 0; break;
            case TAC_OUTPUT: 
                fprintf(yyout, "movl %s, %%eax\nmovl %%eax, 4(%%esp)\nmovl $LC%d, (%%esp)\ncall printf\n", getValue(cur_fun, tac->target->key, n_functions), n_output);
                n_output++;
                cur_param = 0;
                break;
            case TAC_INPUT: 
                fprintf(yyout, "movl $%s, 4(%%esp)\nmovl $LC%d, (%%esp)\ncall __isoc99_scanf\n", getValue(cur_fun, tac->target->key, n_functions), n_output);
                n_output++;
                cur_param = 0;
                break;
            case TAC_RETURN: 
                fprintf(yyout, "movl %s, %%eax\n", getValue(cur_fun, tac->target->key, n_functions));
                break;
            case TAC_AND: 
                fprintf(yyout, "movl %s, %%eax\nmovl %s, %%edx\ntestl %%eax, %%eax\n", 
                        getValue(cur_fun, tac->op1->key, n_functions), getValue(cur_fun, tac->op2->key, n_functions));
                cur_op = TAC_AND;
                break;
            case TAC_OR: 
                /*
                fprintf(yyout, "movl _%s, %%eax\nmovl _%s, %%edx\ntestl %%eax, %%eax\n", tac->op1->key, tac->op2->key);
                cur_op = TAC_OR;
                */
                break;
            case TAC_LABEL: 
                fprintf(yyout, "%s:\n", tac->target->key);
                break;
            case TAC_JUMP: 
                fprintf(yyout, "jmp %s\n", tac->target->key); 
                break;
            case TAC_ACCESS_VET: 
                fprintf(yyout, "movl %s+%d, %%eax\nmovl %%eax, %s\n", 
                        getValue(cur_fun, tac->op1->key, n_functions), atoi(tac->op2->key)*4, getValue(cur_fun, tac->target->key, n_functions));
                break;
            case TAC_ATR_VET:
                fprintf(yyout, "movl %s, %%eax\nmovl %%eax, %s+%d\n", 
                        getValue(cur_fun, tac->op2->key, n_functions), getValue(cur_fun, tac->target->key, n_functions), atoi(tac->op1->key)*4);
                break;
            case TAC_FUN_CALL: 
                fprintf(yyout, "call %s\nmovl %%eax, %s\n", tac->op1->key, getValue(cur_fun, tac->target->key, n_functions));
                cur_param = 0;
                break;
            case TAC_FUN_CALL_PARAM:
                fprintf(yyout, "call %s\nmovl %%eax, %s\n", tac->op1->key, getValue(cur_fun, tac->target->key, n_functions));
                cur_param = 0;
                break;
            case TAC_LOOP: iforloop = 1; break;
            case TAC_MOV: 
                fprintf(yyout, "movl %s, %%eax\nmovl %%eax, %s\n", 
                        getValue(cur_fun, tac->op1->key, n_functions), getValue(cur_fun, tac->target->key, n_functions));
                break;
            case TAC_JZ: 
                if (!iforloop) {
                    switch (cur_op) {
                        case TAC_GT: fprintf(yyout, "jle %s\n", tac->target->key); break;
                        case TAC_LT: fprintf(yyout, "jge %s\n", tac->target->key); break;
                        case TAC_GE: fprintf(yyout, "jl %s\n", tac->target->key); break;
                        case TAC_LE: fprintf(yyout, "jg %s\n", tac->target->key); break;
                        case TAC_EQ: fprintf(yyout, "jne %s\n", tac->target->key); break;
                        case TAC_NE: fprintf(yyout, "je %s\n", tac->target->key); break;
                        case TAC_AND:
                            fprintf(yyout, "je %s\n", tac->target->key);
                            fprintf(yyout, "testl %%edx, %%edx\nje %s\n", tac->target->key);
                            break;
                        case TAC_OR: break;
                    }
                } else {
                    switch (cur_op) {
                        case TAC_GT: fprintf(yyout, "jg %s\n", tac->target->key); break;
                        case TAC_LT: fprintf(yyout, "jl %s\n", tac->target->key); break;
                        case TAC_GE: fprintf(yyout, "jge %s\n", tac->target->key); break;
                        case TAC_LE: fprintf(yyout, "jle %s\n", tac->target->key); break;
                        case TAC_EQ: fprintf(yyout, "je %s\n", tac->target->key); break;
                        case TAC_NE: fprintf(yyout, "jne %s\n", tac->target->key); break;
                        case TAC_AND:
                            fprintf(yyout, "je %s\n", tac->target->key);
                            fprintf(yyout, "testl %%edx, %%edx\nje %s\n", tac->target->key);
                            break;
                        case TAC_OR: break;
                    }
                }
                break;
            default: break;
        }
        tac = tac->next;
    }
}
