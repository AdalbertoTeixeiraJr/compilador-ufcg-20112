/*
** Projeto Compiladores - 2011.2 **
** UFCG - DSC                                    **     
** Prof.: Franklin Ramalho               **
** Equipe:                                               **
**      Adalberto Teixeira                       **
**      Andrey Menezes                           **
**      Augusto Macedo                           **
** Ling. Fonte: Java                     **
*/

%{
#include <stdio.h>
#include <string.h>
/*#include "tkvalues.h"*/
int yylex(void);
int yyerror(char *msg); //funcao de erro (sobrescrita)
int line = 1; //declarado no lexico
int column  = 0; // declarado no lexico
char* yytext = ""; //declarado no lexico
%}

%union {
        char* strval;
}

%token CLASS BEG END STATIC PT_VIRGULA OPEN_COLC CLOSE_COLC EQUAL VIRGULA POINT
%token TYPE_INT TYPE_SHORT TYPE_LONG TYPE_BYTE TYPE_BOOL 
%token TYPE_FLOAT TYPE_DOUBLE TYPE_CHAR TYPE_STRING
%token QUESTION_MARK TWO_POINTS OR_LOGIC AND_LOGIC OPEN_PAREN CLOSE_PAREN NEW
%token OR OR_EXC AND PLUS MINUS MULT DIV MOD INCREMENT DECREMENT NOT NOT_BIT 
%token FOR IF ELSE WHILE CASE SWITCH DEFAULT DO BREAK CONTINUE GOTO RETURN VOID
%token MAIN ARGS PUBLIC 
%token FINAL TRANSIENT VOLATILE
%token <strval> ID
%token <strval> SHIFT_ASSIGN
%token <strval> ARITH_ASSIGN
%token <strval> LOGIC_ASSIGN
%token <strval> LITERAL
%token <strval> EQUALOP
%token <strval> RELOP
%token <strval> SHIFTS

%%

compilation_unit :	class_declaration;

class_declaration :	CLASS {printf("CLASS\n");} identifier class_body;						

identifier :	ID {printf("ID - %s\n", $1);};

class_body :	BEG {printf("{\n");} class_body_declaration END {printf("}\n");};

class_body_declaration :	 class_member_declaration_opt static_initializer;					/* FALTA VERIFICAR class_member_declaration*/	

static_initializer :	PUBLIC {printf("public\n");} STATIC {printf("STATIC\n");} VOID {printf("void\n");} MAIN {printf("main\n");} OPEN_PAREN {printf("(\n");} TYPE_STRING {printf("String\n");} OPEN_COLC {printf("[\n");} CLOSE_COLC {printf("]\n");} 
			ARGS {printf("args\n");}  CLOSE_PAREN {printf(")\n");} block;

block :		BEG {printf("{\n");} block_statements END {printf("}\n");};

block_statements :	block_statement block_statements_
		|       block_statements_;

block_statements_:	block_statement block_statements_ 		/* FALTA VERIFICAR statement, ja dei uma verificada, mas ainda falta*/
                |	/** empty **/;
        
block_statement :	local_variable_declaration_statement 
	|       statement;									

local_variable_declaration_statement : local_variable_declaration PT_VIRGULA {printf(";\n");} local_variable_declaration_;

local_variable_declaration_ : local_variable_declaration PT_VIRGULA {printf(";\n");}
			|	/** empty **/;

local_variable_declaration :    primitive_type variable_declarators
			|	primitive_type OPEN_COLC {printf("[\n");} CLOSE_COLC {printf(";\n");} variable_declarators;
						

primitive_type :	numeric_type 
               |       TYPE_BOOL {printf("TYPE_BOOL\n");}
               |       TYPE_STRING {printf("TYPE_STRING\n");} ;

numeric_type :	integral_type 
             |       floating_point_type;

integral_type :		TYPE_BYTE {printf("TYPE_BYTE\n");} 
                |       TYPE_SHORT {printf("TYPE_SHORT\n");}
                |       TYPE_INT {printf("TYPE_INT\n");}
                |       TYPE_LONG {printf("TYPE_LONG\n");}
                |       TYPE_CHAR {printf("TYPE_CHAR\n");}; 

floating_point_type :	TYPE_FLOAT {printf("TYPE_FLOAT\n");}
                |       TYPE_DOUBLE {printf("TYPE_DOUBLE\n");};

variable_declarators :          variable_declarator variable_declarators_;

