#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//https://www.tutorialspoint.com/data_structures_algorithms/doubly_linked_list_program_in_c.htm

/* node(char * name, int type, int numberValue, char charValue, int arraySize, int * intArray, char * charArray, 
struct node ** parameters, char * scopeName, struct node * up, struct node * down,struct node * next,struct node * prev)*/

typedef struct node {
	char name [100];
	int type;//0 int, 1 char, 2 intArr, 3 charArr, 4 int function, 5 char function
	int setEqualCounter;
	
	//data
	int numVal;
	char charVal;
	
	int arraySize;//default 1
	int * intArr;//array of int
	char * charArr;//array of char
	struct node ** parameters;//array of nodes
	
	char * scopeName;//default: global
	
	struct node* up;
	struct node* down;
    struct node* next; 
    struct node* prev; 
}node;

//this link always point to first Link
struct node *head = NULL;

//this link always point to last Link 
struct node *last = NULL;

struct node *current = NULL;

//create new scope, empty node with a scope name
struct node * newScope(char * scopeName)//VERIFIED
{
	printf("\tNew Scope:%s\n", scopeName);
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->scopeName = scopeName;
	if(head == NULL)
	{
		link->scopeName = scopeName;
		head = link;
		return link;
	}
	else
	{
		link->scopeName = scopeName;
		struct node *current = head;
		while(current->down != NULL)
		{
			current = current->down;
		}
		current->down = link;
		link->up = current;
		return link;
	}
}

//returns pointer to first node of a scope
struct node * moveToScope(char * scopeLoc)//VERIFIED
{
	struct node * current = head;
	if(current != NULL)
	{
		//for(current = head; current->scopeName != scopeLoc; current = current->down)
		for(int i = 0; i < numOfScopes(); i++)
		{
			if(current->scopeName == scopeLoc)
			{
				//printf("Current:%s\n", current->scopeName);
				return current;
			}
			else{
			current = current->down;}
			
		}
		//return NULL;
	}
	else
	{
		//printf("No scope defined, set to Global\n");
		return NULL;
	}
	
	return NULL;
}//**********************************

//return pointer of node, from name and scope name
struct node * getNode(char * name, char * scope)//VERIFIED
{
	struct node * here;
	
	here = moveToScope(scope);
	//printScopeRow(here);
	//printScopeRowNamed(scope);
	//printf("here:%s\n", here->scopeName);
	if(here == NULL)
	{
		printf("Scope does not exist\n");
		return NULL;
	}
	
	while(here != NULL || here != 0)
	{
		//printNode(here);
		//printf("\n");
		
		//if(here->name == name)
		if(strcmp(here->name, name) == 0)
		{
			//printf("%s FOUND!\n", name);
			return here;
		}
		here = here->next;
	}
	return NULL;
}

//return type of node, //0 int, 1 char, 2 intArr, 3 charArr, 4 int function, 5 char function
int getType(char * a, char * scope)
{
	/*int t = -1;
	struct node * b = getNode(a, scope);
	t = b->type;
	return t;*/
	
	if(a != NULL || a != 0)
	{
		//printf("...getting type of %s\n", a);
		struct node * b = getNode(a, scope);
		if(b != NULL || b != 0)
		{
			//printf("...returning type: %d\n",b->type);
			return b->type;
		}
		else 
		{
			//printf("Node not found\n");
			exit(0);
		}
	}
}

int getArrSize(char * a, char * scope)
{
	if(a != NULL || a != 0)
	{
		//printf("...getting type of %s\n", a);
		struct node * b = getNode(a, scope);
		if(b != NULL || b != 0)
		{
			//printf("...returning type: %d\n",b->type);
			return b->arraySize;
		}
		else 
		{
			//printf("Node not found\n");
			exit(0);
		}
	}
}

//return type of node, //0 int, 1 char, 2 intArr, 3 charArr, 4 int function, 5 char function
int checkType(char * a, char * scope, int compareType)
{
	int t = -1;
	struct node * b = getNode(a, scope);
	if(b != NULL || b != 0)
	{
		t = b->type;
		//printf("ID(%d) vs %d\n", t, compareType);
		if(((t%2) == 0) && ((compareType%2) == 0))
		{
			printf("Compatible Int Type");
			t = compareType;
		}
		
		if(((t%2) == 1) && ((compareType%2) == 1))
		{
			printf("Compatible Char Type");
			t = compareType;
		}
	}
	return t;
}

