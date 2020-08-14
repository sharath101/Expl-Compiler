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
    NEW = 319,
    EXTENDS = 320
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
#define EXTENDS 320

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

#line 262 "y.tab.c"

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
#define YYLAST   795

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  168
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  346

#define YYUNDEFTOK  2
#define YYMAXUTOK   320

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
      70,    71,     2,     2,    72,     2,    73,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    69,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    74,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,     2,    68,     2,     2,     2,     2,
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
      65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    44,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    57,    60,    61,    64,    76,    77,
      80,    84,    86,    87,    89,   106,   118,   135,   136,   138,
     139,   141,   143,   144,   146,   147,   152,   153,   155,   155,
     157,   159,   159,   161,   162,   163,   167,   167,   169,   240,
     297,   343,   391,   442,   483,   484,   487,   489,   490,   492,
     492,   494,   496,   496,   498,   499,   500,   505,   506,   509,
     510,   512,   512,   512,   513,   513,   513,   514,   515,   517,
     519,   520,   522,   523,   524,   525,   529,   531,   532,   534,
     535,   537,   539,   540,   541,   542,   543,   544,   546,   547,
     548,   552,   553,   554,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   608,   609,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624
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
  "NEW", "EXTENDS", "'['", "'{'", "'}'", "';'", "'('", "')'", "','", "'.'",
  "']'", "$accept", "Program", "TypeDefBlock", "TypeDefList", "TypeDef",
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
     315,   316,   317,   318,   319,   320,    91,   123,   125,    59,
      40,    41,    44,    46,    93
};
# endif

