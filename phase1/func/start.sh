lex -w tokens.l
yacc -y -d parse.y -Wnone
gcc lex.yy.c y.tab.c -Wall
echo "EXEC 6-----------------------------------------------------"
./a.out < input6.cpp
