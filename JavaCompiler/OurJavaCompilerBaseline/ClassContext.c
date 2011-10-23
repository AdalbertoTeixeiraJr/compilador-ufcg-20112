/*
 ============================================================================
 Name        : ClassContext.c
 Author      : Andrey Menezes, Adalberto Teixeira e Augusto Queiroz
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "ClassContext.h"

/*************** STATIC FUNCTIONS ***************/
//// GETTING
static VarNode * getVarInGlobalContext(char * id);
static MethodNode * getFirstMethodWithId(char * idName);

static MethodNode * getCurrentMethod();
static VarNode * getVarInCurrMethodContext(char * id);
static char * getVarTypevalInCurrMethodContext (char * id);

//// STRLIST
static StrNode * createStrNode(char * str);
static StrNode * getIdInStrList(char * id);
static void freeStrList();

//// CHECKERS
int translateTypevalToInt(char * typeval);
static int checkIdentityConversion(char * typeFrom, char * typeTo);
static int checkWideningConversion(char * typeFrom, char * typeTo);
static int checkNarrowingConversion(char * typeFrom, char * typeTo);

/*************** GLOBAL VARIABLES ***************/
ClassContext * classContext = NULL;
StrNode * strList = NULL;
MethodNode * calledMethod = NULL;
int currentContext = GLOBAL_CONTEXT;


/*
 * CLASSCONTEXT FUNCTION DEFINITIONS
 */

void setCurrentContext(int context){
	currentContext = context;
}

/*
 * STATIC FUNCTIONS
 */

static VarNode * getVarInGlobalContext(char * id){
	return getVarNodeInList(classContext->varsContext, id);
}

static MethodNode * getFirstMethodWithId(char * idName){
	return getMethodNodeInList(classContext->methodContext, idName);
}


//// CREATING

void createClassContext(char * className){

	CHECK_GLOBAL_CONTEXT(currentContext);

	int result = OK;
	classContext = (ClassContext*) malloc(sizeof(ClassContext));

	if (classContext != NULL){
		classContext->name = (char *) malloc(sizeof(char) * MAX_ID_SIZE);
		if (classContext->name != NULL){
			strcpy(classContext->name, className);
		}else{
			result = CLASSCONTEX_CREATION_MALLOC_ERROR;
		}
		classContext->varsContext = NULL;
		classContext->methodContext = NULL;
	}else{
		result = CLASSCONTEX_CREATION_MALLOC_ERROR;
	}

	CHECK_RESULT(result);
}

//// INSERTING

void insertVarListInGlobalContext(char * typeval, int isFinal, int arrayLevels){
	if (currentContext != GLOBAL_CONTEXT){
		freeStrList();
		return;
	}else{
		int result = OK;
		StrNode * strNode = strList;
		VarNode * nodeTmp = NULL;

		while(strNode != NULL){
			nodeTmp = insertVarInVarNodeList(classContext->varsContext, strNode->str, typeval, isFinal, arrayLevels);
			if (nodeTmp != NULL){
				classContext->varsContext = nodeTmp;
				strNode = strNode->next;
			}else{
				result = GLOBAL_VARS_LIST_INSERTION_MALLOC_ERROR;
				break;
			}
		}
		freeStrList();

		CHECK_RESULT(result);
	}
}

void insertMethod(char * idName, char * typeReturn, int arrayLevels){
	CHECK_GLOBAL_CONTEXT(currentContext);

	int result = OK;

	MethodNode * newMethod;
	MethodNode * methodList = classContext->methodContext;

	newMethod = createMethodNode(idName, typeReturn, arrayLevels);
	if (newMethod != NULL){
		if (methodList == NULL){
			classContext->methodContext = newMethod;
		}else{
			while(methodList->next != NULL){
				methodList = methodList->next;
			}
			methodList->next = newMethod;
		}
	}else{
		result = METHOD_CREATION_MALLOC_ERROR;
	}

	CHECK_RESULT(result);
}

//// GETTING

