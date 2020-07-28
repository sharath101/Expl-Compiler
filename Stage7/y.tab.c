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
#line 1 "expl.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "expl.h"
	#include "expl.c"
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
    LDECL = 291,
    LENDDECL = 292,
    GIDec = 293,
    MAIN = 294,
    RET = 295,
    PID = 296,
    LIDec = 297,
    IdList = 298,
    GDeclBlock = 299,
    FID = 300,
    GDECL = 301,
    GENDDECL = 302,
    TID = 303,
    TYPE = 304,
    ENDTYPE = 305,
    Tname = 306,
    TIDec = 307,
    FDID = 308,
    Null = 309,
    initialize = 310,
    alloc = 311,
    FREE = 312,
    CLASS = 313,
    ENDCLASS = 314,
    CID = 315,
    MIDec = 316,
    SELF = 317,
    CFID = 318,
    NEW = 319
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
#define LDECL 291
#define LENDDECL 292
#define GIDec 293
#define MAIN 294
#define RET 295
#define PID 296
#define LIDec 297
#define IdList 298
#define GDeclBlock 299
#define FID 300
#define GDECL 301
#define GENDDECL 302
#define TID 303
#define TYPE 304
#define ENDTYPE 305
#define Tname 306
#define TIDec 307
#define FDID 308
#define Null 309
#define initialize 310
#define alloc 311
#define FREE 312
#define CLASS 313
#define ENDCLASS 314
#define CID 315
#define MIDec 316
#define SELF 317
#define CFID 318
#define NEW 319

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "expl.y"

	struct tnode *no;
	struct Paramstruct *pr;
	struct Gsymbol *gs;
	struct Lsymbol *ls;
	struct Typetable *ts;
	struct Fieldlist *fs;
	struct Classtable *cs;

#line 260 "y.tab.c"

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
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   804

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  164
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  335

#define YYUNDEFTOK  2
#define YYMAXUTOK   319

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
      69,    70,     2,     2,    71,     2,    72,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    68,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    73,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,     2,    67,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    44,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    57,    60,    61,    64,    76,    77,
      80,    84,    86,    87,    89,   107,   109,   110,   112,   114,
     115,   117,   118,   134,   135,   137,   137,   139,   141,   141,
     143,   144,   145,   149,   149,   151,   223,   280,   326,   374,
     423,   463,   464,   467,   469,   470,   472,   472,   474,   476,
     476,   478,   479,   480,   485,   486,   489,   490,   492,   492,
     492,   493,   493,   493,   494,   495,   497,   499,   500,   502,
     503,   504,   508,   510,   511,   513,   514,   516,   518,   519,
     520,   521,   522,   523,   525,   526,   527,   531,   532,   533,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   587,
     588,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603
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
  "IDec", "Varlist", "LDECL", "LENDDECL", "GIDec", "MAIN", "RET", "PID",
  "LIDec", "IdList", "GDeclBlock", "FID", "GDECL", "GENDDECL", "TID",
  "TYPE", "ENDTYPE", "Tname", "TIDec", "FDID", "Null", "initialize",
  "alloc", "FREE", "CLASS", "ENDCLASS", "CID", "MIDec", "SELF", "CFID",
  "NEW", "'['", "'{'", "'}'", "';'", "'('", "')'", "','", "'.'", "']'",
  "$accept", "Program", "TypeDefBlock", "TypeDefList", "TypeDef",
  "FieldDeclList", "FieldDecl", "ClassDefBlock", "ClassDefList",
  "Classdef", "Cname", "Fieldlists", "Fld", "MethodDecl", "MDecl",
  "GdeclBlock", "GdeclList", "GDecl", "GidList", "Gid", "FdefBlock",
  "Fdef", "MainBlock", "ParamList", "Param", "LdeclBlock", "LDecList",
  "LDecl", "LidList", "Type", "Body", "Slist", "stmt", "input", "output",
  "asgn", "Free", "retstmt", "ifstmt", "whilestmt", "ArgList", "var",
  "expr", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,    91,   123,   125,    59,    40,
      41,    44,    46,    93
};
# endif

