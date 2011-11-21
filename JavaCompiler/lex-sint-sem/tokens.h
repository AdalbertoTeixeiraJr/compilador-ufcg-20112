
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CLASS = 258,
     BEG = 259,
     END = 260,
     STATIC = 261,
     PT_VIRGULA = 262,
     OPEN_COLC = 263,
     CLOSE_COLC = 264,
     VIRGULA = 265,
     POINT = 266,
     QUESTION_MARK = 267,
     TWO_POINTS = 268,
     OR_LOGIC = 269,
     AND_LOGIC = 270,
     OPEN_PAREN = 271,
     CLOSE_PAREN = 272,
     NEW = 273,
     OR = 274,
     OR_EXC = 275,
     AND = 276,
     PLUS = 277,
     MINUS = 278,
     MULT = 279,
     DIV = 280,
     MOD = 281,
     INCREMENT = 282,
     DECREMENT = 283,
     NOT = 284,
     NOT_BIT = 285,
     FOR = 286,
     IF = 287,
     ELSE = 288,
     WHILE = 289,
     CASE = 290,
     SWITCH = 291,
     DEFAULT = 292,
     DO = 293,
     BREAK = 294,
     CONTINUE = 295,
     GOTO = 296,
     RETURN = 297,
     MAIN = 298,
     ARGS = 299,
     PUBLIC = 300,
     FINAL = 301,
     EQUALOP = 302,
     EQUAL = 303,
     RELOP = 304,
     SHIFTS = 305,
     SHIFT_ASSIGN = 306,
     ARITH_ASSIGN = 307,
     LOGIC_ASSIGN = 308,
     ID = 309,
     TYPE_INT = 310,
     TYPE_SHORT = 311,
     TYPE_LONG = 312,
     TYPE_BYTE = 313,
     TYPE_BOOL = 314,
     TYPE_FLOAT = 315,
     TYPE_DOUBLE = 316,
     TYPE_CHAR = 317,
     TYPE_STRING = 318,
     VOID = 319,
     LITERAL = 320
   };
#endif
/* Tokens.  */
#define CLASS 258
#define BEG 259
#define END 260
#define STATIC 261
#define PT_VIRGULA 262
#define OPEN_COLC 263
#define CLOSE_COLC 264
#define VIRGULA 265
#define POINT 266
#define QUESTION_MARK 267
#define TWO_POINTS 268
#define OR_LOGIC 269
#define AND_LOGIC 270
#define OPEN_PAREN 271
#define CLOSE_PAREN 272
#define NEW 273
#define OR 274
#define OR_EXC 275
#define AND 276
#define PLUS 277
#define MINUS 278
#define MULT 279
#define DIV 280
#define MOD 281
#define INCREMENT 282
#define DECREMENT 283
#define NOT 284
#define NOT_BIT 285
#define FOR 286
#define IF 287
#define ELSE 288
#define WHILE 289
#define CASE 290
#define SWITCH 291
#define DEFAULT 292
#define DO 293
#define BREAK 294
#define CONTINUE 295
#define GOTO 296
#define RETURN 297
#define MAIN 298
#define ARGS 299
#define PUBLIC 300
#define FINAL 301
#define EQUALOP 302
#define EQUAL 303
#define RELOP 304
#define SHIFTS 305
#define SHIFT_ASSIGN 306
#define ARITH_ASSIGN 307
#define LOGIC_ASSIGN 308
#define ID 309
#define TYPE_INT 310
#define TYPE_SHORT 311
#define TYPE_LONG 312
#define TYPE_BYTE 313
#define TYPE_BOOL 314
#define TYPE_FLOAT 315
#define TYPE_DOUBLE 316
#define TYPE_CHAR 317
#define TYPE_STRING 318
#define VOID 319
#define LITERAL 320




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 51 "sintatico.y"

        char* strval;
	char* typeval;
	int isFinal;
	int levels;



/* Line 1676 of yacc.c  */
#line 191 "tokens.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


