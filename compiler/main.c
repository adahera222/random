// Felipe Gonzalez, Renan Drabach

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) exit(1);   
    yyin = fopen(argv[1], "r");
    initMe();
    int token = yylex();
    while (running) {
        printf("%d: %d %s\n", getLineNumber(), token, yytext); 
        token = yylex();
    }
    hashPrint();
    return 0;
}
