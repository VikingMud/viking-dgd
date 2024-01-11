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
     STRING = 258,
     NOMASK = 259,
     NIL = 260,
     BREAK = 261,
     ELSE = 262,
     CASE = 263,
     WHILE = 264,
     DEFAULT = 265,
     STATIC = 266,
     CONTINUE = 267,
     INT = 268,
     RLIMITS = 269,
     FLOAT = 270,
     FOR = 271,
     INHERIT = 272,
     VOID = 273,
     IF = 274,
     CATCH = 275,
     SWITCH = 276,
     VARARGS = 277,
     MAPPING = 278,
     PRIVATE = 279,
     DO = 280,
     RETURN = 281,
     ATOMIC = 282,
     MIXED = 283,
     OBJECT = 284,
     LARROW = 285,
     RARROW = 286,
     PLUS_PLUS = 287,
     MIN_MIN = 288,
     LSHIFT = 289,
     RSHIFT = 290,
     LE = 291,
     GE = 292,
     EQ = 293,
     NE = 294,
     LAND = 295,
     LOR = 296,
     PLUS_EQ = 297,
     MIN_EQ = 298,
     MULT_EQ = 299,
     DIV_EQ = 300,
     MOD_EQ = 301,
     LSHIFT_EQ = 302,
     RSHIFT_EQ = 303,
     AND_EQ = 304,
     XOR_EQ = 305,
     OR_EQ = 306,
     COLON_COLON = 307,
     DOT_DOT = 308,
     ELLIPSIS = 309,
     STRING_CONST = 310,
     IDENTIFIER = 311,
     INT_CONST = 312,
     FLOAT_CONST = 313,
     MARK = 314,
     HASH = 315,
     HASH_HASH = 316,
     INCL_CONST = 317,
     NR_TOKENS = 318
   };
#endif
/* Tokens.  */
#define STRING 258
#define NOMASK 259
#define NIL 260
#define BREAK 261
#define ELSE 262
#define CASE 263
#define WHILE 264
#define DEFAULT 265
#define STATIC 266
#define CONTINUE 267
#define INT 268
#define RLIMITS 269
#define FLOAT 270
#define FOR 271
#define INHERIT 272
#define VOID 273
#define IF 274
#define CATCH 275
#define SWITCH 276
#define VARARGS 277
#define MAPPING 278
#define PRIVATE 279
#define DO 280
#define RETURN 281
#define ATOMIC 282
#define MIXED 283
#define OBJECT 284
#define LARROW 285
#define RARROW 286
#define PLUS_PLUS 287
#define MIN_MIN 288
#define LSHIFT 289
#define RSHIFT 290
#define LE 291
#define GE 292
#define EQ 293
#define NE 294
#define LAND 295
#define LOR 296
#define PLUS_EQ 297
#define MIN_EQ 298
#define MULT_EQ 299
#define DIV_EQ 300
#define MOD_EQ 301
#define LSHIFT_EQ 302
#define RSHIFT_EQ 303
#define AND_EQ 304
#define XOR_EQ 305
#define OR_EQ 306
#define COLON_COLON 307
#define DOT_DOT 308
#define ELLIPSIS 309
#define STRING_CONST 310
#define IDENTIFIER 311
#define INT_CONST 312
#define FLOAT_CONST 313
#define MARK 314
#define HASH 315
#define HASH_HASH 316
#define INCL_CONST 317
#define NR_TOKENS 318




/* Copy the first part of user declarations.  */
#line 25 "parser.y"


# define INCLUDE_CTYPE
# include "comp.h"
# include "str.h"
# include "array.h"
# include "object.h"
# include "xfloat.h"
# include "interpret.h"
# include "macro.h"
# include "token.h"
# include "ppcontrol.h"
# include "node.h"
# include "compile.h"

# define yylex		pp_gettok
# define yyerror	c_error

int nerrors;			/* number of errors encountered so far */
static int ndeclarations;	/* number of declarations */
static int nstatements;		/* number of statements in current function */
static bool typechecking;	/* does the current function have it? */

