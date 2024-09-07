/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    FLOAT_NUM = 259,               /* FLOAT_NUM  */
    ID = 260,                      /* ID  */
    CHARACTER = 261,               /* CHARACTER  */
    INT = 262,                     /* INT  */
    FLOAT = 263,                   /* FLOAT  */
    CHAR = 264,                    /* CHAR  */
    VOID = 265,                    /* VOID  */
    RETURN = 266,                  /* RETURN  */
    FOR = 267,                     /* FOR  */
    WHILE = 268,                   /* WHILE  */
    IF = 269,                      /* IF  */
    ELSE = 270,                    /* ELSE  */
    LT = 271,                      /* LT  */
    GT = 272,                      /* GT  */
    LE = 273,                      /* LE  */
    GE = 274,                      /* GE  */
    EQ = 275,                      /* EQ  */
    NE = 276,                      /* NE  */
    AND = 277,                     /* AND  */
    OR = 278,                      /* OR  */
    ADD = 279,                     /* ADD  */
    SUB = 280,                     /* SUB  */
    DIV = 281,                     /* DIV  */
    MUL = 282,                     /* MUL  */
    TRUE = 283,                    /* TRUE  */
    FALSE = 284,                   /* FALSE  */
    PUTCHAR = 285                  /* PUTCHAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUMBER 258
#define FLOAT_NUM 259
#define ID 260
#define CHARACTER 261
#define INT 262
#define FLOAT 263
#define CHAR 264
#define VOID 265
#define RETURN 266
#define FOR 267
#define WHILE 268
#define IF 269
#define ELSE 270
#define LT 271
#define GT 272
#define LE 273
#define GE 274
#define EQ 275
#define NE 276
#define AND 277
#define OR 278
#define ADD 279
#define SUB 280
#define DIV 281
#define MUL 282
#define TRUE 283
#define FALSE 284
#define PUTCHAR 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "parser.y"

    int number;
    float float_num;
    char *string;
    char character;

#line 134 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
