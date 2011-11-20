
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
     EQUAL = 265,
     VIRGULA = 266,
     POINT = 267,
     QUESTION_MARK = 268,
     TWO_POINTS = 269,
     OR_LOGIC = 270,
     AND_LOGIC = 271,
     OPEN_PAREN = 272,
     CLOSE_PAREN = 273,
     NEW = 274,
     OR = 275,
     OR_EXC = 276,
     AND = 277,
     PLUS = 278,
     MINUS = 279,
     MULT = 280,
     DIV = 281,
     MOD = 282,
     INCREMENT = 283,
     DECREMENT = 284,
     NOT = 285,
     NOT_BIT = 286,
     FOR = 287,
     IF = 288,
     ELSE = 289,
     WHILE = 290,
     CASE = 291,
     SWITCH = 292,
     DEFAULT = 293,
     DO = 294,
     BREAK = 295,
     CONTINUE = 296,
     GOTO = 297,
     RETURN = 298,
     MAIN = 299,
     ARGS = 300,
     PUBLIC = 301,
     FINAL = 302,
     EQUALOP = 303,
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
#define EQUAL 265
#define VIRGULA 266
#define POINT 267
#define QUESTION_MARK 268
#define TWO_POINTS 269
#define OR_LOGIC 270
#define AND_LOGIC 271
#define OPEN_PAREN 272
#define CLOSE_PAREN 273
#define NEW 274
#define OR 275
#define OR_EXC 276
#define AND 277
#define PLUS 278
#define MINUS 279
#define MULT 280
#define DIV 281
#define MOD 282
#define INCREMENT 283
#define DECREMENT 284
#define NOT 285
#define NOT_BIT 286
#define FOR 287
#define IF 288
#define ELSE 289
#define WHILE 290
#define CASE 291
#define SWITCH 292
#define DEFAULT 293
#define DO 294
#define BREAK 295
#define CONTINUE 296
#define GOTO 297
#define RETURN 298
#define MAIN 299
#define ARGS 300
#define PUBLIC 301
#define FINAL 302
#define EQUALOP 303
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
#line 49 "sintatico.y"

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