#define YYPACT_NINF -280

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-280)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     215,  -280,  -280,    19,  -280,   -28,   -20,    42,   278,   109,
     260,  -280,     5,  -280,   218,  -280,    26,    62,   -37,  -280,
    -280,   153,  -280,    79,  -280,   109,   260,  -280,   260,  -280,
     260,  -280,  -280,   135,    -7,  -280,  -280,    39,    -8,  -280,
     260,  -280,  -280,  -280,  -280,   112,   260,  -280,   260,  -280,
     260,  -280,  -280,  -280,    85,    89,     6,  -280,    26,   -17,
    -280,   123,   260,   260,  -280,  -280,  -280,   140,   115,  -280,
     152,  -280,   157,  -280,  -280,  -280,   126,   260,  -280,   164,
    -280,   139,   210,    20,  -280,   260,  -280,  -280,  -280,   390,
    -280,   185,   181,    20,   141,   668,   393,   240,   193,  -280,
     260,  -280,   201,   235,  -280,   240,   200,    20,  -280,   206,
     216,   231,   243,   241,   257,   405,   259,   263,  -280,   668,
    -280,   285,   294,   308,   309,   373,   325,   326,     7,  -280,
     410,  -280,   361,   345,  -280,   134,   391,   337,   154,   367,
    -280,   240,   370,    48,   405,   405,   405,  -280,  -280,  -280,
    -280,   375,   376,   405,   339,   642,    48,   444,  -280,   440,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,   377,   405,   457,
    -280,  -280,  -280,    75,  -280,  -280,   395,   236,  -280,   398,
    -280,   359,   363,   546,   389,   570,   594,    44,   459,   618,
     405,   405,   405,   405,   405,   405,   397,   416,   405,   405,
     405,   405,  -280,   464,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,  -280,   380,  -280,  -280,
    -280,   389,   767,   229,     1,  -280,  -280,   429,  -280,   408,
    -280,  -280,  -280,  -280,   467,   465,  -280,   273,   262,   474,
     419,  -280,   169,   342,   169,   342,    -4,    49,    -4,    49,
     111,   473,   127,  -280,  -280,   155,   527,  -280,   155,   527,
     155,   527,   155,   527,   155,   527,   155,   527,   422,   169,
     342,   169,   342,    -4,    49,    -4,    49,   111,   473,   127,
    -280,   155,   527,   155,   527,   155,   527,   155,   527,   155,
     527,   155,   527,  -280,  -280,  -280,  -280,  -280,   741,   741,
    -280,   405,  -280,   405,  -280,   405,   146,   214,   660,   688,
     389,   767,   389,   767,   389,   767,  -280,   286,   289,   498,
    -280,   304,   313,   522,   741,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,   722,  -280
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    61,    62,     0,    63,     0,     0,     0,     0,     0,
       0,    13,     0,    34,     0,    36,     0,     0,     0,    16,
      25,     0,    23,     0,     1,     0,     0,     7,     0,    10,
       0,    44,    12,     0,     0,    33,    35,    40,     0,    39,
       0,    14,    15,    21,    22,     0,     0,     5,     0,     6,
       0,     9,    43,    11,     0,     0,     0,    37,     0,     0,
      19,     0,     0,     0,     3,     4,     8,     0,     0,    42,
       0,    52,     0,    38,    17,    18,     0,     0,    27,     0,
       2,     0,     0,     0,    41,     0,    53,    20,    26,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,    29,     0,     0,    28,     0,     0,     0,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,     0,
      67,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,    57,     0,     0,    50,     0,     0,     0,     0,     0,
      48,     0,     0,     0,     0,     0,     0,    74,    75,   163,
     164,    94,     0,     0,     0,     0,     0,     0,    66,     0,
      68,    69,    70,    71,    65,    72,    73,     0,     0,     0,
      54,    56,    60,     0,    49,    24,     0,     0,    46,     0,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,    97,    64,
      81,    80,    79,     0,     0,    96,    58,     0,    32,     0,
      45,    76,    78,    77,     0,     0,   151,     0,     0,     0,
      97,   112,   137,   113,   138,   114,   139,   115,   140,   116,
     141,   117,   142,   118,   150,   148,   124,   149,   147,   123,
     144,   120,   146,   122,   143,   119,   145,   121,    96,   125,
     100,   126,   101,   127,   102,   128,   103,   129,   104,   130,
     105,   136,   111,   135,   110,   132,   107,   134,   109,   131,
     106,   133,   108,    82,    98,    99,    59,    31,     0,     0,
     152,     0,   153,     0,   154,     0,     0,     0,     0,     0,
      92,    93,    88,    90,    89,    91,   160,     0,     0,     0,
     156,     0,     0,     0,     0,    86,    87,   159,   161,   162,
     155,   157,   158,     0,    85
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -280,  -280,  -280,  -280,   476,  -280,   433,   488,  -280,   490,
    -280,  -280,   432,  -280,   423,   234,  -280,   499,  -280,   458,
     -25,   -26,   447,   -65,   430,   -52,  -280,   387,  -280,   144,
      63,  -279,  -119,  -280,  -280,  -280,  -280,   399,  -280,  -280,
      24,  -110,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,    18,    19,    59,    60,     9,    21,    22,
      23,    77,    78,    89,    90,    10,    14,    15,    38,    39,
      30,    31,    11,    70,    71,    97,   130,   131,   173,    33,
      98,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     237,   128,   155
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     158,    48,    82,    50,    52,   154,   194,   204,   205,   206,
     207,   208,   195,    41,    17,     1,     2,   209,   167,   308,
     309,    63,    52,    17,    52,   210,   211,   212,   213,   214,
     215,     4,    95,   181,   182,   184,   184,    52,     1,     2,
      20,   105,    24,   184,    34,   333,   217,   149,   150,   151,
      74,     1,     2,   108,     4,   141,    96,   221,   223,   208,
      57,   168,    55,    58,    37,   209,    13,     4,   203,   183,
     185,   186,   168,   177,   295,   135,    69,   238,   189,   169,
     242,   244,   246,   248,   250,   252,   255,   258,   260,   262,
     264,   266,   222,   224,   269,   271,   273,   275,   277,   279,
     281,   283,   285,   287,   289,   291,   152,   118,    56,    52,
     117,   118,   239,   153,   236,   243,   245,   247,   249,   251,
     253,   256,   259,   261,   263,   265,   267,   195,    40,   270,
     272,   274,   276,   278,   280,   282,   284,   286,   288,   290,
     292,     1,     2,   226,    12,    45,   227,    16,    62,   149,
     150,   151,    12,    12,    67,     3,   106,     4,    16,    68,
     133,   190,   191,   192,   193,   194,     1,     2,   139,    12,
     142,   195,     1,     2,    34,    76,   168,   192,   193,   194,
      54,    83,     4,   203,    61,   195,     1,     2,     4,   158,
     158,   310,   168,   312,    87,   314,   318,   322,    86,   203,
      72,   175,     4,    61,   179,    93,    79,   107,   152,   118,
      81,    72,    43,    20,   158,   153,   316,   149,   150,   151,
     168,    91,    84,    85,   176,    92,   311,   203,   313,    72,
     315,   319,   323,   102,   168,   190,   191,   192,   193,   194,
     132,   203,    26,    28,   136,   195,   103,     1,     2,   104,
       1,     2,    95,   196,   197,   198,   199,   200,   201,    46,
     134,     3,   137,     4,     5,    35,     4,   140,   190,   191,
     192,   193,   194,     6,   132,   143,   152,   118,   195,   136,
      94,    85,    72,   153,   320,   144,   196,   197,   198,   199,
     200,   201,     1,     2,   168,   190,   191,   192,   193,   194,
     145,   203,   294,   104,   138,   195,   229,    85,     4,   147,
       1,     2,   146,   196,   197,   198,   199,   200,   201,   190,
     191,   192,   193,   194,     3,   148,     4,   168,   156,   195,
     317,   321,   302,   303,   203,   157,     6,   196,   197,   198,
     199,   200,   201,   300,   301,   190,   191,   192,   193,   194,
     206,   207,   208,   160,   168,   195,   327,   301,   209,   328,
     303,   203,   161,   196,   197,   198,   199,   200,   201,   190,
     191,   192,   193,   194,   330,   301,   162,   163,   168,   195,
     149,   150,   151,   331,   303,   203,   164,   196,   197,   198,
     199,   200,   201,   165,   166,   190,   191,   192,   193,   194,
     149,   150,   151,   172,   168,   195,   138,   202,   149,   150,
     151,   203,   174,   196,   197,   198,   199,   200,   201,   149,
     150,   151,     1,     2,   168,     1,     2,   100,   168,   231,
     129,   169,   220,   232,   178,   203,    54,   180,     4,   152,
     118,     4,     1,     2,   187,   168,   153,   170,   188,   218,
     293,   254,   169,   219,   168,    27,    29,    32,     4,   152,
     118,   203,   225,   228,   240,   230,   153,   152,   118,   268,
     257,   296,    47,    49,   153,    51,   297,    53,   152,   118,
     204,   205,   206,   207,   208,   153,   298,   299,   306,   209,
     209,   307,    75,    64,    42,    65,    25,    66,   210,   211,
     212,   213,   214,   215,   204,   205,   206,   207,   208,    88,
      80,    44,   101,    36,   209,    99,    73,   171,   159,     0,
       0,     0,   210,   211,   212,   213,   214,   215,   204,   205,
     206,   207,   208,   204,   205,   206,   207,   208,   209,     0,
       0,     0,     0,   209,   304,   305,   210,   211,   212,   213,
     214,   215,   204,   205,   206,   207,   208,     0,     0,     0,
       0,     0,   209,     0,     0,     0,     0,     0,   329,   305,
     210,   211,   212,   213,   214,   215,   204,   205,   206,   207,
     208,     0,     0,     0,     0,     0,   209,     0,     0,     0,
       0,     0,   332,   305,   210,   211,   212,   213,   214,   215,
     204,   205,   206,   207,   208,     0,     0,     0,     0,     0,
     209,     0,     0,     0,     0,     0,   233,     0,   210,   211,
     212,   213,   214,   215,   204,   205,   206,   207,   208,     0,
       0,     0,     0,     0,   209,     0,     0,     0,     0,     0,
     234,     0,   210,   211,   212,   213,   214,   215,   204,   205,
     206,   207,   208,     0,     0,     0,     0,     0,   209,     0,
       0,     0,     0,     0,   235,   108,   210,   211,   212,   213,
     214,   215,     0,   108,   109,   110,     0,   111,   324,     0,
     325,   112,   109,   110,     0,   111,     0,     0,   241,   112,
     113,   114,     0,   108,     0,     0,     0,     0,   113,   114,
       0,     0,   109,   110,     0,   111,     0,     0,   115,   112,
     216,   326,     0,     0,     0,     0,     0,   116,   113,   114,
       0,     0,   117,   118,     0,   116,     0,   108,     0,     0,
     117,   118,     0,     0,     0,     0,   109,   110,     0,   111,
       0,     0,   334,   112,     0,   116,   108,     0,     0,     0,
     117,   118,   113,   114,     0,   109,   110,     0,   111,     0,
       0,     0,   112,     0,     0,     0,     0,     0,     0,     0,
       0,   113,   114,   204,   205,   206,   207,   208,     0,   116,
       0,     0,     0,   209,   117,   118,     0,     0,     0,     0,
       0,   210,   211,   212,   213,   214,   215,     0,   116,     0,
       0,     0,     0,   117,   118
};

