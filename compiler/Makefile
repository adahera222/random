etapa2: lex.yy.o main.o hash.o astree.o y.tab.o
		gcc lex.yy.c main.o hash.o astree.o y.tab.c -o etapa3

lex.yy.c: lex.yy.c
		gcc -c lex.yy.c

lex.yy.o: scanner.l y.tab.o
		flex scanner.l

main.o: main.c
		gcc -c main.c

hash.o: hash.c
		gcc -c hash.c

astree.o: astree.c
		gcc -c astree.c

y.tab.c: parser.y
		bison -y -d parser.y

clean:
		rm lex.yy.c etapa2 *.o y.tab.c
