//TREE POINTER STRUCTURE FILE

/* interface to the lexer */
//extern int yylineno; /* from lexer */
//void yyerror(char *s, ...);
#  include <stdarg.h>

//#include "symTab4v.h"

struct NodeB//generic NodeB
{
	int NodeBType;//type number
	
	int intValue;
	char stringValue [500];
	char charValue;
	
	char name [100];//char string name
	
	struct NodeB *l;//left
	struct NodeB *m;//middle
	struct NodeB *r;//right
	struct NodeB *x;//extra
	
	int symTabPtr;
	//struct node symTabPtr;//points to the symbol table index
};

//---------------------------------------------
struct NodeB * headB; /*= NodeBFun(0, "headB", 0, 0, 0, 0, "", 0, ' ', 0);*/
	
//translates NodeB type to name of NodeB type
char * binOpType(int i)
{
	switch(i)
	{
		case 100:
		return "||";
		break;
		case 106:
		return "%";
		break;
		case 102:
		return "/";
		break;
		case 103:
		return "*";
		break;
		case 104:
		return "-";
		break;
		case 105:
		return "+";
		break;
		case 101:
		return "&&";
		break;
		case 107:
		return "<";
		break;
		case 108:
		return ">";
		break;
		case 109:
		return "<=";
		break;
		case 110:
		return ">=";
		break;
		case 111:
		return "==";
		break;
		case 112:
		return "!=";
		break;
		
		default:
		return ("ERROR unidentified binary operation, inputted value was %d\n", i);
		break;
	}
}

//switch case function that creates NodeBs based on type
// NodeB type, name, left pointer, right, middle, extra, text value, int value, character value, symbolTablePtr
struct NodeB * nodeFun(int NodeBType, char * name, struct NodeB * l, struct NodeB * r, struct NodeB * m,struct NodeB * x, char * text, int val, char sym, /*struct node * */ int symTabPtr)
{										
	struct NodeB *a = malloc(sizeof(struct NodeB));
	struct NodeB *b = malloc(sizeof(struct NodeB));
	struct NodeB *c = malloc(sizeof(struct NodeB));
	struct NodeB *d = malloc(sizeof(struct NodeB));
	struct NodeB *e = malloc(sizeof(struct NodeB));
	//printf("NodeB Created %d\n", a);
	a->l = 0;
	  a->r = 0;
	  a->m = 0;
	  a->x = 0;
  if(!a) {
    //yyerror("No more memory, NodeB cannot be made\n");
	printf("Error, NodeB Not Created\n");
    exit(0);
  }
  
  if(NodeBType >= 1000 && NodeBType <= -1)
  {
	  //yyerror("Incorrect Token Type: %d\n", NodeBType);
	  printf("Error: Incorrect Token Type\n");
	  exit(0);
  }
  
