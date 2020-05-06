/*Semantic Analyzer*/
/*#include "definitions0.h"*/

/*
	struct Node//generic node
	{
		int nodeType;//type number
		int intValue;
		char * stringValue;
		char charValue;
		char * name;//char string name
		struct node *l;//left
		struct node *m;//middle
		struct node *r;//right
		struct node *x;//extra
	};
*/
/*
int verifyType(struct node * one, char * name)
{
	//return type number
	//struct node * getNode(char * name, char * scope)
	struct node t = getNode(name, "Globl");
	if(t.type == one.type)
	{
		return t.type;
	}
	//error = -1
	return -1;
}

char * verifyTypeString(struct node * one, char * name)
{
	//return type name
	switch(verifyType(one, name))
	{
		case 0:
			return "int";
		break;
		case 1:
			return "char";
		break;
	}
	return "ERROR";
	
}

int typeCheck(struct Node * one, struct Node * two)
{
	if(one.nodeType == two.nodeType)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int findID(struct Node * one)
{
	//attatch symbol table pointer to syntax tree
	return -1;
}

int math(struct Node * one, struct Node * two, int operator)
{
	int answer = -1;
	if(verifyType(one, one.type) == verifyType(one, one.type))
	{
		switch(operator)
		{
			case 1:
				//
			break;
		}
		
	}
	return answer;
}

void removeQuotes(char * value)
{
	//shift chars over by one	
	//add /0 at end
}

//struct node * getNode(char * name, char * scope)
int checkID(struct Node * one)
{
	if(getNode(one.name) != -1)
	{
		return 1;
	}
	return -1;
}


int main()
{
	return 0;
}
*/