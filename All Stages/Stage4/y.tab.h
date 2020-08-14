/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 135 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
