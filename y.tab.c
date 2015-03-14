/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PLUS = 258,
     SUB = 259,
     MULT = 260,
     DIV = 261,
     MOD = 262,
     EQUAL = 263,
     PROGRAM = 264,
     BEGIN_PROGRAM = 265,
     END_PROGRAM = 266,
     INTEGER = 267,
     ARRAY = 268,
     OF = 269,
     IF = 270,
     THEN = 271,
     ENDIF = 272,
     ELSE = 273,
     ELSEIF = 274,
     WHILE = 275,
     DO = 276,
     BEGINLOOP = 277,
     ENDLOOP = 278,
     BREAK = 279,
     CONTINUE = 280,
     EXIT = 281,
     READ = 282,
     WRITE = 283,
     AND = 284,
     OR = 285,
     NOT = 286,
     TRUE = 287,
     FALSE = 288,
     EQ = 289,
     NEQ = 290,
     LT = 291,
     GT = 292,
     LTE = 293,
     GTE = 294,
     SEMICOLON = 295,
     COLON = 296,
     COMMA = 297,
     QUESTION = 298,
     L_BRACKET = 299,
     R_BRACKET = 300,
     L_PAREN = 301,
     R_PAREN = 302,
     ASSIGN = 303,
     IDENT = 304,
     NUMBER = 305,
     COMMENT = 306,
     NEG = 307
   };
#endif
/* Tokens.  */
#define PLUS 258
#define SUB 259
#define MULT 260
#define DIV 261
#define MOD 262
#define EQUAL 263
#define PROGRAM 264
#define BEGIN_PROGRAM 265
#define END_PROGRAM 266
#define INTEGER 267
#define ARRAY 268
#define OF 269
#define IF 270
#define THEN 271
#define ENDIF 272
#define ELSE 273
#define ELSEIF 274
#define WHILE 275
#define DO 276
#define BEGINLOOP 277
#define ENDLOOP 278
#define BREAK 279
#define CONTINUE 280
#define EXIT 281
#define READ 282
#define WRITE 283
#define AND 284
#define OR 285
#define NOT 286
#define TRUE 287
#define FALSE 288
#define EQ 289
#define NEQ 290
#define LT 291
#define GT 292
#define LTE 293
#define GTE 294
#define SEMICOLON 295
#define COLON 296
#define COMMA 297
#define QUESTION 298
#define L_BRACKET 299
#define R_BRACKET 300
#define L_PAREN 301
#define R_PAREN 302
#define ASSIGN 303
#define IDENT 304
#define NUMBER 305
#define COMMENT 306
#define NEG 307




/* Copy the first part of user declarations.  */
#line 1 "mini_l.y"

/*Prologue: definitions of headers, types and variables used in actions*/
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>
#include <list>

// if there's a segfault, might be because we pass in a c.string into
// a function whose parameters are strings

using namespace std;

void yyerror (const char* msg);

/* need symbol table. can implement using a map struct */
map <string, int> symbol_table;
vector <string> ident_list;
vector<string> leader_list;
int label_ctr, temp_ctr, pred_ctr  = 0;
string tempName;
string tempVarName;
bool readFlag = false;
bool if_flag = false;//if you encounter an if statement, then you don't push the bool expression code onto milcode.

bool errorFound = false;
bool isArrayAccess = false;
int booleanOp = 0;
int iLeader = 0;
list<string> milcode;
list<string> tempCode;

string newTemp();
string newPred ();
string newLabel ();
string genExprCode ( string dst, string src1, string src2, string op );
bool compare (int lhs, int rhs, int boolOp);

extern int currLine;
extern int currPos; 
extern int yylex();
extern FILE * yyin;
extern char* yytext;

