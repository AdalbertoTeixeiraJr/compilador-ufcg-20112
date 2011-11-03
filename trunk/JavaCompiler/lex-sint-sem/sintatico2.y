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
int yylex(void);
int yyerror(char *msg); //funcao de erro (sobrescrita)
int line = 1; //declarado no lexico
int column  = 0; // declarado no lexico
char* yytext = ""; //declarado no lexico
char* method_or_field_type = "_______________________";
int final_modifier = 0;
int context = 0;
int array_level_def = 0;
int local_level = 0;
char* id_var_local = "_______________________";
char* type_expr_prec = "_______________________";
int final_update = 0; //0 = not isFinal, 1 = isFinal
int level_access = 0;
char* switch_type = "_______________________";
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
%type <strval> identifier_opt 
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
%type <typeval> assignment_expression
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
%type <typeval> unary_expression
%type <typeval> cast_expression
%type <strval> field_access
%type <typeval> array_access
%type <typeval> left_hand_side
%type <typeval> primary_no_new_array
%type <typeval> primary_no_array
%type <typeval> lit
%type <typeval> conditional_opt
%type <typeval> postfix_expression_
%type <typeval> expression_opt
%type <typeval> method_invocation
%type <typeval> postfix_expression


%%	

compilation_unit :	class_declaration;

class_declaration :	CLASS identifier {createClassContext($2);setCurrentContext(GLOBAL_CONTEXT);} class_body {displayClassContext();};		

identifier :	ID;

class_body :	BEG class_body_declaration END ;

class_body_declaration : class_member_declaration_opt static_initializer /*class_member_declaration_opt*/ ;	

static_initializer :	PUBLIC STATIC VOID MAIN OPEN_PAREN TYPE_STRING OPEN_COLC CLOSE_COLC 
			ARGS CLOSE_PAREN {insertMethod("main", "t_void",0);} block {checkRepeatedCurrentMethodSignature();}
		|	/** empty **/;


block :		BEG {setCurrentContext(LOCAL_CONTEXT);} block_statements_  END {setCurrentContext(GLOBAL_CONTEXT);};

block_statements_:	{printf("");} block_statement block_statements_ 
                |	/** empty **/;
        
block_statement :	local_variable_declaration_statement
	|       statement;						

local_variable_declaration_statement : local_variable_declaration PT_VIRGULA;

local_variable_declaration :    field_modifiers_ primitive_type {method_or_field_type = $2; array_level_def = 0;} variable_declarators {insertVarListInCurrMethodContext($2, $1, 0);}
			|	   field_modifiers_ primitive_type colc_opt_ {method_or_field_type = $2;array_level_def = $3;} variable_declarators {insertVarListInCurrMethodContext($2, $1, $3);};
					

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

variable_declarator : variable_declarator_id variable_declarator_ {$$ = $1;};/*array_level_def = 0; local_level = 0;*/

variable_declarators_ :         VIRGULA  variable_declarator {insertStringToStrList($2);} variable_declarators_	
                        |       /** empty **/;

variable_declarator_ :          EQUAL variable_initializer 
                        |       /** empty **/;

variable_declarator_id :        identifier {$$ = $1;}; 
 
variable_initializer :        assignment_expression {checkEqualsTypeval(method_or_field_type,$1); checkEqualsArrayLevel(array_level_def, local_level); array_level_def = 0; local_level = 0;}
                        |left_hand_side {checkEqualsTypeval(method_or_field_type,$1); checkEqualsArrayLevel(array_level_def, local_level); array_level_def = 0; local_level = 0;}
			|	array_initializer;

array_initializer :	BEG  {local_level++;} variable_initializers  virgula_opt END {local_level--;}
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

left_hand_side :	array_access {$$ = getVarTypevalInBothContexts($1);}
		|	field_access {$$ = getVarTypevalInGlobalContext($1);}; /* local_level = local_level+getVarArrayLevelInGlobalContext($1); */

