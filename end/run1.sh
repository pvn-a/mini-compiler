#echo "ABSTRACT SYNTAX TREE"
#lex -w tokens.l
#yacc -y -d parse.y 
#gcc lex.yy.c y.tab.c -Wall -w
#./a.out < test.cpp
#echo "\n\n\n\n\n"

if [ ! "$1" ]; then
  echo "Usage: `basename $0` <input .cpp filename>"
  exit 0
fi

echo "Intermediate and Quadruple generation"
lex -w icg_quad.l
yacc -y -d icg_quad.y -Wnone
gcc y.tab.c -ll -w
./a.out $1

echo "\n\n\n\n\n"
echo "Code Optimisations"
python3 codeopt.py inp.txt