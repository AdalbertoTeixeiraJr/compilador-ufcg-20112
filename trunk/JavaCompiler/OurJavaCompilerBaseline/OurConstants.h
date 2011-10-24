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

// TYPE CONSTANTS
#define OUR_NULL 			0
#define OUR_BOOLEAN 		1
#define OUR_INT 			2
#define OUR_FLOAT 			3
#define OUR_DOUBLE 			4
#define OUR_CHAR 			5
#define OUR_STRING 			6
#define OUR_HEXA 			7
#define OUR_OCTAL 			8
#define OUR_BYTE 			9
#define OUR_LONG 			10
#define OUR_SHORT 			11
#define OUR_EMPTY 			12

// CONVERSION CONSTANTS
#define IDENTITY_CONVERSION 1
#define WIDENING_CONVERSION 2
#define NARROWING_CONVERSION 3

// SIMPLE ERROR CONSTANTS
#define INEXISTANT_ID_IN_CONTEXT							-10
#define CALLED_METHOD_IS_NULL								-17

// IMPORTANT ERROR CONSTANTS
// INTERNAL MALLOC ERRORS
#define CLASSCONTEX_CREATION_MALLOC_ERROR					-1
#define METHOD_CREATION_MALLOC_ERROR						-2
#define CALLED_METHOD_CREATION_MALLOC_ERROR					-3
#define GLOBAL_VARS_LIST_INSERTION_MALLOC_ERROR				-4
#define LOCAL_VARS_LIST_INSERTION_MALLOC_ERROR				-5
#define STR_LIST_INSERION_MALLOC_ERROR						-6
#define CALLED_METHOD_LINE_COLLUMN_CREATION_MALLOC_ERROR	-13

// REAL SEMANTIC ERRORS
#define GLOBAL_VAR_ID_ALREADY_EXISTS_ERROR					-7
#define LOCAL_VAR_ID_ALREADY_EXISTS_ERROR					-8
#define WRONG_STATIC_CLASS_CALL								-9
#define REPEATED_METHOD_ERROR								-10
#define REPEATED_METHOD_PARAM_ID_ERROR						-11
#define WRONG_METHOD_CALL									-12
#define DIFFERENT_ARRAY_LEVEL_DEFINITION_DECLARATION		-14
#define DIFFERENT_TYPE_DEFINITION_DECLARATION				-15
#define INEXISTENT_DECLARED_METHOD_WITH_ID					-16
#define WRONG_CASTING_OPERATION								-17
#define WRONG_BOOLEAN_CHECK									-18
#define WRONG_FINAL_UPDATE									-19
#define WRONG_NUMERICAL_TYPE								-20
#define WRONG_IMPLICIT_CONVERSION							-21
#define WRONG_ASSIGN_CONVERSION								-22
#define WRONG_BINARY_NUMERIC_EXPRESSION						-23
#define WRONG_SHIFT_OPERATION								-24
#define WRONG_EQUALITY_OPERATION							-25
#define WRONG_RELATIONAL_OPERATION							-26
#define WRONG_QUESTION_MARK_OPERATION						-27
#define WRONG_OPERATION										-28
#define WRONG_ARRAY_CREATION_EXPRESSION						-29


/*********** PUBLIC FUNCTION DECLARATIONS ************/
void treatErrorResults(int val);

/************ EXTERN FUNCTION DECLARATIONS ************/
extern int yyerror(char *msg);

#endif /* OURCONSTANTS_H_ */