  switch(NodeBType)
  {
	  
	  case (200)://program
		  a->NodeBType = NodeBType;
		  a->l = l;
		  a->r = r;
		  a->m = m;
		  //a->name = 
		  strcpy(a->name, "PROGRAM");
	  break;
	  
	  case (201)://varDeclList
		  a->NodeBType = NodeBType;
		  a->l = l;
		  a->r = r;
		  //a->m = NULL;
		  //a->name = 
		  strcpy(a->name, "VARDECLLIST");
	  break;
	  
	  case (202)://varDecl: type id
		  a->NodeBType = NodeBType;
		  //struct NodeB *b = malloc(sizeof(struct NodeB));
		  if(sym == 'i'){ //sym == type
				//b->name = 
				strcpy(b->name, "TYPE_INT");
				b->NodeBType = 211;
		  }
		  else{
		  if(sym == 'c'){ //sym == type
				//b->name = 
				strcpy(b->name, "TYPE_CHAR");
				b->NodeBType = 212;
			}
		  }
		  //struct NodeB *c = malloc(sizeof(struct NodeB));
		  //c->name = text;//ID name == text
		  strcpy(c->name, text);
		  c->symTabPtr = symTabPtr;
		  c->NodeBType = 500;
		  a->l = b;//TYPE
		  a->r = c;//ID
		  //a->m = NULL;
		  //a->name = "VARDECL_ID";
		  strcpy(a->name, "VARDECL_ID");
		  
	  break;
	  
	  case (203)://varDecl: Type ID '[' NUM ']' ';'
		  a->NodeBType = NodeBType;
		  //struct NodeB *b = malloc(sizeof(struct NodeB));
		  if(sym == 'i'){ // sym == type
			//b->name = "TYPE_INT";
			strcpy(b->name, "TYPE_INT");
			b->NodeBType = 211;
		  }
		  else{
			if(sym == 'c'){ //sym == type
				//b->name = "TYPE_CHAR";
				strcpy(b->name, "TYPE_CHAR");
				b->NodeBType = 212;
			}
		  }
		  //struct NodeB *c = malloc(sizeof(struct NodeB));
		  //c->name = text;//ID name == text
		  strcpy(c->name, text);
		  c->NodeBType = 500;
		  c->symTabPtr = symTabPtr;
		  //struct NodeB *d = malloc(sizeof(struct NodeB));
		  d->intValue = val;//NUM == val
		  d->NodeBType = 1;
		  //d->name = "NUM";
		  strcpy(d->name, "NUM");
		  a->l = b;//TYPE
		  a->r = c;//ID
		  a->m = d; //NUM
		  //a->name = "VARDECL_ID_ARRAY";
		  strcpy(a->name, "VARDECL_ID_ARRAY");
	  break;
	  
	  
	  case (010): //010 LITCHAR 
	 a->NodeBType = NodeBType;
	 //a->stringValue = text;
	 a->charValue = sym;
	  //a->m = NULL;
	  //a->name = "LITCHAR";
	  strcpy(a->name, "LITCHAR");
	  break;
	  
	  case (011): //011 LITSTRING
	 a->NodeBType = NodeBType;
	 //a->stringValue = text;
	 strcpy(a->stringValue, text);
	 //a->l = NULL;
	 // a->r = NULL;
	  //a->m = NULL;
	  //a->name = "LITSTRING";
	  strcpy(a->name, "LITSTRING");
	  break;
	  
	  
	  case (213): //stmtList: stmt
	 a->NodeBType = NodeBType;
	 a->l = l;//STMT
	  //a->r = NULL;
	  //a->m = NULL;
	  //a->name = "STMTLIST_STMT";
	  strcpy(a->name, "STMTLIST_STMT");
	  break;
	  
	  case (214): //stmtList: stmt or stmt stmtList
	 a->NodeBType = NodeBType;
	 a->l = l;//STMT
	  a->r = r;//stmtList
	  //a->m = NULL;
	  //a->name = "STMTLIST_STMT_STMTLIST";
	  strcpy(a->name, "STMTLIST_STMT_STMTLIST");
	  break;
	  
	  //stmt: ';' or Expr ';' or RETURN Expr ';' or READ ID or WRITE Expr or WRITELN Expr or BREAK ';' or if '(' Expr ')' Stmt ELSE Stmt or WHILE '(' Expr ')' Stmt or BLOCK
	  //stmt: ;
	  case (300): 
	  a->NodeBType = NodeBType;
	 // a->l = NULL;
	  //a->r = NULL;
	  //a->m = NULL;
	  //a->name = "STMT_SEMI";
	  strcpy(a->name, "STMT_SEMI");
	  break;
	  
	  //stmt: EXPR ;
	  case (301): 
	  a->NodeBType = NodeBType;
	  a->l = l;//expr
	 // a->r = NULL;
	  //a->m = NULL;
	  //a->name = 
	  strcpy(a->name, "STMT_EXPR");
	  break;

	  //stmt: READ ID ';'
	  case (303): 
	  a->NodeBType = NodeBType;
	  a->l = l;//id
	  //a->r = NULL;
	 // a->m = NULL;
	  //a->name = 
	  strcpy(a->name, "STMT_READ");
	  break;
	  
	  //stmt: WRITE Expr ';'
	  case (304): 
	  a->NodeBType = NodeBType;
	  a->l = l;//expr
	  //a->r = NULL;
	 // a->m = NULL;
	  //a->name = 
	  strcpy(a->name, "STMT_WRITE");
	  break;
	  
	  //--------STMT-END------------------------------
	  
	  //Expr: Primary or UnaryOp Expr or Expr BinOp Expr or ID '=' Expr or ID '[' Expr ']' '=' Expr
	  //Expr: Primary
	  case (400):
	  a->NodeBType = NodeBType;
	  a->l = l;//PRIMARY
	  //a->name = 
	  strcpy(a->name, "EXPR_PRIMARY");
	  break;
		
	  //Expr: Num
	  case (401):
	  a->NodeBType = NodeBType;
	  //struct NodeB *d = malloc(sizeof(struct NodeB));
	  d->intValue = val;//NUM == val
	  d->NodeBType = 1;
	  //d->name = "NUM";
	  strcpy(d->name, "NUM");
	  a->l = d;//NUM
	  //a->name = 
	  strcpy(a->name, "EXPR_NUM");
	  break;
	  
	  case (402)://expr binary exp + - * /
	  a->NodeBType = NodeBType;	
	  //struct NodeB *e = malloc(sizeof(struct NodeB));
	  //e->name = text;//BinOp name == text
	  //PARSER: (402, "", $1, 0, $3, 0, "", 0, ' ',0);}
	  strcpy(e->name, text);
	  e->NodeBType = val;//BinOp Type = val: (102 /)(103 *)(104 -)(105 +) 
	  if(val == 0)
	  {   if(e->name[0] == 'A')
		  {e->NodeBType = 105;}
		  if(e->name[0] == 'S')
		  {e->NodeBType = 104;}
		  if(e->name[0] == 'M')
		  {
			   if(e->name[1] == 'U')
			{
			  e->NodeBType = 103;
			}
			else
			{
				e->NodeBType = 106;
			}
			  
			  }
		  if(e->name[0] == 'D')
		  {e->NodeBType = 102;}}
	  a->l = l;//expr
	  a->r = e;//binop
	  a->m = m;//expr
	  //a->name = 
	  strcpy(a->name, "EXPR_EXPR_BINOP_EXPR");
	  break;
	  
	   case (403)://id = exp
	  a->NodeBType = NodeBType;
	  //struct NodeB *c = malloc(sizeof(struct NodeB));
	  //c->name = text;//ID name == text
	  strcpy(c->name, text);
	  c->NodeBType = 2;
	  c->symTabPtr = symTabPtr;
		a->l = c;//ID
	  a->r = r;//expr
	 // a->m = NULL;
	  //a->name = 
	  strcpy(a->name, "EXPR_ID_EQUALS_EXPR");
	  break;
	  
	   case (404): //id [ expr ] = expr
	  a->NodeBType = NodeBType;
	  //struct NodeB *c = malloc(sizeof(struct NodeB));
	  //c->name = text;//ID name == text
	  strcpy(c->name, text);
	  c->NodeBType = 2;
	  c->symTabPtr = symTabPtr;
	 a->l = c;//ID
	  a->r = r;//expr
	  a->m = m;//expr
	  //a->name = 
	  strcpy(e->name, "EXPR_ID_ARRAY_INDEX_EQUALS_EXPR");
	  break;
	  //--------------EXPR-END------------------------------
	  
	  //Primary: ID or '(' Expr ')' or ID '(' ExprList ')' or ID '[' Expr ']'
	  //Primary: ID
	  case (500): 
	 a->NodeBType = NodeBType;
	 //struct NodeB *c = malloc(sizeof(struct NodeB));
	  //c->name = text;//ID name == text
	  strcpy(c->name, text);
	  c->NodeBType = 2;
	  c->symTabPtr = symTabPtr;
	 a->l = c;//ID
	  //a->r = NULL;
	  //a->m = NULL;
	  //a->name = 
	  strcpy(a->name, "PRIMARY_ID");
	  break;
	  
	  //Primary: '(' Expr ')'
	  case (502): 
	 a->NodeBType = NodeBType;
	 a->l = l;//expr
	  //a->r = NULL;//
	  //a->m = NULL;//
	  //a->name = 
	  strcpy(e->name, "PRIMARY_(EXPR)");
	  break;

	  //Primary: ID '[' ExprList ']'
	  case (504): 
	 a->NodeBType = NodeBType;
	 //struct NodeB *c = malloc(sizeof(struct NodeB));
	  //c->name = text;//ID name == text
	  strcpy(c->name, text);
	  c->NodeBType = 2;
	  c->symTabPtr = symTabPtr;
	 a->l = c;//ID
	  a->r = r;//exprList
	  //a->m = NULL;//
	  //a->name = 
	  strcpy(a->name, "PRIMARY_ID_[EXPRLIST]");
	  break;
	  
	  //----------------------------primary-end--------------
	  
	  case (700): 
	 a->NodeBType = NodeBType;
	 a->l = l;//exprlisttail or null 
	 // a->r = NULL;//
	 // a->m = NULL;//
	  //a->name = 
	  strcpy(a->name, "EXPRLIST");
	  break;
	  
	  //ExprListTail
	  case (217): 
	 a->NodeBType = NodeBType;
	 a->l = l;//expr 
	 // a->r = NULL;//
	 // a->m = NULL;//
	  //a->name = 
	  strcpy(a->name, "EXPRLISTTAIL_EXPR");
	  break;
	  
	  case (218): 
	 a->NodeBType = NodeBType;
	 a->l = l;//expr or NULL
	  a->r = r;//exprListTail
	 // a->m = NULL;//
	  //a->name = 
	  strcpy(a->name, "EXPRLISTTAIL_EXPR_EXPRLISTTAIL");
	  break;
	  
	  // /
	  case (102): 
	 a->NodeBType = NodeBType;
	 //a->l = NULL;
	  //a->r = NULL;
	 // a->m = NULL;//
	  //a->name = 
	  strcpy(a->name, "DIV");
	  break;
	  
	  // *
	  case (103): 
	 a->NodeBType = NodeBType;
	// a->l = NULL;
	  //a->r = NULL;
	  //a->m = NULL;//
	  //a->name = 
	  strcpy(a->name, "MULT");
	  break;
	  
	  // -
	  case (104): 
	 a->NodeBType = NodeBType;
	// a->l = NULL;
	  //a->r = NULL;
	 // a->m = NULL;//
	  //a->name = 
	  strcpy(a->name, "SUBS");
	  break;
	  
	  // +
	  case (105):
	 a->NodeBType = NodeBType;
	 //a->l = NULL;
	 // a->r = NULL;
	 // a->m = NULL;//
	  //a->name = 
	  strcpy(a->name, "ADD");
	  break;
	  
	  case (106):
	 a->NodeBType = NodeBType;
	 //a->l = NULL;
	 // a->r = NULL;
	 // a->m = NULL;//
	  //a->name = 
	  strcpy(a->name, "MOD");
	  break;
	  
	  //NodeBFun(int NodeBType, char * name, struct NodeB * l, struct NodeB * r, struct NodeB * m,struct NodeB * x, char * text, int val, char sym)
	  case (0):
	 a->NodeBType = NodeBType;
	 a->l = l;
	  a->r = r;
	  a->m = m;//
	  a->x = x;//
	  //a->name = 
	  strcpy(a->name, "headB");
	  break;

	   default: 
	  // yyerror("Incorrect Token Type: %d\n", NodeBType);
	  printf("Incorrect Token Type\n");
	  exit(0);
	  break;
  }
  
