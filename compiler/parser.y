%{
    
/* Felipe Gonzalez, Renan Drabach */

#include <stdio.h>
#include <stdlib.h>
/*#include "astree.h"*/
#include "tac.h"
int yylex(void);
void yyerror(char *);

%}

%token KW_WORD       256
%token KW_BOOL       258
%token KW_BYTE       259
%token KW_IF         261
%token KW_THEN       262
%token KW_ELSE       263
%token KW_LOOP       264
%token KW_INPUT      266
%token KW_RETURN     267
%token KW_OUTPUT     268

%token OPERATOR_LE   270
%token OPERATOR_GE   271
%token OPERATOR_EQ   272
%token OPERATOR_NE   273
%token OPERATOR_AND  274
%token OPERATOR_OR   275

%token<symbol> TK_IDENTIFIER 280
%token<symbol> LIT_INTEGER   281
%token<symbol> LIT_FALSE     283
%token<symbol> LIT_TRUE      284
%token<symbol> LIT_CHAR      285
%token<symbol> LIT_STRING    286

%token TOKEN_ERROR   290

%left OPERATOR_OR OPERATOR_AND
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE
%left '+' '-'
%left '*' '/'

%union {
    HASH_NODE *symbol;
    AST *astree;
}

%type<astree> PROG LIST_DEC DEC DEC_VAR DEC_VET DEC_FUN TYPE LIT LIST_VAL LIST_DEC_LOC
              LIST_DEC_PARAM LIST_DEC_PARAM_SEP DEC_PARAM COMMAND BLOCO IF LOOP EXP 
              LIST_PARAM LIST_COM DEC_LOC_VAR LIST_PARAM_SEP LIST_COM_SEP

%%

PROG: LIST_DEC { $$ = $1; //astPrintFile($$); 
                            declarations($$); 
                            usage($$); 
                            datatypes($$); 
                            hashPrint(); 
                            astPrint($$,0);
                            generateASM(generateCode($$)); }
    ;

LIST_DEC: DEC LIST_DEC { $$ = astCreate(AST_LIST_DEC, 0, $1, $2, 0, 0); }
        | { $$ = astCreate(0, 0, 0, 0, 0, 0); }
        ;

DEC: DEC_VAR ';' { $$ = astCreate(AST_DEC, 0, $1, 0, 0, 0); }
   | DEC_VET ';' { $$ = astCreate(AST_DEC, 0, $1, 0, 0, 0); }
   | DEC_FUN     { $$ = astCreate(AST_DEC, 0, $1, 0, 0, 0); }
   ;

DEC_VAR: TYPE TK_IDENTIFIER ':' LIT { $$ = astCreate(AST_DEC_VAR, $2, $1, $4, 0, 0); $2->data_type = $1->type; }
       | TYPE '$' TK_IDENTIFIER ':' LIT { $$ = astCreate(AST_DEC_PTR, $3, $1, $5, 0, 0); $3->data_type = $1->type; }
       ;

DEC_LOC_VAR: TYPE TK_IDENTIFIER ':' LIT { $$ = astCreate(AST_DEC_LOC_VAR, $2, $1, $4, 0, 0); $2->data_type = $1->type; }
           | TYPE '$' TK_IDENTIFIER ':' LIT { $$ = astCreate(AST_DEC_LOC_PTR, $3, $1, $5, 0, 0); $3->data_type = $1->type; }

TYPE: KW_WORD { $$ = astCreate(AST_WORD, 0, 0, 0, 0, 0); }
    | KW_BYTE { $$ = astCreate(AST_BYTE, 0, 0, 0, 0, 0); }
    | KW_BOOL { $$ = astCreate(AST_BOOL, 0, 0, 0, 0, 0); }
    ;

LIT: LIT_INTEGER { $$ = astCreate(AST_SYMBOL_LIT, $1, 0, 0, 0, 0); $1->data_type = L_INT; }
   | LIT_FALSE { $$ = astCreate(AST_SYMBOL_LIT, $1, 0, 0, 0, 0); $1->data_type = L_BOOL; }
   | LIT_TRUE { $$ = astCreate(AST_SYMBOL_LIT, $1, 0, 0, 0, 0); $1->data_type = L_BOOL; }
   | LIT_CHAR { $$ = astCreate(AST_SYMBOL_LIT, $1, 0, 0, 0, 0); $1->data_type = L_CHAR; }
   | LIT_STRING { $$ = astCreate(AST_SYMBOL_LIT, $1, 0, 0, 0, 0); $1->data_type = L_STR; }
   ;

