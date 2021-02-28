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
#line 2 "parse.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE char *




typedef struct node{
      int scope;
      int value;
      char name[100];
      char dtype[50];
      int line_num;
      int valid;
}node;

typedef struct table{
      node* head;
}table;
// int count = 0;
extern node symTable[1000];


extern int yylineno;
int valid=1;
int yylex();
int yyerror(const char *s);
extern int SymTable[100];
extern char tdType[50];
extern int t_scope;
extern int dflag;
extern int count;
extern void displaySymTable();
extern int find(int  t_scope, char *yytext);
extern void update(char* name, int value, int scope);
extern int insert(int* idx, int scope, char* dtype, char* val, int line_num);
extern void decrScope();


#line 108 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ID = 258,
    CLASS = 259,
    NUM = 260,
    T_lt = 261,
    T_gt = 262,
    COMMA = 263,
    STRC = 264,
    TERMINATOR = 265,
    RETURN = 266,
    FLT = 267,
    T_lteq = 268,
    T_gteq = 269,
    T_neq = 270,
    T_eqeq = 271,
    T_pl = 272,
    T_min = 273,
    T_mul = 274,
    T_div = 275,
    T_and = 276,
    T_or = 277,
    T_incr = 278,
    T_decr = 279,
    T_not = 280,
    T_eq = 281,
    WHILE = 282,
    INT = 283,
    CHAR = 284,
    FLOAT = 285,
    VOID = 286,
    H = 287,
    MAINTOK = 288,
    INCLUDE = 289,
    BREAK = 290,
    CONTINUE = 291,
    IF = 292,
    ELSE = 293,
    COUT = 294,
    STRING = 295,
    FOR = 296,
    OB = 297,
    CB = 298,
    OBR = 299,
    CBR = 300,
    ENDL = 301,
    CHARACTER = 302,
    str_ins = 303,
    str_extr = 304,
    CIN = 305
  };
#endif
/* Tokens.  */
#define ID 258
#define CLASS 259
#define NUM 260
#define T_lt 261
#define T_gt 262
#define COMMA 263
#define STRC 264
#define TERMINATOR 265
#define RETURN 266
#define FLT 267
#define T_lteq 268
#define T_gteq 269
#define T_neq 270
#define T_eqeq 271
#define T_pl 272
#define T_min 273
#define T_mul 274
#define T_div 275
#define T_and 276
#define T_or 277
#define T_incr 278
#define T_decr 279
#define T_not 280
#define T_eq 281
#define WHILE 282
#define INT 283
#define CHAR 284
#define FLOAT 285
#define VOID 286
#define H 287
#define MAINTOK 288
#define INCLUDE 289
#define BREAK 290
#define CONTINUE 291
#define IF 292
#define ELSE 293
#define COUT 294
#define STRING 295
#define FOR 296
#define OB 297
#define CB 298
#define OBR 299
#define CBR 300
#define ENDL 301
#define CHARACTER 302
#define str_ins 303
#define str_extr 304
#define CIN 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 259 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   445

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,     2,
       2,     2,     2,    52,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    52,    56,    57,    62,    63,    64,    69,
      72,    73,   115,   116,   122,   123,   127,   132,   133,   134,
     135,   136,   137,   138,   142,   143,   144,   145,   146,   151,
     152,   153,   154,   158,   159,   160,   161,   162,   163,   164,
     170,   171,   172,   173,   174,   175,   176,   177,   182,   190,
     198,   204,   212,   221,   228,   234,   241,   250,   263,   264,
     265,   278,   290,   294,   306,   309,   312,   315,   321,   326,
     327,   328,   333,   334,   335,   336,   337,   341,   346,   347,
     348,   351,   352,   353,   356,   357,   358,   359,   360,   361,
     381,   382,   386,   389,   395
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "CLASS", "NUM", "T_lt", "T_gt",
  "COMMA", "STRC", "TERMINATOR", "RETURN", "FLT", "T_lteq", "T_gteq",
  "T_neq", "T_eqeq", "T_pl", "T_min", "T_mul", "T_div", "T_and", "T_or",
  "T_incr", "T_decr", "T_not", "T_eq", "WHILE", "INT", "CHAR", "FLOAT",
  "VOID", "H", "MAINTOK", "INCLUDE", "BREAK", "CONTINUE", "IF", "ELSE",
  "COUT", "STRING", "FOR", "OB", "CB", "OBR", "CBR", "ENDL", "CHARACTER",
  "str_ins", "str_extr", "CIN", "'\"'", "'?'", "':'", "$accept", "S",
  "START", "FunctionDeclaration", "FunctionName", "ParamsType",
  "CLASS_DEC", "MAIN", "BODY", "C", "LOOPS", "LOOPBODY", "statement",
  "COND", "ASSIGN_EXPR", "X", "ARITH_EXPR", "ARITH_NEW", "TERNARY_EXPR",
  "INPUT", "PRINT", "LIT", "TYPE", "RELOP", "bin_boolop", "un_arop",
  "un_boolop", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    34,    63,    58
};
# endif

