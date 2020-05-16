/* recognize tokens for the text input and print them out */

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "BisonFun5v.h"
  
  int yylex();
  int yyerror(char *s);
	
	//if all same types for all child nodes, return same type(aka int or char) 
	//0 int, 1 char, 2 intArr, 3 charArr, 4 int function, 5 char function 
	int checkTypeRecursion(struct NodeB * a, int type)
	{
	
		//print input
		if(a == NULL || a == 0)
		{
			printf("Error: pointer doesnt exist\n");
			exit(0);
		}
		if(a->name == NULL || a->name == 0)
		{
			printf("Error: no name node\n");
		}
		if(a->NodeBType == NULL || a->NodeBType == 0)
		{
			printf("Error: no type node\n");
		}
		/*
		printf("Checking Type %d to node %s (%d)\n", type, a->name, a->NodeBType);
		if(a->NodeBType == 500)
		{
			if((getType(a->name, "Globl")) == 0 || (getType(a->name, "Globl")) == 2 || (getType(a->name, "Globl")) == 4)
			{
				printf(" (int:%d)\n", getType(a->name, "Globl"));
			}
			if((getType(a->name, "Globl")) == 1 || (getType(a->name, "Globl")) == 3 || (getType(a->name, "Globl")) == 5)
			{
				printf(" (char:%d)\n", getType(a->name, "Globl"));
			}
		}
		else
		{
			printf("\n");
		}
		*/
		int typeO = -1;
		//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
		int at;
		switch(a->NodeBType) 
		{
		  case 10 :/*character*/
			 if(type == 1 || type == 3 || type == 5)
			 {
				printf("CHECK TYPE CHAR(10)\n");
				typeO = type;
			 }
			 else
			 {
				return -1;
			 }
			 break;
		/*string*/			
		case 11 :
			if(type == 1 || type == 3 || type == 5)
			 {
			 	printf("CHECK TYPE STRING(11)\n");
				typeO = type;
			 }
			 else
			 {
				return -1;
			 }
			break; 
			
		case 500 : /*ID, check symbol table*/
			if(a == NULL || a == 0)
			{
				printf("Error: no node\n");
					exit(0);
			}
			else
			{
				if(a->name == NULL || a->name == 0)
				{ 
					printf("Error: no name node\n");
					exit(0);
				}
			}
			printf("Checkpoint\n");
			printf("\t\t\tComparing %s (%d) vs type(%d)\n", a->name, (getType(a->name, "Globl")), type);///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
			//printf("Checking Type: %d\n", (checkType(a->name, "Globl", type)));
			//return (checkType(a->name, "Globl", type)); 
			
			
			if((((getType(a->name, "Globl"))%2) == 0) && (type%2 == 0))
			{
				printf("%s (%d) is a compatible type (%d)\n", a->name, (getType(a->name, "Globl")), type);
				if(idCounter(a->name, "Globl", 0) < 1)
				{
					printf("Uninstantiated Variable: %s\n", a->name);
					exit(0);
				}
				return type; 
			}
			else
			{
				if((((getType(a->name, "Globl"))%2) == 1) && (type%2 == 1))
				{
					printf("%s (%d) is a compatible type (%d)\n", a->name, (getType(a->name, "Globl")), type);
					if(idCounter(a->name, "Globl", 0) < 1)
					{
						printf("Uninstantiated Variable: %s\n", a->name);
						exit(0);
					}
					return type; 
				}
				else
				{
					printf("%s (%d) is an incompatible type (%d)\n", a->name, (getType(a->name, "Globl")), type);
					return -1;
				}
			}
			 
			 //if ID variable type == inputted type			 
			break;
		  case 401 : /*NUM*/
				if(type == 0 || type == 2 || type == 4)
				{
					printf("CHECK TYPE NUM(401)\n");
					typeO = type;
				}
				else
				{
					return -1;
				}
			 break;
		  default :
			printf("CHECK TYPE DEFAULT(%d) compareto nodeType(%d)\n", type, a->NodeBType);
			 typeO = type;
	   }
	   /*
	   printf("\n\n\n\n"); 
	   printNodeB(a);
	   printf("\n\n\n\n");
	   */
		
		if(a->l != NULL || a->l != 0)
		{		
			//printf("CHECK L (%ld vs %d)\n", a->l, type);
			if(checkTypeRecursion(a->l, type) == -1)
			{
				//printf("CHECK L2\n");
				return -1;
			}
			//else{return type;}
			//printf("CHECK L3\n");
		}
		if(a->r != NULL || a->r != 0)
		{
			//printf("CHECK R\n");
			if(checkTypeRecursion(a->r, type) == -1)
			{
				//printf("CHECK R2\n");
				return -1;
			}
			//else{return type;}
			//printf("CHECK R3\n");
		}
		if(a->m != NULL || a->m != 0)
		{
			//printf("CHECK M\n");
			if(checkTypeRecursion(a->m, type) == -1)
			{
			//printf("CHECK M2\n");
				return -1;
			}
			//else{return type;}
			//printf("CHECK M3\n");
		}
		if(a->x != NULL || a->x != 0)
		{
			printf("CHECK X\n");
			if(checkTypeRecursion(a->x, type) == -1)
			{
			printf("CHECK X2\n");
				return -1;
			}
			//else{return type;}
			//printf("CHECK X3\n");
		}		
		return typeO;
	}
	
