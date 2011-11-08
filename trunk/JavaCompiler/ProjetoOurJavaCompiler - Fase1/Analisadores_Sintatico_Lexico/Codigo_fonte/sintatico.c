
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
#line 12 "sintatico.y"

#include <stdio.h>
#include <string.h>
int yylex(void);
int yyerror(char *msg); //funcao de erro (sobrescrita)
int line = 1; //declarado no lexico
int column  = 0; // declarado no lexico
char* yytext = ""; //declarado no lexico


/* Line 189 of yacc.c  */
#line 84 "sintatico.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
     CLASS = 258,
     BEG = 259,
     END = 260,
     STATIC = 261,
     PT_VIRGULA = 262,
     OPEN_COLC = 263,
     CLOSE_COLC = 264,
     EQUAL = 265,
     VIRGULA = 266,
     POINT = 267,
     QUESTION_MARK = 268,
     TWO_POINTS = 269,
     OR_LOGIC = 270,
     AND_LOGIC = 271,
     OPEN_PAREN = 272,
     CLOSE_PAREN = 273,
     NEW = 274,
     OR = 275,
     OR_EXC = 276,
     AND = 277,
     PLUS = 278,
     MINUS = 279,
     MULT = 280,
     DIV = 281,
     MOD = 282,
     INCREMENT = 283,
     DECREMENT = 284,
     NOT = 285,
     NOT_BIT = 286,
     FOR = 287,
     IF = 288,
     ELSE = 289,
     WHILE = 290,
     CASE = 291,
     SWITCH = 292,
     DEFAULT = 293,
     DO = 294,
     BREAK = 295,
     CONTINUE = 296,
     GOTO = 297,
     RETURN = 298,
     VOID = 299,
     MAIN = 300,
     ARGS = 301,
     PUBLIC = 302,
     TYPE_INT = 303,
     TYPE_SHORT = 304,
     TYPE_LONG = 305,
     TYPE_BYTE = 306,
     TYPE_BOOL = 307,
     TYPE_FLOAT = 308,
     TYPE_DOUBLE = 309,
     TYPE_CHAR = 310,
     TYPE_STRING = 311,
     FINAL = 312,
     TRANSIENT = 313,
     VOLATILE = 314,
     ID = 315,
     SHIFT_ASSIGN = 316,
     ARITH_ASSIGN = 317,
     LOGIC_ASSIGN = 318,
     LITERAL = 319,
     EQUALOP = 320,
     RELOP = 321,
     SHIFTS = 322
   };
#endif
/* Tokens.  */
#define CLASS 258
#define BEG 259
#define END 260
#define STATIC 261
#define PT_VIRGULA 262
#define OPEN_COLC 263
#define CLOSE_COLC 264
#define EQUAL 265
#define VIRGULA 266
#define POINT 267
#define QUESTION_MARK 268
#define TWO_POINTS 269
#define OR_LOGIC 270
#define AND_LOGIC 271
#define OPEN_PAREN 272
#define CLOSE_PAREN 273
#define NEW 274
#define OR 275
#define OR_EXC 276
#define AND 277
#define PLUS 278
#define MINUS 279
#define MULT 280
#define DIV 281
#define MOD 282
#define INCREMENT 283
#define DECREMENT 284
#define NOT 285
#define NOT_BIT 286
#define FOR 287
#define IF 288
#define ELSE 289
#define WHILE 290
#define CASE 291
#define SWITCH 292
#define DEFAULT 293
#define DO 294
#define BREAK 295
#define CONTINUE 296
#define GOTO 297
#define RETURN 298
#define VOID 299
#define MAIN 300
#define ARGS 301
#define PUBLIC 302
#define TYPE_INT 303
#define TYPE_SHORT 304
#define TYPE_LONG 305
#define TYPE_BYTE 306
#define TYPE_BOOL 307
#define TYPE_FLOAT 308
#define TYPE_DOUBLE 309
#define TYPE_CHAR 310
#define TYPE_STRING 311
#define FINAL 312
#define TRANSIENT 313
#define VOLATILE 314
#define ID 315
#define SHIFT_ASSIGN 316
#define ARITH_ASSIGN 317
#define LOGIC_ASSIGN 318
#define LITERAL 319
#define EQUALOP 320
#define RELOP 321
#define SHIFTS 322




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 22 "sintatico.y"

        char* strval;