#define YYPACT_NINF -295

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-295)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     583,  -295,  -295,    17,  -295,   -33,   -38,    46,   191,   172,
     482,  -295,    18,  -295,   256,  -295,    28,   -14,    94,  -295,
      13,   119,  -295,    48,  -295,   172,   482,  -295,   482,  -295,
     482,  -295,  -295,   130,    60,  -295,  -295,    86,    44,  -295,
     482,  -295,  -295,   107,  -295,  -295,   153,   482,  -295,   482,
    -295,   482,  -295,  -295,  -295,   124,   155,    10,  -295,    28,
     -17,  -295,   179,  -295,   482,   482,  -295,  -295,  -295,   125,
     169,  -295,   116,  -295,   201,  -295,  -295,  -295,   182,   623,
    -295,   679,  -295,   196,  -295,   215,   136,     8,  -295,   482,
    -295,  -295,   482,  -295,   711,   482,  -295,   224,   211,     8,
     241,   633,   744,   293,   244,  -295,   254,   269,   482,   395,
     251,  -295,   465,   293,   255,     8,  -295,   262,   271,   286,
     295,   305,   323,   418,   334,   333,  -295,   633,  -295,   338,
     347,   348,   355,   412,   365,   367,   -10,  -295,   747,  -295,
     396,   373,  -295,  -295,   560,  -295,   375,   238,   392,  -295,
     293,   394,    14,   418,   418,   418,  -295,  -295,  -295,  -295,
     391,   397,   418,   342,   597,    14,   460,  -295,   454,  -295,
    -295,  -295,  -295,  -295,  -295,  -295,   350,   418,   463,  -295,
    -295,  -295,   200,  -295,  -295,  -295,   400,  -295,   403,  -295,
      77,   369,   500,   156,   525,   549,    -1,   473,   573,   418,
     418,   418,   418,   418,   418,   356,   383,   418,   418,   418,
     418,  -295,   474,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,  -295,   148,  -295,  -295,  -295,
     417,   156,   746,     1,   237,  -295,  -295,   447,  -295,  -295,
    -295,  -295,  -295,   471,   469,  -295,   264,   267,   423,   426,
    -295,   143,   321,   143,   321,   240,   160,   240,   160,    95,
     477,   -34,  -295,  -295,   393,   554,  -295,   393,   554,   393,
     554,   393,   554,   393,   554,   393,   554,   429,   143,   321,
     143,   321,   240,   160,   240,   160,    95,   477,   -34,  -295,
     393,   554,   393,   554,   393,   554,   393,   554,   393,   554,
     393,   554,  -295,   506,  -295,  -295,  -295,   683,   683,  -295,
     418,  -295,   418,  -295,   418,   197,   208,   441,   622,   644,
     156,   746,   156,   746,   156,   746,  -295,   301,   291,   448,
    -295,   309,   318,   476,  -295,   683,  -295,  -295,  -295,  -295,
    -295,  -295,  -295,  -295,   672,  -295
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    64,    65,     0,    66,     0,     0,     0,     0,     0,
       0,    13,     0,    37,     0,    39,     0,     0,     0,    16,
      27,     0,    23,     0,     1,     0,     0,     7,     0,    10,
       0,    47,    12,     0,     0,    36,    38,    43,     0,    42,
       0,    14,    15,     0,    21,    22,     0,     0,     5,     0,
       6,     0,     9,    46,    11,     0,     0,     0,    40,     0,
       0,    19,     0,    28,     0,     0,     3,     4,     8,     0,
       0,    45,     0,    55,     0,    41,    17,    18,     0,     0,
      30,     0,    33,     0,     2,     0,     0,     0,    44,     0,
      56,    20,     0,    29,     0,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,     0,    70,     0,
       0,     0,     0,     0,     0,     0,     0,    58,     0,    60,
       0,     0,    53,    26,     0,    25,     0,     0,     0,    51,
       0,     0,     0,     0,     0,     0,    77,    78,   167,   168,
      98,     0,     0,     0,     0,     0,     0,    69,     0,    71,
      72,    73,    74,    68,    75,    76,     0,     0,     0,    57,
      59,    63,     0,    52,    24,    35,     0,    49,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,   101,    67,    84,
       0,    83,    82,     0,     0,   100,    61,     0,    34,    48,
      79,    81,    80,     0,     0,   155,     0,     0,     0,   101,
     116,   141,   117,   142,   118,   143,   119,   144,   120,   145,
     121,   146,   122,   154,   152,   128,   153,   151,   127,   148,
     124,   150,   126,   147,   123,   149,   125,   100,   129,   104,
     130,   105,   131,   106,   132,   107,   133,   108,   134,   109,
     140,   115,   139,   114,   136,   111,   138,   113,   135,   110,
     137,   112,    86,     0,   102,   103,    62,     0,     0,   156,
       0,   157,     0,   158,     0,     0,     0,     0,     0,     0,
      96,    97,    92,    94,    93,    95,   164,     0,     0,     0,
     160,     0,     0,     0,    85,     0,    90,    91,   163,   165,
     166,   159,   161,   162,     0,    89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -295,  -295,  -295,  -295,   499,  -295,   458,   513,  -295,   501,
    -295,  -295,   444,   459,   -47,    15,  -295,   523,  -295,   480,
      82,     3,   700,   -57,   451,   -94,  -295,   404,  -295,   146,
     618,  -294,  -127,  -295,  -295,  -295,  -295,   416,  -295,  -295,
      67,  -117,   -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,    18,    19,    60,    61,     9,    21,    22,
      23,    79,    80,    81,    82,    10,    14,    15,    38,    39,
      30,    31,    11,    72,    73,   103,   138,   139,   182,    33,
     104,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     246,   136,   164
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     167,   176,   158,   159,   160,   113,   163,   199,   200,   201,
     202,   203,    86,   318,   319,     1,     2,   204,    17,   116,
     101,   150,    20,    26,    28,   205,   206,   207,   208,   209,
     210,     4,   177,    53,    96,   190,   191,   193,   193,   212,
      47,   344,     1,     2,   102,   193,    24,    96,   226,     1,
       2,    76,    53,    40,    53,   147,   177,    34,     4,   231,
     233,   161,   126,   178,    13,     4,    37,   177,    53,   162,
     245,   192,   194,   195,   212,   304,   125,   126,    43,   247,
     198,    71,   251,   253,   255,   257,   259,   261,   264,   267,
     269,   271,   273,   275,   232,   234,   278,   280,   282,   284,
     286,   288,   290,   292,   294,   296,   298,   300,    49,    53,
      51,   204,    53,    58,   248,    46,    59,   252,   254,   256,
     258,   260,   262,   265,   268,   270,   272,   274,   276,    65,
      56,   279,   281,   283,   285,   287,   289,   291,   293,   295,
     297,   299,   301,   177,    41,    17,    12,    53,   240,    16,
     178,   201,   202,   203,    12,    12,    57,     1,     2,   204,
      16,   177,   199,   200,   201,   202,   203,    63,   212,    34,
     217,    12,   204,     4,   106,    55,   218,   109,    44,    20,
     205,   206,   207,   208,   209,   210,    62,    88,    89,    64,
     144,   167,   167,   320,    69,   322,    85,   324,   328,   332,
     158,   159,   160,    74,     1,     2,    62,   100,    89,   177,
      83,   158,   159,   160,   177,    74,   212,   167,     3,   302,
       4,   178,   177,     1,     2,    83,    70,    97,   321,   212,
     323,    78,   325,   329,   333,    74,    87,     3,   107,     4,
      97,   107,    90,   213,   214,   215,   216,   217,   140,     6,
     203,    91,   107,   218,   107,   107,   204,    98,    74,   161,
     126,   219,   220,   221,   222,   223,   224,   162,   326,   236,
     161,   126,   237,   199,   200,   201,   202,   203,   162,   330,
     111,   112,    99,   204,   140,   110,     1,     2,     1,     2,
     107,   205,   206,   207,   208,   209,   210,   199,   200,   201,
     202,   203,     4,    35,     4,   101,   177,   204,   115,   186,
      89,   305,   142,   212,    55,   205,   206,   207,   208,   209,
     210,   112,   143,   149,   199,   200,   201,   202,   203,   215,
     216,   217,   152,   177,   204,   309,   310,   218,   311,   312,
     212,   153,   205,   206,   207,   208,   209,   210,   199,   200,
     201,   202,   203,   158,   159,   160,   154,   177,   204,   158,
     159,   160,   339,   312,   212,   155,   205,   206,   207,   208,
     209,   210,   338,   310,   156,   199,   200,   201,   202,   203,
     341,   310,   327,   331,   177,   204,   158,   159,   160,   342,
     312,   212,   157,   205,   206,   207,   208,   209,   210,   199,
     200,   201,   202,   203,   165,   229,   166,   169,   177,   204,
     263,   211,   161,   126,   230,   212,   170,   171,   161,   126,
     162,   158,   159,   160,   172,   173,   162,     1,     2,   213,
     214,   215,   216,   217,   174,   177,   175,   266,   181,   218,
     241,   183,   212,     4,   185,   161,   126,   219,   220,   221,
     222,   223,   224,   162,   213,   214,   215,   216,   217,   177,
     187,   196,   189,   145,   218,   227,   212,   228,   235,   238,
     197,   239,   219,   220,   221,   222,   223,   224,   249,   277,
     161,   126,   213,   214,   215,   216,   217,   303,   162,   306,
     307,   308,   218,   218,   313,   314,   315,     1,     2,   316,
     219,   220,   221,   222,   223,   224,   213,   214,   215,   216,
     217,   317,   334,     4,     1,     2,   218,    42,    77,   340,
     314,    25,    45,    93,   219,   220,   221,   222,   223,   224,
       4,   213,   214,   215,   216,   217,   146,    36,    94,    75,
     105,   218,   180,   168,     0,     0,     0,   343,   314,   219,
     220,   221,   222,   223,   224,   213,   214,   215,   216,   217,
     213,   214,   215,   216,   217,   218,     0,     0,     0,     0,
     218,   242,     0,   219,   220,   221,   222,   223,   224,   213,
     214,   215,   216,   217,     0,     0,     0,     0,     0,   218,
       0,     0,     1,     2,     0,     0,   243,   219,   220,   221,
     222,   223,   224,   213,   214,   215,   216,   217,     4,     0,
       0,     0,     0,   218,     0,     1,     2,     0,     0,     0,
     244,   219,   220,   221,   222,   223,   224,   116,   184,     3,
       0,     4,     5,     0,     0,     0,   117,   118,   116,   119,
     335,     6,   336,   120,   250,     0,     0,   117,   118,   116,
     119,     0,   121,   122,   120,     1,     2,     0,   117,   118,
      92,   119,     0,   121,   122,   120,   225,   337,     0,     0,
       0,     4,     0,   123,   121,   122,     0,   116,     0,   124,
       0,     0,     0,     0,   125,   126,   117,   118,   116,   119,
     124,     0,   345,   120,     0,   125,   126,   117,   118,     0,
     119,   124,   121,   122,   120,     0,   125,   126,    27,    29,
      32,     1,     2,   121,   122,     0,    95,   114,     0,     0,
       0,   141,     0,     0,     0,    48,    50,     4,    52,   124,
      54,   148,     0,   151,   125,   126,     0,     0,     0,     0,
     124,     0,     0,     1,     2,   125,   126,    66,   108,    67,
       0,    68,   213,   214,   215,   216,   217,     0,     0,     4,
       0,     0,   218,     0,     0,    84,     0,     0,   188,     0,
     219,   220,   221,   222,   223,   224,     1,     2,     0,     1,
       2,   137,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     4,     0,     0,     4
};