enum IDENT_TYPE
{
	TYPE_INT = 0,
	TYPE_ARRAY = 1
};
   



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 60 "mini_l.y"
{
    char* IntString;
    char* String;
    
    // struct attribute was here
    struct attribute
	{
		//char* name;
		char name [255];
		int type;
		int value;
		char* size;
		char* code;
	};

    
   struct attribute myAttri; 
}
/* Line 193 of yacc.c.  */
#line 277 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 290 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNRULES -- Number of states.  */
#define YYNSTATES  182

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    11,    17,    23,    29,    35,    39,
      43,    45,    49,    52,    55,    59,    62,    66,    69,    74,
      78,    82,    84,    88,    90,    91,    97,   102,   105,   109,
     114,   120,   125,   129,   137,   144,   150,   157,   160,   163,
     165,   167,   169,   170,   172,   174,   176,   178,   180,   182,
     184,   188,   190,   192,   194,   199,   201,   207,   211,   213,
     215,   221,   225,   227,   229,   231,   235,   237,   241,   246,
     249,   252,   257,   261,   263,   265,   269,   271,   273,   275,
     277,   279,   281,   283,   285,   289,   293,   297,   301,   305,
     307,   310,   313,   318,   320,   322
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    -1,     9,    49,    40,    56,    11,
      -1,     1,    49,    40,    56,    11,    -1,     9,    49,    40,
      56,     1,    -1,     9,     1,    40,    56,    11,    -1,     9,
      49,     1,    56,    11,    -1,    58,    57,    59,    -1,    58,
       1,    59,    -1,    10,    -1,    60,    40,    58,    -1,    60,
      40,    -1,    60,     1,    -1,    64,    40,    59,    -1,    64,
      40,    -1,    64,     1,    59,    -1,    64,     1,    -1,    61,
      41,    63,    12,    -1,    61,    63,    12,    -1,    62,    42,
      61,    -1,    62,    -1,    49,     1,    61,    -1,    49,    -1,
      -1,    13,    44,    50,    45,    14,    -1,    49,    50,    45,
      14,    -1,    13,    14,    -1,    13,    45,    14,    -1,    13,
      44,    50,    14,    -1,    13,    44,    50,    45,     1,    -1,
      13,    44,    50,     1,    -1,    74,    69,    84,    -1,    74,
      69,    80,    43,    84,    41,    84,    -1,    75,    80,    65,
      16,    76,    17,    -1,    66,    80,    67,    59,    23,    -1,
      68,    22,    59,    23,    20,    80,    -1,    70,    72,    -1,
      71,    72,    -1,    24,    -1,    25,    -1,    26,    -1,    -1,
      20,    -1,    22,    -1,    21,    -1,    48,    -1,     1,    -1,
      27,    -1,    28,    -1,    74,    73,    72,    -1,    74,    -1,
      42,    -1,    49,    -1,    49,    44,    84,    45,    -1,    15,
      -1,    59,    77,    80,    65,    78,    -1,    59,    79,    59,
      -1,    59,    -1,    19,    -1,    59,    77,    80,    65,    78,
      -1,    59,    79,    59,    -1,    59,    -1,    18,    -1,    81,
      -1,    81,    30,    80,    -1,    82,    -1,    82,    29,    81,
      -1,    31,    84,    83,    84,    -1,    31,    32,    -1,    31,
      33,    -1,    31,    46,    80,    47,    -1,    84,    83,    84,
      -1,    32,    -1,    33,    -1,    46,    80,    47,    -1,     1,
      -1,    34,    -1,    35,    -1,    36,    -1,    37,    -1,    38,
      -1,    39,    -1,    85,    -1,    84,     3,    85,    -1,    84,
       4,    85,    -1,    85,     5,    86,    -1,    85,     6,    86,
      -1,    85,     7,    86,    -1,    86,    -1,     4,    74,    -1,
       4,    50,    -1,     4,    46,    84,    47,    -1,    74,    -1,
      50,    -1,    46,    84,    47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   133,   133,   136,   152,   153,   154,   155,   158,   159,
     162,   165,   166,   167,   170,   171,   172,   173,   176,   213,
     218,   219,   220,   223,   245,   246,   247,   248,   249,   250,
     251,   252,   256,   276,   301,   309,   336,   345,   346,   347,
     348,   349,   355,   364,   378,   392,   401,   402,   405,   407,
     410,   411,   423,   435,   456,   463,   469,   485,   493,   496,
     498,   499,   507,   509,   511,   516,   528,   532,   543,   562,
     574,   586,   595,   605,   606,   607,   608,   611,   612,   613,
     614,   615,   616,   620,   625,   635,   646,   656,   665,   674,
     680,   690,   704,   714,   715,   719
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "\"%\"", "\"=\"", "PROGRAM", "BEGIN_PROGRAM", "END_PROGRAM", "INTEGER",
  "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "ELSEIF", "WHILE", "DO",
  "BEGINLOOP", "ENDLOOP", "BREAK", "CONTINUE", "EXIT", "READ", "WRITE",
  "AND", "OR", "NOT", "TRUE", "FALSE", "EQ", "NEQ", "LT", "GT", "LTE",
  "GTE", "\";\"", "\":\"", "\",\"", "\"?\"", "\"[\"", "\"]\"", "\"(\"",
  "\")\"", "\":=\"", "IDENT", "NUMBER", "COMMENT", "NEG", "$accept", "S",
  "program", "block", "bBEGIN_PROGRAM", "decl_loop", "stmt_loop",
  "declaration", "ident_loop", "iIDENT", "array_decl", "statement",
  "middle", "iWHILE", "iBEGINLOOP", "iDO", "assign", "iREAD", "iWRITE",
  "var_loop", "iCOMMA", "var", "if_", "if_body", "elseif_", "elseif_body",
  "else_", "bool_expr", "relation_and_expr", "relation_expr", "comp",
  "expr", "mult_expr", "term", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    55,    55,    55,    56,    56,
      57,    58,    58,    58,    59,    59,    59,    59,    60,    60,
      61,    61,    61,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    65,    66,    67,    68,    69,    69,    70,    71,
      72,    72,    73,    74,    74,    75,    76,    76,    76,    77,
      78,    78,    78,    79,    80,    80,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    83,
      83,    83,    83,    84,    84,    84,    85,    85,    85,    85,
      86,    86,    86,    86,    86,    86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     5,     5,     5,     5,     5,     3,     3,
       1,     3,     2,     2,     3,     2,     3,     2,     4,     3,
       3,     1,     3,     1,     0,     5,     4,     2,     3,     4,
       5,     4,     3,     7,     6,     5,     6,     2,     2,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     4,     1,     5,     3,     1,     1,
       5,     3,     1,     1,     1,     3,     1,     3,     4,     2,
       2,     4,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     1,
       2,     2,     4,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    21,     0,
       0,     0,     0,     4,     0,    10,     0,    13,    12,     0,
      24,     0,     0,     0,     6,     7,     5,     3,    22,    55,
      43,    45,    39,    40,    41,    48,    49,    53,     9,     0,
       0,     0,     0,     0,     0,     0,     8,    11,    27,     0,
       0,     0,     0,    19,    20,     0,    17,    15,    76,     0,
       0,    73,    74,     0,    94,    93,     0,    64,    66,     0,
      83,    89,     0,    37,    51,    38,    47,    46,     0,    42,
       0,    28,    18,     0,     0,     0,    16,    14,     0,    91,
      90,    69,    70,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,     0,
       0,     0,     0,     0,    52,     0,     0,    32,     0,    31,
      29,     0,    26,     0,    54,     0,     0,     0,    75,    95,
       0,    65,    67,    84,    85,    72,    86,    87,    88,     0,
      50,     0,     0,    30,    25,    92,    71,    68,    35,     0,
       0,    58,     0,    36,     0,    63,    59,     0,     0,    34,
      33,    42,    57,     0,    62,    56,     0,     0,    42,    61,
       0,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    14,    26,    15,   174,    16,    17,    18,
      32,    49,   128,    50,   108,    51,    88,    52,    53,    83,
     125,    75,    55,   162,   167,   175,   168,    76,    77,    78,
     119,    79,    80,    81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -63
