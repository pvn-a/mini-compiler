
%{
#include <stdio.h>
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

typedef struct astnode{
  int isID;
  int scope;
  int entry;
  char *name;
  int numChildren;
  struct astnode** children;
}astnode;

#define YYSTYPE struct astnode*
extern YYSTYPE yylval;

int valid = 1;

astnode* addToTree(char *op, astnode *left,astnode *right, astnode** siblings, int lenSiblings);
void setScopeAndPtr(astnode* node, int scope, int ptr);

void printTree(astnode *tree);

int yyerror(const char *s);
extern int yylineno;

extern node symTable[100];
extern char tdType[50];
extern int t_scope;
extern int dflag;
extern int count;
extern void displaySymTable();
extern int find(int  t_scope, char *yytext);
extern void update(char* name, int value, int scope);
extern int insert(int* idx, int scope, char* dtype, char* val, int line_num);
extern void decrScope();
%}

%define parse.error verbose
%token ID NUM T_lt T_gt COMMA STRC TERMINATOR RETURN FLT T_lteq T_gteq T_neq T_eqeq T_pl S_min S_mul S_add S_div T_min T_mul T_div T_and T_or T_incr T_decr T_not T_eq WHILE INT CHAR FLOAT VOID H MAINTOK INCLUDE BREAK CONTINUE IF ELSE COUT STRING FOR OB CB OBR CBR ENDL


%%
S: START {
        printf("Successful parsing.\n");
        displaySymTable();
        exit(0);
      }
      | error {
         yyerrok;
         yyclearin;
       }
      ;

START
    : INCLUDE T_lt H T_gt MAIN
    | INCLUDE '\"' H '\"' MAIN
    ;



MAIN
      : VOID MAINTOK BODY
      | INT MAINTOK BODY{
        astnode* masternode = addToTree("main", $3, NULL, NULL, 0);
        printTree(masternode);
      }
      ;

BODY
      : OBR C CBR{
        $$ = $2;
      }
      ;

// extensively responsible for printing the nodes, and also adding the nodes, loop and statement, of similar scope together, in a binary tree fashion.
C
      : C statement TERMINATOR {
        $$ = addToTree("", $1, $2, NULL, 0);
        printTree($2);
        printf("\n");
        printf("----------------------------------------------------------------\n");
      }
      | C LOOPS{
        $$ = addToTree("", $1, $2, NULL, 0);
        printTree($2);
        printf("\n");
        printf("----------------------------------------------------------------\n");
      }
      | statement TERMINATOR {
        $$ = addToTree("", $1, NULL, NULL, 0);
        printTree($1);
        printf("\n");
        printf("----------------------------------------------------------------\n");
      }
      | LOOPS{
        $$ = addToTree("", $1, NULL, NULL, 0);
        printTree($1);
        printf("\n");
        printf("----------------------------------------------------------------\n");
      }
      | C OBR C CBR{
        printTree($3);
        printf("\n");
        printf("----------------------------------------------------------------\n");
      }
      | OBR CBR
      | error TERMINATOR
      ;

LOOPS
      : WHILE OB COND CB LOOPBODY {
        $$ = addToTree("while", $3, $5, NULL, 0);
      }
      | FOR OB ASSIGN_EXPR TERMINATOR COND TERMINATOR statement CB LOOPBODY{
        astnode** siblings = (astnode**) malloc(sizeof(astnode*) * 2);
        
        siblings[0] = $7;
        siblings[1] = $3;
        // siblings[2] = statement;
        
        $$ = addToTree("for", $5, $9, siblings, 2);
      }
      | IF OB COND CB LOOPBODY {
         $$ = addToTree("if", $3, $5, NULL, 0);
      }
      | IF OB COND CB LOOPBODY ELSE LOOPBODY{

            astnode* elsePart = addToTree("else", $7, NULL, NULL, 0);
            astnode* ifPart = addToTree("if", $5, NULL, NULL, 0);

            astnode** siblings = (astnode**) malloc(sizeof(astnode*) * 1);
            siblings[0] = elsePart;

            $$ = addToTree("condition", $3, ifPart, siblings, 2);
          }
      | IF OB COND CB LOOPBODY ELSE LOOPS {

              astnode* elsePart = addToTree("else", $7, NULL, NULL, 0);
              astnode* ifPart = addToTree("if", $5, NULL, NULL, 0);

              astnode** siblings = (astnode**) malloc(sizeof(astnode*) * 2);
              siblings[0] = elsePart;

              $$ = addToTree("condition", $3, ifPart, siblings, 2);
        }
      ;


LOOPBODY
	  : OBR C CBR {
      // printTree($2);
      $$ = $2;
    }
	  | TERMINATOR
	  | statement TERMINATOR {
      // printTree($1);
      $$ = $1;
    }
    | OBR CBR {
      $$ = (astnode *) malloc(sizeof(astnode));
    }
	  ;

