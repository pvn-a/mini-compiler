%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define YYSTYPE char*
    extern YYSTYPE yylval;

    #include "y.tab.h"

%}



alphabet [a-zA-z_]
digit [0-9]

%%

\/\/(.*) {};
\/\*(.*\n)*.*\*\/  {};

\n {yylineno++;}

int {  yylval = strdup(yytext); return INT;}
float { yylval = strdup(yytext); return FLOAT;}
char { yylval = strdup(yytext); return CHAR;}
"main()" {  return MAINTOK;}
for {  return FOR;}
while {  return WHILE;}

return { return RETURN;}
if { return IF;}
else { return ELSE;}


cout {yylval = strdup(yytext); return COUT;}
endl { return ENDL;}
break { return BREAK;}
continue { return CONTINUE;}

{alphabet}({alphabet}|{digit})* {

                                yylval = strdup(yytext);
                                return ID;}

"#include"  {return INCLUDE;}

{alphabet}({alphabet}|{digit})*"\.h"?  { return H;}





\( { return OB;}
\) { return CB;}




\{ { return OBR;}
\} {  return CBR;}




{digit}+ {yylval = strdup(yytext); return NUM;}
{digit}+\.{digit}+(E(\+|\-)?{digit}+)? {return FLT;}

\".*\" {  yylval = strdup(yytext); return STRING;}
"==" { yylval = strdup(yytext); return T_eqeq;}
"!=" { yylval = strdup(yytext);  return T_neq;}
">=" {  yylval = strdup(yytext); return T_gteq;}
"<=" { yylval = strdup(yytext);  return T_lteq;}
"<" { yylval = strdup(yytext);  return T_lt;}
">" {  yylval = strdup(yytext); return T_gt;}
\+\+ { yylval = strdup(yytext);  return T_incr;}
-- { yylval = strdup(yytext);  return T_decr;}

\+ { yylval = strdup(yytext); return T_pl;}
\- { yylval = strdup(yytext);  return T_min;}
\/ { yylval = strdup(yytext);  return T_div;}
\* { yylval = strdup(yytext); return T_mul;}
&& { yylval = strdup(yytext); return T_and;}
\|\| { yylval = strdup(yytext); return T_or;}
! { yylval = strdup(yytext);  return T_not;}

= { yylval = strdup(yytext);  return T_eq;}
\*= { yylval = strdup(yytext);  return S_mul;}
\+= { yylval = strdup(yytext);  return S_add;}
-= { yylval = strdup(yytext);  return S_min;}
\/= { yylval = strdup(yytext);  return S_div;}
";" { yylval = strdup(yytext); return TERMINATOR;}
"," {  yylval = strdup(yytext); return COMMA;}
\t ;

" " ;

\"(\\.|[^"\\])*\" { yylval = strdup(yytext); return STRING;}


. {printf("%d\t%s\ERROR\n", yylineno, yytext);}


%%

int yywrap(){
    return 1;
}
