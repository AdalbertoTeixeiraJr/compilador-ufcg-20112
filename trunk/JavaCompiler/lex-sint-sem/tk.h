/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     TYPE_INT = 268,
     TYPE_SHORT = 269,
     TYPE_LONG = 270,
     TYPE_BYTE = 271,
     TYPE_BOOL = 272,
     TYPE_FLOAT = 273,
     TYPE_DOUBLE = 274,
     TYPE_CHAR = 275,
     TYPE_STRING = 276,
     QUESTION_MARK = 277,
     TWO_POINTS = 278,
     OR_LOGIC = 279,
     AND_LOGIC = 280,
     OPEN_PAREN = 281,
     CLOSE_PAREN = 282,
     NEW = 283,
     OR = 284,
     OR_EXC = 285,
     AND = 286,
     PLUS = 287,
     MINUS = 288,
     MULT = 289,
     DIV = 290,
     MOD = 291,
     INCREMENT = 292,
     DECREMENT = 293,
     NOT = 294,
     NOT_BIT = 295,
     FOR = 296,
     IF = 297,
     ELSE = 298,
     WHILE = 299,
     CASE = 300,
     SWITCH = 301,
     DEFAULT = 302,
     DO = 303,
     BREAK = 304,
     CONTINUE = 305,
     GOTO = 306,
     RETURN = 307,
     VOID = 308,
     MAIN = 309,
     ARGS = 310,
     PUBLIC = 311,
     FINAL = 312,
     TRANSIENT = 313,
     VOLATILE = 314,
     ID = 315,
     SHIFT_ASSIGN = 316,
     ARITH_ASSIGN = 317,
     LOGIC_ASSIGN = 318,
     LITERAL = 319,
     EQUALOP = 320,
     RELOP = 321,
     SHIFTS = 322
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
#define TYPE_INT 268
#define TYPE_SHORT 269
#define TYPE_LONG 270
#define TYPE_BYTE 271
#define TYPE_BOOL 272
#define TYPE_FLOAT 273
#define TYPE_DOUBLE 274
#define TYPE_CHAR 275
#define TYPE_STRING 276
#define QUESTION_MARK 277
#define TWO_POINTS 278
#define OR_LOGIC 279
#define AND_LOGIC 280
#define OPEN_PAREN 281
#define CLOSE_PAREN 282
#define NEW 283
#define OR 284
#define OR_EXC 285
#define AND 286
#define PLUS 287
#define MINUS 288
#define MULT 289
#define DIV 290
#define MOD 291
#define INCREMENT 292
#define DECREMENT 293
#define NOT 294
#define NOT_BIT 295
#define FOR 296
#define IF 297
#define ELSE 298
#define WHILE 299
#define CASE 300
#define SWITCH 301
#define DEFAULT 302
#define DO 303
#define BREAK 304
#define CONTINUE 305
#define GOTO 306
#define RETURN 307
#define VOID 308
#define MAIN 309
#define ARGS 310
#define PUBLIC 311
#define FINAL 312
#define TRANSIENT 313
#define VOLATILE 314
#define ID 315
#define SHIFT_ASSIGN 316
#define ARITH_ASSIGN 317
#define LOGIC_ASSIGN 318
#define LITERAL 319
#define EQUALOP 320
#define RELOP 321
#define SHIFTS 322




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "sintatico.y"
{
        char* strval;
}
/* Line 1529 of yacc.c.  */
#line 187 "tk.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

