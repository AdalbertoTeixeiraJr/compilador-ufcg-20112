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
#include <stdio.h>
#include <string.h>
#include "tkvalues.h"
int yylex(void); //funcao do lexico para retornar o token  --  Vi ele nos exemplos, mas nao achei implementação! o0
int line = 1; //declarado no lexico
int col  = 0; // declarado no lexico
char* yytext = ""; //declarado no lexico
%}

%union {
	char* strval;
}

%token BOOLEAN BREAK BYTE CASE CHAR CLASS CONST CONTINUE DEFAULT DO DOUBLE ELSE FINAL FLOAT FOR GOTO IF INT LONG NEW RETURN SHORT STATIC SWITCH TRANSIENT VOID VOLATILE WHILE
%token <strval>  //Quais? Tambem nao soube fazer!

%type <strval>  //Quais os tipos??? Nao to sabendo fazer

%%

compilation_unit : 		class_declaration				;

class_declaration : 		CLASS <identifier> <class body>			;

class_body : 			{ class_body_declaration }			;

class_body_declaration : 	class_member_declaration
			|	static_initializer				;

class_member_declaration : 	field_declaration
			|	method_declaration				;

static_initializer : 		STATIC block					;

formal_parameter_list : 	formal_parameter formal_parameter_list@		;

formal_parameter_list@ : 	formal_parameter formal_parameter_list@
			|	/** empty **/					;

formal_parameter : 		type variable_declarator_id			;

class_type_list : 		class_type class_type_list@			;

class_type_list@ : 		class_type class_type_list@
			|	/** empty **/					;

field_declaration : 		field_modifiers? type variable_declarators	;

field_modifiers : 		field_modifier field_modifiers@			;

field modifiers@ : 		field_modifier field_modifiers@
			| 	/** empty **/					;

field_modifier : 		STATIC
			| 	FINAL
			| 	TRANSIENT
			| 	VOLATILE					;

variable_declarators : 		variable_declarator variable_declarators@	;

variable_declarators@ : 	variable_declarator variable_declarators@
			| 	/** empty **/					;

variable_declarator : 		variable_declarator_id variable_declarator@	;

variable_declarator@ :  	= variable_initializer 
			| 	/** empty **/					;

variable_declarator_id : 	identifier	 
			| 	variable_declarator_id [ ]			;

variable_initializer : 		expression
			| 	array_initializer				;

method_declaration : 		method_header method_body			;

method_header : 		method_modifiers? result_type method_declarator?;

result_type :	 		type 
			| 	VOID						;

method_modifiers : 		method_modifier method_modifiers@		;

method_modifiers@ : 		method_modifier	method_modifiers@ 
			| 	/** empty **/					;

method_modifier :  		STATIC						;

method_declarator : 		identifier ( formal_parameter_list? )		;

method_body : 			block 
				| ;		//** COMO COLOCA ; **/		
				| /** empty **/					;

constant_declaration : 		constant_modifiers type variable_declarator	;

constant_modifiers : 		STATIC 
			| 	FINAL						;

array_initializer : 		{ variable_initializers? , ? }			;

variable_initializers : 	variable_initializer variable_initializers@	;

variable_initializers@ : 	variable_initializer variable_initializers@ 
			|	/** empty **/					;

variable_initializer : 		expression
			| 	array_initializer				;

/* 
**	Types	**
*/

primitive_type : 		numeric_type 
			| 	boolean
			| 	string_literal					;

numeric_type : 			integral_type 
			| 	floating_point_type				;

integral_type : 		BYTE 
			| 	SHORT 
			| 	INT 
			| 	LONG 
			| 	CHAR						;

floating_point_type : 		FLOAT
			|	DOUBLE						;

reference_type : 		class_type 
			| 	array_type					;

class_type : 			type_name					;

array_type :			type [ ]					;

/*
**	Blocks and commands	**
*/

block : 			{ block_statements? }				;

