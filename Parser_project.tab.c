/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "Parser_project.y" /* yacc.c:339  */

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
				return type; 
			}
			else
			{
				if((((getType(a->name, "Globl"))%2) == 1) && (type%2 == 1))
				{
					printf("%s (%d) is a compatible type (%d)\n", a->name, (getType(a->name, "Globl")), type);
					return type; 
				}
				else
				{
					printf("%s (%d) is an incompatible type (%d)\n", a->name, (getType(a->name, "Globl")), type);
					return -1;
				}
			}
		
			/*at = getType(a->name, "Globl");
			printf("CHECK TYPE ID(%d)\n", at);			
			 if((at == 0 && type%2 == 0) || (at == 2 && type%2 == 0) || (at == 4 && type%2 == 0))
			 {
				typeO = type;
				printf("%s is a compatible int type\n", a->name);
			 }
			 else
			 {			 
				if((at == 1 && type%2 == 1) || (at == 3 && type%2 == 1) || (at == 5 && type%2 == 1))
				{
					printf("%s is a compatible char type\n", a->name);
					typeO = type;
				}
				else
				{
					printf("%s (%d) is not a compatible %d type\n", a->name,at, type);
					return -1;
				}
			 }*/
			 
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
	

#line 272 "Parser_project.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Parser_project.tab.h".  */
#ifndef YY_YY_PARSER_PROJECT_TAB_H_INCLUDED
# define YY_YY_PARSER_PROJECT_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    ID = 259,
    CHAR = 260,
    TYPE = 261,
    ARRAY = 262,
    NUM = 263,
    LITCHAR = 264,
    LITSTRING = 265,
    IF = 266,
    ELSE = 267,
    WHILE = 268,
    RETURN = 269,
    BREAK = 270,
    READ = 271,
    WRITE = 272,
    LPAR = 273,
    RPAR = 274,
    LBRACK = 275,
    RBRACK = 276,
    LBRACE = 277,
    RBRACE = 278,
    SEMI = 279,
    EQUALS = 280,
    MULT = 281,
    ADD = 282,
    DIV = 283,
    SUBS = 284,
    MOD = 285,
    EQUAL = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 211 "Parser_project.y" /* yacc.c:355  */

  int i;
  double d;
  char c [3];
  char type [3];
  char idname[100] ;
  char arr [100];
  struct Node * fp;

#line 354 "Parser_project.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_PROJECT_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 371 "Parser_project.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  35
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  70

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   249,   249,   252,   253,   256,   274,   290,   293,   298,
     299,   302,   305,   308,   321,   344,   345,   348,   349,   351,
     390,   391,   392,   393,   394,   395,   396,   447,   478,   491,
     493,   513,   527,   528,   531,   532
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "ID", "CHAR", "TYPE", "ARRAY",
  "NUM", "LITCHAR", "LITSTRING", "IF", "ELSE", "WHILE", "RETURN", "BREAK",
  "READ", "WRITE", "LPAR", "RPAR", "LBRACK", "RBRACK", "LBRACE", "RBRACE",
  "SEMI", "EQUALS", "MULT", "ADD", "DIV", "SUBS", "MOD", "EQUAL",
  "$accept", "program", "VarDeclList", "VarDecl", "StmtList", "Stmt",
  "Expr", "Primary", "ExprList", "ExprListTail", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

