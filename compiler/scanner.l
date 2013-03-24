%{
    
#include "tokens.h"

%}

%%

.   ECHO;
\n  ECHO;

%%

#include "main.c"

int running = 1;

void initMe(void) {

}

int yywrap(void) {
    running = 0;
    return 1;
}