assignment_operator : EQUAL
		|       ARITH_ASSIGN 
		|       SHIFT_ASSIGN 
	    |		LOGIC_ASSIGN; 

array_access : identifier dim_expr dim_expr_opt { $$ = $1; local_level = $3+1; level_access = $3+1;level_access = isVarFinalInBothContexts($1); array_level_def = getVarArrayLevelInGlobalContext($1);}
		|	field_access dim_expr dim_expr_opt {local_level = $3+1; level_access = $3+1;level_access = isVarFinalInGlobalContext($1);};

lit : LITERAL;

primary_no_array : lit {$$ = $1; level_access = 0; final_update = 0;}
		| 	field_access {$$ = getVarTypevalInGlobalContext($1); 
				level_access = getVarArrayLevelInGlobalContext($1), 
				final_update = isVarFinalInGlobalContext($1);} 
		|	method_invocation {$$ = $1;
				level_access = checkMethodLevelsAfterConversion();
				final_update = 1;}
		|	identifier {$$ = getVarTypevalInBothContexts($1);
				level_access = getVarArrayLevelInBothContexts($1);
				final_update = isVarFinalInBothContexts($1);};

primary_no_new_array : 	primary_no_array 
	        | 	array_access {$$ = getVarTypevalInBothContexts($1);};

argument_list : 	expression {addArgsToCalledMethod($1,local_level);} argument_list_
		|	argument_list_;

argument_list_ : 	VIRGULA expression {addArgsToCalledMethod($2,local_level);} argument_list_ 
                | 	/** empty **/;

array_creation_expression : NEW primitive_type {checkEqualsTypeval(method_or_field_type, $2);} dim_expr  dim_exprs {checkEqualsArrayLevel(1+$5,array_level_def);};

dim_exprs : OPEN_COLC dim_expr_or_empty CLOSE_COLC dim_exprs {$$ = $4+1;}
	|	/** empty **/  {$$ = 0;};

dim_expr: OPEN_COLC expression {checkArrayCreationExpression($2);} CLOSE_COLC;

dim_expr_or_empty : expression {checkArrayCreationExpression($1);}
		|	/** empty **/;

dim_expr_opt: dim_expr dim_expr_opt {$$ = $2+1;}
	|	/** empty **/ {$$ = 0;};

conditional_expression : conditional_or_expression  {$$ = $1;} 
                        | OPEN_PAREN conditional_or_expression CLOSE_PAREN conditional_opt {$$ = chooseBinaryOperation($2, $4,type_expr_prec);}
			| conditional_or_expression {checkIsBoolean($1);} QUESTION_MARK conditional_expression TWO_POINTS conditional_expression {$$ = checkQuestionMarkOperator($4,$6);};
			| OPEN_PAREN conditional_or_expression CLOSE_PAREN {checkIsBoolean($2);} QUESTION_MARK  conditional_expression TWO_POINTS conditional_expression {$$ = checkQuestionMarkOperator($6,$8);};

conditional_opt: conditional_or_expression_  {$$ = $1;type_expr_prec = "or";} 
	|	conditional_and_expression_  {$$ = $1;type_expr_prec = "and";} 
	|	inclusive_or_expression_  {$$ = $1;type_expr_prec = "inc_or";} 
	|	exclusive_or_expression_  {$$ = $1;type_expr_prec = "exc_or";} 
	|	and_expression_	 {$$ = $1;type_expr_prec = "and_bit";} 
	|	equality_expression_ {$$ = $1;type_expr_prec = "equal";} 
	|	relational_expression_  {$$ = $1;type_expr_prec = "relop";} 
	|	shift_expression_  {$$ = $1;type_expr_prec = "shift";} 
	|	additive_expression_  {$$ = $1;type_expr_prec = "add";} 
	|	multiplicative_expression_  {$$ = $1;type_expr_prec = "mult";} 
	|	/** empty **/ {$$ = "t_empty";type_expr_prec = "empty";};