struct node * moveToEndOfScope(char * scopeLoc)
{
	struct node * ptr = moveToScope(scopeLoc);
	if(ptr != NULL)
	{
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
			printf("MoveToEndOfScope:%d\n", ptr);
		}
	}
	else{
	return NULL;}
	return ptr;
}

struct node * addToEndOfScope(struct node * x, char * scopeName)
{
	if(moveToEndOfScope(scopeName) != NULL)
	{
		struct node * ptr = moveToEndOfScope(scopeName);
		ptr->next = x;
		x->prev = ptr;
	}	
}

//is list empty
bool isEmpty() {
   return head == NULL;
}

//returns number of elements in of global scope
int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next){
      length++;
   }
	
   return length;
}

//returns number of scopes
int numOfScopes() {//VERIFIED
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->down){
      length++;
   }
	
   return length;
}

int scopeLength(struct node * p)//VERIFIED
{
	int counter = 0;
	if(p != NULL && p != 0)
	{
		while(p->next != NULL)
		{
			p = p->next;
			counter++;
		}
	}
	return counter;
}


//returns all elements from all scopes
int matrixLength() {//VERIFIED
	
   int length = 0;
   struct node *current = head;
	
	while(current != NULL)
	{
		length += scopeLength(current);
		current = current->down;
	}
   
   return length;
}

int arrayBound(struct node * a, char * scope)
{
	int t = -1;
	struct node * b = getNode(a, scope);
	t = b->arraySize;
	return t;
}

int idCounter(char * a, char * scope, int value)
{
	int t = -1;
	struct node * b = getNode(a, scope);
	if(b != NULL || b != 0)
	{
		t = b->setEqualCounter;
		t += value;
		b->setEqualCounter = t;
	}
	return t;
}
/*
int getIDCounter(struct node * a)
{
	return a->setEqualCounter;
}

void incrementIDCounter(struct node * a)
{
	a->setEqualCounter = a->setEqualCounter + 1;
}
*/
//insert link at the first location
void insertNode(char * name, int type, int numberValue, char charValue, int arraySize, int * intArray, char * charArray, struct node ** parameters, char * scopeName, struct node * up, struct node * down,struct node * next,struct node * prev) 
{
	struct node * current;
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   //link->name = name;
    strcpy(link->name, name);
	link->type = type;//0 int, 1 char, 2 intArr, 3 charArr, 4 function
	link->numVal = numberValue;
	link->charVal = charValue;
	
	link->setEqualCounter = 0;
	link->arraySize = arraySize;//default 1
	link->intArr = intArray;//array of int
	link->charArr = charArray;//array of char
	link->parameters = parameters;//array of nodes
	
	link->scopeName = scopeName;//default: global
	
	link->up = up;
	link->down= down;
    link->next = next; 
    link->prev = prev;
	
	//if head == NULL
   if(isEmpty()) {
      //make it the head link
	  head = newScope(scopeName);
      head->next = link;
   } else 
   {
	   current = moveToScope(scopeName);
	   if( current == NULL)//returns null if no scope is found
	   {
		   current = newScope(scopeName);
		   current->next = link;
	   }
	   else
	   {
		 while(current->next != NULL)  
		 {
			 current = current->next;
		 }
		 current->next = link;
	   }
      //update first prev link
      //head->prev = link;
   }

   //point it to old first link
   //link->next = head;
	
   //point first to new first link
   //head = link;
}

//insert link at the first location
void insertNodeArr(char * name, char * type, int numberValue, char charValue, int arraySize, char * scopeName) 
{
	struct node * current;
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   //link->name = name;
    strcpy(link->name, name);
	//link->type = type;//0 int, 1 char, 2 intArr, 3 charArr, 4 function
	if(type[0] == 'i')
   {
	   link->type = 2;//0 int, 1 char, 2 intArr, 3 charArr, 4 function
	   //printf("\n\tINT:%s",type);
   }
   
   if(type[0] == 'c')
   {
	   link->type = 3;//0 int, 1 char, 2 intArr, 3 charArr, 4 function
	   //printf("\n\tCHAR:%s",type);
   }
	link->numVal = numberValue;
	link->charVal = charValue;
	
	link->arraySize = arraySize;//default 1
	
	link->scopeName = scopeName;//default: global
	
	//if head == NULL
   if(isEmpty()) {
      //make it the head link
	  head = newScope(scopeName);
      head->next = link;
   } else 
   {
	   current = moveToScope(scopeName);
	   if( current == NULL)//returns null if no scope is found
	   {
		   current = newScope(scopeName);
		   current->next = link;
	   }
	   else
	   {
		 while(current->next != NULL)  
		 {
			 current = current->next;
		 }
		 current->next = link;
	   }
   }

}


