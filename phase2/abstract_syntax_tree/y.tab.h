/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
    ID = 258,
    NUM = 259,
    T_lt = 260,
    T_gt = 261,
    COMMA = 262,
    STRC = 263,
    TERMINATOR = 264,
    RETURN = 265,
    FLT = 266,
    T_lteq = 267,
    T_gteq = 268,
    T_neq = 269,
    T_eqeq = 270,
    T_pl = 271,
    S_min = 272,
    S_mul = 273,
    S_add = 274,
    S_div = 275,
    T_min = 276,
    T_mul = 277,
    T_div = 278,
    T_and = 279,
    T_or = 280,
    T_incr = 281,
    T_decr = 282,
    T_not = 283,
    T_eq = 284,
    WHILE = 285,
    INT = 286,
    CHAR = 287,
    FLOAT = 288,
    VOID = 289,
    H = 290,
    MAINTOK = 291,
    INCLUDE = 292,
    BREAK = 293,
    CONTINUE = 294,
    IF = 295,
    ELSE = 296,
    COUT = 297,
    STRING = 298,
    FOR = 299,
    OB = 300,
    CB = 301,
    OBR = 302,
    CBR = 303,
    ENDL = 304
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define T_lt 260
#define T_gt 261
#define COMMA 262
#define STRC 263
#define TERMINATOR 264
#define RETURN 265
#define FLT 266
#define T_lteq 267
#define T_gteq 268
#define T_neq 269
#define T_eqeq 270
#define T_pl 271
#define S_min 272
#define S_mul 273
#define S_add 274
#define S_div 275
#define T_min 276
#define T_mul 277
#define T_div 278
#define T_and 279
#define T_or 280
#define T_incr 281
#define T_decr 282
#define T_not 283
#define T_eq 284
#define WHILE 285
#define INT 286
#define CHAR 287
#define FLOAT 288
#define VOID 289
#define H 290
#define MAINTOK 291
#define INCLUDE 292
#define BREAK 293
#define CONTINUE 294
#define IF 295
#define ELSE 296
#define COUT 297
#define STRING 298
#define FOR 299
#define OB 300
#define CB 301
#define OBR 302
#define CBR 303
#define ENDL 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