char * getVarTypevalInGlobalContext (char * id){
	char * result = NULL;
	VarNode * node = getVarNodeInList(classContext->varsContext, id);

	if (node != NULL){
		result = node->typeval;
	}
	return result;
}

int getVarArrayLevelInGlobalContext (char * id){
	int result = -1;
	VarNode * node = getVarNodeInList(classContext->varsContext, id);

	if (node != NULL){
		result = node->arrayLevels;
	}
	return result;
}

//// FREEING

void freeClassContext(){
	free(classContext->name);
	freeVarNodeList(classContext->varsContext);
	freeMethodList(classContext->methodContext);
	free(classContext);
}

//// DISPLAYING

void displayClassContext(){
	printf("CLASS NAME: %s\n\n", classContext->name);
	printf(" -- GLOBAL VARS CONTEXT --\n");
	displayVarNodeList(classContext->varsContext);
	printf("\n -- METHOD'S CONTEXT --\n");
	displayMethodNodeList(classContext->methodContext);
}


/*
 * METHOD FUNCTION DEFINITIONS
 */

/*
 * STATIC FUNCTIONS
 */

static MethodNode * getCurrentMethod(){
	return getLastMethodNodeInList(classContext->methodContext);
}

static char * getVarTypevalInCurrMethodContext (char * id){
	char * result = NULL;
	VarNode * node = getVarNodeInList(getCurrentMethod()->varNodes, id);

	if (node != NULL){
		result = node->typeval;
	}
	return result;
}

/*
 * PUBLIC FUNCTIONS
 */

// INSERTING

void addParamInCurrMethod(char * id, char * typeval, int arrayLevels){

	CHECK_GLOBAL_CONTEXT(currentContext);

	int result = OK;
	MethodNode * curMethod = getCurrentMethod();
	if (getVarNodeInList(curMethod->params, id) == NULL){
		curMethod = addParamInMethod(curMethod, id, typeval, arrayLevels);
	}else{
		result = REPEATED_METHOD_PARAM_ID_ERROR;
	}

	CHECK_RESULT(result);
}

void insertVarListInCurrMethodContext(char * typeval, int isFinal, int arrayLevels){
	if (currentContext != LOCAL_CONTEXT){
		freeStrList();
		return;
	}else{
		int result = OK;

		// GET THE CURRENT METHOD
		MethodNode * methodNode = getCurrentMethod();

		// INSERT THE VAR LIST AT THE METHOD VAR LIST
		StrNode * strNode = strList;
		VarNode * nodeTmp = NULL;

		while(strNode != NULL){
			nodeTmp = insertVarInVarNodeList(methodNode->varNodes, strNode->str, typeval, isFinal, arrayLevels);
			if (nodeTmp != NULL){
				methodNode->varNodes = nodeTmp;
				strNode = strNode->next;
			}else{
				result = LOCAL_VARS_LIST_INSERTION_MALLOC_ERROR;
				break;
			}
		}
		freeStrList();

		CHECK_RESULT(result);
	}
}

// GETTING

VarNode * getVarInCurrMethodContext(char * id){
	return getVarNodeInList(getCurrentMethod()->varNodes, id);
}

/*
 * == AUXILIAR ===== STRING NODE FUNCTION DEFINITIONS
 */

/*
 * STATIC FUNCTIONS
 */

static StrNode * createStrNode(char * str){

	StrNode * node;

	node = (StrNode*) malloc(sizeof(StrNode));

	if (node != NULL){
		node->str = (char *) malloc(sizeof(char) * MAX_ID_SIZE);
		if (node->str != NULL){
			strcpy(node->str, str);
		}else{
			node = NULL;
		}
		node->next = NULL;
	}else{
		node = NULL;
	}
	return node;
}

static StrNode * getIdInStrList(char * id){

	StrNode * strNode = strList;

	while(strNode != NULL){
		if (strcmp(strNode->str, id) == 0){
			break;
		}
		strNode = strNode->next;
	}

	return strNode;
}

