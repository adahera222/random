
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

    
/* Felipe Gonzalez, Renan Drabach */

#include <stdio.h>
#include <stdlib.h>
/*#include "astree.h"*/
#include "tac.h"
int yylex(void);
void yyerror(char *);



/* Line 189 of yacc.c  */
#line 87 "y.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_WORD = 256,
     KW_BOOL = 258,
     KW_BYTE = 259,
     KW_IF = 261,
     KW_THEN = 262,
     KW_ELSE = 263,
     KW_LOOP = 264,
     KW_INPUT = 266,
     KW_RETURN = 267,
     KW_OUTPUT = 268,
     OPERATOR_LE = 270,
     OPERATOR_GE = 271,
     OPERATOR_EQ = 272,
     OPERATOR_NE = 273,
     OPERATOR_AND = 274,
     OPERATOR_OR = 275,
     TK_IDENTIFIER = 280,
     LIT_INTEGER = 281,
     LIT_FALSE = 283,
     LIT_TRUE = 284,
     LIT_CHAR = 285,
     LIT_STRING = 286,
     TOKEN_ERROR = 290
   };
#endif
/* Tokens.  */
#define KW_WORD 256
#define KW_BOOL 258
#define KW_BYTE 259
#define KW_IF 261
#define KW_THEN 262
#define KW_ELSE 263
#define KW_LOOP 264
#define KW_INPUT 266
#define KW_RETURN 267
#define KW_OUTPUT 268
#define OPERATOR_LE 270
#define OPERATOR_GE 271
#define OPERATOR_EQ 272
#define OPERATOR_NE 273
#define OPERATOR_AND 274
#define OPERATOR_OR 275
#define TK_IDENTIFIER 280
#define LIT_INTEGER 281
#define LIT_FALSE 283
#define LIT_TRUE 284
#define LIT_CHAR 285
#define LIT_STRING 286
#define TOKEN_ERROR 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 46 "parser.y"

    HASH_NODE *symbol;
    AST *astree;