conditional_or_expression : conditional_and_expression conditional_or_expression_ {$$ = checkConditionalAndOrOperator($1,$2);}
		|	conditional_and_expression OPEN_PAREN conditional_expression CLOSE_PAREN {$$ = checkConditionalAndOrOperator($1,$3);};

conditional_or_expression_ : OR_LOGIC conditional_and_expression conditional_or_expression_ {$$ = checkConditionalAndOrOperator($2,$3);}
                        | /** empty **/ {$$ = "t_empty";};

conditional_and_expression : inclusive_or_expression conditional_and_expression_ {$$ = checkConditionalAndOrOperator($1,$2);}
		|	inclusive_or_expression OPEN_PAREN conditional_expression CLOSE_PAREN {$$ = checkConditionalAndOrOperator($1,$3);};

conditional_and_expression_ : AND_LOGIC inclusive_or_expression conditional_and_expression_ {$$ = checkConditionalAndOrOperator($2,$3);}
			| /** empty **/ {$$ = "t_empty";};

inclusive_or_expression : exclusive_or_expression  inclusive_or_expression_ {$$ = checkBitwiseLogicalOperator($1,$2);}
		|	exclusive_or_expression  OPEN_PAREN conditional_expression CLOSE_PAREN {$$ = checkBitwiseLogicalOperator($1,$3);};

inclusive_or_expression_ : OR exclusive_or_expression inclusive_or_expression_ {$$ = checkBitwiseLogicalOperator($2,$3);}
                        | /** empty **/ {$$ = "t_empty";};

exclusive_or_expression : and_expression exclusive_or_expression_ {$$ = checkBitwiseLogicalOperator($1,$2);}
		|	and_expression OPEN_PAREN conditional_expression CLOSE_PAREN {$$ = checkBitwiseLogicalOperator($1,$3);};

exclusive_or_expression_ : OR_EXC and_expression exclusive_or_expression_ {$$ = checkBitwiseLogicalOperator($2,$3);}
                        | /** empty **/ {$$ = "t_empty";};

and_expression : equality_expression and_expression_ {$$ = checkBitwiseLogicalOperator($1,$2);}
		|	equality_expression OPEN_PAREN conditional_expression CLOSE_PAREN {$$ = checkBitwiseLogicalOperator($1,$3);};

and_expression_ : AND equality_expression and_expression_ {$$ = checkBitwiseLogicalOperator($2,$3);}
                        | /** empty **/ {$$ = "t_empty";};

equality_expression : relational_expression equality_expression_ {$$ = checkEqualityOperator($1,$2);}
		|	relational_expression OPEN_PAREN conditional_expression CLOSE_PAREN {$$ = checkEqualityOperator($1,$3);};

equality_expression_ : EQUALOP relational_expression equality_expression_ {$$ = checkEqualityOperator($2,$3);}
                        |       /** empty **/ {$$ = "t_empty";};

relational_expression : shift_expression relational_expression_ {$$ = checkRelationalOperator($1,$2);}
		|	shift_expression OPEN_PAREN conditional_expression CLOSE_PAREN {$$ = checkRelationalOperator($1,$3);};

relational_expression_ : RELOP shift_expression relational_expression_ {$$ = checkRelationalOperator($2,$3);}
                        | /** empty **/ {$$ = "t_empty";};

shift_expression : additive_expression shift_expression_ {$$ = checkShiftOperator($1,$2);}
		|	additive_expression OPEN_PAREN conditional_expression CLOSE_PAREN {$$ = checkShiftOperator($1,$3);};

shift_expression_ : SHIFTS additive_expression shift_expression_ {$$ = checkShiftOperator($2,$3);} 
                        | /** empty **/ {$$ = "t_empty";};

additive_expression : multiplicative_expression additive_expression_ {$$ = checkBinaryExpressionResultType($1,$2);} 
		|	multiplicative_expression OPEN_PAREN conditional_expression CLOSE_PAREN {$$ = checkBinaryExpressionResultType($1,$3);};