  /*printNodeB(a);*/
	return a;
}

struct NodeB * nodeFunHead(int NodeBType, char * name, struct NodeB * l, struct NodeB * r, struct NodeB * m,struct NodeB * x, char * text, int val, char sym, /*struct node * */ int symTabPtr)
{										
	struct NodeB *a = malloc(sizeof(struct NodeB));
	struct NodeB *b = malloc(sizeof(struct NodeB));
	struct NodeB *c = malloc(sizeof(struct NodeB));
	struct NodeB *d = malloc(sizeof(struct NodeB));
	struct NodeB *e = malloc(sizeof(struct NodeB));
	//printf("NodeB Created %d\n", a);
	a->l = 0;
	  a->r = 0;
	  a->m = 0;
	  a->x = 0;
  if(!a) {
    //yyerror("No more memory, NodeB cannot be made\n");
	printf("Error, NodeB Not Created\n");
    exit(0);
  }
  
  if(NodeBType >= 1000 && NodeBType <= -1)
  {
	  //yyerror("Incorrect Token Type: %d\n", NodeBType);
	  printf("Error: Incorrect Token Type\n");
	  exit(0);
  }
	//program 200
	a->NodeBType = NodeBType;
	a->l = l;
	a->r = r;
	a->m = m;
	//a->name = 
	strcpy(a->name, "PROGRAM");
	  
  
	headB = a;
	printf("\n\t\t\tHead Node Made\n");
	printNodeB(a);
	return a;
}

