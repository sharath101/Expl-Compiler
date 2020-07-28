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
    FREE = 312
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

#line 245 "y.tab.c"

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   605

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  265

#define YYUNDEFTOK  2
#define YYMAXUTOK   312

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
      63,    64,     2,     2,    62,     2,    65,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    61,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
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
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    40,    40,    41,    42,    43,    44,    45,    47,    50,
      51,    54,    66,    67,    70,    74,    75,    77,    77,    79,
      81,    81,    83,    84,    85,    89,    89,    91,   151,   196,
     230,   265,   313,   352,   353,   356,   358,   359,   361,   361,
     363,   365,   365,   367,   368,   369,   374,   375,   378,   379,
     381,   381,   381,   382,   382,   382,   383,   384,   386,   388,
     389,   391,   392,   393,   396,   398,   399,   401,   402,   404,
     406,   407,   408,   409,   410,   411,   413,   414,   415,   416,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   470,
     471,   473,   474,   475,   476,   477,   478
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
  "alloc", "FREE", "'['", "'{'", "'}'", "';'", "','", "'('", "')'", "'.'",
  "']'", "$accept", "Program", "TypeDefBlock", "TypeDefList", "TypeDef",
  "FieldDeclList", "FieldDecl", "GdeclBlock", "GdeclList", "GDecl",
  "GidList", "Gid", "FdefBlock", "Fdef", "MainBlock", "ParamList", "Param",
  "LdeclBlock", "LDecList", "LDecl", "LidList", "Type", "Body", "Slist",
  "stmt", "input", "output", "asgn", "Free", "retstmt", "ifstmt",
  "whilestmt", "ArgList", "var", "expr", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,    91,   123,
     125,    59,    44,    40,    41,    46,    93
};
# endif

