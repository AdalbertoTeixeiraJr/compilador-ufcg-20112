/*
** Projeto Compiladores - 2011.2 **
** UFCG - DSC                    **     
** Prof.: Franklin Ramalho       **
** Equipe:                       **
**      Adalberto Teixeira       **
**      Andrey Menezes           **
**      Augusto Macedo           **
** Ling. Fonte: Java             **
*/

%{
#include <stdio.h>
#include <string.h>
int yylex(void);
int yyerror(char *msg); //funcao de erro (sobrescrita)
int line = 1; //declarado no lexico
int column  = 0; // declarado no lexico
char* yytext = ""; //declarado no lexico
%}

%union {
        char* strval;
	char* typeval;
}

%token CLASS BEG END STATIC PT_VIRGULA OPEN_COLC CLOSE_COLC EQUAL VIRGULA POINT
%token QUESTION_MARK TWO_POINTS OR_LOGIC AND_LOGIC OPEN_PAREN CLOSE_PAREN NEW
%token OR OR_EXC AND PLUS MINUS MULT DIV MOD INCREMENT DECREMENT NOT NOT_BIT 
%token FOR IF ELSE WHILE CASE SWITCH DEFAULT DO BREAK CONTINUE GOTO RETURN VOID
%token MAIN ARGS PUBLIC

%token FINAL TRANSIENT VOLATILE

%token <strval> EQUALOP
%token <strval> RELOP
%token <strval> SHIFTS
%token <strval> SHIFT_ASSIGN
%token <strval> ARITH_ASSIGN
%token <strval> LOGIC_ASSIGN
%token <strval> ID

%token <typeval> TYPE_INT TYPE_SHORT TYPE_LONG TYPE_BYTE TYPE_BOOL 
%token <typeval> TYPE_FLOAT TYPE_DOUBLE TYPE_CHAR TYPE_STRING


%token <strval, typeval> LITERAL


%type <typeval> numeric_type  primitive_type integral_type floating_point_type
%type <typeval> variable_declarators /*variable_declarator variable_declarator_id
%type <typeval> variable_declarators_ variable_declarator_*/


%%	

compilation_unit :	class_declaration;

class_declaration :	CLASS identifier class_body;						

identifier :	ID ;

class_body :	BEG class_body_declaration END;

class_body_declaration :	 class_member_declaration_opt static_initializer class_member_declaration_opt;	

static_initializer :	PUBLIC STATIC VOID MAIN OPEN_PAREN TYPE_STRING OPEN_COLC CLOSE_COLC 
			ARGS CLOSE_PAREN block;

block :		BEG block_statements END;

block_statements :	block_statement block_statements_
		|       block_statements_;

block_statements_:	block_statement block_statements_ 
                |	/** empty **/;
        
block_statement :	local_variable_declaration_statement 
	|       statement;						

local_variable_declaration_statement : local_variable_declaration PT_VIRGULA local_variable_declaration_;

local_variable_declaration_ : local_variable_declaration PT_VIRGULA
			|	/** empty **/;

local_variable_declaration :    primitive_type variable_declarators
			|	primitive_type OPEN_COLC CLOSE_COLC variable_declarators;
						

primitive_type :	numeric_type 
               |       TYPE_BOOL 
               |       TYPE_STRING;

numeric_type :	integral_type 
             |       floating_point_type;

integral_type :		TYPE_BYTE
                |       TYPE_SHORT
                |       TYPE_INT 
                |       TYPE_LONG
                |       TYPE_CHAR; 

floating_point_type :	TYPE_FLOAT 
                |       TYPE_DOUBLE;

variable_declarators :          variable_declarator variable_declarators_ /*{$1 = $0;} $2 = $0;}*/;

variable_declarator :           variable_declarator_id variable_declarator_ /*{$1 = $0; $2 = $0;}*/;

variable_declarators_ :         VIRGULA  variable_declarator variable_declarators_ /*{$2 = $0, $3 = $0;}*/
                        |       /** empty **/;

variable_declarator_ :          EQUAL variable_initializer 
                        |       /** empty **/;

variable_declarator_id :        identifier /*{$1 = $0;}*/; 
 
variable_initializer :         assignment_expression
                        |       array_initializer
			|	left_hand_side;

array_initializer :	BEG variable_initializers  virgula_opt END
			|	array_creation_expression; 

virgula_opt :	VIRGULA
	|       /** empty **/;

variable_initializers :         variable_initializer variable_initializers_     
                        |       variable_initializers_;

variable_initializers_ :        VIRGULA variable_initializer variable_initializers_ 
                        |       /** empty **/; 

expression : assignment_expression;

assignment_expression : conditional_expression;

field_access : identifier POINT identifier;

left_hand_side :	field_access 
                |       array_access;

assignment_operator : EQUAL
		|       ARITH_ASSIGN 
		|       SHIFT_ASSIGN 
	        |	LOGIC_ASSIGN; 

