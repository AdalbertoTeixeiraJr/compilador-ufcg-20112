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
void updateCol();
void updateLine();
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
exp_indicator	[eE]
float_sufix	[fFdD]
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
/* FALTA *
/*string_literal	"".*""**					
string_literal	["][^"]*["]
coment		{"/*"}.*{"*"}
coment_line	"//"*/

 

%%

{col_delimit}+	{updateCol();}
{line_delimit}  {updateLine();}
";"		{updateCol();return PT_VIRGULA;}
"{"		{updateCol();return BEG;}
"}"		{updateCol();return END;}
"["		{updateCol();return OPEN_COLC;}
"]"		{updateCol();return CLOSE_COLC;}
"("		{updateCol();return OPEN_PAREN;}
")"		{updateCol();return CLOSE_PAREN;}
","		{updateCol();return VIRGULA;}
"."		{updateCol();return POINT;}
":"		{updateCol();return TWO_POINTS;}
"+"		{updateCol();return PLUS;}
"-"		{updateCol();return MINUS;}
"*"		{updateCol();return MULT;}
"/"		{updateCol();return DIV;}
"%"		{updateCol();return MOD;}
"=" 		{updateCol();return EQUAL;}
"?"          	{updateCol();return QUESTION_MARK;}
"||"		{updateCol();return OR_LOGIC;}
"&&"		{updateCol();return AND_LOGIC;}
"++"		{updateCol();return INCREMENT;}
"--"		{updateCol();return DECREMENT;}
"!"		{updateCol();return NOT;}
"~"		{updateCol();return NOT_BIT;}
"|"		{updateCol();return OR;}
"^"		{updateCol();return OR_EXC;}
"&"		{updateCol();return AND;}
"if"	        {updateCol();return IF;}
"else"	        {updateCol();return ELSE;}
"while"         {updateCol();return WHILE;}
"new"		{updateCol();return NEW;}
"do"		{updateCol();return DO;}
"for"           {updateCol();return FOR;}
"break"         {updateCol();return BREAK;}
"continue"      {updateCol();return CONTINUE;}
"goto"          {updateCol();return GOTO;}
"return"        {updateCol();return RETURN;}
"case"          {updateCol();return CASE;}
"switch"        {updateCol();return SWITCH;}
"default"       {updateCol();return DEFAULT;}
"transient"     {updateCol();return TRANSIENT;}
"volatile"	{updateCol();return VOLATILE;}
"final"		{updateCol();return FINAL;}
"class"		{updateCol();return CLASS;}
"static"        {updateCol();return STATIC;}
"void"		{updateCol();return VOID;}
"public"	{updateCol();return PUBLIC;}
"main"		{updateCol();return MAIN;}
"args"		{updateCol();return ARGS;}
"int"		{updateCol();return TYPE_INT;}
"short"		{updateCol();return TYPE_SHORT;}
"long"		{updateCol();return TYPE_LONG;}
"byte"		{updateCol();return TYPE_BYTE;}
"boolean"	{updateCol();return TYPE_BOOL;}
"float"		{updateCol();return TYPE_FLOAT;}
"double"	{updateCol();return TYPE_DOUBLE;}
"char"		{updateCol();return TYPE_CHAR;}
"String"	{updateCol();return TYPE_STRING;}
"true"		{updateCol();yylval.strval = strdup(yytext);return LITERAL;}
"false"		{updateCol();yylval.strval = strdup(yytext);return LITERAL;}
"null"		{updateCol();yylval.strval = strdup(yytext);return LITERAL;}
{char_literal}	{updateCol();yylval.strval = strdup(yytext);return LITERAL;}
{equal_oper}	{updateCol();yylval.strval = strdup(yytext);return EQUALOP;}
{rel_oper}	{updateCol();yylval.strval = strdup(yytext);return RELOP;}
{shifts}	{updateCol();yylval.strval = strdup(yytext);return SHIFTS;}
{int_literal} 	{updateCol();yylval.strval = strdup(yytext);return LITERAL;}
{hex_literal} 	{updateCol();yylval.strval = strdup(yytext);return LITERAL;}
{oct_literal}	{updateCol();yylval.strval = strdup(yytext);return LITERAL;}
{float_literal} {updateCol();yylval.strval = strdup(yytext);return LITERAL;}
{id}		{updateCol();yylval.strval = strdup(yytext);return ID;}



%%
/* TA FALTANDO
shift_assig	{updateCol();yylval.strval = strdup(yytext);return SHIFT_ASSIG;}
arith_assig	{updateCol();yylval.strval = strdup(yytext);return ARIT_ASSIG;}
logic_assig	{updateCol();yylval.strval = strdup(yytext);return LOGIC_ASSIG;}
string_literal 	{updateCol();yylval.strval = strdup(yytext);return STRING_LITERAL;}
{char}		{updateCol();yylval.strval = strdup(yytext);return LITERAL;}
{coment_line}	{updateLine();}
*/

int yywrap(){
   return 1;
}


void updateLine(){
   /**segue para proxima linha e reinicia a coluna**/
   line++;
   column = 1;
}

void updateCol(){
   /**segue para proxima coluna**/
   column += yyleng;
}

