/*
 ============================================================================
 Name        : OurConstants.c
 Author      : Andrey Menezes, Adalberto Teixeira e Augusto Queiroz
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include "OurConstants.h"

int translateTypevalToInt(char * typeval){

	if(typeval == NULL){
		return OUR_NULL;
	}
	if (strcmp("t_null", typeval) == 0){
		return OUR_NULL;
	}else if(strcmp("t_boolean", typeval) == 0){
		return OUR_BOOLEAN;
	}else if(strcmp("t_char", typeval) == 0){
		return OUR_CHAR;
	}else if(strcmp("t_string", typeval) == 0){
		return OUR_STRING;
	}else if(strcmp("t_int", typeval) == 0){
		return OUR_INT;
	}else if(strcmp("t_float", typeval) == 0){
		return OUR_FLOAT;
	}else if(strcmp("t_double", typeval) == 0){
		return OUR_DOUBLE;
	}else if(strcmp("t_hex", typeval) == 0){
		return OUR_HEXA;
	}else if(strcmp("t_oct", typeval) == 0){
		return OUR_OCTAL;
	}else if(strcmp("t_byte", typeval) == 0){
		return OUR_BYTE;
	}else if(strcmp("t_long", typeval) == 0){
		return OUR_LONG;
	}else if(strcmp("t_short", typeval) == 0){
		return OUR_SHORT;
	}else if(strcmp("t_void", typeval) == 0){
		return OUR_VOID;
	}else if(strcmp("t_empty", typeval) == 0){
		return OUR_EMPTY;
	}else{
		return OUR_NULL;
	}
}

void treatErrorResults(int val){
	switch(val){
		case(OK):
			break;
		case(CLASSCONTEX_CREATION_MALLOC_ERROR):
			yyerror("Semantical Error: the class name could not be parsed (internal memory allocation error)");
			break;
		case(CALLED_METHOD_CREATION_MALLOC_ERROR):
			yyerror("Semantical Error: the method call could not be parsed (internal memory allocation error)");
			break;
		case(METHOD_CREATION_MALLOC_ERROR):
			yyerror("Semantical Error: the method signature could not be parsed (internal memory allocation error)");
			break;
		case(GLOBAL_VARS_LIST_INSERTION_MALLOC_ERROR):
			yyerror("Semantical Error: the field attributes could not be parsed (internal memory allocation error)");
			break;
		case(LOCAL_VARS_LIST_INSERTION_MALLOC_ERROR):
			yyerror("Semantical Error: the local variables could not be parsed (memory allocation error)");
			break;
		case(STR_LIST_INSERION_MALLOC_ERROR):
			yyerror("Semantical Error: the variable declaration could not be parsed (internal memory allocation error)");
			break;
		case(CALLED_METHOD_LINE_COLLUMN_CREATION_MALLOC_ERROR):
			yyerror("Semantical Error: the called method line collumn could not be stored (internal memory allocation error)");
			break;
		case(GLOBAL_VAR_ID_ALREADY_EXISTS_ERROR):
			yyerror("Semantical Error: repeated field attributes in a class");
			break;
		case(LOCAL_VAR_ID_ALREADY_EXISTS_ERROR):
			yyerror("Semantical Error: repeated local variables in a method");
			break;
		case(WRONG_STATIC_CLASS_CALL):
			yyerror("Semantical Error: the static call could not be resolved (wrong class name)");
			break;
		case(REPEATED_METHOD_PARAM_ID_ERROR):
			yyerror("Semantical Error: repeated parameter names in a method");
			break;
		case(REPEATED_METHOD_ERROR):
			yyerror("Semantical Error: repeated method signature");
			break;
		case(WRONG_METHOD_CALL):
			yyerror("Semantical Error: there is no declared method for this method call");
			break;
		case(DIFFERENT_ARRAY_LEVEL_DEFINITION_DECLARATION):
			yyerror("Semantical Error: the array is being defined with a different level from the declaration");
			break;
		case(DIFFERENT_TYPES):
			yyerror("Semantical Error: the types do not correspond to each other");
			break;
		case(INEXISTENT_DECLARED_METHOD_WITH_ID):
			yyerror("Semantical Error: there is not a method with this name");
			break;
		case(WRONG_CASTING_OPERATION):
			yyerror("Semantical Error: this casting operation is not allowed");
			break;
		case(WRONG_BOOLEAN_CHECK):
			yyerror("Semantical Error: this expression should return a boolean type");
			break;
		case(WRONG_FINAL_UPDATE):
			yyerror("Semantical Error: final variables cannot be updated");
			break;
		case(WRONG_NUMERICAL_TYPE):
			yyerror("Semantical Error: this is not a numerical type");
			break;
		case(WRONG_IMPLICIT_CONVERSION):
			yyerror("Semantical Error: the implicit conversion could not be executed");
			break;
		case(WRONG_ASSIGN_CONVERSION):
			yyerror("Semantical Error: the assignment conversion could not be executed");
			break;
		case(WRONG_BINARY_NUMERIC_EXPRESSION):
			yyerror("Semantical Error: the binary expression is not allowed");
			break;
		case(WRONG_SHIFT_OPERATION):
			yyerror("Semantical Error: the shift operation is not allowed");
			break;
		case(WRONG_EQUALITY_OPERATION):
			yyerror("Semantical Error: the equality operation is not allowed");
			break;
		case(WRONG_RELATIONAL_OPERATION):
			yyerror("Semantical Error: the relational operation is not allowed");
			break;
		case(WRONG_QUESTION_MARK_OPERATION):
			yyerror("Semantical Error: the question mark operation is not allowed");
			break;
		case(WRONG_OPERATION):
			yyerror("Semantical Error: this operation does not exist");
			break;
		case(WRONG_ARRAY_CREATION_EXPRESSION):
			yyerror("Semantical Error: the array creation expression should contains an integral type");
			break;
		case(NO_VAR_FOUND_IN_BOTH_CONTEXTS):
			yyerror("Semantical Error: there is no variable with this id (nor local neither global contexts)");
			break;
		case(REPEATED_LABEL_IN_SAME_METHOD):
			yyerror("Semantical Error: repeated label in the same method");
			break;
		case(NOT_BOOL_OR_EMPTY):
			yyerror("Semantical Error: the type is neither boolean nor empty expression");
			break;
		case(NO_LABEL_FOUND):
			yyerror("Semantical Error: there is no label with this name");
			break;
		case(WRONG_SWITCH_EXPRESSION):
			yyerror("Semantical Error: this is not a switch expression allowed type");
			break;
		case(WRONG_RETURN_TYPE_IN_CURR_METHOD):
			yyerror("Semantical Error: the type returned does not correspond to the method declaration");
			break;
		case(DIFFERENT_RETURNED_ARRAY_LEVEL_IN_CURR_METHOD):
			yyerror("Semantical Error: the returned array level does not correspond to the method declaration");
			break;
		case(NO_RETURN_DECLARATION):
			yyerror("Semantical Error: this method must return a value");
			break;
		case(WRONG_UPDATE_OF_FINAL_VAR):
			yyerror("Semantical Error: wrong update of final variable");
			break;
		default:
			printf("INTERNAL ERROR, TRY DEBUGGING IT (%d)", val);
			break;
	}
}
