/* recognize tokens for the text input and print them out */

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "BisonFun5v.h"
  
  int yylex();
	int yyerror(char *s);
	
	/*struct NodeB * root;*/
%}

%token INT ID CHAR TYPE ARRAY NUM

%union{
  int i;
  double d;
  char c;
  char type [3]; 
  char idname[100] ;
  char arr [100];
  struct Node * fp;
}

%type <i> NUM
%type <idname> ID
%type <c> CHAR
%type <type> TYPE
%type <arr> ARRAY

%token IF ELSE WHILE RETURN BREAK READ WRITE
%token LPAR RPAR LBRACK RBRACK LBRACE RBRACE SEMI EQUALS MULT ADD DIV SUBS

/*%token program VarDecl VarDeclList StmtList ExprList Stmt Expr Primary ExprListTail*/
%type <fp> program VarDecl VarDeclList StmtList ExprList Stmt Expr Primary ExprListTail 

%start program

/*Lower precedence*/
%right EQUAL
%left ADD SUBS
%left MULT DIV
%left LPAR RPAR
/*Higher precendece*/


//node type, name, left pointer, right, middle, extra, text value, int value, character value
//struct Node * nodeFun(int nodeType, char * name, struct Node * l, struct Node * r, struct Node * m,struct Node * x, char * text, int val, char sym)

%%

program: VarDeclList StmtList ExprList		{printf("\n\t\t\tAST starting: program\n");headB = nodeFun(200, "program", $1, $2, $3, 0, "", 0, ' ',0);}
  ;

VarDeclList:  %empty						{$$ = nodeFun(201, "VarDeclList", 0, 0, 0, 0, "", 0, ' ',0);}
			| VarDecl VarDeclList 			{$$ = nodeFun(201, "VarDeclList", $1, $2, 0, 0, "", 0, ' ',0);}
  ; 

VarDecl: TYPE  ID  SEMI                      {printf("\n VarDecl found\n\tID: %s (%s)\n", $2, $1);    
												
												if(getNode($2, "Globl") == NULL) 
												{
													struct node * temp = insertNodeType($2, $1, "Globl"); 
												}
												else{printf("/n/tError: Duplicate Variable: %s/n",$2);}
												
												{
												char * par = $1;
												$$ = nodeFun(202, "VarDecl", 0, 0, 0, 0, $2, 0, par[0], 0);}
											} 
											
		|TYPE ID LBRACK NUM RBRACK SEMI        {printf("\n Array found \n"); 
												if(getNode($2, "Globl") == NULL){
													insertNodeArr($2, $1, -1, ' ', $4 , "Globl");
												}
												char * par = $1;
												{$$ = nodeFun(203, "VarDecl", 0, 0, 0, 0, $2, $4, par[0],0);}
											}
   ;

StmtList: Stmt 								{printf("\n Stmt found \n");
												$$ = nodeFun(213, "Stmt", $1, 0, 0, 0, "", 0, ' ',0);
																		}
      | Stmt StmtList						{printf("\n Stmt StmtList found \n"); 
												$$ = nodeFun(214, "Stmt", $1, $2, 0, 0, "", 0, ' ',0);
												}
   ;
   
Stmt:  SEMI                                {printf("\n SEMI found \n");$$ = nodeFun(300, "", 0, 0, 0, 0, "", 0, ' ',0);} 
     |WRITE Expr SEMI                      {printf("\n WRITE found \n");$$ = nodeFun(304, "", $2, 0, 0, 0, "", 0, ' ',0);}
     |READ ID SEMI                         {printf("\n READ statement found \n");$$ = nodeFun(303, "", 0, 0, 0, 0, $2, 0, ' ',0);}
     |Expr SEMI                            {printf("\n Expr found \n");$$ = nodeFun(301, "", $1, 0, 0, 0, "", 0, ' ',0);}
     |RETURN Expr SEMI                     {printf("\n RETURN found \n");$$ = nodeFun(302, "", $2, 0, 0, 0, "", 0, ' ',0);}  
   ;

Expr: Primary                              {printf("\n Primary found\n");$$ = nodeFun(400, "", $1, 0, 0, 0, "", 0, ' ',0);}
     |ID  EQUALS Expr                      {printf("\n Assignment found\n");$$ = nodeFun(403, "", 0, $3, 0, 0, $1, 0, ' ',0);}
     |Expr ADD Expr                        {printf("\n Addition found\n");$$ = nodeFun(402, "", $1, 0, $3, 0, "ADD", 0, ' ',0);} 
     |Expr MULT Expr                       {printf("\n Mult found\n");$$ = nodeFun(402, "", $1, 0, $3, 0, "MULT", 0, ' ',0);}
     |Expr SUBS Expr                       {printf("\n Sub found \n");$$ = nodeFun(402, "", $1, 0, $3, 0, "SUBS", 0, ' ',0);}
     |Expr DIV Expr                        {printf("\n Div found\n");$$ = nodeFun(402, "", $1, 0, $3, 0, "DIV", 0, ' ',0);}
     |NUM                                  {printf("\n Number found: %d\n", $1);$$ = nodeFun(401, "", 0, 0, 0, 0, "", $1, ' ',0);}
     |ID LBRACK Expr RBRACK EQUALS Expr    {printf("\n ID expression found\n");$$ = nodeFun(404, "", 0, $3, $6, 0, $1, 0, ' ',0);}
   ;

Primary: ID                                {printf("\n ID found: %s\n", $1);$$ = nodeFun(500, "", 0, 0, 0, 0, $1, 0, ' ',0);
												//printScopeRowNamed("Globl");
												//printf("%ld", getNode($1,"Globl"));
												if(getNode($1,"Globl") == NULL || getNode($1,"Globl") == 0)
												{
													printf("\t\tID (%s) does not exist\n",$1); 
													//exit(0);
												}
												else
												{
													printf("\tID (%s) EXISTS\n", $1); 
												}
											} 
        |LPAR Expr RPAR                    {printf("\n Expression parentheses found\n");$$ = nodeFun(502, "", $2, 0, 0, 0, "", 0, ' ',0);}    
        |ID LBRACK ExprList RBRACK             {printf("\n Array expression found\n");$$ = nodeFun(504, "", 0, $3, 0, 0, $1, 0, ' ',0);}
    ;

ExprList: %empty							{$$ = nodeFun(700, "", 0, 0, 0, 0, "", 0, ' ',0);}
        |ExprListTail   					{$$ = nodeFun(700, "", $1, 0, 0, 0, "", 0, ' ',0);}
    ;

ExprListTail: Expr                          {$$ = nodeFun(217, "", $1, 0, 0, 0, "", 0, ' ',0);}
            | Expr ExprListTail				{$$ = nodeFun(218, "", $1, $2, 0, 0, "", 0, ' ',0);}
   ;

%%






