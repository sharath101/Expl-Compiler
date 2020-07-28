/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "4.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "4.h"
	#include "4.c"
	int yylex(void);

#line 79 "y.tab.c"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    NUM = 258,
    TEXT = 259,
    ID = 260,
    PLUS = 261,
    MINUS = 262,
    MUL = 263,
    DIV = 264,
    MOD = 265,
    EQ = 266,
    BEGIN1 = 267,
    END = 268,
    READ = 269,
    WRITE = 270,
    POW = 271,
    IF = 272,
    ELSE = 273,
    THEN = 274,
    ENDIF = 275,
    WHILE = 276,
    DO = 277,
    ENDWHILE = 278,
    EQEQ = 279,
    NOTEQ = 280,
    GREAT = 281,
    GREATEQ = 282,
    LESS = 283,
    LESSEQ = 284,
    BREAK = 285,
    CONTINUE = 286,
    INT = 287,
    STR = 288,
    IDec = 289,
    Varlist = 290,
    DECL = 291,
    ENDDECL = 292
  };
#endif
/* Tokens.  */
#define NUM 258
#define TEXT 259
#define ID 260
#define PLUS 261
#define MINUS 262
#define MUL 263
#define DIV 264
#define MOD 265
#define EQ 266
#define BEGIN1 267
#define END 268
#define READ 269
#define WRITE 270
#define POW 271
#define IF 272
#define ELSE 273
#define THEN 274
#define ENDIF 275
#define WHILE 276
#define DO 277
#define ENDWHILE 278
#define EQEQ 279
#define NOTEQ 280
#define GREAT 281
#define GREATEQ 282
#define LESS 283
#define LESSEQ 284
#define BREAK 285
#define CONTINUE 286
#define INT 287
#define STR 288
#define IDec 289
#define Varlist 290
#define DECL 291
#define ENDDECL 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "4.y"

	struct tnode *no;

#line 200 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   436

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

#define YYUNDEFTOK  2
#define YYMAXUTOK   292

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    42,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    27,    27,    47,    50,    51,    53,    53,    53,    54,
      54,    55,    56,    57,    59,    61,    62,    64,    65,    68,
      69,    71,    73,    74,    76,    76,    78,    80,    80,    82,
      82,    84,    85,    86,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "TEXT", "ID", "PLUS", "MINUS",
  "MUL", "DIV", "MOD", "EQ", "BEGIN1", "END", "READ", "WRITE", "POW", "IF",
  "ELSE", "THEN", "ENDIF", "WHILE", "DO", "ENDWHILE", "EQEQ", "NOTEQ",
  "GREAT", "GREATEQ", "LESS", "LESSEQ", "BREAK", "CONTINUE", "INT", "STR",
  "IDec", "Varlist", "DECL", "ENDDECL", "'['", "';'", "'('", "')'", "']'",
  "$accept", "program", "Slist", "stmt", "input", "output", "asgn",
  "ifstmt", "whilestmt", "Declarations", "DeclList", "Decl", "Type",
  "VarList", "var", "expr", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,    91,    59,
      40,    41,    93
};
# endif