#define YYPACT_NINF -29

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-29)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,     8,     3,    73,    -1,   -16,   -29,   -19,   -29,   -29,
      34,    14,     7,    34,   -29,    34,    73,    74,   -29,   -29,
      13,   -29,    49,    34,    81,    36,     5,     6,    88,    66,
      46,   -29,   -29,   -29,   -29,    34,    34,    34,    34,    34,
      10,    18,    19,    20,    93,   -29,    43,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,    -4,   -29,    -4,   -29,    35,    38,
      40,   -29,    23,   -29,    34,    34,    42,    93,    93,   -29
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     3,     0,     1,    28,    25,    18,
       0,     0,     0,     0,     9,    32,     7,     0,    17,     4,
       0,     5,    32,     0,     0,     0,    18,     0,     0,     0,
      34,     2,    33,     8,    15,     0,     0,     0,     0,     0,
       0,    25,     0,     0,    19,    16,     0,    13,    10,    11,
      12,    29,    35,    21,    20,    24,    22,    23,     0,    30,
       0,    31,     0,     6,     0,     0,     0,    26,    27,    14
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,    64,   -29,    53,   -29,    -3,   -29,    48,   -28
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    15,    16,    30,    18,    31,    32
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      17,    22,    52,     6,    20,     1,    23,    24,    21,    28,
      29,     7,     5,    17,    52,     8,    26,    27,    25,    42,
      44,    40,    35,     7,    37,    13,    39,     8,     9,    48,
      49,    58,    53,    54,    55,    56,    57,    13,     7,    59,
      60,    61,     8,     9,    66,    35,    36,    37,    38,    39,
       7,    62,    13,     7,     8,     9,    46,    41,     9,    63,
      47,    67,    68,    64,    13,    65,    69,    13,    19,    33,
      43,     0,    35,    36,    37,    38,    39,     7,     0,     0,
       0,     8,     9,     0,     0,    51,     0,    10,     0,    11,
      12,    13,    35,    36,    37,    38,    39,    14,    34,     0,
      35,    36,    37,    38,    39,    45,     0,    35,    36,    37,
      38,    39,    50,     0,    35,    36,    37,    38,    39,    35,
      36,    37,    38,    39
};

static const yytype_int8 yycheck[] =
{
       3,    20,    30,     0,    20,     6,    25,    10,    24,    12,
      13,     4,     4,    16,    42,     8,     9,    10,     4,    22,
      23,     8,    26,     4,    28,    18,    30,     8,     9,    24,
      24,    21,    35,    36,    37,    38,    39,    18,     4,    21,
      21,    21,     8,     9,    21,    26,    27,    28,    29,    30,
       4,     8,    18,     4,     8,     9,    20,     8,     9,    24,
      24,    64,    65,    25,    18,    25,    24,    18,     4,    16,
      22,    -1,    26,    27,    28,    29,    30,     4,    -1,    -1,
      -1,     8,     9,    -1,    -1,    19,    -1,    14,    -1,    16,
      17,    18,    26,    27,    28,    29,    30,    24,    24,    -1,
      26,    27,    28,    29,    30,    24,    -1,    26,    27,    28,
      29,    30,    24,    -1,    26,    27,    28,    29,    30,    26,
      27,    28,    29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    33,    34,    35,     4,     0,     4,     8,     9,
      14,    16,    17,    18,    24,    36,    37,    38,    39,    34,
      20,    24,    20,    25,    38,     4,     9,    10,    38,    38,
      38,    40,    41,    36,    24,    26,    27,    28,    29,    30,
       8,     8,    38,    40,    38,    24,    20,    24,    24,    24,
      24,    19,    41,    38,    38,    38,    38,    38,    21,    21,
      21,    21,     8,    24,    25,    25,    21,    38,    38,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    37,    37,    37,    37,    37,    37,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    39,    39,
      39,    39,    40,    40,    41,    41
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     2,     3,     6,     1,     2,     1,
       3,     3,     3,     3,     6,     2,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     1,     6,     6,     1,     3,
       4,     4,     0,     1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 249 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n\t\t\tAST starting: program\n");headB = nodeFun(200, "program", (yyvsp[-2].fp), (yyvsp[-1].fp), (yyvsp[0].fp), 0, "", 0, ' ',0);}
#line 1497 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 252 "Parser_project.y" /* yacc.c:1646  */
    {(yyval.fp) = nodeFun(201, "VarDeclList", 0, 0, 0, 0, "", 0, ' ',0);}
#line 1503 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 253 "Parser_project.y" /* yacc.c:1646  */
    {(yyval.fp) = nodeFun(201, "VarDeclList", (yyvsp[-1].fp), (yyvsp[0].fp), 0, 0, "", 0, ' ',0);}
#line 1509 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 256 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n VarDecl found\n\tID: %s (%s)\n", (yyvsp[-1].idname), (yyvsp[-2].type));    
												//check if node exists, if not, return 0/NULL
												//FLAW-- variables cant have same name, even if different type
												if(getNode((yyvsp[-1].idname), "Globl") == NULL || getNode((yyvsp[-1].idname), "Globl") == 0)
												{
													//if node doesnt exist, create node in symbol table
													struct node * temp = insertNodeType((yyvsp[-1].idname), (yyvsp[-2].type), "Globl"); 
													//create syntax tree nodes
													char * par = (yyvsp[-2].type);
													(yyval.fp) = nodeFun(202, "VarDecl", 0, 0, 0, 0, (yyvsp[-1].idname), 0, par[0], 0);		
												}
												else
												{
													printf("\n\tError: Duplicate Variable: %s\n",(yyvsp[-1].idname));
													exit(0);
												}											
											}
