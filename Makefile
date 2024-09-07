uni: y.tab.c lex.yy.c
	gcc -o uni y.tab.c

y.tab.c y.tab.h: parser.y
	yacc -d parser.y

lex.yy.c: lexer.l
	lex lexer.l