static void freeStrList(){
	StrNode * tmp;
	while(strList != NULL){
		tmp = strList;
		strList = strList->next;
		free(tmp->str);
		free(tmp);
	}
}

/*
 * PUBLIC FUNCTIONS
 */

void insertStringToStrList(char * id){

	int result = OK;
	StrNode * node = strList;

	// IS THERE ANOTHER OF THIS? IT DEPENDS ON THE CONTEXT...
	if(currentContext == LOCAL_CONTEXT){
		if (getIdInStrList(id) != NULL ||
			getVarInCurrMethodContext(id) != NULL ||
			getVarNodeInList(getCurrentMethod()->params, id) != NULL){
			result = LOCAL_VAR_ID_ALREADY_EXISTS_ERROR;
		}
	}else{
		if (getVarInGlobalContext(id) != NULL || getIdInStrList(id) != NULL){
			result = GLOBAL_VAR_ID_ALREADY_EXISTS_ERROR;
		}
	}

	// IF THERE ISN'T THIS ID, WE INCLUDE IT IN THE LIST
	if (result == OK){
		if (node != NULL){
			while(node->next != NULL){
				node = node->next;
			}
			node->next = createStrNode(id);
			if (node->next == NULL){
				result = STR_LIST_INSERION_MALLOC_ERROR;
			}
		}else{
			strList = createStrNode(id);
			if (strList == NULL){
				result = STR_LIST_INSERION_MALLOC_ERROR;
			}
		}
	}

	CHECK_RESULT(result);
}

void addCalledMethod(char * idName){
	int result = OK;

	MethodNode * newMethod;

	if (getFirstMethodWithId(idName) != NULL){

		newMethod = createMethodNode(idName, "NULL", 0);

		if (newMethod != NULL){
			calledMethod = newMethod;
		}else{
			result = CALLED_METHOD_CREATION_MALLOC_ERROR;
		}
	}else{
		result = INEXISTENT_DECLARED_METHOD_WITH_ID;
	}

	CHECK_RESULT(result);
}

void addArgsToCalledMethod(char * typeval, int arrayLevels){
	int result = OK;

	if (calledMethod != NULL){
		calledMethod = addParamInMethod(calledMethod, "ID_DEFAULT", typeval, arrayLevels);
	}else{
		result = CALLED_METHOD_IS_NULL;
	}

	CHECK_RESULT(result);
}

/*************** SEMANTIC CHECK FUNCTIONS ***************/

/*
 * STATIC FUNCTIONS
 */

int translateTypevalToInt(char * typeval){
	if (strcmp(typeval, "t_null") == 0){
		return OUR_NULL;
	}else if(strcmp(typeval, "t_boolean") == 0){
		return OUR_BOOLEAN;
	}else if(strcmp(typeval, "t_char") == 0){
		return OUR_CHAR;
	}else if(strcmp(typeval, "t_string") == 0){
		return OUR_STRING;
	}else if(strcmp(typeval, "t_int") == 0){
		return OUR_INT;
	}else if(strcmp(typeval, "t_float") == 0){
		return OUR_FLOAT;
	}else if(strcmp(typeval, "t_double") == 0){
		return OUR_DOUBLE;
	}else if(strcmp(typeval, "t_hex") == 0){
		return OUR_HEXA;
	}else if(strcmp(typeval, "t_oct") == 0){
		return OUR_OCTAL;
	}else if(strcmp(typeval, "t_byte") == 0){
		return OUR_BYTE;
	}else if(strcmp(typeval, "t_long") == 0){
		return OUR_LONG;
	}else if(strcmp(typeval, "t_short") == 0){
		return OUR_SHORT;
	}else{
		return OUR_NULL;
	}
}

static int checkIdentityConversion(char * typeFrom, char * typeTo){
	return (strcmp(typeFrom, typeTo) == 0) ? YES : NO;
}