void printNodeB(struct NodeB * a)
{
	if(a != NULL)
	{
		if(a->name != NULL)
		{
			printf("\n");
			printf("NodeB: %s\n",a->name);
			printf("Type: %d\n",a->NodeBType);
			printf("Int Value: %d\n",a->intValue);
			printf("String Value: %s\n",a->stringValue);
			printf("Char Value: %d\n",a->charValue);
			printf("L Pointer: %d\n",a->l);
			printf("R Pointer: %d\n",a->r);
			printf("M Pointer: %d\n",a->m);
			printf("X Pointer: %d\n",a->x);
			printf("\n");
		}
	}
	else
	{
		printf("EMPTY AST\n");
	}
}

void printTable(struct NodeB * a, int lvl)
{
	for(int i = 0; i < lvl; i++)
	{
		printf("\t");
	}
	if(a->NodeBType == 1)
	{
		printf("(%d) Num:%d\t LEVEL_%d\n",a->NodeBType, a->intValue, lvl);
	}
	else
	{
		if(a->NodeBType == 1)
		{
			printf("(%d) Char:%c\t LEVEL_%d\n",a->NodeBType, a->charValue, lvl);
		}
		else{
			printf("(%d) %s\t LEVEL_%d\n",a->NodeBType, a->name, lvl);
		}
	}
	if(a->l != 0)
	{
		printTable(a->l, lvl+1);	
	}
	if(a->r != 0)
	{
		printTable(a->r, lvl+1);	
	}
	
	if(a->m != 0)
	{
		printTable(a->m, lvl+1);	
	}
	
	if(a->x != 0)
	{
		printTable(a->x, lvl+1);	
	}
}