variable_declarator :           variable_declarator_id variable_declarator_ ;			/** Pode declarar variaveis de mesmo tipo antes do ; **/

variable_declarators_ :         VIRGULA {printf("VIRGULA\n");} variable_declarator variable_declarators_
                        |       /** empty **/;

variable_declarator_ :          EQUAL {printf("=\n");} variable_initializer 
                        |       /** empty **/;

variable_declarator_id :        identifier; 
 
variable_initializer :          /*left_hand_side assignment_operator*/ assignment_expression			/** Acho que essa regra tá errada, não tem esse left_hand_side */
                        |       array_initializer
			|	left_hand_side;

array_initializer :	BEG  {printf("{\n");} variable_initializers  virgula_opt END{printf("}\n");}
			|	array_creation_expression; 

virgula_opt :	VIRGULA {printf("VIRGULA\n");}
	|       /** empty **/;

variable_initializers :         variable_initializer variable_initializers_     
                        |       variable_initializers_;

variable_initializers_ :        VIRGULA {printf("VIRGULA\n");}variable_initializer variable_initializers_ 
                        |       /** empty **/; 

expression : assignment_expression;

assignment_expression : conditional_expression;

field_access : identifier POINT identifier;

left_hand_side :	field_access 
                |       array_access;

assignment_operator : EQUAL {printf("EQUAL\n");}
		|       ARITH_ASSIGN {printf("ARITH_ASSIGN\n");}
		|       SHIFT_ASSIGN {printf("SHIFT_ASSIGN\n");}
	        |	LOGIC_ASSIGN {printf("LOGIC_ASSIGN\n");}; 

array_access : primary_no_new_array OPEN_COLC {printf("[\n");} expression CLOSE_COLC {printf("]\n");};

primary_no_new_array : 	LITERAL {printf("LITERAL - %s\n", $1);}
		| 	field_access 
		|	method_invocation 
	        | 	array_access
		|	identifier;

argument_list : 	expression argument_list_
		|	argument_list_;

argument_list_ : 	VIRGULA {printf("VIRGULA\n");} expression argument_list_ 
                | 	/** empty **/;

/*primary : 	primary_no_new_array 
	| 	array_creation_expression;*/

array_creation_expression : NEW {printf("NEW\n");} primitive_type dim_exprs dims;

dim_exprs : OPEN_COLC {printf("[\n");} dim_expr_or_empty CLOSE_COLC {printf("]\n");};

dim_expr_or_empty : expression
		|	/** empty **/;

dims: dim_exprs
	| 	/**empty**/;



conditional_expression : conditional_or_expression 
                        | conditional_or_expression QUESTION_MARK {printf("?\n");} conditional_expression TWO_POINTS {printf(":\n");} conditional_expression;


conditional_or_expression : conditional_and_expression conditional_or_expression_;

conditional_or_expression_ : OR_LOGIC {printf("OR_LOGIC\n");} conditional_and_expression conditional_or_expression_ 
                        | /** empty **/;

conditional_and_expression : inclusive_or_expression conditional_and_expression_;

conditional_and_expression_ : AND_LOGIC {printf("AND_LOGIC\n");} inclusive_or_expression conditional_and_expression_ 
			| /** empty **/;

inclusive_or_expression : exclusive_or_expression  inclusive_or_expression_     ;

inclusive_or_expression_ : OR {printf("OR\n");} exclusive_or_expression inclusive_or_expression_ 
                        | /** empty **/;

exclusive_or_expression : and_expression exclusive_or_expression_      ;

exclusive_or_expression_ : OR_EXC {printf("OR_EXC\n");}and_expression exclusive_or_expression_ 
                        | /** empty **/;

and_expression : equality_expression and_expression_    ;

and_expression_ : AND {printf("AND\n");} equality_expression and_expression_ 
                        | /** empty **/;

equality_expression : relational_expression equality_expression_;

equality_expression_ : EQUALOP {printf("EQUALOP\n");} relational_expression equality_expression_
                        |       /** empty **/;

relational_expression : shift_expression relational_expression_;

relational_expression_ : RELOP {printf("RELOP\n");} shift_expression relational_expression_ 
                        | /** empty **/;

shift_expression : additive_expression shift_expression_;

shift_expression_ : SHIFTS {printf("SHIFTS\n");} additive_expression shift_expression_ 
                        | /** empty **/;

additive_expression : multiplicative_expression additive_expression_;

