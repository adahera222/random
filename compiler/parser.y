%{
    
/* Felipe Gonzalez, Renan Drabach */

#include <stdio.h>
#include <stdlib.h>
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

%token TK_IDENTIFIER 280
%token LIT_INTEGER   281
%token LIT_FALSE     283
%token LIT_TRUE      284
%token LIT_CHAR      285
%token LIT_STRING    286

%token TOKEN_ERROR   290


/* exemplo de aula... */
%union {
    int number;
    struct hash_node* node;
}
/* pra fazer coisas desse tipo... */
/*%token <number>LIT_INTEGER; */
/*%token <node>IDENTIFIER */

/*vardec: : KW_INT IDENTIFIER '=' LIT_INTEGER {fprintf(stderr,"Var %s recebe %d \n", $2->text, $4)}
 */
/*campo do hash_node*/

%%

PROG: LIST_DEC
        ;

LIST_DEC: DEC LIST_DEC
        |
        ;

DEC: DEC_VAR ';'
    | DEC_VET ';'
    | DEC_FUN
    ;

DEC_VAR: TYPE TK_IDENTIFIER ':' LIT
        | TYPE '$' TK_IDENTIFIER ':' LIT
        ;

TYPE: KW_WORD
    | KW_BYTE
    | KW_BOOL
    ;

LIT: LIT_INTEGER
    | LIT_FALSE
    | LIT_TRUE
    | LIT_CHAR
    | LIT_STRING
    ;

DEC_VET: TYPE TK_IDENTIFIER '[' LIT_INTEGER ']'
        | TYPE TK_IDENTIFIER '[' LIT_INTEGER ']' ':' LIST_VAL
        ;

LIST_VAL: LIT LIST_VAL
        |
        ;

DEC_FUN: TYPE TK_IDENTIFIER '(' LIST_DEC_PARAM ')' LIST_DEC_LOC COMMAND
        ;

LIST_DEC_LOC: DEC_VAR ';' LIST_DEC_LOC
            |
            ;

/* quebra em duas partes para questao de nao poder ter virgula no ultimo */
LIST_DEC_PARAM: LIST_DEC_PARAM_SEP DEC_PARAM
                |
                ;

LIST_DEC_PARAM_SEP: LIST_DEC_PARAM ','
                    |
                    ;

DEC_PARAM: TYPE TK_IDENTIFIER
            ;

COMMAND: BLOCO
        | IF
        | LOOP
        | TK_IDENTIFIER '=' EXP
        | KW_INPUT EXP
        | KW_OUTPUT LIST_PARAM
        | KW_RETURN EXP
        | KW_RETURN
        | TK_IDENTIFIER '(' LIST_PARAM ')'
        | TK_IDENTIFIER '(' ')'
        |
        ;

BLOCO: '{' LIST_COM '}'
        ;

/* quebra em duas partes para questao de nao poder ter virgula no ultimo */
LIST_COM: LIST_COM_SEP COMMAND
        ;

LIST_COM_SEP: LIST_COM ';'
            |
            ;

/* comando pode ser vazio, entao vai aceitar isso aqui (then <nada>)... */
IF: KW_IF '(' EXP ')' KW_THEN COMMAND
    | KW_IF '(' EXP ')' KW_THEN COMMAND KW_ELSE COMMAND
    ;

/* comando pode ser vazio, entao vai aceitar isso aqui... (?) */
LOOP: KW_LOOP '(' EXP ')' COMMAND
    ;

/* 2f seria float (?) */
EXP: TK_IDENTIFIER
    | '&' TK_IDENTIFIER
    | '*' TK_IDENTIFIER
    | LIT
    | EXP OP EXP
    | '(' EXP ')'
    | FUN
    ;

FUN: TK_IDENTIFIER '(' LIST_PARAM ')'
    | TK_IDENTIFIER '(' ')'
    ;

/* quebra em duas partes para questao de nao poder ter virgula no ultimo */
LIST_PARAM: LIST_PARAM_SEP EXP
            ;

LIST_PARAM_SEP: LIST_PARAM ','
                |
                ;

OP: '*'
    | '/'
    | '+'
    | '-'
    | '<'
    | '>'
    | '!'
    | OPERATOR_LE
    | OPERATOR_GE
    | OPERATOR_EQ
    | OPERATOR_AND
    | OPERATOR_OR
    ;

%%

void yyerror(char *s) {
	fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", getLineNumber(), s);
	exit(3);
}