void printheadB()
{
	printNodeB(headB);
}

void printNodeBHead()
{
	if(headB != NULL)
	{
		if(headB->name != NULL)
		{
			printf("\n");
			printf("NodeB: %s\n",headB->name);
			printf("Type: %d\n",headB->NodeBType);
			printf("Int Value: %d\n",headB->intValue);
			printf("String Value: %s\n",headB->stringValue);
			printf("Char Value: %d\n",headB->charValue);
			printf("L Pointer: %d\n",headB->l);
			printf("R Pointer: %d\n",headB->r);
			printf("M Pointer: %d\n",headB->m);
			printf("X Pointer: %d\n",headB->x);
			printf("\n");
		}
	}
	else
	{
		printf("NO HEAD\n");
	}
}

void printNodeBHeadTable()
{
	int lvl = 0;
	printf("(Node Type: %d) %s\t LEVEL_%d\n",headB->NodeBType, headB->name, lvl);
	
	if(headB->l != 0)
	{
		printTable(headB->l, lvl+1);	
	}
	if(headB->r != 0)
	{
		printTable(headB->r, lvl+1);	
	}
	
	if(headB->m != 0)
	{
		printTable(headB->m, lvl+1);	
	}
	
	if(headB->x != 0)
	{
		printTable(headB->x, lvl+1);	
	}
}

void printTableau(struct NodeB * a, int lvl)
{
	for(int i = 0; i < lvl; i++)
	{
		printf("\t");
	}
	
	if(a != NULL || a != 0)
	{
		switch(a->NodeBType) 
		{
			case 211 :
				printf("int\n" );
			break;
			case 212 :
				printf("char\n" );
			break;
			case 500 :
				printf("%s\n",a->name );
			break;
			
			case 300 :
				printf(";\n");
			break;
			
			case 303 :
				printf("Read\n");
			break;
			
			case 304 :
				printf("Write\n");
			break;
			
			case 401 :
				printf("NUM(%d)\n",a->intValue);
			break;
			
			case 403 :
				printf("=\n");
			break;
			
			case 404 :
				printf("Array = expr\n");
			break;
			
			case 102 :
				printf("/\n");
			break;
			
			case 103 :
				printf("*\n");
			break;
			
			case 104 :
				printf("-\n");
			break;
			
			case 105 :
				printf("+\n");
			break;
			
			case 502 :
				printf("Parentheis\n");
			break;
			
			case 504 :
				printf("(id)[ExprList]\n");
			break;
			
			default :
				printf("\n" );
		}
	}
	
	if(a->l != 0)
	{
		printTableau(a->l, lvl+1);	
	}
	if(a->r != 0)
	{
		printTableau(a->r, lvl+1);	
	}
	
	if(a->m != 0)
	{
		printTableau(a->m, lvl+1);	
	}
	
	if(a->x != 0)
	{
		printTableau(a->x, lvl+1);	
	}
}















 