additive_expression_ : PLUS {printf("PLUS\n");} multiplicative_expression additive_expression_
                        | MINUS {printf("MINUS\n");}multiplicative_expression additive_expression_
			| /** empty **/;

multiplicative_expression : unary_expression multiplicative_expression_         ;

multiplicative_expression_ : MULT {printf("MULT\n");} unary_expression multiplicative_expression_ 
                        | DIV {printf("DIV\n");} unary_expression multiplicative_expression_ 
                        | MOD {printf("MOD\n");} unary_expression multiplicative_expression_
			| /** empty **/;

unary_expression : 	INCREMENT {printf("INCREMENT\n");} unary_expression
		|	DECREMENT {printf("DECREMENT\n");} unary_expression  
		|	PLUS {printf("PLUS\n");} unary_expression  
		|	MINUS {printf("MINUS\n");} unary_expression  
		|	postfix_expression 
		|	NOT {printf("NOT\n");} unary_expression 
		|	NOT_BIT {printf("NOT_BIT\n");} unary_expression 
		|	cast_expression;

cast_expression : OPEN_PAREN {printf("(\n");} primitive_type CLOSE_PAREN {printf(")\n");}unary_expression 
		| OPEN_PAREN {printf("(\n");} reference_type CLOSE_PAREN {printf(")\n");} unary_expression_not_plus_minus;

reference_type : 	class_type
		|       array_type;

class_type :	identifier;

array_type :	primitive_type OPEN_COLC {printf("[\n");} CLOSE_COLC {printf("]\n");};


unary_expression_not_plus_minus : postfix_expression 
                        | NOT_BIT unary_expression 
                        | NOT unary_expression
                        | cast_expression;

postfix_expression : primary_no_new_array postfix_expression_;		/** Regra alterada, nao pode ser um novoo array **/

postfix_expression_ : INCREMENT {printf("INCREMENT\n");} postfix_expression_              
                        | DECREMENT {printf("DECREMENT\n");} postfix_expression_
                        | /** empty **/;

statement :	statement_without_trailing_substatement
	|       identifier TWO_POINTS {printf(":\n");} statement
	|       IF {printf("IF\n");} OPEN_PAREN {printf("(\n");} expression CLOSE_PAREN {printf(")\n");} optional_else
	|       WHILE {printf("WHILE\n");} OPEN_PAREN {printf("(\n");} expression CLOSE_PAREN {printf(")\n");} statement 
	|       FOR {printf("FOR\n");} OPEN_PAREN {printf("(\n");} for_init PT_VIRGULA {printf(";\n");} expression_opt PT_VIRGULA {printf(";\n");} for_update_opt CLOSE_PAREN  {printf(")\n");}statement;

optional_else : statement
	|	statement_no_short_if ELSE {printf("ELSE\n");} statement;

for_init : statement_expression_list 
	|       local_variable_declaration 
	|	/** empty **/;

statement_expression_list : statement_expression statement_expression_list_     ;

statement_expression_list_ : VIRGULA statement_expression statement_expression_list_    
                        |	/** empty **/;

statement_expression :          primary_no_new_array assignment_operator assignment_expression /** modifiquei pq tirei a regra assignment **/
                        |       preincrement_expression 
                        |       post_incr_decrement_expression 
                        |       predecrement_expression;

preincrement_expression : INCREMENT {printf("INCREMENT\n");} unary_expression;

post_incr_decrement_expression : postfix_expression;

predecrement_expression : DECREMENT {printf("DECREMENT\n");} unary_expression;


method_invocation : 	identifier OPEN_PAREN {printf("(\n");} argument_list CLOSE_PAREN {printf(")\n");}
		|	field_access OPEN_PAREN {printf("(\n");} argument_list CLOSE_PAREN {printf(")\n");};

expression_opt : expression
		|	/** empty **/;

for_update :	statement_expression_list;

for_update_opt :	for_update
		|       /** empty **/;

statement_without_trailing_substatement : block 
                        |       empty_statement 
                        |       expression_statement 
                        |       switch_statement 
                        |       do_statement
                        |       break_statement 
                        |       continue_statement
                        |       goto_statement
                        |       return_statement;

empty_statement : PT_VIRGULA {printf(";\n");};

expression_statement :	statement_expression PT_VIRGULA {printf(";\n");};


switch_statement : SWITCH {printf("SWITCH\n");} OPEN_PAREN {printf("(\n");} expression CLOSE_PAREN {printf(")\n");} switch_block;

switch_block : BEG {printf("{\n");} switch_block_statement_groups switch_labels END {printf("}\n");};

