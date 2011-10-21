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

static MethodNode * getCurrentMethod();

static StrNode * createStrNode(char * str);
static StrNode * getIdInStrList(char * id);
static void freeStrList();

static MethodNode * getCurrentCalledMethod();
static LineCollumnCoord * getLastLineCollumnFromCalledMethods();

ClassContext * classContext = NULL;
StrNode * strList = NULL;
MethodNode * calledMethods = NULL;
LineCollumnCoord * calledMethodsLC = NULL;

int currentContext = CLASS_CONTEXT;

/*
 * ALL CONTEXT FUNCTION DEFINITIONS
 */

void setCurrentContext(int context){
	currentContext = context;
}

/*
 * CLASSCONTEXT FUNCTION DEFINITIONS
 */

//// CREATING

int createClassContext(char * className){

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

	return result;
}

//// INSERTING

int insertVarListInGlobalContext(char * typeval, int isFinal){
	int result = OK;
	StrNode * strNode = strList;
	VarNode * nodeTmp = NULL;

	while(strNode != NULL){
		nodeTmp = insertVarInVarNodeList(classContext->varsContext, strNode->str, typeval, isFinal);
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

	return result;
}

int insertMethod(char * idName, char * typeReturn){
	int result = OK;

	MethodNode * newMethod;
	MethodNode * methodList = classContext->methodContext;

	newMethod = createMethodNode(idName, typeReturn);
	if (newMethod != NULL){
		if (methodList == NULL){
			classContext->methodContext = newMethod;
		}else{
			while(methodList->nextMethod != NULL){
				methodList = methodList->nextMethod;
			}
			methodList->nextMethod = newMethod;
		}
	}else{
		result = METHOD_CREATION_MALLOC_ERROR;
	}

	CHECK_RESULT(result);

	return result;
}

//// CHECKING

int isVarFinalInGlobalContext(char * id){
	int result = INEXISTANT_ID_IN_CONTEXT;
	VarNode * node = getVarNodeInList(classContext->varsContext, id);

	if (node != NULL){
		result = node->isFinal;
	}
	return result;
}


//// GETTING

VarNode * getVarInGlobalContext(char * id){
	return getVarNodeInList(classContext->varsContext, id);
}


char * getVarTypevalInGlobalContext (char * id){
	char * result = NULL;
	VarNode * node = getVarNodeInList(classContext->varsContext, id);

	if (node != NULL){
		result = node->typeval;
	}
	return result;
}

MethodNode * getMethod(char * idName){
	return getMethodNodeInList(classContext->methodContext, idName);
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

int addParamInCurrMethod(char * id, char * typeval){
	int result = OK;
	MethodNode * curMethod = getCurrentMethod();
	if (getVarNodeInList(curMethod->params, id) == NULL){
		curMethod = addParamInMethod(curMethod, id, typeval);
	}else{
		result = REPEATED_METHOD_PARAM_ID_ERROR;
	}

	CHECK_RESULT(result);

	return result;
}

int finishCurrMethodSignCreation(){
	int result = YES;

	// NOW WE CHECK FOR EQUALITY
	MethodNode * methodList = classContext->methodContext;
	MethodNode * curMethod = getCurrentMethod();
	while (methodList != NULL){
		if (isMethodEqual(methodList, curMethod) == YES){
			result = REPEATED_METHOD_ERROR;
			break;
		}
		methodList = methodList->nextMethod;
	}

	CHECK_RESULT(result);

	return result;
}

int insertVarListInCurrMethodContext(char * typeval, int isFinal){
	int result = OK;

	// GET THE CURRENT METHOD
	MethodNode * methodNode = getCurrentMethod();

	// INSERT THE VAR LIST AT THE METHOD VAR LIST
	StrNode * strNode = strList;
	VarNode * nodeTmp = NULL;

	while(strNode != NULL){
		nodeTmp = insertVarInVarNodeList(methodNode->varNodes, strNode->str, typeval, isFinal);
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

	return result;
}


// CHECKING

int isVarFinalInCurrMethodContext(char * id){
	int result = INEXISTANT_ID_IN_CONTEXT;
	VarNode * node = getVarNodeInList(getCurrentMethod()->varNodes, id);

	if (node != NULL){
		result = node->isFinal;
	}
	return result;
}

// GETTING

VarNode * getVarInCurrMethodContext(char * id){
	return getVarNodeInList(getCurrentMethod()->varNodes, id);
}

char * getVarTypevalInCurrMethodContext (char * id){
	char * result = NULL;
	VarNode * node = getVarNodeInList(getCurrentMethod()->varNodes, id);

	if (node != NULL){
		result = node->typeval;
	}
	return result;
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

int insertStringToStrList(char * id){
	int result = OK;
	StrNode * node = strList;

	// IS THERE ANOTHER OF THIS? IT DEPENDS ON THE CONTEXT...
	if(currentContext == METHOD_CONTEXT){
		if (getVarInCurrMethodContext(id) != NULL || getIdInStrList(id) != NULL){
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

	return result;
}

/*
 * == AUXILIAR ===== CALLED METHODS STRUCTURE
 */

int addCalledMethod(char * idName, char * typeReturn){
	int result = OK;

	MethodNode * newMethod;
	MethodNode * calledMethodList = calledMethods;

	newMethod = createMethodNode(idName, typeReturn);

	if (newMethod != NULL){
		if (calledMethodList == NULL){
			calledMethods = newMethod;
		}else{
			while(calledMethodList->nextMethod != NULL){
				calledMethodList = calledMethodList->nextMethod;
			}
			calledMethodList->nextMethod = newMethod;
		}
	}else{
		result = CALLED_METHOD_CREATION_MALLOC_ERROR;
	}

	CHECK_RESULT(result);
	return result;
}

int addArgsToCurrCalledMethod(char * id, char * typeval){
	int result = OK;

	MethodNode * curCalledMethod = getCurrentCalledMethod();
	if (curCalledMethod != NULL){
		curCalledMethod = addParamInMethod(curCalledMethod, id, typeval);
	}else{
		result = CURR_CALLED_METHOD_IS_NULL;
	}

	CHECK_RESULT(result);
	return result;
}

int setLineCollumnOfCalledMethod(int line, int collumn){
	int result = OK;

	LineCollumnCoord * newLineCollumn;
	LineCollumnCoord * lastLineCollumn = getLastLineCollumnFromCalledMethods();

	newLineCollumn = (LineCollumnCoord*) malloc(sizeof(LineCollumnCoord));

	if (newLineCollumn != NULL){
		newLineCollumn->line = line;
		newLineCollumn->collumn = collumn;
		newLineCollumn->next = NULL;

		if (lastLineCollumn == NULL){
			calledMethodsLC = newLineCollumn;
		}else{
			lastLineCollumn->next = newLineCollumn;
		}
	}else{
		result = CALLED_METHOD_LINE_COLLUMN_CREATION_MALLOC_ERROR;
	}

	CHECK_RESULT(result);
	return result;
}

/*
 * STATIC FUNCTIONS
 */

static MethodNode * getCurrentCalledMethod(){
	return getLastMethodNodeInList(calledMethods);
}

static LineCollumnCoord * getLastLineCollumnFromCalledMethods(){
	return getLastLineCollumCoordInList(calledMethodsLC);
}

/*************** SEMANTIC CHECK FUNCTIONS ***************/

void checkStaticClassId(char * id){
	int result = (strcmp(classContext->name, id) == 0) ? OK : WRONG_STATIC_CLASS_CALL;
	CHECK_RESULT(result);
}

int checkCalledAndRealMethodsCorrespondence(){
	int result = OK;

	MethodNode * calledMethodList = calledMethods;
	MethodNode * declaredMethodList = NULL;
	LineCollumnCoord * lineCollumnList = calledMethodsLC;

	while(calledMethodList != NULL){
		declaredMethodList = classContext->methodContext;
		while(declaredMethodList != NULL){
			if (isMethodEqual(declaredMethodList, calledMethodList) == NO){
				fprintf(stderr,"MethodName: %s, Line: %d, Collumn: %d\n", calledMethodList->idName, lineCollumnList->line, lineCollumnList->collumn);
				result = WRONG_METHOD_CALL;
				break;
			}
			declaredMethodList = declaredMethodList->nextMethod;
		}

		if(result == OK){
			calledMethodList = calledMethodList->nextMethod;
			lineCollumnList = lineCollumnList->next;
		}else{
			break;
		}
	}

	freeMethodList(calledMethods);
	freeLineCollumnCoordList(calledMethodsLC);

	CHECK_RESULT(result);
	return result;
}