%}

%token INT ID CHAR TYPE ARRAY NUM LITCHAR LITSTRING

%union{
  int i;
  double d;
  char c [3];
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
%type <c> LITCHAR
%type <arr> LITSTRING

%token IF ELSE WHILE RETURN BREAK READ WRITE
%token LPAR RPAR LBRACK RBRACK LBRACE RBRACE SEMI EQUALS MULT ADD DIV SUBS MOD

/*%token program VarDecl VarDeclList StmtList ExprList Stmt Expr Primary ExprListTail*/
%type <fp> program VarDecl VarDeclList StmtList ExprList Stmt Expr Primary ExprListTail 

%start program

/*Lower precedence*/ 
%right EQUAL
%left ADD SUBS
%left MULT DIV MOD
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
												//check if node exists, if not, return 0/NULL
												//FLAW-- variables cant have same name, even if different type
												if(getNode($2, "Globl") == NULL || getNode($2, "Globl") == 0)
												{
													//if node doesnt exist, create node in symbol table
													struct node * temp = insertNodeType($2, $1, "Globl"); 
													//create syntax tree nodes
													char * par = $1;
													$$ = nodeFun(202, "VarDecl", 0, 0, 0, 0, $2, 0, par[0], 0);		
												}
												else
												{
													printf("\n\tError: Duplicate Variable: %s\n",$2);
													exit(0);
												}											
											} 
											
	|TYPE ID LBRACK NUM RBRACK SEMI        {printf("\n Array found \n"); 
												//create array node if not exist
												if(getNode($2, "Globl") == NULL)
												{
													insertNodeArr($2, $1, -1, ' ', $4 , "Globl");
													char * par = $1;
													$$ = nodeFun(203, "VarDecl", 0, 0, 0, 0, $2, $4, par[0],0);
												}
												else
												{
													printf("\n\tError: Duplicate Variable: %s\n",$2);
													exit(0);
												}
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
	 | WRITE LITCHAR SEMI					{ printf("\n WRITE CHAR %s found \n", $2);
												$$ = nodeFun(610, "", 0, 0, 0, 0, "", 0, $2,0);
											}
	 | WRITE LITSTRING SEMI					{ printf("\n WRITE STRING found: %s \n", $2);
												$$ = nodeFun(611, "", 0, 0, 0, 0, $2, 0, ' ',0);
											}
     | WRITE Expr SEMI                      {printf("\n WRITE found \n");
												$$ = nodeFun(304, "", $2, 0, 0, 0, "", 0, ' ',0);
											}
     |READ ID SEMI                         {printf("\n READ statement found \n");/*struct NodeB * t*/$$ = nodeFun(303, "", 0, 0, 0, 0, $2, 0, ' ',0);
												if(getNode($2,"Globl") == NULL || getNode($2,"Globl") == 0)
												{
													printf("\t\tID (%s) does not exist\n",$2); 
													exit(0);
												}
												else 
												{
													printf("\tID (%s) EXISTS\n", $2); 
												}
	 
											}
											
	|READ ID LBRACK NUM RBRACK SEMI         {printf("\n READ statement found \n");/*struct NodeB * t*/$$ = nodeFun(303, "", 0, 0, 0, 0, $2, 0, ' ',0);
												if(getNode($2,"Globl") == NULL || getNode($2,"Globl") == 0)
												{
													printf("\t\tID (%s) does not exist\n",$2); 
													exit(0);
												}
												else 
												{
													//check if array index is between 0 and NUM-1
													//printf("%d < %d\n", (arrayBound($2,"Globl")), $4);
													if((arrayBound($2,"Globl"))  > $4 &&(arrayBound($2,"Globl"))  > -1)
													{
														printf("\tID (%s) EXISTS\n", $2);
													}
													else
													{
														printf("%s is out of array bounds\n", $2);
														exit(0);
													}
												}
	 
											}
											
     |Expr SEMI                            {printf("\n Expr found \n");$$ = nodeFun(301, "", $1, 0, 0, 0, "", 0, ' ',0);}
     |RETURN Expr SEMI                     {printf("\n RETURN found \n");$$ = nodeFun(302, "", $2, 0, 0, 0, "", 0, ' ',0);}  
   ;

Expr: Primary                              {printf("\n Primary found\n");$$ = nodeFun(400, "", $1, 0, 0, 0, "", 0, ' ',0);}
	| LITCHAR								{/*printf("LITCHAR found\n");*/$$ = nodeFun(010, "", 0, 0, 0, 0, "", 0, $1,0);}

     |ID EQUALS Expr                      {printf("\n Assignment found\n");
												/*FLAW ID CAN BE SET TO EQUAL ITSELT, WITHOUT ALERTING TO THE NULL ERROR*/
												struct NodeB * t = nodeFun(403, "", 0, $3, 0, 0, $1, 0, ' ',0);
												if(getNode($1,"Globl") == NULL || getNode($1,"Globl") == 0)
												{ 
													printf("\t\tID (%s) does not exist\n",$1);
													exit(0);
												} 
												else 
												{
													/*Check if id is a variable or an array*/
													if(getType($1, "Globl") == 0 || getType($1, "Globl") == 1)
													{
														printf("\tID (%s) EXISTS\n", $1);
														
														//printf("INcrement counter\n");
														printf("%d\n",idCounter($1,"Globl",1));
														//printf("counter INcremented \n");
													}
													else
													{
														printf("\t\tID (%s) is not non-array variable type\n",$1); 
														exit(0);
													}
												}
												/*###############################################*/
												int tyTemp = getType($1, "Globl");
												printf("\tID (%s) type: \n",$1, tyTemp);
												int tyTemp2 = checkTypeRecursion(t, getType($1, "Globl"));
												printf("checkTypeRecursion: %d\n", tyTemp2);
												if( tyTemp2 == -1) 
												{
													printf("\t\t\t%s set to equal an incompatible expression!\n", $1);
													exit(0);
												}
												$$ = t;
												/*###############################################*/
												
											}
     |Expr ADD Expr                        {printf("\n Addition found\n");$$ = nodeFun(402, "", $1, 0, $3, 0, "ADD", 0, ' ',0);} 
     |Expr MULT Expr                       {printf("\n Mult found\n");$$ = nodeFun(402, "", $1, 0, $3, 0, "MULT", 0, ' ',0);}
     |Expr SUBS Expr                       {printf("\n Sub found \n");$$ = nodeFun(402, "", $1, 0, $3, 0, "SUBS", 0, ' ',0);}
     |Expr MOD Expr                       {printf("\n Sub found \n");$$ = nodeFun(402, "", $1, 0, $3, 0, "MOD", 0, ' ',0);}
     |Expr DIV Expr                        {printf("\n Div found\n");$$ = nodeFun(402, "", $1, 0, $3, 0, "DIV", 0, ' ',0);}
     |NUM                                  {printf("\n Number found: %d\n", $1);$$ = nodeFun(401, "", 0, 0, 0, 0, "", $1, ' ',0);}
	 |ID LBRACK NUM RBRACK EQUALS Expr    {printf("\n ID expression found\n");struct NodeB * tt = nodeFun(404, "", 0, $3, $6, 0, $1, 0, ' ',0);																							
												/*check if ID exists in symbol table*/
												if(getNode($1,"Globl") == NULL || getNode($1,"Globl") == 0)
												{
													printf("\t\tID (%s) does not exist\n",$1); 
													exit(0);
												}
												else
												{
													/*Check if id is array*/
													if(getType($1, "Globl") == 2 || getType($1, "Globl") == 3)
													{
														printf("\tID (%s) EXISTS\n", $1); 
														printf("INcrement counter\n");
														printf("%d\n",idCounter($1,"Globl",1));
														printf("counter INcremented \n");
														
														//check if ID array is in bounds
														if((arrayBound($1,"Globl"))  > $3 &&(arrayBound($1,"Globl"))  > -1)
														{
															//printf("\tID (%s) EXISTS\n", $1);
														}
														else
														{
															printf("%s is out of array bounds\n", $1);
															exit(0);
														}
															
													}
													else
													{
														printf("\t\tID (%s) is not an array\n",$1); 
														exit(0);
													}
												}
												/*Check if first expression is a number*/
												
												/*check if second expression is same type as ID*/
												int x = getType($1, "Globl");
												/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
												int tyTemp = getType($1, "Globl");
												printf("\tID (%s) type: \n",$1, tyTemp);
												int tyTemp2 = checkTypeRecursion(tt, getType($1, "Globl"));
												printf("checkTypeRecursion: %d\n", tyTemp2);
												if( tyTemp2 == -1) 
												{
													printf("\t\t\t%s set to equal an incompatible expression!\n", $1);
													exit(0);
												}
												$$ = tt;
											}
     |ID LBRACK Expr RBRACK EQUALS Expr    {printf("\n ID expression found\n");$$ = nodeFun(404, "", 0, $3, $6, 0, $1, 0, ' ',0);
																							
												/*check if ID exists in symbol table*/
												if(getNode($1,"Globl") == NULL || getNode($1,"Globl") == 0)
												{
													printf("\t\tID (%s) does not exist\n",$1); 
													exit(0);
												}
												else
												{
													/*Check if id is array*/
													if(getType($1, "Globl") == 2 || getType($1, "Globl") == 3)
													{
														/*printf("\tID (%s) EXISTS\n", $1); 
														printf("INcrement counter\n");
														printf("%d\n",idCounter($1,"Globl",1));
														printf("counter INcremented \n");*/
													}
													else
													{
														printf("\t\tID (%s) is not an array\n",$1); 
														exit(0);
													}
												}
												/*Check if first expression is a number*/
												
												/*check if second expression is same type as ID*/
												int x = getType($1, "Globl");
											}
   ;

Primary: ID                                {printf("\n ID found: %s\n", $1);$$ = nodeFun(501, "", 0, 0, 0, 0, $1, 0, ' ',0);
												//printScopeRowNamed("Globl");
												//printf("%ld", getNode($1,"Globl"));
												if(getNode($1,"Globl") == NULL || getNode($1,"Globl") == 0)
												{
													printf("\t\tID (%s) does not exist\n",$1); 
													exit(0);
												}
												else
												{
													//printf("\tID (%s) EXISTS\n", $1); 
												}
											} 
    |LPAR Expr RPAR                	    {printf("\n Expression parentheses found\n");$$ = nodeFun(502, "", $2, 0, 0, 0, "", 0, ' ',0);}    
	
	|ID LBRACK NUM RBRACK          {printf("\n Array expression found\n");$$ = nodeFun(504, "", 0, $3, 0, 0, $1, 0, ' ',0);
											if(getNode($1,"Globl") == NULL || getNode($1,"Globl") == 0)
											{
												printf("\t\tID (%s) does not exist\n",$1); 
												exit(0);
											}
											else
											{
												if((arrayBound($1,"Globl"))  > $3 &&(arrayBound($1,"Globl"))  > -1)
												{
													//printf("\tID (%s) EXISTS\n", $1);
												}
												else
												{
													printf("%s is out of array bounds\n", $1);
													exit(0);
												}
											}	
										}
	
    |ID LBRACK ExprList RBRACK          {printf("\n Array expression found\n");$$ = nodeFun(504, "", 0, $3, 0, 0, $1, 0, ' ',0);
											//check if node exists
											if(getNode($1,"Globl") == NULL || getNode($1,"Globl") == 0)
											{
												printf("\t\tID (%s) does not exist\n",$1); 
												exit(0);
											}
											else
											{
												//printf("\tID (%s) EXISTS\n", $1); 
											}	
										}										
    ;

ExprList: %empty							{$$ = nodeFun(700, "", 0, 0, 0, 0, "", 0, ' ',0);}
        |ExprListTail   					{$$ = nodeFun(700, "", $1, 0, 0, 0, "", 0, ' ',0);}
    ;

ExprListTail: Expr                          {$$ = nodeFun(217, "", $1, 0, 0, 0, "", 0, ' ',0);}
            | Expr ExprListTail				{$$ = nodeFun(218, "", $1, $2, 0, 0, "", 0, ' ',0);}
   ;

%%

	/*optimizations: remove nonreferenced IDs from symbol table*/


