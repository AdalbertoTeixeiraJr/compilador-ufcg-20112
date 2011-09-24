
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
     IF = 258,
     ELSE = 259,
     WHILE = 260,
     OPEN_PAREN = 261,
     CLOSE_PAREN = 262,
     TYPE_INT = 263,
     TYPE_SHORT = 264,
     TYPE_LONG = 265,
     TYPE_BYTE = 266,
     TYPE_BOOL = 267,
     TYPE_FLOAT = 268,
     TYPE_DOUBLE = 269,
     TYPE_CHAR = 270,
     TYPE_STRING = 271,
     PT_VIRGULA = 272,
     VIRGULA = 273,
     EQUAL = 274,
     MULT = 275,
     DIV = 276,
     MOD = 277,
     PLUS = 278,
     MINUS = 279,
     TWO_POINTS = 280,
     OR_EXC = 281,
     AND = 282,
     OR = 283,
     OR_LOGIC = 284,
     AND_LOGIC = 285,
     INCREMENT = 286,
     DECREMENT = 287,
     NOT = 288,
     NOT_BIT = 289,
     POINT = 290,
     NEW = 291,
     OPEN_COLC = 292,
     CLOSE_COLC = 293,
     BEG = 294,
     END = 295,
     GOTO = 296,
     QUESTION_MARK = 297,
     BREAK = 298,
     CASE = 299,
     CLASS = 300,
     CONTINUE = 301,
     DEFAULT = 302,
     DO = 303,
     FINAL = 304,
     FOR = 305,
     RETURN = 306,
     STATIC = 307,
     TRANSIENT = 308,
     VOLATILE = 309,
     SWITCH = 310,
     VOID = 311,
     LITERAL = 312,
     EQUALOP = 313,
     RELOP = 314,
     ID = 315,
     SHIFTS = 316,
     SHIFT_ASSIGN = 317,
     ARITH_ASSIGN = 318,
     LOGIC_ASSIGN = 319
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define WHILE 260
#define OPEN_PAREN 261
#define CLOSE_PAREN 262
#define TYPE_INT 263
#define TYPE_SHORT 264
#define TYPE_LONG 265
#define TYPE_BYTE 266
#define TYPE_BOOL 267
#define TYPE_FLOAT 268
#define TYPE_DOUBLE 269
#define TYPE_CHAR 270
#define TYPE_STRING 271
#define PT_VIRGULA 272
#define VIRGULA 273
#define EQUAL 274
#define MULT 275
#define DIV 276
#define MOD 277
#define PLUS 278
#define MINUS 279
#define TWO_POINTS 280
#define OR_EXC 281
#define AND 282
#define OR 283
#define OR_LOGIC 284
#define AND_LOGIC 285
#define INCREMENT 286
#define DECREMENT 287
#define NOT 288
#define NOT_BIT 289
#define POINT 290
#define NEW 291
#define OPEN_COLC 292
#define CLOSE_COLC 293
#define BEG 294
#define END 295
#define GOTO 296
#define QUESTION_MARK 297
#define BREAK 298
#define CASE 299
#define CLASS 300
#define CONTINUE 301
#define DEFAULT 302
#define DO 303
#define FINAL 304
#define FOR 305
#define RETURN 306
#define STATIC 307
#define TRANSIENT 308
#define VOLATILE 309
#define SWITCH 310
#define VOID 311
#define LITERAL 312
#define EQUALOP 313
#define RELOP 314
#define ID 315
#define SHIFTS 316
#define SHIFT_ASSIGN 317
#define ARITH_ASSIGN 318
#define LOGIC_ASSIGN 319




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 23 "sintatico.y"

        char* strval;



/* Line 1676 of yacc.c  */
#line 186 "tk.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