#define YYPACT_NINF -115

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-115)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,   319,    13,  -115,   -17,   -16,    41,    47,    58,    63,
      79,    64,   330,  -115,    92,    95,    99,   107,   108,  -115,
       1,  -115,  -115,    18,    14,    14,    14,  -115,  -115,  -115,
    -115,  -115,   100,  -115,     7,   109,  -115,  -115,  -115,  -115,
    -115,  -115,    14,    14,    62,  -115,  -115,    14,   183,   207,
      66,   231,   255,  -115,  -115,  -115,    49,  -115,    66,   407,
     135,   159,  -115,   279,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,  -115,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,  -115,
      86,   117,  -115,  -115,  -115,  -115,  -115,    61,    70,    61,
      70,     0,    24,     0,    24,    -5,   133,   112,  -115,    -1,
      20,    -1,    20,    -1,    20,    -1,    20,    -1,    20,    -1,
      20,    61,    70,    61,    70,     0,    24,     0,    24,    -5,
     133,   112,  -115,    -1,    20,    -1,    20,    -1,    20,    -1,
      20,    -1,    20,    -1,    20,   376,   376,   295,   348,   376,
    -115,  -115,   368,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,    11,
       0,     1,     3,     0,     0,     0,     0,    12,    13,    27,
      28,    23,     0,    25,     0,     0,     4,     6,     7,     8,
       9,    10,     0,     0,     0,    83,    84,     0,     0,     0,
       0,     0,     0,    22,    24,    30,     0,     2,    18,    17,
       0,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,    29,    26,    32,    33,    46,    71,    47,    72,
      48,    73,    49,    74,    50,    75,    51,    76,    52,    82,
      58,    81,    57,    78,    54,    80,    56,    77,    53,    79,
      55,    59,    34,    60,    35,    61,    36,    62,    37,    63,
      38,    64,    39,    70,    45,    69,    44,    66,    41,    68,
      43,    65,    40,    67,    42,     0,     0,     0,     0,     0,
      20,    21,     0,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -115,  -115,  -114,   -12,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,   120,  -115,  -115,   -22,    42
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    12,    13,    14,    15,    16,    17,    18,    19,
      32,    33,    34,    56,    20,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    44,    48,    50,    50,    64,    65,    66,    67,    68,
      68,    69,    42,    21,     1,    69,    69,    45,    46,     3,
      58,    60,    22,     3,    23,    50,    77,    78,    79,    80,
      81,   147,   148,    43,    81,   152,    82,    43,    43,    43,
      82,    55,    97,    99,   101,   103,   105,   107,   109,   111,
     113,   115,   117,   119,    47,   121,   123,   125,   127,   129,
     131,   133,   135,   137,   139,   141,   143,    51,    52,    66,
      67,    68,    64,    65,    66,    67,    68,    69,    79,    80,
      81,    24,    69,    92,    59,    61,    82,    25,    93,    63,
      70,    71,    72,    73,    74,    75,    29,    30,    26,    43,
      43,    31,    27,    62,    43,   145,    98,   100,   102,   104,
     106,   108,   110,   112,   114,   116,   118,   120,    28,   122,
     124,   126,   128,   130,   132,   134,   136,   138,   140,   142,
     144,    37,    29,    30,    38,    36,    36,    53,    39,   146,
      36,    64,    65,    66,    67,    68,    40,    41,    57,    82,
      43,    69,    54,     0,     0,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    77,    78,    79,    80,    81,
       0,     0,     0,    43,     0,    82,     0,    94,     0,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    88,    64,
      65,    66,    67,    68,     0,     0,     0,     0,     0,    69,
       0,    95,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    77,    78,    79,    80,    81,     0,     0,
       0,    43,     0,    82,    76,     0,     0,     0,     0,     0,
       0,    83,    84,    85,    86,    87,    88,    77,    78,    79,
      80,    81,     0,     0,     0,     0,     0,    82,    89,     0,
       0,     0,     0,     0,     0,    83,    84,    85,    86,    87,
      88,    77,    78,    79,    80,    81,     0,     0,     0,     0,
       0,    82,    90,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,    87,    88,    77,    78,    79,    80,    81,
       0,     0,     0,     0,     0,    82,    91,     0,     0,     0,
       3,     0,     0,    83,    84,    85,    86,    87,    88,     5,
       6,     0,     7,   149,     0,   150,     8,     0,     0,     0,
      96,     0,     0,     0,     3,     9,    10,     0,     0,     0,
       0,    11,     4,     5,     6,     3,     7,     0,     0,     0,
       8,     0,     0,    35,     5,     6,     0,     7,     0,     9,
      10,     8,     0,     3,     0,    11,     0,     0,     0,     0,
       9,    10,     5,     6,     0,     7,    11,     0,     0,     8,
       0,   151,     0,     3,     0,     0,     0,     0,     9,    10,
       0,     3,     5,     6,    11,     7,     0,     0,   153,     8,
       5,     6,     0,     7,     0,     0,     0,     8,     9,    10,
       0,     0,     0,     0,    11,     0,     9,    10,     0,     0,
       0,     0,    11,    77,    78,    79,    80,    81,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,    83,    84,    85,    86,    87,    88
};

