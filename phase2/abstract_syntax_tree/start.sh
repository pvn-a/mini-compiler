lex -w tokens.l
yacc -y -d parse.y 
gcc lex.yy.c y.tab.c -Wall
./a.out < test.c
