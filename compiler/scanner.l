%{

/* Felipe Gonzalez, Renan Drabach */

#include <stdio.h>
#include "astree.h"
#include "y.tab.h"
#include "scanner.h"

int running = 1;
int line_number = 1;

%}

%x multiLineComment

%%

word        return KW_WORD; 
bool        return KW_BOOL; 
byte        return KW_BYTE; 
if          return KW_IF;
then        return KW_THEN; 
else        return KW_ELSE;
loop        return KW_LOOP;
input       return KW_INPUT;
output      return KW_OUTPUT;
return      return KW_RETURN;
true        yylval.symbol = hashInsert(yytext, SYMBOL_LIT_TRUE); return LIT_TRUE;
TRUE        yylval.symbol = hashInsert(yytext, SYMBOL_LIT_TRUE); return LIT_TRUE;
false       yylval.symbol = hashInsert(yytext, SYMBOL_LIT_FALSE); return LIT_FALSE;
FALSE       yylval.symbol = hashInsert(yytext, SYMBOL_LIT_FALSE); return LIT_FALSE;
[,;:\(\)\[\]{}\+\-\*/<>=!&\$] return yytext[0];
\<=         return OPERATOR_LE;
>=          return OPERATOR_GE;
==          return OPERATOR_EQ;
\!=         return OPERATOR_NE; 
&&          return OPERATOR_AND; 
\|\|        return OPERATOR_OR; 
[_a-zA-Z][_a-zA-Z0-9]*  yylval.symbol = hashInsert(yytext, SYMBOL_IDENTIFIER); return TK_IDENTIFIER;
[0-9][0-9A-Fa-f]*       yylval.symbol = hashInsert(yytext, SYMBOL_LIT_INTEGER); return LIT_INTEGER;
'.'                     yylval.symbol = hashInsert(yytext, SYMBOL_LIT_CHAR); return LIT_CHAR;
\"([^\"]|\\.)*\"        yylval.symbol = hashInsert(yytext, SYMBOL_LIT_STRING); return LIT_STRING;
\/\/.*\n                ++line_number;
\/\*                        BEGIN(multiLineComment);
<multiLineComment>\*\/      BEGIN(INITIAL);
<multiLineComment>\n        ++line_number;
<multiLineComment>. 
[\n\r]                          ++line_number;
\ 
\t
. printf("Lexical error on line %d: %s\n", line_number, yytext); return TOKEN_ERROR;

%%

void initMe(void) {
    hashInit();
}

//#include "main.c"

int getLineNumber(void) {
    return line_number;
}

int yywrap(void) {
    running = 0;
    return 1;
}