block_statements : 		block_statement block_statements@		; 

block_statements : 		block_statement block_statements@ 
			|	/** empty **/					;
	
block_statement : 		local_variable_declaration_statement 
			| 	statement					;
	
local_variable_declaration_statement : local_variable_declaration 		;

local_variable_declaration : 	type variable_declarators			;

statement : 			statement_without_trailing_substatement
			| 	identifier : statement 
			| 	IF ( expression ) statement	 
			| 	IF ( expression ) statement_no_short_if ELSE statement 
			| 	WHILE ( expression ) statement 
			| 	FOR ( for_init? ; expression? ; for_update? ) statement
										;

statement_no_short_if : 	statement_without_trailing_substatement 
			| 	identifier : statement_no_short_if 
			| 	IF ( expression ) statement_no_short_if ELSE 								statement_no_short_if 
			|  	WHILE ( expression ) statement_no_short_if 
			|  	FOR ( for_init? ; expression? ; for_update? ) 
							statement_no_short_if	;

statement_without_trailing_substatement : block 
			| 	empty_statement 
			| 	expression_statement 
			| 	switch_statement 
			| 	do_statement
			| 	break_statement
			| 	continue_statement
			| 	return_statement				;

empty_statement : 		; /** COMO COLOCA ; **/				;

labeled_statement : 		identifier : statement				;

labeled_statement no short if : identifier : statement_no_short_if		;

expression_statement : 		statement_expression				;

statement_expression : 		assignment 
			| 	preincrement_expression 
			| 	postincrement_expression 
			| 	predecrement_expression 
			| 	postdecrement_expression 
			| 	method_invocation 
			|	class_instance_creation_expression		;

<if then statement>: if ( <expression> ) <statement>	;

<if then else statement>: if ( <expression> ) <statement no short if> else <statement>	;

<if then else statement no short if> : if ( <expression> ) <statement no short if> else <statement no short if>	;

<switch statement> : switch ( <expression> ) <switch block>	;

<switch block> : { <switch block statement groups>? <switch labels>? }	;

<switch block statement groups> : <switch block statement group> <switch block statement groups@>	;

<switch block statement groups@> : <switch block statement group> <switch block statement groups@> 
	| E
	;

<switch block statement group> : <switch labels> <block statements>	;

<switch labels> : <switch label> <switch labels@>	;

<switch labels@> : <switch label> <switch labels@> 
	| E
	;

<switch label> : case <constant expression> : 
	| default :
	;

<while statement> : while ( <expression> ) <statement>	;

<while statement no short if> : while ( <expression> ) <statement no short if>	;

<do statement> : do <statement> while ( <expression> ) ;	;

<for statement> : for ( <for init>? ; <expression>? ; <for update>? ) <statement>	;

<for statement no short if> : for ( <for init>? ; <expression>? ; <for update>? ) <statement no short if>	;

<for init> : <statement expression list> 
	| <local variable declaration>
	;

<for update> : <statement expression list>	;

<statement expression list> : <statement expression> <statement expression list@>	;

<statement expression list@> : , <statement expression> <statement expression list@> 
	| E
	;

<break statement> : break <identifier>? ;	;

<continue statement> : continue <identifier>? ;	;

<return statement> : return <expression>? ;	;

/*
**	Expression	**
*/

<constant expression> : <expression>	;

<expression> : <assignment expression>	;

<assignment expression> : <conditional expression> 
	| <left hand side> <assignment operator> <assignment expression>
	;

<assignment> : <left hand side> <assignment operator> <assignment expression>	;

<left hand side> : <expression name> 
	| <field access> 
	| <array access>
	;

<assignment operator> : = 
	| *= 
	| /= 
	| %= 
	| += 
	| -= 
	| <<= 
	| >>= 
	| >>>= 
	| &= 
	| ^= 
	| |=
	;

<conditional expression> : <conditional or expression> 
	| <conditional or expression> ? <expression> : <conditional expression>
	;