/* Line 214 of yacc.c  */
#line 180 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 192 "y.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   203

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    34,     2,    43,     2,
      37,    38,    30,    28,    39,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    32,
      26,    40,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     3,     2,     4,     5,
       2,     6,     7,     8,     9,     2,    10,    11,    12,     2,
      13,    14,    15,    16,    17,    18,     2,     2,     2,     2,
      19,    20,     2,    21,    22,    23,    24,     2,     2,     2,
      25,     1,     2
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    15,    17,    22,
      28,    33,    39,    41,    43,    45,    47,    49,    51,    53,
      55,    61,    69,    72,    73,    81,    85,    86,    89,    90,
      93,    94,    97,    99,   101,   103,   107,   114,   117,   120,
     123,   125,   130,   134,   135,   139,   142,   145,   146,   153,
     162,   168,   170,   173,   176,   181,   183,   185,   187,   189,
     191,   195,   199,   203,   207,   211,   215,   219,   223,   227,
     231,   235,   239,   243,   248,   252,   255,   258
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    46,    -1,    47,    46,    -1,    -1,    48,
      32,    -1,    52,    32,    -1,    54,    -1,    50,    19,    33,
      51,    -1,    50,    34,    19,    33,    51,    -1,    50,    19,
      33,    51,    -1,    50,    34,    19,    33,    51,    -1,     3,
      -1,     5,    -1,     4,    -1,    20,    -1,    21,    -1,    22,
      -1,    23,    -1,    24,    -1,    50,    19,    35,    20,    36,
      -1,    50,    19,    35,    20,    36,    33,    53,    -1,    51,
      53,    -1,    -1,    50,    19,    37,    56,    38,    55,    59,
      -1,    49,    32,    55,    -1,    -1,    57,    58,    -1,    -1,
      56,    39,    -1,    -1,    50,    19,    -1,    60,    -1,    63,
      -1,    64,    -1,    19,    40,    65,    -1,    19,    35,    65,
      36,    40,    65,    -1,    10,    65,    -1,    12,    66,    -1,
      11,    65,    -1,    11,    -1,    19,    37,    66,    38,    -1,
      19,    37,    38,    -1,    -1,    41,    61,    42,    -1,    62,
      59,    -1,    61,    32,    -1,    -1,     6,    37,    65,    38,
       7,    59,    -1,     6,    37,    65,    38,     7,    59,     8,
      59,    -1,     9,    37,    65,    38,    59,    -1,    19,    -1,
      43,    19,    -1,    30,    19,    -1,    19,    35,    65,    36,
      -1,    20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,
      -1,    65,    30,    65,    -1,    65,    31,    65,    -1,    65,
      28,    65,    -1,    65,    29,    65,    -1,    65,    26,    65,
      -1,    65,    27,    65,    -1,    65,    13,    65,    -1,    65,
      14,    65,    -1,    65,    15,    65,    -1,    65,    16,    65,
      -1,    65,    17,    65,    -1,    65,    18,    65,    -1,    37,
      65,    38,    -1,    19,    37,    66,    38,    -1,    19,    37,
      38,    -1,    67,    65,    -1,    66,    39,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    66,    67,    70,    71,    72,    75,    76,
      79,    80,    82,    83,    84,    87,    88,    89,    90,    91,
      94,    95,    98,    99,   102,   106,   107,   110,   111,   114,
     115,   118,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   135,   139,   142,   143,   145,   146,
     149,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   178,   181,   182
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_WORD", "KW_BOOL", "KW_BYTE", "KW_IF",
  "KW_THEN", "KW_ELSE", "KW_LOOP", "KW_INPUT", "KW_RETURN", "KW_OUTPUT",
  "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ", "OPERATOR_NE",
  "OPERATOR_AND", "OPERATOR_OR", "TK_IDENTIFIER", "LIT_INTEGER",
  "LIT_FALSE", "LIT_TRUE", "LIT_CHAR", "LIT_STRING", "TOKEN_ERROR", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "';'", "':'", "'$'", "'['", "']'",
  "'('", "')'", "','", "'='", "'{'", "'}'", "'&'", "$accept", "PROG",
  "LIST_DEC", "DEC", "DEC_VAR", "DEC_LOC_VAR", "TYPE", "LIT", "DEC_VET",
  "LIST_VAL", "DEC_FUN", "LIST_DEC_LOC", "LIST_DEC_PARAM",
  "LIST_DEC_PARAM_SEP", "DEC_PARAM", "COMMAND", "BLOCO", "LIST_COM",
  "LIST_COM_SEP", "IF", "LOOP", "EXP", "LIST_PARAM", "LIST_PARAM_SEP", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   291,   292,   256,   258,   259,   261,   262,   263,   264,
     266,   267,   268,   270,   271,   272,   273,   274,   275,   280,
     281,   283,   284,   285,   286,   290,    60,    62,    43,    45,
      42,    47,    59,    58,    36,    91,    93,    40,    41,    44,
      61,   123,   125,    38
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    48,    48,
      49,    49,    50,    50,    50,    51,    51,    51,    51,    51,
      52,    52,    53,    53,    54,    55,    55,    56,    56,    57,
      57,    58,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    60,    61,    62,    62,    63,    63,
      64,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    67,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     2,     1,     4,     5,
       4,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     7,     2,     0,     7,     3,     0,     2,     0,     2,
       0,     2,     1,     1,     1,     3,     6,     2,     2,     2,
       1,     4,     3,     0,     3,     2,     2,     0,     6,     8,
       5,     1,     2,     2,     4,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     2,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    12,    14,    13,     0,     2,     4,     0,     0,     0,
       7,     1,     3,     5,     0,     0,     6,     0,     0,    30,
       0,    15,    16,    17,    18,    19,     8,     0,     0,     0,
       0,    20,    26,    29,     0,    27,     9,    23,     0,     0,
      43,    31,    23,    21,    26,     0,     0,     0,     0,     0,
      40,    77,     0,    47,    24,    32,    33,    34,    22,    25,
       0,     0,     0,     0,    51,    55,    56,    57,    58,    59,
       0,     0,     0,    37,    39,    38,     0,     0,    77,     0,
       0,    43,    10,     0,     0,     0,     0,    77,    53,     0,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,    75,     0,    42,     0,    35,    46,
      44,    45,    11,     0,    43,     0,    74,     0,    72,    66,
      67,    68,    69,    70,    71,    64,    65,    62,    63,    60,
      61,     0,    41,    43,    50,    54,    73,     0,    48,    36,
      43,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    38,     8,    42,     9,    43,
      10,    40,    28,    29,    35,    54,    55,    80,    81,    56,
      57,    73,    75,    76
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -80
static const yytype_int16 yypact[] =
{
      74,   -80,   -80,   -80,    25,   -80,    74,     2,   -15,     5,
     -80,   -80,   -80,   -80,   -13,     9,   -80,    69,    43,     1,
      55,   -80,   -80,   -80,   -80,   -80,   -80,    92,    36,    74,
      69,    96,    74,   -80,   119,   -80,   -80,    69,   107,    -2,
      -3,   -80,    69,   -80,    74,   108,   121,   105,   113,   100,
     100,   -80,    27,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
      69,   120,   100,   100,    -4,   -80,   -80,   -80,   -80,   -80,
     132,   100,   133,   166,   166,   122,   100,   100,   124,   100,
     -31,    -3,   -80,    69,    42,    68,   100,   125,   -80,    87,
     -80,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   -80,   166,   118,   -80,    73,   166,   -80,
     -80,   -80,   -80,   157,    -3,   142,   -80,    88,   -80,    79,
      79,    79,    79,   172,   172,    79,    79,    35,    35,   -80,
     -80,   126,   -80,    -3,   -80,   -80,   -80,   100,   159,   166,
      -3,   -80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   168,   -80,   -80,   -80,   -14,    -7,   -80,   123,
     -80,   131,   -80,   -80,   -80,   -79,   -80,   -80,   -80,   -80,
     -80,   -50,   -73,   -80
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -29
static const yytype_int16 yytable[] =
{
      74,   109,   111,    47,    14,   107,    48,    49,    50,    51,
      26,   110,    84,    85,   117,    34,    52,    45,    39,    15,
      17,    89,    18,    36,    19,    11,   104,   105,    20,   108,
      39,    86,    46,    87,    13,   134,   115,    16,    53,   -28,
     -28,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    82,   138,    91,    92,    93,    94,    95,
      96,   141,    77,    27,    78,   101,   102,    79,    97,    98,
      99,   100,   101,   102,    32,    33,   112,     1,     2,     3,
     113,    91,    92,    93,    94,    95,    96,   139,    30,    21,
      22,    23,    24,    25,    97,    98,    99,   100,   101,   102,
      91,    92,    93,    94,    95,    96,   114,    99,   100,   101,
     102,   132,   103,    97,    98,    99,   100,   101,   102,    64,
      65,    66,    67,    68,    69,   118,   136,   103,    31,    37,
      70,    91,    92,    93,    94,    95,    96,    71,    41,    44,
      61,    60,    62,    72,    97,    98,    99,   100,   101,   102,
      63,    88,    90,    83,   131,    91,    92,    93,    94,    95,
      96,   103,   106,   116,   133,    58,   137,   140,    97,    98,
      99,   100,   101,   102,    12,    59,     0,     0,   135,    91,
      92,    93,    94,    95,    96,    91,    92,    93,    94,     0,
       0,     0,    97,    98,    99,   100,   101,   102,    97,    98,
      99,   100,   101,   102
};

static const yytype_int16 yycheck[] =
{
      50,    32,    81,     6,    19,    78,     9,    10,    11,    12,
      17,    42,    62,    63,    87,    29,    19,    19,    32,    34,
      33,    71,    35,    30,    37,     0,    76,    77,    19,    79,
      44,    35,    34,    37,    32,   114,    86,    32,    41,    38,
      39,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    60,   133,    13,    14,    15,    16,    17,
      18,   140,    35,    20,    37,    30,    31,    40,    26,    27,
      28,    29,    30,    31,    38,    39,    83,     3,     4,     5,
      38,    13,    14,    15,    16,    17,    18,   137,    33,    20,
      21,    22,    23,    24,    26,    27,    28,    29,    30,    31,
      13,    14,    15,    16,    17,    18,    38,    28,    29,    30,
      31,    38,    39,    26,    27,    28,    29,    30,    31,    19,
      20,    21,    22,    23,    24,    38,    38,    39,    36,    33,
      30,    13,    14,    15,    16,    17,    18,    37,    19,    32,
      19,    33,    37,    43,    26,    27,    28,    29,    30,    31,
      37,    19,    19,    33,    36,    13,    14,    15,    16,    17,
      18,    39,    38,    38,     7,    42,    40,     8,    26,    27,
      28,    29,    30,    31,     6,    44,    -1,    -1,    36,    13,
      14,    15,    16,    17,    18,    13,    14,    15,    16,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    26,    27,
      28,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    45,    46,    47,    48,    50,    52,
      54,     0,    46,    32,    19,    34,    32,    33,    35,    37,
      19,    20,    21,    22,    23,    24,    51,    20,    56,    57,
      33,    36,    38,    39,    50,    58,    51,    33,    49,    50,
      55,    19,    51,    53,    32,    19,    34,     6,     9,    10,
      11,    12,    19,    41,    59,    60,    63,    64,    53,    55,
      33,    19,    37,    37,    19,    20,    21,    22,    23,    24,
      30,    37,    43,    65,    65,    66,    67,    35,    37,    40,
      61,    62,    51,    33,    65,    65,    35,    37,    19,    65,
      19,    13,    14,    15,    16,    17,    18,    26,    27,    28,
      29,    30,    31,    39,    65,    65,    38,    66,    65,    32,
      42,    59,    51,    38,    38,    65,    38,    66,    38,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    36,    38,     7,    59,    36,    38,    40,    59,    65,
       8,    59
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 2:

/* Line 1455 of yacc.c  */
#line 57 "parser.y"
    { (yyval.astree) = (yyvsp[(1) - (1)].astree); //astPrintFile($$); 
                            declarations((yyval.astree)); 
                            usage((yyval.astree)); 
                            datatypes((yyval.astree)); 
                            hashPrint(); 
                            astPrint((yyval.astree),0);
                            generateASM(generateCode((yyval.astree))); }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 66 "parser.y"
    { (yyval.astree) = astCreate(AST_LIST_DEC, 0, (yyvsp[(1) - (2)].astree), (yyvsp[(2) - (2)].astree), 0, 0); }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 67 "parser.y"
    { (yyval.astree) = astCreate(0, 0, 0, 0, 0, 0); }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 70 "parser.y"
    { (yyval.astree) = astCreate(AST_DEC, 0, (yyvsp[(1) - (2)].astree), 0, 0, 0); }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 71 "parser.y"
    { (yyval.astree) = astCreate(AST_DEC, 0, (yyvsp[(1) - (2)].astree), 0, 0, 0); }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 72 "parser.y"
    { (yyval.astree) = astCreate(AST_DEC, 0, (yyvsp[(1) - (1)].astree), 0, 0, 0); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 75 "parser.y"
    { (yyval.astree) = astCreate(AST_DEC_VAR, (yyvsp[(2) - (4)].symbol), (yyvsp[(1) - (4)].astree), (yyvsp[(4) - (4)].astree), 0, 0); (yyvsp[(2) - (4)].symbol)->data_type = (yyvsp[(1) - (4)].astree)->type; }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    { (yyval.astree) = astCreate(AST_DEC_PTR, (yyvsp[(3) - (5)].symbol), (yyvsp[(1) - (5)].astree), (yyvsp[(5) - (5)].astree), 0, 0); (yyvsp[(3) - (5)].symbol)->data_type = (yyvsp[(1) - (5)].astree)->type; }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    { (yyval.astree) = astCreate(AST_DEC_LOC_VAR, (yyvsp[(2) - (4)].symbol), (yyvsp[(1) - (4)].astree), (yyvsp[(4) - (4)].astree), 0, 0); (yyvsp[(2) - (4)].symbol)->data_type = (yyvsp[(1) - (4)].astree)->type; }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    { (yyval.astree) = astCreate(AST_DEC_LOC_PTR, (yyvsp[(3) - (5)].symbol), (yyvsp[(1) - (5)].astree), (yyvsp[(5) - (5)].astree), 0, 0); (yyvsp[(3) - (5)].symbol)->data_type = (yyvsp[(1) - (5)].astree)->type; }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    { (yyval.astree) = astCreate(AST_WORD, 0, 0, 0, 0, 0); }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    { (yyval.astree) = astCreate(AST_BYTE, 0, 0, 0, 0, 0); }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    { (yyval.astree) = astCreate(AST_BOOL, 0, 0, 0, 0, 0); }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 87 "parser.y"
    { (yyval.astree) = astCreate(AST_SYMBOL_LIT, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); (yyvsp[(1) - (1)].symbol)->data_type = L_INT; }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    { (yyval.astree) = astCreate(AST_SYMBOL_LIT, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); (yyvsp[(1) - (1)].symbol)->data_type = L_BOOL; }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    { (yyval.astree) = astCreate(AST_SYMBOL_LIT, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); (yyvsp[(1) - (1)].symbol)->data_type = L_BOOL; }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 90 "parser.y"
    { (yyval.astree) = astCreate(AST_SYMBOL_LIT, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); (yyvsp[(1) - (1)].symbol)->data_type = L_CHAR; }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    { (yyval.astree) = astCreate(AST_SYMBOL_LIT, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); (yyvsp[(1) - (1)].symbol)->data_type = L_STR; }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    { (yyval.astree) = astCreate(AST_DEC_VET, (yyvsp[(2) - (5)].symbol), (yyvsp[(1) - (5)].astree), astCreate(AST_VET_SIZE, (yyvsp[(4) - (5)].symbol), 0, 0, 0, 0), 0, 0); (yyvsp[(2) - (5)].symbol)->data_type = (yyvsp[(1) - (5)].astree)->type; }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    { (yyval.astree) = astCreate(AST_DEC_VET, (yyvsp[(2) - (7)].symbol), (yyvsp[(1) - (7)].astree), astCreate(AST_VET_SIZE, (yyvsp[(4) - (7)].symbol), 0, 0, 0, 0), astCreate(AST_LIST_VAL, 0, (yyvsp[(7) - (7)].astree), 0, 0, 0), 0); (yyvsp[(2) - (7)].symbol)->data_type = (yyvsp[(1) - (7)].astree)->type; }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    { (yyval.astree) = astCreate(AST_LIST_VAL, 0, (yyvsp[(1) - (2)].astree), (yyvsp[(2) - (2)].astree), 0, 0); }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    { (yyval.astree) = astCreate(0, 0, 0, 0, 0, 0); }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    { (yyval.astree) = astCreate(AST_DEC_FUN, (yyvsp[(2) - (7)].symbol), (yyvsp[(1) - (7)].astree), (yyvsp[(4) - (7)].astree), (yyvsp[(6) - (7)].astree), (yyvsp[(7) - (7)].astree)); (yyvsp[(2) - (7)].symbol)->data_type = (yyvsp[(1) - (7)].astree)->type; (yyvsp[(2) - (7)].symbol)->params = (yyvsp[(4) - (7)].astree); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    { (yyval.astree) = astCreate(AST_LIST_DEC_LOC, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0); }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { (yyval.astree) = astCreate(0, 0, 0, 0, 0, 0); }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
    { (yyval.astree) = astCreate(AST_LIST_DEC_PARAM, 0, (yyvsp[(1) - (2)].astree), (yyvsp[(2) - (2)].astree), 0, 0); }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 111 "parser.y"
    { (yyval.astree) = astCreate(AST_EMPTY, 0, 0, 0, 0, 0); }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    { (yyval.astree) = astCreate(AST_LIST_DEC_PARAM_SEP, 0, (yyvsp[(1) - (2)].astree), 0, 0, 0); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    { (yyval.astree) = astCreate(AST_EMPTY, 0, 0, 0, 0, 0); }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 118 "parser.y"
    { (yyval.astree) = astCreate(AST_DEC_PARAM, (yyvsp[(2) - (2)].symbol), (yyvsp[(1) - (2)].astree), 0, 0, 0); (yyvsp[(2) - (2)].symbol)->data_type = (yyvsp[(1) - (2)].astree)->type; }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    { (yyval.astree) = astCreate(AST_COMMAND, 0, (yyvsp[(1) - (1)].astree), 0, 0, 0); }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    { (yyval.astree) = astCreate(AST_COMMAND, 0, (yyvsp[(1) - (1)].astree), 0, 0, 0); }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    { (yyval.astree) = astCreate(AST_COMMAND, 0, (yyvsp[(1) - (1)].astree), 0, 0, 0); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    { (yyval.astree) = astCreate(AST_ATR, (yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].astree), 0, 0, 0); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    { (yyval.astree) = astCreate(AST_ATR_VET, (yyvsp[(1) - (6)].symbol), (yyvsp[(3) - (6)].astree), (yyvsp[(6) - (6)].astree), 0, 0); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    { (yyval.astree) = astCreate(AST_INPUT, 0, (yyvsp[(2) - (2)].astree), 0, 0, 0); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    { (yyval.astree) = astCreate(AST_OUTPUT, 0, (yyvsp[(2) - (2)].astree), 0, 0, 0); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    { (yyval.astree) = astCreate(AST_RETURN, 0, (yyvsp[(2) - (2)].astree), 0, 0, 0); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    { (yyval.astree) = astCreate(AST_RETURN, 0, 0, 0, 0, 0); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    { (yyval.astree) = astCreate(AST_CALL, (yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].astree), 0, 0, 0); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    { (yyval.astree) = astCreate(AST_CALL_EMPTY, (yyvsp[(1) - (3)].symbol), 0, 0, 0, 0); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    { (yyval.astree) = astCreate(0, 0, 0, 0, 0, 0); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    { (yyval.astree) = astCreate(AST_BLOCO, 0, (yyvsp[(2) - (3)].astree), 0, 0, 0); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    { (yyval.astree) = astCreate(AST_LIST_COM, 0, (yyvsp[(1) - (2)].astree), (yyvsp[(2) - (2)].astree), 0, 0); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    { (yyval.astree) = astCreate(AST_LIST_COM_SEP, 0, (yyvsp[(1) - (2)].astree), 0, 0, 0); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    { (yyval.astree) = astCreate(0, 0, 0, 0, 0, 0); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    { (yyval.astree) = astCreate(AST_IF, 0, (yyvsp[(3) - (6)].astree), (yyvsp[(6) - (6)].astree), 0, 0); }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    { (yyval.astree) = astCreate(AST_IF, 0, (yyvsp[(3) - (8)].astree), (yyvsp[(6) - (8)].astree), (yyvsp[(8) - (8)].astree), 0); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    { (yyval.astree) = astCreate(AST_LOOP, 0, (yyvsp[(3) - (5)].astree), (yyvsp[(5) - (5)].astree), 0, 0); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    { (yyval.astree) = astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    { (yyval.astree) = astCreate(AST_REF, (yyvsp[(2) - (2)].symbol), 0, 0, 0, 0); }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    { (yyval.astree) = astCreate(AST_DEREF, (yyvsp[(2) - (2)].symbol), 0, 0, 0, 0); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    { (yyval.astree) = astCreate(AST_VET, (yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].astree), 0, 0, 0); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    { (yyval.astree) = astCreate(AST_SYMBOL_LIT, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); (yyvsp[(1) - (1)].symbol)->data_type = L_INT; }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    { (yyval.astree) = astCreate(AST_SYMBOL_LIT, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); (yyvsp[(1) - (1)].symbol)->data_type = L_BOOL; }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    { (yyval.astree) = astCreate(AST_SYMBOL_LIT, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); (yyvsp[(1) - (1)].symbol)->data_type = L_BOOL; }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    { (yyval.astree) = astCreate(AST_SYMBOL_LIT, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); (yyvsp[(1) - (1)].symbol)->data_type = L_CHAR; }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    { (yyval.astree) = astCreate(AST_SYMBOL_LIT, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); (yyvsp[(1) - (1)].symbol)->data_type = L_STR; }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    { (yyval.astree) = astCreate(AST_MUL, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    { (yyval.astree) = astCreate(AST_DIV, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    { (yyval.astree) = astCreate(AST_SUM, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    { (yyval.astree) = astCreate(AST_SUB, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    { (yyval.astree) = astCreate(AST_LT, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    { (yyval.astree) = astCreate(AST_GT, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    { (yyval.astree) = astCreate(AST_LE, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    { (yyval.astree) = astCreate(AST_GE, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    { (yyval.astree) = astCreate(AST_EQ, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    { (yyval.astree) = astCreate(AST_NE, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    { (yyval.astree) = astCreate(AST_AND, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0); }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 172 "parser.y"
    { (yyval.astree) = astCreate(AST_OR, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0); }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    { (yyval.astree) = astCreate(AST_PAREN, 0, (yyvsp[(2) - (3)].astree), 0, 0, 0); }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 174 "parser.y"
    { (yyval.astree) = astCreate(AST_CALL, (yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].astree), 0, 0, 0); }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 175 "parser.y"
    { (yyval.astree) = astCreate(AST_CALL_EMPTY, (yyvsp[(1) - (3)].symbol), 0, 0, 0, 0); }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    { (yyval.astree) = astCreate(AST_LIST_PARAM, 0, (yyvsp[(1) - (2)].astree), (yyvsp[(2) - (2)].astree), 0, 0); }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    { (yyval.astree) = astCreate(AST_LIST_PARAM_SEP, 0, (yyvsp[(1) - (2)].astree), 0, 0, 0); }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    { (yyval.astree) = astCreate(AST_EMPTY, 0, 0, 0, 0, 0); }
    break;



/* Line 1455 of yacc.c  */
#line 2063 "y.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 185 "parser.y"


void yyerror(char *s) {
	fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", getLineNumber(), s);
	exit(3);
}