#define YYPACT_NINF -146

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-146)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,  -146,     3,    19,  -146,   -17,    51,  -146,    29,    39,
      69,    -7,    77,   119,    59,    63,  -146,   366,    59,  -146,
    -146,  -146,    57,  -146,   103,    64,    64,    99,  -146,  -146,
      86,  -146,  -146,  -146,  -146,  -146,    72,   189,   131,  -146,
      78,   118,   120,  -146,   193,  -146,  -146,  -146,  -146,   237,
     138,    25,    25,   109,  -146,   179,  -146,  -146,    25,  -146,
     193,    54,  -146,   108,   269,    40,   147,   163,   125,   127,
     129,   132,  -146,   227,  -146,   164,   176,  -146,  -146,    25,
      25,    25,    25,  -146,  -146,    25,  -146,    15,   193,   193,
     175,     4,  -146,   275,   193,  -146,   139,  -146,   134,  -146,
    -146,  -146,  -146,  -146,  -146,    41,    41,    41,   317,  -146,
     366,   189,   189,    94,  -146,   179,  -146,  -146,   183,  -146,
     150,     7,     7,  -146,  -146,   193,   197,    25,   119,    74,
     195,  -146,    22,   395,    91,  -146,   182,    41,   205,   174,
     181,    99,   209,   323,  -146,   219,    48,  -146,   145,  -146,
    -146,   119,  -146,  -146,   184,    41,  -146,    41,  -146,  -146,
     366,   366,   189,  -146,   178,   197,    25,   197,  -146,   395,
     317,   185,  -146,   196,   230,   232,  -146,   225,  -146,  -146,
      41,  -146,   366,   395,  -146,   197,  -146,  -146,   198,  -146,
     366,  -146
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     2,     0,     0,     1,     0,     0,
      13,     0,     0,     0,     0,     0,     5,     0,    81,    82,
      83,     4,     0,     8,     0,     0,     0,    77,    78,    30,
       0,    79,    92,    93,    94,    81,     0,     0,     0,    80,
       0,     0,     0,    33,    34,    58,    35,    36,    37,    57,
       0,     0,     0,     0,     9,     0,    15,    14,     0,    38,
      39,     0,    77,     0,    41,     0,     0,     0,     0,     0,
       0,     0,    32,     0,    20,     0,     0,    12,    31,     0,
       0,     0,     0,    90,    91,     0,    60,    50,    61,    62,
       0,     0,    11,     0,    48,    75,    72,    74,     0,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    47,    23,
       0,     0,     0,     0,    22,     0,    29,    18,     0,    19,
      69,    64,    65,    66,    67,    59,     0,     0,     0,     0,
       0,    16,     0,     0,    40,    45,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     0,    54,    51,    49,     6,
      10,     0,    76,    73,     0,     0,    46,     0,    44,    28,
       0,     0,     0,    21,    70,     0,     0,     0,     7,     0,
       0,     0,    24,    26,     0,     0,    53,    56,    52,    68,
       0,    43,     0,     0,    71,     0,    42,    27,     0,    55,
       0,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,  -146,  -112,  -146,  -146,  -146,   235,   221,   -49,
     -59,   -97,   -38,  -104,   -27,  -145,   -20,  -146,  -146,  -146,
    -146,   -36,   -11,  -103,   -53,   199,   -33
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    21,    22,    91,    13,    23,    56,    73,
      74,    41,    42,    63,    43,   147,    44,    45,    46,    47,
      48,    49,    50,   105,    85,    51,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      75,    64,    24,    59,    65,   137,    93,   139,   140,     5,
      60,   106,   129,   138,   117,     8,   149,    75,     1,     7,
     176,    14,   178,   126,    15,   152,    81,    82,    62,   108,
      28,    88,    89,   157,   117,   118,    10,    31,    94,   168,
     189,   127,    92,    62,    62,    28,    28,   130,    32,    33,
      34,     2,    31,    31,     6,   118,   165,    95,   174,   121,
     122,   123,   124,   172,   173,   125,   143,   180,   153,   134,
     135,   136,    39,    12,   166,    64,    64,    75,    65,    65,
      17,   155,   107,     9,   117,   187,   142,    39,    39,    27,
      11,    28,    25,   191,    96,   154,    26,   141,    31,    53,
      97,   158,    35,    19,    20,   118,    54,   148,    55,    32,
      33,    34,    83,    84,    35,    19,    20,    24,   150,   170,
      61,   171,    35,    19,    20,    58,    64,    76,    77,    65,
      78,   179,    66,    39,    27,    67,    28,    35,    19,    20,
      24,    87,    30,    31,   186,   188,   177,    18,    19,    20,
      15,    98,    90,   167,    32,    33,    34,   109,    68,    35,
      19,    20,    79,    80,    81,    82,   110,   111,    69,   112,
      36,   113,    70,    37,   119,    71,    72,   114,    39,   120,
      66,    40,    27,    67,    28,   128,   133,   132,    99,   100,
      30,    31,    62,   144,    28,   101,   102,   103,   104,   145,
     146,    31,    32,    33,    34,   151,    68,    35,    19,    20,
      79,    80,    81,    82,    34,   159,    69,   160,    36,   162,
      70,    37,   164,    71,   161,   156,    39,   175,   181,    40,
      27,    67,    28,   185,   182,   184,    39,   169,    30,    31,
     183,   190,    79,    80,    81,    82,    16,    57,    86,     0,
      32,    33,    34,     0,    68,    35,    19,    20,    83,    84,
      32,    33,     0,     0,    69,     0,    36,     0,    70,    37,
       0,   115,   116,     0,    39,    99,   100,    40,    27,    67,
      28,     0,   101,   102,   103,   104,    30,    31,     0,     0,
      83,    84,     0,     0,     0,     0,     0,     0,    32,    33,
      34,     0,    68,    35,    19,    20,     0,     0,     0,     0,
       0,     0,    69,     0,    36,     0,    70,    37,     0,   115,
     131,     0,    39,    99,   100,    40,    27,    67,    28,     0,
     101,   102,   103,   104,    30,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,    33,    34,     0,
      68,    35,    19,    20,     0,     0,     0,     0,     0,     0,
      69,     0,    36,     0,    70,    37,     0,   115,   163,    27,
      39,    28,     0,    40,     0,     0,    29,    30,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,    34,     0,     0,    35,    19,    20,     0,    27,     0,
      28,     0,     0,     0,     0,    36,    30,    31,    37,     0,
      38,     0,     0,    39,     0,     0,    40,     0,    32,    33,
      34,     0,     0,    35,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,    36,     0,     0,    37,     0,     0,
       0,     0,    39,     0,     0,    40
};