//insert link at the first location//VERIFIED
struct node * insertNodeType(char * name, char * type, char * scopeName) //VERIFIED
{
	struct node * current;
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   //link->name = name;
   strcpy(link->name, name);
   
   //printf("\n\t%s TYPE!", type);// for some reason, it wont compare var type to "int" or "char" correctly
   if(type[0] == 'i')
   {
	   link->type = 0;//0 int, 1 char, 2 intArr, 3 charArr, 4 function
	   //printf("\n\tINT:%s",type);
   }
   
   if(type[0] == 'c')
   {
	   link->type = 1;//0 int, 1 char, 2 intArr, 3 charArr, 4 function
	   //printf("\n\tCHAR:%s",type);
   }
	//link->type = type;//0 int, 1 char, 2 intArr, 3 charArr, 4 function
	
	link->scopeName = scopeName;//default: global
	
	//if head == NULL
   if(isEmpty()) {
      //make it the head link
	  head = newScope(scopeName);
      head->next = link;
	  link->prev = head;
   } 
   else 
   {
	   current = moveToScope(scopeName);
	   if( current == NULL)//returns null if no scope is found
	   {
		   current = newScope(scopeName);
		   current->next = link;
		   link->prev = current;
	   }
	   else
	   {
		 while(current->next != NULL)  
		 {
			 current = current->next;
		 }
		 current->next = link;
		 link->prev = current;
	   }
      //update first prev link
      //head->prev = link;
   }
   
   printNode(link);
   
	return link;
}

//insert link at the first location//VERIFIED
struct node * insertNodeScope(char * name, int type, char * scopeName) //VERIFIED
{
	struct node * current;
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   //link->name = name;
    strcpy(link->name, name);
   
   /*if(type == "int" || type == "Int" || type == "INT")
   {
	   link->type = 0;//0 int, 1 char, 2 intArr, 3 charArr, 4 function
   }
   
   if(type == "char" || type == "Char" || type == "CHAR")
   {
	   link->type = 1;//0 int, 1 char, 2 intArr, 3 charArr, 4 function
   }*/
	link->type = type;//0 int, 1 char, 2 intArr, 3 charArr, 4 function
	
	link->scopeName = scopeName;//default: global
	
	//if head == NULL
   if(isEmpty()) {
      //make it the head link
	  head = newScope(scopeName);
      head->next = link;
	  link->prev = head;
   } 
   else 
   {
	   current = moveToScope(scopeName);
	   if( current == NULL)//returns null if no scope is found
	   {
		   current = newScope(scopeName);
		   current->next = link;
		   link->prev = current;
	   }
	   else
	   {
		 while(current->next != NULL)  
		 {
			 current = current->next;
		 }
		 current->next = link;
		 link->prev = current;
	   }
      //update first prev link
      //head->prev = link;
   }
   
   printNode(link);
   
	return link;
}

//insert link at the first location
struct node * insertNodeSimple(char * name, int type )
{
	//printf("\tNode Created: %s Type:%d\n", name, type);
	struct node * current;
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	//link->name = name;
	 strcpy(link->name, name);
	link->type = type;//0 int, 1 char, 2 intArr, 3 charArr, 4 function
	link->scopeName = "Global";
	printf("\tNode Created: %s Type:%d\n", link->name, link->type);
	
