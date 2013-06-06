etapa4: lex.yy.o main.o hash.o astree.o sem.o y.tab.o
		gcc lex.yy.c main.o hash.o astree.o sem.o y.tab.c -o etapa4

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

y.tab.c: parser.y
		bison -y -d parser.y

clean:
		rm lex.yy.c etapa4 *.o y.tab.c
