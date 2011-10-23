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
#include <stdlib.h>
#include <string.h>
#include "ClassContext.h"
#include "OurConstants.h"
#include "OurStructs.h"
int yylex(void);
int yyerror(char *msg); //funcao de erro (sobrescrita)
int line = 1; //declarado no lexico
int column  = 0; // declarado no lexico
char* yytext = ""; //declarado no lexico
char* method_or_field_type = "";
int final_modifier = 0;
int context = 0;
int array_level_def = 0;
int local_level = 0;
char* id_var_local = "";

%}

%union {
        char* strval;
	char* typeval;
	int isFinal;
	int field_or_method; //field = 0, method = 1
	int levels;
}

%token CLASS BEG END STATIC PT_VIRGULA OPEN_COLC CLOSE_COLC EQUAL VIRGULA POINT
%token QUESTION_MARK TWO_POINTS OR_LOGIC AND_LOGIC OPEN_PAREN CLOSE_PAREN NEW
%token OR OR_EXC AND PLUS MINUS MULT DIV MOD INCREMENT DECREMENT NOT NOT_BIT 
%token FOR IF ELSE WHILE CASE SWITCH DEFAULT DO BREAK CONTINUE GOTO RETURN VOID
%token MAIN ARGS PUBLIC

%token FINAL

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

/** Types **/
%type <typeval> numeric_type  primitive_type integral_type floating_point_type

/** Fields and Methods **/
%type <strval> identifier 
%type <strval> variable_declarators
%type <strval> variable_declarator_id
%type <strval> variable_declarator
%type <strval> field_declaration
%type <isFinal> field_modifiers_
%type <typeval> array_creation_expression
%type <strval> method_header
%type <strval> method_declaration
%type <levels> colc_opt 
%type <levels> colc_opt_
%type <levels> dim_exprs
%type <levels> dim_expr_opt

/** Expressions **/
%type <typeval> expression
%type <typeval> conditional_expression
%type <typeval> conditional_or_expression
%type <typeval> conditional_or_expression_
%type <typeval> conditional_and_expression_ 
%type <typeval> inclusive_or_expression_ 
%type <typeval> exclusive_or_expression_ 
%type <typeval> and_expression_	
%type <typeval> equality_expression_ 
%type <typeval> relational_expression_ 
%type <typeval> shift_expression_ 
%type <typeval> additive_expression_ 
%type <typeval> multiplicative_expression_
%type <typeval> conditional_and_expression
%type <typeval> inclusive_or_expression 
%type <typeval> exclusive_or_expression 
%type <typeval> and_expression	
%type <typeval> equality_expression 
%type <typeval> relational_expression 
%type <typeval> shift_expression 
%type <typeval> additive_expression 
%type <typeval> multiplicative_expression 
%type <strval> field_access
%type <typeval> array_access
%type <typeval> left_hand_side
%type <typeval> primary_no_new_array
%type <typeval> primary_no_array
%type <typeval> unary_expression
%type <typeval> lit
%type <typeval> conditional_opt
%type <typeval> postfix_expression_
%type <typeval> expression_opt


%%	

compilation_unit :	class_declaration;

class_declaration :	CLASS identifier {createClassContext($2);setCurrentContext(GLOBAL_CONTEXT);} class_body {displayClassContext();};		

identifier :	ID;

class_body :	BEG class_body_declaration END ;

class_body_declaration : class_member_declaration_opt static_initializer /*class_member_declaration_opt*/ ;	

static_initializer :	PUBLIC STATIC VOID MAIN OPEN_PAREN TYPE_STRING OPEN_COLC CLOSE_COLC 
			ARGS CLOSE_PAREN {insertMethod("MAIN", "t_void",0);} block {checkEqualityCurrentMethodSignature();}
		|	/** empty **/;

block :		BEG {setCurrentContext(LOCAL_CONTEXT);} block_statements  END {setCurrentContext(GLOBAL_CONTEXT);};

block_statements :	block_statement block_statements_
		|       block_statements_;

block_statements_:	block_statement block_statements_ 
                |	/** empty **/;
        
block_statement :	local_variable_declaration_statement 
	|       statement;						

local_variable_declaration_statement : local_variable_declaration PT_VIRGULA local_variable_declaration_;

local_variable_declaration_ : local_variable_declaration PT_VIRGULA local_variable_declaration_
			|	/** empty **/;

local_variable_declaration :    field_modifiers_ primitive_type {method_or_field_type = $2;} variable_declarators 
				{insertVarListInCurrMethodContext($2, $1, 0);}
			|	field_modifiers_ primitive_type colc_opt_ {method_or_field_type = $2;array_level_def = $3;} variable_declarators
				{insertVarListInCurrMethodContext($2, $1, $3);};
					

primitive_type :	numeric_type 
               |       TYPE_BOOL 
               |       TYPE_STRING;

numeric_type :	     integral_type 
             |       floating_point_type;

