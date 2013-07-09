etapa5: lex.yy.o main.o hash.o astree.o sem.o tac.o genco.o y.tab.o
		gcc lex.yy.c main.o hash.o astree.o sem.o tac.o genco.o y.tab.c -o etapa5

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

sem.o: sem.c
		gcc -c sem.c

tac.o: tac.c
		gcc -c tac.c

genco.o: genco.c
		gcc -c genco.c

y.tab.c: parser.y
		bison -y -d parser.y

clean:
		rm lex.yy.c etapa5 *.o y.tab.c
