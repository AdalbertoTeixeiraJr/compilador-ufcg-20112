/*
** Projeto Compiladores - 2011.2 **
** UFCG - DSC			 		 **	
** Prof.: Franklin Ramalho	 	 **
** Equipe:			 			 **
**	Adalberto Teixeira	 		 **
**	Andrey Menezes		 		 **
** 	Augusto Macedo		 		 **
** Ling. Fonte: Java		 	 **
*/

%{
#include "tk.h"
#include "tkvalues.h"
#include <string.h>
extern int column; // carrega do sintatico
extern int line; // carrega do sintatico
extern char* yytext;
void moveCol();
void moveLine();
%}

col_delimit	[ \r\t]
line_delimit	[\n]
id              {letter_no_digit}+({letter})*
letter          [A-Za-z_0-9]
letter_no_digit [A-Za-z_]
digit		[0-9]
non_zero_digit	[1-9]
int_literal	{signal}?{non_zero_digit}+{digit}*{int_type_suf}?
int_type_suf	[lL]
signal 		[+-]
float_literal	{signal}?{digit}+.{digit}+{exp_indicator}?{float_sufix}?{digit}+{exp_indicator}?{float_sufix}?
double_literal	{signal}?{digit}+.{digit}+{exp_indicator}?{double_sufix}?{digit}+{exp_indicator}?{double_sufix}? 
exp_indicator	[eE]
float_sufix	[fF]
double_sufix	[dDfF]
hex_literal	0{hex_id}{hex_digit}*
hex_id		[xX]
hex_digit	[0-9A-F]
oct_literal	0{oct_digit}*
oct_digit	[0-7]
equal_oper	"=="|"!="
arith_assig	"*="|"/="|"+="|"-="|"%="				/* FALTA */
shift_assig	"<<="|">>="|">>>="					/* FALTA */
rel_oper	"<"|">"|"<="|">="|"instanceof"
shifts		"<<"|">>"|">>>"
logic_assig	"&="|"^="|"|="		
char_literal	['][^']{1}[']
string_literal	["][^"]*["]			
/* FALTA *
coment		{"/*"}.*{"*"}
coment_line	"//"*/

 

%%

{col_delimit}+		{moveCol();}
{line_delimit} 		{moveLine();}
"//".*{line_delimit} 	{moveLine();}
";"			{moveCol();return PT_VIRGULA;}
"{"			{moveCol();return BEG;}
"}"			{moveCol();return END;}
"["			{moveCol();return OPEN_COLC;}
"]"			{moveCol();return CLOSE_COLC;}
"("			{moveCol();return OPEN_PAREN;}
")"			{moveCol();return CLOSE_PAREN;}
","			{moveCol();return VIRGULA;}
"."			{moveCol();return POINT;}
":"			{moveCol();return TWO_POINTS;}
"+"			{moveCol();return PLUS;}
"-"			{moveCol();return MINUS;}
"*"			{moveCol();return MULT;}
"/"			{moveCol();return DIV;}
"%"			{moveCol();return MOD;}
"=" 			{moveCol();return EQUAL;}
"?"          		{moveCol();return QUESTION_MARK;}
"||"			{moveCol();return OR_LOGIC;}
"&&"			{moveCol();return AND_LOGIC;}
"++"			{moveCol();return INCREMENT;}
"--"			{moveCol();return DECREMENT;}
"!"			{moveCol();return NOT;}
"~"			{moveCol();return NOT_BIT;}
"|"			{moveCol();return OR;}
"^"			{moveCol();return OR_EXC;}
"&"			{moveCol();return AND;}
"if"	        	{moveCol();return IF;}
"else"	        	{moveCol();return ELSE;}
"while"         	{moveCol();return WHILE;}
"new"			{moveCol();return NEW;}
"do"			{moveCol();return DO;}
"for"           	{moveCol();return FOR;}
"break"         	{moveCol();return BREAK;}
"continue"      	{moveCol();return CONTINUE;}
"goto"          	{moveCol();return GOTO;}
"return"        	{moveCol();return RETURN;}
"case"          	{moveCol();return CASE;}
"switch"        	{moveCol();return SWITCH;}
"default"       	{moveCol();return DEFAULT;}
"transient"     	{moveCol();return TRANSIENT;}
"volatile"		{moveCol();return VOLATILE;}
"final"			{moveCol();return FINAL;}
"class"			{moveCol();return CLASS;}
"static"        	{moveCol();return STATIC;}
"void"			{moveCol();return VOID;}
"public"		{moveCol();return PUBLIC;}
"main"			{moveCol();return MAIN;}
"args"			{moveCol();return ARGS;}
"int"			{moveCol();return TYPE_INT;}
"short"			{moveCol();return TYPE_SHORT;}
"long"			{moveCol();return TYPE_LONG;}
"byte"			{moveCol();return TYPE_BYTE;}
"boolean"		{moveCol();return TYPE_BOOL;}
"float"			{moveCol();return TYPE_FLOAT;}
"double"		{moveCol();return TYPE_DOUBLE;}
"char"			{moveCol();return TYPE_CHAR;}
"String"		{moveCol();return TYPE_STRING;}
"true"			{moveCol();yylval.strval = strdup(yytext);return LITERAL;}
"false"			{moveCol();yylval.strval = strdup(yytext);return LITERAL;}
"null"			{moveCol();yylval.strval = strdup(yytext);return LITERAL;}
{char_literal}		{moveCol();yylval.strval = strdup(yytext);return LITERAL;}
{string_literal}	{moveCol();yylval.strval = strdup(yytext);return LITERAL;}
{equal_oper}		{moveCol();yylval.strval = strdup(yytext);return EQUALOP;}
{rel_oper}		{moveCol();yylval.strval = strdup(yytext);return RELOP;}
{shifts}		{moveCol();yylval.strval = strdup(yytext);return SHIFTS;}
{int_literal} 		{moveCol();yylval.strval = strdup(yytext);return LITERAL;}
{hex_literal} 		{moveCol();yylval.strval = strdup(yytext);return LITERAL;}
{oct_literal}		{moveCol();yylval.strval = strdup(yytext);return LITERAL;}
{float_literal} 	{moveCol();yylval.strval = strdup(yytext);return LITERAL;}
{double_literal} 	{moveCol();yylval.strval = strdup(yytext);return LITERAL;}
{id}			{moveCol();yylval.strval = strdup(yytext);return ID;}



%%
/* TA FALTANDO
shift_assig	{moveCol();yylval.strval = strdup(yytext);return SHIFT_ASSIG;}
arith_assig	{moveCol();yylval.strval = strdup(yytext);return ARIT_ASSIG;}
logic_assig	{moveCol();yylval.strval = strdup(yytext);return LOGIC_ASSIG;}
{coment_line}	{moveLine();}
*/

int yywrap(){
   return 1;
}


void moveLine(){
   /**segue para proxima linha e reinicia a coluna**/
   line++;
   column = 1;
}

void moveCol(){
   /**segue para proxima coluna**/
   column += yyleng;
}