#define YYPACT_NINF -213

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-213)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     305,  -213,  -213,   228,  -213,   -39,    23,   254,     9,  -213,
      -4,  -213,   363,  -213,    22,   -12,    79,  -213,  -213,     9,
    -213,     9,  -213,  -213,    -5,    -9,  -213,  -213,    38,   -57,
    -213,     9,  -213,  -213,     9,  -213,  -213,  -213,    49,    34,
     126,  -213,    22,   225,  -213,    64,  -213,   153,    62,  -213,
      35,  -213,   102,  -213,  -213,  -213,   100,   107,    58,     2,
       9,  -213,  -213,  -213,     2,   125,   499,   356,   164,   127,
    -213,   164,   128,     2,  -213,   145,   146,   155,   156,   167,
     168,    16,   158,   499,  -213,   169,   172,   190,   192,   203,
     194,   198,    45,  -213,   478,  -213,   220,   174,  -213,   210,
    -213,   164,   212,   258,    16,    16,    16,  -213,  -213,  -213,
    -213,    16,   240,   472,   258,  -213,   269,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,    41,    16,   278,  -213,  -213,  -213,
     117,  -213,  -213,   224,  -213,   230,   283,   374,   307,   399,
     423,   448,    16,    16,    16,    16,    16,    16,    48,   114,
      16,    16,    16,    16,  -213,    -2,    16,    16,    16,    16,
      16,    16,    16,    16,    16,    16,    16,    16,  -213,   285,
    -213,  -213,   307,   563,    99,   186,  -213,  -213,   255,  -213,
    -213,  -213,  -213,   277,   282,  -213,   173,   189,   173,   189,
     261,    27,   261,    27,     0,   290,   262,  -213,  -213,     1,
     589,  -213,     1,   589,     1,   589,     1,   589,     1,   589,
       1,   589,  -213,   142,   216,   350,   173,   189,   173,   189,
     261,    27,   261,    27,     0,   290,   262,  -213,     1,   589,
       1,   589,     1,   589,     1,   589,     1,   589,     1,   589,
    -213,  -213,  -213,  -213,   545,   545,    16,  -213,    16,  -213,
      16,  -213,   488,   517,   307,   563,   307,   563,   307,   563,
     545,  -213,  -213,   537,  -213
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    43,    44,     0,    45,     0,     0,     0,     0,     7,
       0,    16,     0,    18,     0,     0,     0,    10,     1,     0,
       4,     0,    26,     6,     0,     0,    15,    17,    22,     0,
      21,     0,     8,     9,     0,     3,    25,     5,     0,     0,
       0,    19,     0,     0,    13,     0,     2,     0,     0,    24,
       0,    34,     0,    20,    11,    12,     0,     0,     0,     0,
       0,    23,    35,    14,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,    39,     0,     0,    32,     0,
      30,     0,     0,     0,     0,     0,     0,    56,    57,   135,
     136,     0,     0,     0,     0,    48,     0,    50,    51,    52,
      53,    47,    54,    55,     0,     0,     0,    36,    38,    42,
       0,    31,    28,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,     0,
      46,    63,    62,    61,     0,     0,    77,    40,     0,    27,
      58,    60,    59,     0,     0,    92,   117,    93,   118,    94,
     119,    95,   120,    96,   121,    97,   122,    98,   130,   128,
     104,   129,   127,   103,   124,   100,   126,   102,   123,    99,
     125,   101,   131,     0,     0,     0,   105,    80,   106,    81,
     107,    82,   108,    83,   109,    84,   110,    85,   116,    91,
     115,    90,   112,    87,   114,    89,   111,    86,   113,    88,
      64,    78,    79,    41,     0,     0,     0,   132,     0,   133,
       0,   134,     0,     0,    74,    75,    70,    72,    71,    73,
       0,    68,    69,     0,    67
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -213,  -213,  -213,  -213,   302,  -213,   279,   314,  -213,   318,
    -213,   297,   325,    -8,   321,   298,   292,   -49,  -213,   267,
    -213,   160,   -46,  -212,   -83,  -213,  -213,  -213,  -213,   280,
    -213,  -213,  -213,   -75,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,    16,    17,    43,    44,     8,    12,    13,
      29,    30,    21,    22,     9,    50,    51,    68,    94,    95,
     130,    24,    69,    83,    84,    85,    86,    87,    88,    89,
      90,    91,   213,    92,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     115,   109,   110,    74,    41,    42,   112,   142,   143,   144,
     145,   146,    15,    36,    66,    71,   147,   147,    72,   109,
     110,    74,    97,    18,   101,    99,    36,   102,   135,   136,
     138,   138,   252,   253,    25,    25,   138,   160,    67,   169,
      38,     1,     2,   161,   109,   110,    74,    31,   263,   172,
     174,   109,   110,    74,    39,   133,   124,     4,   125,   125,
      28,   111,   212,   155,   155,   126,   126,   186,   188,   190,
     192,   194,   196,   199,   202,   204,   206,   208,   210,   111,
     214,   216,   218,   220,   222,   224,   226,   228,   230,   232,
     234,   236,   238,   137,   139,   140,   171,    60,    48,    61,
     141,    40,   198,   125,   111,   142,   143,   144,   145,   146,
     126,   111,    47,   173,   175,   147,    56,   109,   110,    74,
      60,    59,    65,   148,   149,   150,   151,   152,   153,    32,
      15,   187,   189,   191,   193,   195,   197,   200,   203,   205,
     207,   209,   211,    62,   215,   217,   219,   221,   223,   225,
     227,   229,   231,   233,   235,   237,   239,   125,     1,     2,
      10,    63,   155,    14,   126,   241,    64,    10,   201,   115,
     115,   254,    14,   256,     4,   258,    66,   111,   177,   178,
     115,   144,   145,   146,    73,     1,     2,    98,   100,   147,
      49,    45,   156,   157,   158,   159,   160,   158,   159,   160,
      52,     4,   161,    45,   246,   161,   247,    52,   103,   104,
     162,   163,   164,   165,   166,   167,   121,    57,   105,   106,
      52,   114,   142,   143,   144,   145,   146,    96,   107,   108,
     117,   125,   147,   118,   131,   255,   155,   257,   126,   259,
     148,   149,   150,   151,   152,   153,   142,   143,   144,   145,
     146,   119,   242,   120,    96,   122,   147,     1,     2,   123,
       1,     2,   129,    74,   148,   149,   150,   151,   152,   153,
     132,   146,   134,     4,   125,    11,     4,   147,   248,   155,
     249,   126,   170,   176,   179,    54,     1,     2,   125,   142,
     143,   144,   145,   146,   180,   126,   244,   243,   125,   147,
       3,   154,     4,   155,   245,   126,   161,   148,   149,   150,
     151,   152,   153,   142,   143,   144,   145,   146,    33,   125,
     125,    19,    55,   147,   155,   155,   126,   126,    20,    23,
      27,   148,   149,   150,   151,   152,   153,     1,     2,    53,
      35,   125,    37,   125,    34,    58,   155,   181,   126,   240,
     126,     3,    70,     4,     5,    46,   156,   157,   158,   159,
     160,   128,     0,   116,     0,   125,   161,     0,     0,     0,
     155,     0,   126,     0,   162,   163,   164,   165,   166,   167,
     156,   157,   158,   159,   160,     0,     0,     0,     1,     2,
     161,     0,     0,    93,     0,     1,     2,     0,   162,   163,
     164,   165,   166,   167,     4,   156,   157,   158,   159,   160,
      26,     4,   250,     0,   251,   161,     0,     0,     0,     0,
       0,     0,     0,   162,   163,   164,   165,   166,   167,   156,
     157,   158,   159,   160,     0,     0,     0,     0,   182,   161,
       0,     0,     0,     0,     0,     0,     0,   162,   163,   164,
     165,   166,   167,     0,   156,   157,   158,   159,   160,     0,
       0,     0,     0,   183,   161,     0,     0,     0,     0,     0,
       0,     0,   162,   163,   164,   165,   166,   167,   156,   157,
     158,   159,   160,     0,     0,     0,     0,   184,   161,     0,
       0,     0,     0,    74,     0,     0,   162,   163,   164,   165,
     166,   167,    75,    76,    74,    77,   260,     0,   261,    78,
       1,     2,   185,    75,    76,   127,    77,     0,    79,    80,
      78,     0,    74,     0,     0,     0,     4,     0,     0,    79,
      80,    75,    76,   168,    77,     0,     0,     0,    78,    81,
     262,     0,    74,     0,     0,    82,     0,    79,    80,     0,
      74,    75,    76,     0,    77,     0,    82,   264,    78,    75,
      76,     0,    77,     0,     0,     0,    78,    79,    80,   156,
     157,   158,   159,   160,    82,    79,    80,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,   162,   163,   164,
     165,   166,   167,     0,    82,   156,   157,   158,   159,   160,
       0,     0,    82,     0,     0,   161
};