   if(isEmpty()) {
	   printf("\tSymbol Table is Empty\n");
      //make it the head link
	  current = newScope("Global");
	  
	  if(current == NULL)
	  {
		  printf("\tScope Global not found\n");
	  }
	  else
	  {
		  printf("\tScope Global found\n");
		  //printNodePointer(current);
	  }
	  //link->scopeName = "Global";
      current->next = link;
	  //printNodePointer(current);
   }
   else
   {
	   current = moveToScope("Global");
	   if( current == NULL)//returns null if no scope is found
	   {
		   current = newScope("Global");
		   current->next = link;
	   }
	   else
	   {
		 while(current->next != NULL)
		 {
			 current = current->next;
		 }
		 current->next = link;
	   }
      //update first prev link
      //head->prev = link;
   }

   //point it to old first link
   //link->next = head;
	
   //point first to new first link
   //head = link;
   
   //printNode(link);
   
   return link;
}

void deleteNode(struct node * a)
{
	(a->prev)->next = a->next;
	free(a);
}

//getNode(char * name, char * scope)
void deleteNodeNamed(char * name, char * scopeName)
{
	deleteNode(getNode(name, scopeName));
}

void printNode(struct node * a)//VERIFIED
{	
	if(a != NULL){
		if(a->name != NULL){
		//printf("\t*****************************************************\n[");
		printf("\t[%s]\n",a->name);
		printf("\tID set: %d times\n", a->setEqualCounter);
		if(a->type == 0)
		{
			printf("\t[INT]\n");
		}
		if(a->type == 1)
		{
			printf("\t[CHAR]\n");
		}
		if(a->type == 3)
		{
			printf("\t[CHAR ARR: %d]\n", a->arraySize);
		}
		if(a->type == 2)
		{
			printf("\t[INT ARR: %d]\n", a->arraySize);
		}
		//printf("\t[Scope:%s]\n\n",a->scopeName);
		if(a->arraySize > 1){
		printf("\t[Array Size:%d]\n\n",a->arraySize);}
		//printf("]\n\t*****************************************************\n");
		}
	}
	else{printf("\n\t\tPointer is NULL: %ld\n", a);}
	
}

void printNodePointer(struct node * a)//VERIFIED
{	
	//printf("printing node...\n");
	if(a != NULL){
	//printf("\t*****************************************************\n[");
	if(a->name != NULL){
		//printf("name...\n");
	printf("\t[%s]\n",a->name);}
	if(a->scopeName != NULL){
		//printf("scope...\n");
	printf("\t[Scope:%s]\t",a->scopeName);}
	if(a->up != NULL){
		//printf("up...\n");
	printf("\t[UP:%d]\t",a->up);}
	if(a->down != NULL){
	printf("\t[DOWN:%d]\t",a->down);}
	if(a->next != NULL){
	printf("\t[NEXT:%d]\t",a->next);}
	if(a->prev != NULL){
	printf("\t[PREV:%d]\t",a->prev);}
	//printf("]\n\t*****************************************************\n");
	}
	else{printf("\tNODE EMPTY\n");}
}

void printNamedNode(char * name, char * scope)//VERIFIED
{
	struct node * pty = getNode(name, scope);
	printf("\nPrintNamedNode:%d\n",pty);
	if(pty != NULL && pty !=  0)
	{	
		printNode(pty);
	}
}

void printScopeRow(struct node * a)//VERIFIED
{
	if(a != NULL)
	{
		//uses printNode
		printf("\n%s:\n", a->scopeName);
		while(a != NULL)
		{
			printNode(a);
			a = a->next;
			printf("\n");
		}
	}
	else
	{
		printf("Cannot Print Entire Scope\n");
	}
}

void printScopeRowNamed(char * scope)//VERIFIED
{
	if(moveToScope(scope) != NULL){
	printScopeRow(moveToScope(scope));
	}
}

void printAll()//VERIFIED
{
	//uses printScopeRow
	struct node * point = head;
	if(point != NULL)
	{
		//printNode(point);
		printf("\n\nTOTAL SYMBAL TABLE\n");
	
		while(point != NULL)
		{
			printScopeRow(point);
			point = point->down;
		}
		
		printf("\nEND OF TABLE\n\n\n");
	}
	else{
		printf("\tTable Empty\n");
	}
}

