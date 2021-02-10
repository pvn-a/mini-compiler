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
    T_min = 272,
    T_mul = 273,
    T_div = 274,
    T_and = 275,
    T_or = 276,
    T_incr = 277,
    T_decr = 278,
    T_not = 279,
    T_eq = 280,
    WHILE = 281,
    INT = 282,
    CHAR = 283,
    FLOAT = 284,
    VOID = 285,
    H = 286,
    MAINTOK = 287,
    INCLUDE = 288,
    BREAK = 289,
    CONTINUE = 290,
    IF = 291,
    ELSE = 292,
    COUT = 293,
    STRING = 294,
    FOR = 295,
    OB = 296,
    CB = 297,
    OBR = 298,
    CBR = 299,
    ENDL = 300,
    CHARACTER = 301,
    str_ins = 302,
    str_extr = 303
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
#define T_min 272
#define T_mul 273
#define T_div 274
#define T_and 275
#define T_or 276
#define T_incr 277
#define T_decr 278
#define T_not 279
#define T_eq 280
#define WHILE 281
#define INT 282
#define CHAR 283
#define FLOAT 284
#define VOID 285
#define H 286
#define MAINTOK 287
#define INCLUDE 288
#define BREAK 289
#define CONTINUE 290
#define IF 291
#define ELSE 292
#define COUT 293
#define STRING 294
#define FOR 295
#define OB 296
#define CB 297
#define OBR 298
#define CBR 299
#define ENDL 300
#define CHARACTER 301
#define str_ins 302
#define str_extr 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
