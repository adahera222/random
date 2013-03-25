%{
    
#include <stdio.h>
#include "tokens.h"

int running = 1;
int line_number = 0;
void initMe(void) {}

%}

%%

word printf("KW_WORD\n");
bool printf("KW_BOOL\n");
byte printf("KW_BYTE\n");
if printf("KW_IF\n");
then printf("KW_THEN\n");
else printf("KW_ELSE\n");
loop printf("KW_LOOP\n");
input printf("KW_INPUT\n");
output printf("KW_OUTPUT\n");
return printf("KW_RETURN\n");
true printf("LIT_TRUE\n");
TRUE printf("LIT_TRUE\n");
false printf("LIT_FALSE\n");
FALSE printf("LIT_FALSE\n");
[,;:\(\)\[\]{}\+\-\*/<>=!&\$] printf("%c\n", yytext[0]);
\<= printf("OPERATOR_LE\n");
>= printf("OPERATOR_GE\n");
== printf("OPERATOR_EQ\n");
\!= printf("OPERATOR_NE\n");
&& printf("OPERATOR_AND\n");
\|\| printf("OPERATOR_OR\n");
[_a-zA-Z][_a-zA-Z0-9]* printf("TK_IDENTIFIER\n");
[0-9][0-9A-Fa-f]* printf("LIT_INTEGER\n");
'.' printf("LIT_CHAR\n");
\"([^\"]|\\.)*\" printf("LIT_STRING\n");
\n ++line_number;
\ 
. printf("TOKEN_ERROR\n");

%%

#include "main.c"

int getLineNumber(void) {
    return line_number;
}


int yywrap(void) {
    running = 0;
    printf("Lines: %d\n", line_number); 
    return 1;
}