#line 1531 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 274 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n Array found \n"); 
												//create array node if not exist
												if(getNode((yyvsp[-4].idname), "Globl") == NULL)
												{
													insertNodeArr((yyvsp[-4].idname), (yyvsp[-5].type), -1, ' ', (yyvsp[-2].i) , "Globl");
													char * par = (yyvsp[-5].type);
													(yyval.fp) = nodeFun(203, "VarDecl", 0, 0, 0, 0, (yyvsp[-4].idname), (yyvsp[-2].i), par[0],0);
												}
												else
												{
													printf("\n\tError: Duplicate Variable: %s\n",(yyvsp[-4].idname));
													exit(0);
												}
											}
#line 1550 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 290 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n Stmt found \n");
												(yyval.fp) = nodeFun(213, "Stmt", (yyvsp[0].fp), 0, 0, 0, "", 0, ' ',0);
											}
#line 1558 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 293 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n Stmt StmtList found \n"); 
												(yyval.fp) = nodeFun(214, "Stmt", (yyvsp[-1].fp), (yyvsp[0].fp), 0, 0, "", 0, ' ',0);
											}
#line 1566 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 298 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n SEMI found \n");(yyval.fp) = nodeFun(300, "", 0, 0, 0, 0, "", 0, ' ',0);}
#line 1572 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 299 "Parser_project.y" /* yacc.c:1646  */
    { printf("\n WRITE CHAR %s found \n", (yyvsp[-1].c));
												(yyval.fp) = nodeFun(610, "", 0, 0, 0, 0, "", 0, (yyvsp[-1].c),0);
											}
#line 1580 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 302 "Parser_project.y" /* yacc.c:1646  */
    { printf("\n WRITE STRING found: %s \n", (yyvsp[-1].arr));
												(yyval.fp) = nodeFun(611, "", 0, 0, 0, 0, (yyvsp[-1].arr), 0, ' ',0);
											}
#line 1588 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 305 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n WRITE found \n");
												(yyval.fp) = nodeFun(304, "", (yyvsp[-1].fp), 0, 0, 0, "", 0, ' ',0);
											}
#line 1596 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 308 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n READ statement found \n");/*struct NodeB * t*/(yyval.fp) = nodeFun(303, "", 0, 0, 0, 0, (yyvsp[-1].idname), 0, ' ',0);
												if(getNode((yyvsp[-1].idname),"Globl") == NULL || getNode((yyvsp[-1].idname),"Globl") == 0)
												{
													printf("\t\tID (%s) does not exist\n",(yyvsp[-1].idname)); 
													exit(0);
												}
												else 
												{
													printf("\tID (%s) EXISTS\n", (yyvsp[-1].idname)); 
												}
	 
											}