static const yytype_int16 yycheck[] =
{
      38,    37,    13,    30,    37,   108,    55,   111,   112,     6,
      30,    64,     8,   110,    73,    32,   128,    55,     1,     0,
     165,    28,   167,     8,    31,     3,    19,    20,     3,    65,
       5,    51,    52,   136,    93,    73,     7,    12,    58,   151,
     185,    26,    53,     3,     3,     5,     5,    43,    23,    24,
      25,    34,    12,    12,    51,    93,     8,     3,   162,    79,
      80,    81,    82,   160,   161,    85,   115,   170,    46,   105,
     106,   107,    47,     4,    26,   111,   112,   115,   111,   112,
       3,   134,    42,    32,   143,   182,   113,    47,    47,     3,
      51,     5,    33,   190,    40,   133,    33,     3,    12,    42,
      46,   137,    28,    29,    30,   143,     3,   127,    44,    23,
      24,    25,    21,    22,    28,    29,    30,   128,   129,   155,
      48,   157,    28,    29,    30,    26,   162,    49,    10,   162,
      10,   169,     1,    47,     3,     4,     5,    28,    29,    30,
     151,     3,    11,    12,   180,   183,   166,    28,    29,    30,
      31,    43,    43,     8,    23,    24,    25,    10,    27,    28,
      29,    30,    17,    18,    19,    20,     3,    42,    37,    42,
      39,    42,    41,    42,    10,    44,    45,    45,    47,     3,
       1,    50,     3,     4,     5,    10,    52,    48,     6,     7,
      11,    12,     3,    10,     5,    13,    14,    15,    16,    49,
       3,    12,    23,    24,    25,    10,    27,    28,    29,    30,
      17,    18,    19,    20,    25,    10,    37,    43,    39,    10,
      41,    42,     3,    44,    43,    43,    47,    49,    43,    50,
       3,     4,     5,     8,    38,     3,    47,    53,    11,    12,
      10,    43,    17,    18,    19,    20,    11,    26,    49,    -1,
      23,    24,    25,    -1,    27,    28,    29,    30,    21,    22,
      23,    24,    -1,    -1,    37,    -1,    39,    -1,    41,    42,
      -1,    44,    45,    -1,    47,     6,     7,    50,     3,     4,
       5,    -1,    13,    14,    15,    16,    11,    12,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    39,    -1,    41,    42,    -1,    44,
      45,    -1,    47,     6,     7,    50,     3,     4,     5,    -1,
      13,    14,    15,    16,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    39,    -1,    41,    42,    -1,    44,    45,     3,
      47,     5,    -1,    50,    -1,    -1,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    -1,    -1,    28,    29,    30,    -1,     3,    -1,
       5,    -1,    -1,    -1,    -1,    39,    11,    12,    42,    -1,
      44,    -1,    -1,    47,    -1,    -1,    50,    -1,    23,    24,
      25,    -1,    -1,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    34,    55,    56,     6,    51,     0,    32,    32,
       7,    51,     4,    60,    28,    31,    61,     3,    28,    29,
      30,    57,    58,    61,    76,    33,    33,     3,     5,    10,
      11,    12,    23,    24,    25,    28,    39,    42,    44,    47,
      50,    65,    66,    68,    70,    71,    72,    73,    74,    75,
      76,    79,    80,    42,     3,    44,    62,    62,    26,    68,
      70,    48,     3,    67,    75,    80,     1,     4,    27,    37,
      41,    44,    45,    63,    64,    66,    49,    10,    10,    17,
      18,    19,    20,    21,    22,    78,    79,     3,    70,    70,
      43,    59,    76,    63,    70,     3,    40,    46,    43,     6,
       7,    13,    14,    15,    16,    77,    78,    42,    75,    10,
       3,    42,    42,    42,    45,    44,    45,    64,    66,    10,
       3,    70,    70,    70,    70,    70,     8,    26,    10,     8,
      43,    45,    48,    52,    75,    75,    75,    77,    65,    67,
      67,     3,    68,    63,    10,    49,     3,    69,    70,    57,
      76,    10,     3,    46,    66,    78,    43,    77,    75,    10,
      43,    43,    10,    45,     3,     8,    26,     8,    57,    53,
      75,    75,    65,    65,    67,    49,    69,    70,    69,    66,
      77,    43,    38,    10,     3,     8,    75,    65,    66,    69,
      43,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    57,    57,    57,    58,
      59,    59,    60,    60,    61,    61,    62,    63,    63,    63,
      63,    63,    63,    63,    64,    64,    64,    64,    64,    65,
      65,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    68,
      68,    68,    68,    69,    69,    69,    69,    70,    70,    70,
      70,    70,    70,    71,    71,    71,    71,    71,    72,    73,
      73,    73,    74,    74,    74,    74,    74,    75,    75,    75,
      75,    76,    76,    76,    77,    77,    77,    77,    77,    77,
      78,    78,    79,    79,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     6,     5,     5,     6,     1,     2,
       3,     1,     4,     0,     3,     3,     3,     3,     2,     2,
       1,     4,     2,     2,     5,     9,     5,     7,     4,     3,
       1,     2,     2,     1,     1,     1,     1,     1,     2,     2,
       3,     1,     7,     6,     4,     3,     4,     2,     3,     4,
       2,     4,     6,     3,     1,     5,     3,     1,     1,     3,
       2,     2,     2,     1,     3,     3,     3,     3,     7,     3,
       5,     7,     3,     5,     3,     3,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
#line 51 "parse.y" /* yacc.c:1646  */
    {printf("Successful parsing.\n");displaySymTable();exit(0);}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 52 "parse.y" /* yacc.c:1646  */
    { yyerrok; yyclearin;}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 182 "parse.y" /* yacc.c:1646  */
    {
      ;
        if (find(t_scope, (yyvsp[-2])) == -1) {
          yyerror("variable not declared");
        }
      update((yyvsp[-2]), (int)(yyvsp[0]), t_scope);
    }
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 190 "parse.y" /* yacc.c:1646  */
    {
        if(!insert(&count, t_scope, (yyvsp[-3]), (yyvsp[-2]), yylineno))
              yyerror("Variable redeclared");

        update((yyvsp[-2]), (int)(yyvsp[0]), t_scope);
      }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 198 "parse.y" /* yacc.c:1646  */
    {

        if(!insert(&count, t_scope, (yyvsp[-1]), (yyvsp[0]), yylineno))
              yyerror("Variable redeclared");
      }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 204 "parse.y" /* yacc.c:1646  */
    {
        strcpy(tdType, (yyvsp[-3]));
        dflag = 1;

        if(!insert(&count, t_scope, (yyvsp[-3]), (yyvsp[-2]), yylineno))
              yyerror("Variable redeclared");
            }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 212 "parse.y" /* yacc.c:1646  */
    {
        strcpy(tdType, (yyvsp[-5]));
        dflag = 1;
        if(!insert(&count, t_scope, (yyvsp[-5]), (yyvsp[-4]), yylineno))
              yyerror("Variable redeclared");
        update((yyvsp[-4]), atoi((yyvsp[-2])), t_scope);
      }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 221 "parse.y" /* yacc.c:1646  */
    {
  if(!insert(&count, t_scope, tdType, (yyvsp[-2]), yylineno)){
    printf("redeclared: %s\n", (yyvsp[-2]));
    yyerror("Variable redeclared");
  }
}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 228 "parse.y" /* yacc.c:1646  */
    {
    if(!insert(&count, t_scope, tdType, (yyvsp[0]), yylineno)){
      printf("redeclared: %s\n", (yyvsp[0]));
      yyerror("Variable redeclared");
    }
  }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 234 "parse.y" /* yacc.c:1646  */
    {
    if(!insert(&count, t_scope, tdType, (yyvsp[-4]), yylineno)){
      printf("redeclared: %s\n", (yyvsp[-4]));
      yyerror("Variable redeclared");
    }
    update((yyvsp[-4]), atoi((yyvsp[-2])), t_scope);
  }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 241 "parse.y" /* yacc.c:1646  */
    {
    if(!insert(&count, t_scope, tdType, (yyvsp[-2]), yylineno)){
      printf("redeclared: %s\n", (yyvsp[-2]));
      yyerror("Variable redeclared");
    }
    update((yyvsp[-2]), atoi((yyvsp[0])), t_scope);
  }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 250 "parse.y" /* yacc.c:1646  */
    {
            int val;
            if(atoi((yyvsp[0]))){
                  val = atoi((yyvsp[0]));
            }
            else{
                  int idx = find(t_scope, (yyvsp[0]));
                  val = symTable[idx].value;
                  
            } 
            (yyval) = val;
          
      }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 263 "parse.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 265 "parse.y" /* yacc.c:1646  */
    {
            int val;
            if(atoi((yyvsp[-1]))){
                  yyerror("needs an lvalue");
            }
            else{
                  int idx = find(t_scope, (yyvsp[-1]));
                  val = symTable[idx].value;
                  update((yyvsp[-1]), val+1, t_scope);                  
            } 
            (yyval) = val;
            
      }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 278 "parse.y" /* yacc.c:1646  */
    {
            int val;
            if(atoi((yyvsp[0]))){
                  yyerror("needs an lvalue");
            }
            else{
                  int idx = find(t_scope, (yyvsp[0]));
                  val = symTable[idx].value + 1;
                  update((yyvsp[0]), val+1, t_scope);                  
            } 
            (yyval) = val;
      }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 294 "parse.y" /* yacc.c:1646  */
    {
            int val;
            if(atoi((yyvsp[0]))){
                  val = atoi((yyvsp[0]));
            }
            else{
                  int idx = find(t_scope, (yyvsp[0]));
                  val = symTable[idx].value;
                  
            } 
            (yyval) = val; 
      }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 306 "parse.y" /* yacc.c:1646  */
    {
            (yyval) = (int)(yyvsp[-2]) + (int)(yyvsp[0]);
      }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 309 "parse.y" /* yacc.c:1646  */
    {
            (yyval) = (int)(yyvsp[-2]) - (int)(yyvsp[0]);
      }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 312 "parse.y" /* yacc.c:1646  */
    {
            (yyval) = (int)(yyvsp[-2]) * (int)(yyvsp[0]);
      }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 315 "parse.y" /* yacc.c:1646  */
    {
            (yyval) = (int)(yyvsp[-2]) / (int)(yyvsp[0]);
      }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 341 "parse.y" /* yacc.c:1646  */
    {
        if (find(t_scope, (yyvsp[0])) == -1) {
            yyerror("variable not declared");
        }
      }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 386 "parse.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
      }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 389 "parse.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
      }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1767 "y.tab.c" /* yacc.c:1646  */
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
#line 405 "parse.y" /* yacc.c:1906  */


#include <ctype.h>
int yyerror(const char *s)
{
  	extern int yylineno;
  	valid =0;
  	printf("\n\nERROR: line number: %d - error: %s\n\n",yylineno,s);

}

int main()
{
	t_scope=1;
	count=0;
	yyparse();
	if(valid)
  		printf("Parsing successful\n\n\n");
	else
	{
  		printf("Parsing unsuccessful\n\n\n");
	}
	displaySymTable();
	return 0;
}