array_access : primary_no_new_array OPEN_COLC expression CLOSE_COLC;

primary_no_new_array : 	LITERAL 
		| 	field_access 
		|	method_invocation 
	        | 	array_access
		|	identifier;

argument_list : 	expression argument_list_
		|	argument_list_;

argument_list_ : 	VIRGULA expression argument_list_ 
                | 	/** empty **/;

array_creation_expression : NEW primitive_type dim_exprs dims;

dim_exprs : OPEN_COLC dim_expr_or_empty CLOSE_COLC;

dim_expr_or_empty : expression
		|	/** empty **/;

dims: dim_exprs
	| 	/**empty**/;



conditional_expression : conditional_or_expression 
                        | OPEN_PAREN conditional_or_expression CLOSE_PAREN conditional_opt
			| conditional_or_expression QUESTION_MARK conditional_expression TWO_POINTS conditional_expression;
			| OPEN_PAREN conditional_or_expression CLOSE_PAREN QUESTION_MARK  conditional_expression TWO_POINTS conditional_expression;


conditional_opt: conditional_or_expression_ 
	|	conditional_and_expression_
	|	inclusive_or_expression_
	|	exclusive_or_expression_
	|	and_expression_	
	|	equality_expression_
	|	relational_expression_
	|	shift_expression_
	|	additive_expression_
	|	multiplicative_expression_
	|	/* empty */;


conditional_or_expression : conditional_and_expression conditional_or_expression_
		|	conditional_and_expression OPEN_PAREN conditional_expression CLOSE_PAREN;

conditional_or_expression_ : OR_LOGIC conditional_and_expression conditional_or_expression_ 
                        | /** empty **/;

conditional_and_expression : inclusive_or_expression conditional_and_expression_
		|	inclusive_or_expression OPEN_PAREN conditional_expression CLOSE_PAREN;

conditional_and_expression_ : AND_LOGIC inclusive_or_expression conditional_and_expression_ 
			| /** empty **/;

inclusive_or_expression : exclusive_or_expression  inclusive_or_expression_ 
		|	exclusive_or_expression  OPEN_PAREN conditional_expression CLOSE_PAREN    ;

inclusive_or_expression_ : OR exclusive_or_expression inclusive_or_expression_ 
                        | /** empty **/;

exclusive_or_expression : and_expression exclusive_or_expression_
		|	and_expression OPEN_PAREN conditional_expression CLOSE_PAREN;

exclusive_or_expression_ : OR_EXC and_expression exclusive_or_expression_ 
                        | /** empty **/;

and_expression : equality_expression and_expression_
		|	equality_expression OPEN_PAREN conditional_expression CLOSE_PAREN   ;

and_expression_ : AND equality_expression and_expression_ 
                        | /** empty **/;

equality_expression : relational_expression equality_expression_
		|	relational_expression OPEN_PAREN conditional_expression CLOSE_PAREN;

equality_expression_ : EQUALOP relational_expression equality_expression_
                        |       /** empty **/;

relational_expression : shift_expression relational_expression_
		|	shift_expression OPEN_PAREN conditional_expression CLOSE_PAREN;

relational_expression_ : RELOP shift_expression relational_expression_ 
                        | /** empty **/;

shift_expression : additive_expression shift_expression_
		|	additive_expression OPEN_PAREN conditional_expression CLOSE_PAREN;

shift_expression_ : SHIFTS additive_expression shift_expression_ 
                        | /** empty **/;

additive_expression : multiplicative_expression additive_expression_
		|	multiplicative_expression OPEN_PAREN conditional_expression CLOSE_PAREN;

additive_expression_ : PLUS multiplicative_expression additive_expression_
                        | MINUS multiplicative_expression additive_expression_
			| /** empty **/;

multiplicative_expression : unary_expression multiplicative_expression_  
			|    unary_expression OPEN_PAREN conditional_expression  CLOSE_PAREN  ;

multiplicative_expression_ : MULT unary_expression multiplicative_expression_ 
                        | DIV unary_expression multiplicative_expression_ 
                        | MOD unary_expression multiplicative_expression_
			| /** empty **/;

unary_expression : 	INCREMENT unary_expression
		|	DECREMENT unary_expression  
		|	PLUS unary_expression  
		|	MINUS unary_expression  
		|	postfix_expression 
		|	NOT unary_expression 
		|	NOT_BIT unary_expression 
		|	cast_expression
		|	OPEN_PAREN conditional_expression CLOSE_PAREN;

cast_expression : OPEN_PAREN primitive_type CLOSE_PAREN unary_expression 
		| OPEN_PAREN reference_type CLOSE_PAREN unary_expression_not_plus_minus;

reference_type : 	class_type
		|       array_type;

class_type :	identifier;

array_type :	primitive_type OPEN_COLC CLOSE_COLC;