static const yytype_int16 yycheck[] =
{
      12,    23,    24,    25,    26,     6,     7,     8,     9,    10,
      10,    16,    11,     0,    12,    16,    16,     3,     4,     5,
      42,    43,    39,     5,    40,    47,     6,     7,     8,     9,
      10,   145,   146,    38,    10,   149,    16,    38,    38,    38,
      16,    34,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    40,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    25,    26,     8,
       9,    10,     6,     7,     8,     9,    10,    16,     8,     9,
      10,    40,    16,    34,    42,    43,    16,    40,    39,    47,
      24,    25,    26,    27,    28,    29,    32,    33,    40,    38,
      38,    37,    39,    41,    38,    19,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    39,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    39,    32,    33,    39,   147,   148,    37,    39,    22,
     152,     6,     7,     8,     9,    10,    39,    39,    39,    16,
      38,    16,    32,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    38,    -1,    16,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    29,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    38,    -1,    16,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    16,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,
      29,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    16,    41,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    16,    41,    -1,    -1,    -1,
       5,    -1,    -1,    24,    25,    26,    27,    28,    29,    14,
      15,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    -1,
      41,    -1,    -1,    -1,     5,    30,    31,    -1,    -1,    -1,
      -1,    36,    13,    14,    15,     5,    17,    -1,    -1,    -1,
      21,    -1,    -1,    13,    14,    15,    -1,    17,    -1,    30,
      31,    21,    -1,     5,    -1,    36,    -1,    -1,    -1,    -1,
      30,    31,    14,    15,    -1,    17,    36,    -1,    -1,    21,
      -1,    23,    -1,     5,    -1,    -1,    -1,    -1,    30,    31,
      -1,     5,    14,    15,    36,    17,    -1,    -1,    20,    21,
      14,    15,    -1,    17,    -1,    -1,    -1,    21,    30,    31,
      -1,    -1,    -1,    -1,    36,    -1,    30,    31,    -1,    -1,
      -1,    -1,    36,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    44,     5,    13,    14,    15,    17,    21,    30,
      31,    36,    45,    46,    47,    48,    49,    50,    51,    52,
      57,     0,    39,    40,    40,    40,    40,    39,    39,    32,
      33,    37,    53,    54,    55,    13,    46,    39,    39,    39,
      39,    39,    11,    38,    57,     3,     4,    40,    57,    58,
      57,    58,    58,    37,    54,    34,    56,    39,    57,    58,
      57,    58,    41,    58,     6,     7,     8,     9,    10,    16,
      24,    25,    26,    27,    28,    29,    41,     6,     7,     8,
       9,    10,    16,    24,    25,    26,    27,    28,    29,    41,
      41,    41,    34,    39,    42,    42,    41,    57,    58,    57,
      58,    57,    58,    57,    58,    57,    58,    57,    58,    57,
      58,    57,    58,    57,    58,    57,    58,    57,    58,    57,
      58,    57,    58,    57,    58,    57,    58,    57,    58,    57,
      58,    57,    58,    57,    58,    57,    58,    57,    58,    57,
      58,    57,    58,    57,    58,    19,    22,    45,    45,    18,
      20,    23,    45,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    46,    46,    46,    46,
      46,    46,    46,    46,    47,    48,    48,    49,    49,    50,
      50,    51,    52,    52,    53,    53,    54,    55,    55,    56,
      56,    57,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     2,     1,     2,     2,     2,     2,
       2,     1,     2,     2,     4,     4,     4,     3,     3,     9,
       7,     7,     3,     2,     2,     1,     3,     1,     1,     2,
       1,     1,     4,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
#line 27 "4.y"
    {
										(yyval.no)=(yyvsp[-2].no);
										printf("program done\n"); 
										FILE *fptr = fopen("target.xsm", "w");
										fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
										fprintf(fptr, "BRKP\n");
										int p=codegen((yyvsp[-2].no),fptr);
										fprintf(fptr, "PASS");
										FILE *fptr2 = fopen("array.c", "w");
										fprintf(fptr2,"int a1[100]={");
										for(int i=0;i<r;i++){
											if(i==0)
												fprintf(fptr2,"%d",a[i]);
											else
												fprintf(fptr2,",%d",a[i]);
										}
										fprintf(fptr2,"};");
										printf("program done\n");
										exit(1);
									}
#line 1471 "y.tab.c"
    break;

  case 3:
#line 47 "4.y"
    {exit(1);}
#line 1477 "y.tab.c"
    break;

  case 4:
#line 50 "4.y"
    {(yyval.no) = makenode("connector",3,-1,(yyvsp[-1].no),NULL,(yyvsp[0].no));}
#line 1483 "y.tab.c"
    break;

  case 12:
#line 56 "4.y"
    {(yyval.no)=(yyvsp[-1].no);}
#line 1489 "y.tab.c"
    break;

  case 13:
#line 57 "4.y"
    {(yyval.no)=(yyvsp[-1].no);}
#line 1495 "y.tab.c"
    break;

  case 14:
#line 59 "4.y"
    {(yyval.no) = makenode("read",1,-1,(yyvsp[-1].no),NULL,NULL);}
#line 1501 "y.tab.c"
    break;

  case 15:
#line 61 "4.y"
    {(yyval.no) = makenode("write",2,-1,(yyvsp[-1].no),NULL,NULL);}
#line 1507 "y.tab.c"
    break;

  case 16:
#line 62 "4.y"
    {(yyval.no) = makenode("write",2,-1,(yyvsp[-1].no),NULL,NULL);}
#line 1513 "y.tab.c"
    break;

  case 17:
#line 64 "4.y"
    {(yyval.no) = makenode("=",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1519 "y.tab.c"
    break;

  case 18:
#line 65 "4.y"
    {(yyval.no) = makenode("=",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1525 "y.tab.c"
    break;

  case 19:
#line 68 "4.y"
    {(yyval.no)= makenode("ifelse",6,-1,(yyvsp[-6].no),(yyvsp[-3].no),(yyvsp[-1].no));}
#line 1531 "y.tab.c"
    break;

  case 20:
#line 69 "4.y"
    {(yyval.no)= makenode("if",6,-1,(yyvsp[-4].no),(yyvsp[-1].no),NULL);}
#line 1537 "y.tab.c"
    break;

  case 21:
#line 71 "4.y"
    {(yyval.no)= makenode("while",5,-1,(yyvsp[-4].no),NULL,(yyvsp[-1].no));}
#line 1543 "y.tab.c"
    break;

  case 22:
#line 73 "4.y"
    {(yyval.no)= makeleaf('d',8);}
#line 1549 "y.tab.c"
    break;

  case 23:
#line 74 "4.y"
    {(yyval.no)= makeleaf('d',8);}
#line 1555 "y.tab.c"
    break;

  case 32:
#line 85 "4.y"
    {(yyval.no) = makearraynode((yyvsp[-3].no)->varname,0,(yyvsp[-1].no));}
#line 1561 "y.tab.c"
    break;

  case 33:
#line 86 "4.y"
    {(yyval.no) = makearraynode((yyvsp[-3].no)->varname,0,(yyvsp[-1].no));}
#line 1567 "y.tab.c"
    break;

  case 34:
#line 88 "4.y"
    {(yyval.no) = makenode("+",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1573 "y.tab.c"
    break;

  case 35:
#line 89 "4.y"
    {(yyval.no) = makenode("-",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1579 "y.tab.c"
    break;

  case 36:
#line 90 "4.y"
    {(yyval.no) = makenode("*",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1585 "y.tab.c"
    break;

  case 37:
#line 91 "4.y"
    {(yyval.no) = makenode("/",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1591 "y.tab.c"
    break;

  case 38:
#line 92 "4.y"
    {(yyval.no) = makenode("%",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1597 "y.tab.c"
    break;

  case 39:
#line 93 "4.y"
    {(yyval.no) = makenode("@",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1603 "y.tab.c"
    break;

  case 40:
#line 94 "4.y"
    {(yyval.no) = makenode("<",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1609 "y.tab.c"
    break;

  case 41:
#line 95 "4.y"
    {(yyval.no) = makenode(">",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1615 "y.tab.c"
    break;

  case 42:
#line 96 "4.y"
    {(yyval.no) = makenode("<=",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1621 "y.tab.c"
    break;

  case 43:
#line 97 "4.y"
    {(yyval.no) = makenode(">=",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1627 "y.tab.c"
    break;

  case 44:
#line 98 "4.y"
    {(yyval.no) = makenode("!=",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1633 "y.tab.c"
    break;

  case 45:
#line 99 "4.y"
    {(yyval.no) = makenode("==",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1639 "y.tab.c"
    break;

  case 46:
#line 100 "4.y"
    {(yyval.no) = (yyvsp[-1].no);}
#line 1645 "y.tab.c"
    break;

  case 47:
#line 101 "4.y"
    {(yyval.no) = makenode("+",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1651 "y.tab.c"
    break;

  case 48:
#line 102 "4.y"
    {(yyval.no) = makenode("-",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1657 "y.tab.c"
    break;

  case 49:
#line 103 "4.y"
    {(yyval.no) = makenode("*",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1663 "y.tab.c"
    break;

  case 50:
#line 104 "4.y"
    {(yyval.no) = makenode("/",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1669 "y.tab.c"
    break;

  case 51:
#line 105 "4.y"
    {(yyval.no) = makenode("%",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1675 "y.tab.c"
    break;

  case 52:
#line 106 "4.y"
    {(yyval.no) = makenode("@",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1681 "y.tab.c"
    break;

  case 53:
#line 107 "4.y"
    {(yyval.no) = makenode("<",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1687 "y.tab.c"
    break;

  case 54:
#line 108 "4.y"
    {(yyval.no) = makenode(">",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1693 "y.tab.c"
    break;

  case 55:
#line 109 "4.y"
    {(yyval.no) = makenode("<=",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1699 "y.tab.c"
    break;

  case 56:
#line 110 "4.y"
    {(yyval.no) = makenode(">=",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1705 "y.tab.c"
    break;

  case 57:
#line 111 "4.y"
    {(yyval.no) = makenode("!=",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1711 "y.tab.c"
    break;

  case 58:
#line 112 "4.y"
    {(yyval.no) = makenode("==",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1717 "y.tab.c"
    break;

  case 59:
#line 114 "4.y"
    {(yyval.no) = makenode("+",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1723 "y.tab.c"
    break;

  case 60:
#line 115 "4.y"
    {(yyval.no) = makenode("-",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1729 "y.tab.c"
    break;

  case 61:
#line 116 "4.y"
    {(yyval.no) = makenode("*",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1735 "y.tab.c"
    break;

  case 62:
#line 117 "4.y"
    {(yyval.no) = makenode("/",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1741 "y.tab.c"
    break;

  case 63:
#line 118 "4.y"
    {(yyval.no) = makenode("%",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1747 "y.tab.c"
    break;

  case 64:
#line 119 "4.y"
    {(yyval.no) = makenode("@",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1753 "y.tab.c"
    break;

  case 65:
#line 120 "4.y"
    {(yyval.no) = makenode("<",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1759 "y.tab.c"
    break;

  case 66:
#line 121 "4.y"
    {(yyval.no) = makenode(">",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1765 "y.tab.c"
    break;

  case 67:
#line 122 "4.y"
    {(yyval.no) = makenode("<=",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1771 "y.tab.c"
    break;

  case 68:
#line 123 "4.y"
    {(yyval.no) = makenode(">=",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1777 "y.tab.c"
    break;

  case 69:
#line 124 "4.y"
    {(yyval.no) = makenode("!=",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1783 "y.tab.c"
    break;

  case 70:
#line 125 "4.y"
    {(yyval.no) = makenode("==",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1789 "y.tab.c"
    break;

  case 71:
#line 127 "4.y"
    {(yyval.no) = makenode("+",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1795 "y.tab.c"
    break;

  case 72:
#line 128 "4.y"
    {(yyval.no) = makenode("-",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1801 "y.tab.c"
    break;

  case 73:
#line 129 "4.y"
    {(yyval.no) = makenode("*",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1807 "y.tab.c"
    break;

  case 74:
#line 130 "4.y"
    {(yyval.no) = makenode("/",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1813 "y.tab.c"
    break;

  case 75:
#line 131 "4.y"
    {(yyval.no) = makenode("%",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1819 "y.tab.c"
    break;

  case 76:
#line 132 "4.y"
    {(yyval.no) = makenode("@",4,0,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1825 "y.tab.c"
    break;

  case 77:
#line 133 "4.y"
    {(yyval.no) = makenode("<",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1831 "y.tab.c"
    break;

  case 78:
#line 134 "4.y"
    {(yyval.no) = makenode(">",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1837 "y.tab.c"
    break;

  case 79:
#line 135 "4.y"
    {(yyval.no) = makenode("<=",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1843 "y.tab.c"
    break;

  case 80:
#line 136 "4.y"
    {(yyval.no) = makenode(">=",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1849 "y.tab.c"
    break;

  case 81:
#line 137 "4.y"
    {(yyval.no) = makenode("!=",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1855 "y.tab.c"
    break;

  case 82:
#line 138 "4.y"
    {(yyval.no) = makenode("==",4,1,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1861 "y.tab.c"
    break;

  case 83:
#line 139 "4.y"
    {(yyval.no) = (yyvsp[0].no);}
#line 1867 "y.tab.c"
    break;

  case 84:
#line 140 "4.y"
    {(yyval.no) = (yyvsp[0].no);}
#line 1873 "y.tab.c"
    break;


#line 1877 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 143 "4.y"


yyerror(char *s)
{
    printf("yyerror %s",s);
}


int main(void) {
	extern FILE *yyin;
  	yyin = fopen("Input", "r");
	yyparse();	
	return 0;
}
