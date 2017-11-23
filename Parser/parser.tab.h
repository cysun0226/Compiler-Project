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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    AND = 258,
    ARRAY = 259,
    CASE = 260,
    CONST = 261,
    DIV = 262,
    DO = 263,
    DOWNTO = 264,
    ELSE = 265,
    END = 266,
    EXTERNAL = 267,
    FOR = 268,
    FORWARD = 269,
    FUNCTION = 270,
    GOTO = 271,
    IF = 272,
    IN = 273,
    INTEGER = 274,
    LABEL = 275,
    MOD = 276,
    NIL = 277,
    NOT = 278,
    OF = 279,
    OR = 280,
    OTHERWISE = 281,
    PACKED = 282,
    PBEGIN = 283,
    PFILE = 284,
    PROCEDURE = 285,
    PROGRAM = 286,
    RECORD = 287,
    REPEAT = 288,
    SET = 289,
    THEN = 290,
    TO = 291,
    TYPE = 292,
    UNTIL = 293,
    VAR = 294,
    WHILE = 295,
    WITH = 296,
    REAL = 297,
    id = 298,
    ASSIGNMENT = 299,
    CHARACTER_STRING = 300,
    COLON = 301,
    COMMA = 302,
    DIGSEQ = 303,
    DOT = 304,
    DOTDOT = 305,
    EQUAL = 306,
    GE = 307,
    GT = 308,
    LBRAC = 309,
    LE = 310,
    LPAREN = 311,
    LT = 312,
    MINUS = 313,
    PLUS = 314,
    RBRAC = 315,
    REALNUMBER = 316,
    RPAREN = 317,
    SEMICOLON = 318,
    SLASH = 319,
    STAR = 320,
    STARSTAR = 321,
    notEQUAL = 322,
    NUM = 323,
    REAL_NUM = 324
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 37 "parser.y" /* yacc.c:1909  */

    struct Node* node;
    int number;
    char* string;

#line 130 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
