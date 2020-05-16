#include <stdio.h>
#include <stdlib.h>

char * strings;
char * variables;
char * instructions;
FILE *fp;

char* concat(const char *s1, const char *s2)
{
	if(s1 != NULL && s2 != NULL){
		char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
		// in real code you would check for errors in malloc here
		strcpy(result, s1);
		strcat(result, s2);
		//free(s1);
		//free(s2);
		printf("******************************\n%s\n", result);
		return result;
	}
	
	if(s1 != NULL && s2 == NULL){
		char *result = malloc(strlen(s1) + 1); // +1 for the null-terminator
		// in real code you would check for errors in malloc here
		strcpy(result, s1);
		//free(s1);
		//free(s2);
		printf("******************************\n%s\n", result);
		return result;
	}
	
	if(s1 == NULL && s2 != NULL){
		char *result = malloc(strlen(s2) + 1); // +1 for the null-terminator
		// in real code you would check for errors in malloc here
		strcpy(result, s2);
		//free(s1);
		//free(s2);
		printf("******************************\n%s\n", result);
		return result;
	}
	return " ";
}

//0 int, 1 char, 2 intArr, 3 charArr, 4 int function, 5 char function 
/*char 1 bytes, int 4 bytes(word)*/
void addVariables(char * name, int type, int arrSize)
{
	char * t;
	char arrSizeX;
	switch(type) 
	{
	   case 0:
			t = concat(name, ": .word #integer variable");
			variables = concat(variables, t);
		  break;
		
	   case 1:
			t = concat(name,": .byte #character variable");
			variables = concat(variables, t);
		break; 
		
		case 2:
			t = concat(name,": .space ");
			arrSizeX = (arrSize*4) + '0';
			t = concat(t, arrSizeX );
			t = concat(t," #integer array");
			variables = concat(variables, t);
		break; 
		
		case 3:
			t = concat(name,": .space ");
			arrSizeX = (arrSize) + '0';
			t = concat(t, arrSizeX );
			t = concat(t," #char array");
			variables = concat(variables, t);
		break; 
		
		default:
			printf("Error converting ID %s into MIPS code\n", name);
		break;
	}
}

void addDotData()
{
	variables = concat(variables, ".data\n");
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
	char * all;
	all= concat(all, strings);
	all = concat(all, variables);
	all = concat(all, instructions);
	fp = fopen("mips.asm", "w+");
	if(all != NULL || all != 0){
		fputs(fp, all);}
	//fputs("This is testing for fputs...\n", fp);
	fclose(fp);
}

int main()
{
	addDotData();
	addStart();
	addVariables("Fake",0,0);
	addEnd();
	printAllStrings();
	write2File();
	return 0;
	
}


