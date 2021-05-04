#!/bin/bash
lex -w icg_quad.l
yacc icg_quad.y -Wnone
gcc y.tab.c -ll -w
cat input.c
./a.out