integral_type :		TYPE_BYTE
                |       TYPE_SHORT
                |       TYPE_INT 
                |       TYPE_LONG
                |       TYPE_CHAR; 

floating_point_type :	TYPE_FLOAT 
                |       TYPE_DOUBLE;

variable_declarators :          variable_declarator {insertStringToStrList($1);} variable_declarators_ ;

variable_declarator : variable_declarator_id variable_declarator_ {$$ = $1;};

variable_declarators_ :         VIRGULA  variable_declarator {insertStringToStrList($2);} variable_declarators_	
                        |       /** empty **/;

variable_declarator_ :          EQUAL variable_initializer /** metodo que compare com o method_or_field_type **/
                        |       /** empty **/;

variable_declarator_id :        identifier {$$ = $1;}; 
 
variable_initializer :         assignment_expression /** comparar se o tipo de retorno ta certo **/
                        |       array_initializer
			|	left_hand_side;

array_initializer :	BEG variable_initializers  virgula_opt END 
			|	array_creation_expression ; 

virgula_opt :	VIRGULA
	|       /** empty **/;

variable_initializers :         variable_initializer variable_initializers_     
                        |       variable_initializers_;

variable_initializers_ :        VIRGULA variable_initializer variable_initializers_ 
                        |       /** empty **/; 

expression : assignment_expression ;

assignment_expression : conditional_expression;

field_access : identifier  {checkStaticClassId($1);} POINT identifier {$$ = $4;} ;

left_hand_side :	field_access {$$ = getVarTypevalInGlobalContext($1);}
                |       array_access {$$ = "t_array";};

assignment_operator : EQUAL
		|       ARITH_ASSIGN 
		|       SHIFT_ASSIGN 
	        |	LOGIC_ASSIGN; 

array_access : primary_no_array dim_expr dim_expr_opt /**{$$local_level = getLevelDiff()}**/;

lit : LITERAL;

primary_no_array: lit {$$ = $1;}
		| 	field_access {$$ = getVarTypevalInGlobalContext($1);}
		|	method_invocation {$$ = "t_method";}
		|	identifier {$$ = "t_type";};

primary_no_new_array : 	primary_no_array
	        | 	array_access {$$ = "t_array";};

argument_list : 	expression {addArgsToCalledMethod($1,local_level);} argument_list_
		|	argument_list_;

argument_list_ : 	VIRGULA expression {addArgsToCalledMethod($2,local_level);} argument_list_ 
                | 	/** empty **/;

array_creation_expression : NEW primitive_type {checkEqualityTypeval(method_or_field_type, $2);} dim_expr  dim_exprs {checkEqualityArrayLevel(1+$5,array_level_def);};

dim_exprs : OPEN_COLC dim_expr_or_empty CLOSE_COLC dim_exprs {$$ = $4+1;}
	|	/** empty **/  {$$ = 0;};

dim_expr: OPEN_COLC expression CLOSE_COLC;

dim_expr_or_empty : expression
		|	/** empty **/;

dim_expr_opt: dim_expr dim_expr_opt {$$ = $2+1;}
	|	/** empty **/ {$$ = 0;};

conditional_expression : conditional_or_expression  {$$ = $1;} 
                        | OPEN_PAREN conditional_or_expression CLOSE_PAREN conditional_opt
			| conditional_or_expression /** tem que retornar um boolean **/ QUESTION_MARK conditional_expression TWO_POINTS conditional_expression;
			| OPEN_PAREN conditional_or_expression CLOSE_PAREN QUESTION_MARK  conditional_expression TWO_POINTS conditional_expression; 


conditional_opt: conditional_or_expression_ /** {$$ = $1} **/
	|	conditional_and_expression_ /** {$$ = $1} **/
	|	inclusive_or_expression_ /** {$$ = $1} **/
	|	exclusive_or_expression_ /** {$$ = $1} **/
	|	and_expression_	/** {$$ = $1} **/
	|	equality_expression_ /** {$$ = $1} **/
	|	relational_expression_ /** {$$ = $1} **/
	|	shift_expression_ /** {$$ = $1} **/
	|	additive_expression_ /** {$$ = $1} **/
	|	multiplicative_expression_ /** {$$ = $1} **/
	|	/* empty */ {$$ = "t_empty";};


conditional_or_expression : conditional_and_expression conditional_or_expression_
		|	conditional_and_expression OPEN_PAREN conditional_expression CLOSE_PAREN;

conditional_or_expression_ : OR_LOGIC conditional_and_expression conditional_or_expression_ 
                        | /** empty **/;

conditional_and_expression : inclusive_or_expression conditional_and_expression_
		|	inclusive_or_expression OPEN_PAREN conditional_expression CLOSE_PAREN;

conditional_and_expression_ : AND_LOGIC inclusive_or_expression conditional_and_expression_ 
			| /** empty **/;

inclusive_or_expression : exclusive_or_expression  inclusive_or_expression_ 
		|	exclusive_or_expression  OPEN_PAREN conditional_expression CLOSE_PAREN;