switch_block_statement_groups : switch_block_statement_group switch_block_statement_groups_
                        |      switch_block_statement_groups_;

switch_block_statement_groups_ : switch_block_statement_group switch_block_statement_groups_ 
                        |	/** empty **/;

switch_block_statement_group : switch_labels block_statements;

switch_labels : switch_label switch_labels_     
	| 	switch_labels_ ;

switch_labels_ : switch_label switch_labels_ 
	|	/** empty **/;

switch_label : CASE {printf("CASE\n");} expression TWO_POINTS {printf(":\n");}
	|       DEFAULT {printf("DEFAULT:\n");} TWO_POINTS{printf(":\n");};


do_statement : DO {printf("DO\n");} statement WHILE {printf("WHILE\n");} OPEN_PAREN {printf("(\n");} expression CLOSE_PAREN {printf(")\n");} PT_VIRGULA{printf(";\n");};

break_statement : BREAK {printf("BREAK\n");} identifier_opt PT_VIRGULA {printf(";\n");};

continue_statement : CONTINUE {printf("CONTINUE\n");} identifier_opt PT_VIRGULA {printf(";\n");};

goto_statement : GOTO {printf("GOTO\n");}  identifier_opt PT_VIRGULA {printf(";\n");};

return_statement : RETURN {printf("RETURN\n");} expression_opt PT_VIRGULA {printf(";\n");};

identifier_opt: identifier
	|	/** empty **/;

statement_no_short_if :         statement_without_trailing_substatement 
                        |       identifier TWO_POINTS {printf(":\n");} statement_no_short_if 
                        |       IF {printf("IF\n");} OPEN_PAREN {printf("(\n");} expression CLOSE_PAREN {printf(")\n");} statement_no_short_if ELSE {printf("ELSE\n");} statement_no_short_if 
                        |       WHILE {printf("WHILE\n");} OPEN_PAREN {printf("(\n");} expression CLOSE_PAREN {printf(")\n");} statement_no_short_if 
                        |       FOR {printf("FOR\n");} OPEN_PAREN {printf("(\n");} for_init PT_VIRGULA {printf(";\n");} expression_opt PT_VIRGULA {printf(";\n");} for_update_opt CLOSE_PAREN {printf(")\n");} statement_no_short_if;

class_member_declaration_opt : class_member_declaration class_member_declaration_
			| /** empty **/;

class_member_declaration_ : class_member_declaration class_member_declaration_
			| /** empty **/;

class_member_declaration :      STATIC {printf("STATIC\n");} method_declaration
			|	STATIC {printf("STATIC\n");} field_declaration;

method_declaration :	method_header method_body;

method_header :	result_type method_declarator;

result_type :	primitive_type 
	|       VOID {printf("VOID\n");};

method_declarator :	identifier OPEN_PAREN {printf("(\n");} formal_parameter_list CLOSE_PAREN {printf(")\n");};

method_body :	block 
	|	PT_VIRGULA {printf(";\n");}              
	|	/** empty **/;

formal_parameter_list :	formal_parameter formal_parameter_list_         
		|       formal_parameter_list_;

formal_parameter_list_ : VIRGULA {printf("VIRGULA\n");} formal_parameter formal_parameter_list_
		|	/** empty **/;

formal_parameter :	primitive_type variable_declarator_id;

field_declaration :	field_modifiers primitive_type variable_declarators PT_VIRGULA {printf(";\n");}
		|	field_modifiers primitive_type OPEN_COLC {printf("[\n");} CLOSE_COLC {printf("]\n");} variable_declarators PT_VIRGULA {printf(";\n");};

field_modifiers :	field_modifier field_modifiers_                 
                |       field_modifiers_;

field_modifiers_ :	field_modifier field_modifiers_
		|       /** empty **/;

field_modifier :	FINAL {printf("FINAL\n");}
                |       TRANSIENT {printf("TRANSIENT\n");}
                |       VOLATILE {printf("VOLTATILE\n");};





%%

int main(void) {
	yydebug=0;
	return yyparse();
}

//funcao de erro - imprime linha e coluna do erro sintatico
int yyerror(char *msg){
        int tk = YYTRANSLATE(yychar);
        fprintf(stderr,"%s:\n",msg);
	fprintf(stderr,"\tLast Token: %s - %s\n",yytname[tk],yytext);
        fprintf(stderr,"\tLine %d, Column %d\n", line, column);
        return 1;
}