statement
      : ASSIGN_EXPR {$$ = $1;}
      | ARITH_EXPR
      | TERNARY_EXPR
      | SUGAR_OPS { $$ = $1; }
      | PRINT
      | RETURN ASSIGN_EXPR
      | RETURN ARITH_EXPR
      ;

SUGAR_OPS:
      ID s_ops ARITH_EXPR {
          int id =  insert(&count, t_scope, tdType, $1, yylineno);
          if(id == -1){
            printf("redeclared: %s\n", $1);
            yyerror("Variable redeclared");
          }

          astnode* newnode =addToTree((char*) $1, NULL, NULL, NULL, 0);
          setScopeAndPtr(newnode, t_scope, id);
          char temp[] = "";
          char ch = ((char*)$2)[0];
          strncat(temp, &ch, 1);
          astnode* rhs = addToTree((char*)temp, newnode, $3, NULL, 0);
          $$ = addToTree("=", newnode, rhs, NULL, 0);
       }
      ;


COND
      : LIT RELOP LIT {
        $$=addToTree((char *)$2,$1,$3, NULL, 0);
      }
      | LIT {
        $$=$1;
      }
      | LIT RELOP LIT bin_boolop LIT RELOP LIT
      | un_boolop OB LIT RELOP LIT CB
      | un_boolop LIT RELOP LIT
      | LIT bin_boolop LIT
      | un_boolop OB LIT CB
      | un_boolop LIT
      ;


ASSIGN_EXPR
      : ID T_eq ARITH_EXPR
      {
        int id = find(t_scope, $1);
        if (id == -1) {
          yyerror("variable not declared");
        }
        update($1, atoi($3 -> name), t_scope);

        astnode* newnode =addToTree((char*) $1, NULL, NULL, NULL, 0);
        setScopeAndPtr(newnode, -1, id);
        $$=addToTree("=", newnode, $3, NULL, 0);
      }
      | TYPE ID T_eq ARITH_EXPR
      {
        int id = insert(&count, t_scope, $1, $2, yylineno);
        if(id == -1)
              yyerror("Variable redeclared");

        update((char *) $2, atoi($4 -> name), t_scope);

        astnode* newnode =addToTree((char*) $2, NULL, NULL, NULL, 0);
        setScopeAndPtr(newnode, t_scope, id);
        $$ = addToTree("=", newnode , $4, NULL, 0);
      }

    |
      TYPE ID {
          int id = insert(&count, t_scope, $1, $2, yylineno);

          if(id == -1)
                yyerror("Variable redeclared");

          astnode* newnode =addToTree((char*) $2, NULL, NULL, NULL, 0);
          setScopeAndPtr(newnode, t_scope, id);
          $$= addToTree("init", newnode, NULL, NULL, 0);
      }

      | TYPE ID COMMA X {
          strcpy(tdType, $1);
          dflag = 1;

          int id = insert(&count, t_scope, $1, $2, yylineno);
          if(id == -1)
                yyerror("Variable redeclared");


          astnode* newnode =addToTree((char*) $2, NULL, NULL, NULL, 0);
          setScopeAndPtr(newnode, t_scope, id);
          $$= addToTree("init", newnode, NULL, NULL, 0);
        }
      |
      TYPE ID T_eq ARITH_EXPR COMMA X {
        strcpy(tdType, $1);
        dflag = 1;
        int id = insert(&count, t_scope, $1, $2, yylineno);
        if(id == -1)
              yyerror("Variable redeclared");
        update($2, atoi($4 -> name), t_scope);

        astnode* newnode =addToTree((char*) $2, NULL, NULL, NULL, 0);
        setScopeAndPtr(newnode, t_scope, id);
        $$= addToTree("=", newnode, NULL, NULL, 0);
      }
      ;

X : ID COMMA X {
    int id = insert(&count, t_scope, tdType, $1, yylineno);
    if(id == -1){
      printf("redeclared: %s\n", $1);
      yyerror("Variable redeclared");
    }

    astnode* newnode =addToTree((char*) $1, NULL, NULL, NULL, 0);
    setScopeAndPtr(newnode, t_scope, id);
    $$= addToTree("init", newnode, NULL, NULL, 0);
}
  |
  ID {
      int id =  insert(&count, t_scope, tdType, $1, yylineno);
      if(id == -1){
        printf("redeclared: %s\n", $1);
        yyerror("Variable redeclared");
      }

      astnode* newnode =addToTree((char*) $1, NULL, NULL, NULL, 0);
      setScopeAndPtr(newnode, t_scope, id);
      $$= addToTree("init", newnode, NULL, NULL, 0);
  }
  | ID T_eq ARITH_EXPR COMMA X {
    int id = insert(&count, t_scope, tdType, $1, yylineno);
    if(id == -1){
      printf("redeclared: %s\n", $1);
      yyerror("Variable redeclared");
    }
    update($1, atoi($3 -> name), t_scope);

    astnode* newnode =addToTree((char*) $1, NULL, NULL, NULL, 0);
    setScopeAndPtr(newnode, t_scope, id);
    $$= addToTree("=", newnode, $2, NULL, 0);
  }
  | ID T_eq ARITH_EXPR {
    int id = insert(&count, t_scope, tdType, $1, yylineno);
    if(id == -1){
      printf("redeclared: %s\n", $1);
      yyerror("Variable redeclared");
    }
    update($1, atoi($3 -> name), t_scope);

    astnode* newnode =addToTree((char*) $1, NULL, NULL, NULL, 0);
    setScopeAndPtr(newnode, t_scope, id);
    $$= addToTree("=", newnode, $2, NULL, 0);
  }

