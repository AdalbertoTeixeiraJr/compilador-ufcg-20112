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
			yyerror("Semantical Error: the class name could not be parsed (memory allocation error)");
			break;
		case(GLOBAL_VARS_LIST_INSERTION_MALLOC_ERROR):
			yyerror("Semantical Error: the field attributes could not be parsed (memory allocation error)");
			break;
		case(LOCAL_VAR_ID_ALREADY_EXISTS_ERROR):
			yyerror("Semantical Error: repeated local variables in a method");
			break;
		case(GLOBAL_VAR_ID_ALREADY_EXISTS_ERROR):
			yyerror("Semantical Error: repeated field attributes in a class");
			break;
		case(STR_LIST_INSERION_MALLOC_ERROR):
			yyerror("Semantical Error: the variable declaration could not be parsed (memory allocation error)");
			break;
		case(METHOD_CREATION_MALLOC_ERROR):
			yyerror("Semantical Error: the method signature could not be parsed (memory allocation error)");
			break;
		case(REPEATED_METHOD_PARAM_ID_ERROR):
			yyerror("Semantical Error: repeated parameter names in a method");
			break;
		case(REPEATED_METHOD_ERROR):
			yyerror("Semantical Error: repeated method signature");
			break;
		case(LOCAL_VARS_LIST_INSERTION_MALLOC_ERROR):
			yyerror("Semantical Error: the local variables could not be parsed (memory allocation error)");
			break;
		case(WRONG_STATIC_CLASS_CALL):
			yyerror("Semantical Error: the static call could not be resolved (wrong class name)");
			break;
		default:
			// do nothing
			break;
	}
}
