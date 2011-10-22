/*
 ============================================================================
 Name        : OurConstants.h
 Author      : Andrey Menezes, Adalberto Teixeira e Augusto Queiroz
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#ifndef OURCONSTANTS_H_
#define OURCONSTANTS_H_

/**************** CONSTANT DEFINITIONS ***************/

#define MAX_ID_SIZE 128
#define MAX_TYPEVAL_SIZE 20
#define ERROR_MSG_MAX_SIZE 256

#define OK	1

#define YES	1
#define NO	0

#define LOCAL_CONTEXT	10
#define GLOBAL_CONTEXT	20

// SIMPLE ERROR CONSTANTS
#define INEXISTANT_ID_IN_CONTEXT							-10

// IMPORTANT ERROR CONSTANTS
// INTERNAL MALLOC ERRORS
#define CLASSCONTEX_CREATION_MALLOC_ERROR					-1
#define METHOD_CREATION_MALLOC_ERROR						-2
#define CALLED_METHOD_CREATION_MALLOC_ERROR					-3
#define GLOBAL_VARS_LIST_INSERTION_MALLOC_ERROR				-4
#define LOCAL_VARS_LIST_INSERTION_MALLOC_ERROR				-5
#define STR_LIST_INSERION_MALLOC_ERROR						-6
#define CALLED_METHOD_LINE_COLLUMN_CREATION_MALLOC_ERROR	-13

// REAL SEMANTIC ERROS
#define GLOBAL_VAR_ID_ALREADY_EXISTS_ERROR					-7
#define LOCAL_VAR_ID_ALREADY_EXISTS_ERROR					-8
#define WRONG_STATIC_CLASS_CALL								-9
#define REPEATED_METHOD_ERROR								-10
#define REPEATED_METHOD_PARAM_ID_ERROR						-11
#define WRONG_METHOD_CALL									-12


/*********** PUBLIC FUNCTION DECLARATIONS ************/
void treatErrorResults(int val);

/************ EXTERN FUNCTION DECLARATIONS ************/
extern int yyerror(char *msg);

#endif /* OURCONSTANTS_H_ */
