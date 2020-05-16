#include <stdio.h>
#include <stdlib.h>

char * strings;
char * variables;
char * instructions;

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
	//free(s1);
	//free(s2);
	printf("******************************\n%s\n", result);
    return result;
}

//0 int, 1 char, 2 intArr, 3 charArr, 4 int function, 5 char function 
/*char 1 bytes, int 4 bytes(word)*/
void addVariables(char * name, int type, int arrSize)
{
	switch(type) 
	{
	   case 0:
			char t[] = name + ": .word #integer variable";
			variables = concat(t, variables);
		  break;
		
	   case 1:
			char t[] = name + ": .byte #character variable";
			variables = concat(t, variables);
		break; 
		
		case 2:
			char t[] = name + ": .space" + arrSize +" #integer array";
			variables = concat(t, variables);
		break; 
		
		case 3:
			char t[] = name + ": .space" + arrSize +" #character array";
			variables = concat(t, variables);
		break; 
		
		default:
			printf("Error converting ID %s into MIPS code\n", name);
		break;
	}
}

void addDotData()
{
	variables = concat(".data\n", variables);
}

void addStart()
{
	instructions = concat(".text\n.globl main\n.ent main\nmain:\n", instructions);
}


