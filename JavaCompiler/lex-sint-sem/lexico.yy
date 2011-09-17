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
extern int col; // sintatico
extern int line; // sintatico
extern char* yytext;
void updateCol();
void updateLine();
%}


col_delimit		[ \r\t]
line_delimit	[\n]
underline		_
id				{underline}?{string_chars}
simple_name		{id}
method_name		{id} | {id}.{id}
exp_name		{id} | {id}.{id}
literal 		{int_literal} | {float_literal} | {boolean_literal} | {string_literal} | {null_literal}
int_literal		{hex_int_literal} | {dec_int_literal} | {oct_int_literal} 
dec_int_literal	{dec_num} {int_type_suf}?
hex_int_literal	{hex_num} {int_type_suf}?
oct_int_literal	{oct_num} {int_type_suf}?
int_type_suf	l|L
dec_num 		{zero_digit} | {non_zero_digit} {digits}?
digits			{digit} | {digits}{digit}
digit			{zero_digit}|non_zero_digit
zero_digit		[0]
non_zero_digit	[1-9]	
hex_num			{zero_digit}x{hex_digit} | {zero_digit}X{hex_digit} | {hex_num}{hex_digit}
hex_digit		[0-9A-F]
oct_num			{zero_digit} {oct_digit} | {oct_num} {oct_digit}
oct_digit		[0-7]
float_literal	{digits}.{digits}?{exp_part}?{float_sufix}?{digits}?{exp_part}?{float_sufix}? 
exp_part		{exp_indicator} | {signed_int}
exp_indicator	e|E
signed_int		{signal}? {digits}
signal 			+|-
float_sufix		f|F|d|D
letter          [A-Za-z]
boolean_literal true | false
string_char		{letter} | {digit}								// melhoria: mapear unicode
string_literal	"{string_chars}?"
string_chars	{string_char} | {string_chars}{string_char}
null_literal	null
rel_oper		< | > | == | != | <= | >= 



%%


{col_delimit}+	{updateCol();}
{line_delimit}	{updateLine();}
if				{updateCol();return IF;}
else			{updateCol();return ELSE;}
while			{updateCol();return WHILE;}
"{"				{updateCol();return BEG;}
"}"				{updateCol();return END;}
"("				{updateCol();return OPEN_PAREN;}
")"				{updateCol();return CLOSE_PAREN;}
"["				{updateCol();return OPEN_INDEX;}
"]"				{updateCol();return CLOSE_INDEX; }
"int"			{updateCol();return TYPE_INT;}
"bool"			{updateCol();return TYPE_BOOL;}
"float"			{updateCol();return TYPE_FLOAT;}
"double"		{updateCol();return TYPE_DOUBLE;}
"string"		{updateCol();return TYPE_STRING;}
rel_oper		{updateCol();yylval.strval = strdup(yytext);return RELOP;}
id				{updateCol();yylval.strval = strdup(yytext);return ID;}

%%


void nextLine(){
   //segue para proxima linha e reseta a coluna
   line++;
   col = 1;
}

void nextCol(){
   //segue para proxima coluna
   col += yyleng;
}