unary_expression_not_plus_minus : postfix_expression 
                        | NOT_BIT unary_expression 
                        | NOT unary_expression
                        | cast_expression;

postfix_expression : primary_no_new_array postfix_expression_;		/** Regra alterada, nao pode ser um novoo array **/

postfix_expression_ : INCREMENT postfix_expression_
			| DECREMENT postfix_expression_
                        | /** empty **/;

statement :	statement_without_trailing_substatement
	|       identifier TWO_POINTS statement
	|       IF OPEN_PAREN expression CLOSE_PAREN optional_else
	|       WHILE OPEN_PAREN expression CLOSE_PAREN statement 
	|       FOR OPEN_PAREN for_init PT_VIRGULA expression_opt PT_VIRGULA for_update_opt CLOSE_PAREN  statement;

optional_else : statement
	|	statement_no_short_if ELSE statement;

for_init : statement_expression_list 
	|       local_variable_declaration 
	|	/** empty **/;

statement_expression_list : statement_expression statement_expression_list_     ;

statement_expression_list_ : VIRGULA statement_expression statement_expression_list_    
                        |	/** empty **/;

statement_expression :          primary_no_new_array assignment_operator assignment_expression
                        |       preincrement_expression 
                        |       post_incr_decrement_expression 
                        |       predecrement_expression;

preincrement_expression : INCREMENT unary_expression;

post_incr_decrement_expression : postfix_expression;

predecrement_expression : DECREMENT unary_expression;


method_invocation : 	identifier OPEN_PAREN argument_list CLOSE_PAREN 
		|	field_access OPEN_PAREN argument_list CLOSE_PAREN
		|	LITERAL POINT identifier OPEN_PAREN argument_list CLOSE_PAREN;

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

empty_statement : PT_VIRGULA;

expression_statement :	statement_expression PT_VIRGULA;


switch_statement : SWITCH OPEN_PAREN expression CLOSE_PAREN switch_block;

switch_block : BEG switch_block_statement_groups switch_labels END;

switch_block_statement_groups : switch_block_statement_group switch_block_statement_groups_
                        |      switch_block_statement_groups_;

switch_block_statement_groups_ : switch_block_statement_group switch_block_statement_groups_ 
                        |	/** empty **/;

switch_block_statement_group : switch_labels block_statements;

switch_labels : switch_label switch_labels_     
	| 	switch_labels_ ;

switch_labels_ : switch_label switch_labels_ 
	|	/** empty **/;

switch_label : CASE expression TWO_POINTS
	|       DEFAULT TWO_POINTS;


do_statement : DO statement WHILE OPEN_PAREN expression CLOSE_PAREN PT_VIRGULA;

break_statement : BREAK identifier_opt PT_VIRGULA;

continue_statement : CONTINUE identifier_opt PT_VIRGULA;

goto_statement : GOTO identifier_opt PT_VIRGULA;

return_statement : RETURN expression_opt PT_VIRGULA;

identifier_opt: identifier
	|	/** empty **/;

statement_no_short_if :         statement_without_trailing_substatement 
                        |       identifier TWO_POINTS statement_no_short_if 
                        |       IF OPEN_PAREN  expression CLOSE_PAREN  statement_no_short_if ELSE statement_no_short_if 
                        |       WHILE OPEN_PAREN expression CLOSE_PAREN statement_no_short_if 
                        |       FOR OPEN_PAREN for_init PT_VIRGULA expression_opt PT_VIRGULA for_update_opt CLOSE_PAREN statement_no_short_if;

class_member_declaration_opt : class_member_declaration class_member_declaration_
			| /** empty **/;

class_member_declaration_ : class_member_declaration class_member_declaration_
			| /** empty **/;

class_member_declaration :     STATIC field_or_method_declaration
			
field_or_method_declaration : field_declaration
			| 	method_declaration;

method_declaration :	method_header method_body;

method_header :	result_type method_declarator;

result_type :	primitive_type
	|	array_type 
	|       VOID;

method_declarator :	identifier OPEN_PAREN formal_parameter_list CLOSE_PAREN;

method_body :	block
	|	PT_VIRGULA              
	|	/** empty **/;

formal_parameter_list :	formal_parameter formal_parameter_list_         
		|       formal_parameter_list_;

formal_parameter_list_ : VIRGULA formal_parameter formal_parameter_list_
		|	/** empty **/;

formal_parameter :	primitive_type variable_declarator_id 
	|	array_type variable_declarator_id ;

field_declaration :	field_modifiers_ primitive_type variable_declarators PT_VIRGULA 
						{$3 = $2;}
		|	field_modifiers_ primitive_type OPEN_COLC CLOSE_COLC variable_declarators PT_VIRGULA {$5 = $2;};


field_modifiers_ :	field_modifier field_modifiers_
		|	/** empty **/;

field_modifier :	FINAL
                |       TRANSIENT
                |       VOLATILE;





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