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
int yylex(void);
int yyerror(char *msg); //funcao de erro (sobrescrita)
int line = 1; //declarado no lexico
int col  = 0; // declarado no lexico
char* yytext = ""; //declarado no lexico
%}

%union {
	char* strval;
}

%token BOOLEAN BREAK BYTE CASE CHAR CLASS CONST CONTINUE DEFAULT DO DOUBLE ELSE FINAL FLOAT FOR GOTO 
%token IF INT LONG NEW RETURN SHORT STATIC SWITCH TRANSIENT VOID VOLATILE WHILE PT_VIRGULA MULT DIV 
%token PLUS MINUS LEFT RIGHT TWO_POINT OR_EXC AND OR AND_LOGIC OR_LOGIC EQUAL_COMP NOT NOT_BIT
%token INCREMENT DECREMENT NEW OPEN_COLC CLOSE_COLC POINT
%token <strval> RELOP
%token <strval> ID

%type <strval>  //Quais os tipos??? Nao to sabendo fazer

%%

compilation_unit : 			class_declaration							;

class_declaration : 		CLASS <identifier> <class body>				;

class_body : 				{ class_body_declaration }					;

class_body_declaration : 	class_member_declaration
			|				static_initializer							;
	
class_member_declaration : 	field_declaration
			|				method_declaration							;

static_initializer : 		STATIC block								;

formal_parameter_list : 	formal_parameter formal_parameter_list@		;

formal_parameter_list@ : 	formal_parameter formal_parameter_list@
			|				/** empty **/								;

formal_parameter : 			type variable_declarator_id					;

class_type_list : 			class_type class_type_list@					;

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
			| 		PT_VIRGULA		
			| 		/** empty **/					;

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
	
local_variable_declaration_statement : local_variable_declaration PT_VIRGULA ;

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
			| 	IF ( expression ) statement_no_short_if ELSE statement_no_short_if 
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

empty_statement : 		PT_VIRGULA			;

labeled_statement : 		identifier : statement				;

labeled_statement no short if : identifier : statement_no_short_if		;

expression_statement : 		statement_expression PT_VIRGULA				;

statement_expression : 		assignment 
			| 	preincrement_expression 
			| 	postincrement_expression 
			| 	predecrement_expression 
			| 	postdecrement_expression 
			| 	method_invocation 
			|	class_instance_creation_expression		;

if_then_statement: IF ( expression ) statement	;

if_then_else_statement: IF ( expression ) statement_no_short_if ELSE statement	;

if_then_else_statement_no_short_if : IF ( expression ) statement_no_short_if ELSE statement_no_short_if	;

switch_statement : SWITCH ( expression ) switch_block	;

switch_block : { switch_block_statement_groups? switch_labels? }	;

switch_block_statement_groups : switch_block_statement_group switch_block_statement_groups@	;

switch_block_statement_groups@ : switch_block_statement_group switch_block_statement_groups@ 
			| 						/** empty **/						;

switch_block_statement_group : switch_labels block_statements			;

switch_labels : switch_label switch_labels@	;

switch_labels@ : switch_label switch_labels@ 
			| 						/** empty **/						;

switch_label : CASE constant_expression TWO_POINTS
			| 	DEFAULT TWO_POINTS										;

while_statement : WHILE ( expression ) statement	;

while_statement_no_short_if> : WHILE ( expression ) statement_no_short_if	;

do_statement : DO statement WHILE ( expression ) PT_VIRGULA						;

for_statement : FOR ( for_init? ; expression? ; for_update ) statement	;

for_statement_no_short_if : FOR ( for_init? ; expression? ; for_update? ) statement_no_short_if	;

for_init : statement_expression_list 
			| 	local_variable_declaration								;

for_update : statement_expression_list									;

statement_expression_list : statement_expression statement_expression_list@	;

statement_expression_list@ : VIRGULA statement_expression statement_expression_list@ 	
			| 					/** empty **/							;

break_statement : BREAK identifier? PT_VIRGULA									;

continue_statement : CONTINUE identifier? PT_VIRGULA	;

return_statement : RETURN expression? PT_VIRGULA	;

/*
**	Expression	**
*/

constant_expression : expression	;

expression : assignment_expression	;

assignment_expression : conditional_expression 
			| 	left_hand_side assignment_operator assignment_expression		;

assignment : left_hand_side assignment_operator assignment_expression	;

left_hand_side : expression_name 
			| 	field_access 
			| 	array_access											;

assignment_operator PT_VIRGULA EQUAL 
			| 	MULT EQUAL 
			| 	DIV EQUAL  
			|	MOD EQUAL 
			| 	PLUS EQUAL 
			| 	MINUS EQUAL 
			| 	LEFT LEFT EQUAL 
			| 	RIGHT RIGHT EQUAL
			| 	RIGHT RIGHT RIGHT 
			| 	AND EQUAL 
			|	OR_EXC EQUAL 
			| 	OR EQUAL													;

conditional_expression : conditional_or_expression 
			| conditional_or_expression? expression TWO_POINTS conditional_expression	;