static const yytype_int16 yypact[] =
{
      81,   -39,    11,    48,   -63,    33,    68,    32,   -63,    62,
      62,    62,    62,    12,    59,     6,    38,    66,    72,   134,
     135,    86,    62,   -63,   139,   -63,   139,   -63,    62,    80,
      63,   105,   146,    62,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   124,   -63,    43,
      19,   147,   121,   121,     8,    19,   -63,   -63,   -63,   122,
     157,   161,   129,   -63,   -63,    17,   139,   139,   -63,    77,
      60,   -63,   -63,    19,   -63,   -63,   153,   148,   150,   100,
      93,   -63,   139,   -63,   138,   -63,   -63,   -63,    19,   -63,
      26,   -63,   -63,   162,    17,    14,   -63,   -63,    17,   -63,
     -63,   -63,   -63,    19,   100,   130,    82,   -63,   139,    19,
      19,    17,    17,   -63,   -63,   -63,   -63,   -63,   -63,    17,
      17,    17,    17,   158,   -63,   121,   140,   100,   166,   -63,
     -63,    21,   -63,    27,   -63,    34,   137,    17,   -63,   -63,
     163,   -63,   -63,    93,    93,   127,   -63,   -63,   -63,   165,
     -63,    17,   139,   -63,   -63,   -63,   -63,   127,   -63,    19,
      92,    -4,   170,   -63,    17,   -63,   -63,    19,   139,   -63,
     127,   -63,   -63,   139,    -4,   -63,    19,   139,   -63,   -63,
     139,   -63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,   -63,   131,   -63,   164,   -20,   -63,    58,   -63,
     159,   -63,   -31,   -63,   -63,   -63,   -63,   -63,   -63,   -48,
     -63,   -24,   -63,   -63,    16,    13,    20,   -54,    85,   -63,
      87,   -62,    50,    30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -24
static const yytype_int16 yytable[] =
{
      54,    89,    54,    95,    48,    85,    56,    24,   104,    86,
       5,   106,     6,    22,   165,   166,    25,   111,   112,   105,
      68,    69,   153,    69,   -23,   -23,   127,   129,    84,    84,
     111,   112,   133,    11,   126,   154,   135,   111,   112,    27,
     130,   106,    54,    54,    66,   100,    96,    97,     8,   136,
      70,    71,    72,   -23,   -23,   141,    87,   145,    54,   134,
       7,   -23,   123,    94,    69,    73,    47,    74,    47,    74,
      23,   131,    12,     9,   139,   157,    29,   150,    28,    29,
      38,   155,     1,    67,    54,   111,   112,    36,   140,   160,
       2,    64,   101,   102,    58,   111,   112,    37,   120,   121,
     122,    84,   170,   111,   112,   163,   103,    30,    10,    47,
      74,    13,    31,   171,    33,    31,   113,   114,   115,   116,
     117,   118,   178,    98,    59,    60,    47,    99,    54,   139,
     111,   112,   161,   164,   113,   114,   115,   116,   117,   118,
     173,    19,    20,    21,    54,    34,    35,   180,   172,    54,
     146,   147,   148,    54,    39,    62,    54,   179,    63,    40,
      41,   143,   144,    42,    43,    44,    45,    46,    65,    82,
      47,    91,    90,    92,    93,   107,   132,   138,   109,   110,
     124,   149,   152,   151,   156,   159,   158,   169,    47,    61,
     176,   137,    57,   181,   177,   142
};

static const yytype_uint8 yycheck[] =
{
      24,    55,    26,    65,    24,    53,    26,     1,    70,     1,
      49,    73,     1,     1,    18,    19,    10,     3,     4,    73,
       1,     4,     1,     4,    12,    13,    88,     1,    52,    53,
       3,     4,    94,     1,    88,    14,    98,     3,     4,     1,
      14,   103,    66,    67,     1,    69,    66,    67,     0,   103,
      31,    32,    33,    41,    42,   109,    48,   119,    82,    45,
      49,    49,    82,    46,     4,    46,    49,    50,    49,    50,
      11,    45,    40,    40,    47,   137,    13,   125,    40,    13,
      22,    47,     1,    40,   108,     3,     4,     1,   108,   151,
       9,    33,    32,    33,    14,     3,     4,    11,     5,     6,
       7,   125,   164,     3,     4,   159,    46,    41,    40,    49,
      50,    49,    49,   167,    42,    49,    34,    35,    36,    37,
      38,    39,   176,    46,    44,    45,    49,    50,   152,    47,
       3,     4,   152,    41,    34,    35,    36,    37,    38,    39,
     171,    10,    11,    12,   168,    11,    11,   178,   168,   173,
     120,   121,   122,   177,    15,    50,   180,   177,    12,    20,
      21,   111,   112,    24,    25,    26,    27,    28,    44,    22,
      49,    14,    50,    12,    45,    22,    14,    47,    30,    29,
      42,    23,    16,    43,    47,    20,    23,    17,    49,    30,
     174,   104,    28,   180,   174,   110
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     9,    54,    55,    49,     1,    49,     0,    40,
      40,     1,    40,    49,    56,    58,    60,    61,    62,    56,
      56,    56,     1,    11,     1,    10,    57,     1,    40,    13,
      41,    49,    63,    42,    11,    11,     1,    11,    61,    15,
      20,    21,    24,    25,    26,    27,    28,    49,    59,    64,
      66,    68,    70,    71,    74,    75,    59,    58,    14,    44,
      45,    63,    50,    12,    61,    44,     1,    40,     1,     4,
      31,    32,    33,    46,    50,    74,    80,    81,    82,    84,
      85,    86,    22,    72,    74,    72,     1,    48,    69,    80,
      50,    14,    12,    45,    46,    84,    59,    59,    46,    50,
      74,    32,    33,    46,    84,    80,    84,    22,    67,    30,
      29,     3,     4,    34,    35,    36,    37,    38,    39,    83,
       5,     6,     7,    59,    42,    73,    80,    84,    65,     1,
      14,    45,    14,    84,    45,    84,    80,    83,    47,    47,
      59,    80,    81,    85,    85,    84,    86,    86,    86,    23,
      72,    43,    16,     1,    14,    47,    47,    84,    23,    20,
      84,    59,    76,    80,    41,    18,    19,    77,    79,    17,
      84,    80,    59,    65,    59,    78,    77,    79,    80,    59,
      65,    78
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 137 "mini_l.y"
    { printf("program -> PROGRAM IDENT SEMICOLON block END_PROGRAM\n"); /*cout << milCode;*/
	  
	  if (!errorFound)
	  {
			list <string>::iterator it;
	  
			for ( it = milcode.begin(); it != milcode.end(); ++it)
				cout << *it << endl;
			cout << " : EndLabel\n";
	  }
      else
      {
        cout << "error found! Will not print program!\n";
      }
	;}
    break;

  case 10:
#line 162 "mini_l.y"
    { milcode.push_back(" : START"); ;}
    break;

  case 14:
#line 170 "mini_l.y"
    { ;}
    break;

  case 15:
#line 171 "mini_l.y"
    { ;}
    break;

  case 18:
#line 177 "mini_l.y"
    { 	/* check if identifer in symbol table
	iterate through identifier list and search for it in map. if it's there,
	print out an error message. otherwise, add to symbol table.
	*/

	int size = ident_list.size();
		
	for (int i = 0; i < size; i++ )
	{
		string ident = ident_list[i];
		map <string, int>::iterator it = symbol_table.find (ident);
		
		// if ident isn't in symbol table and ident is an array
		// add to the symbol table.
		if (it == symbol_table.end() && (yyvsp[(3) - (4)].myAttri).type == TYPE_ARRAY )
		{
			symbol_table[ident] = TYPE_ARRAY;
			string arrSize = (yyvsp[(3) - (4)].myAttri).size;
			
			// generate milcode
			string newCode = "\t.[] _" +  ident + ", " + arrSize;
			milcode.push_back (newCode);
		}
		
		// if ident isn't in symbol table and ident is an int
		// add to the symbol table.	
		else if ( it == symbol_table.end() && (yyvsp[(3) - (4)].myAttri).type == TYPE_INT)
		{
			symbol_table[ident] = TYPE_INT;
			
			string newCode =  "\t. _" + ident;
			milcode.push_back (newCode);
		}
			
	}
;}
    break;

  case 19:
#line 214 "mini_l.y"
    {printf("Syntax error at line %d: invalid declaration\n", currLine);;}
    break;

  case 23:
#line 224 "mini_l.y"
    { 
				string ident = (yyvsp[(1) - (1)].String); 
				// check if ident is already in the symbol table
				map <string, int>::iterator it = symbol_table.find (ident);
				
				// if it isn't in symbol table, push ident onto list
				// of idents
				if ( it == symbol_table.end() )
					ident_list.push_back(ident);
				
				// otherwise, why are you redeclaring ident??!?! >:(	
				else
				{
				//	errorFound = true;
					cout << "Error at line " << currLine 
						 << ": redeclaration of '" << ident << "'\n";
				}	
			;}
    break;

  case 24:
#line 245 "mini_l.y"
    { (yyval.myAttri).type = TYPE_INT; ;}
    break;

  case 25:
#line 246 "mini_l.y"
    { (yyval.myAttri).type = TYPE_ARRAY; (yyval.myAttri).size = (yyvsp[(3) - (5)].IntString) ;}
    break;

  case 26:
#line 247 "mini_l.y"
    {printf("Invalid array declaration\n");;}
    break;

  case 27:
#line 248 "mini_l.y"
    { printf ("Invalid array declaration!\n"); ;}
    break;

  case 28:
#line 249 "mini_l.y"
    { printf ("Invalid array declaration!\n"); ;}
    break;

  case 29:
#line 250 "mini_l.y"
    { printf ("Invalid array declaration!\n"); ;}
    break;

  case 30:
#line 251 "mini_l.y"
    {;}
    break;

  case 31:
#line 252 "mini_l.y"
    {;}
    break;

  case 32:
#line 257 "mini_l.y"
    {

		    	string varName = (yyvsp[(1) - (3)].myAttri).name;
	    		string exprName = (yyvsp[(3) - (3)].myAttri).name;
			    //if variable is not in the symbol table, then this will
    			//immediately create the variable and assign value, which
	    		//is bad.
		    	symbol_table[varName] = (yyvsp[(3) - (3)].myAttri).value;
			  	
			string newCode = "\t= " + varName + ", " + exprName;
			/*if(!if_flag)
	    			milcode.push_back (newCode);		
			else
				tempCode.push_back(newCode);
			*/
			milcode.push_back(newCode);	

                
			;}
    break;

  case 33:
#line 277 "mini_l.y"
    {
				string varName = (yyvsp[(1) - (7)].myAttri).name;
				string boolexprName = (yyvsp[(3) - (7)].myAttri).name;
				
				string expr1Name = (yyvsp[(5) - (7)].myAttri).name;
				string expr2Name = (yyvsp[(7) - (7)].myAttri).name;
				string newCode = "";
				
				newCode = "\t= " + varName + ", " + expr1Name;
			/*	if(!if_flag)
	    				milcode.push_back (newCode);		
				else
					tempCode.push_back(newCode);
                   	*/
			milcode.push_back(newCode);			
				newCode = "\t= " + varName + ", " + expr2Name;
			/*	
				if(!if_flag)
	    				milcode.push_back (newCode);		
				else
					tempCode.push_back(newCode);
                */
			milcode.push_back(newCode);
			;}
    break;

  case 34:
#line 302 "mini_l.y"
    {	
			string label = " : " + leader_list.back();
			leader_list.pop_back();
			string boolExprName = (yyvsp[(2) - (6)].myAttri).name;

			milcode.push_back(label);
		;}
    break;

  case 35:
#line 310 "mini_l.y"
    {
			/*
			string predName = newPred();
			string newCode = "\t! " + predName + ", " + $2.name;
			
			
                	string labelName = newLabel();
			leader_list.push_back(labelName);
			newCode = " := " + labelName; 
			milcode.push_back (newCode);
			*/
			
			/* save the end label before popback */
			string endLabel = leader_list.back();
			leader_list.pop_back();
	

			/*print goto statement */
			string newCode = "\t:= " + leader_list.back();
			milcode.push_back(newCode);
			leader_list.pop_back();

			newCode = " : " + endLabel;
			milcode.push_back(newCode);
                
            	;}
    break;

  case 36:
#line 337 "mini_l.y"
    {
			string boolexprName = (yyvsp[(6) - (6)].myAttri).name;
			string label = leader_list.back();
			leader_list.pop_back();

			string newCode = "\t?:= " + label + ", " + boolexprName;
			milcode.push_back(newCode);
		;}
    break;

  case 37:
#line 345 "mini_l.y"
    {;}
    break;

  case 38:
#line 346 "mini_l.y"
    {;}
    break;

  case 39:
#line 347 "mini_l.y"
    {;}
    break;

  case 40:
#line 348 "mini_l.y"
    {;}
    break;

  case 41:
#line 350 "mini_l.y"
    {
			string newCode = "\t := EndLabel";
			milcode.push_back (newCode);
          	;}
    break;

  case 42:
#line 355 "mini_l.y"
    {	
		string predName = newPred();
		string label = leader_list.back();
		string newCode = "\t! " + predName + ", " + tempName;
		milcode.push_back(newCode);
		newCode = "\t?:= " + label + ", " + predName;
		milcode.push_back(newCode);
		;}
    break;

  case 43:
#line 365 "mini_l.y"
    {
		/* generate the start label*/
		string label = newLabel();
		leader_list.push_back (label);
		string newCode = " : " + label;
		milcode.push_back (newCode);

		/* generate the end label*/
		label = newLabel();
		leader_list.push_back (label);
	;}
    break;

  case 44:
#line 379 "mini_l.y"
    {
		string label = leader_list.back();
		string predName = newPred();
		string newCode = "\t! " + predName + ", " + tempName;
		milcode.push_back (newCode);

		newCode = "\t:= " + label + ", " + predName;
		milcode.push_back (newCode);
		//leader_list.pop_back();
		
	;}
    break;

  case 45:
#line 393 "mini_l.y"
    {
		string label = newLabel();
		leader_list.push_back(label);
		string newCode = " : " + label;
		milcode.push_back (newCode);
	;}
    break;

  case 48:
#line 405 "mini_l.y"
    { readFlag = true; ;}
    break;

  case 49:
#line 407 "mini_l.y"
    { readFlag = false; ;}
    break;

  case 51:
#line 412 "mini_l.y"
    {
		string varName = (yyvsp[(1) - (1)].myAttri).name;
		string newCode;

		if (readFlag)
			newCode = "\t.< " + varName;
		else
			newCode = "\t.> " + varName;
		milcode.push_back (newCode);
	    ;}
    break;

  case 52:
#line 424 "mini_l.y"
    {
		string newCode;
		
		if (readFlag)
			newCode = "\t.< " + tempVarName;
		else
			newCode = "\t.> " + tempVarName;
		milcode.push_back (newCode); 
	;}
    break;

  case 53:
#line 436 "mini_l.y"
    {
			string ident = (yyvsp[(1) - (1)].String); 
			// check if ident is already in the symbol table
			map <string, int>::iterator it = symbol_table.find (ident);
			
			if ( it == symbol_table.end() )
			{
				errorFound = true;
				cout << "Error at line " << currLine << ": '" << ident
					 << "' was not declared\n";
			}
			else {
				int temp = symbol_table[ident];
				(yyval.myAttri).value = temp;
			}
			strcpy ((yyval.myAttri).name, (yyvsp[(1) - (1)].String));
			tempVarName = (yyvsp[(1) - (1)].String);
          
		;}
    break;

  case 54:
#line 457 "mini_l.y"
    {
			/*	need to determine if array access or array assignment
				ex: n = array[0] vs array[0] = n;
			*/	
        ;}
    break;

  case 55:
#line 463 "mini_l.y"
    {string label = newLabel();
	    leader_list.push_back(label);
	    if_flag = true;
	;}
    break;

  case 56:
#line 470 "mini_l.y"
    {
		string label = leader_list.back();
		if(!leader_list.empty()) {
			leader_list.pop_back();
		}
		/*
		string bool_exprName = $3.name;
		string predName = newPred();
		string newCode = "\t! " + predName + ", " + bool_exprName;
		milcode.push_back(newCode);
		newCode = "\t?:= " + label + ", " + predName;
		milcode.push_back(newCode);*/

	//	milcode.push_back (" : " + label);
            ;}
    break;

  case 57:
#line 486 "mini_l.y"
    {
		if(leader_list.empty()) {
		cout << "stmt_loop else_stmt_loop: List empy\n";
		}
		else
			leader_list.pop_back();
	    ;}
    break;

  case 59:
#line 496 "mini_l.y"
    { string label = newLabel(); leader_list.push_back(label); milcode.push_back(" : " + label);;}
    break;

  case 61:
#line 500 "mini_l.y"
    {
		if(leader_list.empty()) {
		cout << "stmt_loop else_stmt_loop: List empy\n";
		}
		else
			leader_list.pop_back();
		;}
    break;

  case 63:
#line 509 "mini_l.y"
    { leader_list.back();  ;}
    break;

  case 64:
#line 512 "mini_l.y"
    {
			strcpy((yyval.myAttri).name, (yyvsp[(1) - (1)].myAttri).name);
			tempName = (yyvsp[(1) - (1)].myAttri).name;
		;}
    break;

  case 65:
#line 517 "mini_l.y"
    {
			string predLHSName = (yyvsp[(1) - (3)].myAttri).name;
			string predRHSName = (yyvsp[(3) - (3)].myAttri).name;
			string predName = newPred();
			string newCode = genExprCode (predName, predLHSName, predRHSName, "||");
			milcode.push_back(newCode);
			strcpy((yyval.myAttri).name, predName.c_str());
			tempName = predName;
		;}
    break;

  case 66:
#line 529 "mini_l.y"
    {
				strcpy((yyval.myAttri).name, (yyvsp[(1) - (1)].myAttri).name);
			;}
    break;

  case 67:
#line 533 "mini_l.y"
    {
				string predLHSName = (yyvsp[(1) - (3)].myAttri).name;
				string predRHSName = (yyvsp[(3) - (3)].myAttri).name;
				string predName = newPred();
				string newCode = genExprCode (predName, predLHSName, predRHSName, "&&");
				milcode.push_back(newCode);
				strcpy((yyval.myAttri).name, predName.c_str());
			;}
    break;

  case 68:
#line 544 "mini_l.y"
    {
					// need to implement comparator stuff
					
					string predName1 = newPred();
					
					// first, we generate code for "p_n = expr comp expr"
					//genExprCode (dest, src1, src2, OP)
					string newCode = genExprCode (predName1, (yyvsp[(2) - (4)].myAttri).name, (yyvsp[(4) - (4)].myAttri).name, (yyvsp[(3) - (4)].myAttri).name);
					milcode.push_back (newCode);
					
					// then, we generate code for "p_(n+1) = NOT p_n"
					string predName2 = newPred();
					newCode = "\t! " + predName2 + predName1;
					milcode.push_back (newCode);
					
					strcpy ((yyval.myAttri).name, predName2.c_str());
					
				;}
    break;

  case 69:
#line 563 "mini_l.y"
    {
					// p contains the value of the bool_expr
					// p <- false <- NOT true
					string predName = newPred();
					strcpy ((yyval.myAttri).name, predName.c_str());
					
					// ! dest, src
					string newCode = "\t! " + predName + ", true";
					milcode.push_back (newCode);
					
				;}
    break;

  case 70:
#line 575 "mini_l.y"
    {	
					// p contains the value of the bool_expr
					// p <- true <- NOT false
					string predName = newPred();
					strcpy ((yyval.myAttri).name, predName.c_str());
					
					// ! dest, src
					string newCode = "\t! " + predName + ", false";
					milcode.push_back (newCode);
					
				;}
    break;

  case 71:
#line 587 "mini_l.y"
    {
					string boolexpr_name = (yyvsp[(3) - (4)].myAttri).name;
					string predName = newPred();
					strcpy ((yyval.myAttri).name, predName.c_str());
					
					string newCode = "\t! " + predName + boolexpr_name;
					milcode.push_back (newCode);
				;}
    break;

  case 72:
#line 596 "mini_l.y"
    {
					string bool_op = (yyvsp[(2) - (3)].myAttri).name;
					
					string predName = newPred();
					strcpy ((yyval.myAttri).name, predName.c_str());
					
					string newCode = genExprCode(predName, (yyvsp[(1) - (3)].myAttri).name, (yyvsp[(3) - (3)].myAttri).name, bool_op);
					milcode.push_back (newCode);	
				;}
    break;

  case 73:
#line 605 "mini_l.y"
    { string temp = "true"; strcpy((yyval.myAttri).name, temp.c_str());;}
    break;

  case 74:
#line 606 "mini_l.y"
    { string temp = "false"; strcpy ((yyval.myAttri).name, temp.c_str());;}
    break;

  case 75:
#line 607 "mini_l.y"
    { strcpy ((yyval.myAttri).name, (yyvsp[(2) - (3)].myAttri).name); ;}
    break;

  case 76:
#line 608 "mini_l.y"
    { printf("Syntax Error: Invalid condition\n"); ;}
    break;

  case 77:
#line 611 "mini_l.y"
    { string temp = "=="; strcpy((yyval.myAttri).name, temp.c_str()); booleanOp = 0; ;}
    break;

  case 78:
#line 612 "mini_l.y"
    { string temp = "!="; strcpy((yyval.myAttri).name, temp.c_str()); booleanOp = 1; ;}
    break;

  case 79:
#line 613 "mini_l.y"
    { string temp = "<"; strcpy((yyval.myAttri).name, temp.c_str()); booleanOp = 2; ;}
    break;

  case 80:
#line 614 "mini_l.y"
    { string temp = ">"; strcpy((yyval.myAttri).name, temp.c_str()); booleanOp = 3; ;}
    break;

  case 81:
#line 615 "mini_l.y"
    { string temp = ">="; strcpy ((yyval.myAttri).name, temp.c_str()); booleanOp = 4; ;}
    break;

  case 82:
#line 616 "mini_l.y"
    { string temp = "<="; strcpy ((yyval.myAttri).name, temp.c_str()); booleanOp = 5; ;}
    break;

  case 83:
#line 621 "mini_l.y"
    {
			strcpy((yyval.myAttri).name, (yyvsp[(1) - (1)].myAttri).name); 
			(yyval.myAttri).value = (yyvsp[(1) - (1)].myAttri).value;
		;}
    break;

  case 84:
#line 626 "mini_l.y"
    {
			string tempName = newTemp();
			strcpy ((yyval.myAttri).name, tempName.c_str());
			(yyval.myAttri).value = (yyvsp[(1) - (3)].myAttri).value + (yyvsp[(3) - (3)].myAttri).value;
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode (tempName, (yyvsp[(1) - (3)].myAttri).name, (yyvsp[(3) - (3)].myAttri).name, "+");
			milcode.push_back (newCode);
			
		;}
    break;

  case 85:
#line 636 "mini_l.y"
    {
			string tempName = newTemp();
			strcpy ((yyval.myAttri).name, tempName.c_str());
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode (tempName, (yyvsp[(1) - (3)].myAttri).name, (yyvsp[(3) - (3)].myAttri).name, "-");
			milcode.push_back (newCode);
		;}
    break;

  case 86:
#line 647 "mini_l.y"
    {
			string tempName = newTemp();
			strcpy((yyval.myAttri).name, tempName.c_str());
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode(tempName, (yyvsp[(1) - (3)].myAttri).name, (yyvsp[(3) - (3)].myAttri).name, "*");
			milcode.push_back (newCode);
			
		;}
    break;

  case 87:
#line 657 "mini_l.y"
    {
			string tempName = newTemp();
			strcpy((yyval.myAttri).name, tempName.c_str());
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode(tempName, (yyvsp[(1) - (3)].myAttri).name, (yyvsp[(3) - (3)].myAttri).name, "/");
			milcode.push_back (newCode);
		;}
    break;

  case 88:
#line 666 "mini_l.y"
    {
			string tempName = newTemp();
			strcpy((yyval.myAttri).name, tempName.c_str());
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode(tempName, (yyvsp[(1) - (3)].myAttri).name, (yyvsp[(3) - (3)].myAttri).name, "%");
			milcode.push_back (newCode);
		;}
    break;

  case 89:
#line 675 "mini_l.y"
    { strcpy((yyval.myAttri).name, (yyvsp[(1) - (1)].myAttri).name); 
			(yyval.myAttri).value = (yyvsp[(1) - (1)].myAttri).value;
		;}
    break;

  case 90:
#line 681 "mini_l.y"
    { 
			string tempName = newTemp();
			strcpy ((yyval.myAttri).name, tempName.c_str());
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode (tempName, "0", (yyvsp[(2) - (2)].myAttri).name, "-");
			// milCode = milCode + tempCode;
			milcode.push_back (newCode);
		;}
    break;

  case 91:
#line 691 "mini_l.y"
    {
			string tempName = newTemp();
			strcpy ((yyval.myAttri).name, tempName.c_str());
			
			int number = atoi((yyvsp[(2) - (2)].IntString));
			number = -1 * number;
			(yyval.myAttri).value = number;
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode (tempName, "0", (yyvsp[(2) - (2)].IntString), "-");
			//milCode = milCode + tempCode;
			milcode.push_back (newCode);
		;}
    break;

  case 92:
#line 705 "mini_l.y"
    {
			string tempName = newTemp();
			strcpy ((yyval.myAttri).name, tempName.c_str());
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode (tempName, "0", (yyvsp[(3) - (4)].myAttri).name, "-");
			// milCode = milCode + tempCode;
			milcode.push_back (newCode);
		;}
    break;

  case 93:
#line 714 "mini_l.y"
    { strcpy((yyval.myAttri).name, (yyvsp[(1) - (1)].myAttri).name); ;}
    break;

  case 94:
#line 715 "mini_l.y"
    { strcpy((yyval.myAttri).name, (yyvsp[(1) - (1)].IntString)); 
		    int number = atoi((yyvsp[(1) - (1)].IntString));
			(yyval.myAttri).value = number;
			;}
    break;

  case 95:
#line 719 "mini_l.y"
    { strcpy((yyval.myAttri).name, (yyvsp[(2) - (3)].myAttri).name);;}
    break;


/* Line 1267 of yacc.c.  */
#line 2414 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 722 "mini_l.y"


/*	generates the mil code for the expressions
	dst = src1 OP src2 ----> OP dest, src1, src2
	OP can be '+', '-', '/', etc.
*/
string genExprCode ( string dst, string src1, string src2, string op )
{
	string exprCode = "\t" + op + " " + 
					  dst + ", " + 
					  src1 + ", " +
					  src2;
	return exprCode;
}

/*	generates a new temp variable, tn.
	where n is a number
*/
string newTemp ()
{
	stringstream ss;
	ss << temp_ctr;
	string newTempName = "t" + ss.str();
	temp_ctr++;
	
	return newTempName;
}

/*	generates a new predicate variable, pn.
	where n is a number
*/
string newPred ()
{
	stringstream ss;
	ss << pred_ctr;
	string newPredName = "p" + ss.str();
	pred_ctr++;
	
	return newPredName;
}

string newLabel ()
{
	stringstream ss;
	ss << label_ctr;
	string newLabelName = "L" + ss.str();
	label_ctr++;
	
	return newLabelName;
}
bool compare(int lhs, int rhs, int boolOp)
{
	switch(boolOp) {
		case 0:
			return lhs == rhs;
			break;
		case 1:
			return lhs != rhs;
			break;
		case 2:
			return lhs < rhs;
			break;
		case 3:
			return lhs > rhs;
			break;
		case 4:
			return lhs <= rhs;
			break;
		case 5:
			return lhs >= rhs;
			break;
		default:
			break;
	}
}
void print () {
	for(int i = 0; i < leader_list.size(); ++i) {
		cout << leader_list[i] << endl;
	}
}

int main() {

    yyparse();
    return 0;
}

void yyerror (const char* msg)
{

    printf( "line %d: %s\n", currLine, msg );
//    printf("Syntax error at line %d: \n",currLine, );
//	printf("Syntax error at line %d: \n", currLine, yytext);
}