inclusive_or_expression_ : OR exclusive_or_expression inclusive_or_expression_ 
                        | /** empty **/;

exclusive_or_expression : and_expression exclusive_or_expression_
		|	and_expression OPEN_PAREN conditional_expression CLOSE_PAREN;

exclusive_or_expression_ : OR_EXC and_expression exclusive_or_expression_ 
                        | /** empty **/;

and_expression : equality_expression and_expression_
		|	equality_expression OPEN_PAREN conditional_expression CLOSE_PAREN;

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
			|    unary_expression OPEN_PAREN conditional_expression  CLOSE_PAREN;

multiplicative_expression_ : MULT unary_expression multiplicative_expression_ 
                        | DIV unary_expression multiplicative_expression_ 
                        | MOD unary_expression multiplicative_expression_
			| /** empty **/ {$$ = "t_empty";};

unary_expression : 	INCREMENT unary_expression /** nao pode ser string **/
		|	DECREMENT unary_expression  /** nao pode ser string **/
		|	PLUS unary_expression  /** nao pode ser char e string **/
		|	MINUS unary_expression  /** nao pode ser char e string **/
		|	postfix_expression /** nao pode ser string **/
		|	NOT unary_expression {$$ = "t_boolean";}
		|	NOT_BIT unary_expression 
		|	cast_expression
		|	OPEN_PAREN conditional_expression CLOSE_PAREN {$$ = $2;};

cast_expression : OPEN_PAREN primitive_type CLOSE_PAREN unary_expression;

postfix_expression : primary_no_new_array postfix_expression_;		/** Regra alterada, nao pode ser um novoo array **/

postfix_expression_ : INCREMENT postfix_expression_ /** nao pode ser final **/
			| DECREMENT postfix_expression_
                        | /** empty **/ {$$ = "t_empty";};

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


method_invocation : 	identifier {addCalledMethod($1);} OPEN_PAREN argument_list CLOSE_PAREN {finishCalledMethod();}
		|	field_access OPEN_PAREN {addCalledMethod($1);} argument_list CLOSE_PAREN {finishCalledMethod();} ;

expression_opt : expression {$$ = $1;}
		|	/** empty **/ {$$ = "t_empty";};

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

class_member_declaration :     STATIC  field_modifiers_ {final_modifier = $2;} field_or_method_declaration 
			| 	PT_VIRGULA;
			
field_or_method_declaration :   primitive_type {method_or_field_type = $1;} colc_opt {array_level_def = $3;} field_or_method_declaration_rest
			|	void_method_declaration;

field_or_method_declaration_rest: method_declaration  
			|	field_declaration {
						insertVarListInGlobalContext(method_or_field_type, final_modifier,array_level_def);
						};

colc_opt: OPEN_COLC CLOSE_COLC colc_opt_ {$$ = $3+1;}
	| /** empty **/ {$$ = 0;};

colc_opt_ : OPEN_COLC CLOSE_COLC colc_opt_ {$$ = $3+1;}
	| /**empty **/ {$$ = 0;};

method_declaration :	method_header method_body {$$ = $1;};

method_header :	identifier {insertMethod($1, method_or_field_type, array_level_def);}
					method_declarator;

void_method_declaration: VOID identifier {insertMethod($2, "t_void",0);} method_declarator method_body ;

method_declarator :	OPEN_PAREN formal_parameter_list CLOSE_PAREN {checkEqualityCurrentMethodSignature();};

method_body :	block;

formal_parameter_list :	formal_parameter formal_parameter_list_         
		|       formal_parameter_list_;

formal_parameter_list_ : VIRGULA formal_parameter formal_parameter_list_
		|	/** empty **/;

formal_parameter :	primitive_type variable_declarator_id {addParamInCurrMethod($2, $1,0);}
	|	primitive_type colc_opt_ variable_declarator_id {addParamInCurrMethod($3,$1,$2);};

field_declaration :	variable_declarators PT_VIRGULA;


field_modifiers_ :	FINAL {$$ = YES;}
		|	/** empty **/ {$$ = NO;};





%%

int main(void) {
	//YY_BUFFER_STATE buffer = yy_create_buffer(stdin,10000);
	yydebug=0;
	/*yylex_destroy();
	yyrestart(stdin);
	yy_init_globals();
	yy_switch_to_buffer(buffer);
	line = 1; column = 0;
	setCurrentContext(LOCAL_CONTEXT);*/
	return yyparse();
}

//funcao de erro - imprime linha e coluna do erro sintatico
int yyerror(char *msg){
        int tk = YYTRANSLATE(yychar);
        fprintf(stderr,"%s:\n",msg);
	fprintf(stderr,"\tLast Token: %s - %s\n",yytname[tk],yytext);
        fprintf(stderr,"\tLine %d, Column %d\n", line, column);
	exit(1);
        return 1;
}


