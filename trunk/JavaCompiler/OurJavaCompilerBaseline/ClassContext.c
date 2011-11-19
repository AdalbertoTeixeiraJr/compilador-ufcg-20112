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

//// STRLIST
static StrNode * createStrNode(char * str);
static StrNode * getIdInStrList(char * id);
static void freeStrList();

//// CHECKERS
int translateTypevalToInt(char * typeval);
static int checkIdentityConversion(char * typeFrom, char * typeTo);
static int checkWideningConversion(char * typeFrom, char * typeTo);
static int checkNarrowingConversion(char * typeFrom, char * typeTo);
static int checkImplicitConversion(char * typeFrom, char * typeTo);
static int checkIntegralType(char * type);
static int checkFloatType(char * type);

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
			strncpy(classContext->name, className, MAX_ID_SIZE);
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

int getVarArrayLevelInBothContexts (char * id){
	int result = -1;
	VarNode * node = getVarNodeInList(getCurrentMethod()->varNodes, id);

	if (node != NULL){
		result = node->arrayLevels;
	}else{
		node = getVarNodeInList(getCurrentMethod()->params, id);

		if (node != NULL){
			result = node->arrayLevels;
		}else{
			node = getVarNodeInList(classContext->varsContext, id);

			if (node != NULL){
				result = node->arrayLevels;
			}else{
				result = NO_VAR_FOUND_IN_BOTH_CONTEXTS;
			}
		}
	}
	return result;
}


char * getVarTypevalInBothContexts (char * id){
	int result = OK;
	char * resultType = NULL;

	VarNode * node = getVarNodeInList(getCurrentMethod()->varNodes, id);

	if (node != NULL){
		resultType = node->typeval;
	}else{
		node = getVarNodeInList(getCurrentMethod()->params, id);

		if (node != NULL){
			resultType = node->typeval;
		}else{
			node = getVarNodeInList(classContext->varsContext, id);

			if (node != NULL){
				resultType = node->typeval;
			}else{
				result = NO_VAR_FOUND_IN_BOTH_CONTEXTS;
			}
		}
	}

	CHECK_RESULT(result);
	return resultType;
}

int isVarFinalInGlobalContext(char * id){
	int result = INEXISTANT_ID_IN_CONTEXT;
	VarNode * node = getVarNodeInList(classContext->varsContext, id);

	if (node != NULL){
		result = node->isFinal;
	}
	return result;
}

int isVarFinalInCurrMethodContext(char * id){
	int result = INEXISTANT_ID_IN_CONTEXT;
	VarNode * node = getVarNodeInList(getCurrentMethod()->varNodes, id);

	if (node != NULL){
		result = node->isFinal;
	}
	return result;
}

