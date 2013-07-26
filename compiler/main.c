/* Felipe Gonzalez, Renan Drabach */

#include <stdio.h>
#include "astree.h"
#include "lex.yy.h"
#include "scanner.h"
#include "y.tab.h"

int yyparse(void);

int main(int argc, char *argv[]) {
    yyin = fopen(argv[1], "r");

    yyout = fopen(argv[2], "w");
    if (yyout == NULL) perror(argv[2]);

    initMe();
    yyparse();

    fclose(yyin);
    fclose(yyout);
    
    printf("No syntax error.\n");
    return 0;
}