static const yytype_int16 yycheck[] =
{
     127,    11,     3,     4,     5,    99,   123,     6,     7,     8,
       9,    10,    69,   307,   308,    32,    33,    16,    51,     5,
      12,   115,    60,     8,     9,    24,    25,    26,    27,    28,
      29,    48,    66,    30,    81,   152,   153,   154,   155,    73,
      25,   335,    32,    33,    36,   162,     0,    94,   165,    32,
      33,    68,    49,    67,    51,   112,    66,    39,    48,   176,
     177,    62,    63,    73,    47,    48,    38,    66,    65,    70,
      71,   153,   154,   155,    73,    74,    62,    63,    65,   196,
     162,    71,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   176,   177,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    26,   106,
      28,    16,   109,    69,   196,    67,    72,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    47,
      70,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    66,    50,    51,     0,   144,    71,     3,
      73,     8,     9,    10,     8,     9,    70,    32,    33,    16,
      14,    66,     6,     7,     8,     9,    10,    60,    73,    39,
      10,    25,    16,    48,    92,    45,    16,    95,    59,    60,
      24,    25,    26,    27,    28,    29,    40,    71,    72,    36,
     108,   318,   319,   310,    70,   312,    71,   314,   315,   316,
       3,     4,     5,    57,    32,    33,    60,    71,    72,    66,
      64,     3,     4,     5,    66,    69,    73,   344,    46,    71,
      48,    73,    66,    32,    33,    79,    71,    81,   310,    73,
     312,    52,   314,   315,   316,    89,    67,    46,    92,    48,
      94,    95,    41,     6,     7,     8,     9,    10,   102,    58,
      10,    69,   106,    16,   108,   109,    16,    61,   112,    62,
      63,    24,    25,    26,    27,    28,    29,    70,    71,    69,
      62,    63,    72,     6,     7,     8,     9,    10,    70,    71,
      69,    70,    67,    16,   138,    61,    32,    33,    32,    33,
     144,    24,    25,    26,    27,    28,    29,     6,     7,     8,
       9,    10,    48,    47,    48,    12,    66,    16,    67,    71,
      72,    74,    68,    73,    45,    24,    25,    26,    27,    28,
      29,    70,    68,    68,     6,     7,     8,     9,    10,     8,
       9,    10,    70,    66,    16,    71,    72,    16,    71,    72,
      73,    70,    24,    25,    26,    27,    28,    29,     6,     7,
       8,     9,    10,     3,     4,     5,    70,    66,    16,     3,
       4,     5,    71,    72,    73,    70,    24,    25,    26,    27,
      28,    29,    71,    72,    69,     6,     7,     8,     9,    10,
      71,    72,   315,   316,    66,    16,     3,     4,     5,    71,
      72,    73,    69,    24,    25,    26,    27,    28,    29,     6,
       7,     8,     9,    10,    70,    55,    73,    69,    66,    16,
      54,    69,    62,    63,    64,    73,    69,    69,    62,    63,
      70,     3,     4,     5,    69,    13,    70,    32,    33,     6,
       7,     8,     9,    10,    69,    66,    69,    54,    42,    16,
      71,    68,    73,    48,    69,    62,    63,    24,    25,    26,
      27,    28,    29,    70,     6,     7,     8,     9,    10,    66,
      68,    70,    68,    68,    16,     5,    73,    13,     5,    69,
      73,    68,    24,    25,    26,    27,    28,    29,     5,     5,
      62,    63,     6,     7,     8,     9,    10,    70,    70,    42,
      19,    22,    16,    16,    71,    72,    70,    32,    33,    70,
      24,    25,    26,    27,    28,    29,     6,     7,     8,     9,
      10,     5,    71,    48,    32,    33,    16,    18,    60,    71,
      72,     8,    21,    79,    24,    25,    26,    27,    28,    29,
      48,     6,     7,     8,     9,    10,    71,    14,    79,    59,
      89,    16,   138,   127,    -1,    -1,    -1,    71,    72,    24,
      25,    26,    27,    28,    29,     6,     7,     8,     9,    10,
       6,     7,     8,     9,    10,    16,    -1,    -1,    -1,    -1,
      16,    71,    -1,    24,    25,    26,    27,    28,    29,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    32,    33,    -1,    -1,    71,    24,    25,    26,
      27,    28,    29,     6,     7,     8,     9,    10,    48,    -1,
      -1,    -1,    -1,    16,    -1,    32,    33,    -1,    -1,    -1,
      71,    24,    25,    26,    27,    28,    29,     5,    68,    46,
      -1,    48,    49,    -1,    -1,    -1,    14,    15,     5,    17,
      18,    58,    20,    21,    71,    -1,    -1,    14,    15,     5,
      17,    -1,    30,    31,    21,    32,    33,    -1,    14,    15,
      37,    17,    -1,    30,    31,    21,    69,    23,    -1,    -1,
      -1,    48,    -1,    40,    30,    31,    -1,     5,    -1,    57,
      -1,    -1,    -1,    -1,    62,    63,    14,    15,     5,    17,
      57,    -1,    20,    21,    -1,    62,    63,    14,    15,    -1,
      17,    57,    30,    31,    21,    -1,    62,    63,     8,     9,
      10,    32,    33,    30,    31,    -1,    37,    99,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    25,    26,    48,    28,    57,
      30,   113,    -1,   115,    62,    63,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    32,    33,    62,    63,    47,    37,    49,
      -1,    51,     6,     7,     8,     9,    10,    -1,    -1,    48,
      -1,    -1,    16,    -1,    -1,    65,    -1,    -1,   150,    -1,
      24,    25,    26,    27,    28,    29,    32,    33,    -1,    32,
      33,    37,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    33,    46,    48,    49,    58,    76,    77,    82,
      90,    97,   104,    47,    91,    92,   104,    51,    78,    79,
      60,    83,    84,    85,     0,    82,    90,    97,    90,    97,
      95,    96,    97,   104,    39,    47,    92,    38,    93,    94,
      67,    50,    79,    65,    59,    84,    67,    90,    97,    95,
      97,    95,    97,    96,    97,    45,    70,    70,    69,    72,
      80,    81,   104,    60,    36,    95,    97,    97,    97,    70,
      71,    71,    98,    99,   104,    94,    68,    81,    52,    86,
      87,    88,    89,   104,    97,    71,    98,    67,    71,    72,
      41,    69,    37,    87,    88,    37,    89,   104,    61,    67,
      71,    12,    36,   100,   105,    99,    95,   104,    37,    95,
      61,    69,    70,   100,   105,    67,     5,    14,    15,    17,
      21,    30,    31,    40,    57,    62,    63,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   116,    37,   101,   102,
     104,   105,    68,    68,    95,    68,    71,    98,   105,    68,
     100,   105,    70,    70,    70,    70,    69,    69,     3,     4,
       5,    62,    70,   116,   117,    70,    73,   107,   112,    69,
      69,    69,    69,    13,    69,    69,    11,    66,    73,    37,
     102,    42,   103,    68,    68,    69,    71,    68,   105,    68,
     116,   116,   117,   116,   117,   117,    70,    73,   117,     6,
       7,     8,     9,    10,    16,    24,    25,    26,    27,    28,
      29,    69,    73,     6,     7,     8,     9,    10,    16,    24,
      25,    26,    27,    28,    29,    69,   116,     5,    13,    55,
      64,   116,   117,   116,   117,     5,    69,    72,    69,    68,
      71,    71,    71,    71,    71,    71,   115,   116,   117,     5,
      71,   116,   117,   116,   117,   116,   117,   116,   117,   116,
     117,   116,   117,    54,   116,   117,    54,   116,   117,   116,
     117,   116,   117,   116,   117,   116,   117,     5,   116,   117,
     116,   117,   116,   117,   116,   117,   116,   117,   116,   117,
     116,   117,   116,   117,   116,   117,   116,   117,   116,   117,
     116,   117,    71,    70,    74,    74,    42,    19,    22,    71,
      72,    71,    72,    71,    72,    70,    70,     5,   106,   106,
     116,   117,   116,   117,   116,   117,    71,   115,   116,   117,
      71,   115,   116,   117,    71,    18,    20,    23,    71,    71,
      71,    71,    71,    71,   106,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    77,    78,    78,    79,    80,    80,
      81,    82,    83,    83,    84,    84,    84,    85,    85,    86,
      86,    87,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    93,    93,    94,    94,    94,    95,    95,    96,    96,
      96,    96,    97,    97,    98,    98,    99,   100,   100,   101,
     101,   102,   103,   103,   104,   104,   104,   105,   105,   106,
     106,   107,   107,   107,   107,   107,   107,   107,   107,   108,
     109,   109,   110,   110,   110,   110,   111,   112,   112,   113,
     113,   114,   115,   115,   115,   115,   115,   115,   116,   116,
     116,   116,   116,   116,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     3,     3,     2,     4,     3,
       2,     3,     2,     1,     3,     2,     1,     4,     2,     1,
       3,     3,     2,     1,     8,     7,     7,     1,     3,     2,
       1,     3,     2,     1,     6,     5,     3,     2,     2,     1,
       3,     3,     1,     1,     4,     3,     2,     1,     9,     8,
       8,     7,     8,     7,     3,     1,     2,     3,     2,     2,
       1,     3,     3,     1,     1,     1,     1,     4,     3,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     4,
       4,     4,     3,     3,     3,     6,     4,     3,     3,     9,
       7,     7,     3,     3,     3,     3,     3,     3,     1,     1,
       3,     3,     4,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     4,     4,     6,
       5,     6,     6,     6,     5,     6,     6,     1,     1
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
#line 1688 "y.tab.c"
    break;

  case 3:
#line 45 "expl.y"
    {printf("Program done\n");}
#line 1694 "y.tab.c"
    break;

  case 4:
#line 46 "expl.y"
    {printf("Program done\n");}
#line 1700 "y.tab.c"
    break;

  case 5:
#line 47 "expl.y"
    {printf("Program done\n");}
#line 1706 "y.tab.c"
    break;

  case 6:
#line 48 "expl.y"
    {printf("Program done\n");}
#line 1712 "y.tab.c"
    break;

  case 7:
#line 49 "expl.y"
    {printf("Program done\n");}
#line 1718 "y.tab.c"
    break;

  case 8:
#line 50 "expl.y"
    {printf("Program done\n");}
#line 1724 "y.tab.c"
    break;

  case 9:
#line 51 "expl.y"
    {printf("Program done\n");}
#line 1730 "y.tab.c"
    break;

  case 10:
#line 52 "expl.y"
    {printf("Program done\n");}
#line 1736 "y.tab.c"
    break;

  case 11:
#line 53 "expl.y"
    {printf("Program done\n");}
#line 1742 "y.tab.c"
    break;

  case 12:
#line 54 "expl.y"
    {printf("Program done\n");}
#line 1748 "y.tab.c"
    break;

  case 13:
#line 55 "expl.y"
    {printf("Program done\n");}
#line 1754 "y.tab.c"
    break;

  case 14:
#line 57 "expl.y"
    {(yyval.no)=(yyvsp[-2].no);tdisplay();printf("--------------------Typedec done--------------------\n");}
#line 1760 "y.tab.c"
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
#line 1775 "y.tab.c"
    break;

  case 20:
#line 80 "expl.y"
    {(yyval.fs)= newfield((yyvsp[-1].no)->varname,(yyvsp[-2].ts));}
#line 1781 "y.tab.c"
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
#line 1802 "y.tab.c"
    break;

  case 25:
#line 107 "expl.y"
    {
												mdisplay(mroot);
												(yyval.cs)=Appendclass((yyvsp[-6].cs)->name,NULL,mroot,cnum,fnum,mnum);
												cnum++;
												fnum=0;
												mnum=0;
												cfroot=NULL;
												mroot=NULL;
												currclass=NULL;
												printf("-------------------------------Class %s done----------------------------\n",(yyvsp[-6].cs)->name);
											}
#line 1818 "y.tab.c"
    break;

  case 26:
#line 119 "expl.y"
    {
												if(fnum>8){
													printf("Class field limit exceeded\n");
													exit(1);
												}
												cfdisplay(cfroot);
												(yyval.cs)=Appendclass((yyvsp[-6].cs)->name,cfroot,NULL,cnum,fnum,mnum);
												cnum++;
												fnum=0;
												mnum=0;
												cfroot=NULL;
												mroot=NULL;
												currclass=NULL;
												printf("-------------------------------Class %s done----------------------------\n",(yyvsp[-6].cs)->name);
											}
#line 1838 "y.tab.c"
    break;

  case 27:
#line 135 "expl.y"
    {Cptr = newclass((yyvsp[0].ts)->name,NULL); currclass=Cptr; (yyval.cs)=Cptr; classnum++;}
#line 1844 "y.tab.c"
    break;

  case 28:
#line 136 "expl.y"
    {Cptr = newclass((yyvsp[-2].ts)->name,(yyvsp[0].ts)->name); currclass=Cptr; (yyval.cs)=Cptr; classnum++;}
#line 1850 "y.tab.c"
    break;

  case 31:
#line 141 "expl.y"
    {newcfield(Cptr,(yyvsp[-2].ts),(yyvsp[-1].no)->varname);}
#line 1856 "y.tab.c"
    break;

  case 34:
#line 146 "expl.y"
    {newcmethod(Cptr,(yyvsp[-4].no)->varname,(yyvsp[-5].ts),(yyvsp[-2].pr));lroot=NULL;}
#line 1862 "y.tab.c"
    break;

  case 35:
#line 147 "expl.y"
    {newcmethod(Cptr,(yyvsp[-3].no)->varname,(yyvsp[-4].ts),NULL);lroot=NULL;}
#line 1868 "y.tab.c"
    break;

  case 36:
#line 152 "expl.y"
    {gdisplay();printf("--------------------Global done--------------------\n");(yyval.no)=(yyvsp[-2].no);}
#line 1874 "y.tab.c"
    break;

  case 40:
#line 157 "expl.y"
    {(yyval.gs)=(yyvsp[-1].gs);}
#line 1880 "y.tab.c"
    break;

  case 44:
#line 162 "expl.y"
    {(yyval.gs)= Appendgparam((yyvsp[-3].gs),(yyvsp[-1].pr));}
#line 1886 "y.tab.c"
    break;

  case 45:
#line 163 "expl.y"
    {(yyval.gs)= Appendgparam((yyvsp[-2].gs),NULL);}
#line 1892 "y.tab.c"
    break;

  case 48:
#line 170 "expl.y"
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
#line 1967 "y.tab.c"
    break;

  case 49:
#line 241 "expl.y"
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
#line 2028 "y.tab.c"
    break;

  case 50:
#line 298 "expl.y"
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
#line 2078 "y.tab.c"
    break;

  case 51:
#line 344 "expl.y"
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
#line 2128 "y.tab.c"
    break;

  case 52:
#line 392 "expl.y"
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
										     createvirtualtable(fptr);
											 fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
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
											 exitprogram(fptr);
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
#line 2182 "y.tab.c"
    break;

  case 53:
#line 443 "expl.y"
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
											 fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
											 fprintf(fptr, "MOV BP, SP\n");pos++;
											 codegen((yyvsp[-1].no),fptr);
											 exitprogram(fptr);
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
#line 2224 "y.tab.c"
    break;

  case 54:
#line 483 "expl.y"
    {(yyval.pr) = Appendparam((yyvsp[-2].pr),(yyvsp[0].pr));}
#line 2230 "y.tab.c"
    break;

  case 55:
#line 484 "expl.y"
    {(yyval.pr) = (yyvsp[0].pr);}
#line 2236 "y.tab.c"
    break;

  case 56:
#line 487 "expl.y"
    {(yyval.pr)=(yyvsp[0].pr);}
#line 2242 "y.tab.c"
    break;

  case 61:
#line 494 "expl.y"
    {(yyval.ls)=(yyvsp[-1].ls);}
#line 2248 "y.tab.c"
    break;

  case 67:
#line 505 "expl.y"
    {(yyval.no)=makenode("filledlater",12,NULL,NULL,(yyvsp[-2].no),NULL,(yyvsp[-1].no));}
#line 2254 "y.tab.c"
    break;

  case 68:
#line 506 "expl.y"
    {(yyval.no)=makenode("filledlater",12,NULL,NULL,NULL,NULL,(yyvsp[-1].no));printf("Nothing inside body\n");}
#line 2260 "y.tab.c"
    break;

  case 69:
#line 509 "expl.y"
    {(yyval.no) = makenode("connector",3,NULL,NULL,(yyvsp[-1].no),NULL,(yyvsp[0].no));}
#line 2266 "y.tab.c"
    break;

  case 77:
#line 514 "expl.y"
    {(yyval.no)=(yyvsp[-1].no);}
#line 2272 "y.tab.c"
    break;

  case 78:
#line 515 "expl.y"
    {(yyval.no)=(yyvsp[-1].no);}
#line 2278 "y.tab.c"
    break;

  case 79:
#line 517 "expl.y"
    {(yyval.no) = makenode("read",1,NULL,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2284 "y.tab.c"
    break;

  case 80:
#line 519 "expl.y"
    {(yyval.no) = makenode("write",2,NULL,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2290 "y.tab.c"
    break;

  case 81:
#line 520 "expl.y"
    {(yyval.no) = makenode("write",2,NULL,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2296 "y.tab.c"
    break;

  case 82:
#line 522 "expl.y"
    {(yyval.no) = makenode("=",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2302 "y.tab.c"
    break;

  case 83:
#line 523 "expl.y"
    {(yyval.no) = makenode("=",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2308 "y.tab.c"
    break;

  case 84:
#line 524 "expl.y"
    {(yyval.no) = makenode("=",14,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2314 "y.tab.c"
    break;

  case 85:
#line 525 "expl.y"
    {(yyval.no) = makenode("=",4,tint,NULL,(yyvsp[-5].no),(yyvsp[-1].no),(yyvsp[-3].no));}
#line 2320 "y.tab.c"
    break;

  case 86:
#line 529 "expl.y"
    {(yyval.no) = makenode("free",14,tint,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2326 "y.tab.c"
    break;

  case 87:
#line 531 "expl.y"
    {(yyval.no) = makenode("return",11,NULL,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2332 "y.tab.c"
    break;

  case 88:
#line 532 "expl.y"
    {(yyval.no) = makenode("return",11,NULL,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2338 "y.tab.c"
    break;

  case 89:
#line 534 "expl.y"
    {(yyval.no)= makenode("ifelse",6,NULL,NULL,(yyvsp[-6].no),(yyvsp[-3].no),(yyvsp[-1].no));}
#line 2344 "y.tab.c"
    break;

  case 90:
#line 535 "expl.y"
    {(yyval.no)= makenode("if",6,NULL,NULL,(yyvsp[-4].no),(yyvsp[-1].no),NULL);}
#line 2350 "y.tab.c"
    break;

  case 91:
#line 537 "expl.y"
    {(yyval.no)= makenode("while",5,NULL,NULL,(yyvsp[-4].no),NULL,(yyvsp[-1].no));}
#line 2356 "y.tab.c"
    break;

  case 92:
#line 539 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2362 "y.tab.c"
    break;

  case 93:
#line 540 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2368 "y.tab.c"
    break;

  case 94:
#line 541 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2374 "y.tab.c"
    break;

  case 95:
#line 542 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2380 "y.tab.c"
    break;

  case 96:
#line 543 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2386 "y.tab.c"
    break;

  case 97:
#line 544 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2392 "y.tab.c"
    break;

  case 100:
#line 548 "expl.y"
    {(yyval.no) = fieldconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2398 "y.tab.c"
    break;

  case 101:
#line 552 "expl.y"
    {(yyval.no) = makenode("self",15,(yyvsp[0].no)->type,NULL,(yyvsp[0].no),NULL,NULL);}
#line 2404 "y.tab.c"
    break;

  case 102:
#line 553 "expl.y"
    {(yyval.no) = makearraynode((yyvsp[-3].no)->varname,(yyvsp[-3].no)->type,(yyvsp[-1].no));}
#line 2410 "y.tab.c"
    break;

  case 103:
#line 554 "expl.y"
    {(yyval.no) = makearraynode((yyvsp[-3].no)->varname,(yyvsp[-3].no)->type,(yyvsp[-1].no));}
#line 2416 "y.tab.c"
    break;

  case 104:
#line 556 "expl.y"
    {(yyval.no) = makenode("+",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2422 "y.tab.c"
    break;

  case 105:
#line 557 "expl.y"
    {(yyval.no) = makenode("-",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2428 "y.tab.c"
    break;

  case 106:
#line 558 "expl.y"
    {(yyval.no) = makenode("*",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2434 "y.tab.c"
    break;

  case 107:
#line 559 "expl.y"
    {(yyval.no) = makenode("/",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2440 "y.tab.c"
    break;

  case 108:
#line 560 "expl.y"
    {(yyval.no) = makenode("%",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2446 "y.tab.c"
    break;

  case 109:
#line 561 "expl.y"
    {(yyval.no) = makenode("@",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2452 "y.tab.c"
    break;

  case 110:
#line 562 "expl.y"
    {(yyval.no) = makenode("<",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2458 "y.tab.c"
    break;

  case 111:
#line 563 "expl.y"
    {(yyval.no) = makenode(">",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2464 "y.tab.c"
    break;

  case 112:
#line 564 "expl.y"
    {(yyval.no) = makenode("<=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2470 "y.tab.c"
    break;

  case 113:
#line 565 "expl.y"
    {(yyval.no) = makenode(">=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2476 "y.tab.c"
    break;

  case 114:
#line 566 "expl.y"
    {(yyval.no) = makenode("!=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2482 "y.tab.c"
    break;

  case 115:
#line 567 "expl.y"
    {(yyval.no) = makenode("==",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2488 "y.tab.c"
    break;

  case 116:
#line 568 "expl.y"
    {(yyval.no) = (yyvsp[-1].no);}
#line 2494 "y.tab.c"
    break;

  case 117:
#line 569 "expl.y"
    {(yyval.no) = makenode("+",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2500 "y.tab.c"
    break;

  case 118:
#line 570 "expl.y"
    {(yyval.no) = makenode("-",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2506 "y.tab.c"
    break;

  case 119:
#line 571 "expl.y"
    {(yyval.no) = makenode("*",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2512 "y.tab.c"
    break;

  case 120:
#line 572 "expl.y"
    {(yyval.no) = makenode("/",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2518 "y.tab.c"
    break;

  case 121:
#line 573 "expl.y"
    {(yyval.no) = makenode("%",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2524 "y.tab.c"
    break;

  case 122:
#line 574 "expl.y"
    {(yyval.no) = makenode("@",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2530 "y.tab.c"
    break;

  case 123:
#line 575 "expl.y"
    {(yyval.no) = makenode("<",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2536 "y.tab.c"
    break;

  case 124:
#line 576 "expl.y"
    {(yyval.no) = makenode(">",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2542 "y.tab.c"
    break;

  case 125:
#line 577 "expl.y"
    {(yyval.no) = makenode("<=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2548 "y.tab.c"
    break;

  case 126:
#line 578 "expl.y"
    {(yyval.no) = makenode(">=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2554 "y.tab.c"
    break;

  case 127:
#line 579 "expl.y"
    {(yyval.no) = makenode("!=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2560 "y.tab.c"
    break;

  case 128:
#line 580 "expl.y"
    {(yyval.no) = makenode("==",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2566 "y.tab.c"
    break;

  case 129:
#line 582 "expl.y"
    {(yyval.no) = makenode("+",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2572 "y.tab.c"
    break;

  case 130:
#line 583 "expl.y"
    {(yyval.no) = makenode("-",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2578 "y.tab.c"
    break;

  case 131:
#line 584 "expl.y"
    {(yyval.no) = makenode("*",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2584 "y.tab.c"
    break;

  case 132:
#line 585 "expl.y"
    {(yyval.no) = makenode("/",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2590 "y.tab.c"
    break;

  case 133:
#line 586 "expl.y"
    {(yyval.no) = makenode("%",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2596 "y.tab.c"
    break;

  case 134:
#line 587 "expl.y"
    {(yyval.no) = makenode("@",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2602 "y.tab.c"
    break;

  case 135:
#line 588 "expl.y"
    {(yyval.no) = makenode("<",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2608 "y.tab.c"
    break;

  case 136:
#line 589 "expl.y"
    {(yyval.no) = makenode(">",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2614 "y.tab.c"
    break;

  case 137:
#line 590 "expl.y"
    {(yyval.no) = makenode("<=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2620 "y.tab.c"
    break;

  case 138:
#line 591 "expl.y"
    {(yyval.no) = makenode(">=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2626 "y.tab.c"
    break;

  case 139:
#line 592 "expl.y"
    {(yyval.no) = makenode("!=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2632 "y.tab.c"
    break;

  case 140:
#line 593 "expl.y"
    {(yyval.no) = makenode("==",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2638 "y.tab.c"
    break;

  case 141:
#line 595 "expl.y"
    {(yyval.no) = makenode("+",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2644 "y.tab.c"
    break;

  case 142:
#line 596 "expl.y"
    {(yyval.no) = makenode("-",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2650 "y.tab.c"
    break;

  case 143:
#line 597 "expl.y"
    {(yyval.no) = makenode("*",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2656 "y.tab.c"
    break;

  case 144:
#line 598 "expl.y"
    {(yyval.no) = makenode("/",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2662 "y.tab.c"
    break;

  case 145:
#line 599 "expl.y"
    {(yyval.no) = makenode("%",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2668 "y.tab.c"
    break;

  case 146:
#line 600 "expl.y"
    {(yyval.no) = makenode("@",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2674 "y.tab.c"
    break;

  case 147:
#line 601 "expl.y"
    {(yyval.no) = makenode("<",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2680 "y.tab.c"
    break;

  case 148:
#line 602 "expl.y"
    {(yyval.no) = makenode(">",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2686 "y.tab.c"
    break;

  case 149:
#line 603 "expl.y"
    {(yyval.no) = makenode("<=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2692 "y.tab.c"
    break;

  case 150:
#line 604 "expl.y"
    {(yyval.no) = makenode(">=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2698 "y.tab.c"
    break;

  case 151:
#line 605 "expl.y"
    {(yyval.no) = makenode("!=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2704 "y.tab.c"
    break;

  case 152:
#line 606 "expl.y"
    {(yyval.no) = makenode("==",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2710 "y.tab.c"
    break;

  case 153:
#line 608 "expl.y"
    {(yyval.no) = makenode("!=",14,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2716 "y.tab.c"
    break;

  case 154:
#line 609 "expl.y"
    {(yyval.no) = makenode("==",14,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2722 "y.tab.c"
    break;

  case 155:
#line 611 "expl.y"
    {(yyval.no) = makenode((yyvsp[-2].no)->varname,10,(yyvsp[-2].no)->type,NULL,NULL,NULL,NULL);}
#line 2728 "y.tab.c"
    break;

  case 156:
#line 612 "expl.y"
    {(yyval.no) = makenode((yyvsp[-3].no)->varname,10,(yyvsp[-3].no)->type,(yyvsp[-1].no),NULL,NULL,NULL);}
#line 2734 "y.tab.c"
    break;

  case 157:
#line 613 "expl.y"
    {(yyval.no) = makenode((yyvsp[-3].no)->varname,10,(yyvsp[-3].no)->type,(yyvsp[-1].no),NULL,NULL,NULL);}
#line 2740 "y.tab.c"
    break;

  case 158:
#line 614 "expl.y"
    {(yyval.no) = makenode((yyvsp[-3].no)->varname,10,(yyvsp[-3].no)->type,(yyvsp[-1].no),NULL,NULL,NULL);}
#line 2746 "y.tab.c"
    break;

  case 159:
#line 615 "expl.y"
    {(yyval.no) = makemethodnode((yyvsp[-5].no),(yyvsp[-3].no)->varname,10,(yyvsp[-5].no)->type,(yyvsp[-1].no));}
#line 2752 "y.tab.c"
    break;

  case 160:
#line 616 "expl.y"
    {(yyval.no) = makemethodnode((yyvsp[-4].no),(yyvsp[-2].no)->varname,10,(yyvsp[-4].no)->type,NULL);}
#line 2758 "y.tab.c"
    break;

  case 161:
#line 617 "expl.y"
    {(yyval.no) = makemethodnode((yyvsp[-5].no),(yyvsp[-3].no)->varname,10,(yyvsp[-5].no)->type,(yyvsp[-1].no));}
#line 2764 "y.tab.c"
    break;

  case 162:
#line 618 "expl.y"
    {(yyval.no) = makemethodnode((yyvsp[-5].no),(yyvsp[-3].no)->varname,10,(yyvsp[-5].no)->type,(yyvsp[-1].no));}
#line 2770 "y.tab.c"
    break;

  case 163:
#line 619 "expl.y"
    {(yyval.no) = makemethodnode((yyvsp[-5].no),(yyvsp[-3].no)->varname,10,(yyvsp[-5].no)->type,(yyvsp[-1].no));}
#line 2776 "y.tab.c"
    break;

  case 164:
#line 620 "expl.y"
    {(yyval.no) = makemethodnode((yyvsp[-4].no),(yyvsp[-2].no)->varname,10,(yyvsp[-4].no)->type,NULL);}
#line 2782 "y.tab.c"
    break;

  case 165:
#line 621 "expl.y"
    {(yyval.no) = makemethodnode((yyvsp[-5].no),(yyvsp[-3].no)->varname,10,(yyvsp[-5].no)->type,(yyvsp[-1].no));}
#line 2788 "y.tab.c"
    break;

  case 166:
#line 622 "expl.y"
    {(yyval.no) = makemethodnode((yyvsp[-5].no),(yyvsp[-3].no)->varname,10,(yyvsp[-5].no)->type,(yyvsp[-1].no));}
#line 2794 "y.tab.c"
    break;

  case 167:
#line 623 "expl.y"
    {(yyval.no) = (yyvsp[0].no);}
#line 2800 "y.tab.c"
    break;

  case 168:
#line 624 "expl.y"
    {(yyval.no) = (yyvsp[0].no);}
#line 2806 "y.tab.c"
    break;


#line 2810 "y.tab.c"

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
#line 627 "expl.y"


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
