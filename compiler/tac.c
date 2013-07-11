#include "tac.h"
#include <string.h>

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
		case TAC_LOOP: printf("TAC_LOOP");break;
        case TAC_MOV: printf("TAC_MOV");break;
        case TAC_JZ: printf("TAC_JZ");break;
        case TAC_JJ: printf("TAC_JJ");break;
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

    // Go over list again with all literals set
    TAC *tac = list;
    n_output = 0;
    int cur_op = 0;
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
                fprintf(yyout, "movl _%s, %%edx\nmovl _%s, %%eax\naddl %%eax, %%edx\nmovl %%edx, _%s\n", tac->op1->key, tac->op2->key, tac->target->key);
                break;
            case TAC_SUB: 
                fprintf(yyout, "movl _%s, %%edx\nmovl _%s, %%eax\nsubl %%eax, %%edx\nmovl %%edx, _%s\n", tac->op1->key, tac->op2->key, tac->target->key);
                break;
            case TAC_MUL:
                fprintf(yyout, "movl _%s, %%edx\nmovl _%s, %%eax\nimull %%eax, %%edx\nmovl %%edx, _%s\n", tac->op1->key, tac->op2->key, tac->target->key);
                break;
            case TAC_DIV: 
                fprintf(yyout, "movl _%s, %%edx\nmovl _%s, %%eax\nmovl %%eax, 28(%%esp)\ncltd\nidivl 28(%%esp)\nmovl %%edx, _%s\n", tac->op1->key, tac->op2->key, tac->target->key);
                break;
            case TAC_BEGINFUN: 
                if (strcmp(tac->target->key, "main")) {
                    fprintf(yyout, ".text\n.def _%s; .scl 2; .type 32; .endef\n_%s:\npushl %%ebp\nmovl %%esp, %%ebp\n", tac->target->key, tac->target->key);
                } else {
                    fprintf(yyout, ".def ___main; .scl 2; .type 32; .endef\n.section .rdata,\"dr\"\n.text\n.def _main; .scl 2; .type 32; .endef\n_main:\npushl %%ebp\nmovl %%esp, %%ebp\nandl $-16, %%esp\nsubl $16, %%esp\ncall ___main\n");
                }
                break;
                
            case TAC_ENDFUN: 
                if (strcmp(tac->target->key, "main")) {
                    fprintf(yyout, "popl %%ebp\nret\n");
                } else {
                    fprintf(yyout, "leave\nret\n");
                }
                break;
            case TAC_COPY: printf("TAC_COPY");break;
            case TAC_EQ: 
                fprintf(yyout, "movl _%s, %%eax\nmovl _%s, %%edx\ncmpl %%eax, %%edx\n", tac->op1->key, tac->op2->key);
                cur_op = TAC_EQ;
                break;
            case TAC_NE:
                fprintf(yyout, "movl _%s, %%eax\nmovl _%s, %%edx\ncmpl %%eax, %%edx\n", tac->op1->key, tac->op2->key);
                cur_op = TAC_NE;
                break;
            case TAC_GE: 
                fprintf(yyout, "movl _%s, %%eax\nmovl _%s, %%edx\ncmpl %%eax, %%edx\n", tac->op1->key, tac->op2->key);
                cur_op = TAC_GE;
                break;
            case TAC_LE: 
                fprintf(yyout, "movl _%s, %%eax\nmovl _%s, %%edx\ncmpl %%eax, %%edx\n", tac->op1->key, tac->op2->key);
                cur_op = TAC_LE;
                break;
            case TAC_GT: 
                fprintf(yyout, "movl _%s, %%eax\nmovl _%s, %%edx\ncmpl %%eax, %%edx\n", tac->op1->key, tac->op2->key);
                cur_op = TAC_GT;
                break;
            case TAC_LT: 
                fprintf(yyout, "movl _%s, %%eax\nmovl _%s, %%edx\ncmpl %%eax, %%edx\n", tac->op1->key, tac->op2->key);
                cur_op = TAC_LT;
                break;
            case TAC_IF: break;
            case TAC_OUTPUT: 
                fprintf(yyout, "movl _%s, %%eax\nmovl %%eax, 4(%%esp)\nmovl $LC%d, (%%esp)\ncall _printf\n", tac->target->key, n_output);
                n_output++;
                break;
            case TAC_INPUT: printf("TAC_INPUT");break;
            case TAC_RETURN: 
                fprintf(yyout, "movl _%s, %%eax\n", tac->target->key);            
                break;
            case TAC_AND: 
                fprintf(yyout, "movl _%s, %%eax\nmovl _%s, %%edx\ntestl %%eax, %%eax\n", tac->op1->key, tac->op2->key);
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
                fprintf(yyout, "movl _%s+%d, %%eax\nmovl %%eax, _%s\n", tac->op1->key, atoi(tac->op2->key)*4, tac->target->key);
                break;
            case TAC_ATR_VET:
                fprintf(yyout, "movl _%s, %%eax\nmovl %%eax, _%s+%d\n", tac->op2->key, tac->target->key, atoi(tac->op1->key)*4);
                break;
            case TAC_FUN_CALL: 
                fprintf(yyout, "call _%s\nmovl %%eax, _%s\n", tac->op1->key, tac->target->key);
                break;
            case TAC_LOOP: break;
            case TAC_MOV: 
                fprintf(yyout, "movl _%s, %%eax\nmovl %%eax, _%s\n", tac->op1->key, tac->target->key);
                break;
            case TAC_JJ:
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