#line 1613 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 321 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n READ statement found \n");/*struct NodeB * t*/(yyval.fp) = nodeFun(303, "", 0, 0, 0, 0, (yyvsp[-4].idname), 0, ' ',0);
												if(getNode((yyvsp[-4].idname),"Globl") == NULL || getNode((yyvsp[-4].idname),"Globl") == 0)
												{
													printf("\t\tID (%s) does not exist\n",(yyvsp[-4].idname)); 
													exit(0);
												}
												else 
												{
													//check if array index is between 0 and NUM-1
													//printf("%d < %d\n", (arrayBound($2,"Globl")), $4);
													if((arrayBound((yyvsp[-4].idname),"Globl"))  > (yyvsp[-2].i) &&(arrayBound((yyvsp[-4].idname),"Globl"))  > -1)
													{
														printf("\tID (%s) EXISTS\n", (yyvsp[-4].idname));
													}
													else
													{
														printf("%s is out of array bounds\n", (yyvsp[-4].idname));
														exit(0);
													}
												}
	 
											}
#line 1640 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 344 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n Expr found \n");(yyval.fp) = nodeFun(301, "", (yyvsp[-1].fp), 0, 0, 0, "", 0, ' ',0);}
#line 1646 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 345 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n RETURN found \n");(yyval.fp) = nodeFun(302, "", (yyvsp[-1].fp), 0, 0, 0, "", 0, ' ',0);}
#line 1652 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 348 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n Primary found\n");(yyval.fp) = nodeFun(400, "", (yyvsp[0].fp), 0, 0, 0, "", 0, ' ',0);}
#line 1658 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 349 "Parser_project.y" /* yacc.c:1646  */
    {/*printf("LITCHAR found\n");*/(yyval.fp) = nodeFun(010, "", 0, 0, 0, 0, "", 0, (yyvsp[0].c),0);}
#line 1664 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 351 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n Assignment found\n");
												/*FLAW ID CAN BE SET TO EQUAL ITSELT, WITHOUT ALERTING TO THE NULL ERROR*/
												struct NodeB * t = nodeFun(403, "", 0, (yyvsp[0].fp), 0, 0, (yyvsp[-2].idname), 0, ' ',0);
												if(getNode((yyvsp[-2].idname),"Globl") == NULL || getNode((yyvsp[-2].idname),"Globl") == 0)
												{ 
													printf("\t\tID (%s) does not exist\n",(yyvsp[-2].idname));
													exit(0);
												} 
												else 
												{
													/*Check if id is a variable or an array*/
													if(getType((yyvsp[-2].idname), "Globl") == 0 || getType((yyvsp[-2].idname), "Globl") == 1)
													{
														printf("\tID (%s) EXISTS\n", (yyvsp[-2].idname));
														
														//printf("INcrement counter\n");
														printf("%d\n",idCounter((yyvsp[-2].idname),"Globl",1));
														//printf("counter INcremented \n");
													}
													else
													{
														printf("\t\tID (%s) is not non-array variable type\n",(yyvsp[-2].idname)); 
														exit(0);
													}
												}
												/*###############################################*/
												int tyTemp = getType((yyvsp[-2].idname), "Globl");
												printf("\tID (%s) type: \n",(yyvsp[-2].idname), tyTemp);
												int tyTemp2 = checkTypeRecursion(t, getType((yyvsp[-2].idname), "Globl"));
												printf("checkTypeRecursion: %d\n", tyTemp2);
												if( tyTemp2 == -1) 
												{
													printf("\t\t\t%s set to equal an incompatible expression!\n", (yyvsp[-2].idname));
													exit(0);
												}
												(yyval.fp) = t;
												/*###############################################*/
												
											}