int isVarFinalInBothContexts(char * id){
	return (isVarFinalInCurrMethodContext(id) == YES || isVarFinalInGlobalContext(id) == YES)? YES : NO;
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
			strncpy(node->str, str, MAX_ID_SIZE);
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

		newMethod = createMethodNode(idName, "ALWAYS_NULL", 0);

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

/*************** LABEL FUNCTIONS ***************/
void addLabel(char * name){

	int result = OK;

	MethodNode * method = getCurrentMethod();
	LabelStruct * newLabel = createLabel(name);
	LabelStruct * labels = method->labels;

	if (labels != NULL){
		while(labels->next != NULL){
			if (strcmp(labels->name, name) == 0){
				result = REPEATED_LABEL_IN_SAME_METHOD;
				break;
			}
			labels = labels->next;
		}
	}
	if(result == OK){
		if (labels == NULL){
			method->labels = newLabel;
		}else if (strcmp(labels->name, name) == 0){
			result = REPEATED_LABEL_IN_SAME_METHOD;
		}else{
			labels->next = newLabel;
		}
	}

	CHECK_RESULT(result);
}

void checkLabelInCurrMethod(char * name){
	int result = NO_LABEL_FOUND;

	if (strcmp(name, "id_empty") == 0){
		result = OK;
	}else{
		LabelStruct * labels = getCurrentMethod()->labels;

		while(labels != NULL){
			if (strcmp(labels->name, name) == 0){
				result = OK;
				break;
			}
			labels = labels->next;
		}
	}
	CHECK_RESULT(result);
}


/*************** SEMANTIC CHECK FUNCTIONS ***************/

/*
 * STATIC FUNCTIONS
 */

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

static int checkImplicitConversion(char * typeFrom, char * typeTo){
	int result = WRONG_IMPLICIT_CONVERSION;
	if (checkIdentityConversion(typeFrom, typeTo) == YES ||
		checkWideningConversion(typeFrom, typeTo) == YES ){
		result = OK;
	}
	return result;
}

static int checkIntegralType(char * type){
	int result = NO;
	int ourType = translateTypevalToInt(type);
	if (ourType == OUR_BYTE || ourType == OUR_SHORT || ourType == OUR_INT || ourType == OUR_LONG || ourType == OUR_CHAR){
		result = OK;
	}
	return result;
}

static int checkFloatType(char * type){
	int result = NO;
	int ourType = translateTypevalToInt(type);
	if (ourType == OUR_FLOAT || ourType == OUR_DOUBLE){
		result = OK;
	}
	return result;
}


/*
 * PUBLIC FUNCTIONS
 */

void checkStaticClassId(char * id){
	int result = (strcmp(classContext->name, id) == 0) ? OK : WRONG_STATIC_CLASS_CALL;
	CHECK_RESULT(result);
}

void checkRepeatedCurrentMethodSignature(){
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

void checkEqualsArrayLevel(int declarationLevel, int definitionLevel){
	int result = (declarationLevel == definitionLevel)? OK: DIFFERENT_ARRAY_LEVEL_DEFINITION_DECLARATION;
	CHECK_RESULT(result);
}

void checkEqualsTypeval(char * declarationLevel, char * definitionLevel){
	int result = (strcmp(declarationLevel,definitionLevel)== 0)? OK: DIFFERENT_TYPES;
//	printf("t1: %s, t2: %s\n", declarationLevel, definitionLevel);
	CHECK_RESULT(result);
}

void checkIsBoolean(char * type){
	int result = (translateTypevalToInt(type) == OUR_BOOLEAN) ? OK: WRONG_BOOLEAN_CHECK;
	CHECK_RESULT(result);
}

void checkIncrementDecrement(char * varType, char * operType, int isFinal){
	int result = OK;
	if (translateTypevalToInt(operType) != OUR_EMPTY ){
		if (isFinal == YES){
			result = WRONG_FINAL_UPDATE;
		}else{
			result = checkNumericalType(varType);
		}
	}
	CHECK_RESULT(result);
}

int checkNumericalType(char * type){
	int result = WRONG_NUMERICAL_TYPE;

	if (checkIntegralType(type) == OK || checkFloatType(type) == OK){
		result = OK;
	}
	CHECK_RESULT(result);
	return result;
}

void checkAssignConversion(char * typeFrom, char * typeTo){
	int result = (checkImplicitConversion(typeFrom, typeTo) == OK) ? OK : WRONG_ASSIGN_CONVERSION;
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

int methodArrayLevelsTmp = 0;

char * checkMethodConversion(){

	int result = YES;
	char * returnType;

	MethodNode * methodTo = classContext->methodContext;
	VarNode * paramsTo;
	VarNode * paramsFrom = calledMethod->params;

	if(calledMethod != NULL){

		// AT FIRST IT TRIES AN IDENTITY CONVERSION
		while(methodTo != NULL){
			result = YES;
			if(strcmp(calledMethod->idName, methodTo->idName) == 0){
				paramsTo = methodTo->params;
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
				if (result == YES){
					if(paramsTo != NULL){
						result = NO;
					}else{
						break;
					}
				}
			}
			methodTo = methodTo->next;
			result = NO;
		}

		if(result != YES){
			// AT SECOND checkNumericalTypeIT TRIES AN WIDENING CONVERSION

			methodTo = classContext->methodContext;
			paramsFrom = calledMethod->params;

			while(methodTo != NULL){
				result = YES;
				if(strcmp(calledMethod->idName, methodTo->idName) == 0){
					paramsTo = methodTo->params;
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
					if (result == YES){
						if (paramsTo != NULL){
							result = NO;
						}else{
							break;
						}
					}
				}
				methodTo = methodTo->next;
				result = NO;
			}
		}
	}

	if(result == YES){
		returnType = methodTo->returnType;
		methodArrayLevelsTmp = methodTo->arrayLevels;
	}else{
		result = WRONG_METHOD_CALL;
		returnType = NULL;
	}

	freeMethodList(calledMethod);

	CHECK_RESULT(result);

	return returnType;
}

int checkMethodLevelsAfterConversion(){
	return methodArrayLevelsTmp;
}


// BINARY COMPARISONS

char * checkBinaryExpressionResultType(char * leftType, char * rightType){
	int result = OK;
	char * resultType;
	if (translateTypevalToInt(rightType) == OUR_EMPTY){
		resultType = leftType;
	}else if (checkNumericalType(leftType) == OK && checkNumericalType(rightType) == OK){
		if (checkImplicitConversion(leftType, rightType) == OK){
			resultType = rightType;
		}else if(checkImplicitConversion(rightType, leftType) == OK){
			resultType = leftType;
		}else{
			result = WRONG_BINARY_NUMERIC_EXPRESSION;
		}
	}else{
		result = WRONG_BINARY_NUMERIC_EXPRESSION;
	}
	CHECK_RESULT(result);
	return resultType;
}


char * checkShiftOperator(char * leftType, char * shiftDistanceType){
	int result = WRONG_SHIFT_OPERATION;
	if (translateTypevalToInt(shiftDistanceType) == OUR_EMPTY ||
		(checkIntegralType(leftType) == OK && checkIntegralType(shiftDistanceType) == OK)){
		result = OK;
		return leftType;
	}

	CHECK_RESULT(result);
	return NULL;
}

char * checkEqualityOperator(char * leftType, char * rightType){
	int result = OK;
	char * resultType = NULL;
	int ourLeftType = translateTypevalToInt(leftType);
	int ourRightType = translateTypevalToInt(rightType);

	if (translateTypevalToInt(rightType) == OUR_EMPTY){
		resultType = leftType;
	}else if ((ourLeftType == OUR_BOOLEAN && ourRightType == OUR_BOOLEAN)	||
		(ourLeftType == OUR_NULL && ourRightType == OUR_NULL) ||
		(checkNumericalType(leftType) == OK && checkNumericalType(rightType) == OK)){
		resultType = "t_boolean";
	}else{
		result = WRONG_EQUALITY_OPERATION;
	}
	CHECK_RESULT(result);
	return resultType;
}

char * checkBitwiseLogicalOperator(char * leftType, char * rightType){
	int result = OK;
	char * resultType = NULL;
	int ourLeftType = translateTypevalToInt(leftType);
	int ourRightType = translateTypevalToInt(rightType);

	if (translateTypevalToInt(rightType) == OUR_EMPTY){
		resultType = leftType;
	}else if(checkNumericalType(leftType) == OK && checkNumericalType(rightType) == OK){
		if (checkImplicitConversion(leftType, rightType) == OK){
			resultType = rightType;
		}else if(checkImplicitConversion(rightType, leftType) == OK){
			resultType = leftType;
		}else{
			result = WRONG_EQUALITY_OPERATION;
		}
	}else if (ourLeftType == OUR_BOOLEAN && ourRightType == OUR_BOOLEAN){
		resultType = leftType;
		result = OK;
	}
	CHECK_RESULT(result);
	return resultType;
}

char * checkConditionalAndOrOperator(char * leftType, char * rightType){
	int result = OK;
	char * resultType = NULL;
	int ourLeftType = translateTypevalToInt(leftType);
	int ourRightType = translateTypevalToInt(rightType);

	if (translateTypevalToInt(rightType) == OUR_EMPTY){
		resultType = leftType;
	}else if ((ourLeftType == OUR_BOOLEAN && ourRightType == OUR_BOOLEAN)){
		resultType = "t_boolean";
	}else{
		result = WRONG_EQUALITY_OPERATION;
	}
	CHECK_RESULT(result);
	return resultType;
}

char * checkRelationalOperator(char * leftType, char * rightType){
	int result = OK;
	char * resultType = NULL;

	if (translateTypevalToInt(rightType) == OUR_EMPTY){
		resultType = leftType;
	}else if(checkNumericalType(leftType) == OK && checkNumericalType(rightType) == OK){
		resultType = "t_boolean";
	}else{
		result = WRONG_RELATIONAL_OPERATION;
	}
	CHECK_RESULT(result);
	return resultType;
}

char * checkQuestionMarkOperator(char * leftType, char * rightType){
	int result = OK;
	char * resultType = NULL;

	if (checkImplicitConversion(leftType, rightType) == OK){
		resultType = rightType;
	}else if(checkImplicitConversion(rightType, leftType) == OK){
		resultType = leftType;
	}else{
		result = WRONG_QUESTION_MARK_OPERATION;
	}
	CHECK_RESULT(result);
	return resultType;
}

void checkArrayCreationExpression(char * type){
	int result = OK;

	if (checkIntegralType(type) != OK){
		result = WRONG_ARRAY_CREATION_EXPRESSION;
	}
	CHECK_RESULT(result);
}

void checkIsEmptyOrBool(char* typeval){
      int result = OK;
      if((strcmp(typeval, "t_empty") != 0) && (strcmp(typeval, "t_boolean") != 0)){
    	  result = NOT_BOOL_OR_EMPTY;
      }
      CHECK_RESULT(result);
}

void checkIsSwitchExpression(char* typeval){
	int result = WRONG_SWITCH_EXPRESSION;
	int ourType = translateTypevalToInt(typeval);

	if(ourType == OUR_CHAR || ourType == OUR_BYTE || ourType == OUR_SHORT || ourType == OUR_INT){
		result = OK;
	}
	CHECK_RESULT(result);
}

void checkReturnTypeAndLevelInCurrMethod(char * returnedType, int returnedLevel){
	int result = WRONG_RETURN_TYPE_IN_CURR_METHOD;

	char * methodReturnType = getCurrentMethod()->returnType;
	int methodReturnArrayLevel = getCurrentMethod()->arrayLevels;

	if (translateTypevalToInt(returnedType) == OUR_EMPTY && translateTypevalToInt(methodReturnType) == OUR_VOID){
		result = OK;
	} else if (checkImplicitConversion(returnedType, methodReturnType) == OK){
		result = OK;
	}

	if (result == OK){
		result = (returnedLevel == methodReturnArrayLevel)? OK: DIFFERENT_RETURNED_ARRAY_LEVEL_IN_CURR_METHOD;
	}

	CHECK_RESULT(result);
}

void checkHasReturn(int hasReturn){
	int result = (hasReturn == YES)? OK: NO_RETURN_DECLARATION;
	CHECK_RESULT(result);
}

void checkFinalUpdate(int isFinal){
	int result = (isFinal == NO)? OK: WRONG_UPDATE_OF_FINAL_VAR;
	CHECK_RESULT(result);
}


// AUXILIAR OPERATOR CHOOSER
char * chooseBinaryOperation(char * leftType, char * rightType, char * oper){
	int result = OK;
	char * resultType = NULL;

	if (translateTypevalToInt(rightType) == OUR_EMPTY){
		resultType = leftType;
	}else{
		if(strcmp(oper, "and") == 0 || strcmp(oper, "or") == 0){
			return checkConditionalAndOrOperator(leftType, rightType);
		}else if (strcmp(oper, "inc_or") == 0 || strcmp(oper, "exc_or")== 0 || strcmp(oper, "and_bit")== 0){
			return checkBitwiseLogicalOperator(leftType, rightType);
		}else if (strcmp(oper, "equal") == 0){
			return checkConditionalAndOrOperator(leftType, rightType);
		}else if (strcmp(oper, "relop") == 0){
			return checkRelationalOperator(leftType, rightType);
		}else if (strcmp(oper, "shift") == 0){
			return checkShiftOperator(leftType, rightType);
		}else if (strcmp(oper, "add") == 0 || strcmp(oper, "mult") == 0){
			return checkBinaryExpressionResultType(leftType, rightType);
		}else{
			result = WRONG_OPERATION;
		}
	}

	CHECK_RESULT(result);
	return resultType;
}
