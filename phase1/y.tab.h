/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
