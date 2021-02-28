
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE char *




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
// int count = 0;
extern node symTable[1000];


extern int yylineno;
int valid=1;
int yylex();
int yyerror(const char *s);
extern int SymTable[100];
extern char tdType[50];
extern int t_scope;
extern int dflag;
extern int count;
extern void displaySymTable();
extern int find(int  t_scope, char *yytext);
extern void update(char* name, int value, int scope);
extern int insert(int* idx, int scope, char* dtype, char* val, int line_num);
extern void decrScope();
extern void incrScope();

%}

%define parse.error verbose
%token ID CLASS NUM T_lt T_gt COMMA STRC TERMINATOR RETURN FLT T_lteq T_gteq T_neq T_eqeq T_pl T_min T_mul T_div T_and T_or T_incr T_decr T_not T_eq WHILE INT CHAR FLOAT VOID H MAINTOK INCLUDE BREAK  CONTINUE IF ELSE COUT STRING FOR OB CB OBR CBR ENDL CHARACTER str_ins str_extr CIN 
%left T_pl T_min
%left T_mul T_div 

%%
S
      : START {printf("Successful parsing.\n");displaySymTable();exit(0);}
    |error { yyerrok; yyclearin;}
      ;

START
    : INCLUDE T_lt H T_gt CLASS_DEC FunctionDeclaration MAIN
    | INCLUDE '\"' H '\"' MAIN
    ;



FunctionDeclaration : TYPE ID  OB CB TERMINATOR Function 
       | TYPE ID  OB ParamsType CB TERMINATOR Function
       | MAIN
       |        
       ;

Function : TYPE ID OB CB BODY 
   | TYPE ID OB FunctionParams CB BODY {t_scope++;}
   |
   ;


ParamsType : ParamsType COMMA TYPE  
     | TYPE   
     ;

FunctionParams : FunctionParams COMMA TYPE ID
         | TYPE ID
         ;






CLASS_DEC
  : CLASS ID LOOPBODY TERMINATOR
  |
  ;
  


MAIN
      : VOID MAINTOK BODY
      | INT MAINTOK BODY
      ;

BODY
      : OBR C CBR
      ;


C
      : C statement TERMINATOR
      | C LOOPS
      | statement TERMINATOR
      | LOOPS
      | C OBR C CBR
      | OBR CBR
      | error TERMINATOR
      ;

LOOPS
      : WHILE OB COND CB LOOPBODY
      | FOR OB ASSIGN_EXPR TERMINATOR COND TERMINATOR statement CB LOOPBODY
      | IF OB COND CB LOOPBODY
      | IF OB COND CB LOOPBODY ELSE LOOPBODY
      | CLASS ID LOOPBODY TERMINATOR
      ;


LOOPBODY
    : OBR C CBR
    | TERMINATOR
    | statement TERMINATOR
    | OBR CBR
    ;

statement
      : ASSIGN_EXPR
      | ARITH_EXPR
      | TERNARY_EXPR
      | INPUT
      | PRINT
      | RETURN ASSIGN_EXPR
      | RETURN ARITH_EXPR
        
      ;


COND
      : LIT RELOP LIT
      | LIT
      | LIT RELOP LIT bin_boolop LIT RELOP LIT
      | un_boolop OB LIT RELOP LIT CB
      | un_boolop LIT RELOP LIT
      | LIT bin_boolop LIT
      | un_boolop OB LIT CB
      | un_boolop LIT
      ;


ASSIGN_EXPR
      : ID T_eq ARITH_EXPR {
      ;
        if (find(t_scope, $1) == -1) {
          yyerror("variable not declared");
        }
      update($1, $3, t_scope);
    }

      | TYPE ID T_eq ARITH_EXPR {
        if(!insert(&count, t_scope, $1, $2, yylineno))
              yyerror("Variable redeclared");

        update($2, $4, t_scope);
      }

    |
      TYPE ID {

        if(!insert(&count, t_scope, $1, $2, yylineno))
              yyerror("Variable redeclared");
      }

      | TYPE ID COMMA X {
        strcpy(tdType, $1);
        dflag = 1;

        if(!insert(&count, t_scope, $1, $2, yylineno))
              yyerror("Variable redeclared");
            }
      |
      TYPE ID T_eq ARITH_EXPR COMMA X {
        strcpy(tdType, $1);
        dflag = 1;
        if(!insert(&count, t_scope, $1, $2, yylineno))
              yyerror("Variable redeclared");
        update($2, atoi($4), t_scope);
      }
      ;

