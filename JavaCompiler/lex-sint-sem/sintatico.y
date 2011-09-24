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

%token IF ELSE WHILE OPEN_PAREN CLOSE_PAREN
%token TYPE_INT TYPE_SHORT TYPE_LONG TYPE_BYTE TYPE_BOOL TYPE_FLOAT TYPE_DOUBLE TYPE_CHAR TYPE_STRING 
%token PT_VIRGULA VIRGULA EQUAL MULT DIV MOD PLUS MINUS TWO_POINTS OR_EXC AND OR OR_LOGIC AND_LOGIC
%token INCREMENT DECREMENT NOT NOT_BIT POINT NEW OPEN_COLC CLOSE_COLC BEG END GOTO QUESTION_MARK 
%token BREAK CASE CLASS CONTINUE DEFAULT DO FINAL FOR RETURN STATIC TRANSIENT VOLATILE SWITCH VOID

%token <strval> LITERAL
%token <strval> EQUALOP
%token <strval> RELOP
%token <strval> ID
%token <strval> SHIFTS
%token <strval> SHIFT_ASSIGN
%token <strval> ARITH_ASSIGN
%token <strval> LOGIC_ASSIGN

%%

compilation_unit :       class_declaration                                              ;

class_declaration :             CLASS identifier class_body                         ;

class_body :                            BEG class_body_declaration END                                      ;

class_body_declaration :        class_member_declaration
                        |                               static_initializer                                                      ;
        
class_member_declaration :      method_declaration
			|	field_declaration                                            ;

static_initializer :            STATIC block                                                            ;

formal_parameter_list :         formal_parameter formal_parameter_list_         
                        |       formal_parameter_list_                         ;

formal_parameter_list_ :        formal_parameter formal_parameter_list_
                        |                               /** empty **/                                                           ;

formal_parameter :                      primitive_type variable_declarator_id                                     ;

field_declaration :             field_modifiers primitive_type variable_declarators       ;

field_modifiers :               field_modifier field_modifiers_                 
                        |       field_modifiers_                                ;

field_modifiers_ :              field_modifier field_modifiers_
                        |       /** empty **/                                   ;

field_modifier :                STATIC
                        |       FINAL
                        |       TRANSIENT
                        |       VOLATILE                                        ;

variable_declarators :          variable_declarator variable_declarators_       ;

variable_declarators_ :         variable_declarator variable_declarators_
                        |       /** empty **/                                   ;

variable_declarator :           variable_declarator_id variable_declarator_     ;

variable_declarator_ :          EQUAL variable_initializer 
                        |       /** empty **/                                   ;

variable_declarator_id :        identifier       
                        |       variable_declarator_id OPEN_COLC CLOSE_COLC     ;

method_declaration :            method_header method_body                       ;

method_header :                 method_modifiers result_type method_declarator;

result_type :                   primitive_type 
                        |       VOID                                            ;

method_modifiers :              method_modifier method_modifiers_
                        |       method_modifiers_               ;

method_modifiers_ :             method_modifier method_modifiers_ 
                        |       /** empty **/                                   ;

method_modifier :               STATIC                                          ;

method_declarator :             identifier OPEN_PAREN formal_parameter_list CLOSE_PAREN           
                        |       /** empty **/                                   ;

method_body :                   block 
                        |               PT_VIRGULA              
                        |               /** empty **/                                   ;


array_initializer :             BEG variable_initializers  virgula_opt END                  ; 

/* Virgula opcional do for (criacao nossa)*/
virgula_opt :                VIRGULA
                        |       /** empty **/                                   ;

variable_initializers :         variable_initializer variable_initializers_     
                        |       variable_initializers_                          ;

variable_initializers_ :        variable_initializer variable_initializers_ 
                        |       /** empty **/                                   ;

variable_initializer :          expression
                        |       array_initializer                               ;

/* 
**      Types   **
*/

primitive_type :                numeric_type 
                        |       TYPE_BOOL
                        |       TYPE_STRING                                  ;

numeric_type :                  integral_type 
                        |       floating_point_type                             ;

integral_type :                 TYPE_BYTE 
                        |       TYPE_SHORT 
                        |       TYPE_INT 
                        |       TYPE_LONG 
                        |       TYPE_CHAR                                            ;

floating_point_type :           TYPE_FLOAT
                        |       TYPE_DOUBLE                                          ;

reference_type :                class_type 
                        |       array_type                                      ;

class_type :                    identifier                                       ;

array_type :                    primitive_type OPEN_COLC CLOSE_COLC                       ;

/*
**      Blocks and commands     **
*/

block :                         BEG block_statements END      ;

block_statements :              block_statement block_statements_               
                        |       block_statements_                               ;