#line 1708 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 390 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n Addition found\n");(yyval.fp) = nodeFun(402, "", (yyvsp[-2].fp), 0, (yyvsp[0].fp), 0, "ADD", 0, ' ',0);}
#line 1714 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 391 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n Mult found\n");(yyval.fp) = nodeFun(402, "", (yyvsp[-2].fp), 0, (yyvsp[0].fp), 0, "MULT", 0, ' ',0);}
#line 1720 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 392 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n Sub found \n");(yyval.fp) = nodeFun(402, "", (yyvsp[-2].fp), 0, (yyvsp[0].fp), 0, "SUBS", 0, ' ',0);}
#line 1726 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 393 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n Sub found \n");(yyval.fp) = nodeFun(402, "", (yyvsp[-2].fp), 0, (yyvsp[0].fp), 0, "MOD", 0, ' ',0);}
#line 1732 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 394 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n Div found\n");(yyval.fp) = nodeFun(402, "", (yyvsp[-2].fp), 0, (yyvsp[0].fp), 0, "DIV", 0, ' ',0);}
#line 1738 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 395 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n Number found: %d\n", (yyvsp[0].i));(yyval.fp) = nodeFun(401, "", 0, 0, 0, 0, "", (yyvsp[0].i), ' ',0);}
#line 1744 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 396 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n ID expression found\n");struct NodeB * tt = nodeFun(404, "", 0, (yyvsp[-3].i), (yyvsp[0].fp), 0, (yyvsp[-5].idname), 0, ' ',0);																							
												/*check if ID exists in symbol table*/
												if(getNode((yyvsp[-5].idname),"Globl") == NULL || getNode((yyvsp[-5].idname),"Globl") == 0)
												{
													printf("\t\tID (%s) does not exist\n",(yyvsp[-5].idname)); 
													exit(0);
												}
												else
												{
													/*Check if id is array*/
													if(getType((yyvsp[-5].idname), "Globl") == 2 || getType((yyvsp[-5].idname), "Globl") == 3)
													{
														printf("\tID (%s) EXISTS\n", (yyvsp[-5].idname)); 
														printf("INcrement counter\n");
														printf("%d\n",idCounter((yyvsp[-5].idname),"Globl",1));
														printf("counter INcremented \n");
														
														//check if ID array is in bounds
														if((arrayBound((yyvsp[-5].idname),"Globl"))  > (yyvsp[-3].i) &&(arrayBound((yyvsp[-5].idname),"Globl"))  > -1)
														{
															printf("\tID (%s) EXISTS\n", (yyvsp[-5].idname));
														}
														else
														{
															printf("%s is out of array bounds\n", (yyvsp[-5].idname));
															exit(0);
														}
															
													}
													else
													{
														printf("\t\tID (%s) is not an array\n",(yyvsp[-5].idname)); 
														exit(0);
													}
												}
												/*Check if first expression is a number*/
												
												/*check if second expression is same type as ID*/
												int x = getType((yyvsp[-5].idname), "Globl");
												/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
												int tyTemp = getType((yyvsp[-5].idname), "Globl");
												printf("\tID (%s) type: \n",(yyvsp[-5].idname), tyTemp);
												int tyTemp2 = checkTypeRecursion(tt, getType((yyvsp[-5].idname), "Globl"));
												printf("checkTypeRecursion: %d\n", tyTemp2);
												if( tyTemp2 == -1) 
												{
													printf("\t\t\t%s set to equal an incompatible expression!\n", (yyvsp[-5].idname));
													exit(0);
												}
												(yyval.fp) = tt;
											}
#line 1800 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 447 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n ID expression found\n");(yyval.fp) = nodeFun(404, "", 0, (yyvsp[-3].fp), (yyvsp[0].fp), 0, (yyvsp[-5].idname), 0, ' ',0);
																							
												/*check if ID exists in symbol table*/
												if(getNode((yyvsp[-5].idname),"Globl") == NULL || getNode((yyvsp[-5].idname),"Globl") == 0)
												{
													printf("\t\tID (%s) does not exist\n",(yyvsp[-5].idname)); 
													exit(0);
												}
												else
												{
													/*Check if id is array*/
													if(getType((yyvsp[-5].idname), "Globl") == 2 || getType((yyvsp[-5].idname), "Globl") == 3)
													{
														printf("\tID (%s) EXISTS\n", (yyvsp[-5].idname)); 
														printf("INcrement counter\n");
														printf("%d\n",idCounter((yyvsp[-5].idname),"Globl",1));
														printf("counter INcremented \n");
													}
													else
													{
														printf("\t\tID (%s) is not an array\n",(yyvsp[-5].idname)); 
														exit(0);
													}
												}
												/*Check if first expression is a number*/
												
												/*check if second expression is same type as ID*/
												int x = getType((yyvsp[-5].idname), "Globl");
											}
