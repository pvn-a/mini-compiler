


%{
	#include<stdio.h>	
	#include <stdlib.h>
    	#include <string.h>
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
    int t_scope = 0;
    int flag = 0;
    int dflag = 0;
    char tdType[50];
    int in_flag=0;
    int f_flag=0;
    int ch_flag=0;
    void insertSymTable(int *index,int scope,char* dtype, char* name, int line_num);
   void displaySymTable(); 
int yyline;
   char* yylval;



%}



alphabet [a-zA-z_]
digit [0-9]


%%


\/\/(.*) {};
\/\*(.*\n)*.*\*\/  {};

\n {yylineno++;}


int {printf("%d\t%s\tTYPE\n", yylineno, yytext); in_flag=1; f_flag=0; dflag = 1; strcpy(tdType, yytext);   yylval = strdup(yytext); }
float {printf("%d\t%s\tTYPE\n", yylineno, yytext); in_flag=0; f_flag=1; dflag = 1; strcpy(tdType, yytext); yylval = strdup(yytext);}





char {printf("%d\t%s\tTYPE\n", yylineno, yytext); dflag = 1; strcpy(tdType, yytext); yylval = strdup(yytext);}
"main()" {printf("%d\t%s\tKEYW\n", yylineno, yytext); dflag = 0;}
for {printf("%d\t%s\tKEYW\n", yylineno, yytext);  flag = 1;}
while {printf("%d\t%s\tKEYW\n", yylineno, yytext); flag = 1;}

return {printf("%d\t%s\tKEYW\n", yylineno, yytext);}

if {printf("%d\t%s\tKEYW\n", yylineno, yytext );
 	}

else {printf("%d\t%s\tKEYW\n", yylineno, yytext);}


cout {printf("%d\t%s\tKEYW\n", yylineno, yytext);}

endl {printf("%d\t%s\tKEYW\n", yylineno, yytext);}

break {printf("%d\t%s\tKEYW\n", yylineno, yytext);}


continue {printf("%d\t%s\tKEYW\n", yylineno, yytext);}





{alphabet}({alphabet}|{digit})* {
                                yylval = strdup(yytext);
                                printf("%d\t%s\tID\n", yylineno, yytext);
		if(in_flag==1)
			insertSymTable(&count,t_scope,"int",yytext,yylineno);
		if(f_flag==1)
			insertSymTable(&count,t_scope,"float",yytext,yylineno);
                               }

"#include"  {printf("%d\t%s\tKEYW\n", yylineno, yytext); dflag = 0; }

{alphabet}({alphabet}|{digit})*"\.h"?  {printf("%d\t%s\tPREPROCESSOR\n", yylineno, yytext);}





\( {printf("%d\t%s\tOPEN BRACKETS\n", yylineno,yytext); }
\) {printf("%d\t%s\tCLOSE BRACKETS\n", yylineno, yytext);}



\{ { t_scope++; if(!flag){
    
		t_scope++;
	}
	printf("%d\t%s\tOPEN BRACES\n", yylineno, yytext); }
\} { t_scope--; printf("%d\t%s\tCLOSE BRACES\n", yylineno, yytext); }


{digit}+ {printf("%d\t%s\tINTEGER\n", yylineno, yytext); yylval = strdup(yytext);}
{digit}+\.{digit}+(E(\+|\-)?{digit}+)? {printf("%d\t%s\tFLOATING POINT NUMBER\n", yylineno, yytext);}

\".*\" {printf("%d\t%s\tSTRING CONSTANT\n", yylineno, yytext); }
"==" {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext);}
"!=" {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext);}
">=" {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); }
"<=" {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); }
"<" {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); }
">" {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); }
\+\+ {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); }
-- {printf("%d\t%s\tUNARY OPERATORS\n", yylineno, yytext); }

\+ {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext); }
\- {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext); }
\/ {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext); }
\* {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); yylval = strdup(yytext); }
&& {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext);}
\|\| {printf("%d\t%s\tRELATIONAL OPERATORS\n", yylineno, yytext); }
! {printf("%d\t%s\tLOGICAL OPERATORS\n", yylineno, yytext); }

= {printf("%d\t%s\tASSIGNMENT\n", yylineno, yytext);}
";" {printf("%d\t%s\tTERMINATOR\n", yylineno, yytext); dflag = 0; flag = 0;}
"," {printf("%d\t%s\tCOMMA\n", yylineno, yytext); }
\t ;

" " ;

\"(\\.|[^"\\])*\" {printf("%d\t%s\tSTRING CONSTANT\n", yylineno, yytext); }


. {printf("%d\t%s\ERROR\n", yylineno, yytext);}





%%



void insertSymTable(int *idx,int scope,char* dtype, char* name, int line_num){
    int present = 0;

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


    }

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


int yywrap()
{
	return 1;
}





	



int main()
{


yyin = fopen("input.c", "r"); 
  
    /* yyout points to the file output.txt 
    and opens it in write mode*/

    yyout = fopen("Output.txt", "w"); 
   
    yylex();	
	displaySymTable();
}