additive_expression_ : PLUS multiplicative_expression additive_expression_ {$$ = checkBinaryExpressionResultType($2,$3);}
                        | MINUS multiplicative_expression additive_expression_ {$$ = checkBinaryExpressionResultType($2,$3);}
			| /** empty **/ {$$ = "t_empty";};

multiplicative_expression :  unary_expression multiplicative_expression_ {$$ = checkBinaryExpressionResultType($1,$2);};

multiplicative_expression_ : MULT unary_expression multiplicative_expression_ {$$ = checkBinaryExpressionResultType($2,$3);}
                        | DIV unary_expression multiplicative_expression_ {$$ = checkBinaryExpressionResultType($2,$3);}
                        | MOD unary_expression multiplicative_expression_ {$$ = checkBinaryExpressionResultType($2,$3);}
			| /** empty **/ {$$ = "t_empty";};

unary_expression : 	INCREMENT unary_expression {checkNumericalType($2);$$ = $2;}
		|	DECREMENT unary_expression  {checkNumericalType($2);$$ = $2;}
		|	PLUS unary_expression  {checkNumericalType($2);$$ = $2;}
		|	MINUS unary_expression  {checkNumericalType($2);$$ = $2;}
		|	postfix_expression {$$ = $1;}
		|	NOT unary_expression {checkIsBoolean($2);$$ = $2;}
		|	NOT_BIT unary_expression {checkNumericalType($2);$$ = $2;}
		|	cast_expression {$$ = $1;}
		|	OPEN_PAREN conditional_expression CLOSE_PAREN {$$ = $2;};

cast_expression : OPEN_PAREN primitive_type CLOSE_PAREN unary_expression {checkCastingConversion($4,$2); $$ = $2;};

postfix_expression : primary_no_array postfix_expression_  {$$ = $1;checkIncrementDecrement($1, $2, final_update);};	

postfix_expression_ : INCREMENT postfix_expression_ {$$ = "t_inc_dec";}
			| DECREMENT postfix_expression_ {$$ = "t_inc_dec";}
                        | /** empty **/ {$$ = "t_empty";};

statement :	statement_without_trailing_substatement
	|       identifier {addLabel($1);} TWO_POINTS statement
	|       IF OPEN_PAREN expression {checkIsBoolean($3);} CLOSE_PAREN optional_else
	|       WHILE OPEN_PAREN expression {checkIsBoolean($3);} CLOSE_PAREN statement 
	|       FOR OPEN_PAREN for_init PT_VIRGULA expression_opt {checkIsEmptyOrBool($5);} PT_VIRGULA for_update_opt CLOSE_PAREN  statement;

optional_else : statement
	|	statement_no_short_if ELSE statement;

for_init : statement_expression_list 
	|       local_variable_declaration 
	|	/** empty **/;

statement_expression_list : statement_expression statement_expression_list_     ;

statement_expression_list_ : VIRGULA statement_expression statement_expression_list_    
                        |	/** empty **/;

statement_expression :          primary_no_new_array assignment_operator assignment_expression {checkIncrementDecrement($1, "t_update", final_update);}
                        |       preincrement_expression 
                        |       post_incr_decrement_expression 
                        |       predecrement_expression;

preincrement_expression : INCREMENT unary_expression {checkIncrementDecrement($2, "t_inc", final_update);};

post_incr_decrement_expression : postfix_expression;

predecrement_expression : DECREMENT unary_expression {checkIncrementDecrement($2, "t_dec", final_update);} ;


method_invocation : 	identifier {addCalledMethod($1);} OPEN_PAREN argument_list CLOSE_PAREN {$$ = checkMethodConversion();}
		|	field_access OPEN_PAREN {addCalledMethod($1);} argument_list CLOSE_PAREN {$$ = checkMethodConversion();} ;

expression_opt : expression {$$ = $1;}
		|	/** empty **/ {$$ = "t_empty";};

