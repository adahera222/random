/* Felipe Gonzalez, Renan Drabach */

#include <stdio.h>
#include "astree.h"
#include "lex.yy.h"
#include "scanner.h"
#include "y.tab.h"

int yyparse(void);

int main(int argc, char *argv[]) {
    
    if (argc < 2) exit(1);   
        yyin = fopen(argv[1], "r");
    
    initMe();
    
    yyparse();
    
    printf("Nenhum erro sintatico.\n");
    return 0;
}
