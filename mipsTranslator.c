#include <stdio.h>
#include <stdlib.h>

char * strings;
char * variables;
char * instructions;
FILE *fp;
int stringCounter = 0;

char* concat(const char *s1, const char *s2)
{
	if(s1 != NULL && s2 != NULL){
		char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
		// in real code you would check for errors in malloc here
		strcpy(result, s1);
		strcat(result, s2);
		//free(s1);
		//free(s2);
		printf("*************both*****************\n%s\n", result);
		return result;
	}
	
	if(s1 != NULL && s2 == NULL){
		char *result = malloc(strlen(s1) + 1); // +1 for the null-terminator
		// in real code you would check for errors in malloc here
		strcpy(result, s1);
		//free(s1);
		//free(s2);
		printf("************s1******************\n%s\n", result);
		return result;
	}
	
	if(s1 == NULL && s2 != NULL){
		char *result = malloc(strlen(s2) + 1); // +1 for the null-terminator
		// in real code you would check for errors in malloc here
		strcpy(result, s2);
		//free(s1);
		//free(s2);
		printf("**************s2****************\n%s\n", result);
		return result;
	}
	return " ";
}

//0 int, 1 char, 2 intArr, 3 charArr, 4 int function, 5 char function 
/*char 1 bytes, int 4 bytes(word)*/
void addVariables(char * name, int type, int arrSize)
{
	char * t;
	int arrSizex4= arrSize*4;
	char arrSizeX[100];
	switch(type) 
	{
	   case 0:
			t = concat(name, ": .word #integer variable\n");
			variables = concat(variables, t);
		  break;
		
	   case 1:
			t = concat(name,": .byte #character variable\n");
			variables = concat(variables, t);
		break; 
		
		case 2:
			t = concat(name,": .space ");
			//arrSizeX = arrSizex4 + '0';
			sprintf(arrSizeX, "%d", arrSizex4);
			t = concat(t, arrSizeX );
			t = concat(t," #integer array\n");
			variables = concat(variables, t);
		break; 
		
		case 3:
			t = concat(name,": .space ");
			//arrSizeX = arrSizex4 + '0';
			sprintf(arrSizeX, "%d", arrSize);
			t = concat(t, arrSizeX );
			t = concat(t," #character array\n");
			variables = concat(variables, t);
		break; 
		
		/*case 10://message1: .asciiz "Word or character(s)..."
			strings = concat(strings, name);
			strings = concat(strings, ": .asciiz ");
			strings = concat(strings, liString);
			strings = concat(strings, "\n");
		break;
		
		case 11:
			t = concat(name,": .byte #literal character\n");
			t = concat(t,litChar[1]);
			variables = concat(variables, t);
		break;*/
		
		default:
			printf("Error converting ID %s into MIPS code\n", name);
		break;
	}
}

void addLitString(char * arr)
{
	/*
		010 LITCHAR
		011 LITSTRING
	*/
	
}

void addDotData()
{
	variables = concat(variables, ".data\n");
	//printf("Testing>> %s\n", variables);
}

void addStart()
{
	instructions = concat(instructions, ".text\n.globl main\n.ent main\nmain:\n" );
}

void addEnd()
{
	instructions = concat( instructions, "\nli $v0, 10 			# parameter call code for terminate\nsyscall\n.end main");
}

void printAllStrings()
{
	printf("\n___________________FINAL_OUTPUT:_______________\n");
	if(strings != NULL || strings != 0){
		printf("%s\n",strings);}
	if(variables != NULL || variables != 0){
		printf("%s\n",variables);}
	if(instructions != NULL || instructions != 0){
		printf("%s\n",instructions);}
}

void write2File()
{
	char * all = NULL;
	all= concat(all, strings);
	all = concat(all, variables);
	all = concat(all, instructions);
	printf("\n\n\n\nPRINTING>>>\n%s\n", all);
	fp = fopen("mips.asm", "w+");
	if (fp == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	
	if(all != NULL || all != 0)
	{
		//printf("PRINTING>>>\n%s\n", all);
		fputs(all, fp);
	}
	//fputs("This is testing for fputs...\n", fp);
	fclose(fp);
}

int main()
{
	addDotData();
	addStart();
	addVariables("FakeInt",0,0);
	addVariables("FakeChar",1,0);
	addVariables("FakeIntArr",2,5);
	addVariables("FakeCharArr",3,5);

	addEnd();
	printAllStrings();
	write2File();
	return 0;
	
}


