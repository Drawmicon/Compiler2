 #include <stdio.h>
 #include "symTab4v.h"
 /*#include "BisonFun5v.h"*/
 #include <time.h> 
  
 extern FILE *yyin;
 #define YYERROR_VERBOSE

int main(int argc, char** argv)  
{ 
  printf("Welcome to my compiler:\n");
  clock_t begin = clock(); 
  double time_spent  = 0.0; 
  // open a file handle to a particular file:
  if(argc > 1){
    if(!(yyin = fopen(argv[1],"r"))){  
      perror(argv[1]);
      return(1);
    }
  }
  // lex through the input:
  //while(yylex()); 
  printf("\nParsing:\n\n");  
	   
  //return yyparse();  
  yyparse();
  
   printf("\n*************************PRINTING SYMBOL TABLE************************************************\n");
  printAll();
 
  printf("****************************AST*********************************************\n"); 
  //printTable(headB, 0);
  //printNodeB(headB);  
  //printNodeBHead();   
  //printNodeB(headB->l); 
  printNodeBHeadTable(); 
  //printf("****************************FILE OUTPUT*********************************************\n");
  //printFile();
	clock_t end = clock();
	time_spent += (double) (end-begin)/CLOCKS_PER_SEC; 
	
	printf("***********************TIME ELAPSED****************************\n\t\t\t\t\t%f s", time_spent);
	
	return 0;
}

void yyerror(const char *s){

   printf(">>> error: %s\n",s);
}