DEC_VET: TYPE TK_IDENTIFIER '[' LIT_INTEGER ']' { $$ = astCreate(AST_DEC_VET, $2, $1, astCreate(AST_VET_SIZE, $4, 0, 0, 0, 0), 0, 0); $2->data_type = $1->type; }
       | TYPE TK_IDENTIFIER '[' LIT_INTEGER ']' ':' LIST_VAL { $$ = astCreate(AST_DEC_VET, $2, $1, astCreate(AST_VET_SIZE, $4, 0, 0, 0, 0), $7, 0); $2->data_type = $1->type; }
       ;

LIST_VAL: LIT LIST_VAL { $$ = astCreate(AST_LIST_VAL, 0, $1, $2, 0, 0); }
        | { $$ = astCreate(0, 0, 0, 0, 0, 0); }
        ;

DEC_FUN: TYPE TK_IDENTIFIER '(' LIST_DEC_PARAM ')' LIST_DEC_LOC COMMAND { $$ = astCreate(AST_DEC_FUN, $2, $1, $4, $6, $7); $2->data_type = $1->type; $2->params = $4; }
       ;

/* try to fix 6shift/reduce here later */
LIST_DEC_LOC: DEC_LOC_VAR ';' LIST_DEC_LOC { $$ = astCreate(AST_LIST_DEC_LOC, 0, $1, $3, 0, 0); }
            | { $$ = astCreate(0, 0, 0, 0, 0, 0); }
            ;

LIST_DEC_PARAM: LIST_DEC_PARAM_SEP DEC_PARAM { $$ = astCreate(AST_LIST_DEC_PARAM, 0, $1, $2, 0, 0); }
              | { $$ = astCreate(AST_EMPTY, 0, 0, 0, 0, 0); }
              ;

LIST_DEC_PARAM_SEP: LIST_DEC_PARAM ',' { $$ = astCreate(AST_LIST_DEC_PARAM_SEP, 0, $1, 0, 0, 0); }
                  | { $$ = astCreate(AST_EMPTY, 0, 0, 0, 0, 0); }
                  ;

DEC_PARAM: TYPE TK_IDENTIFIER { $$ = astCreate(AST_DEC_PARAM, $2, $1, 0, 0, 0); $2->data_type = $1->type; }
         ;

COMMAND: BLOCO { $$ = astCreate(AST_COMMAND, 0, $1, 0, 0, 0); }
       | IF { $$ = astCreate(AST_COMMAND, 0, $1, 0, 0, 0); }
       | LOOP { $$ = astCreate(AST_COMMAND, 0, $1, 0, 0, 0); }
       | TK_IDENTIFIER '=' EXP { $$ = astCreate(AST_ATR, $1, $3, 0, 0, 0); }
       | TK_IDENTIFIER '[' EXP ']' '=' EXP { $$ = astCreate(AST_ATR_VET, $1, $3, $6, 0, 0); }
       | KW_INPUT EXP { $$ = astCreate(AST_INPUT, 0, $2, 0, 0, 0); }
       | KW_OUTPUT LIST_PARAM { $$ = astCreate(AST_OUTPUT, 0, $2, 0, 0, 0); }
       | KW_RETURN EXP { $$ = astCreate(AST_RETURN, 0, $2, 0, 0, 0); }
       | KW_RETURN { $$ = astCreate(AST_RETURN, 0, 0, 0, 0, 0); }
       | TK_IDENTIFIER '(' LIST_PARAM ')' { $$ = astCreate(AST_CALL, $1, $3, 0, 0, 0); }
       | TK_IDENTIFIER '(' ')' { $$ = astCreate(AST_CALL_EMPTY, $1, 0, 0, 0, 0); }
       | { $$ = astCreate(0, 0, 0, 0, 0, 0); }
       ;

BLOCO: '{' LIST_COM '}' { $$ = astCreate(AST_BLOCO, 0, $2, 0, 0, 0); }
     ;

/* quebra em duas partes para questao de nao poder ter virgula no ultimo */
LIST_COM: LIST_COM_SEP COMMAND { $$ = astCreate(AST_LIST_COM, 0, $1, $2, 0, 0); }
        ;