block_statements_:              block_statement block_statements_ 
                        |       /** empty **/                                   ;
        
block_statement :               local_variable_declaration_statement 
                        |       statement                                       ;
        
local_variable_declaration_statement : local_variable_declaration PT_VIRGULA ;

local_variable_declaration :    primitive_type variable_declarators                       ;

statement :                     statement_without_trailing_substatement
                        |       identifier TWO_POINTS statement 
                        |       IF OPEN_PAREN expression CLOSE_PAREN statement      
                        |       IF OPEN_PAREN expression CLOSE_PAREN statement_no_short_if ELSE statement 
                        |       WHILE OPEN_PAREN expression CLOSE_PAREN statement 
                        |       FOR OPEN_PAREN for_init PT_VIRGULA expression_opt PT_VIRGULA for_update_opt CLOSE_PAREN statement                 ;

statement_no_short_if :         statement_without_trailing_substatement 
                        |       identifier TWO_POINTS statement_no_short_if 
                        |       IF OPEN_PAREN expression CLOSE_PAREN statement_no_short_if ELSE statement_no_short_if 
                        |       WHILE OPEN_PAREN expression CLOSE_PAREN statement_no_short_if 
                        |       FOR OPEN_PAREN for_init PT_VIRGULA expression_opt PT_VIRGULA for_update_opt CLOSE_PAREN 
                                                        statement_no_short_if   ;

statement_without_trailing_substatement : block 
                        |       empty_statement 
                        |       expression_statement 
                        |       switch_statement 
                        |       do_statement
                        |       break_statement
                        |       continue_statement
                        |       goto_statement
                        |       return_statement                                ;

empty_statement :               PT_VIRGULA                      ;

expression_statement :          statement_expression PT_VIRGULA                         ;

statement_expression :          assignment 
                        |       preincrement_expression 
                        |       postincrement_expression 
                        |       predecrement_expression 
                        |       postdecrement_expression 
                        |       method_invocation               ;


switch_statement : SWITCH OPEN_PAREN expression CLOSE_PAREN switch_block   ;

switch_block : BEG switch_block_statement_groups switch_labels END        ;

switch_block_statement_groups : switch_block_statement_group switch_block_statement_groups_
                        |      switch_block_statement_groups_     ;

switch_block_statement_groups_ : switch_block_statement_group switch_block_statement_groups_ 
                        |                                               /** empty **/                                           ;

switch_block_statement_group : switch_labels block_statements                   ;

switch_labels : switch_label switch_labels_     
						| 	switch_labels_ ;

switch_labels_ : switch_label switch_labels_ 
                        |                                               /** empty **/                                           ;

switch_label : CASE expression TWO_POINTS
                        |       DEFAULT TWO_POINTS                                                                              ;


do_statement : DO statement WHILE OPEN_PAREN expression CLOSE_PAREN PT_VIRGULA                                             ;

for_init : statement_expression_list 
                        |       local_variable_declaration                                                              
                        |                                       /** empty **/                                                   ;

for_update : statement_expression_list                                                                  ;

for_update_opt :                for_update
                        |       /** empty **/                                   ;

statement_expression_list : statement_expression statement_expression_list_     ;

statement_expression_list_ : VIRGULA statement_expression statement_expression_list_    
                        |                                       /** empty **/                                                   ;

break_statement : BREAK identifier_opt PT_VIRGULA                                                                  ;

continue_statement : CONTINUE identifier_opt PT_VIRGULA    ;

goto_statement : GOTO  identifier_opt PT_VIRGULA                                                                  ;

return_statement : RETURN expression_opt PT_VIRGULA        ;

/*
**      Expression      **
*/

expression : assignment_expression      ;

/* Expressao opcional do for (criacao nossa)*/
expression_opt :                expression
                        |       /** empty **/                                   ;

assignment_expression : conditional_expression 
                        |       left_hand_side assignment_operator assignment_expression                ;

assignment : left_hand_side assignment_operator assignment_expression   ;

left_hand_side :       field_access 
                        |       array_access                                                                                    ;

assignment_operator : EQUAL 
                        |       ARITH_ASSIGN 
                        |       SHIFT_ASSIGN
                        |       LOGIC_ASSIGN                                                                                                        ;

conditional_expression : conditional_or_expression 
                        | conditional_or_expression QUESTION_MARK expression TWO_POINTS conditional_expression       ;

conditional_or_expression : conditional_and_expression conditional_or_expression_        ;

conditional_or_expression_ : OR_LOGIC conditional_and_expression conditional_or_expression_ 
                        | /** empty **/                                                                                                                         ;

conditional_and_expression : inclusive_or_expression conditional_and_expression_        ;