static const yytype_int16 yycheck[] =
{
     119,    26,    67,    28,    30,   115,    10,     6,     7,     8,
       9,    10,    16,    50,    51,    32,    33,    16,    11,   298,
     299,    46,    48,    51,    50,    24,    25,    26,    27,    28,
      29,    48,    12,   143,   144,   145,   146,    63,    32,    33,
      60,    93,     0,   153,    39,   324,   156,     3,     4,     5,
      67,    32,    33,     5,    48,   107,    36,   167,   168,    10,
      68,    65,    69,    71,    38,    16,    47,    48,    72,   144,
     145,   146,    65,   138,    73,   100,    70,   187,   153,    72,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   167,   168,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,    62,    63,    69,   135,
      62,    63,   187,    69,    70,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    16,    66,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,    32,    33,    68,     0,    66,    71,     3,    36,     3,
       4,     5,     8,     9,    69,    46,    93,    48,    14,    70,
      97,     6,     7,     8,     9,    10,    32,    33,   105,    25,
     107,    16,    32,    33,    39,    52,    65,     8,     9,    10,
      45,    66,    48,    72,    40,    16,    32,    33,    48,   308,
     309,   301,    65,   303,    68,   305,   306,   307,    41,    72,
      56,    67,    48,    59,   141,    66,    62,    66,    62,    63,
      70,    67,    59,    60,   333,    69,    70,     3,     4,     5,
      65,    77,    70,    71,    70,    61,   301,    72,   303,    85,
     305,   306,   307,    89,    65,     6,     7,     8,     9,    10,
      96,    72,     8,     9,   100,    16,    61,    32,    33,    68,
      32,    33,    12,    24,    25,    26,    27,    28,    29,    25,
      67,    46,    61,    48,    49,    47,    48,    67,     6,     7,
       8,     9,    10,    58,   130,    69,    62,    63,    16,   135,
      70,    71,   138,    69,    70,    69,    24,    25,    26,    27,
      28,    29,    32,    33,    65,     6,     7,     8,     9,    10,
      69,    72,    73,    68,    69,    16,    70,    71,    48,    68,
      32,    33,    69,    24,    25,    26,    27,    28,    29,     6,
       7,     8,     9,    10,    46,    68,    48,    65,    69,    16,
     306,   307,    70,    71,    72,    72,    58,    24,    25,    26,
      27,    28,    29,    70,    71,     6,     7,     8,     9,    10,
       8,     9,    10,    68,    65,    16,    70,    71,    16,    70,
      71,    72,    68,    24,    25,    26,    27,    28,    29,     6,
       7,     8,     9,    10,    70,    71,    68,    68,    65,    16,
       3,     4,     5,    70,    71,    72,    13,    24,    25,    26,
      27,    28,    29,    68,    68,     6,     7,     8,     9,    10,
       3,     4,     5,    42,    65,    16,    69,    68,     3,     4,
       5,    72,    67,    24,    25,    26,    27,    28,    29,     3,
       4,     5,    32,    33,    65,    32,    33,    37,    65,    70,
      37,    72,    55,    70,    67,    72,    45,    67,    48,    62,
      63,    48,    32,    33,    69,    65,    69,    37,    72,     5,
      70,    54,    72,    13,    65,     8,     9,    10,    48,    62,
      63,    72,     5,    68,     5,    67,    69,    62,    63,     5,
      54,    42,    25,    26,    69,    28,    68,    30,    62,    63,
       6,     7,     8,     9,    10,    69,    19,    22,    69,    16,
      16,    69,    59,    46,    18,    48,     8,    50,    24,    25,
      26,    27,    28,    29,     6,     7,     8,     9,    10,    77,
      63,    21,    89,    14,    16,    85,    58,   130,   119,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    29,     6,     7,
       8,     9,    10,     6,     7,     8,     9,    10,    16,    -1,
      -1,    -1,    -1,    16,    70,    71,    24,    25,    26,    27,
      28,    29,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    70,    71,
      24,    25,    26,    27,    28,    29,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    70,    71,    24,    25,    26,    27,    28,    29,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    70,    -1,    24,    25,
      26,    27,    28,    29,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    24,    25,    26,    27,    28,    29,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    70,     5,    24,    25,    26,    27,
      28,    29,    -1,     5,    14,    15,    -1,    17,    18,    -1,
      20,    21,    14,    15,    -1,    17,    -1,    -1,    70,    21,
      30,    31,    -1,     5,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    14,    15,    -1,    17,    -1,    -1,    40,    21,
      68,    23,    -1,    -1,    -1,    -1,    -1,    57,    30,    31,
      -1,    -1,    62,    63,    -1,    57,    -1,     5,    -1,    -1,
      62,    63,    -1,    -1,    -1,    -1,    14,    15,    -1,    17,
      -1,    -1,    20,    21,    -1,    57,     5,    -1,    -1,    -1,
      62,    63,    30,    31,    -1,    14,    15,    -1,    17,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,     6,     7,     8,     9,    10,    -1,    57,
      -1,    -1,    -1,    16,    62,    63,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,    -1,    57,    -1,
      -1,    -1,    -1,    62,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    33,    46,    48,    49,    58,    75,    76,    81,
      89,    96,   103,    47,    90,    91,   103,    51,    77,    78,
      60,    82,    83,    84,     0,    81,    89,    96,    89,    96,
      94,    95,    96,   103,    39,    47,    91,    38,    92,    93,
      66,    50,    78,    59,    83,    66,    89,    96,    94,    96,
      94,    96,    95,    96,    45,    69,    69,    68,    71,    79,
      80,   103,    36,    94,    96,    96,    96,    69,    70,    70,
      97,    98,   103,    93,    67,    80,    52,    85,    86,   103,
      96,    70,    97,    66,    70,    71,    41,    68,    86,    87,
      88,   103,    61,    66,    70,    12,    36,    99,   104,    98,
      37,    88,   103,    61,    68,    99,   104,    66,     5,    14,
      15,    17,    21,    30,    31,    40,    57,    62,    63,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   115,    37,
     100,   101,   103,   104,    67,    94,   103,    61,    69,   104,
      67,    99,   104,    69,    69,    69,    69,    68,    68,     3,
       4,     5,    62,    69,   115,   116,    69,    72,   106,   111,
      68,    68,    68,    68,    13,    68,    68,    11,    65,    72,
      37,   101,    42,   102,    67,    67,    70,    97,    67,   104,
      67,   115,   115,   116,   115,   116,   116,    69,    72,   116,
       6,     7,     8,     9,    10,    16,    24,    25,    26,    27,
      28,    29,    68,    72,     6,     7,     8,     9,    10,    16,
      24,    25,    26,    27,    28,    29,    68,   115,     5,    13,
      55,   115,   116,   115,   116,     5,    68,    71,    68,    70,
      67,    70,    70,    70,    70,    70,    70,   114,   115,   116,
       5,    70,   115,   116,   115,   116,   115,   116,   115,   116,
     115,   116,   115,   116,    54,   115,   116,    54,   115,   116,
     115,   116,   115,   116,   115,   116,   115,   116,     5,   115,
     116,   115,   116,   115,   116,   115,   116,   115,   116,   115,
     116,   115,   116,   115,   116,   115,   116,   115,   116,   115,
     116,   115,   116,    70,    73,    73,    42,    68,    19,    22,
      70,    71,    70,    71,    70,    71,    69,    69,   105,   105,
     115,   116,   115,   116,   115,   116,    70,   114,   115,   116,
      70,   114,   115,   116,    18,    20,    23,    70,    70,    70,
      70,    70,    70,   105,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    76,    77,    77,    78,    79,    79,
      80,    81,    82,    82,    83,    84,    85,    85,    86,    87,
      87,    88,    88,    89,    89,    90,    90,    91,    92,    92,
      93,    93,    93,    94,    94,    95,    95,    95,    95,    96,
      96,    97,    97,    98,    99,    99,   100,   100,   101,   102,
     102,   103,   103,   103,   104,   104,   105,   105,   106,   106,
     106,   106,   106,   106,   106,   106,   107,   108,   108,   109,
     109,   109,   110,   111,   111,   112,   112,   113,   114,   114,
     114,   114,   114,   114,   115,   115,   115,   115,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     3,     3,     2,     4,     3,
       2,     3,     2,     1,     3,     2,     1,     4,     2,     1,
       3,     3,     2,     1,     8,     1,     2,     1,     3,     2,
       1,     6,     5,     3,     2,     2,     1,     3,     3,     1,
       1,     4,     3,     2,     1,     9,     8,     8,     7,     8,
       7,     3,     1,     2,     3,     2,     2,     1,     3,     3,
       1,     1,     1,     1,     4,     3,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     4,     4,     4,     3,
       3,     3,     4,     3,     3,     9,     7,     7,     3,     3,
       3,     3,     3,     3,     1,     1,     3,     3,     4,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     4,     4,     6,     5,     6,     6,     6,
       5,     6,     6,     1,     1
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
#line 44 "expl.y"
    {printf("Program done\n");}
#line 1684 "y.tab.c"
    break;

  case 3:
#line 45 "expl.y"
    {printf("Program done\n");}
#line 1690 "y.tab.c"
    break;

  case 4:
#line 46 "expl.y"
    {printf("Program done\n");}
#line 1696 "y.tab.c"
    break;

  case 5:
#line 47 "expl.y"
    {printf("Program done\n");}
#line 1702 "y.tab.c"
    break;

  case 6:
#line 48 "expl.y"
    {printf("Program done\n");}
#line 1708 "y.tab.c"
    break;

  case 7:
#line 49 "expl.y"
    {printf("Program done\n");}
#line 1714 "y.tab.c"
    break;

  case 8:
#line 50 "expl.y"
    {printf("Program done\n");}
#line 1720 "y.tab.c"
    break;

  case 9:
#line 51 "expl.y"
    {printf("Program done\n");}
#line 1726 "y.tab.c"
    break;

  case 10:
#line 52 "expl.y"
    {printf("Program done\n");}
#line 1732 "y.tab.c"
    break;

  case 11:
#line 53 "expl.y"
    {printf("Program done\n");}
#line 1738 "y.tab.c"
    break;

  case 12:
#line 54 "expl.y"
    {printf("Program done\n");}
#line 1744 "y.tab.c"
    break;

  case 13:
#line 55 "expl.y"
    {printf("Program done\n");}
#line 1750 "y.tab.c"
    break;

  case 14:
#line 57 "expl.y"
    {(yyval.no)=(yyvsp[-2].no);tdisplay();printf("--------------------Typedec done--------------------\n");}
#line 1756 "y.tab.c"
    break;

  case 17:
#line 64 "expl.y"
    { 
													int size=GetSize((yyvsp[-1].fs));
													printf("%s: ",(yyvsp[-3].ts)->name);
													fdisplay(froot);
													(yyvsp[-3].ts)->size=size;
													(yyvsp[-3].ts)->fields=froot;
													(yyval.ts)=(yyvsp[-3].ts);
													froot=NULL;
													fieldpos=1;
												}
#line 1771 "y.tab.c"
    break;

  case 20:
#line 80 "expl.y"
    {(yyval.fs)= newfield((yyvsp[-1].no)->varname,(yyvsp[-2].ts));}
#line 1777 "y.tab.c"
    break;

  case 24:
#line 90 "expl.y"
    {
												if(fnum>8){
													printf("Class field limit exceeded\n");
													exit(1);
												}
												cfdisplay(cfroot);
												mdisplay(mroot);
												(yyval.cs)=Appendclass((yyvsp[-7].cs)->name,cfroot,mroot,cnum,fnum,mnum);
												cnum++;
												fnum=0;
												mnum=0;
												cfroot=NULL;
												mroot=NULL;
												currclass=NULL;
												printf("-------------------------------Class %s done----------------------------\n",(yyvsp[-7].cs)->name);
											}
#line 1798 "y.tab.c"
    break;

  case 25:
#line 107 "expl.y"
    {Cptr = newclass((yyvsp[0].ts)->name,NULL); currclass=Cptr; (yyval.cs)=Cptr;classnum++;}
#line 1804 "y.tab.c"
    break;

  case 28:
#line 112 "expl.y"
    {newcfield(Cptr,(yyvsp[-2].ts),(yyvsp[-1].no)->varname);}
#line 1810 "y.tab.c"
    break;

  case 31:
#line 117 "expl.y"
    {newcmethod(Cptr,(yyvsp[-4].no)->varname,(yyvsp[-5].ts),(yyvsp[-2].pr));lroot=NULL;}
#line 1816 "y.tab.c"
    break;

  case 32:
#line 118 "expl.y"
    {newcmethod(Cptr,(yyvsp[-3].no)->varname,(yyvsp[-4].ts),NULL);lroot=NULL;}
#line 1822 "y.tab.c"
    break;

  case 33:
#line 134 "expl.y"
    {gdisplay();printf("--------------------Global done--------------------\n");(yyval.no)=(yyvsp[-2].no);}
#line 1828 "y.tab.c"
    break;

  case 37:
#line 139 "expl.y"
    {(yyval.gs)=(yyvsp[-1].gs);}
#line 1834 "y.tab.c"
    break;

  case 41:
#line 144 "expl.y"
    {(yyval.gs)= Appendgparam((yyvsp[-3].gs),(yyvsp[-1].pr));}
#line 1840 "y.tab.c"
    break;

  case 42:
#line 145 "expl.y"
    {(yyval.gs)= Appendgparam((yyvsp[-2].gs),NULL);}
#line 1846 "y.tab.c"
    break;

  case 45:
#line 152 "expl.y"
    {	
											struct Paramstruct *p;
											printf("Function name: %s\n",(yyvsp[-7].no)->text);
											if(currclass!=NULL){
												p=getmethodparam(currclass,(yyvsp[-7].no)->text);
												tLookup(currclass->name)->fields=cfroot;
											}
											else
												p=getparam((yyvsp[-7].no)->text);
											if(!checkparamlist((yyvsp[-5].pr),p)){
												printf("Function parameters don't match with the declaration\n");
												exit(1);
											}
											(yyvsp[-1].no)->Lentry=lroot;
											proot=(yyvsp[-5].pr);
											fname=(char*)malloc(sizeof(char));
											strcpy(fname,(yyvsp[-7].no)->text);
											strcpy((yyvsp[-1].no)->varname,(yyvsp[-7].no)->text);
											(yyvsp[-1].no)->right->Lentry=lroot;
											ldisplay();
											lroot=NULL;
											(yyval.no)=(yyvsp[-1].no);
											printf("Codegen start\n");
											FILE *fptr = fopen("target.xsm", "a");
											if(beginflag==1){
												fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
												fprintf(fptr, "JMP MAIN\n");pos++;
												beginflag=0;
											}
											int f;
											if(currclass!=NULL)
												f=cmlookup(currclass,(yyvsp[-7].no)->text)->flabel;
											else
												f=getflabel((yyvsp[-7].no)->text);
											fprintf(fptr,"F%d:\n",f);
											func[f]=2*pos+2056;
											fprintf(fptr, "PUSH BP\n");pos++;
											fprintf(fptr, "MOV BP, SP\n");pos++;
											struct Lsymbol *l=(yyvsp[-1].no)->Lentry;
											struct Paramstruct *par=(yyvsp[-5].pr);
											int y=getreg();
											if(par==NULL || l==NULL){
												printf("Parameterlist is NULL\n");
												exit(1);
											}
											else if(par!=NULL && l!=NULL){
												while(p->next!=NULL){
													p=p->next;
													l=l->next;
												}
												if(l->next==NULL){
													printf("Nothing in local declaration block\n");
													exit(1);
												}
												else
													l=l->next;
												while(l->next!=NULL){
													fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++; 
													l=l->next;
												}
												fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++;
											}
											freereg();
											selflab=setlocalbinding((yyvsp[-5].pr),(yyvsp[-1].no)->Lentry);
											codegen((yyvsp[-1].no),fptr);
											fclose(fptr);
											k=-1;
											lvar=0;
											selflab=0;
											printf("-------------------function %s done------------------\n",(yyvsp[-7].no)->text);
										}
#line 1922 "y.tab.c"
    break;

  case 46:
#line 224 "expl.y"
    {
											struct Paramstruct *p;
											printf("Function name: %s\n",(yyvsp[-6].no)->text);
											if(currclass!=NULL){
												p=getmethodparam(currclass,(yyvsp[-6].no)->text);
												tLookup(currclass->name)->fields=cfroot;
											}
											else
												p=getparam((yyvsp[-6].no)->text);
											if(p!=NULL){
												printf("Function parameters don't match with the declaration\n");
												exit(1);
											}
											(yyvsp[-1].no)->Lentry=lroot;
											proot=NULL;
											fname=(char*)malloc(sizeof(char));
											strcpy(fname,(yyvsp[-6].no)->text);
											strcpy((yyvsp[-1].no)->varname,(yyvsp[-6].no)->text);
											(yyvsp[-1].no)->right->Lentry=lroot;
											ldisplay();
											lroot=NULL;
											(yyval.no)=(yyvsp[-1].no);
											printf("Codegen start\n");
											FILE *fptr = fopen("target.xsm", "a");
											if(beginflag==1){
												fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
												fprintf(fptr, "JMP MAIN\n");pos++;
												beginflag=0;
											}
											int f;
											if(currclass!=NULL)
												f=cmlookup(currclass,(yyvsp[-6].no)->text)->flabel;
											else
												f=getflabel((yyvsp[-6].no)->text);
											fprintf(fptr,"F%d:\n",f);
											func[f]=2*pos+2056;
											fprintf(fptr, "PUSH BP\n");pos++;
											fprintf(fptr, "MOV BP, SP\n");pos++;
											if((yyvsp[-1].no)->Lentry!=NULL){
												struct Lsymbol *l=(yyvsp[-1].no)->Lentry;
												int y=getreg();
												while(l->next!=NULL){
													fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++; //empty space
													l=l->next;
												}
												fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++; 
												freereg();
											}
											selflab=setlocalbinding(NULL,(yyvsp[-1].no)->Lentry);
											codegen((yyvsp[-1].no),fptr);
											fclose(fptr);
											k=-1;
											lvar=0;
											selflab=0;
											printf("-------------------function %s done------------------\n",(yyvsp[-6].no)->text);
										}
#line 1983 "y.tab.c"
    break;

  case 47:
#line 281 "expl.y"
    {
											struct Paramstruct *p;
											printf("Function name: %s\n",(yyvsp[-6].no)->text);
											if(currclass!=NULL){
												p=getmethodparam(currclass,(yyvsp[-6].no)->text);
												tLookup(currclass->name)->fields=cfroot;
											}
											else
												p=getparam((yyvsp[-6].no)->text);
											if(!checkparamlist((yyvsp[-4].pr),p)){
												printf("Function parameters don't match with the declaration\n");
												exit(1);
											}
											(yyvsp[-1].no)->Lentry=lroot;
											proot=(yyvsp[-4].pr);
											fname=(char*)malloc(sizeof(char));
											strcpy(fname,(yyvsp[-6].no)->text);
											strcpy((yyvsp[-1].no)->varname,(yyvsp[-6].no)->text);
											(yyvsp[-1].no)->right->Lentry=lroot;
											ldisplay();
											lroot=NULL;
											(yyval.no)=(yyvsp[-1].no);
											printf("Codegen start\n");
											FILE *fptr = fopen("target.xsm", "a");
											if(beginflag==1){
												fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
												fprintf(fptr, "JMP MAIN\n");pos++;
												beginflag=0;
											}
											int f;
											if(currclass!=NULL)
												f=cmlookup(currclass,(yyvsp[-6].no)->text)->flabel;
											else
												f=getflabel((yyvsp[-6].no)->text);
											fprintf(fptr,"F%d:\n",f);
											func[f]=2*pos+2056;
											fprintf(fptr, "PUSH BP\n");pos++;
											fprintf(fptr, "MOV BP, SP\n");pos++;
											selflab=setlocalbinding((yyvsp[-4].pr),(yyvsp[-1].no)->Lentry);
											codegen((yyvsp[-1].no),fptr);
											fclose(fptr);
											k=-1;
											selflab=0;
											printf("-------------------function %s done------------------\n",(yyvsp[-6].no)->text);
										}
#line 2033 "y.tab.c"
    break;

  case 48:
#line 327 "expl.y"
    {
											struct Paramstruct *p;
											printf("Function name: %s\n",(yyvsp[-5].no)->text);
											if(currclass!=NULL){
												p=getmethodparam(currclass,(yyvsp[-5].no)->text);
												tLookup(currclass->name)->fields=cfroot;
											}
											else
												p=getparam((yyvsp[-5].no)->text);
											if(p!=NULL){
												printf("Function parameters don't match with the declaration\n");
												exit(1);
											}
											(yyvsp[-1].no)->Lentry=NULL;
											proot=NULL;
											fname=(char*)malloc(sizeof(char));
											strcpy(fname,(yyvsp[-5].no)->text);
											strcpy((yyvsp[-1].no)->varname,(yyvsp[-5].no)->text);
											(yyvsp[-1].no)->right->Lentry=lroot;
											ldisplay();
											lroot=NULL;
											(yyval.no)=(yyvsp[-1].no);
											printf("Codegen start\n");
											FILE *fptr = fopen("target.xsm", "a");
											if(beginflag==1){
												fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
												fprintf(fptr, "JMP MAIN\n");pos++;
												beginflag=0;
											}
											int f;
											if(currclass!=NULL)
												f=cmlookup(currclass,(yyvsp[-5].no)->text)->flabel;
											else
												f=getflabel((yyvsp[-5].no)->text);
											fprintf(fptr,"F%d:\n",f);
											func[f]=2*pos+2056;
											fprintf(fptr, "PUSH BP\n");pos++;
											fprintf(fptr, "MOV BP, SP\n");pos++;
											selflab=-3;
											codegen((yyvsp[-1].no),fptr);
											selflab=0;
											fclose(fptr);
											k=-1;
											printf("-------------------function %s done------------------\n",(yyvsp[-5].no)->text);
										}
#line 2083 "y.tab.c"
    break;

  case 49:
#line 375 "expl.y"
    {
                                			 printf("MAIN\n");
                     						 (yyvsp[-1].no)->Lentry=lroot;
                     						 fname=(char*)malloc(sizeof(char));
                     						 strcpy(fname,"main");
                                   			 (yyval.no)=(yyvsp[-1].no);
                                   			 ldisplay();
                                   			 printf("Codegen start\n");
											 FILE *fptr = fopen("target.xsm", "a");
											 if(beginflag==1){
												 fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
												 beginflag=0;
											 }
											 fprintf(fptr,"MAIN:\n");
											 mainl=2*pos+2056;
											 fprintf(fptr, "MOV BP, SP\n");pos++;
											 if((yyvsp[-1].no)->Lentry!=NULL){
											 	struct Lsymbol *l=(yyvsp[-1].no)->Lentry;
											 	int y=getreg();
											 	while(l->next!=NULL){
													 fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++; //empty space
												 	l=l->next;
											 	}
											 	fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++; 
											 	freereg();
											 }
											 setlocalbinding(NULL,(yyvsp[-1].no)->Lentry);
											 codegen((yyvsp[-1].no),fptr);
											 fprintf(fptr, "PASS");pos++;
											 fclose(fptr);
											 k=-1;
											 FILE *fptr2 = fopen("array.c", "w");
											 fprintf(fptr2,"int a[100]={");
											 for(int i=0;i<r;i++){
												 if(i==0)
												 	 fprintf(fptr2,"%d",a[i]);
												 else
													 fprintf(fptr2,",%d",a[i]);
											 }
											 fprintf(fptr2,"};\n");
											 fprintf(fptr2,"int f[100]={0");
											 for(int i=1;i<flabel;i++)
												 fprintf(fptr2,",%d",func[i]);
											 fprintf(fptr2,"};\n");
											 fprintf(fptr2,"int mainl=%d;",mainl);
                                   			 printf("--------------------Main done-----------------------\n");
                                		}
#line 2135 "y.tab.c"
    break;

  case 50:
#line 424 "expl.y"
    {
                                			 printf("MAIN\n");
                     						 (yyvsp[-1].no)->Lentry=lroot;
                     						 fname=(char*)malloc(sizeof(char));
                     						 strcpy(fname,"main");
                                   			 (yyval.no)=(yyvsp[-1].no);
                                   			 ldisplay();
                                   			 printf("Codegen start\n");
											 FILE *fptr = fopen("target.xsm", "a");
											 if(beginflag==1){
												 fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
											 	 beginflag=0;
											 }
											 fprintf(fptr,"MAIN:\n");
											 mainl=2*pos+2056;
											 fprintf(fptr, "MOV BP, SP\n");pos++;
											 codegen((yyvsp[-1].no),fptr);
											 fprintf(fptr, "PASS");pos++;
											 fclose(fptr);
											 k=-1;
											 FILE *fptr2 = fopen("array.c", "w");
											 fprintf(fptr2,"int a[100]={");
											 for(int i=0;i<r;i++){
												 if(i==0)
												 	 fprintf(fptr2,"%d",a[i]);
												 else
													 fprintf(fptr2,",%d",a[i]);
											 }
											 fprintf(fptr2,"};\n");
											 fprintf(fptr2,"int f[100]={0");
											 for(int i=1;i<flabel;i++)
												 fprintf(fptr2,",%d",func[i]);
											 fprintf(fptr2,"};\n");
											 fprintf(fptr2,"int mainl=%d;",mainl);
                                   			 printf("--------------------Main done-----------------------\n");
                                		}
#line 2176 "y.tab.c"
    break;

  case 51:
#line 463 "expl.y"
    {(yyval.pr) = Appendparam((yyvsp[-2].pr),(yyvsp[0].pr));}
#line 2182 "y.tab.c"
    break;

  case 52:
#line 464 "expl.y"
    {(yyval.pr) = (yyvsp[0].pr);}
#line 2188 "y.tab.c"
    break;

  case 53:
#line 467 "expl.y"
    {(yyval.pr)=(yyvsp[0].pr);}
#line 2194 "y.tab.c"
    break;

  case 58:
#line 474 "expl.y"
    {(yyval.ls)=(yyvsp[-1].ls);}
#line 2200 "y.tab.c"
    break;

  case 64:
#line 485 "expl.y"
    {(yyval.no)=makenode("filledlater",12,NULL,NULL,(yyvsp[-2].no),NULL,(yyvsp[-1].no));}
#line 2206 "y.tab.c"
    break;

  case 65:
#line 486 "expl.y"
    {(yyval.no)=makenode("filledlater",12,NULL,NULL,NULL,NULL,(yyvsp[-1].no));printf("Nothing inside body\n");}
#line 2212 "y.tab.c"
    break;

  case 66:
#line 489 "expl.y"
    {(yyval.no) = makenode("connector",3,NULL,NULL,(yyvsp[-1].no),NULL,(yyvsp[0].no));}
#line 2218 "y.tab.c"
    break;

  case 74:
#line 494 "expl.y"
    {(yyval.no)=(yyvsp[-1].no);}
#line 2224 "y.tab.c"
    break;

  case 75:
#line 495 "expl.y"
    {(yyval.no)=(yyvsp[-1].no);}
#line 2230 "y.tab.c"
    break;

  case 76:
#line 497 "expl.y"
    {(yyval.no) = makenode("read",1,NULL,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2236 "y.tab.c"
    break;

  case 77:
#line 499 "expl.y"
    {(yyval.no) = makenode("write",2,NULL,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2242 "y.tab.c"
    break;

  case 78:
#line 500 "expl.y"
    {(yyval.no) = makenode("write",2,NULL,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2248 "y.tab.c"
    break;

  case 79:
#line 502 "expl.y"
    {(yyval.no) = makenode("=",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2254 "y.tab.c"
    break;

  case 80:
#line 503 "expl.y"
    {(yyval.no) = makenode("=",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2260 "y.tab.c"
    break;

  case 81:
#line 504 "expl.y"
    {(yyval.no) = makenode("=",14,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2266 "y.tab.c"
    break;

  case 82:
#line 508 "expl.y"
    {(yyval.no) = makenode("free",14,tint,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2272 "y.tab.c"
    break;

  case 83:
#line 510 "expl.y"
    {(yyval.no) = makenode("return",11,NULL,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2278 "y.tab.c"
    break;

  case 84:
#line 511 "expl.y"
    {(yyval.no) = makenode("return",11,NULL,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2284 "y.tab.c"
    break;

  case 85:
#line 513 "expl.y"
    {(yyval.no)= makenode("ifelse",6,NULL,NULL,(yyvsp[-6].no),(yyvsp[-3].no),(yyvsp[-1].no));}
#line 2290 "y.tab.c"
    break;

  case 86:
#line 514 "expl.y"
    {(yyval.no)= makenode("if",6,NULL,NULL,(yyvsp[-4].no),(yyvsp[-1].no),NULL);}
#line 2296 "y.tab.c"
    break;

  case 87:
#line 516 "expl.y"
    {(yyval.no)= makenode("while",5,NULL,NULL,(yyvsp[-4].no),NULL,(yyvsp[-1].no));}
#line 2302 "y.tab.c"
    break;

  case 88:
#line 518 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2308 "y.tab.c"
    break;

  case 89:
#line 519 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2314 "y.tab.c"
    break;

  case 90:
#line 520 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2320 "y.tab.c"
    break;

  case 91:
#line 521 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2326 "y.tab.c"
    break;

  case 92:
#line 522 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2332 "y.tab.c"
    break;

  case 93:
#line 523 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2338 "y.tab.c"
    break;

  case 96:
#line 527 "expl.y"
    {(yyval.no) = fieldconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2344 "y.tab.c"
    break;

  case 97:
#line 531 "expl.y"
    {(yyval.no) = makenode("self",15,(yyvsp[0].no)->type,NULL,(yyvsp[0].no),NULL,NULL);}
#line 2350 "y.tab.c"
    break;

  case 98:
#line 532 "expl.y"
    {(yyval.no) = makearraynode((yyvsp[-3].no)->varname,(yyvsp[-3].no)->type,(yyvsp[-1].no));}
#line 2356 "y.tab.c"
    break;

  case 99:
#line 533 "expl.y"
    {(yyval.no) = makearraynode((yyvsp[-3].no)->varname,(yyvsp[-3].no)->type,(yyvsp[-1].no));}
#line 2362 "y.tab.c"
    break;

  case 100:
#line 535 "expl.y"
    {(yyval.no) = makenode("+",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2368 "y.tab.c"
    break;

  case 101:
#line 536 "expl.y"
    {(yyval.no) = makenode("-",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2374 "y.tab.c"
    break;

  case 102:
#line 537 "expl.y"
    {(yyval.no) = makenode("*",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2380 "y.tab.c"
    break;

  case 103:
#line 538 "expl.y"
    {(yyval.no) = makenode("/",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2386 "y.tab.c"
    break;

  case 104:
#line 539 "expl.y"
    {(yyval.no) = makenode("%",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2392 "y.tab.c"
    break;

  case 105:
#line 540 "expl.y"
    {(yyval.no) = makenode("@",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2398 "y.tab.c"
    break;

  case 106:
#line 541 "expl.y"
    {(yyval.no) = makenode("<",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2404 "y.tab.c"
    break;

  case 107:
#line 542 "expl.y"
    {(yyval.no) = makenode(">",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2410 "y.tab.c"
    break;

  case 108:
#line 543 "expl.y"
    {(yyval.no) = makenode("<=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2416 "y.tab.c"
    break;

  case 109:
#line 544 "expl.y"
    {(yyval.no) = makenode(">=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2422 "y.tab.c"
    break;

  case 110:
#line 545 "expl.y"
    {(yyval.no) = makenode("!=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2428 "y.tab.c"
    break;

  case 111:
#line 546 "expl.y"
    {(yyval.no) = makenode("==",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2434 "y.tab.c"
    break;

  case 112:
#line 547 "expl.y"
    {(yyval.no) = (yyvsp[-1].no);}
#line 2440 "y.tab.c"
    break;

  case 113:
#line 548 "expl.y"
    {(yyval.no) = makenode("+",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2446 "y.tab.c"
    break;

  case 114:
#line 549 "expl.y"
    {(yyval.no) = makenode("-",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2452 "y.tab.c"
    break;

  case 115:
#line 550 "expl.y"
    {(yyval.no) = makenode("*",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2458 "y.tab.c"
    break;

  case 116:
#line 551 "expl.y"
    {(yyval.no) = makenode("/",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2464 "y.tab.c"
    break;

  case 117:
#line 552 "expl.y"
    {(yyval.no) = makenode("%",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2470 "y.tab.c"
    break;

  case 118:
#line 553 "expl.y"
    {(yyval.no) = makenode("@",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2476 "y.tab.c"
    break;

  case 119:
#line 554 "expl.y"
    {(yyval.no) = makenode("<",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2482 "y.tab.c"
    break;

  case 120:
#line 555 "expl.y"
    {(yyval.no) = makenode(">",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2488 "y.tab.c"
    break;

  case 121:
#line 556 "expl.y"
    {(yyval.no) = makenode("<=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2494 "y.tab.c"
    break;

  case 122:
#line 557 "expl.y"
    {(yyval.no) = makenode(">=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2500 "y.tab.c"
    break;

  case 123:
#line 558 "expl.y"
    {(yyval.no) = makenode("!=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2506 "y.tab.c"
    break;

  case 124:
#line 559 "expl.y"
    {(yyval.no) = makenode("==",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2512 "y.tab.c"
    break;

  case 125:
#line 561 "expl.y"
    {(yyval.no) = makenode("+",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2518 "y.tab.c"
    break;

  case 126:
#line 562 "expl.y"
    {(yyval.no) = makenode("-",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2524 "y.tab.c"
    break;

  case 127:
#line 563 "expl.y"
    {(yyval.no) = makenode("*",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2530 "y.tab.c"
    break;

  case 128:
#line 564 "expl.y"
    {(yyval.no) = makenode("/",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2536 "y.tab.c"
    break;

  case 129:
#line 565 "expl.y"
    {(yyval.no) = makenode("%",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2542 "y.tab.c"
    break;

  case 130:
#line 566 "expl.y"
    {(yyval.no) = makenode("@",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2548 "y.tab.c"
    break;

  case 131:
#line 567 "expl.y"
    {(yyval.no) = makenode("<",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2554 "y.tab.c"
    break;

  case 132:
#line 568 "expl.y"
    {(yyval.no) = makenode(">",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2560 "y.tab.c"
    break;

  case 133:
#line 569 "expl.y"
    {(yyval.no) = makenode("<=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2566 "y.tab.c"
    break;

  case 134:
#line 570 "expl.y"
    {(yyval.no) = makenode(">=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2572 "y.tab.c"
    break;

  case 135:
#line 571 "expl.y"
    {(yyval.no) = makenode("!=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2578 "y.tab.c"
    break;

  case 136:
#line 572 "expl.y"
    {(yyval.no) = makenode("==",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2584 "y.tab.c"
    break;

  case 137:
#line 574 "expl.y"
    {(yyval.no) = makenode("+",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2590 "y.tab.c"
    break;

  case 138:
#line 575 "expl.y"
    {(yyval.no) = makenode("-",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2596 "y.tab.c"
    break;

  case 139:
#line 576 "expl.y"
    {(yyval.no) = makenode("*",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2602 "y.tab.c"
    break;

  case 140:
#line 577 "expl.y"
    {(yyval.no) = makenode("/",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2608 "y.tab.c"
    break;

  case 141:
#line 578 "expl.y"
    {(yyval.no) = makenode("%",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2614 "y.tab.c"
    break;

  case 142:
#line 579 "expl.y"
    {(yyval.no) = makenode("@",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2620 "y.tab.c"
    break;

  case 143:
#line 580 "expl.y"
    {(yyval.no) = makenode("<",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2626 "y.tab.c"
    break;

  case 144:
#line 581 "expl.y"
    {(yyval.no) = makenode(">",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2632 "y.tab.c"
    break;

  case 145:
#line 582 "expl.y"
    {(yyval.no) = makenode("<=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2638 "y.tab.c"
    break;

  case 146:
#line 583 "expl.y"
    {(yyval.no) = makenode(">=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2644 "y.tab.c"
    break;

  case 147:
#line 584 "expl.y"
    {(yyval.no) = makenode("!=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2650 "y.tab.c"
    break;

  case 148:
#line 585 "expl.y"
    {(yyval.no) = makenode("==",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2656 "y.tab.c"
    break;

  case 149:
#line 587 "expl.y"
    {(yyval.no) = makenode("!=",14,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2662 "y.tab.c"
    break;

  case 150:
#line 588 "expl.y"
    {(yyval.no) = makenode("==",14,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2668 "y.tab.c"
    break;

  case 151:
#line 590 "expl.y"
    {(yyval.no) = makenode((yyvsp[-2].no)->varname,10,(yyvsp[-2].no)->type,NULL,NULL,NULL,NULL);}
#line 2674 "y.tab.c"
    break;

  case 152:
#line 591 "expl.y"
    {(yyval.no) = makenode((yyvsp[-3].no)->varname,10,(yyvsp[-3].no)->type,(yyvsp[-1].no),NULL,NULL,NULL);}
#line 2680 "y.tab.c"
    break;

  case 153:
#line 592 "expl.y"
    {(yyval.no) = makenode((yyvsp[-3].no)->varname,10,(yyvsp[-3].no)->type,(yyvsp[-1].no),NULL,NULL,NULL);}
#line 2686 "y.tab.c"
    break;

  case 154:
#line 593 "expl.y"
    {(yyval.no) = makenode((yyvsp[-3].no)->varname,10,(yyvsp[-3].no)->type,(yyvsp[-1].no),NULL,NULL,NULL);}
#line 2692 "y.tab.c"
    break;

  case 155:
#line 594 "expl.y"
    {(yyval.no) = makemethodnode((yyvsp[-5].no),(yyvsp[-3].no)->varname,10,(yyvsp[-5].no)->type,(yyvsp[-1].no));}
#line 2698 "y.tab.c"
    break;

  case 156:
#line 595 "expl.y"
    {(yyval.no) = makemethodnode((yyvsp[-4].no),(yyvsp[-2].no)->varname,10,(yyvsp[-4].no)->type,NULL);}
#line 2704 "y.tab.c"
    break;

  case 157:
#line 596 "expl.y"
    {(yyval.no) = makemethodnode((yyvsp[-5].no),(yyvsp[-3].no)->varname,10,(yyvsp[-5].no)->type,(yyvsp[-1].no));}
#line 2710 "y.tab.c"
    break;

  case 158:
#line 597 "expl.y"
    {(yyval.no) = makemethodnode((yyvsp[-5].no),(yyvsp[-3].no)->varname,10,(yyvsp[-5].no)->type,(yyvsp[-1].no));}
#line 2716 "y.tab.c"
    break;

  case 159:
#line 598 "expl.y"
    {(yyval.no) = makemethodnode((yyvsp[-5].no),(yyvsp[-3].no)->varname,10,(yyvsp[-5].no)->type,(yyvsp[-1].no));}
#line 2722 "y.tab.c"
    break;

  case 160:
#line 599 "expl.y"
    {(yyval.no) = makemethodnode((yyvsp[-4].no),(yyvsp[-2].no)->varname,10,(yyvsp[-4].no)->type,NULL);}
#line 2728 "y.tab.c"
    break;

  case 161:
#line 600 "expl.y"
    {(yyval.no) = makemethodnode((yyvsp[-5].no),(yyvsp[-3].no)->varname,10,(yyvsp[-5].no)->type,(yyvsp[-1].no));}
#line 2734 "y.tab.c"
    break;

  case 162:
#line 601 "expl.y"
    {(yyval.no) = makemethodnode((yyvsp[-5].no),(yyvsp[-3].no)->varname,10,(yyvsp[-5].no)->type,(yyvsp[-1].no));}
#line 2740 "y.tab.c"
    break;

  case 163:
#line 602 "expl.y"
    {(yyval.no) = (yyvsp[0].no);}
#line 2746 "y.tab.c"
    break;

  case 164:
#line 603 "expl.y"
    {(yyval.no) = (yyvsp[0].no);}
#line 2752 "y.tab.c"
    break;


#line 2756 "y.tab.c"

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
#line 606 "expl.y"


yyerror(char *s)
{
    printf("yyerror %s\n",s);
}


int main(void) {
	extern FILE *yyin;
  	yyin = fopen("Input", "r");
  	FILE *fptr = fopen("target.xsm", "w");
  	fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	fprintf(fptr, "BRKP\n");
	fclose(fptr);
	TypeTableCreate();
	tint=tLookup("int");
	tbool=tLookup("bool");
	yyparse();	
	return 0;
}