<conditional or expression> : <conditional and expression> <conditional or expression@>	;

<conditional or expression@> : || <conditional and expression> <conditional or expression@> 
	| E
	;

<conditional and expression> : <inclusive or expression> <conditional and expression@>	;

<conditional and expression@> : && <inclusive or expression> <conditional and expression@> 
	| E
	;

<inclusive or expression> : <exclusive or expression> <inclusive or expression@>	;

<inclusive or expression@> : | <exclusive or expression> <inclusive or expression@> 
	| E
	;

<exclusive or expression> : <and expression> <exclusive or expression@>	;

<exclusive or expression@> : ^ <and expression> <exclusive or expression@> 
	| E
	;

<and expression> : <equality expression> <and expression@>	;

<and expression@> : & <equality expression> <and expression@> 
	| E
	;

<equality expression> : <relational expression> <equality expression@>	;

<equality expression@> : == <relational expression> <equality expression@>
	| != <relational expression> <equality expression@> 
	| E
	;

<relational expression> : <shift expression> <relational expression@>	;

<relational expression@> : < <shift expression> <relational expression@> 
	| > <shift expression> <relational expression@> 
	| <= <shift expression> <relational expression@> 
	| >= <shift expression> <relational expression@> 
	| instanceof <reference type> <relational expression@> 
	| E 
	;

<shift expression> : <additive expression> <shift expression@>	;

<shift expression@> : << <additive expression> <shift expression@> 
	| >> <additive expression> <shift expression@> 
	|  >>> <additive expression> <shift expression@> 
	| E 
	;

<additive expression> : <multiplicative expression> <additive expression@>	;

<additive expression@> : + <multiplicative expression> <additive expression@> 
	| - <multiplicative expression> <additive expression@>
	;

<multiplicative expression> : <unary expression> <multiplicative expression@>	;

<multiplicative expression@> : * <unary expression> <multiplicative expression@> 
	| / <unary expression> <multiplicative expression@> 
	| % <unary expression> <multiplicative expression@>
	;

<cast expression> : ( <primitive type> ) <unary expression> 
	| ( <reference type> ) <unary expression not plus minus>
	;

<unary expression> : ++ <unary expression> 
	| -- <unary expression> 
	| + <unary expression> 
	| - <unary expression> 
	| <postfix expression> 
	| ~ <unary expression> 
	| ! <unary expression> 
	| <cast expression>
	;

<predecrement expression> : -- <unary expression>	;

<preincrement expression> : ++ <unary expression>	;

<unary expression not plus minus> : <postfix expression> 
	| ~ <unary expression> 
	| ! <unary expression> 
	| <cast expression>
	;

<postdecrement expression> : <postfix expression> --	;

<postincrement expression> : <postfix expression> ++	;

<postfix expression> : <primary> <postfix expression@> 
	| <expression name> <postfix expression@> 
	;

<postfix expression@> : ++ <postfix expression@> 
	| -- <postfix expression@> 
	| E
	;

<method invocation> : <method name> ( <argument list>? ) 
	| <primary> . <identifier> ( <argument list>? ) 
	;

<field access> : <primary> . <identifier>	;

<primary> : <primary no new array> 
	| <array creation expression>
	;

<primary no new array> : <literal> 
	| ( <expression> ) 
	| <field access> 
	| <method invocation> 
	| <array access>
	;

<argument list> : <expression> <argument list@>	;

<argument list@> : , <expression> <argument list@> 
	| E
	;

<array creation expression> : new <primitive type> <dim exprs> <dims>?	;

<dim exprs> : <dim expr> <dim exprs@>	;

<dim exprs@> : <dim expr> <dim exprs@> 
	| E
	;

<dim expr> : [ <expression> ]	;

<dims> : [ ] <dims@>	;

<dims@> : [ ] <dims@> 
	| E
	;

<array access> : <expression name> [ <expression> ] 
	| <primary no new array> [ <expression>]
	;