static int checkWideningConversion(char * typeFrom, char * typeTo){
	int result = NO;
	int ourTypeFrom = translateTypevalToInt(typeFrom);
	int ourTypeTo = translateTypevalToInt(typeTo);

	switch(ourTypeFrom){
		case(OUR_BYTE):
			if(ourTypeTo == OUR_SHORT ||
				ourTypeTo == OUR_INT ||
				ourTypeTo == OUR_LONG ||
				ourTypeTo == OUR_FLOAT ||
				ourTypeTo == OUR_DOUBLE){
				result = YES;
			}
			break;
		case(OUR_SHORT):
			if(ourTypeTo == OUR_INT ||
				ourTypeTo == OUR_LONG ||
				ourTypeTo == OUR_FLOAT ||
				ourTypeTo == OUR_DOUBLE){
				result = YES;
			}
			break;
		case(OUR_CHAR):
			if(ourTypeTo == OUR_INT ||
				ourTypeTo == OUR_LONG ||
				ourTypeTo == OUR_FLOAT ||
				ourTypeTo == OUR_DOUBLE){
				result = YES;
			}
			break;
		case(OUR_INT):
			if(ourTypeTo == OUR_LONG ||
				ourTypeTo == OUR_FLOAT ||
				ourTypeTo == OUR_DOUBLE){
				result = YES;
			}
			break;
		case(OUR_LONG):
			if(ourTypeTo == OUR_FLOAT ||
				ourTypeTo == OUR_DOUBLE){
				result = YES;
			}
			break;
		case(OUR_FLOAT):
			if(ourTypeTo == OUR_DOUBLE){
				result = YES;

			}
			break;
		default:
			break;
	}

	/*
	 * byte to short, int, long, float, or double
	 * short to int, long, float, or double
	 * char to int, long, float, or double
	 * int to long, float, or double
	 * long to float or double
	 * float to double
	 */

	return result;
}

static int checkNarrowingConversion(char * typeFrom, char * typeTo){
	int result = NO;
	int ourTypeFrom = translateTypevalToInt(typeFrom);
	int ourTypeTo = translateTypevalToInt(typeTo);

	switch(ourTypeFrom){
		case(OUR_SHORT):
			if(ourTypeTo == OUR_BYTE ||
				ourTypeTo == OUR_CHAR){
				result = YES;
			}
			break;
		case(OUR_CHAR):
			if(ourTypeTo == OUR_BYTE ||
				ourTypeTo == OUR_SHORT){
				result = YES;
			}
			break;
		case(OUR_INT):
			if(ourTypeTo == OUR_BYTE ||
				ourTypeTo == OUR_SHORT ||
				ourTypeTo == OUR_CHAR){
				result = YES;
			}
			break;
		case(OUR_LONG):
			if(ourTypeTo == OUR_BYTE ||
				ourTypeTo == OUR_SHORT ||
				ourTypeTo == OUR_CHAR ||
				ourTypeTo == OUR_INT){
				result = YES;
			}
			break;
		case(OUR_FLOAT):
			if(ourTypeTo == OUR_BYTE ||
				ourTypeTo == OUR_SHORT ||
				ourTypeTo == OUR_CHAR ||
				ourTypeTo == OUR_INT ||
				ourTypeTo == OUR_LONG){
				result = YES;
			}
			break;
		case(OUR_DOUBLE):
			if(ourTypeTo == OUR_BYTE ||
				ourTypeTo == OUR_SHORT ||
				ourTypeTo == OUR_CHAR ||
				ourTypeTo == OUR_INT ||
				ourTypeTo == OUR_LONG ||
				ourTypeTo == OUR_FLOAT){
				result = YES;
			}
			break;
		default:
			break;
	}
	/*
	 * short to byte or char
	 * char to byte or short
	 * int to byte, short, or char
	 * long to byte, short, char, or int
	 * float to byte, short, char, int, or long
	 * double to byte, short, char, int, long, or float
	 */

	return result;
}


/*
 * PUBLIC FUNCTIONS
 */

void checkStaticClassId(char * id){
	int result = (strcmp(classContext->name, id) == 0) ? OK : WRONG_STATIC_CLASS_CALL;
	CHECK_RESULT(result);
}