void printFile()
{
	FILE *f = fopen("symbolTablefile.txt", "w");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}

	/* print some text */
	//const char *text = "Write this to the file";
	//fprintf(f, "Some text: %s\n", text);
	struct node * point = head;
	if(point != NULL)
	{
		printNode(point);
		fprintf(f, "\tSYMBAL TABLE\n");
	
		while(point != NULL)
		{
			//printScopeRow(point);
			//******************************************************
			if(point != NULL)
			{
				//uses printNode
				fprintf(f,"\n%s:\n", point->scopeName);
				while(point != NULL)
				{
					//printNode(point);
					//******************************************************
					fprintf(f,"\t[%s]\n",point->name);
					if(point->type == 0)
					{
					fprintf(f,"\t[INT]\n");
					}
					if(point->type == 1)
					{
					fprintf(f,"\t[CHAR]\n");
					}
					fprintf(f,"\t[Scope:%s]\n\n",point->scopeName);					
					//******************************************************
					point = point->next;
				}
			}
			else
			{
				fprintf(f,"Cannot Print Entire Scope\n");
			}
			//******************************************************
			point = point->down;
		}
		
		fprintf(f, "\nEND OF TABLE\n\n\n");
	}
	else{
		fprintf(f,"\tTable Empty\n");
	}

	/* 
	//print integers and floats
	int i = 1;
	float py = 3.1415927;
	fprintf(f, "Integer: %d, float: %f\n", i, py);

	//printing single chatacters
	char c = 'A';
	fprintf(f, "A character: %c\n", c);
	*/
	fclose(f);
}

//int main ()
//{
	/*
	printNodePointer(head);
	printf("Number of Scopes: %d\n",numOfScopes());
	printAll();
	printf("Number of Scopes: %d\n",numOfScopes());
	struct node * ptr1 = insertNodeSimple("Test1", 0);
	struct node * ptr2 = insertNodeSimple("Test2", 1);
	printf("PRINTING NODE INFO:\n");
	printNodePointer(head);
	printNodePointer(ptr2);
	printNodePointer(getNode("Test1", "Global"));
	
	printf("Number of Scopes: %d\n",numOfScopes());
	printAll();*/
	/*
	printf("Number of Scopes:%d\n", numOfScopes());
	newScope("a");
	newScope("b");
	printf("Number of Scopes:%d\n", numOfScopes());
	newScope("c");
	newScope("d");
	printf("Number of Scopes:%d\n", numOfScopes());
	
	struct node * pointy = moveToScope("a");
	//printf("Address: %d\n", pointy);
	//printNodePointer(pointy);
	while(pointy != NULL)
	{
		printNodePointer(pointy);
		printf("\n------------------------\n");
		pointy = pointy->down;
	}
	pointy = moveToScope("d");
	
	printf("REVERSE\n");
	while(pointy != NULL)
	{
		printNodePointer(pointy);
		printf("\n------------------------\n");
		pointy = pointy->up;	
	}
	
	pointy = insertNodeScope("tester1",1,"a");
	pointy = insertNodeScope("tester2",1,"a");
	pointy = insertNodeScope("tester3",1,"a");
	pointy = insertNodeScope("tester4",1,"b");
	pointy = insertNodeScope("tester5",1,"b");
	printf("\n--------PRINT FROM NAME----------------\n");
	*/
	//printf("Scope Length: %d\n",scopeLength(moveToScope("c")));
	
	//printf("Total: %d\n", matrixLength());
	//printNode(getNode("tester2","a"));
	//printScopeRowNamed("b");
	//printAll();
	//printNamedNode("tester3", "a");
	/*
	pointy = insertNodeScope("tester1",1,"a");
	//printf("\n--------PRINT ROW----------------\n");
	//printScopeRow(moveToScope("a"));
	//printf("\n------------------------\n");
	//printScopeRow(pointy);
	//printf("\n------------------------\n");
	pointy = insertNodeScope("tester2",1,"b");
	//printf("\n------------------------\n");
	//printScopeRow(pointy);
	//printf("\n------------------------\n");
	pointy = insertNodeScope("tester3",1,"b");
	//printf("\n------------------------\n");
	pointy=moveToScope("b");
	printf("\n--------PRINT ROW----------------\n");
	printScopeRow(pointy);
	
	pointy=moveToScope("a");
	printf("\n--------PRINT ROW----------------\n");
	printScopeRow(pointy);
	//printf("\n------------------------\n");
	*/
	//printNodePointer(getNode("tester1","a"));
	//printScopeRow(pointy);
	//printScopeRowNamed("b");
	//return 0;
//}






