conditional_or_expression : conditional_and_expression conditional_or_expression@	;

conditional_or_expression@ : OR_LOGIC conditional_and_expression conditional_or_expression@ 
			| /** empty **/																;

conditional_and_expression : inclusive_or_expression conditional_and_expression@	;

conditional_and_expression@ : AND_LOGIC inclusive_or_expression conditional_and_expression@ 
			| /** empty **/													;

inclusive_or_expression : exclusive_or_expression  inclusive_or_expression@	;

inclusive_or_expression@ : OR exclusive_or_expression inclusive_or_expression@ 
			| /** empty **/													;

exclusive_or_expression : and_expression exclusive_or_expression@>	;

exclusive_or_expression@ : OR_EXC and_expression exclusive_or_expression@ 
			| /** empty **/													;

and_expression : equality_expression and_expression@	;

and_expression@ : AND_LOGIC equality_expression and_expression@ 
			| /** empty **/													;

equality_expression : relational_expression equality_expression@			;

equality_expression@ : EQUAL_COMP relational_expression equality_expression@
			| 	DIFF_EQUAL relational_expression equality_expression@ 
			| 	/** empty **/												;

relational_expression : shift_expression relational_expression@				;

relational_expression@ : < shift_expression relational_expression@ 
			| > shift_expression relational_expression@ 
			| <= shift_expression relational_expression@ 
			| >= shift_expression relational_expression@ 
			| instanceof shift_expression relational_expression@ 
			| /** empty **/													;

shift_expression : additive_expression shift_expression@					;

shift_expression@ : << additive_expression shift_expression@ 
			| SHIFT_RIGHT additive_expression shift_expression@
			| SHIFT_RIGHT_LOGIC additive_expression shift_expression@ 
			| /** empty **/													;

additive_expression : multiplicative_expression additive_expression@		;

additive_expression@ : PLUS multiplicative_expression additive_expression@ 
			| MINUS multiplicative_expression additive_expression@			;

multiplicative_expression : unary_expression multiplicative_expression@		;

multiplicative_expression@ : MULT unary_expression multiplicative_expression@ 
			| DIV unary_expression multiplicative_expression@ 
			| MOD unary_expression multiplicative_expression@				;

cast_expression : OPEN_PAREN primitive_type OPEN_PAREN unary_expression 
			| OPEN_PAREN reference_type CLOSE_PAREN unary_expression_not_plus_minus;

unary_expression : INCREMENT unary_expression 
			| DECREMENT unary_expression 
			| PLUS unary_expression 
			| MINUS unary_expression 
			| postfix_expression 
			| NOT unary_expression 
			| NOT_BIT unary_expression 
			| cast_expression												;

predecrement_expression : DECREMENT unary_expression						;

preincrement_expression : INCREMENT unary_expression						;

unary_expression_not_plus_minus : postfix_expression 
			| NOT_BIT unary_expression 
			| NOT unary_expression
			| cast_expression												;

postdecrement_expression : postfix_expression DECREMENT						;

postincrement_expression : postfix_expression INCREMENT						;

postfix_expression : primary postfix_expression@ 
			| expression_name postfix_expression@							;

postfix_expression@ : INCREMENT postfix_expression@		 
			| DECREMENT postfix_expression@
			| /** empty **/													;

method_invocation : method_name OPEN_PAREN argument_list? CLOSE_PAREN 
			| primary POINT identifier OPEN_PAREN argument_list? CLOSE_PAREN;

field_access : primary POINT identifier										;

primary : primary_no_new_array 
			| array_creation_expression										;

primary_no_new_array : literal 
				| OPEN_PAREN expression CLOSE_PAREN 
				| field_access 
				| method_invocation 
				| array_access												;

argument_list : expression argument_list@									;

argument_list@ : VIRGULA expression argument_list@ 
			 	| /** empty **/												;

array_creation_expression : NEW primitive_type dim_exprs dims?				;

dim_exprs : dim_expr dim_exprs@												;

dim_exprs@ : dim_expr dim_exprs@ 
				| /** empty **/												;

dim_expr : OPEN_COLC expression CLOSE_COLC	;

dims : OPEN_COLC CLOSE_COLC dims@	;

dims@ : OPEN_COLC CLOSE_COLC dims@ 
				| /** empty **/												;

array_access : expression_name OPEN_COLC expression CLOSE_COLC 
				| primary_no_new_array OPEN_COLC expression CLOSE_COLC		;

				
%%

int main(void) {
	return yyparse();
}

//funcao de erro - imprime linha e coluna do erro sintatico
int yyerror(char *msg){
	int tk = YYTRANSLATE(yychar);
	if(strcmp("syntax error", msg) == 0){
		msg = "Erro Sintatico";
	}
	fprintf(stderr,"%s:\n",msg);
	fprintf(stderr,"\tLinha %d, Coluna %d\n", line, col);
	fprintf(stderr,"\tUltimo token lido: %s - %s\n",yytname[tk],yytext);
	return 1;
}