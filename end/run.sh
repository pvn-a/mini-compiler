#echo "ABSTRACT SYNTAX TREE"
#lex -w tokens.l
#yacc -y -d parse.y 
#gcc lex.yy.c y.tab.c -Wall -w
#./a.out < test.cpp
#echo "\n\n\n\n\n"


echo "Intermediate and Quadruple generation"
lex -w icg_quad.l
yacc -y -d icg_quad.y -Wnone
./a.out test.cpp

echo "\n\n\n\n\n"
echo "Code Optimisations"
python3 codeopt.py inp.txt