conditional_and_expression_ : AND_LOGIC inclusive_or_expression conditional_and_expression_ 
                        | /** empty **/                                                                                                 ;

inclusive_or_expression : exclusive_or_expression  inclusive_or_expression_     ;

inclusive_or_expression_ : OR exclusive_or_expression inclusive_or_expression_ 
                        | /** empty **/                                                                                                 ;

exclusive_or_expression : and_expression exclusive_or_expression_      ;

exclusive_or_expression_ : OR_EXC and_expression exclusive_or_expression_ 
                        | /** empty **/                                                                                                 ;

and_expression : equality_expression and_expression_    ;

and_expression_ : AND_LOGIC equality_expression and_expression_ 
                        | /** empty **/                                                                                                 ;

equality_expression : relational_expression equality_expression_                        ;

equality_expression_ : EQUALOP relational_expression equality_expression_
                        |       /** empty **/                                                                                           ;

relational_expression : shift_expression relational_expression_                         ;

relational_expression_ : RELOP shift_expression relational_expression_ 
                        | /** empty **/                                                                                                 ;

shift_expression : additive_expression shift_expression_                                        ;

shift_expression_ : SHIFTS additive_expression shift_expression_ 
                        | /** empty **/                                                                                                 ;

additive_expression : multiplicative_expression additive_expression_            ;

additive_expression_ : PLUS multiplicative_expression additive_expression_ 
                        | MINUS multiplicative_expression additive_expression_                  ;

multiplicative_expression : unary_expression multiplicative_expression_         ;

multiplicative_expression_ : MULT unary_expression multiplicative_expression_ 
                        | DIV unary_expression multiplicative_expression_ 
                        | MOD unary_expression multiplicative_expression_                               ;

cast_expression : OPEN_PAREN primitive_type OPEN_PAREN unary_expression 
                        | OPEN_PAREN reference_type CLOSE_PAREN unary_expression_not_plus_minus;

unary_expression : INCREMENT unary_expression 
                        | DECREMENT unary_expression 
                        | PLUS unary_expression 
                        | MINUS unary_expression 
                        | postfix_expression 
                        | NOT unary_expression 
                        | NOT_BIT unary_expression 
                        | cast_expression                                                                                               ;

predecrement_expression : DECREMENT unary_expression                                            ;

preincrement_expression : INCREMENT unary_expression                                            ;

unary_expression_not_plus_minus : postfix_expression 
                        | NOT_BIT unary_expression 
                        | NOT unary_expression
                        | cast_expression                                                                                               ;

postdecrement_expression : postfix_expression DECREMENT                                         ;

postincrement_expression : postfix_expression INCREMENT                                         ;

postfix_expression : primary postfix_expression_                                            ;

postfix_expression_ : INCREMENT postfix_expression_              
                        | DECREMENT postfix_expression_
                        | /** empty **/                                                                                                 ;

method_invocation : identifier OPEN_PAREN argument_list CLOSE_PAREN 
                        | primary POINT identifier OPEN_PAREN argument_list CLOSE_PAREN;

field_access : identifier POINT identifier                                                                         ;

primary : primary_no_new_array 
                        | array_creation_expression                                                                             ;

primary_no_new_array : LITERAL 
                                | field_access 
                                | method_invocation 
                                | array_access                                                                                          ;

argument_list : expression argument_list_
				| argument_list_                                                                       ;

argument_list_ : VIRGULA expression argument_list_ 
                                | /** empty **/                                                                                         ;

array_creation_expression : NEW primitive_type dim_exprs dims                          ;

dim_exprs : dim_expr dim_exprs_                                                                                         ;

dim_exprs_ : dim_expr dim_exprs_ 
                                | /** empty **/                                                                                         ;

dim_expr : OPEN_COLC expression CLOSE_COLC      ;

dims : OPEN_COLC CLOSE_COLC dims_       
		| dims_;

dims_ : OPEN_COLC CLOSE_COLC dims_ 
                                | /** empty **/                                                                                         ;

array_access : field_access OPEN_COLC expression CLOSE_COLC 
                                | primary_no_new_array OPEN_COLC expression CLOSE_COLC          ;

/* NOSSO IDENTIFIER */

identifier : ID;

identifier_opt :                 identifier
                        |       /** empty **/                                   ;

                                
%%

int main(void) {
        return yyparse();
}

//funcao de erro - imprime linha e coluna do erro sintatico
int yyerror(char *msg){
        int tk = YYTRANSLATE(yychar);
        fprintf(stderr,"%s:\n",msg);
	fprintf(stderr,"\tLast Token: %s - %s\n",yytname[tk],yytext);
        fprintf(stderr,"\tLine %d, Column %d\n", line, col);
        return 1;
}
