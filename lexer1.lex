%{
#include <stdio.h>
#include <string.h>
#include "Parser_project.tab.h"

int DISPLAY_FLEX_OUTPUT = 1;

%}

%option noyywrap

%%

"int"     {if(DISPLAY_FLEX_OUTPUT) printf("%s TYPEINT\n", yytext); sscanf(yytext, "%s", yylval.type); return TYPE;}
"char"	  {if(DISPLAY_FLEX_OUTPUT) printf("%s TYPECHAR\n", yytext);sscanf(yytext, "%s", yylval.type);return TYPE;}
";"	      {if(DISPLAY_FLEX_OUTPUT) printf("%s SEMICOLON\n", yytext);return SEMI;}
"["	      {if(DISPLAY_FLEX_OUTPUT) printf("%s LEFT BRACKET\n", yytext);return LBRACK;}
"]"	      {if(DISPLAY_FLEX_OUTPUT) printf("%s RIGHT BRACKET\n\n", yytext);return RBRACK;}

[0-9]+    {if(DISPLAY_FLEX_OUTPUT)  printf("%s Number\n",yytext); yylval.i = atoi(yytext); return (NUM);}
"("	      {if(DISPLAY_FLEX_OUTPUT) printf("%s LEFT PARENTHESIS \n", yytext);return LPAR;}
")"	      {if(DISPLAY_FLEX_OUTPUT) printf("%s RIGHT PARENTHESIS\n\n", yytext);return RPAR;}
"{"	      {if(DISPLAY_FLEX_OUTPUT) printf("%s LEFT BRACE\n", yytext);return LBRACE;}
"}"	      {if(DISPLAY_FLEX_OUTPUT) printf("%s RIGHT BRACE\n", yytext);return RBRACE;}
"="       {if(DISPLAY_FLEX_OUTPUT) printf("%s EQUALS\n", yytext);return EQUALS;}
"+"       {if(DISPLAY_FLEX_OUTPUT) printf("%s ADD\n", yytext);return ADD;}
"*"       {if(DISPLAY_FLEX_OUTPUT) printf("%s MULTIPLY\n", yytext);return MULT;}
"/"       {if(DISPLAY_FLEX_OUTPUT) printf("%s DIVIDE\n", yytext);return DIV;}
"-"       {if(DISPLAY_FLEX_OUTPUT) printf("%s MINUS\n", yytext);return SUBS;}
"read"|"READ"|"Read"    {if(DISPLAY_FLEX_OUTPUT) printf("%s READ\n", yytext);return READ;}
"break"|"BREAK"|"Break"   {if(DISPLAY_FLEX_OUTPUT) printf("%s BREAK\n", yytext);return BREAK;}
"write"|"WRITE"|"Write"   {if(DISPLAY_FLEX_OUTPUT) printf("%s WRITE\n", yytext);return WRITE;}
"return"|"RETURN"|"Return"   {if(DISPLAY_FLEX_OUTPUT) printf("%s RETURN\n", yytext);return RETURN;}

[a-z][a-zA-Z0-9_]* {if(DISPLAY_FLEX_OUTPUT) printf("%s ID\n",yytext); sscanf(yytext, "%s", yylval.idname); return (ID);}

[ \t\n\r]+  { /* ignore white space */ }
.		  {printf("\nPeculiar input at line %d\n", yylineno); printf("INPUT:[%s]\n\n",yytext);}

%%