LIST_COM_SEP: LIST_COM ';' { $$ = astCreate(AST_LIST_COM_SEP, 0, $1, 0, 0, 0); }
            | { $$ = astCreate(0, 0, 0, 0, 0, 0); }

IF: KW_IF '(' EXP ')' KW_THEN COMMAND { $$ = astCreate(AST_IF, 0, $3, $6, 0, 0); }
  | KW_IF '(' EXP ')' KW_THEN COMMAND KW_ELSE COMMAND { $$ = astCreate(AST_IF, 0, $3, $6, $8, 0); }
  ;

LOOP: KW_LOOP '(' EXP ')' COMMAND { $$ = astCreate(AST_LOOP, 0, $3, $5, 0, 0); }
    ;

EXP: TK_IDENTIFIER { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
   | '&' TK_IDENTIFIER { $$ = astCreate(AST_REF, $2, 0, 0, 0, 0); }
   | '*' TK_IDENTIFIER { $$ = astCreate(AST_DEREF, $2, 0, 0, 0, 0); }
   | TK_IDENTIFIER '[' EXP ']' { $$ = astCreate(AST_VET, $1, $3, 0, 0, 0); }
   | LIT_INTEGER { $$ = astCreate(AST_SYMBOL_LIT, $1, 0, 0, 0, 0); $1->data_type = L_INT; }
   | LIT_FALSE { $$ = astCreate(AST_SYMBOL_LIT, $1, 0, 0, 0, 0); $1->data_type = L_BOOL; }
   | LIT_TRUE { $$ = astCreate(AST_SYMBOL_LIT, $1, 0, 0, 0, 0); $1->data_type = L_BOOL; }
   | LIT_CHAR { $$ = astCreate(AST_SYMBOL_LIT, $1, 0, 0, 0, 0); $1->data_type = L_CHAR; }
   | LIT_STRING { $$ = astCreate(AST_SYMBOL_LIT, $1, 0, 0, 0, 0); $1->data_type = L_STR; }
   | EXP '*' EXP { $$ = astCreate(AST_MUL, 0, $1, $3, 0, 0); }
   | EXP '/' EXP { $$ = astCreate(AST_DIV, 0, $1, $3, 0, 0); }
   | EXP '+' EXP { $$ = astCreate(AST_SUM, 0, $1, $3, 0, 0); }
   | EXP '-' EXP { $$ = astCreate(AST_SUB, 0, $1, $3, 0, 0); }
   | EXP '<' EXP { $$ = astCreate(AST_LT, 0, $1, $3, 0, 0); }
   | EXP '>' EXP { $$ = astCreate(AST_GT, 0, $1, $3, 0, 0); }
   | EXP OPERATOR_LE EXP { $$ = astCreate(AST_LE, 0, $1, $3, 0, 0); }
   | EXP OPERATOR_GE EXP { $$ = astCreate(AST_GE, 0, $1, $3, 0, 0); }
   | EXP OPERATOR_EQ EXP { $$ = astCreate(AST_EQ, 0, $1, $3, 0, 0); }
   | EXP OPERATOR_NE EXP { $$ = astCreate(AST_NE, 0, $1, $3, 0, 0); }
   | EXP OPERATOR_AND EXP { $$ = astCreate(AST_AND, 0, $1, $3, 0, 0); }
   | EXP OPERATOR_OR EXP { $$ = astCreate(AST_OR, 0, $1, $3, 0, 0); }
   | '(' EXP ')' { $$ = astCreate(AST_PAREN, 0, $2, 0, 0, 0); }
   | TK_IDENTIFIER '(' LIST_PARAM ')' { $$ = astCreate(AST_CALL, $1, $3, 0, 0, 0); }
   | TK_IDENTIFIER '(' ')' { $$ = astCreate(AST_CALL_EMPTY, $1, 0, 0, 0, 0); }
   ;

LIST_PARAM: LIST_PARAM_SEP EXP { $$ = astCreate(AST_LIST_PARAM, 0, $1, $2, 0, 0); }
          ;

LIST_PARAM_SEP: LIST_PARAM ',' { $$ = astCreate(AST_LIST_PARAM_SEP, 0, $1, 0, 0, 0); }
              | { $$ = astCreate(AST_EMPTY, 0, 0, 0, 0, 0); }
              ;

%%

void yyerror(char *s) {
	fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", getLineNumber(), s);
	exit(3);
}