for_update :	statement_expression_list;

for_update_opt :	for_update
		|       /** empty **/;

statement_without_trailing_substatement : block /* falta */
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


switch_statement : SWITCH OPEN_PAREN expression {checkIsSwitchExpression($3);switch_type = $3;} CLOSE_PAREN switch_block;

switch_block : BEG switch_block_statement_groups switch_labels END;

switch_block_statement_groups : switch_block_statement_group switch_block_statement_groups_
                        |      switch_block_statement_groups_;

switch_block_statement_groups_ : switch_block_statement_group switch_block_statement_groups_ 
                        |	/** empty **/;

switch_block_statement_group : switch_labels block_statements_;

switch_labels : switch_label switch_labels_     
	| 	switch_labels_ ;

switch_labels_ : switch_label switch_labels_ 
	|	/** empty **/;

switch_label : CASE expression {checkEqualsTypeval($2,switch_type);} TWO_POINTS
	|       DEFAULT TWO_POINTS;


do_statement : DO statement WHILE OPEN_PAREN expression {checkIsBoolean($5);} CLOSE_PAREN PT_VIRGULA;

break_statement : BREAK identifier_opt {checkLabelInCurrMethod($2);} PT_VIRGULA;

continue_statement : CONTINUE identifier_opt {checkLabelInCurrMethod($2);} PT_VIRGULA;

goto_statement : GOTO identifier {checkLabelInCurrMethod($2);} PT_VIRGULA;

return_statement : RETURN expression_opt {checkReturnTypeInCurrMethod(method_or_field_type, $2);} PT_VIRGULA;

identifier_opt: identifier {$$ = $1;}
	|	/** empty **/ {$$ = "id_empty";};

statement_no_short_if :         statement_without_trailing_substatement 
                        |       identifier {addLabel($1);} TWO_POINTS statement_no_short_if 
                        |       IF OPEN_PAREN  expression {checkIsBoolean($3);} CLOSE_PAREN  statement_no_short_if ELSE statement_no_short_if 
                        |       WHILE OPEN_PAREN expression {checkIsBoolean($3);} CLOSE_PAREN statement_no_short_if 
                        |       FOR OPEN_PAREN for_init PT_VIRGULA expression_opt {checkIsEmptyOrBool($5);} PT_VIRGULA for_update_opt CLOSE_PAREN statement_no_short_if;

class_member_declaration_opt : class_member_declaration class_member_declaration_
			| /** empty **/;

class_member_declaration_ : class_member_declaration class_member_declaration_
			| /** empty **/;

class_member_declaration :     STATIC  field_modifiers_ {final_modifier = $2;} field_or_method_declaration 
			| 	PT_VIRGULA;
			
field_or_method_declaration :   primitive_type {method_or_field_type = $1;} colc_opt {array_level_def = $3;} field_or_method_declaration_rest
			|	void_method_declaration;

field_or_method_declaration_rest: method_declaration  
			|	field_declaration {insertVarListInGlobalContext(method_or_field_type, final_modifier,array_level_def); array_level_def = 0;};

colc_opt: OPEN_COLC CLOSE_COLC colc_opt_ {$$ = $3+1;}
	| /** empty **/ {$$ = 0;};

colc_opt_ : OPEN_COLC CLOSE_COLC colc_opt_ {$$ = $3+1;}
	| /**empty **/ {$$ = 0;};

method_declaration :	method_header method_body {$$ = $1;};

method_header :	identifier {insertMethod($1, method_or_field_type, array_level_def); array_level_def = 0; printf("tipo metodo: %s, array level: %d\n",method_or_field_type, array_level_def); }
					method_declarator;

void_method_declaration: VOID identifier {insertMethod($2, "t_void", 0);} method_declarator method_body ;

method_declarator :	OPEN_PAREN formal_parameter_list CLOSE_PAREN {checkRepeatedCurrentMethodSignature();};

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