/* Line 214 of yacc.c  */
#line 260 "sintatico.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 272 "sintatico.c"

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   676

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  117
/* YYNRULES -- Number of rules.  */
#define YYNRULES  248
/* YYNRULES -- Number of states.  */
#define YYNSTATES  455

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    11,    15,    19,    31,    35,
      38,    40,    43,    44,    46,    48,    52,    55,    56,    59,
      64,    66,    68,    70,    72,    74,    76,    78,    80,    82,
      84,    86,    88,    91,    94,    98,    99,   102,   103,   105,
     107,   109,   111,   116,   118,   120,   121,   124,   126,   130,
     131,   133,   135,   139,   141,   143,   145,   147,   149,   151,
     156,   158,   160,   162,   164,   166,   169,   171,   175,   176,
     181,   185,   187,   188,   190,   191,   193,   198,   204,   212,
     214,   216,   218,   220,   222,   224,   226,   228,   230,   232,
     233,   236,   241,   245,   246,   249,   254,   258,   259,   262,
     267,   271,   272,   275,   280,   284,   285,   288,   293,   297,
     298,   301,   306,   310,   311,   314,   319,   323,   324,   327,
     332,   336,   337,   340,   345,   349,   353,   354,   357,   362,
     366,   370,   374,   375,   378,   381,   384,   387,   389,   392,
     395,   397,   401,   406,   411,   413,   415,   417,   421,   423,
     426,   429,   431,   434,   437,   440,   441,   443,   447,   453,
     459,   469,   471,   475,   477,   479,   480,   483,   487,   488,
     492,   494,   496,   498,   501,   503,   506,   511,   516,   523,
     525,   526,   528,   530,   531,   533,   535,   537,   539,   541,
     543,   545,   547,   549,   551,   554,   560,   565,   568,   570,
     573,   574,   577,   580,   582,   585,   586,   590,   593,   601,
     605,   609,   613,   617,   619,   620,   622,   626,   634,   640,
     650,   653,   654,   657,   658,   661,   663,   665,   668,   671,
     673,   675,   677,   682,   684,   686,   687,   690,   692,   696,
     697,   700,   703,   708,   715,   718,   719,   721,   723
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      69,     0,    -1,    70,    -1,     3,    71,    72,    -1,    60,
      -1,     4,    73,     5,    -1,   170,    74,   170,    -1,    47,
       6,    44,    45,    17,    56,     8,     9,    46,    18,    75,
      -1,     4,    76,     5,    -1,    78,    77,    -1,    77,    -1,
      78,    77,    -1,    -1,    79,    -1,   139,    -1,    81,     7,
      80,    -1,    81,     7,    -1,    -1,    82,    86,    -1,    82,
       8,     9,    86,    -1,    83,    -1,    52,    -1,    56,    -1,
      84,    -1,    85,    -1,    51,    -1,    49,    -1,    48,    -1,
      50,    -1,    55,    -1,    53,    -1,    54,    -1,    87,    88,
      -1,    90,    89,    -1,    11,    87,    88,    -1,    -1,    10,
      91,    -1,    -1,    71,    -1,    97,    -1,    92,    -1,    99,
      -1,     4,    94,    93,     5,    -1,   105,    -1,    11,    -1,
      -1,    91,    95,    -1,    95,    -1,    11,    91,    95,    -1,
      -1,    97,    -1,   109,    -1,    71,    12,    71,    -1,    98,
      -1,   101,    -1,    10,    -1,    62,    -1,    61,    -1,    63,
      -1,   102,     8,    96,     9,    -1,    64,    -1,    98,    -1,
     148,    -1,   101,    -1,    71,    -1,    96,   104,    -1,   104,
      -1,    11,    96,   104,    -1,    -1,    19,    82,   106,   108,
      -1,     8,   107,     9,    -1,    96,    -1,    -1,   106,    -1,
      -1,   111,    -1,    17,   111,    18,   110,    -1,   111,    13,
     109,    14,   109,    -1,    17,   111,    18,    13,   109,    14,
     109,    -1,   112,    -1,   114,    -1,   116,    -1,   118,    -1,
     120,    -1,   122,    -1,   124,    -1,   126,    -1,   128,    -1,
     130,    -1,    -1,   113,   112,    -1,   113,    17,   109,    18,
      -1,    15,   113,   112,    -1,    -1,   115,   114,    -1,   115,
      17,   109,    18,    -1,    16,   115,   114,    -1,    -1,   117,
     116,    -1,   117,    17,   109,    18,    -1,    20,   117,   116,
      -1,    -1,   119,   118,    -1,   119,    17,   109,    18,    -1,
      21,   119,   118,    -1,    -1,   121,   120,    -1,   121,    17,
     109,    18,    -1,    22,   121,   120,    -1,    -1,   123,   122,
      -1,   123,    17,   109,    18,    -1,    65,   123,   122,    -1,
      -1,   125,   124,    -1,   125,    17,   109,    18,    -1,    66,
     125,   124,    -1,    -1,   127,   126,    -1,   127,    17,   109,
      18,    -1,    67,   127,   126,    -1,    -1,   129,   128,    -1,
     129,    17,   109,    18,    -1,    23,   129,   128,    -1,    24,
     129,   128,    -1,    -1,   131,   130,    -1,   131,    17,   109,
      18,    -1,    25,   131,   130,    -1,    26,   131,   130,    -1,
      27,   131,   130,    -1,    -1,    28,   131,    -1,    29,   131,
      -1,    23,   131,    -1,    24,   131,    -1,   137,    -1,    30,
     131,    -1,    31,   131,    -1,   132,    -1,    17,   109,    18,
      -1,    17,    82,    18,   131,    -1,    17,   133,    18,   136,
      -1,   134,    -1,   135,    -1,    71,    -1,    82,     8,     9,
      -1,   137,    -1,    31,   131,    -1,    30,   131,    -1,   132,
      -1,   102,   138,    -1,    28,   138,    -1,    29,   138,    -1,
      -1,   152,    -1,    71,    14,   139,    -1,    33,    17,    96,
      18,   140,    -1,    35,    17,    96,    18,   139,    -1,    32,
      17,   141,     7,   149,     7,   151,    18,   139,    -1,   139,
      -1,   169,    34,   139,    -1,   142,    -1,    81,    -1,    -1,
     144,   143,    -1,    11,   144,   143,    -1,    -1,   102,   100,
      97,    -1,   145,    -1,   146,    -1,   147,    -1,    28,   131,
      -1,   137,    -1,    29,   131,    -1,    71,    17,   103,    18,
      -1,    98,    17,   103,    18,    -1,    64,    12,    71,    17,
     103,    18,    -1,    96,    -1,    -1,   142,    -1,   150,    -1,
      -1,    75,    -1,   153,    -1,   154,    -1,   155,    -1,   163,
      -1,   164,    -1,   165,    -1,   166,    -1,   167,    -1,     7,
      -1,   144,     7,    -1,    37,    17,    96,    18,   156,    -1,
       4,   157,   160,     5,    -1,   159,   158,    -1,   158,    -1,
     159,   158,    -1,    -1,   160,    76,    -1,   162,   161,    -1,
     161,    -1,   162,   161,    -1,    -1,    36,    96,    14,    -1,
      38,    14,    -1,    39,   139,    35,    17,    96,    18,     7,
      -1,    40,   168,     7,    -1,    41,   168,     7,    -1,    42,
     168,     7,    -1,    43,   149,     7,    -1,    71,    -1,    -1,
     152,    -1,    71,    14,   169,    -1,    33,    17,    96,    18,
     169,    34,   169,    -1,    35,    17,    96,    18,   169,    -1,
      32,    17,   141,     7,   149,     7,   151,    18,   169,    -1,
     172,   171,    -1,    -1,   172,   171,    -1,    -1,     6,   173,
      -1,   182,    -1,   174,    -1,   175,   178,    -1,   176,   177,
      -1,    82,    -1,   135,    -1,    44,    -1,    71,    17,   179,
      18,    -1,    75,    -1,     7,    -1,    -1,   181,   180,    -1,
     180,    -1,    11,   181,   180,    -1,    -1,    82,    90,    -1,
     135,    90,    -1,   183,    82,    86,     7,    -1,   183,    82,
       8,     9,    86,     7,    -1,   184,   183,    -1,    -1,    57,
      -1,    58,    -1,    59,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    45,    45,    47,    49,    51,    53,    55,    58,    60,
      61,    63,    64,    66,    67,    69,    71,    72,    74,    75,
      78,    79,    80,    82,    83,    85,    86,    87,    88,    89,
      91,    92,    94,    96,    98,    99,   101,   102,   104,   106,
     107,   108,   110,   111,   113,   114,   116,   117,   119,   120,
     122,   124,   126,   128,   129,   131,   132,   133,   134,   136,
     138,   139,   140,   141,   142,   144,   145,   147,   148,   150,
     152,   154,   155,   157,   158,   162,   163,   164,   165,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     181,   182,   184,   185,   187,   188,   190,   191,   193,   194,
     196,   197,   199,   200,   202,   203,   205,   206,   208,   209,
     211,   212,   214,   215,   217,   218,   220,   221,   223,   224,
     226,   227,   229,   230,   232,   233,   234,   236,   237,   239,
     240,   241,   242,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   254,   255,   257,   258,   260,   262,   265,   266,
     267,   268,   270,   272,   273,   274,   276,   277,   278,   279,
     280,   282,   283,   285,   286,   287,   289,   291,   292,   294,
     295,   296,   297,   299,   301,   303,   306,   307,   308,   310,
     311,   313,   315,   316,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   328,   330,   333,   335,   337,   338,   340,
     341,   343,   345,   346,   348,   349,   351,   352,   355,   357,
     359,   361,   363,   365,   366,   368,   369,   370,   371,   372,
     374,   375,   377,   378,   380,   382,   383,   385,   387,   389,
     390,   391,   393,   395,   396,   397,   399,   400,   402,   403,
     405,   406,   408,   409,   412,   413,   415,   416,   417
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "BEG", "END", "STATIC",
  "PT_VIRGULA", "OPEN_COLC", "CLOSE_COLC", "EQUAL", "VIRGULA", "POINT",
  "QUESTION_MARK", "TWO_POINTS", "OR_LOGIC", "AND_LOGIC", "OPEN_PAREN",
  "CLOSE_PAREN", "NEW", "OR", "OR_EXC", "AND", "PLUS", "MINUS", "MULT",
  "DIV", "MOD", "INCREMENT", "DECREMENT", "NOT", "NOT_BIT", "FOR", "IF",
  "ELSE", "WHILE", "CASE", "SWITCH", "DEFAULT", "DO", "BREAK", "CONTINUE",
  "GOTO", "RETURN", "VOID", "MAIN", "ARGS", "PUBLIC", "TYPE_INT",
  "TYPE_SHORT", "TYPE_LONG", "TYPE_BYTE", "TYPE_BOOL", "TYPE_FLOAT",
  "TYPE_DOUBLE", "TYPE_CHAR", "TYPE_STRING", "FINAL", "TRANSIENT",
  "VOLATILE", "ID", "SHIFT_ASSIGN", "ARITH_ASSIGN", "LOGIC_ASSIGN",
  "LITERAL", "EQUALOP", "RELOP", "SHIFTS", "$accept", "compilation_unit",
  "class_declaration", "identifier", "class_body",
  "class_body_declaration", "static_initializer", "block",
  "block_statements", "block_statements_", "block_statement",
  "local_variable_declaration_statement", "local_variable_declaration_",
  "local_variable_declaration", "primitive_type", "numeric_type",
  "integral_type", "floating_point_type", "variable_declarators",
  "variable_declarator", "variable_declarators_", "variable_declarator_",
  "variable_declarator_id", "variable_initializer", "array_initializer",
  "virgula_opt", "variable_initializers", "variable_initializers_",
  "expression", "assignment_expression", "field_access", "left_hand_side",
  "assignment_operator", "array_access", "primary_no_new_array",
  "argument_list", "argument_list_", "array_creation_expression",
  "dim_exprs", "dim_expr_or_empty", "dims", "conditional_expression",
  "conditional_opt", "conditional_or_expression",
  "conditional_or_expression_", "conditional_and_expression",
  "conditional_and_expression_", "inclusive_or_expression",
  "inclusive_or_expression_", "exclusive_or_expression",
  "exclusive_or_expression_", "and_expression", "and_expression_",
  "equality_expression", "equality_expression_", "relational_expression",
  "relational_expression_", "shift_expression", "shift_expression_",
  "additive_expression", "additive_expression_",
  "multiplicative_expression", "multiplicative_expression_",
  "unary_expression", "cast_expression", "reference_type", "class_type",
  "array_type", "unary_expression_not_plus_minus", "postfix_expression",
  "postfix_expression_", "statement", "optional_else", "for_init",
  "statement_expression_list", "statement_expression_list_",
  "statement_expression", "preincrement_expression",
  "post_incr_decrement_expression", "predecrement_expression",
  "method_invocation", "expression_opt", "for_update", "for_update_opt",
  "statement_without_trailing_substatement", "empty_statement",
  "expression_statement", "switch_statement", "switch_block",
  "switch_block_statement_groups", "switch_block_statement_groups_",
  "switch_block_statement_group", "switch_labels", "switch_labels_",
  "switch_label", "do_statement", "break_statement", "continue_statement",
  "goto_statement", "return_statement", "identifier_opt",
  "statement_no_short_if", "class_member_declaration_opt",
  "class_member_declaration_", "class_member_declaration",
  "field_or_method_declaration", "method_declaration", "method_header",
  "result_type", "method_declarator", "method_body",
  "formal_parameter_list", "formal_parameter_list_", "formal_parameter",
  "field_declaration", "field_modifiers_", "field_modifier", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      76,    77,    77,    78,    78,    79,    80,    80,    81,    81,
      82,    82,    82,    83,    83,    84,    84,    84,    84,    84,
      85,    85,    86,    87,    88,    88,    89,    89,    90,    91,
      91,    91,    92,    92,    93,    93,    94,    94,    95,    95,
      96,    97,    98,    99,    99,   100,   100,   100,   100,   101,
     102,   102,   102,   102,   102,   103,   103,   104,   104,   105,
     106,   107,   107,   108,   108,   109,   109,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   119,   119,   120,   120,
     121,   121,   122,   122,   123,   123,   124,   124,   125,   125,
     126,   126,   127,   127,   128,   128,   128,   129,   129,   130,
     130,   130,   130,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   132,   132,   133,   133,   134,   135,   136,   136,
     136,   136,   137,   138,   138,   138,   139,   139,   139,   139,
     139,   140,   140,   141,   141,   141,   142,   143,   143,   144,
     144,   144,   144,   145,   146,   147,   148,   148,   148,   149,
     149,   150,   151,   151,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   153,   154,   155,   156,   157,   157,   158,
     158,   159,   160,   160,   161,   161,   162,   162,   163,   164,
     165,   166,   167,   168,   168,   169,   169,   169,   169,   169,
     170,   170,   171,   171,   172,   173,   173,   174,   175,   176,
     176,   176,   177,   178,   178,   178,   179,   179,   180,   180,
     181,   181,   182,   182,   183,   183,   184,   184,   184
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     3,     3,    11,     3,     2,
       1,     2,     0,     1,     1,     3,     2,     0,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     0,     2,     0,     1,     1,
       1,     1,     4,     1,     1,     0,     2,     1,     3,     0,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     4,
       1,     1,     1,     1,     1,     2,     1,     3,     0,     4,
       3,     1,     0,     1,     0,     1,     4,     5,     7,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     4,     3,     0,     2,     4,     3,     0,     2,     4,
       3,     0,     2,     4,     3,     0,     2,     4,     3,     0,
       2,     4,     3,     0,     2,     4,     3,     0,     2,     4,
       3,     0,     2,     4,     3,     3,     0,     2,     4,     3,
       3,     3,     0,     2,     2,     2,     2,     1,     2,     2,
       1,     3,     4,     4,     1,     1,     1,     3,     1,     2,
       2,     1,     2,     2,     2,     0,     1,     3,     5,     5,
       9,     1,     3,     1,     1,     0,     2,     3,     0,     3,
       1,     1,     1,     2,     1,     2,     4,     4,     6,     1,
       0,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     5,     4,     2,     1,     2,
       0,     2,     2,     1,     2,     0,     3,     2,     7,     3,
       3,     3,     3,     1,     0,     1,     3,     7,     5,     9,
       2,     0,     2,     0,     2,     1,     1,     2,     2,     1,
       1,     1,     4,     1,     1,     0,     2,     1,     3,     0,
       2,     2,     4,     6,     2,     0,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,   221,     3,     0,
       0,     0,   223,   231,    27,    26,    28,    25,    21,    30,
      31,    29,    22,   246,   247,   248,   229,    20,    23,    24,
     230,   224,   226,   235,     0,   225,     0,   245,     5,     0,
     221,   220,   223,     0,    12,   234,   233,   227,     0,   228,
       0,   244,     0,     6,   222,   147,   193,     0,     0,     0,
       0,     0,     0,     0,   214,   214,   214,   180,    60,    64,
     184,     0,    10,    12,    13,     0,     0,    61,    63,   155,
     174,    14,     0,   170,   171,   172,    62,   156,   185,   186,
     187,   188,   189,   190,   191,   192,   239,     0,    38,     0,
      35,    37,     0,     0,     0,     0,     0,     0,     0,     0,
      64,   155,   173,   140,   137,   175,   165,     0,     0,     0,
       0,   213,     0,     0,     0,     0,   179,    50,    51,    75,
      93,    97,   101,   105,   109,   113,   117,   121,   126,   132,
       0,     0,     0,     0,    68,     8,     9,    12,    17,     0,
      18,    68,     0,    55,   155,   155,    57,    56,    58,     0,
     152,   194,     0,     0,     0,     0,   237,   239,     0,   242,
       0,    32,     0,    33,     0,    64,     0,     0,     0,   144,
     145,   135,   136,   133,   134,   138,   139,   164,     0,   163,
     168,     0,     0,     0,     0,   209,   210,   211,     0,     0,
       0,     0,    90,     0,     0,    94,     0,     0,    98,     0,
       0,   102,     0,     0,   106,     0,     0,   110,     0,     0,
     114,     0,     0,   118,     0,     0,     0,   122,     0,     0,
       0,     0,   127,   212,     0,    52,   157,     0,    68,     0,
      66,    11,    15,     0,     0,     0,     0,   153,   154,   169,
     239,   240,   241,   232,   236,     0,    35,    49,     0,    36,
      40,    39,    61,    41,    63,    43,     0,     0,   141,     0,
     180,     0,   166,     0,     0,     0,     0,    89,     0,    93,
       0,    97,     0,     0,   101,     0,   105,     0,   109,     0,
     113,     0,   117,     0,   121,     0,   126,   126,     0,   132,
     132,   132,    68,    68,    65,   176,    16,    19,   177,    59,
     238,   243,    34,     0,    49,    45,    47,     0,     0,   142,
       0,     0,     0,   151,   143,   148,     0,   168,     0,     0,
       0,    64,   161,   158,   156,     0,   159,   205,   195,     0,
       0,    76,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,    92,    91,    96,    95,    99,   100,   103,
     104,   107,   108,   111,   112,   115,   116,   119,   120,   123,
     124,   125,   128,   129,   130,   131,     0,    67,    49,    46,
      44,     0,    72,    74,     0,   146,   150,   149,   183,   167,
     165,     0,     0,     0,     0,     0,     0,   205,   198,   205,
      12,   203,   205,     0,     0,    77,   178,    48,    42,    71,
       0,    73,    69,     0,   181,   182,     0,     0,     0,     0,
     216,   162,     0,   207,     0,   197,   205,   201,   202,   205,
     208,     0,    70,     0,     0,   180,     0,     0,   206,   196,
     199,   204,    78,     0,   160,     0,     0,   218,     7,   183,
       0,     0,   217,     0,   219
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   110,     8,    10,    40,    70,    71,    72,
      73,    74,   242,    75,    76,    27,    28,    29,    99,   100,
     171,   173,   101,   259,   260,   381,   315,   316,   126,   127,
      77,   263,   159,    78,   111,   239,   240,   265,   383,   410,
     412,   128,   341,   129,   202,   130,   205,   131,   208,   132,
     211,   133,   214,   134,   217,   135,   220,   136,   223,   137,
     227,   138,   232,   139,   113,   178,   179,   180,   324,   114,
     160,    81,   333,   188,   189,   272,    82,    83,    84,    85,
      86,   140,   415,   416,    87,    88,    89,    90,   338,   397,
     398,   426,   400,   401,   402,    91,    92,    93,    94,    95,
     122,   335,    11,    41,    12,    31,    32,    33,    34,    49,
      47,   165,   166,   167,    35,    36,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -368
