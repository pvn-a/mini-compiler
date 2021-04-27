%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define YYSTYPE struct astnode*
    extern YYSTYPE yylval;

    #include "y.tab.h"

    typedef struct astnode{
      int isID;
      int scope;
      int entry;
      char *name;
      int numChildren;
      struct astnode** children;
    }astnode;

    typedef struct node{
        int scope;
        int value;
        char name[100];
        char dtype[50];
        int line_num;
        int valid;
    }node;

    typedef struct table{
        node* head;
    }table;

    int count = 0;
    node symTable[1000];
    int t_scope = 1;
    int flag = 0;
    int dflag = 0;
    char tdType[50];

    int insert(int* idx, int scope, char* dtype, char* val, int line_num);
    void displaySymTable();
    int find(int  t_scope, char *name);
    void update(char* name, int value, int scope);
    void incrScope();
    void decrScope();
%}



alphabet [a-zA-z_]
digit [0-9]

%%

\/\/(.*) {};
\/\*(.*\n)*.*\*\/  {};

\n {yylineno++;}

int {printf("%d\t%s\tTYPE\n", yylineno, yytext); dflag = 1; yylval = strdup(yytext); return INT;}
float {printf("%d\t%s\tTYPE\n", yylineno, yytext); dflag = 1; yylval = strdup(yytext); return FLOAT;}
char {printf("%d\t%s\tTYPE\n", yylineno, yytext); dflag = 1; yylval = strdup(yytext); return CHAR;}
"main()" {printf("%d\t%s\tKEYW\n", yylineno, yytext); dflag = 0; return MAINTOK;}
for {printf("%d\t%s\tKEYW\n", yylineno, yytext); flag = 1; t_scope++; incrScope(); return FOR;}
while {printf("%d\t%s\tKEYW\n", yylineno, yytext); flag = 1; t_scope++; incrScope(); return WHILE;}

return {printf("%d\t%s\tKEYW\n", yylineno, yytext); return RETURN;}
if {printf("%d\t%s\tKEYW\n", yylineno, yytext); return IF;}
else {printf("%d\t%s\tKEYW\n", yylineno, yytext); return ELSE;}


cout {printf("%d\t%s\tKEYW\n", yylineno, yytext);yylval = strdup(yytext); return COUT;}
endl {printf("%d\t%s\tKEYW\n", yylineno, yytext); return ENDL;}
break {printf("%d\t%s\tKEYW\n", yylineno, yytext); return BREAK;}
continue {printf("%d\t%s\tKEYW\n", yylineno, yytext); return CONTINUE;}

{alphabet}({alphabet}|{digit})* {
                                printf("%d\t%s\tID\n", yylineno, yytext);
                                yylval = strdup(yytext);
                                return ID;}

"#include"  {printf("%d\t%s\tKEYW\n", yylineno, yytext); dflag = 0; return INCLUDE;}

{alphabet}({alphabet}|{digit})*"\.h"?  {printf("%d\t%s\tPREPROCESSOR\n", yylineno, yytext); return H;}





\( {printf("%d\t%s\tOPEN BRACKETS\n", yylineno,yytext); return OB;}
\) {printf("%d\t%s\tCLOSE BRACKETS\n", yylineno, yytext); return CB;}




\{ {if(!flag){
    incrScope();
		t_scope++;
	}
	printf("%d\t%s\tOPEN BRACES\n", yylineno, yytext); return OBR;}
\} {t_scope--; decrScope(t_scope); printf("%d\t%s\tCLOSE BRACES\n", yylineno, yytext); return CBR;}




{digit}+ {printf("%d\t%s\tINTEGER\n", yylineno, yytext); yylval = strdup(yytext); return NUM;}
{digit}+\.{digit}+(E(\+|\-)?{digit}+)? {printf("%d\t%s\tFLOATING POINT NUMBER\n", yylineno, yytext); return FLT;}

\".*\" {printf("%d\t%s\tSTRING CONSTANT\n", yylineno, yytext);  yylval = strdup(yytext); return STRING;}
"==" {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext); return T_eqeq;}
"!=" {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext);  return T_neq;}
">=" {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext);  yylval = strdup(yytext); return T_gteq;}
"<=" {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext);  return T_lteq;}
"<" {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext);  return T_lt;}
">" {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext);  yylval = strdup(yytext); return T_gt;}
\+\+ {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext);  return T_incr;}
-- {printf("%d\t%s\tUNARY OPERATORS\n", yylineno, yytext); yylval = strdup(yytext);  return T_decr;}


\*= {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext);  return S_mul;}
\+= {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext);  return S_add;}
-= {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext);  return S_min;}
\/= {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext);  return S_div;}
\+ {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext); return T_pl;}
\- {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext);  return T_min;}
\/ {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext);  return T_div;}
\* {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext); return T_mul;}
&& {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext); return T_and;}
\|\| {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext); return T_or;}
! {printf("%d\t%s\tLOGICAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext);  return T_not;}

= {printf("%d\t%s\tASSIGNMENT\n", yylineno, yytext); yylval = strdup(yytext);  return T_eq;}
";" {printf("%d\t%s\tTERMINATOR\n", yylineno, yytext); yylval = strdup(yytext);  dflag = 0; flag = 0; return TERMINATOR;}
"," {printf("%d\t%s\tCOMMA\n", yylineno, yytext);  yylval = strdup(yytext); return COMMA;}
\t ;

" " ;

\"(\\.|[^"\\])*\" {printf("%d\t%s\tSTRING CONSTANT\n", yylineno, yytext); yylval = strdup(yytext); return STRING;}


. {printf("%d\t%s\ERROR\n", yylineno, yytext);}


%%
int insert(int* idx, int scope, char* dtype, char* name, int line_num){
    int present = 0;
    int index = -1;

    for(int i = 0; i < *idx; i++){
            if(!strcmp(symTable[i].name, name) && symTable[i].scope == scope && !symTable[0].valid){
                present = 1;
                break;
            }
    }

    if(!present){
        symTable[*idx].scope = scope;
        symTable[*idx].line_num = line_num;
        symTable[*idx].value = 0;
        strcpy(symTable[*idx].name, name);
        strcpy(symTable[*idx].dtype, dtype);
        symTable[*idx].valid = scope;
        *idx = *idx + 1;

        return *idx - 1;
    }

    return -1;
}

void displaySymTable()
{
        printf("printing symbol table: \n");
        printf("Token\t\tData type\tScope\t\tValue\t\tLine number\n");
        for(int i = 0; i < count; i++)
        {
                printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\n", symTable[i].name, symTable[i].dtype, symTable[i].scope, symTable[i].value, symTable[i].line_num);
        }
}

void update(char* name, int value, int scope){
  /* printf("update %s with %d\n", name, value); */
  for(int i = 0; i < count; i++)
  {
    if(!strcmp(symTable[i].name, name) && symTable[i].scope == scope && symTable[i].valid){
        symTable[i].value = value;
    }
  }
}

int find(int  scope, char *name){

  for(int i = 0; i < count; i++)
  {
    if(!strcmp(symTable[i].name, name) && symTable[i].scope <= scope && symTable[i].valid){
        return i;
    }
  }
    return -1;
}


void incrScope(){
    for(int i = 0; i < count; i++)
    {
      if(symTable[i].valid) symTable[i].valid += 1;
    }
}

void decrScope(){
  for(int i = 0; i < count; i++)
  {
    if(symTable[i].valid != 0)
    {
      symTable[i].valid -= 1;
      if(symTable[i].valid < symTable[i].scope){
          symTable[i].valid = 0;
        }
    }
  }
}

int yywrap(){
    return 1;
}