void checkEqualityCurrentMethodSignature(){
	CHECK_GLOBAL_CONTEXT(currentContext);

	int result = OK;

	// NOW WE CHECK FOR EQUALITY
	MethodNode * methodList = classContext->methodContext;
	MethodNode * curMethod = getCurrentMethod();

	if(methodList != NULL){
		while (methodList->next != NULL){
			if (isMethodEqual(methodList, curMethod) == YES){
				result = REPEATED_METHOD_ERROR;
				break;
			}
			methodList = methodList->next;
		}
	}

	CHECK_RESULT(result);
}

void checkEqualityArrayLevel(int declarationLevel, int definitionLevel){
	int result = (declarationLevel == definitionLevel)? OK: DIFFERENT_ARRAY_LEVEL_DEFINITION_DECLARATION;
	CHECK_RESULT(result);
}

void checkEqualityTypeval(char * declarationLevel, char * definitionLevel){
	int result = (strcmp(declarationLevel,definitionLevel)== 0)? OK: DIFFERENT_TYPE_DEFINITION_DECLARATION;
	CHECK_RESULT(result);
}

void checkAssignmentConversion(char * typeFrom, char * typeTo){
	int result = WRONG_CASTING_OPERATION;
	if (checkIdentityConversion(typeFrom, typeTo) == YES ||
		checkWideningConversion(typeFrom, typeTo) == YES ){
		result = OK;
	}
	CHECK_RESULT(result);
}

void checkCastingConversion(char * typeFrom, char * typeTo){
	int result = WRONG_CASTING_OPERATION;
	if (checkIdentityConversion(typeFrom, typeTo) == YES ||
		checkWideningConversion(typeFrom, typeTo) == YES ||
		checkNarrowingConversion(typeFrom, typeTo) == YES){
		result = OK;
	}
	CHECK_RESULT(result);
}

char * checkMethodConversion(){

	int result = YES;
	char * returnType;

	MethodNode * methodTo = classContext->methodContext;
	VarNode * paramsTo = methodTo->params;
	VarNode * paramsFrom = calledMethod->params;

	if(calledMethod != NULL){

		// AT FIRST IT TRIES AN IDENTITY CONVERSION
		while(methodTo != NULL){
			if(strcmp(calledMethod->idName, methodTo->idName) == 0){
				while(paramsFrom != NULL){
					if (paramsTo != NULL){
						if(checkIdentityConversion(paramsFrom->typeval, paramsTo->typeval) != YES){
							result = NO;
							break;
						}
					}else{
						result = NO;
						break;
					}
					paramsFrom = paramsFrom->nextNode;
					paramsTo = paramsTo->nextNode;
				}
				if (result == YES && paramsTo != NULL){
					result = NO;
				}
			}else{
				result = NO;
			}

			methodTo = methodTo->next;
		}

		if(result != YES){
			// AT SECOND IT TRIES AN WIDENING CONVERSION

			methodTo = classContext->methodContext;
			paramsTo = methodTo->params;
			paramsFrom = calledMethod->params;

			while(methodTo != NULL){
				if(strcmp(calledMethod->idName, methodTo->idName) == 0){
					while(paramsFrom != NULL){
						if (paramsTo != NULL){
							if(checkWideningConversion(paramsFrom->typeval, paramsTo->typeval) != YES){
								result = NO;
								break;
							}
						}else{
							result = NO;
							break;
						}
						paramsFrom = paramsFrom->nextNode;
						paramsTo = paramsTo->nextNode;
					}
					if (result == YES && paramsTo != NULL){
						result = NO;
					}
				}else{
					result = NO;
				}
				methodTo = methodTo->next;
			}
		}
	}

	if(result == YES){
		returnType = paramsTo->typeval;
	}else{
		result = WRONG_METHOD_CALL;
		returnType = NULL;
	}

	freeMethodList(calledMethod);

	CHECK_RESULT(result);

	return returnType;
}