#line 1834 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 478 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n ID found: %s\n", (yyvsp[0].idname));(yyval.fp) = nodeFun(501, "", 0, 0, 0, 0, (yyvsp[0].idname), 0, ' ',0);
												//printScopeRowNamed("Globl");
												//printf("%ld", getNode($1,"Globl"));
												if(getNode((yyvsp[0].idname),"Globl") == NULL || getNode((yyvsp[0].idname),"Globl") == 0)
												{
													printf("\t\tID (%s) does not exist\n",(yyvsp[0].idname)); 
													exit(0);
												}
												else
												{
													printf("\tID (%s) EXISTS\n", (yyvsp[0].idname)); 
												}
											}
#line 1852 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 491 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n Expression parentheses found\n");(yyval.fp) = nodeFun(502, "", (yyvsp[-1].fp), 0, 0, 0, "", 0, ' ',0);}
#line 1858 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 493 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n Array expression found\n");(yyval.fp) = nodeFun(504, "", 0, (yyvsp[-1].i), 0, 0, (yyvsp[-3].idname), 0, ' ',0);
											if(getNode((yyvsp[-3].idname),"Globl") == NULL || getNode((yyvsp[-3].idname),"Globl") == 0)
											{
												printf("\t\tID (%s) does not exist\n",(yyvsp[-3].idname)); 
												exit(0);
											}
											else
											{
												if((arrayBound((yyvsp[-3].idname),"Globl"))  > (yyvsp[-1].i) &&(arrayBound((yyvsp[-3].idname),"Globl"))  > -1)
												{
													printf("\tID (%s) EXISTS\n", (yyvsp[-3].idname));
												}
												else
												{
													printf("%s is out of array bounds\n", (yyvsp[-3].idname));
													exit(0);
												}
											}	
										}
#line 1882 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 513 "Parser_project.y" /* yacc.c:1646  */
    {printf("\n Array expression found\n");(yyval.fp) = nodeFun(504, "", 0, (yyvsp[-1].fp), 0, 0, (yyvsp[-3].idname), 0, ' ',0);
											//check if node exists
											if(getNode((yyvsp[-3].idname),"Globl") == NULL || getNode((yyvsp[-3].idname),"Globl") == 0)
											{
												printf("\t\tID (%s) does not exist\n",(yyvsp[-3].idname)); 
												exit(0);
											}
											else
											{
												printf("\tID (%s) EXISTS\n", (yyvsp[-3].idname)); 
											}	
										}
#line 1899 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 527 "Parser_project.y" /* yacc.c:1646  */
    {(yyval.fp) = nodeFun(700, "", 0, 0, 0, 0, "", 0, ' ',0);}
#line 1905 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 528 "Parser_project.y" /* yacc.c:1646  */
    {(yyval.fp) = nodeFun(700, "", (yyvsp[0].fp), 0, 0, 0, "", 0, ' ',0);}
#line 1911 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 531 "Parser_project.y" /* yacc.c:1646  */
    {(yyval.fp) = nodeFun(217, "", (yyvsp[0].fp), 0, 0, 0, "", 0, ' ',0);}
#line 1917 "Parser_project.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 532 "Parser_project.y" /* yacc.c:1646  */
    {(yyval.fp) = nodeFun(218, "", (yyvsp[-1].fp), (yyvsp[0].fp), 0, 0, "", 0, ' ',0);}
#line 1923 "Parser_project.tab.c" /* yacc.c:1646  */
    break;


#line 1927 "Parser_project.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 535 "Parser_project.y" /* yacc.c:1906  */