X : ID COMMA X {
  if(!insert(&count, t_scope, tdType, $1, yylineno)){
    printf("redeclared: %s\n", $1);
    yyerror("Variable redeclared");
  }
}
  |
  ID {
    if(!insert(&count, t_scope, tdType, $1, yylineno)){
      printf("redeclared: %s\n", $1);
      yyerror("Variable redeclared");
    }
  }
  | ID T_eq ARITH_EXPR COMMA X {
    if(!insert(&count, t_scope, tdType, $1, yylineno)){
      printf("redeclared: %s\n", $1);
      yyerror("Variable redeclared");
    }
    update($1, atoi($3), t_scope);
  }
  | ID T_eq ARITH_EXPR {
    if(!insert(&count, t_scope, tdType, $1, yylineno)){
      printf("redeclared: %s\n", $1);
      yyerror("Variable redeclared");
    }
    update($1, atoi($3), t_scope);
  }

ARITH_EXPR
      : LIT{
            int val;
            if(atoi($1)){
                  val = atoi($1);
            }
            else{
                  int idx = find(t_scope, $1);
                  val = symTable[idx].value;
                  
            } 
            $$ = val;
          
      }
      | ARITH_NEW {$$ = $1;}
      | LIT bin_boolop ARITH_EXPR
      | LIT un_arop{
            int val;
            if(atoi($1)){
                  yyerror("needs an lvalue");
            }
            else{
                  int idx = find(t_scope, $1);
                  val = symTable[idx].value;
                  update($1, val+1, t_scope);                  
            } 
            $$ = val;
            
      }
      | un_arop ARITH_EXPR{
            int val;
            if(atoi($2)){
                  yyerror("needs an lvalue");
            }
            else{
                  int idx = find(t_scope, $2);
                  val = symTable[idx].value + 1;
                  update($2, val+1, t_scope);                  
            } 
            $$ = val;
      }
      | un_boolop ARITH_EXPR
      ;

ARITH_NEW:
      LIT{
            int val;
            if(atoi($1)){
                  val = atoi($1);
            }
            else{
                  int idx = find(t_scope, $1);
                  val = symTable[idx].value;
                  
            } 
            $$ = val; 
      }
      | ARITH_EXPR T_pl ARITH_EXPR{
            $$ = (int)$1 + (int)$3;
      }
      | ARITH_EXPR T_min ARITH_EXPR{
            $$ = (int)$1 - (int)$3;
      }
      | ARITH_EXPR T_mul ARITH_EXPR{
            $$ = (int)$1 * (int)$3;
      }
      | ARITH_EXPR T_div ARITH_EXPR{
            $$ = (int)$1 / (int)$3;
      }
      ;

TERNARY_EXPR
      : OB COND CB '?' statement ':' statement
      ;


INPUT
      : CIN str_extr ID
      | CIN str_extr ID str_extr ID
      | CIN str_extr ID str_extr ID str_extr ID
      ;


PRINT
      : COUT str_ins STRING
      | COUT str_ins STRING str_ins ENDL
      | COUT str_ins ENDL
      | COUT str_ins ID
      | COUT str_ins STRING str_ins ID

      ;
LIT
      : ID {
        if (find(t_scope, $1) == -1) {
            yyerror("variable not declared");
        }
      }
      | NUM
      | FLT
      | CHARACTER 
      ;
TYPE
      : INT
      | CHAR
      | FLOAT 
      ;
RELOP
      : T_lt
      | T_gt
      | T_lteq
      | T_gteq
      | T_neq
      | T_eqeq
      ;


bin_arop
      : T_pl{
            $$ = $1;
      }
      | T_min{
            $$ = $1;
      }
      | T_mul{
            $$ = $1;
      }
      | T_div{
            $$ = $1;
      }
      ;

bin_boolop
      : T_and
      | T_or
      ;

un_arop
      : T_incr{
            $$ = $1;
      }
      | T_decr{
            $$ = $1;
      }
      ;

un_boolop
      : T_not
      ;








%%

#include <ctype.h>
int yyerror(const char *s)
{
    extern int yylineno;
    valid =0;
    printf("\n\nERROR: line number: %d - error: %s\n\n",yylineno,s);

}

int main()
{
  t_scope=1;
  count=0;
  yyparse();
  if(valid)
      printf("Parsing successful\n\n\n");
  else
  {
      printf("Parsing unsuccessful\n\n\n");
  }
  displaySymTable();
  return 0;
}