static void  t_void	(node*);
static bool  t_unary	(node*, char*);
static node *uassign	(int, node*, char*);
static node *cast	(node*, node*);
static node *idx	(node*, node*);
static node *range	(node*, node*, node*);
static node *bini	(int, node*, node*, char*);
static node *bina	(int, node*, node*, char*);
static node *mult	(int, node*, node*, char*);
static node *mdiv	(int, node*, node*, char*);
static node *mod	(int, node*, node*, char*);
static node *add	(int, node*, node*, char*);
static node *sub	(int, node*, node*, char*);
static node *umin	(node*);
static node *lshift	(int, node*, node*, char*);
static node *rshift	(int, node*, node*, char*);
static node *rel	(int, node*, node*, char*);
static node *eq		(node*, node*);
static node *and	(int, node*, node*, char*);
static node *xor	(int, node*, node*, char*);
static node *or		(int, node*, node*, char*);
static node *land	(node*, node*);
static node *lor	(node*, node*);
static node *quest	(node*, node*, node*);
static node *assign	(node*, node*);
static node *comma	(node*, node*);



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
#line 92 "parser.y"
{
    Int number;			/* lex input */
    xfloat real;		/* lex input */
    unsigned short type;	/* internal */
    struct _node_ *node;	/* internal */
}
/* Line 187 of yacc.c.  */
#line 281 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 294 "y.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   471

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  195
/* YYNRULES -- Number of states.  */
#define YYNSTATES  339

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    76,     2,     2,     2,    79,    82,     2,
      66,    67,    69,    65,    68,    75,     2,    78,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    70,    64,
      80,    86,    81,    85,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    74,    83,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,    84,    72,    77,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    11,    17,    19,    21,
      22,    24,    26,    28,    32,    36,    38,    43,    44,    50,
      51,    59,    64,    65,    67,    69,    72,    74,    78,    81,
      83,    86,    88,    90,    92,    95,    97,   100,   102,   104,
     105,   107,   109,   111,   113,   115,   117,   119,   121,   123,
     126,   128,   130,   132,   133,   136,   139,   145,   147,   149,
     151,   155,   156,   159,   161,   163,   166,   167,   174,   177,
     179,   181,   182,   187,   188,   197,   198,   205,   206,   217,
     218,   227,   228,   229,   235,   236,   243,   244,   250,   251,
     259,   260,   265,   268,   271,   275,   277,   278,   283,   284,
     287,   289,   292,   296,   298,   300,   302,   304,   310,   316,
     318,   322,   327,   328,   334,   341,   345,   351,   353,   358,
     365,   367,   370,   373,   375,   378,   381,   384,   387,   390,
     393,   395,   401,   403,   407,   411,   415,   417,   421,   425,
     427,   431,   435,   437,   441,   445,   449,   453,   455,   459,
     463,   465,   469,   471,   475,   477,   481,   483,   487,   489,
     493,   495,   496,   497,   505,   507,   511,   515,   519,   523,
     527,   531,   535,   539,   543,   547,   551,   553,   557,   558,
     560,   562,   564,   566,   570,   571,   573,   576,   577,   579,
     582,   586,   588,   592,   593,   595
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      88,     0,    -1,    -1,    89,    90,    -1,    -1,    90,    91,
      -1,   108,    17,    92,    94,    64,    -1,    96,    -1,    97,
      -1,    -1,    93,    -1,    56,    -1,    95,    -1,    94,    65,
      95,    -1,    66,    94,    67,    -1,    55,    -1,   105,   110,
     115,    64,    -1,    -1,   105,   110,   113,    98,   132,    -1,
      -1,   105,    93,    66,   101,    67,    99,   132,    -1,   105,
     110,   115,    64,    -1,    -1,    18,    -1,   102,    -1,   102,
      54,    -1,   103,    -1,   102,    68,   103,    -1,    22,   104,
      -1,   104,    -1,   110,   112,    -1,    93,    -1,   108,    -1,
     109,    -1,   107,   106,    -1,   107,    -1,   106,   107,    -1,
      24,    -1,   109,    -1,    -1,    24,    -1,    11,    -1,    27,
      -1,     4,    -1,    22,    -1,    13,    -1,    15,    -1,     3,
      -1,    29,    -1,    29,    94,    -1,    23,    -1,    28,    -1,
      18,    -1,    -1,   111,    69,    -1,   111,    93,    -1,   111,
      93,    66,   101,    67,    -1,   112,    -1,   113,    -1,   114,
      -1,   115,    68,   114,    -1,    -1,   116,   117,    -1,   100,
      -1,   120,    -1,     1,    64,    -1,    -1,    19,    66,   158,
      67,   119,   120,    -1,   156,    64,    -1,   132,    -1,   118,
      -1,    -1,   118,     7,   121,   120,    -1,    -1,    25,   122,
     120,     9,    66,   158,    67,    64,    -1,    -1,     9,    66,
     158,    67,   123,   120,    -1,    -1,    16,    66,   157,    64,
     159,    64,   157,    67,   124,   120,    -1,    -1,    14,    66,
     158,    64,   158,    67,   125,   132,    -1,    -1,    -1,    20,
     126,   132,   127,   134,    -1,    -1,    21,    66,   158,    67,
     128,   132,    -1,    -1,     8,   155,    70,   129,   120,    -1,
      -1,     8,   155,    53,   155,    70,   130,   120,    -1,    -1,
      10,    70,   131,   120,    -1,     6,    64,    -1,    12,    64,
      -1,    26,   159,    64,    -1,    64,    -1,    -1,    71,   133,
     116,    72,    -1,    -1,    70,   120,    -1,    93,    -1,    52,
      93,    -1,    93,    52,    93,    -1,    57,    -1,    58,    -1,
       5,    -1,    95,    -1,    66,    71,   162,    72,    67,    -1,
      66,    73,   165,    74,    67,    -1,    93,    -1,    66,   156,
      67,    -1,   135,    66,   161,    67,    -1,    -1,    20,    66,
     137,   156,    67,    -1,   138,    31,    93,    66,   161,    67,
      -1,   138,    30,    95,    -1,   138,    30,    66,    94,    67,
      -1,   136,    -1,   138,    73,   158,    74,    -1,   138,    73,
     159,    53,   159,    74,    -1,   138,    -1,   139,    32,    -1,
     139,    33,    -1,   139,    -1,    32,   141,    -1,    33,   141,
      -1,    75,   141,    -1,    65,   141,    -1,    76,   141,    -1,
      77,   141,    -1,   140,    -1,    66,   110,   111,    67,   141,
      -1,   141,    -1,   142,    69,   141,    -1,   142,    78,   141,
      -1,   142,    79,   141,    -1,   142,    -1,   143,    65,   142,
      -1,   143,    75,   142,    -1,   143,    -1,   144,    34,   143,
      -1,   144,    35,   143,    -1,   144,    -1,   145,    80,   144,
      -1,   145,    81,   144,    -1,   145,    36,   144,    -1,   145,
      37,   144,    -1,   145,    -1,   146,    38,   145,    -1,   146,
      39,   145,    -1,   146,    -1,   147,    82,   146,    -1,   147,
      -1,   148,    83,   147,    -1,   148,    -1,   149,    84,   148,
      -1,   149,    -1,   150,    40,   149,    -1,   150,    -1,   151,
      41,   150,    -1,   151,    -1,    -1,    -1,   151,    85,   153,
     156,    70,   154,   152,    -1,   152,    -1,   152,    86,   155,
      -1,   152,    42,   155,    -1,   152,    43,   155,    -1,   152,
      44,   155,    -1,   152,    45,   155,    -1,   152,    46,   155,
      -1,   152,    47,   155,    -1,   152,    48,   155,    -1,   152,
      49,   155,    -1,   152,    50,   155,    -1,   152,    51,   155,
      -1,   155,    -1,   156,    68,   155,    -1,    -1,   156,    -1,
     156,    -1,   157,    -1,   155,    -1,   160,    68,   155,    -1,
      -1,   160,    -1,   160,    54,    -1,    -1,   160,    -1,   160,
      68,    -1,   155,    70,   155,    -1,   163,    -1,   164,    68,
     163,    -1,    -1,   164,    -1,   164,    68,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   130,   130,   130,   142,   144,   153,   166,   168,   174,
     175,   179,   184,   185,   187,   192,   197,   203,   202,   214,
     213,   229,   235,   236,   237,   238,   246,   247,   252,   257,
     261,   267,   274,   275,   276,   281,   282,   287,   289,   294,
     295,   300,   302,   304,   306,   311,   312,   313,   315,   317,
     319,   321,   322,   327,   328,   338,   346,   351,   352,   356,
     357,   363,   364,   369,   376,   380,   391,   390,   396,   398,
     399,   406,   405,   412,   412,   416,   415,   425,   424,   434,
     433,   451,   456,   451,   467,   466,   477,   476,   487,   486,
     497,   496,   506,   510,   514,   516,   520,   520,   533,   534,
     539,   540,   542,   547,   549,   551,   552,   553,   555,   557,
     574,   576,   579,   578,   585,   590,   592,   597,   598,   600,
     605,   606,   608,   613,   614,   616,   618,   620,   622,   627,
     644,   645,   653,   654,   656,   658,   663,   664,   666,   671,
     672,   674,   679,   680,   682,   684,   686,   691,   692,   694,
     699,   700,   705,   706,   711,   712,   717,   718,   723,   724,
     729,   731,   733,   730,   742,   743,   745,   747,   749,   751,
     753,   755,   757,   759,   761,   763,   768,   769,   775,   776,
     780,   785,   790,   791,   800,   801,   802,   815,   816,   817,
     822,   831,   832,   838,   839,   840
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "NOMASK", "NIL", "BREAK",
  "ELSE", "CASE", "WHILE", "DEFAULT", "STATIC", "CONTINUE", "INT",
  "RLIMITS", "FLOAT", "FOR", "INHERIT", "VOID", "IF", "CATCH", "SWITCH",
  "VARARGS", "MAPPING", "PRIVATE", "DO", "RETURN", "ATOMIC", "MIXED",
  "OBJECT", "LARROW", "RARROW", "PLUS_PLUS", "MIN_MIN", "LSHIFT", "RSHIFT",
  "LE", "GE", "EQ", "NE", "LAND", "LOR", "PLUS_EQ", "MIN_EQ", "MULT_EQ",
  "DIV_EQ", "MOD_EQ", "LSHIFT_EQ", "RSHIFT_EQ", "AND_EQ", "XOR_EQ",
  "OR_EQ", "COLON_COLON", "DOT_DOT", "ELLIPSIS", "STRING_CONST",
  "IDENTIFIER", "INT_CONST", "FLOAT_CONST", "MARK", "HASH", "HASH_HASH",
  "INCL_CONST", "NR_TOKENS", "';'", "'+'", "'('", "')'", "','", "'*'",
  "':'", "'{'", "'}'", "'['", "']'", "'-'", "'!'", "'~'", "'/'", "'%'",
  "'<'", "'>'", "'&'", "'^'", "'|'", "'?'", "'='", "$accept", "program",
  "@1", "top_level_declarations", "top_level_declaration",
  "opt_inherit_label", "ident", "composite_string", "string",
  "data_declaration", "function_declaration", "@2", "@3",
  "local_data_declaration", "formals_declaration",
  "formal_declaration_list", "varargs_formal_declaration",
  "formal_declaration", "class_specifier_list", "class_specifier_list2",
  "class_specifier", "opt_private", "non_private", "type_specifier",
  "star_list", "data_dcltr", "function_dcltr", "dcltr", "list_dcltr",
  "dcltr_or_stmt_list", "dcltr_or_stmt", "if_stmt", "@4", "stmt", "@5",
  "@6", "@7", "@8", "@9", "@10", "@11", "@12", "@13", "@14", "@15",
  "compound_stmt", "@16", "opt_caught_stmt", "function_name",
  "primary_p1_exp", "@17", "primary_p2_exp", "postfix_exp", "prefix_exp",
  "cast_exp", "mult_oper_exp", "add_oper_exp", "shift_oper_exp",
  "rel_oper_exp", "equ_oper_exp", "bitand_oper_exp", "bitxor_oper_exp",
  "bitor_oper_exp", "and_oper_exp", "or_oper_exp", "cond_exp", "@18",
  "@19", "exp", "list_exp", "opt_list_exp", "f_list_exp", "f_opt_list_exp",
  "arg_list", "opt_arg_list", "opt_arg_list_comma", "assoc_exp",
  "assoc_arg_list", "opt_assoc_arg_list_comma", 0
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
     315,   316,   317,   318,    59,    43,    40,    41,    44,    42,
      58,   123,   125,    91,    93,    45,    33,   126,    47,    37,
      60,    62,    38,    94,   124,    63,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    89,    88,    90,    90,    91,    91,    91,    92,
      92,    93,    94,    94,    94,    95,    96,    98,    97,    99,
      97,   100,   101,   101,   101,   101,   102,   102,   103,   103,
     104,   104,   105,   105,   105,   106,   106,   107,   107,   108,
     108,   109,   109,   109,   109,   110,   110,   110,   110,   110,
     110,   110,   110,   111,   111,   112,   113,   114,   114,   115,
     115,   116,   116,   117,   117,   117,   119,   118,   120,   120,
     120,   121,   120,   122,   120,   123,   120,   124,   120,   125,
     120,   126,   127,   120,   128,   120,   129,   120,   130,   120,
     131,   120,   120,   120,   120,   120,   133,   132,   134,   134,
     135,   135,   135,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   137,   136,   136,   136,   136,   138,   138,   138,
     139,   139,   139,   140,   140,   140,   140,   140,   140,   140,
     141,   141,   142,   142,   142,   142,   143,   143,   143,   144,
     144,   144,   145,   145,   145,   145,   145,   146,   146,   146,
     147,   147,   148,   148,   149,   149,   150,   150,   151,   151,
     152,   153,   154,   152,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   156,   156,   157,   157,
     158,   159,   160,   160,   161,   161,   161,   162,   162,   162,
     163,   164,   164,   165,   165,   165
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     5,     1,     1,     0,
       1,     1,     1,     3,     3,     1,     4,     0,     5,     0,
       7,     4,     0,     1,     1,     2,     1,     3,     2,     1,
       2,     1,     1,     1,     2,     1,     2,     1,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     0,     2,     2,     5,     1,     1,     1,
       3,     0,     2,     1,     1,     2,     0,     6,     2,     1,
       1,     0,     4,     0,     8,     0,     6,     0,    10,     0,
       8,     0,     0,     5,     0,     6,     0,     5,     0,     7,
       0,     4,     2,     2,     3,     1,     0,     4,     0,     2,
       1,     2,     3,     1,     1,     1,     1,     5,     5,     1,
       3,     4,     0,     5,     6,     3,     5,     1,     4,     6,
       1,     2,     2,     1,     2,     2,     2,     2,     2,     2,
       1,     5,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     0,     0,     7,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     0,     1,
       1,     1,     1,     3,     0,     1,     2,     0,     1,     2,
       3,     1,     3,     0,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     4,     1,    39,    43,    41,    44,    40,    42,
       5,     7,     8,     0,     0,    32,    33,    47,    45,    46,
      52,    50,    51,    48,    11,     0,    53,    37,    34,    35,
      38,     9,    15,     0,    49,    12,    22,     0,    57,    58,
      59,     0,    36,     0,    10,     0,     0,    52,     0,    31,
       0,    24,    26,    29,    53,    54,    55,     0,    16,    53,
       0,    14,    13,    28,    19,    25,     0,     0,    30,    22,
      96,    18,    58,    60,     6,     0,    27,    55,     0,    61,
      20,    56,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,    81,     0,    73,   178,     0,     0,     0,
     103,   104,    95,     0,     0,    97,     0,     0,     0,   109,
     106,    63,     0,    32,    62,    70,    64,    69,     0,   117,
     120,   123,   130,   132,   136,   139,   142,   147,   150,   152,
     154,   156,   158,   160,   164,   176,     0,    65,    92,     0,
       0,     0,    90,    93,     0,   178,     0,   112,     0,     0,
       0,   179,   181,     0,   124,   125,   101,   127,   187,   193,
      53,     0,   126,   128,   129,     0,    53,    71,   184,     0,
       0,   178,   121,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68,     0,     0,    86,   180,     0,
       0,     0,     0,     0,     0,    82,     0,     0,    94,   182,
     188,     0,     0,   191,   194,     0,     0,   110,   102,     0,
       0,   185,     0,     0,   115,     0,   179,     0,     0,   133,
     134,   135,   137,   138,   140,   141,   145,   146,   143,   144,
     148,   149,   151,   153,   155,   157,   159,     0,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   165,   177,
       0,     0,    75,    91,     0,   178,    66,     0,    98,    84,
       0,   189,     0,     0,   195,     0,     0,    21,    72,   186,
       0,   111,     0,   184,   118,   178,     0,    88,    87,     0,
       0,     0,     0,   113,     0,    83,     0,     0,   183,   107,
     190,   192,   108,   131,   116,     0,     0,   162,     0,    76,
      79,   178,    67,    99,    85,     0,   114,   119,     0,    89,
       0,     0,     0,   163,    80,    77,    74,     0,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,    10,    43,   109,    34,   110,    11,
      12,    57,    75,   111,    50,    51,    52,    53,    13,    28,
      14,    15,    16,    54,    37,    38,    72,    40,    41,    82,
     114,   115,   302,   116,   230,   150,   299,   337,   330,   148,
     278,   306,   271,   318,   210,   117,    79,   305,   118,   119,
     214,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   257,   328,   135,   136,
     152,   209,   153,   231,   232,   221,   223,   224,   225
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -151
static const yytype_int16 yypact[] =
{
    -151,    73,  -151,  -151,    37,  -151,  -151,  -151,    63,  -151,
    -151,  -151,  -151,   169,    94,    84,   143,  -151,  -151,  -151,
    -151,  -151,  -151,    23,  -151,    98,  -151,  -151,    94,  -151,
    -151,    52,  -151,    23,    95,  -151,    16,    -9,  -151,    97,
    -151,    45,  -151,    23,  -151,    50,   123,   119,   169,  -151,
     124,   -44,  -151,  -151,  -151,  -151,   127,   128,  -151,  -151,
      86,  -151,  -151,  -151,  -151,  -151,    40,    -9,  -151,    16,
    -151,  -151,  -151,  -151,  -151,   128,  -151,  -151,   134,  -151,
    -151,  -151,   256,   131,  -151,   139,   176,   141,   146,   150,
     157,   172,   173,   177,   178,  -151,   176,   176,   176,    52,
    -151,  -151,  -151,   176,   321,  -151,   176,   176,   176,   -24,
    -151,  -151,   342,  -151,  -151,   228,  -151,  -151,   180,  -151,
       2,   144,  -151,  -151,    74,    29,   155,    -1,   167,   165,
     171,   164,   210,   -19,   249,  -151,    56,  -151,  -151,   177,
     -13,   176,  -151,  -151,   176,   176,   176,  -151,   128,   176,
     394,   187,  -151,   192,  -151,  -151,  -151,  -151,   176,   176,
    -151,   152,  -151,  -151,  -151,    52,  -151,  -151,   176,    48,
      52,   176,  -151,  -151,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,  -151,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,  -151,   176,   176,  -151,   187,   191,
     394,   199,   222,   220,   176,  -151,   223,   292,  -151,  -151,
     234,   231,   235,  -151,   236,   232,    79,  -151,  -151,    58,
     394,    27,   240,    23,  -151,   243,    -3,   241,   257,  -151,
    -151,  -151,    74,    74,    29,    29,   155,   155,   155,   155,
      -1,    -1,   167,   165,   171,   164,   210,   176,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
     246,   394,  -151,  -151,   176,   176,  -151,   154,   247,  -151,
     252,   176,   258,   176,   176,   262,   176,  -151,  -151,  -151,
     176,  -151,    96,   176,  -151,   176,   105,  -151,  -151,   394,
     263,   255,   394,  -151,   394,  -151,   128,   176,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,   270,   264,  -151,   394,  -151,
    -151,   176,  -151,  -151,  -151,   273,  -151,  -151,   176,  -151,
     128,   275,   259,  -151,  -151,  -151,  -151,   394,  -151
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,  -151,  -151,  -151,  -151,  -151,    75,   -31,   -20,  -151,
    -151,  -151,  -151,  -151,   274,  -151,   280,   299,   266,  -151,
      42,   269,    72,    -5,   -50,   298,   330,   300,   195,  -151,
    -151,  -151,  -151,  -133,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,   -57,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,   -92,    33,    57,   -25,    44,   175,
     170,   174,   179,   181,  -151,    36,  -151,  -151,   -66,   -95,
    -138,  -119,  -150,   208,    81,  -151,    83,  -151,  -151
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -181
static const yytype_int16 yytable[] =
{
      71,   151,    45,    35,    67,   154,   155,   212,    26,   161,
      65,   157,    60,    35,   162,   163,   164,   217,    80,    17,
     140,   238,   191,    35,    66,   211,    62,   213,   165,    18,
     216,    19,   169,   170,    47,   181,   182,    -3,    48,    21,
     206,     5,  -100,    17,    22,    23,   208,    24,     6,   208,
     151,   208,   237,    18,   208,    19,    29,   207,    20,     7,
      55,     8,    48,    21,     9,   205,   192,   -37,    22,    23,
      42,  -180,    24,     3,   -37,   171,   236,   273,    32,   183,
     184,   289,   239,   240,   241,   -37,    30,   -37,    25,    33,
     -37,   215,   219,   222,   177,   290,    24,   288,     5,   160,
      30,    31,   219,    32,   178,     6,    44,   166,    24,    58,
     226,    49,    56,    59,   233,    46,     7,    61,    27,   277,
     204,     9,   287,    49,   205,   301,    59,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   298,   269,
     270,    49,    77,   174,    49,   316,   286,   -38,    55,   234,
      74,    46,   175,   176,   -38,   300,   246,   247,   248,   249,
      46,    46,   296,   314,    36,   -38,   319,   -38,   -17,   322,
     -38,   323,    17,   205,   156,   317,   172,   173,    32,   208,
     151,    84,    18,   331,    19,   329,   -23,    20,   325,   179,
     180,    64,    21,    69,   313,   137,   139,    22,    23,    70,
     151,    81,   292,   138,   338,   185,   186,   141,    97,    98,
     242,   243,   208,    35,   143,   308,   142,   310,   222,   227,
     205,   303,   205,   144,   308,    24,   151,   219,    99,   250,
     251,    32,    24,   100,   101,   167,   244,   245,   145,   146,
     228,   103,   104,   147,   149,   235,   168,   187,   189,   324,
     190,   106,   107,   108,   188,   205,   218,    83,   272,   -39,
       5,    84,    85,   274,    86,    87,    88,     6,    89,   -39,
      90,   -39,    91,   334,   -39,    92,    93,    94,     7,   -39,
       8,    95,    96,     9,   -39,   -39,   275,   276,    97,    98,
     279,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   280,   281,   282,   284,   283,   285,   291,    99,   293,
     295,    32,    24,   100,   101,   294,   297,   304,   307,   321,
     102,   103,   104,   336,    17,   309,    84,    70,   105,   312,
     320,   106,   107,   108,    18,   203,    19,   326,   327,    20,
     332,   139,   335,    78,    21,    17,    76,    63,   112,    22,
      23,   113,    68,    97,    98,    18,    39,    19,   253,    73,
      20,   229,   252,   254,   333,    21,   220,   311,     0,   255,
      22,    23,   256,    99,   315,     0,    32,    24,   100,   101,
       0,     0,     0,     0,     0,     0,   103,   104,     0,     0,
       0,     0,   158,     0,   159,     0,   106,   107,   108,    84,
      85,     0,    86,    87,    88,     0,    89,     0,    90,     0,
      91,     0,     0,    92,    93,    94,     0,     0,     0,    95,
      96,     0,     0,     0,     0,     0,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,     0,     0,    32,
      24,   100,   101,     0,     0,     0,     0,     0,   102,   103,
     104,     0,     0,     0,     0,    70,     0,     0,     0,   106,
     107,   108
};

static const yytype_int16 yycheck[] =
{
      57,    96,    33,    23,    54,    97,    98,   145,    13,   104,
      54,   103,    43,    33,   106,   107,   108,   150,    75,     3,
      86,   171,    41,    43,    68,   144,    46,   146,    52,    13,
     149,    15,    30,    31,    18,    36,    37,     0,    22,    23,
      53,     4,    66,     3,    28,    29,   141,    56,    11,   144,
     145,   146,   171,    13,   149,    15,    14,    70,    18,    22,
      69,    24,    22,    23,    27,    68,    85,     4,    28,    29,
      28,    74,    56,     0,    11,    73,   171,   210,    55,    80,
      81,    54,   174,   175,   176,    22,    14,    24,    13,    66,
      27,   148,   158,   159,    65,    68,    56,   230,     4,   104,
      28,    17,   168,    55,    75,    11,    31,   112,    56,    64,
     160,    36,    37,    68,    66,    65,    22,    67,    24,   214,
      64,    27,    64,    48,    68,   275,    68,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   271,   205,
     206,    66,    67,    69,    69,   295,    67,     4,    69,   169,
      64,    65,    78,    79,    11,   274,   181,   182,   183,   184,
      65,    65,   257,    67,    66,    22,   299,    24,    71,   302,
      27,   304,     3,    68,    99,    70,    32,    33,    55,   274,
     275,     5,    13,   321,    15,   318,    67,    18,   307,    34,
      35,    67,    23,    66,   286,    64,    20,    28,    29,    71,
     295,    67,   233,    64,   337,    38,    39,    66,    32,    33,
     177,   178,   307,   233,    64,   281,    70,   283,   284,    67,
      68,    67,    68,    66,   290,    56,   321,   293,    52,   185,
     186,    55,    56,    57,    58,     7,   179,   180,    66,    66,
     165,    65,    66,    66,    66,   170,    66,    82,    84,   306,
      40,    75,    76,    77,    83,    68,    64,     1,    67,     3,
       4,     5,     6,    64,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   330,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    64,    67,    32,    33,
      67,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     9,    68,    72,    68,    70,    74,    67,    52,    66,
      53,    55,    56,    57,    58,    74,    70,    70,    66,    64,
      64,    65,    66,    64,     3,    67,     5,    71,    72,    67,
      67,    75,    76,    77,    13,    86,    15,    67,    74,    18,
      67,    20,    67,    69,    23,     3,    66,    48,    82,    28,
      29,    82,    54,    32,    33,    13,    26,    15,   188,    59,
      18,   166,   187,   189,   328,    23,   158,   284,    -1,   190,
      28,    29,   191,    52,   293,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    -1,
      -1,    -1,    71,    -1,    73,    -1,    75,    76,    77,     5,
       6,    -1,     8,     9,    10,    -1,    12,    -1,    14,    -1,
      16,    -1,    -1,    19,    20,    21,    -1,    -1,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    75,
      76,    77
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    88,    89,     0,    90,     4,    11,    22,    24,    27,
      91,    96,    97,   105,   107,   108,   109,     3,    13,    15,
      18,    23,    28,    29,    56,    93,   110,    24,   106,   107,
     109,    17,    55,    66,    94,    95,    66,   111,   112,   113,
     114,   115,   107,    92,    93,    94,    65,    18,    22,    93,
     101,   102,   103,   104,   110,    69,    93,    98,    64,    68,
      94,    67,    95,   104,    67,    54,    68,   111,   112,    66,
      71,   132,   113,   114,    64,    99,   103,    93,   101,   133,
     132,    67,   116,     1,     5,     6,     8,     9,    10,    12,
      14,    16,    19,    20,    21,    25,    26,    32,    33,    52,
      57,    58,    64,    65,    66,    72,    75,    76,    77,    93,
      95,   100,   105,   108,   117,   118,   120,   132,   135,   136,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   155,   156,    64,    64,    20,
     155,    66,    70,    64,    66,    66,    66,    66,   126,    66,
     122,   156,   157,   159,   141,   141,    93,   141,    71,    73,
     110,   156,   141,   141,   141,    52,   110,     7,    66,    30,
      31,    73,    32,    33,    69,    78,    79,    65,    75,    34,
      35,    36,    37,    80,    81,    38,    39,    82,    83,    84,
      40,    41,    85,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    86,    64,    68,    53,    70,   156,   158,
     131,   158,   157,   158,   137,   132,   158,   120,    64,   155,
     160,   162,   155,   163,   164,   165,   111,    67,    93,   115,
     121,   160,   161,    66,    95,    93,   156,   158,   159,   141,
     141,   141,   142,   142,   143,   143,   144,   144,   144,   144,
     145,   145,   146,   147,   148,   149,   150,   153,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   129,    67,   120,    64,    64,    67,   156,   127,    67,
       9,    68,    72,    70,    68,    74,    67,    64,   120,    54,
      68,    67,    94,    66,    74,    53,   156,    70,   120,   123,
     158,   159,   119,    67,    70,   134,   128,    66,   155,    67,
     155,   163,    67,   141,    67,   161,   159,    70,   130,   120,
      67,    64,   120,   120,   132,   158,    67,    74,   154,   120,
     125,   157,    67,   152,   132,    67,    64,   124,   120
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
        case 2:
#line 130 "parser.y"
    {
		  nerrors = 0;
		  ndeclarations = 0;
		}
    break;

  case 3:
#line 135 "parser.y"
    {
		  if (nerrors > 0) {
		      YYABORT;
		  }
		}
    break;

  case 5:
#line 145 "parser.y"
    {
		  if (nerrors > 0) {
		      YYABORT;
		  }
		}
    break;

  case 6:
#line 154 "parser.y"
    {
		  if (ndeclarations > 0) {
		      c_error("inherit must precede all declarations");
		  } else if (nerrors > 0 ||
			     !c_inherit((yyvsp[(4) - (5)].node)->l.string->text, (yyvsp[(3) - (5)].node), (yyvsp[(1) - (5)].type) != 0)) {
		      /*
		       * The object to be inherited may have been compiled;
		       * abort this compilation and possibly restart later.
		       */
		      YYABORT;
		  }
		}
    break;

  case 7:
#line 167 "parser.y"
    { ndeclarations++; }
    break;

  case 8:
#line 169 "parser.y"
    { ndeclarations++; }
    break;

  case 9:
#line 174 "parser.y"
    { (yyval.node) = (node *) NULL; }
    break;

  case 11:
#line 180 "parser.y"
    { (yyval.node) = node_str(str_new(yytext, (long) yyleng)); }
    break;

  case 13:
#line 186 "parser.y"
    { (yyval.node) = node_str(str_add((yyvsp[(1) - (3)].node)->l.string, (yyvsp[(3) - (3)].node)->l.string)); }
    break;

  case 14:
#line 188 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 15:
#line 193 "parser.y"
    { (yyval.node) = node_str(str_new(yytext, (long) yyleng)); }
    break;

  case 16:
#line 198 "parser.y"
    { c_global((yyvsp[(1) - (4)].type), (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node)); }
    break;

  case 17:
#line 203 "parser.y"
    { 
		  typechecking = TRUE;
		  c_function((yyvsp[(1) - (3)].type), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
		}
    break;

  case 18:
#line 208 "parser.y"
    {
		  if (nerrors == 0) {
		      c_funcbody((yyvsp[(5) - (5)].node));
		  }
		}
    break;

  case 19:
#line 214 "parser.y"
    {
		  typechecking = c_typechecking();
		  c_function((yyvsp[(1) - (5)].type), node_type((typechecking) ? T_VOID : T_NIL,
					   (string *) NULL),
			     node_bin(N_FUNC, 0, (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node)));
		}
    break;

  case 20:
#line 221 "parser.y"
    {
		  if (nerrors == 0) {
		      c_funcbody((yyvsp[(7) - (7)].node));
		  }
		}
    break;

  case 21:
#line 230 "parser.y"
    { c_local((yyvsp[(1) - (4)].type), (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node)); }
    break;

  case 22:
#line 235 "parser.y"
    { (yyval.node) = (node *) NULL; }
    break;

  case 23:
#line 236 "parser.y"
    { (yyval.node) = (node *) NULL; }
    break;

  case 25:
#line 239 "parser.y"
    {
		  (yyval.node) = (yyvsp[(1) - (2)].node);
		  (yyval.node)->flags |= F_ELLIPSIS;
		}
    break;

  case 27:
#line 248 "parser.y"
    { (yyval.node) = node_bin(N_PAIR, 0, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 28:
#line 253 "parser.y"
    {
		  (yyval.node) = (yyvsp[(2) - (2)].node);
		  (yyval.node)->flags |= F_VARARGS;
		}
    break;

  case 30:
#line 262 "parser.y"
    {
		  (yyval.node) = (yyvsp[(2) - (2)].node);
		  (yyval.node)->mod |= (yyvsp[(1) - (2)].node)->mod;
		  (yyval.node)->class = (yyvsp[(1) - (2)].node)->class;
		}
    break;

  case 31:
#line 267 "parser.y"
    {
		  (yyval.node) = (yyvsp[(1) - (1)].node);
		  (yyval.node)->mod = T_NIL;	/* only if typechecking, though */
		}
    break;

  case 34:
#line 277 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (2)].type) | (yyvsp[(2) - (2)].type); }
    break;

  case 36:
#line 283 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (2)].type) | (yyvsp[(2) - (2)].type); }
    break;

  case 37:
#line 288 "parser.y"
    { (yyval.type) = C_STATIC | C_PRIVATE; }
    break;

  case 39:
#line 294 "parser.y"
    { (yyval.type) = 0; }
    break;

  case 40:
#line 296 "parser.y"
    { (yyval.type) = C_STATIC | C_PRIVATE; }
    break;

  case 41:
#line 301 "parser.y"
    { (yyval.type) = C_STATIC; }
    break;

  case 42:
#line 303 "parser.y"
    { (yyval.type) = C_ATOMIC; }
    break;

  case 43:
#line 305 "parser.y"
    { (yyval.type) = C_NOMASK; }
    break;

  case 44:
#line 307 "parser.y"
    { (yyval.type) = C_VARARGS; }
    break;

  case 45:
#line 311 "parser.y"
    { (yyval.node) = node_type(T_INT, (string *) NULL); }
    break;

  case 46:
#line 312 "parser.y"
    { (yyval.node) = node_type(T_FLOAT, (string *) NULL); }
    break;

  case 47:
#line 314 "parser.y"
    { (yyval.node) = node_type(T_STRING, (string *) NULL); }
    break;

  case 48:
#line 316 "parser.y"
    { (yyval.node) = node_type(T_OBJECT, (string *) NULL); }
    break;

  case 49:
#line 318 "parser.y"
    { (yyval.node) = node_type(T_CLASS, c_objecttype((yyvsp[(2) - (2)].node))); }
    break;

  case 50:
#line 320 "parser.y"
    { (yyval.node) = node_type(T_MAPPING, (string *) NULL); }
    break;

  case 51:
#line 321 "parser.y"
    { (yyval.node) = node_type(T_MIXED, (string *) NULL); }
    break;

  case 52:
#line 322 "parser.y"
    { (yyval.node) = node_type(T_VOID, (string *) NULL); }
    break;

  case 53:
#line 327 "parser.y"
    { (yyval.type) = 0; }
    break;

  case 54:
#line 329 "parser.y"
    {
		  (yyval.type) = (yyvsp[(1) - (2)].type) + 1;
		  if ((yyval.type) == 1 << (8 - REFSHIFT)) {
		      c_error("too deep indirection");
		  }
		}
    break;

  case 55:
#line 339 "parser.y"
    {
		  (yyval.node) = (yyvsp[(2) - (2)].node);
		  (yyval.node)->mod = ((yyvsp[(1) - (2)].type) << REFSHIFT) & T_REF;
		}
    break;

  case 56:
#line 347 "parser.y"
    { (yyval.node) = node_bin(N_FUNC, ((yyvsp[(1) - (5)].type) << REFSHIFT) & T_REF, (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node)); }
    break;

  case 60:
#line 358 "parser.y"
    { (yyval.node) = node_bin(N_PAIR, 0, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 61:
#line 363 "parser.y"
    { (yyval.node) = (node *) NULL; }
    break;

  case 62:
#line 365 "parser.y"
    { (yyval.node) = c_concat((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 63:
#line 370 "parser.y"
    {
		  if (nstatements > 0) {
		      c_error("declaration after statement");
		  }
		  (yyval.node) = (node *) NULL;
		}
    break;

  case 64:
#line 376 "parser.y"
    {
		  nstatements++;
		  (yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 65:
#line 381 "parser.y"
    {
		  if (nerrors >= MAX_ERRORS) {
		      YYABORT;
		  }
		  (yyval.node) = (node *) NULL;
		}
    break;

  case 66:
#line 391 "parser.y"
    { c_startcond(); }
    break;

  case 67:
#line 392 "parser.y"
    { (yyval.node) = c_if((yyvsp[(3) - (6)].node), (yyvsp[(6) - (6)].node)); }
    break;

  case 68:
#line 397 "parser.y"
    { (yyval.node) = c_exp_stmt((yyvsp[(1) - (2)].node)); }
    break;

  case 70:
#line 400 "parser.y"
    {
		  c_endcond();
		  (yyval.node) = c_endif((yyvsp[(1) - (1)].node), (node *) NULL);
		}
    break;

  case 71:
#line 406 "parser.y"
    { c_startcond2(); }
    break;

  case 72:
#line 408 "parser.y"
    {
		  c_matchcond();
		  (yyval.node) = c_endif((yyvsp[(1) - (4)].node), (yyvsp[(4) - (4)].node));
		}
    break;

  case 73:
#line 412 "parser.y"
    { c_loop(); }
    break;

  case 74:
#line 414 "parser.y"
    { (yyval.node) = c_do((yyvsp[(6) - (8)].node), (yyvsp[(3) - (8)].node)); }
    break;

  case 75:
#line 416 "parser.y"
    {
		  c_loop();
		  c_startcond();
		}
    break;

  case 76:
#line 420 "parser.y"
    {
		  c_endcond();
		  (yyval.node) = c_while((yyvsp[(3) - (6)].node), (yyvsp[(6) - (6)].node));
		}
    break;

  case 77:
#line 425 "parser.y"
    {
		  c_loop();
		  c_startcond();
		}
    break;

  case 78:
#line 429 "parser.y"
    {
		  c_endcond();
		  (yyval.node) = c_for(c_exp_stmt((yyvsp[(3) - (10)].node)), (yyvsp[(5) - (10)].node), c_exp_stmt((yyvsp[(7) - (10)].node)), (yyvsp[(10) - (10)].node));
		}
    break;

  case 79:
#line 434 "parser.y"
    {
		  if (typechecking) {
		      char tnbuf[17];

		      if ((yyvsp[(3) - (6)].node)->mod != T_INT && (yyvsp[(3) - (6)].node)->mod != T_MIXED) {
			  c_error("bad type for stack rlimit (%s)",
				  i_typename(tnbuf, (yyvsp[(3) - (6)].node)->mod));
		      }
		      if ((yyvsp[(5) - (6)].node)->mod != T_INT && (yyvsp[(5) - (6)].node)->mod != T_MIXED) {
			  c_error("bad type for ticks rlimit (%s)",
				  i_typename(tnbuf, (yyvsp[(5) - (6)].node)->mod));
		      }
		  }
		  c_startrlimits();
		}
    break;

  case 80:
#line 450 "parser.y"
    { (yyval.node) = c_endrlimits((yyvsp[(3) - (8)].node), (yyvsp[(5) - (8)].node), (yyvsp[(8) - (8)].node)); }
    break;

  case 81:
#line 451 "parser.y"
    {
		  c_startcatch();
		  c_startcond();
		}
    break;

  case 82:
#line 456 "parser.y"
    {
		  c_endcond();
		  c_endcatch();
		  c_startcond();
		}
    break;

  case 83:
#line 462 "parser.y"
    {
		  c_endcond();
		  (yyval.node) = c_donecatch((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
		}
    break;

  case 84:
#line 467 "parser.y"
    {
		  c_startswitch((yyvsp[(3) - (4)].node), typechecking);
		  c_startcond();
		}
    break;

  case 85:
#line 472 "parser.y"
    {
		  c_endcond();
		  (yyval.node) = c_endswitch((yyvsp[(3) - (6)].node), (yyvsp[(6) - (6)].node));
		}
    break;

  case 86:
#line 477 "parser.y"
    { (yyvsp[(2) - (3)].node) = c_case((yyvsp[(2) - (3)].node), (node *) NULL); }
    break;

  case 87:
#line 478 "parser.y"
    {
		  (yyval.node) = (yyvsp[(2) - (5)].node);
		  if ((yyval.node) != (node *) NULL) {
		      (yyval.node)->l.left = (yyvsp[(5) - (5)].node);
		  } else {
		      (yyval.node) = (yyvsp[(5) - (5)].node);
		  }
		}
    break;

  case 88:
#line 487 "parser.y"
    { (yyvsp[(2) - (5)].node) = c_case((yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node)); }
    break;

  case 89:
#line 488 "parser.y"
    {
		  (yyval.node) = (yyvsp[(2) - (7)].node);
		  if ((yyval.node) != (node *) NULL) {
		      (yyval.node)->l.left = (yyvsp[(7) - (7)].node);
		  } else {
		      (yyval.node) = (yyvsp[(7) - (7)].node);
		  }
		}
    break;

  case 90:
#line 497 "parser.y"
    { (yyvsp[(2) - (2)].node) = c_default(); }
    break;

  case 91:
#line 498 "parser.y"
    {
		  (yyval.node) = (yyvsp[(2) - (4)].node);
		  if ((yyval.node) != (node *) NULL) {
		      (yyval.node)->l.left = (yyvsp[(4) - (4)].node);
		  } else {
		      (yyval.node) = (yyvsp[(4) - (4)].node);
		  }
		}
    break;

  case 92:
#line 507 "parser.y"
    {
		  (yyval.node) = c_break();
		}
    break;

  case 93:
#line 511 "parser.y"
    {
		  (yyval.node) = c_continue();
		}
    break;

  case 94:
#line 515 "parser.y"
    { (yyval.node) = c_return((yyvsp[(2) - (3)].node), typechecking); }
    break;

  case 95:
#line 516 "parser.y"
    { (yyval.node) = (node *) NULL; }
    break;

  case 96:
#line 520 "parser.y"
    {
		  nstatements = 0;
		  c_startcompound();
		}
    break;

  case 97:
#line 525 "parser.y"
    {
		  nstatements++;
		  (yyval.node) = c_endcompound((yyvsp[(3) - (4)].node));
		}
    break;

  case 98:
#line 533 "parser.y"
    { (yyval.node) = (node *) NULL; }
    break;

  case 99:
#line 535 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 100:
#line 539 "parser.y"
    { (yyval.node) = c_flookup((yyvsp[(1) - (1)].node), typechecking); }
    break;

  case 101:
#line 541 "parser.y"
    { (yyval.node) = c_iflookup((yyvsp[(2) - (2)].node), (node *) NULL); }
    break;

  case 102:
#line 543 "parser.y"
    { (yyval.node) = c_iflookup((yyvsp[(3) - (3)].node), (yyvsp[(1) - (3)].node)); }
    break;

  case 103:
#line 548 "parser.y"
    { (yyval.node) = node_int((yyvsp[(1) - (1)].number)); }
    break;

  case 104:
#line 550 "parser.y"
    { (yyval.node) = node_float(&(yyvsp[(1) - (1)].real)); }
    break;

  case 105:
#line 551 "parser.y"
    { (yyval.node) = node_nil(); }
    break;

  case 107:
#line 554 "parser.y"
    { (yyval.node) = c_aggregate((yyvsp[(3) - (5)].node), T_MIXED | (1 << REFSHIFT)); }
    break;

  case 108:
#line 556 "parser.y"
    { (yyval.node) = c_aggregate((yyvsp[(3) - (5)].node), T_MAPPING); }
    break;

  case 109:
#line 557 "parser.y"
    {
		  (yyval.node) = c_variable((yyvsp[(1) - (1)].node));
		  if (typechecking) {
		      if ((yyval.node)->type == N_GLOBAL && (yyval.node)->mod != T_MIXED &&
			  !conf_typechecking()) {
			  /*
			   * global vars might be modified by untypechecked
			   * functions...
			   */
			  (yyval.node) = node_mon(N_CAST, (yyval.node)->mod, (yyval.node));
			  (yyval.node)->class = (yyval.node)->l.left->class;
		      }
		  } else {
		      /* the variable could be anything */
		      (yyval.node)->mod = T_MIXED;
		  }
		}
    break;

  case 110:
#line 575 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 111:
#line 577 "parser.y"
    { (yyval.node) = c_checkcall(c_funcall((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node)), typechecking); }
    break;

  case 112:
#line 579 "parser.y"
    { c_startcond(); }
    break;

  case 113:
#line 581 "parser.y"
    {
		  c_endcond();
		  (yyval.node) = node_mon(N_CATCH, T_STRING, (yyvsp[(4) - (5)].node));
		}
    break;

  case 114:
#line 586 "parser.y"
    {
		  t_void((yyvsp[(1) - (6)].node));
		  (yyval.node) = c_checkcall(c_arrow((yyvsp[(1) - (6)].node), (yyvsp[(3) - (6)].node), (yyvsp[(5) - (6)].node)), typechecking);
		}
    break;

  case 115:
#line 591 "parser.y"
    { (yyval.node) = c_instanceof((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 116:
#line 593 "parser.y"
    { (yyval.node) = c_instanceof((yyvsp[(1) - (5)].node), (yyvsp[(4) - (5)].node)); }
    break;

  case 118:
#line 599 "parser.y"
    { (yyval.node) = idx((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node)); }
    break;

  case 119:
#line 601 "parser.y"
    { (yyval.node) = range((yyvsp[(1) - (6)].node), (yyvsp[(3) - (6)].node), (yyvsp[(5) - (6)].node)); }
    break;

  case 121:
#line 607 "parser.y"
    { (yyval.node) = uassign(N_PLUS_PLUS, (yyvsp[(1) - (2)].node), "++"); }
    break;

  case 122:
#line 609 "parser.y"
    { (yyval.node) = uassign(N_MIN_MIN, (yyvsp[(1) - (2)].node), "--"); }
    break;

  case 124:
#line 615 "parser.y"
    { (yyval.node) = uassign(N_ADD_EQ_1, (yyvsp[(2) - (2)].node), "++"); }
    break;

  case 125:
#line 617 "parser.y"
    { (yyval.node) = uassign(N_SUB_EQ_1, (yyvsp[(2) - (2)].node), "--"); }
    break;

  case 126:
#line 619 "parser.y"
    { (yyval.node) = umin((yyvsp[(2) - (2)].node)); }
    break;

  case 127:
#line 621 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 128:
#line 623 "parser.y"
    {
		  t_void((yyvsp[(2) - (2)].node));
		  (yyval.node) = c_not((yyvsp[(2) - (2)].node));
		}
    break;

  case 129:
#line 628 "parser.y"
    {
		  (yyval.node) = (yyvsp[(2) - (2)].node);
		  t_void((yyval.node));
		  if (typechecking && (yyval.node)->mod != T_INT && (yyval.node)->mod != T_MIXED) {
		      char tnbuf[17];

		      c_error("bad argument type for ~ (%s)",
			      i_typename(tnbuf, (yyval.node)->mod));
		      (yyval.node)->mod = T_MIXED;
		  } else {
		      (yyval.node) = xor(N_XOR, (yyval.node), node_int((Int) -1), "^");
		  }
		}
    break;

  case 131:
#line 646 "parser.y"
    {
		  (yyvsp[(2) - (5)].node)->mod |= ((yyvsp[(3) - (5)].type) << REFSHIFT) & T_REF;
		  (yyval.node) = cast((yyvsp[(5) - (5)].node), (yyvsp[(2) - (5)].node));
		}
    break;

  case 133:
#line 655 "parser.y"
    { (yyval.node) = mult(N_MULT, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "*"); }
    break;

  case 134:
#line 657 "parser.y"
    { (yyval.node) = mdiv(N_DIV, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "/"); }
    break;

  case 135:
#line 659 "parser.y"
    { (yyval.node) = mod(N_MOD, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "%"); }
    break;

  case 137:
#line 665 "parser.y"
    { (yyval.node) = add(N_ADD, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "+"); }
    break;

  case 138:
#line 667 "parser.y"
    { (yyval.node) = sub(N_SUB, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "-"); }
    break;

  case 140:
#line 673 "parser.y"
    { (yyval.node) = lshift(N_LSHIFT, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "<<"); }
    break;

  case 141:
#line 675 "parser.y"
    { (yyval.node) = rshift(N_RSHIFT, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), ">>"); }
    break;

  case 143:
#line 681 "parser.y"
    { (yyval.node) = rel(N_LT, (yyval.node), (yyvsp[(3) - (3)].node), "<"); }
    break;

  case 144:
#line 683 "parser.y"
    { (yyval.node) = rel(N_GT, (yyval.node), (yyvsp[(3) - (3)].node), ">"); }
    break;

  case 145:
#line 685 "parser.y"
    { (yyval.node) = rel(N_LE, (yyval.node), (yyvsp[(3) - (3)].node), "<="); }
    break;

  case 146:
#line 687 "parser.y"
    { (yyval.node) = rel(N_GE, (yyval.node), (yyvsp[(3) - (3)].node), ">="); }
    break;

  case 148:
#line 693 "parser.y"
    { (yyval.node) = eq((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 149:
#line 695 "parser.y"
    { (yyval.node) = c_not(eq((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node))); }
    break;

  case 151:
#line 701 "parser.y"
    { (yyval.node) = and(N_AND, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "&"); }
    break;

  case 153:
#line 707 "parser.y"
    { (yyval.node) = xor(N_XOR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "^"); }
    break;

  case 155:
#line 713 "parser.y"
    { (yyval.node) = or(N_OR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "|"); }
    break;

  case 157:
#line 719 "parser.y"
    { (yyval.node) = land((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 159:
#line 725 "parser.y"
    { (yyval.node) = lor((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 161:
#line 731 "parser.y"
    { c_startcond(); }
    break;

  case 162:
#line 733 "parser.y"
    { c_startcond2(); }
    break;

  case 163:
#line 735 "parser.y"
    {
		  c_matchcond();
		  (yyval.node) = quest((yyvsp[(1) - (7)].node), (yyvsp[(4) - (7)].node), (yyvsp[(7) - (7)].node));
		}
    break;

  case 165:
#line 744 "parser.y"
    { (yyval.node) = assign(c_assign((yyvsp[(1) - (3)].node)), (yyvsp[(3) - (3)].node)); }
    break;

  case 166:
#line 746 "parser.y"
    { (yyval.node) = add(N_ADD_EQ, c_lvalue((yyvsp[(1) - (3)].node), "+="), (yyvsp[(3) - (3)].node), "+="); }
    break;

  case 167:
#line 748 "parser.y"
    { (yyval.node) = sub(N_SUB_EQ, c_lvalue((yyvsp[(1) - (3)].node), "-="), (yyvsp[(3) - (3)].node), "-="); }
    break;

  case 168:
#line 750 "parser.y"
    { (yyval.node) = mult(N_MULT_EQ, c_lvalue((yyvsp[(1) - (3)].node), "*="), (yyvsp[(3) - (3)].node), "*="); }
    break;

  case 169:
#line 752 "parser.y"
    { (yyval.node) = mdiv(N_DIV_EQ, c_lvalue((yyvsp[(1) - (3)].node), "/="), (yyvsp[(3) - (3)].node), "/="); }
    break;

  case 170:
#line 754 "parser.y"
    { (yyval.node) = mod(N_MOD_EQ, c_lvalue((yyvsp[(1) - (3)].node), "%="), (yyvsp[(3) - (3)].node), "%="); }
    break;

  case 171:
#line 756 "parser.y"
    { (yyval.node) = lshift(N_LSHIFT_EQ, c_lvalue((yyvsp[(1) - (3)].node), "<<="), (yyvsp[(3) - (3)].node), "<<="); }
    break;

  case 172:
#line 758 "parser.y"
    { (yyval.node) = rshift(N_RSHIFT_EQ, c_lvalue((yyvsp[(1) - (3)].node), ">>="), (yyvsp[(3) - (3)].node), ">>="); }
    break;

  case 173:
#line 760 "parser.y"
    { (yyval.node) = and(N_AND_EQ, c_lvalue((yyvsp[(1) - (3)].node), "&="), (yyvsp[(3) - (3)].node), "&="); }
    break;

  case 174:
#line 762 "parser.y"
    { (yyval.node) = xor(N_XOR_EQ, c_lvalue((yyvsp[(1) - (3)].node), "^="), (yyvsp[(3) - (3)].node), "^="); }
    break;

  case 175:
#line 764 "parser.y"
    { (yyval.node) = or(N_OR_EQ, c_lvalue((yyvsp[(1) - (3)].node), "|="), (yyvsp[(3) - (3)].node), "|="); }
    break;

  case 177:
#line 770 "parser.y"
    { (yyval.node) = comma((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 178:
#line 775 "parser.y"
    { (yyval.node) = (node *) NULL; }
    break;

  case 180:
#line 781 "parser.y"
    { t_void((yyval.node) = (yyvsp[(1) - (1)].node)); }
    break;

  case 181:
#line 786 "parser.y"
    { t_void((yyval.node) = (yyvsp[(1) - (1)].node)); }
    break;

  case 182:
#line 790 "parser.y"
    { t_void((yyval.node) = (yyvsp[(1) - (1)].node)); }
    break;

  case 183:
#line 792 "parser.y"
    {
		  t_void((yyvsp[(3) - (3)].node));
		  (yyval.node) = node_bin(N_PAIR, 0, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		}
    break;

  case 184:
#line 800 "parser.y"
    { (yyval.node) = (node *) NULL; }
    break;

  case 186:
#line 803 "parser.y"
    {
		  (yyval.node) = (yyvsp[(1) - (2)].node);
		  if ((yyval.node)->type == N_PAIR) {
		      (yyval.node)->r.right = node_mon(N_SPREAD, -1, (yyval.node)->r.right);
		  } else {
		      (yyval.node) = node_mon(N_SPREAD, -1, (yyval.node));
		  }
		}
    break;

  case 187:
#line 815 "parser.y"
    { (yyval.node) = (node *) NULL; }
    break;

  case 189:
#line 818 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 190:
#line 823 "parser.y"
    {
		  t_void((yyvsp[(1) - (3)].node));
		  t_void((yyvsp[(3) - (3)].node));
		  (yyval.node) = node_bin(N_COMMA, 0, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		}
    break;

  case 192:
#line 833 "parser.y"
    { (yyval.node) = node_bin(N_PAIR, 0, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 193:
#line 838 "parser.y"
    { (yyval.node) = (node *) NULL; }
    break;

  case 195:
#line 841 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;


/* Line 1267 of yacc.c.  */
#line 2850 "y.tab.c"
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


#line 844 "parser.y"


/*
 * NAME:	t_void()
 * DESCRIPTION:	if the argument is of type void, an error will result
 */
static void t_void(node *n)
{
    if (n != (node *) NULL && n->mod == T_VOID) {
	c_error("void value not ignored");
	n->mod = T_MIXED;
    }
}

/*
 * NAME:	t_unary()
 * DESCRIPTION:	typecheck the argument of a unary operator
 */
static bool t_unary(node *n, char *name)
{
    char tnbuf[17];

    t_void(n);
    if (typechecking && !T_ARITHMETIC(n->mod) && n->mod != T_MIXED) {
	c_error("bad argument type for %s (%s)", name,
		i_typename(tnbuf, n->mod));
	n->mod = T_MIXED;
	return FALSE;
    }
    return TRUE;
}

/*
 * NAME:	uassign()
 * DESCRIPTION:	handle a unary assignment operator
 */
static node *uassign(int op, node *n, char *name)
{
    t_unary(n, name);
    return node_mon((n->mod == T_INT) ? op + 1 : op, n->mod, c_lvalue(n, name));
}

/*
 * NAME:	cast()
 * DESCRIPTION:	cast an expression to a type
 */
static node *cast(node *n, node *type)
{
    xfloat flt;
    Int i;
    char *p, buffer[18];

    if (type->mod != n->mod) {
	switch (type->mod) {
	case T_INT:
	    switch (n->type) {
	    case N_FLOAT:
		/* cast float constant to int */
		NFLT_GET(n, flt);
		return node_int(flt_ftoi(&flt));

	    case N_STR:
		/* cast string to int */
		p = n->l.string->text;
		i = strtoint(&p);
		if (p == n->l.string->text + n->l.string->len) {
		    return node_int(i);
		} else {
		    c_error("cast of invalid string constant");
		    n->mod = T_MIXED;
		}
		break;

	    case N_TOFLOAT:
	    case N_TOSTRING:
		if (n->l.left->type == N_INT) {
		    /* (int) (float) i, (int) (string) i */
		    return n->l.left;
		}
		/* fall through */
	    default:
		if (n->mod == T_FLOAT || n->mod == T_STRING ||
		    n->mod == T_MIXED) {
		    return node_mon(N_TOINT, T_INT, n);
		}
		break;
	    }
	    break;

	case T_FLOAT:
	    switch (n->type) {
	    case N_INT:
		/* cast int constant to float */
		flt_itof(n->l.number, &flt);
		return node_float(&flt);

	    case N_STR:
		/* cast string to float */
		p = n->l.string->text;
		if (flt_atof(&p, &flt) &&
		    p == n->l.string->text + n->l.string->len) {
		    return node_float(&flt);
		} else {
		    yyerror("cast of invalid string constant");
		    n->mod = T_MIXED;
		}
		break;

	    case N_TOSTRING:
		if (n->l.left->mod == T_INT) {
		    return node_mon(N_TOFLOAT, T_FLOAT, n->l.left);
		}
		/* fall through */
	    default:
		if (n->mod == T_INT || n->mod == T_STRING || n->mod == T_MIXED)
		{
		    return node_mon(N_TOFLOAT, T_FLOAT, n);
		}
		break;
	    }
	    break;

	case T_STRING:
	    switch (n->type) {
	    case N_INT:
		/* cast int constant to string */
		sprintf(buffer, "%ld", (long) n->l.number);
		return node_str(str_new(buffer, (long) strlen(buffer)));

	    case N_FLOAT:
		/* cast float constant to string */
		NFLT_GET(n, flt);
		flt_ftoa(&flt, buffer);
		return node_str(str_new(buffer, (long) strlen(buffer)));

	    default:
		if (n->mod == T_INT || n->mod == T_FLOAT || n->mod == T_MIXED) {
		    return node_mon(N_TOSTRING, T_STRING, n);
		}
		break;
	    }
	    break;
	}

	if (type->mod == T_MIXED || (type->mod & T_TYPE) == T_VOID) {
	    /* (mixed), (void), (void *) */
	    c_error("cannot cast to %s", i_typename(buffer, type->mod));
	    n->mod = T_MIXED;
	} else if ((type->mod & T_REF) < (n->mod & T_REF)) {
	    /* (mixed *) of (mixed **) */
	    c_error("illegal cast of array type (%s)",
		    i_typename(buffer, n->mod));
	} else if ((n->mod & T_TYPE) != T_MIXED &&
		   ((type->mod & T_TYPE) != T_CLASS ||
		    ((n->mod & T_TYPE) != T_OBJECT &&
		     (n->mod & T_TYPE) != T_CLASS) ||
		    (type->mod & T_REF) != (n->mod & T_REF))) {
	    /* can only cast from mixed, or object/class to class */
	    c_error("cast of invalid type (%s)", i_typename(buffer, n->mod));
	} else {
	    if ((type->mod & T_REF) == 0 || (n->mod & T_REF) == 0) {
		/* runtime cast */
		n = node_mon(N_CAST, type->mod, n);
	    } else {
		n->mod = type->mod;
	    }
	    n->class = type->class;
	}
    } else if (type->mod == T_CLASS && str_cmp(type->class, n->class) != 0) {
	/*
	 * cast to different object class
	 */
	n = node_mon(N_CAST, type->mod, n);
	n->class = type->class;
    }
    return n;
}

/*
 * NAME:	idx()
 * DESCRIPTION:	handle the [ ] operator
 */
static node *idx(node *n1, node *n2)
{
    char tnbuf[17];
    unsigned short type;

    if (n1->type == N_STR && n2->type == N_INT) {
	/* str [ int ] */
	if (n2->l.number < 0 || n2->l.number >= (Int) n1->l.string->len) {
	    c_error("string index out of range");
	} else {
	    n2->l.number =
		    UCHAR(n1->l.string->text[str_index(n1->l.string,
						       (long) n2->l.number)]);
	}
	return n2;
    }

    if ((n1->mod & T_REF) != 0) {
	/*
	 * array
	 */
	if (typechecking) {
	    type = n1->mod - (1 << REFSHIFT);
	    if (n2->mod != T_INT && n2->mod != T_MIXED) {
		c_error("bad index type (%s)", i_typename(tnbuf, n2->mod));
	    }
	    if (type != T_MIXED) {
		/* you can't trust these arrays */
		n2 = node_mon(N_CAST, type, node_bin(N_INDEX, type, n1, n2));
		n2->class = n1->class;
		return n2;
	    }
	}
	type = T_MIXED;
    } else if (n1->mod == T_STRING) {
	/*
	 * string
	 */
	if (typechecking && n2->mod != T_INT && n2->mod != T_MIXED) {
	    c_error("bad index type (%s)", i_typename(tnbuf, n2->mod));
	}
	type = T_INT;
    } else {
	if (typechecking && n1->mod != T_MAPPING && n1->mod != T_MIXED) {
	    c_error("bad indexed type (%s)", i_typename(tnbuf, n1->mod));
	}
	type = T_MIXED;
    }
    return node_bin(N_INDEX, type, n1, n2);
}

/*
 * NAME:	range()
 * DESCRIPTION:	handle the [ .. ] operator
 */
static node *range(node *n1, node *n2, node *n3)
{
    if (n1->type == N_STR && (n2 == (node *) NULL || n2->type == N_INT) &&
	(n3 == (node *) NULL || n3->type == N_INT)) {
	Int from, to;

	/* str [ int .. int ] */
	from = (n2 == (node *) NULL) ? 0 : n2->l.number;
	to = (n3 == (node *) NULL) ? n1->l.string->len - 1 : n3->l.number;
	if (from < 0 || from > to + 1 || to >= n1->l.string->len) {
	    c_error("invalid string range");
	} else {
	    return node_str(str_range(n1->l.string, (long) from, (long) to));
	}
    }

    if (typechecking && n1->mod != T_MAPPING && n1->mod != T_MIXED) {
	char tnbuf[17];

	/* indices */
	if (n2 != (node *) NULL && n2->mod != T_INT && n2->mod != T_MIXED) {
	    c_error("bad index type (%s)", i_typename(tnbuf, n2->mod));
	}
	if (n3 != (node *) NULL && n3->mod != T_INT && n3->mod != T_MIXED) {
	    c_error("bad index type (%s)", i_typename(tnbuf, n3->mod));
	}
	/* range */
	if ((n1->mod & T_REF) == 0 && n1->mod != T_STRING) {
	    c_error("bad indexed type (%s)", i_typename(tnbuf, n1->mod));
	}
    }

    return node_bin(N_RANGE, n1->mod, n1, node_bin(N_PAIR, 0, n2, n3));
}

/*
 * NAME:	bini()
 * DESCRIPTION:	handle a binary int operator
 */
static node *bini(int op, node *n1, node *n2, char *name)
{
    char tnbuf1[17], tnbuf2[17];

    t_void(n1);
    t_void(n2);

    if (typechecking &&
	((n1->mod != T_INT && n1->mod != T_MIXED) ||
	 (n2->mod != T_INT && n2->mod != T_MIXED))) {
	c_error("bad argument types for %s (%s, %s)", name,
		i_typename(tnbuf1, n1->mod), i_typename(tnbuf2, n2->mod));
    }
    if (n1->mod == T_INT && n2->mod == T_INT) {
	op++;
    }
    return node_bin(op, T_INT, n1, n2);
}

/*
 * NAME:	bina()
 * DESCRIPTION:	handle a binary arithmetic operator
 */
static node *bina(int op, node *n1, node *n2, char *name)
{
    char tnbuf1[17], tnbuf2[17];
    unsigned short type;

    t_void(n1);
    t_void(n2);

    type = T_MIXED;
    if (typechecking &&
	((n1->mod != n2->mod && n1->mod != T_MIXED && n2->mod != T_MIXED) ||
	 (!T_ARITHMETIC(n1->mod) && n1->mod != T_MIXED) ||
	 (!T_ARITHMETIC(n2->mod) && n2->mod != T_MIXED))) {
	c_error("bad argument types for %s (%s, %s)", name,
		i_typename(tnbuf1, n1->mod), i_typename(tnbuf2, n2->mod));
    } else if (n1->mod == T_INT || n2->mod == T_INT) {
	if (n1->mod == T_INT && n2->mod == T_INT) {
	    op++;
	}
	type = T_INT;
    } else if (n1->mod == T_FLOAT || n2->mod == T_FLOAT) {
	type = T_FLOAT;
    }

    return node_bin(op, type, n1, n2);
}

/*
 * NAME:	mult()
 * DESCRIPTION:	handle the * *= operators
 */
static node *mult(int op, node *n1, node *n2, char *name)
{
    xfloat f1, f2;

    if (n1->type == N_INT && n2->type == N_INT) {
	/* i * i */
	n1->l.number *= n2->l.number;
	return n1;
    }
    if (n1->type == N_FLOAT && n2->type == N_FLOAT) {
	NFLT_GET(n1, f1);
	NFLT_GET(n2, f2);
	flt_mult(&f1, &f2);
	NFLT_PUT(n1, f1);
	return n1;
    }
    return bina(op, n1, n2, name);
}

/*
 * NAME:	mdiv()
 * DESCRIPTION:	handle the / /= operators
 */
static node *mdiv(int op, node *n1, node *n2, char *name)
{
    xfloat f1, f2;

    if (n1->type == N_INT && n2->type == N_INT) {
	Int i, d;

	/* i / i */
	i = n1->l.number;
	d = n2->l.number;
	if (d == 0) {
	    /* i / 0 */
	    c_error("division by zero");
	    return n1;
	}
	if ((d | i) < 0) {
	    Int r;

            r = ((Uint) ((i < 0) ? -i : i)) / ((Uint) ((d < 0) ? -d : d));
            n1->l.number = ((i ^ d) < 0) ? -r : r;
	} else {
	    n1->l.number = ((Uint) i) / ((Uint) d);
	}
	return n1;
    } else if (n1->type == N_FLOAT && n2->type == N_FLOAT) {
	/* f / f */
	if (NFLT_ISZERO(n2)) {
	    /* f / 0.0 */
	    c_error("division by zero");
	    return n1;
	}
	NFLT_GET(n1, f1);
	NFLT_GET(n2, f2);
	flt_div(&f1, &f2);
	NFLT_PUT(n1, f1);
	return n1;
    }

    return bina(op, n1, n2, name);
}

/*
 * NAME:	mod()
 * DESCRIPTION:	handle the % %= operators
 */
static node *mod(int op, node *n1, node *n2, char *name)
{
    if (n1->type == N_INT && n2->type == N_INT) {
	Int i, d;

	/* i % i */
	i = n1->l.number;
	d = n2->l.number;
	if (d == 0) {
	    /* i % 0 */
	    c_error("modulus by zero");
	    return n1;
	}
	if (d < 0) {
	    d = -d;
	}
	if (i < 0) {
            n1->l.number = - (Int) (((Uint) -i) % ((Uint) d));
	} else {
	    n1->l.number = ((Uint) i) % ((Uint) d);
	}
	return n1;
    }

    return bini(op, n1, n2, name);
}

/*
 * NAME:	add()
 * DESCRIPTION:	handle the + += operators, possibly rearranging the order
 *		of the expression
 */
static node *add(int op, node *n1, node *n2, char *name)
{
    char tnbuf1[17], tnbuf2[17];
    xfloat f1, f2;
    unsigned short type;

    t_void(n1);
    t_void(n2);

    if (n1->mod == T_STRING) {
	if (n2->mod == T_INT || n2->mod == T_FLOAT ||
	    (n2->mod == T_MIXED && typechecking)) {
	    n2 = cast(n2, node_type(T_STRING, (string *) NULL));
	}
    } else if (n2->mod == T_STRING && op == N_ADD) {
	if (n1->mod == T_INT || n1->mod == T_FLOAT ||
	    (n1->mod == T_MIXED && typechecking)) {
	    n1 = cast(n1, node_type(T_STRING, (string *) NULL));
	}
    }

    if (n1->type == N_INT && n2->type == N_INT) {
	/* i + i */
	n1->l.number += n2->l.number;
	return n1;
    }
    if (n1->type == N_FLOAT && n2->type == N_FLOAT) {
	/* f + f */
	NFLT_GET(n1, f1);
	NFLT_GET(n2, f2);
	flt_add(&f1, &f2);
	NFLT_PUT(n1, f1);
	return n1;
    }
    if (n1->type == N_STR && n2->type == N_STR) {
	/* s + s */
	return node_str(str_add(n1->l.string, n2->l.string));
    }

    type = c_tmatch(n1->mod, n2->mod);
    if (type == T_NIL || type == T_OBJECT || type == T_CLASS) {
	type = T_MIXED;
	if (typechecking) {
	    c_error("bad argument types for %s (%s, %s)", name,
		    i_typename(tnbuf1, n1->mod), i_typename(tnbuf2, n2->mod));
	}
    } else if (type == T_INT) {
	op++;
    } else if (op == N_ADD_EQ) {
	if (n1->mod == T_INT) {
	    n2 = node_mon(N_CAST, T_INT, n2);
	    type = T_INT;
	    op++;
	} else if (n1->mod == T_FLOAT && n2->mod != T_FLOAT) {
	    n2 = node_mon(N_CAST, T_FLOAT, n2);
	    type = T_FLOAT;
	}
    }
    return node_bin(op, type, n1, n2);
}

/*
 * NAME:	sub()
 * DESCRIPTION:	handle the - -= operators
 */
static node *sub(int op, node *n1, node *n2, char *name)
{
    char tnbuf1[17], tnbuf2[17];
    xfloat f1, f2;
    unsigned short type;

    t_void(n1);
    t_void(n2);

    if (n1->type == N_INT && n2->type == N_INT) {
	/* i - i */
	n1->l.number -= n2->l.number;
	return n1;
    }
    if (n1->type == N_FLOAT && n2->type == N_FLOAT) {
	/* f - f */
	NFLT_GET(n1, f1);
	NFLT_GET(n2, f2);
	flt_sub(&f1, &f2);
	NFLT_PUT(n1, f1);
	return n1;
    }

    type = c_tmatch(n1->mod, n2->mod);
    if (type == T_NIL || type == T_STRING || type == T_OBJECT ||
	type == T_CLASS || type == T_MAPPING) {
	if ((type=n1->mod) != T_MAPPING ||
	    (n2->mod != T_MIXED && (n2->mod & T_REF) == 0)) {
	    type = T_MIXED;
	    if (typechecking) {
		c_error("bad argument types for %s (%s, %s)", name,
			i_typename(tnbuf1, n1->mod),
			i_typename(tnbuf2, n2->mod));
	    }
	}
    } else if (type == T_INT) {
	op++;
    } else if (type == T_MIXED) {
	type = (n1->mod == T_MIXED) ? n2->mod : n1->mod;
    } else if (n1->mod == T_MIXED && (n2->mod & T_REF)) {
	type = T_MIXED;
    }
    return node_bin(op, type, n1, n2);
}

/*
 * NAME:	umin()
 * DESCRIPTION:	handle unary minus
 */
static node *umin(node *n)
{
    xfloat flt;

    if (t_unary(n, "unary -")) {
	if (n->mod == T_FLOAT) {
	    FLT_ZERO(flt.high, flt.low);
	    n = sub(N_SUB, node_float(&flt), n, "-");
	} else {
	    n = sub(N_SUB, node_int((Int) 0), n, "-");
	}
    }
    return n;
}

/*
 * NAME:	lshift()
 * DESCRIPTION:	handle the << <<= operators
 */
static node *lshift(int op, node *n1, node *n2, char *name)
{
    if (n2->type == N_INT) {
	if (n2->l.number < 0) {
	    c_error("negative left shift");
	    n2->l.number = 0;
	}
	if (n1->type == N_INT) {
	    /* i << i */
	    n1->l.number = (n2->l.number < 32) ?
			    (Uint) n1->l.number << n2->l.number : 0;
	    return n1;
	}
    }

    return bini(op, n1, n2, name);
}

/*
 * NAME:	rshift()
 * DESCRIPTION:	handle the >> >>= operators
 */
static node *rshift(int op, node *n1, node *n2, char *name)
{
    if (n2->type == N_INT) {
	if (n2->l.number < 0) {
	    c_error("negative right shift");
	    n2->l.number = 0;
	}
	if (n1->type == N_INT) {
	    /* i >> i */
	    n1->l.number = (n2->l.number < 32) ?
			    (Uint) n1->l.number >> n2->l.number : 0;
	    return n1;
	}
    }

    return bini(op, n1, n2, name);
}

/*
 * NAME:	rel()
 * DESCRIPTION:	handle the < > <= >= operators
 */
static node *rel(int op, node *n1, node *n2, char *name)
{
    char tnbuf1[17], tnbuf2[17];

    t_void(n1);
    t_void(n2);

    if (n1->type == N_INT && n2->type == N_INT) {
	/* i . i */
	switch (op) {
	case N_GE:
	    n1->l.number = (n1->l.number >= n2->l.number);
	    break;

	case N_GT:
	    n1->l.number = (n1->l.number > n2->l.number);
	    break;

	case N_LE:
	    n1->l.number = (n1->l.number <= n2->l.number);
	    break;

	case N_LT:
	    n1->l.number = (n1->l.number < n2->l.number);
	    break;
	}
	return n1;
    }
    if (n1->type == N_FLOAT && n2->type == N_FLOAT) {
	xfloat f1, f2;

	/* f . f */
	NFLT_GET(n1, f1);
	NFLT_GET(n2, f2);

	switch (op) {
	case N_GE:
	    return node_int((Int) (flt_cmp(&f1, &f2) >= 0));

	case N_GT:
	    return node_int((Int) (flt_cmp(&f1, &f2) > 0));

	case N_LE:
	    return node_int((Int) (flt_cmp(&f1, &f2) <= 0));

	case N_LT:
	    return node_int((Int) (flt_cmp(&f1, &f2) < 0));
	}
	return n1;
    }
    if (n1->type == N_STR && n2->type == N_STR) {
	/* s . s */
	switch (op) {
	case N_GE:
	    return node_int((Int) (str_cmp(n1->l.string, n2->l.string) >= 0));

	case N_GT:
	    return node_int((Int) (str_cmp(n1->l.string, n2->l.string) > 0));

	case N_LE:
	    return node_int((Int) (str_cmp(n1->l.string, n2->l.string) <= 0));

	case N_LT:
	    return node_int((Int) (str_cmp(n1->l.string, n2->l.string) < 0));
	}
    }

    if (typechecking &&
	((n1->mod != n2->mod && n1->mod != T_MIXED && n2->mod != T_MIXED) ||
	 (!T_ARITHSTR(n1->mod) && n1->mod != T_MIXED) ||
	 (!T_ARITHSTR(n2->mod) && n2->mod != T_MIXED))) {
	c_error("bad argument types for %s (%s, %s)", name,
		i_typename(tnbuf1, n1->mod), i_typename(tnbuf2, n2->mod));
    } else if (n1->mod == T_INT && n2->mod == T_INT) {
	op++;
    }
    return node_bin(op, T_INT, n1, n2);
}

/*
 * NAME:	eq()
 * DESCRIPTION:	handle the == operator
 */
static node *eq(node *n1, node *n2)
{
    char tnbuf1[17], tnbuf2[17];
    xfloat f1, f2;
    int op;

    t_void(n1);
    t_void(n2);

    switch (n1->type) {
    case N_INT:
	if (n2->type == N_INT) {
	    /* i == i */
	    n1->l.number = (n1->l.number == n2->l.number);
	    return n1;
	}
	if (nil_node == N_INT && n1->l.number == 0 && n2->type == N_STR) {
	    /* nil == str */
	    return node_int((Int) FALSE);
	}
	break;

    case N_FLOAT:
	if (n2->type == N_FLOAT) {
	    /* f == f */
	    NFLT_GET(n1, f1);
	    NFLT_GET(n2, f2);
	    return node_int((Int) (flt_cmp(&f1, &f2) == 0));
	}
	break;

    case N_STR:
	if (n2->type == N_STR) {
	    /* s == s */
	    return node_int((Int) (str_cmp(n1->l.string, n2->l.string) == 0));
	}
	if (n2->type == nil_node && n2->l.number == 0) {
	    /* s == nil */
	    return node_int((Int) FALSE);
	}
	break;

    case N_NIL:
	if (n2->type == N_NIL) {
	    /* nil == nil */
	    return node_int((Int) TRUE);
	}
	if (n2->type == N_STR) {
	    /* nil == str */
	    return node_int((Int) FALSE);
	}
	break;
    }

    op = N_EQ;
    if (n1->mod != n2->mod && n1->mod != T_MIXED && n2->mod != T_MIXED &&
	(!c_nil(n1) || !T_POINTER(n2->mod)) &&
	(!c_nil(n2) || !T_POINTER(n1->mod))) {
	if (typechecking) {
	    c_error("incompatible types for equality (%s, %s)",
		    i_typename(tnbuf1, n1->mod), i_typename(tnbuf2, n2->mod));
	}
    } else if (n1->mod == T_INT && n2->mod == T_INT) {
	op++;
    }
    return node_bin(op, T_INT, n1, n2);
}

/*
 * NAME:	and()
 * DESCRIPTION:	handle the & &= operators
 */
static node *and(int op, node *n1, node *n2, char *name)
{
    unsigned short type;

    if (n1->type == N_INT && n2->type == N_INT) {
	/* i & i */
	n1->l.number &= n2->l.number;
	return n1;
    }
    if ((((type=n1->mod) == T_MIXED || type == T_MAPPING) &&
	 ((n2->mod & T_REF) != 0 || n2->mod == T_MIXED)) ||
	((type=c_tmatch(n1->mod, n2->mod)) & T_REF) != T_NIL) {
	/*
	 * possibly array & array or mapping & array
	 */
	return node_bin(op, type, n1, n2);
    }
    return bini(op, n1, n2, name);
}

/*
 * NAME:	xor()
 * DESCRIPTION:	handle the ^ ^= operators
 */
static node *xor(int op, node *n1, node *n2, char *name)
{
    unsigned short type;

    if (n1->type == N_INT && n2->type == N_INT) {
	/* i ^ i */
	n1->l.number ^= n2->l.number;
	return n1;
    }
    if (((type=n1->mod) == T_MIXED && n2->mod == T_MIXED) ||
	((type=c_tmatch(n1->mod, n2->mod)) & T_REF) != T_NIL) {
	/*
	 * possibly array ^ array
	 */
	return node_bin(op, type, n1, n2);
    }
    return bini(op, n1, n2, name);
}

/*
 * NAME:	or()
 * DESCRIPTION:	handle the | |= operators
 */
static node *or(int op, node *n1, node *n2, char *name)
{
    unsigned short type;

    if (n1->type == N_INT && n2->type == N_INT) {
	/* i | i */
	n1->l.number |= n2->l.number;
	return n1;
    }
    if (((type=n1->mod) == T_MIXED && n2->mod == T_MIXED) ||
	((type=c_tmatch(n1->mod, n2->mod)) & T_REF) != T_NIL) {
	/*
	 * possibly array | array
	 */
	return node_bin(op, type, n1, n2);
    }
    return bini(op, n1, n2, name);
}

/*
 * NAME:	land()
 * DESCRIPTION:	handle the && operator
 */
static node *land(node *n1, node *n2)
{
    t_void(n1);
    t_void(n2);

    if ((n1->flags & F_CONST) && (n2->flags & F_CONST)) {
	n1 = c_tst(n1);
	n2 = c_tst(n2);
	n1->l.number &= n2->l.number;
	return n1;
    }

    return node_bin(N_LAND, T_INT, n1, n2);
}

/*
 * NAME:	lor()
 * DESCRIPTION:	handle the || operator
 */
static node *lor(node *n1, node *n2)
{
    t_void(n1);
    t_void(n2);

    if ((n1->flags & F_CONST) && (n2->flags & F_CONST)) {
	n1 = c_tst(n1);
	n2 = c_tst(n2);
	n1->l.number |= n2->l.number;
	return n1;
    }

    return node_bin(N_LOR, T_INT, n1, n2);
}

/*
 * NAME:	quest()
 * DESCRIPTION:	handle the ? : operator
 */
static node *quest(node *n1, node *n2, node *n3)
{
    unsigned short type;

    t_void(n1);

    if ((n2->flags & F_CONST) && n3->type == n2->type) {
	switch (n1->type) {
	case N_INT:
	    return (n1->l.number == 0) ? n3 : n2;

	case N_FLOAT:
	    return (NFLT_ISZERO(n1)) ? n3 : n2;

	case N_STR:
	    return n2;

	case N_NIL:
	    return n3;
	}
    }

    type = T_MIXED;
    if (c_nil(n2) && T_POINTER(n3->mod)) {
	/*
	 * expr ? nil : expr
	 */
	type = n3->mod;
    } else if (c_nil(n3) && T_POINTER(n2->mod)) {
	/*
	 * expr ? expr : nil;
	 */
	type = n2->mod;
    } else if (typechecking) {
	/*
	 * typechecked
	 */
	if (n2->mod == T_VOID || n3->mod == T_VOID) {
	    /* result can never be used */
	    type = T_VOID;
	} else {
	    type = c_tmatch(n2->mod, n3->mod);
	    if (type == T_NIL) {
		/* no typechecking here, just let the result be mixed */
		type = T_MIXED;
	    }
	}
    }

    n1 = node_bin(N_QUEST, type, n1, node_bin(N_PAIR, 0, n2, n3));
    if ((type & T_TYPE) == T_CLASS) {
	if (n2->class == (string *) NULL) {
	    n1->class = n3->class;
	} else if (n3->class == (string *) NULL ||
		   str_cmp(n2->class, n3->class) == 0) {
	    n1->class = n2->class;
	} else {
	    /* downgrade to object */
	    n1->type = (n1->type & T_REF) | T_OBJECT;
	}
    }
    return n1;
}

/*
 * NAME:	assign()
 * DESCRIPTION:	handle the assignment operator
 */
static node *assign(node *n1, node *n2)
{
    char tnbuf1[17], tnbuf2[17];
    node *n, *m;
    unsigned short type;

    if (n1->type == N_AGGR) {
	/*
	 * ({ a, b }) = array;
	 */
	if (typechecking) {
	    type = n2->mod;
	    if ((n2->mod & T_REF) != 0) {
		type -= 1 << REFSHIFT;
		if (type != T_MIXED) {
		    n = node_mon(N_TYPE, type, (node *) NULL);
		    n->class = n2->class;
		    n1->r.right = n;
		}
	    } else if (type != T_MIXED) {
		c_error("incompatible types for = (%s, %s)",
			i_typename(tnbuf1, n1->mod),
			i_typename(tnbuf2, type));
		type = T_MIXED;
	    }
  
	    n = n1->l.left;
	    while (n != (node *) NULL) {
		if (n->type == N_PAIR) {
		    m = n->l.left;
		    n = n->r.right;
		} else {
		    m = n;
		    n = (node *) NULL;
		}
		if (c_tmatch(m->mod, type) == T_NIL) {
		    c_error("incompatible types for = (%s, %s)",
			    i_typename(tnbuf1, m->mod),
			    i_typename(tnbuf2, type));
		}
	    }
	}
	n1 = node_bin(N_ASSIGN, n2->mod, n1, n2);
	n1->class = n2->class;
	return n1;
    } else {
	if (typechecking && (!c_nil(n2) || !T_POINTER(n1->mod))) {
	    /*
	     * typechecked
	     */
	    if (c_tmatch(n1->mod, n2->mod) == T_NIL) {
		c_error("incompatible types for = (%s, %s)",
			i_typename(tnbuf1, n1->mod),
			i_typename(tnbuf2, n2->mod));
	    } else if ((n1->mod != T_MIXED && n2->mod == T_MIXED) ||
		       (n1->mod == T_CLASS &&
			(n2->mod != T_CLASS ||
			 str_cmp(n1->class, n2->class) != 0))) {
		n2 = node_mon(N_CAST, n1->mod, n2);
		n2->class = n1->class;
	    }
	}

	n2 = node_bin(N_ASSIGN, n1->mod, n1, n2);
	n2->class = n1->class;
	return n2;
    }
}

/*
 * NAME:	comma()
 * DESCRIPTION:	handle the comma operator, rearranging the order of the
 *		expression if needed
 */
static node *comma(node *n1, node *n2)
{
    if (n2->type == N_COMMA) {
	/* a, (b, c) --> (a, b), c */
	n2->l.left = comma(n1, n2->l.left);
	return n2;
    } else {
	n1 = node_bin(N_COMMA, n2->mod, n1, n2);
	n1->class = n2->class;
	return n1;
    }
}