ARITH_EXPR
      : LIT
      | LIT bin_arop ARITH_EXPR {
        $$=addToTree((char *) $2, $1, $3, NULL, 0);
      }
      | LIT bin_boolop ARITH_EXPR {
        $$=addToTree((char *) $2, $1, $3, NULL, 0);
      }
      | LIT un_arop {
        $$= addToTree((char *) $2, $1, NULL, NULL, 0);
      }
      | un_arop ARITH_EXPR{
        $$= addToTree((char *) $1, $2, NULL, NULL, 0);
      }
      | un_boolop ARITH_EXPR{
        $$= addToTree((char *) $1, $2, NULL, NULL, 0);
      }
      ;


TERNARY_EXPR
      : OB COND CB '?' statement ':' statement
      ;


PRINT
      : COUT T_lt T_lt STRING {
        astnode* x = addToTree((char *) $4, NULL, NULL, NULL, 0);
        $$ = addToTree((char *) $1, x, NULL, NULL, 0);
      }
      | COUT T_lt T_lt STRING T_lt T_lt ENDL {
        {
          astnode* x = addToTree((char *) $4, NULL, NULL, NULL, 0);
          $$ = addToTree((char *) $1, x, NULL, NULL, 0);
        }
      }
      | COUT T_lt T_lt ENDL{
        astnode* x = addToTree("", NULL, NULL, NULL, 0);
        $$ = addToTree((char *) $1, x, NULL, NULL, 0);
      }

      ;
LIT
      : ID {
            int id = find(t_scope, $1);
            if (find == -1) {
                yyerror("variable not declared");
            }
            astnode* newNode = addToTree((char*) $1, NULL, NULL, NULL, 0);
            setScopeAndPtr(newNode, -1, id);
            $$ = newNode;
        }
      | NUM {
        $$=addToTree((char*) $1, NULL, NULL, NULL, 0);
      }
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
      : T_pl
      | T_min
      | T_mul
      | T_div
      ;

bin_boolop
      : T_and
      | T_or
      ;

un_arop
      : T_incr
      | T_decr
      ;

un_boolop
      : T_not
      ;

s_ops:
      S_mul
      | S_add
      | S_min
      | S_div
      ;
%%


#include <ctype.h>

// siblings = list of the n sibling nodes, other than the left and right child, to be added to the parent node.
// will useful in the future i guess
astnode* addToTree(char *op,astnode *left,astnode *right, astnode** siblings, int lenSiblings)
{
  astnode* new = (astnode*) malloc(sizeof(astnode));
  char *newstr = (char *) malloc(strlen(op)+1);
  strcpy(newstr,op);
  new->name=newstr;
  new->children = (astnode**) malloc(sizeof(astnode*) * (lenSiblings + 2));
  new->children[0] = left;
  new->children[1] = right;
  new->numChildren = lenSiblings + 2;
  if(siblings){
        for(int i = 0; i < lenSiblings; i++){
              new->children[i + 2] = siblings[i];
        }
  }
  return (new);
}

// printing the nodes, need to add bfs logic here.
void printTree(astnode *tree)
{
  if(tree){

    if(tree->children[0] || tree->children[1])
    printf("(");
    printf(" %s ",tree->name);
    int i = 0;

    while(i < tree->numChildren){
          printTree(tree->children[i]);
          i++;
    }
    if(tree->children[0] || tree->children[1])
    printf(")");
  }
}

void setScopeAndPtr(astnode* node, int scope, int ptr){
  node -> entry = ptr;
  if(scope > 0) node -> scope = symTable[ptr].scope;
  node -> isID = 1;

  printf("added id: %s with pointing to index %d of the symbol table\n", node -> name, node -> entry);
}

int yyerror(const char *s)
{
  	extern int yylineno;
    valid = 0;
  	printf("\n\nERROR: line number: %d - error: %s\n\n",yylineno,s);
}

int main()
{
	yyparse();
	if(valid)
  		printf("\nParsing successful\n\n\n");
	else
	{
  		printf("Parsing unsuccessful\n\n\n");
	}
	displaySymTable();
	return 0;
}