static const yytype_int16 yycheck[] =
{
      83,     3,     4,     5,    61,    62,    81,     6,     7,     8,
       9,    10,    51,    21,    12,    64,    16,    16,    64,     3,
       4,     5,    68,     0,    73,    71,    34,    73,   103,   104,
     105,   106,   244,   245,    39,    39,   111,    10,    36,   114,
      45,    32,    33,    16,     3,     4,     5,    59,   260,   124,
     125,     3,     4,     5,    63,   101,    11,    48,    58,    58,
      38,    63,    64,    63,    63,    65,    65,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    63,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   104,   105,   106,    55,    62,    64,    64,
     111,    63,    54,    58,    63,     6,     7,     8,     9,    10,
      65,    63,    63,   124,   125,    16,    52,     3,     4,     5,
      62,    59,    64,    24,    25,    26,    27,    28,    29,    50,
      51,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    41,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    58,    32,    33,
       0,    61,    63,     3,    65,    66,    59,     7,    54,   252,
     253,   246,    12,   248,    48,   250,    12,    63,    61,    62,
     263,     8,     9,    10,    59,    32,    33,    60,    60,    16,
      64,    31,     6,     7,     8,     9,    10,     8,     9,    10,
      40,    48,    16,    43,    62,    16,    64,    47,    63,    63,
      24,    25,    26,    27,    28,    29,    13,    64,    63,    63,
      60,    63,     6,     7,     8,     9,    10,    67,    61,    61,
      61,    58,    16,    61,    60,   246,    63,   248,    65,   250,
      24,    25,    26,    27,    28,    29,     6,     7,     8,     9,
      10,    61,    66,    61,    94,    61,    16,    32,    33,    61,
      32,    33,    42,     5,    24,    25,    26,    27,    28,    29,
      60,    10,    60,    48,    58,    47,    48,    16,    62,    63,
      64,    65,    13,     5,    60,    60,    32,    33,    58,     6,
       7,     8,     9,    10,    64,    65,    19,    42,    58,    16,
      46,    61,    48,    63,    22,    65,    16,    24,    25,    26,
      27,    28,    29,     6,     7,     8,     9,    10,    16,    58,
      58,     7,    43,    16,    63,    63,    65,    65,     7,     8,
      12,    24,    25,    26,    27,    28,    29,    32,    33,    42,
      19,    58,    21,    58,    19,    47,    63,    64,    65,    64,
      65,    46,    60,    48,    49,    34,     6,     7,     8,     9,
      10,    94,    -1,    83,    -1,    58,    16,    -1,    -1,    -1,
      63,    -1,    65,    -1,    24,    25,    26,    27,    28,    29,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    32,    33,
      16,    -1,    -1,    37,    -1,    32,    33,    -1,    24,    25,
      26,    27,    28,    29,    48,     6,     7,     8,     9,    10,
      47,    48,    62,    -1,    64,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    64,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    29,    -1,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    64,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    29,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    64,    16,    -1,
      -1,    -1,    -1,     5,    -1,    -1,    24,    25,    26,    27,
      28,    29,    14,    15,     5,    17,    18,    -1,    20,    21,
      32,    33,    64,    14,    15,    37,    17,    -1,    30,    31,
      21,    -1,     5,    -1,    -1,    -1,    48,    -1,    -1,    30,
      31,    14,    15,    61,    17,    -1,    -1,    -1,    21,    40,
      23,    -1,     5,    -1,    -1,    57,    -1,    30,    31,    -1,
       5,    14,    15,    -1,    17,    -1,    57,    20,    21,    14,
      15,    -1,    17,    -1,    -1,    -1,    21,    30,    31,     6,
       7,     8,     9,    10,    57,    30,    31,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    29,    -1,    57,     6,     7,     8,     9,    10,
      -1,    -1,    57,    -1,    -1,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    33,    46,    48,    49,    68,    69,    74,    81,
      88,    47,    75,    76,    88,    51,    70,    71,     0,    74,
      81,    79,    80,    81,    88,    39,    47,    76,    38,    77,
      78,    59,    50,    71,    79,    81,    80,    81,    45,    63,
      63,    61,    62,    72,    73,    88,    81,    63,    64,    64,
      82,    83,    88,    78,    60,    73,    52,    64,    82,    59,
      62,    64,    41,    61,    59,    64,    12,    36,    84,    89,
      83,    84,    89,    59,     5,    14,    15,    17,    21,    30,
      31,    40,    57,    90,    91,    92,    93,    94,    95,    96,
      97,    98,   100,    37,    85,    86,    88,    89,    60,    89,
      60,    84,    89,    63,    63,    63,    63,    61,    61,     3,
       4,    63,   100,   101,    63,    91,    96,    61,    61,    61,
      61,    13,    61,    61,    11,    58,    65,    37,    86,    42,
      87,    60,    60,    89,    60,   100,   100,   101,   100,   101,
     101,   101,     6,     7,     8,     9,    10,    16,    24,    25,
      26,    27,    28,    29,    61,    63,     6,     7,     8,     9,
      10,    16,    24,    25,    26,    27,    28,    29,    61,   100,
      13,    55,   100,   101,   100,   101,     5,    61,    62,    60,
      64,    64,    64,    64,    64,    64,   100,   101,   100,   101,
     100,   101,   100,   101,   100,   101,   100,   101,    54,   100,
     101,    54,   100,   101,   100,   101,   100,   101,   100,   101,
     100,   101,    64,    99,   100,   101,   100,   101,   100,   101,
     100,   101,   100,   101,   100,   101,   100,   101,   100,   101,
     100,   101,   100,   101,   100,   101,   100,   101,   100,   101,
      64,    66,    66,    42,    19,    22,    62,    64,    62,    64,
      62,    64,    90,    90,   100,   101,   100,   101,   100,   101,
      18,    20,    23,    90,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    68,    68,    68,    68,    69,    70,
      70,    71,    72,    72,    73,    74,    74,    75,    75,    76,
      77,    77,    78,    78,    78,    79,    79,    80,    80,    80,
      80,    81,    81,    82,    82,    83,    84,    84,    85,    85,
      86,    87,    87,    88,    88,    88,    89,    89,    90,    90,
      91,    91,    91,    91,    91,    91,    91,    91,    92,    93,
      93,    94,    94,    94,    95,    96,    96,    97,    97,    98,
      99,    99,    99,    99,    99,    99,   100,   100,   100,   100,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     2,     1,     3,     2,
       1,     4,     2,     1,     3,     3,     2,     2,     1,     3,
       3,     1,     1,     4,     3,     2,     1,     9,     8,     8,
       7,     8,     7,     3,     1,     2,     3,     2,     2,     1,
       3,     3,     1,     1,     1,     1,     4,     3,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     4,     4,
       4,     3,     3,     3,     4,     3,     3,     9,     7,     7,
       3,     3,     3,     3,     3,     3,     1,     3,     4,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     4,     4,     1,     1
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
#line 40 "expl.y"
    {printf("Program done\n");}
#line 1593 "y.tab.c"
    break;

  case 3:
#line 41 "expl.y"
    {printf("Program done\n");}
#line 1599 "y.tab.c"
    break;

  case 4:
#line 42 "expl.y"
    {printf("Program done\n");}
#line 1605 "y.tab.c"
    break;

  case 5:
#line 43 "expl.y"
    {printf("Program done\n");}
#line 1611 "y.tab.c"
    break;

  case 6:
#line 44 "expl.y"
    {printf("Program done\n");}
#line 1617 "y.tab.c"
    break;

  case 7:
#line 45 "expl.y"
    {printf("Program done\n");}
#line 1623 "y.tab.c"
    break;

  case 8:
#line 47 "expl.y"
    {(yyval.no)=(yyvsp[-2].no);tdisplay();printf("--------------------Typedec done--------------------\n");}
#line 1629 "y.tab.c"
    break;

  case 11:
#line 54 "expl.y"
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
#line 1644 "y.tab.c"
    break;

  case 14:
#line 70 "expl.y"
    {(yyval.fs)= newfield((yyvsp[-1].no)->varname,(yyvsp[-2].ts));}
#line 1650 "y.tab.c"
    break;

  case 15:
#line 74 "expl.y"
    {gdisplay();printf("--------------------Global done--------------------\n");(yyval.no)=(yyvsp[-2].no);}
#line 1656 "y.tab.c"
    break;

  case 19:
#line 79 "expl.y"
    {(yyval.gs)=(yyvsp[-1].gs);}
#line 1662 "y.tab.c"
    break;

  case 23:
#line 84 "expl.y"
    {(yyval.gs)= Appendgparam((yyvsp[-3].gs),(yyvsp[-1].pr));}
#line 1668 "y.tab.c"
    break;

  case 24:
#line 85 "expl.y"
    {(yyval.gs)= Appendgparam((yyvsp[-2].gs),NULL);}
#line 1674 "y.tab.c"
    break;

  case 27:
#line 92 "expl.y"
    {	
											struct Paramstruct *p=getparam((yyvsp[-7].no)->text);
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
											int f=getflabel((yyvsp[-7].no)->text);
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
											setlocalbinding((yyvsp[-5].pr),(yyvsp[-1].no)->Lentry);
											codegen((yyvsp[-1].no),fptr);
											fclose(fptr);
											k=-1;
											lvar=0;
											printf("-------------------function %s done------------------\n",(yyvsp[-7].no)->text);
										}
#line 1738 "y.tab.c"
    break;

  case 28:
#line 152 "expl.y"
    {
											struct Paramstruct *p=getparam((yyvsp[-6].no)->text);
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
											int f=getflabel((yyvsp[-6].no)->text);
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
											setlocalbinding(NULL,(yyvsp[-1].no)->Lentry);
											codegen((yyvsp[-1].no),fptr);
											fclose(fptr);
											k=-1;
											lvar=0;
											printf("-------------------function %s done------------------\n",(yyvsp[-6].no)->text);
										}
#line 1787 "y.tab.c"
    break;

  case 29:
#line 197 "expl.y"
    {
											struct Paramstruct *p=getparam((yyvsp[-6].no)->text);
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
											int f=getflabel((yyvsp[-6].no)->text);
											fprintf(fptr,"F%d:\n",f);
											func[f]=2*pos+2056;
											fprintf(fptr, "PUSH BP\n");pos++;
											fprintf(fptr, "MOV BP, SP\n");pos++;
											setlocalbinding((yyvsp[-4].pr),(yyvsp[-1].no)->Lentry);
											codegen((yyvsp[-1].no),fptr);
											fclose(fptr);
											k=-1;
											printf("-------------------function %s done------------------\n",(yyvsp[-6].no)->text);
										}
#line 1825 "y.tab.c"
    break;

  case 30:
#line 231 "expl.y"
    {
											struct Paramstruct *p=getparam((yyvsp[-5].no)->text);
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
											int f=getflabel((yyvsp[-5].no)->text);
											fprintf(fptr,"F%d:\n",f);
											func[f]=2*pos+2056;
											fprintf(fptr, "PUSH BP\n");pos++;
											fprintf(fptr, "MOV BP, SP\n");pos++;
											codegen((yyvsp[-1].no),fptr);
											fclose(fptr);
											k=-1;
											printf("-------------------function %s done------------------\n",(yyvsp[-5].no)->text);
										}
#line 1862 "y.tab.c"
    break;

  case 31:
#line 266 "expl.y"
    {
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
#line 1913 "y.tab.c"
    break;

  case 32:
#line 314 "expl.y"
    {
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
#line 1953 "y.tab.c"
    break;

  case 33:
#line 352 "expl.y"
    {(yyval.pr) = Appendparam((yyvsp[-2].pr),(yyvsp[0].pr));}
#line 1959 "y.tab.c"
    break;

  case 34:
#line 353 "expl.y"
    {(yyval.pr) = (yyvsp[0].pr);}
#line 1965 "y.tab.c"
    break;

  case 35:
#line 356 "expl.y"
    {(yyval.pr)=(yyvsp[0].pr);}
#line 1971 "y.tab.c"
    break;

  case 40:
#line 363 "expl.y"
    {(yyval.ls)=(yyvsp[-1].ls);}
#line 1977 "y.tab.c"
    break;

  case 46:
#line 374 "expl.y"
    {(yyval.no)=makenode("filledlater",12,NULL,NULL,(yyvsp[-2].no),NULL,(yyvsp[-1].no));}
#line 1983 "y.tab.c"
    break;

  case 47:
#line 375 "expl.y"
    {printf("Nothing inside body\n");exit(1);}
#line 1989 "y.tab.c"
    break;

  case 48:
#line 378 "expl.y"
    {(yyval.no) = makenode("connector",3,NULL,NULL,(yyvsp[-1].no),NULL,(yyvsp[0].no));}
#line 1995 "y.tab.c"
    break;

  case 56:
#line 383 "expl.y"
    {(yyval.no)=(yyvsp[-1].no);}
#line 2001 "y.tab.c"
    break;

  case 57:
#line 384 "expl.y"
    {(yyval.no)=(yyvsp[-1].no);}
#line 2007 "y.tab.c"
    break;

  case 58:
#line 386 "expl.y"
    {(yyval.no) = makenode("read",1,NULL,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2013 "y.tab.c"
    break;

  case 59:
#line 388 "expl.y"
    {(yyval.no) = makenode("write",2,NULL,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2019 "y.tab.c"
    break;

  case 60:
#line 389 "expl.y"
    {/*if($3->type!=tint || $3->type!=tstr) {printf("Can only write integer/String\n");exit(1);}*/(yyval.no) = makenode("write",2,NULL,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2025 "y.tab.c"
    break;

  case 61:
#line 391 "expl.y"
    {(yyval.no) = makenode("=",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2031 "y.tab.c"
    break;

  case 62:
#line 392 "expl.y"
    {(yyval.no) = makenode("=",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2037 "y.tab.c"
    break;

  case 63:
#line 393 "expl.y"
    {(yyval.no) = makenode("=",14,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2043 "y.tab.c"
    break;

  case 64:
#line 396 "expl.y"
    {(yyval.no) = makenode("free",14,tint,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2049 "y.tab.c"
    break;

  case 65:
#line 398 "expl.y"
    {(yyval.no) = makenode("return",11,NULL,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2055 "y.tab.c"
    break;

  case 66:
#line 399 "expl.y"
    {(yyval.no) = makenode("return",11,NULL,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 2061 "y.tab.c"
    break;

  case 67:
#line 401 "expl.y"
    {(yyval.no)= makenode("ifelse",6,NULL,NULL,(yyvsp[-6].no),(yyvsp[-3].no),(yyvsp[-1].no));}
#line 2067 "y.tab.c"
    break;

  case 68:
#line 402 "expl.y"
    {(yyval.no)= makenode("if",6,NULL,NULL,(yyvsp[-4].no),(yyvsp[-1].no),NULL);}
#line 2073 "y.tab.c"
    break;

  case 69:
#line 404 "expl.y"
    {(yyval.no)= makenode("while",5,NULL,NULL,(yyvsp[-4].no),NULL,(yyvsp[-1].no));}
#line 2079 "y.tab.c"
    break;

  case 70:
#line 406 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2085 "y.tab.c"
    break;

  case 71:
#line 407 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2091 "y.tab.c"
    break;

  case 72:
#line 408 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2097 "y.tab.c"
    break;

  case 73:
#line 409 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2103 "y.tab.c"
    break;

  case 74:
#line 410 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2109 "y.tab.c"
    break;

  case 75:
#line 411 "expl.y"
    {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2115 "y.tab.c"
    break;

  case 77:
#line 414 "expl.y"
    {(yyval.no) = fieldconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 2121 "y.tab.c"
    break;

  case 78:
#line 415 "expl.y"
    {(yyval.no) = makearraynode((yyvsp[-3].no)->varname,(yyvsp[-3].no)->type,(yyvsp[-1].no));}
#line 2127 "y.tab.c"
    break;

  case 79:
#line 416 "expl.y"
    {(yyval.no) = makearraynode((yyvsp[-3].no)->varname,(yyvsp[-3].no)->type,(yyvsp[-1].no));}
#line 2133 "y.tab.c"
    break;

  case 80:
#line 418 "expl.y"
    {(yyval.no) = makenode("+",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2139 "y.tab.c"
    break;

  case 81:
#line 419 "expl.y"
    {(yyval.no) = makenode("-",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2145 "y.tab.c"
    break;

  case 82:
#line 420 "expl.y"
    {(yyval.no) = makenode("*",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2151 "y.tab.c"
    break;

  case 83:
#line 421 "expl.y"
    {(yyval.no) = makenode("/",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2157 "y.tab.c"
    break;

  case 84:
#line 422 "expl.y"
    {(yyval.no) = makenode("%",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2163 "y.tab.c"
    break;

  case 85:
#line 423 "expl.y"
    {(yyval.no) = makenode("@",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2169 "y.tab.c"
    break;

  case 86:
#line 424 "expl.y"
    {(yyval.no) = makenode("<",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2175 "y.tab.c"
    break;

  case 87:
#line 425 "expl.y"
    {(yyval.no) = makenode(">",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2181 "y.tab.c"
    break;

  case 88:
#line 426 "expl.y"
    {(yyval.no) = makenode("<=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2187 "y.tab.c"
    break;

  case 89:
#line 427 "expl.y"
    {(yyval.no) = makenode(">=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2193 "y.tab.c"
    break;

  case 90:
#line 428 "expl.y"
    {(yyval.no) = makenode("!=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2199 "y.tab.c"
    break;

  case 91:
#line 429 "expl.y"
    {(yyval.no) = makenode("==",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2205 "y.tab.c"
    break;

  case 92:
#line 430 "expl.y"
    {(yyval.no) = (yyvsp[-1].no);}
#line 2211 "y.tab.c"
    break;

  case 93:
#line 431 "expl.y"
    {(yyval.no) = makenode("+",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2217 "y.tab.c"
    break;

  case 94:
#line 432 "expl.y"
    {(yyval.no) = makenode("-",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2223 "y.tab.c"
    break;

  case 95:
#line 433 "expl.y"
    {(yyval.no) = makenode("*",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2229 "y.tab.c"
    break;

  case 96:
#line 434 "expl.y"
    {(yyval.no) = makenode("/",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2235 "y.tab.c"
    break;

  case 97:
#line 435 "expl.y"
    {(yyval.no) = makenode("%",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2241 "y.tab.c"
    break;

  case 98:
#line 436 "expl.y"
    {(yyval.no) = makenode("@",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2247 "y.tab.c"
    break;

  case 99:
#line 437 "expl.y"
    {(yyval.no) = makenode("<",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2253 "y.tab.c"
    break;

  case 100:
#line 438 "expl.y"
    {(yyval.no) = makenode(">",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2259 "y.tab.c"
    break;

  case 101:
#line 439 "expl.y"
    {(yyval.no) = makenode("<=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2265 "y.tab.c"
    break;

  case 102:
#line 440 "expl.y"
    {(yyval.no) = makenode(">=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2271 "y.tab.c"
    break;

  case 103:
#line 441 "expl.y"
    {(yyval.no) = makenode("!=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2277 "y.tab.c"
    break;

  case 104:
#line 442 "expl.y"
    {(yyval.no) = makenode("==",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2283 "y.tab.c"
    break;

  case 105:
#line 444 "expl.y"
    {(yyval.no) = makenode("+",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2289 "y.tab.c"
    break;

  case 106:
#line 445 "expl.y"
    {(yyval.no) = makenode("-",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2295 "y.tab.c"
    break;

  case 107:
#line 446 "expl.y"
    {(yyval.no) = makenode("*",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2301 "y.tab.c"
    break;

  case 108:
#line 447 "expl.y"
    {(yyval.no) = makenode("/",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2307 "y.tab.c"
    break;

  case 109:
#line 448 "expl.y"
    {(yyval.no) = makenode("%",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2313 "y.tab.c"
    break;

  case 110:
#line 449 "expl.y"
    {(yyval.no) = makenode("@",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2319 "y.tab.c"
    break;

  case 111:
#line 450 "expl.y"
    {(yyval.no) = makenode("<",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2325 "y.tab.c"
    break;

  case 112:
#line 451 "expl.y"
    {(yyval.no) = makenode(">",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2331 "y.tab.c"
    break;

  case 113:
#line 452 "expl.y"
    {(yyval.no) = makenode("<=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2337 "y.tab.c"
    break;

  case 114:
#line 453 "expl.y"
    {(yyval.no) = makenode(">=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2343 "y.tab.c"
    break;

  case 115:
#line 454 "expl.y"
    {(yyval.no) = makenode("!=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2349 "y.tab.c"
    break;

  case 116:
#line 455 "expl.y"
    {(yyval.no) = makenode("==",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2355 "y.tab.c"
    break;

  case 117:
#line 457 "expl.y"
    {(yyval.no) = makenode("+",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2361 "y.tab.c"
    break;

  case 118:
#line 458 "expl.y"
    {(yyval.no) = makenode("-",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2367 "y.tab.c"
    break;

  case 119:
#line 459 "expl.y"
    {(yyval.no) = makenode("*",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2373 "y.tab.c"
    break;

  case 120:
#line 460 "expl.y"
    {(yyval.no) = makenode("/",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2379 "y.tab.c"
    break;

  case 121:
#line 461 "expl.y"
    {(yyval.no) = makenode("%",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2385 "y.tab.c"
    break;

  case 122:
#line 462 "expl.y"
    {(yyval.no) = makenode("@",4,tint,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2391 "y.tab.c"
    break;

  case 123:
#line 463 "expl.y"
    {(yyval.no) = makenode("<",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2397 "y.tab.c"
    break;

  case 124:
#line 464 "expl.y"
    {(yyval.no) = makenode(">",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2403 "y.tab.c"
    break;

  case 125:
#line 465 "expl.y"
    {(yyval.no) = makenode("<=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2409 "y.tab.c"
    break;

  case 126:
#line 466 "expl.y"
    {(yyval.no) = makenode(">=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2415 "y.tab.c"
    break;

  case 127:
#line 467 "expl.y"
    {(yyval.no) = makenode("!=",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2421 "y.tab.c"
    break;

  case 128:
#line 468 "expl.y"
    {(yyval.no) = makenode("==",4,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2427 "y.tab.c"
    break;

  case 129:
#line 470 "expl.y"
    {(yyval.no) = makenode("!=",14,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2433 "y.tab.c"
    break;

  case 130:
#line 471 "expl.y"
    {(yyval.no) = makenode("==",14,tbool,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2439 "y.tab.c"
    break;

  case 131:
#line 473 "expl.y"
    {(yyval.no) = makenode((yyvsp[-2].no)->varname,10,(yyvsp[-2].no)->type,NULL,NULL,NULL,NULL);}
#line 2445 "y.tab.c"
    break;

  case 132:
#line 474 "expl.y"
    {(yyval.no) = makenode((yyvsp[-3].no)->varname,10,(yyvsp[-3].no)->type,(yyvsp[-1].no),NULL,NULL,NULL);}
#line 2451 "y.tab.c"
    break;

  case 133:
#line 475 "expl.y"
    {(yyval.no) = makenode((yyvsp[-3].no)->varname,10,(yyvsp[-3].no)->type,(yyvsp[-1].no),NULL,NULL,NULL);}
#line 2457 "y.tab.c"
    break;

  case 134:
#line 476 "expl.y"
    {(yyval.no) = makenode((yyvsp[-3].no)->varname,10,(yyvsp[-3].no)->type,(yyvsp[-1].no),NULL,NULL,NULL);}
#line 2463 "y.tab.c"
    break;

  case 135:
#line 477 "expl.y"
    {(yyval.no) = (yyvsp[0].no);}
#line 2469 "y.tab.c"
    break;

  case 136:
#line 478 "expl.y"
    {(yyval.no) = (yyvsp[0].no);}
#line 2475 "y.tab.c"
    break;


#line 2479 "y.tab.c"

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
#line 481 "expl.y"


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
	tstr=tLookup("str");
	yyparse();	
	return 0;
}
