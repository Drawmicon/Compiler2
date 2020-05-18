#include <stdio.h>
#include <stdlib.h>

char * strings;
char * variables;
char * instructions;
FILE *fp;
int stringCounter = 0;

/*
	ERRORS:
		write '\n'; does not work, only write "\n";
		writing a string doesnt work if there are spaces in it
*/

char* concat(const char *s1, const char *s2)
{
	if(s1 != NULL && s2 != NULL){
		char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
		// in real code you would check for errors in malloc here
		strcpy(result, s1);
		strcat(result, s2);
		//free(s1);
		//free(s2);
		//printf("*************both*****************\n%s\n", result);
		return result;
	}
	
	if(s1 != NULL && s2 == NULL){
		char *result = malloc(strlen(s1) + 1); // +1 for the null-terminator
		// in real code you would check for errors in malloc here
		strcpy(result, s1);
		//free(s1);
		//free(s2);
		//printf("************s1******************\n%s\n", result);
		return result;
	}
	
	if(s1 == NULL && s2 != NULL){
		char *result = malloc(strlen(s2) + 1); // +1 for the null-terminator
		// in real code you would check for errors in malloc here
		strcpy(result, s2);
		//free(s1);
		//free(s2);
		//printf("**************s2****************\n%s\n", result);
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
			t = concat(name, ": .word 0  #integer variable\n");
			variables = concat(variables, t);
		  break;
		
	   case 1:
			t = concat(name,": .byte '_'  #character variable\n");
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

/*message1: .asciiz "Word or character(s)..."*/
void addWriteLitString(char * arr)//ERROR
{
	/*
		010 LITCHAR
		011 LITSTRING
	*/
	printf("\n\n\tCheckpoint: %s\n\n", arr);
	char * sName = "litString";
	printf("%s\n",sName);
	char sN [100];
	sprintf(sN, "%d", stringCounter);
	printf("%s\n",sN);
	sName = concat (sName, sN);
	printf("%s\n",sName);
	char * temp = "\n\nli $v0, 4\nla $a0, ";
	temp = concat(temp, sName);
	temp = concat(temp, "   #Print statment\nsyscall\n\n");
	
	instructions = concat(instructions, temp);
	
	strings = concat(strings, sName);
	strings = concat(strings, ": .asciiz ");
	strings = concat(strings, arr);
	strings = concat(strings, "\n");
	stringCounter++;
}

void addWriteLitChar(char * arr)
{
	/*
		010 LITCHAR
		011 LITSTRING
	*/
	char * temp = "\nli $a0,";
	temp = concat(temp, arr);
	temp = concat(temp,"\nli $v0, 11    # print_character\nsyscall\n\n");
	
	instructions = concat(instructions, temp);
}

void addReadID(char * id, int type)
{/*
	char * temp = "li $v0, 8 #get string from input\nmove $t0, $v0 #put string in $t0\nla $t1, (";
	temp = concat(temp, id);
	temp = concat(temp, ")    // load the address of original\nsw $t0, 0($t1)   // store that data at location of the original string");*/
	
	/*
		li $v0, 8
		la $a0, input
		li $a1, 1
		syscall
	*/
	if(type == 1)
	{
		char * temp = "\nli   $v0, 8   #Read 1 Character\nla $a0, ";
		temp = concat(temp, id);
		temp = concat(temp, "\nli $a1, 2\n syscall\n");
		/*temp = concat(temp, "\nsyscall# Read Character\nmove $t0, $v0\nsw	$t0,");
		temp = concat(temp, id);
		temp = concat(temp, "\n\n");*/
		instructions = concat(instructions, temp);
	}
	else
	{
		/*
			li $v0, 5
			syscall
			move $t0, $v0
			sw $t0, id
		*/
		if(type == 0)
		{
			char * temp = "\nli   $v0, 5\nsyscall# Read Integer\nmove $t0, $v0\nsw $t0, ";			
			temp = concat(temp, id);
			temp = concat(temp, "\n");
			instructions = concat(instructions, temp);
		}
		else
		{
			printf("\n\n\n\nError! Read ID %s not int or char!\n\n\n\n\n", id);

		}
	}
}

void addWriteIDArr(char * name)
{
	char * temp = "li $v0, 4  #Printing ID string\n la $a0, ";
	temp = concat(temp, name);
	temp = concat(temp, "\nsyscall\n");
	instructions = concat(instructions, temp);	
	/*
		{  //!!!!!!!!!!!!!!!!!!!!!!!!!!WRITE ID LBRACK RBRACK  SEMI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			int as = getArrSize($2, "Globl");
			addWriteIDArr($2);
		}										
		{ //!!!!!!!!!!!!!!!!!!!!!!!!!READ ID LBRACK RBRACK EQUALS LITSTRING SEMI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			int as = getArrSize($2, "Globl");
			addReadIDArrString($2, $6, as);
		}
	*/
}

void addReadIDArrString(char * name, char * text, int arrSize)
{
	char * temp =  "li $v0, 8   #read string into variable\nla $a0, ";
	temp = concat(temp, name);
	temp = concat(temp, "\nli $a1, ");
	temp = concat(temp, arrSize);
	temp = concat(temp, "\nsyscall\n");
	
}

void addReadIDArr(char * name, int type, int index)
{
	int indeX4 = index*4;
	char str[100];
	char str4[100];
	sprintf(str, "%d", index);// Now str contains the integer as characters
	sprintf(str4, "%d", indeX4);// Now str4 contains the integer as characters
	
	if(type == 0 || type == 2 )//int: .word(4 bytes)
	{
		char * temp = "\nli $v0, 5  #read int\nsyscall\nla $t3,";
		temp = concat(temp, name);
		temp = concat(temp, "\nmove $t0 $v0\nsw $t0, ");
		temp = concat(temp, str4);
		temp = concat(temp, "(");
		temp = concat(temp, "$t3");
		temp = concat(temp, ")   #store value into array at index\n");
		//temp = concat(temp, "# put address of list into $t3\nli $t2, 6  # put the index into $t2\nadd $t2, $t2, $t2    # double the index\nadd $t2, $t2, $t2    # double the index again (now 4x)\nadd $t1, $t2, $t3    # combine the two components of the address\nsw $t4, 0($t1)      # store the value into the array cell\n");
		instructions = concat(instructions, temp); 
	}
	else
	{
		if(type == 1 || type == 3)//char: .byte
		{
			char * temp = "\nli $v0, 5  #read char\nsyscall\nla $t3,";
			temp = concat(temp, name);
			temp = concat(temp, "\nmove $t0 $v0\nsw $t0, ");
			temp = concat(temp, str);
			temp = concat(temp, "(");
			temp = concat(temp, "$t3");
			temp = concat(temp, ")   #store value into array at index\n");
			instructions = concat(instructions, temp);
		}
		else
		{
			printf("\n\n\t\tError: ID addReadIDArr %s!!!\n", name);
		}
		
	}
	
}

void addWriteID(char * name, int type)//int0, char1
{
	if(type == 1)
	{
		char * temp = "li $v0, 4 #printing character variable\nla $a0, ";
		temp = concat(temp, name);
		temp = concat(temp, "\nsyscall\n\n");
		instructions = concat(instructions, temp);
	}
	else
	{
		if(type == 0)
		{
			char * temp = "li $v0, 1 #printing int variable\nlw $a0, ";
			temp = concat(temp, name);
			temp = concat(temp, "\nsyscall\n\n");
			instructions = concat(instructions, temp);
		}
		else
		{
			printf("\n\n\n\nERROR with writing variable %s in MIPS!\n\n\n\n", name);
		}
	}
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

void addEndMips()
{
	instructions = concat( instructions, "\nli $v0, 10 			# parameter call code for terminate\nsyscall\n.end main");
}

void printAllStringsMips()
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
	all = concat(all, variables);
	all= concat(all, strings);
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
/*
int main()
{
	addDotData();
	addStart();
	addVariables("FakeInt",0,0);
	addVariables("FakeChar",1,0);
	addVariables("FakeIntArr",2,5);
	addVariables("FakeCharArr",3,5);

	addEndMips();
	printAllStringsMips();
	write2File();
	return 0;
	
}
*/

