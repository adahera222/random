#include "tac.h"
#include <string.h>
#include <ctype.h>

FILE *yyout;

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

char *getValue(char functions[][200][50], char fun[], char key[], int n) {
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(functions[i][0], fun) == 0) {
            for (j = 1; j < 50; j++) {
                if (strcmp(functions[i][j], key) == 0) { 
                    int p = 8+(j-1)*4;
                    char *str = malloc(50*sizeof(char));
                    sprintf(str, "%d", p);
                    strcat(str, "(%ebp)");
                    return str; 
                }
            }
        }
    }
    char *str2 = malloc(50*sizeof(char));
    strcpy(str2, "_");
    strcat(str2, key);
    return str2;
}

void generateASM(TAC *list) {
    printf("\n\n");
    // Go over list once to find all literals, outputs and label them
    int n_output = 0;
    TAC *lit = list;
    char symbols[200][50];
    int n_symbols = 0;
    while (lit) {
        switch (lit->type) {
            case TAC_SYMBOL_LIT: 
                if (!contains(symbols, lit->target->key, n_symbols)) {
                    fprintf(yyout, ".data\n_%s: .long %s\n", lit->target->key, lit->target->key); 
                    strcpy(symbols[n_symbols], lit->target->key); 
                    n_symbols++;
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
                        }
                    }
                }
                break;
            case TAC_OUTPUT:
                fprintf(yyout, "LC%d: .ascii \"%%d\\12\\0\"\n", n_output); 
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
    char functions[200][200][50];
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
        for (j = 0; j < 10; j++) {
            if (strcmp(functions[i][j], "000") != 0) fprintf(stderr, "%s\n", functions[i][j]);
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
    while (tac) {
        switch(tac->type)
        {
            case TAC_SYMBOL: break;
            case TAC_SYMBOL_LIT: break;
            case TAC_VAR: 
                fprintf(yyout, ".data\n_%s: .long %s\n", tac->target->key, tac->op1->key);
                break;
            case TAC_VET:
                fprintf(yyout, ".data\n.comm _%s, %d\n", tac->target->key, atoi(tac->op1->key)*4);
                break;
            case TAC_SUM: 
                fprintf(yyout, "movl %s, %%edx\nmovl %s, %%eax\naddl %%eax, %%edx\nmovl %%edx, %s\n", 
                        getValue(functions, cur_fun, tac->op1->key, n_functions), getValue(functions, cur_fun, tac->op2->key, n_functions), getValue(functions, cur_fun, tac->target->key, n_functions));
                break;
            case TAC_SUB: 
                fprintf(yyout, "movl %s, %%edx\nmovl %s, %%eax\nsubl %%eax, %%edx\nmovl %%edx, %s\n", 
                        getValue(functions, cur_fun, tac->op1->key, n_functions), getValue(functions, cur_fun, tac->op2->key, n_functions), getValue(functions, cur_fun, tac->target->key, n_functions));
                break;
            case TAC_MUL:
                fprintf(yyout, "movl %s, %%edx\nmovl %s, %%eax\nimull %%eax, %%edx\nmovl %%edx, %s\n", 
                        getValue(functions, cur_fun, tac->op1->key, n_functions), getValue(functions, cur_fun, tac->op2->key, n_functions), getValue(functions, cur_fun, tac->target->key, n_functions));
                break;
            case TAC_DIV: 
                fprintf(yyout, "movl _%s, %%edx\nmovl _%s, %%eax\nmovl %%eax, 28(%%esp)\ncltd\nidivl 28(%%esp)\nmovl %%edx, _%s\n", tac->op1->key, tac->op2->key, tac->target->key);
                break;
            case TAC_BEGINFUN: 
                if (strcmp(tac->target->key, "main")) {
                    fprintf(yyout, ".text\n.def _%s; .scl 2; .type 32; .endef\n_%s:\npushl %%ebp\nmovl %%esp, %%ebp\n", tac->target->key, tac->target->key);
                } else {
                    fprintf(yyout, ".def ___main; .scl 2; .type 32; .endef\n.section .rdata,\"dr\"\n.text\n.def _main; .scl 2; .type 32; .endef\n_main:\npushl %%ebp\nmovl %%esp, %%ebp\nandl $-16, %%esp\nsubl $%d, %%esp\ncall ___main\n", 8+max_params*4);
                }
                strcpy(cur_fun, tac->target->key);
                break;
                
            case TAC_ENDFUN: 
                if (strcmp(tac->target->key, "main")) {
                    fprintf(yyout, "popl %%ebp\nret\n");
                } else {
                    fprintf(yyout, "leave\nret\n");
                }
                break;
            case TAC_PARAM: 
                if (tac->target) {
                    fprintf(yyout, "movl _%s, %%eax\nmovl %%eax, %d(%%esp)\n", tac->target->key, cur_param*4); 
                    cur_param++;
                }
                break;
            case TAC_COPY: printf("TAC_COPY");break;
            case TAC_EQ: 
                fprintf(yyout, "movl %s, %%eax\nmovl %s, %%edx\ncmpl %%eax, %%edx\n", 
                        getValue(functions, cur_fun, tac->op1->key, n_functions), getValue(functions, cur_fun, tac->op2->key, n_functions));
                cur_op = TAC_EQ;
                break;
            case TAC_NE:
                fprintf(yyout, "movl %s, %%eax\nmovl %s, %%edx\ncmpl %%eax, %%edx\n", 
                        getValue(functions, cur_fun, tac->op1->key, n_functions), getValue(functions, cur_fun, tac->op2->key, n_functions));
                cur_op = TAC_NE;
                break;
            case TAC_GE: 
                fprintf(yyout, "movl %s, %%eax\nmovl %s, %%edx\ncmpl %%eax, %%edx\n", 
                        getValue(functions, cur_fun, tac->op1->key, n_functions), getValue(functions, cur_fun, tac->op2->key, n_functions));
                cur_op = TAC_GE;
                break;
            case TAC_LE: 
                fprintf(yyout, "movl %s, %%eax\nmovl %s, %%edx\ncmpl %%eax, %%edx\n", 
                        getValue(functions, cur_fun, tac->op1->key, n_functions), getValue(functions, cur_fun, tac->op2->key, n_functions));
                cur_op = TAC_LE;
                break;
            case TAC_GT: 
                fprintf(yyout, "movl %s, %%eax\nmovl %s, %%edx\ncmpl %%eax, %%edx\n", 
                        getValue(functions, cur_fun, tac->op1->key, n_functions), getValue(functions, cur_fun, tac->op2->key, n_functions));
                cur_op = TAC_GT;
                break;
            case TAC_LT: 
                fprintf(yyout, "movl %s, %%eax\nmovl %s, %%edx\ncmpl %%eax, %%edx\n", 
                        getValue(functions, cur_fun, tac->op1->key, n_functions), getValue(functions, cur_fun, tac->op2->key, n_functions));
                cur_op = TAC_LT;
                break;
            case TAC_IF: break;
            case TAC_OUTPUT: 
                fprintf(yyout, "movl %s, %%eax\nmovl %%eax, 4(%%esp)\nmovl $LC%d, (%%esp)\ncall _printf\n", getValue(functions, cur_fun, tac->target->key, n_functions), n_output);
                n_output++;
                break;
            case TAC_INPUT: printf("TAC_INPUT");break;
            case TAC_RETURN: 
                fprintf(yyout, "movl %s, %%eax\n", getValue(functions, cur_fun, tac->target->key, n_functions));
                break;
            case TAC_AND: 
                fprintf(yyout, "movl %s, %%eax\nmovl %s, %%edx\ntestl %%eax, %%eax\n", 
                        getValue(functions, cur_fun, tac->op1->key, n_functions), getValue(functions, cur_fun, tac->op2->key, n_functions));
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
                        getValue(functions, cur_fun, tac->op1->key, n_functions), atoi(tac->op2->key)*4, getValue(functions, cur_fun, tac->target->key, n_functions));
                break;
            case TAC_ATR_VET:
                fprintf(yyout, "movl %s, %%eax\nmovl %%eax, %s+%d\n", 
                        getValue(functions, cur_fun, tac->op2->key, n_functions), getValue(functions, cur_fun, tac->target->key, n_functions), atoi(tac->op1->key)*4);
                break;
            case TAC_FUN_CALL: 
                fprintf(yyout, "call _%s\nmovl %%eax, %s\n", tac->op1->key, getValue(functions, cur_fun, tac->target->key, n_functions));
                break;
            case TAC_FUN_CALL_PARAM:
                fprintf(yyout, "call _%s\nmovl %%eax, %s\n", tac->op1->key, getValue(functions, cur_fun, tac->target->key, n_functions));
                cur_param = 0;
                break;
            case TAC_LOOP: break;
            case TAC_MOV: 
                fprintf(yyout, "movl %s, %%eax\nmovl %%eax, %s\n", 
                        getValue(functions, cur_fun, tac->op1->key, n_functions), getValue(functions, cur_fun, tac->target->key, n_functions));
                break;
            case TAC_JZ: 
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
                break;
            default: break;
        }
        tac = tac->next;
    }
}