static const yytype_int16 yypact[] =
{
      50,    62,   134,  -368,  -368,   153,  -368,   133,  -368,   595,
     161,   129,   133,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,  -368,   179,  -368,  -368,  -368,
    -368,  -368,  -368,    44,    62,  -368,   620,   182,  -368,   173,
     133,  -368,   133,   194,   425,  -368,  -368,  -368,   209,  -368,
      18,  -368,   198,  -368,  -368,  -368,  -368,   551,   551,   228,
     241,   245,   249,   267,    62,    62,    62,   578,   258,   204,
    -368,   271,  -368,   425,  -368,   280,    31,   277,  -368,   253,
    -368,  -368,   296,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,  -368,   392,   303,  -368,   298,
     302,   307,   275,   536,   551,   551,   551,   551,   551,   551,
      35,    98,  -368,  -368,  -368,  -368,   569,   578,   578,   578,
     286,  -368,   315,   318,   319,   536,  -368,  -368,  -368,   316,
     219,   235,   148,   184,    97,    11,     5,    12,   167,   171,
     321,    62,    62,   267,   513,  -368,  -368,   425,   620,   323,
    -368,   513,   578,  -368,   240,   240,  -368,  -368,  -368,   578,
    -368,  -368,   620,    33,    62,   312,  -368,   322,    62,  -368,
      62,  -368,   320,  -368,   324,    35,   117,   329,   335,  -368,
    -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,   331,  -368,
     344,   338,   341,   342,   325,  -368,  -368,  -368,   214,   578,
     551,   578,  -368,   551,   578,  -368,   578,   551,  -368,   578,
     551,  -368,   578,   551,  -368,   578,   551,  -368,   578,   551,
    -368,   578,   551,  -368,   578,   551,   551,  -368,   578,   551,
     551,   551,  -368,  -368,   345,  -368,  -368,   578,   354,   350,
    -368,  -368,  -368,   333,    62,   351,   361,  -368,  -368,  -368,
     322,  -368,  -368,  -368,  -368,   364,   302,   200,   620,  -368,
    -368,  -368,   195,  -368,   142,  -368,   326,   551,  -368,   121,
     578,    84,  -368,   465,   267,   368,   578,   496,   360,   366,
     358,   363,   365,   367,   369,   370,   374,   372,   375,   378,
     339,   387,   340,   390,   348,   394,   255,   255,   398,   223,
     223,   223,   513,   354,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,   320,   376,   407,  -368,   411,   412,  -368,
     607,   551,   551,  -368,  -368,  -368,   379,   344,   404,   408,
     410,   208,  -368,  -368,   396,   397,  -368,    30,  -368,   406,
     578,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,   578,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,  -368,   416,  -368,   376,  -368,
    -368,   423,   578,   411,   428,  -368,  -368,  -368,    84,  -368,
     569,   578,   578,   465,   267,   578,   424,   221,  -368,    30,
     425,  -368,   221,   432,   436,  -368,  -368,  -368,  -368,  -368,
     442,  -368,  -368,   409,  -368,  -368,   438,   452,   443,   445,
    -368,  -368,   456,  -368,   466,  -368,    30,  -368,  -368,   221,
    -368,   578,  -368,   464,   267,   578,   465,   465,  -368,  -368,
    -368,  -368,  -368,   479,  -368,   477,   453,  -368,  -368,    84,
     465,   468,  -368,   465,  -368
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -368,  -368,  -368,    -1,  -368,  -368,  -368,   -32,    88,   -60,
     -57,  -368,  -368,  -110,    -2,  -368,  -368,  -368,   -71,   343,
     234,  -368,   120,  -236,  -368,  -368,  -368,  -295,   -94,  -157,
    -158,  -368,  -368,  -154,   -27,  -141,  -218,  -368,   108,  -368,
    -368,   -29,  -368,   371,   -12,   292,   -68,   300,  -106,   288,
    -132,   289,  -233,   297,  -223,   285,  -232,   295,  -221,   293,
    -160,    60,  -191,    24,   257,  -368,  -368,     2,  -368,   -36,
     135,   -59,  -368,   137,  -357,   201,  -113,  -368,  -368,  -368,
    -368,  -261,  -368,    82,  -243,  -368,  -368,  -368,  -368,  -368,
    -367,   196,   138,  -360,  -314,  -368,  -368,  -368,  -368,  -368,
     227,  -332,   492,   497,    28,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -155,   383,  -368,   501,  -368
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -216
static const yytype_int16 yytable[] =
{
       5,    46,   249,   190,   120,   150,   187,    26,    80,   326,
     245,    30,   254,   146,   262,   261,   147,    79,   264,   379,
     304,   314,   218,   191,   192,   193,    97,    80,   215,   221,
     334,   414,   425,    48,    50,  -200,    79,    80,   243,   149,
      42,    43,   428,    69,   346,   348,    79,   142,    44,    98,
     238,    45,   144,     1,   347,   362,   349,   238,   246,   440,
     366,   420,    69,   121,   121,   121,   395,   364,   396,   441,
      42,   219,    69,   368,   177,    98,   216,   378,     4,   222,
      80,   112,   115,   407,   236,   377,   351,   241,   429,    79,
     147,     4,   414,     4,   163,   310,   177,   255,   164,   262,
     261,   176,   175,   264,   446,   447,   152,    80,   373,   374,
     375,    80,    57,    58,   212,   429,    79,   350,   452,   213,
      79,   454,     4,   176,   175,    43,   154,   155,   181,   182,
     183,   184,   185,   186,     6,   267,   370,   371,   320,     9,
     234,   235,    69,   303,     4,   345,    69,   -54,    68,   -54,
     334,   321,   322,   -54,   360,   262,   261,     7,   327,   264,
     163,   376,    98,    98,   164,   206,    38,    98,   207,    98,
     278,   344,   280,   307,   445,   282,    39,   283,   358,    52,
     285,     4,   339,   287,   224,    68,   289,    43,   228,   291,
     225,   226,   293,   334,   334,   295,   229,   230,   231,   298,
     -53,   209,   -53,    55,   257,   210,   -53,   334,   238,   343,
     334,   313,   151,   355,   332,   336,   142,   125,   143,   258,
     142,   144,   393,   104,   105,   144,    96,   199,   106,   107,
     108,   109,   277,   325,   200,    80,   201,    80,    80,    23,
      24,    25,   102,    98,    79,   116,    79,    79,   229,   230,
     231,   203,   204,   299,   300,   301,   317,   395,   117,   396,
       4,   152,   118,   153,    68,   342,   119,   353,   154,   155,
     141,    44,   331,    69,    56,   190,   145,   190,   225,   226,
     187,   154,   155,   251,   252,   296,   297,   148,   409,   247,
     248,   319,   123,   124,   151,    57,    58,   418,   419,    59,
      60,   422,    61,   161,    62,   169,    63,    64,    65,    66,
      67,   404,   168,   170,   156,   157,   158,   172,   176,   385,
     174,   194,   195,   405,   257,   196,   197,     4,   233,   199,
     253,    68,   244,   162,   236,   421,   190,   125,   270,   258,
     306,   266,   276,   104,   105,   386,   387,   268,   106,   107,
     108,   109,    80,   269,    80,   271,   273,    80,    80,   274,
     275,    79,   302,    79,    80,   237,    79,    79,   305,   308,
     309,   311,   337,    79,   352,   444,   354,   332,   336,   203,
       4,   200,   318,   356,    68,   357,   388,   313,   359,   207,
     361,   421,   331,    69,   444,   210,   363,   213,    80,    69,
      80,    80,   442,   162,   216,   365,   219,    79,   367,    79,
      79,   448,   369,    80,    80,   222,   372,    80,   380,   382,
     384,   390,    79,    79,   403,   391,    79,   392,   408,    44,
    -215,   394,    56,    69,   406,   331,   331,   413,   423,   430,
      14,    15,    16,    17,    18,    19,    20,    21,    22,   331,
     431,   432,   331,    57,    58,   433,   434,    59,    60,   435,
      61,   436,    62,   437,    63,    64,    65,    66,    67,    44,
     438,   439,    56,    14,    15,    16,    17,    18,    19,    20,
      21,    22,   443,    44,   449,     4,   453,   450,   427,    68,
     312,   411,   279,    57,    58,   284,   198,   328,   329,   286,
     330,   290,    62,   281,    63,    64,    65,    66,    67,   340,
     288,   200,   203,   256,   292,   294,   207,   210,   213,   225,
     226,   229,   230,   231,   237,     4,   323,   417,   389,    68,
     125,   451,    53,   399,     0,   424,   104,   105,    51,    54,
       0,   106,   107,   108,   109,   250,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,   104,
     105,   216,   219,   222,   106,   107,   108,   109,   103,     0,
       0,     0,     0,     4,   104,   105,     0,    68,     0,   106,
     107,   108,   109,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     0,   125,     4,    57,    58,     0,
      68,   104,   105,     0,     0,     0,   106,   107,   108,   109,
       0,     4,     0,     0,     0,    68,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     0,     0,     0,     4,
       0,     0,     0,    68,     0,     0,     0,     0,     4,    13,
       0,     0,    68,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,     0,     0,     4,    14,    15,
      16,    17,    18,    19,    20,    21,    22
};

static const yytype_int16 yycheck[] =
{
       1,    33,   159,   116,    63,    76,   116,     9,    44,   270,
     151,     9,   167,    73,   172,   172,    73,    44,   172,   314,
     238,   257,    17,   117,   118,   119,     8,    63,    17,    17,
     273,   388,   399,    34,    36,     5,    63,    73,   148,     8,
      12,     8,   402,    44,   277,   277,    73,    12,     4,    50,
     144,     7,    17,     3,   277,   288,   277,   151,   152,   426,
     292,   393,    63,    64,    65,    66,    36,   290,    38,   429,
      42,    66,    73,   294,   103,    76,    65,   313,    60,    67,
     116,    57,    58,   378,   143,   303,   277,   147,   402,   116,
     147,    60,   449,    60,    96,   250,   125,   168,    96,   257,
     257,   103,   103,   257,   436,   437,     8,   143,   299,   300,
     301,   147,    28,    29,    17,   429,   143,   277,   450,    22,
     147,   453,    60,   125,   125,     8,    28,    29,   104,   105,
     106,   107,   108,   109,     0,    18,   296,   297,    17,     6,
     141,   142,   143,   237,    60,   277,   147,     5,    64,     7,
     393,    30,    31,    11,   286,   313,   313,     4,   271,   313,
     162,   302,   163,   164,   162,    17,     5,   168,    20,   170,
     199,   277,   201,   244,   435,   204,    47,   206,   284,     6,
     209,    60,   276,   212,    17,    64,   215,     8,    17,   218,
      23,    24,   221,   436,   437,   224,    25,    26,    27,   228,
       5,    17,     7,     9,     4,    21,    11,   450,   302,   277,
     453,    11,    17,   281,   273,   274,    12,    17,    14,    19,
      12,    17,    14,    23,    24,    17,    17,    13,    28,    29,
      30,    31,    18,   269,    15,   271,    17,   273,   274,    57,
      58,    59,    44,   244,   271,    17,   273,   274,    25,    26,
      27,    16,    17,   229,   230,   231,   258,    36,    17,    38,
      60,     8,    17,    10,    64,   277,    17,   279,    28,    29,
      12,     4,   273,   274,     7,   388,     5,   390,    23,    24,
     390,    28,    29,   163,   164,   225,   226,     7,   382,   154,
     155,   267,    65,    66,    17,    28,    29,   391,   392,    32,
      33,   395,    35,     7,    37,     7,    39,    40,    41,    42,
      43,   340,     9,    11,    61,    62,    63,    10,   320,   320,
      45,    35,     7,   352,     4,     7,     7,    60,     7,    13,
      18,    64,     9,    11,   393,   394,   449,    17,     7,    19,
       7,    17,    17,    23,    24,   321,   322,    18,    28,    29,
      30,    31,   388,    18,   390,    11,    18,   393,   394,    18,
      18,   388,    17,   390,   400,    11,   393,   394,    18,    18,
       9,     7,     4,   400,    14,   434,    18,   436,   437,    16,
      60,    15,    56,    18,    64,    18,     7,    11,    18,    20,
      18,   450,   393,   394,   453,    21,    18,    22,   434,   400,
     436,   437,   431,    11,    65,    18,    66,   434,    18,   436,
     437,   443,    18,   449,   450,    67,    18,   453,    11,     8,
       8,    17,   449,   450,    18,    17,   453,    17,     5,     4,
      34,    34,     7,   434,    18,   436,   437,     9,    14,     7,
      48,    49,    50,    51,    52,    53,    54,    55,    56,   450,
      14,     9,   453,    28,    29,    46,    18,    32,    33,     7,
      35,    18,    37,    18,    39,    40,    41,    42,    43,     4,
      14,     5,     7,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    18,     4,     7,    60,    18,    34,   400,    64,
     256,   383,   200,    28,    29,   207,   125,    32,    33,   210,
      35,   216,    37,   203,    39,    40,    41,    42,    43,    13,
     213,    15,    16,   170,   219,   222,    20,    21,    22,    23,
      24,    25,    26,    27,    11,    60,   269,   390,   327,    64,
      17,   449,    40,   337,    -1,   397,    23,    24,    37,    42,
      -1,    28,    29,    30,    31,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    23,
      24,    65,    66,    67,    28,    29,    30,    31,    17,    -1,
      -1,    -1,    -1,    60,    23,    24,    -1,    64,    -1,    28,
      29,    30,    31,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    17,    60,    28,    29,    -1,
      64,    23,    24,    -1,    -1,    -1,    28,    29,    30,    31,
      -1,    60,    -1,    -1,    -1,    64,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    60,    44,
      -1,    -1,    64,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    60,    48,    49,
      50,    51,    52,    53,    54,    55,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    69,    70,    60,    71,     0,     4,    72,     6,
      73,   170,   172,    44,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    82,    83,    84,    85,
     135,   173,   174,   175,   176,   182,   183,   184,     5,    47,
      74,   171,   172,     8,     4,     7,    75,   178,    71,   177,
      82,   183,     6,   170,   171,     9,     7,    28,    29,    32,
      33,    35,    37,    39,    40,    41,    42,    43,    64,    71,
      75,    76,    77,    78,    79,    81,    82,    98,   101,   102,
     137,   139,   144,   145,   146,   147,   148,   152,   153,   154,
     155,   163,   164,   165,   166,   167,    17,     8,    71,    86,
      87,    90,    44,    17,    23,    24,    28,    29,    30,    31,
      71,   102,   131,   132,   137,   131,    17,    17,    17,    17,
     139,    71,   168,   168,   168,    17,    96,    97,   109,   111,
     113,   115,   117,   119,   121,   123,   125,   127,   129,   131,
     149,    12,    12,    14,    17,     5,    77,    78,     7,     8,
      86,    17,     8,    10,    28,    29,    61,    62,    63,   100,
     138,     7,    11,    82,   135,   179,   180,   181,     9,     7,
      11,    88,    10,    89,    45,    71,    82,   109,   133,   134,
     135,   131,   131,   131,   131,   131,   131,    81,   141,   142,
     144,    96,    96,    96,    35,     7,     7,     7,   111,    13,
      15,    17,   112,    16,    17,   114,    17,    20,   116,    17,
      21,   118,    17,    22,   120,    17,    65,   122,    17,    66,
     124,    17,    67,   126,    17,    23,    24,   128,    17,    25,
      26,    27,   130,     7,    71,    71,   139,    11,    96,   103,
     104,    77,    80,    81,     9,   103,    96,   138,   138,    97,
     181,    90,    90,    18,   180,    86,    87,     4,    19,    91,
      92,    97,    98,    99,   101,   105,    17,    18,    18,    18,
       7,    11,   143,    18,    18,    18,    17,    18,   109,   113,
     109,   115,   109,   109,   117,   109,   119,   109,   121,   109,
     123,   109,   125,   109,   127,   109,   129,   129,   109,   131,
     131,   131,    17,    96,   104,    18,     7,    86,    18,     9,
     180,     7,    88,    11,    91,    94,    95,    82,    56,   131,
      17,    30,    31,   132,   136,   137,   149,   144,    32,    33,
      35,    71,   139,   140,   152,   169,   139,     4,   156,    96,
      13,   110,   112,   114,   116,   118,   120,   122,   124,   126,
     128,   130,    14,   112,    18,   114,    18,    18,   116,    18,
     118,    18,   120,    18,   122,    18,   124,    18,   126,    18,
     128,   128,    18,   130,   130,   130,   103,   104,    91,    95,
      11,    93,     8,   106,     8,    71,   131,   131,     7,   143,
      17,    17,    17,    14,    34,    36,    38,   157,   158,   159,
     160,   161,   162,    18,   109,   109,    18,    95,     5,    96,
     107,   106,   108,     9,   142,   150,   151,   141,    96,    96,
     169,   139,    96,    14,   160,   158,   159,    76,   161,   162,
       7,    14,     9,    46,    18,     7,    18,    18,    14,     5,
     158,   161,   109,    18,   139,   149,   169,   169,    75,     7,
      34,   151,   169,    18,   169
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
      

/* Line 1455 of yacc.c  */
#line 1971 "sintatico.c"
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
#line 423 "sintatico.y"


int main(void) {
	yydebug=0;
	return yyparse();
}

//funcao de erro - imprime linha e coluna do erro sintatico
int yyerror(char *msg){
        int tk = YYTRANSLATE(yychar);
        fprintf(stderr,"%s:\n",msg);
	fprintf(stderr,"\tLast Token: %s - %s\n",yytname[tk],yytext);
        fprintf(stderr,"\tLine %d, Column %d\n", line, column);
        return 1;
}

