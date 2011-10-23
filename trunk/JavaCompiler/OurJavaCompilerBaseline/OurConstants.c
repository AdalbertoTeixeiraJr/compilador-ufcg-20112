/*
 ============================================================================
 Name        : OurConstants.c
 Author      : Andrey Menezes, Adalberto Teixeira e Augusto Queiroz
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#include "OurConstants.h"

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
		case(DIFFERENT_TYPE_DEFINITION_DECLARATION):
			yyerror("Semantical Error: the type definition does not correspond to the declaration type");
			break;
		default:
			// do nothing
			break;
	}
}
