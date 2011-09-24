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
extern int col; // carrega do sintatico
extern int line; // carrega do sintatico
char* yytext;
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
null_literal	"null"
equal_oper		"==" | "!="
rel_oper		"<" | ">" | "<=" | ">=" | "instanceof"
shifts			"<<" | ">>" | ">>>"
shifts_assig	"<<=" | ">>=" | ">>>="
arith_assig		"*=" | "/=" | "+=" | "-=' | "%="
logic_assig		"&=" | "^=" | "|=" 

%%


{col_delimit}+	{updateCol();}
{line_delimit}	{updateLine();}
if				{updateCol();return IF;}
else			{updateCol();return ELSE;}
while			{updateCol();return WHILE;}
"("				{updateCol();return OPEN_PAREN;}
")"				{updateCol();return CLOSE_PAREN;}
"int"			{updateCol();return TYPE_INT;}
"short"			{updateCol();return TYPE_SHORT;}
"long"			{updateCol();return TYPE_LONG;}
"byte"			{updateCol();return TYPE_BYTE;}
"boolean"		{updateCol();return TYPE_BOOL;}
"float"			{updateCol();return TYPE_FLOAT;}
"double"		{updateCol();return TYPE_DOUBLE;}
"char"			{updateCol();return TYPE_CHAR;}
"String"		{updateCol();return TYPE_STRING;}
";"				{updateCol();return PT_VIRGULA;}
","				{updateCol();return VIRGULA;}
"=" 			{updateCol();return EQUAL;}
"*"				{updateCol();return MULT;}
"/"				{updateCol();return DIV;}
"%"				{updateCol();return MOD;}
"+"				{updateCol();return PLUS;}
"-"				{updateCol();return MINUS;}
":"				{updateCol();return TWO_POINTS;}
"^"				{updateCol();return OR_EXC;}
"&"				{updateCol();return AND;}
"|"				{updateCol();return OR;}
"||"			{updateCol();return OR_LOGIC;}
"&&"			{updateCol();return AND_LOGIC;}
"++"			{updateCol();return INCREMENT;}
"--"			{updateCol();return DECREMENT;}
"!"				{updateCol();return NOT;}
"~"				{updateCol();return NOT_BIT;}
"."				{updateCol();return POINT;}
"new"			{updateCol();return NEW;}
"["				{updateCol();return OPEN_COLC;}
"]"				{updateCol();return CLOSE_COLC;}
"{"				{updateCol();return BEG;}
"}"				{updateCol();return END;}
"goto"          {updateCol();return GOTO;}
"?"          	{updateCol();return QUESTION_MARK;}
"break"         {updateCol();return BREAK;}
"case"          {updateCol();return CASE;}
"class"         {updateCol();return CLASS;}
"continue"      {updateCol();return CONTINUE;}
"default"       {updateCol();return DEFAULT;}
"do"            {updateCol();return DO;}
"final"         {updateCol();return FINAL;}
"for"           {updateCol();return FOR;}
"return"        {updateCol();return RETURN;}
"static"        {updateCol();return STATIC;}
"transient"     {updateCol();return TRANSIENT;}
"switch"        {updateCol();return SWITCH;}
"void"          {updateCol();return VOID;}
equal_oper		{updateCol();yylval.strval = strdup(yytext);return EQUALOP;}
rel_oper		{updateCol();yylval.strval = strdup(yytext);return RELOP;}
id				{updateCol();yylval.strval = strdup(yytext);return ID;}
shifts			{updateCol();yylval.strval = strdup(yytext);return SHIFTS;}
shift_assig		{updateCol();yylval.strval = strdup(yytext);return SHIFT_ASSIGN;}
arith_assig		{updateCol();yylval.strval = strdup(yytext);return ARITH_ASSIGN;}
logic_assig		{updateCol();yylval.strval = strdup(yytext);return LOGIC_ASSIGN;}
literal			{updateCol();yylval.strval = strdup(yytext);return LITERAL;}

%%


void updateLine(){
   //segue para proxima linha e reseta a coluna
   line++;
   col = 1;
}

void updateCol(){
   //segue para proxima coluna
   col += yyleng;
}

int yywrap() {
  return 1;
}

