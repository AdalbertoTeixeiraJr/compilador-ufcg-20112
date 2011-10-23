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
static MethodNode * getMethod(char * idName);
static VarNode * getVarInGlobalContext(char * id);

static MethodNode * getCurrentMethod();
static VarNode * getVarInCurrMethodContext(char * id);
static char * getVarTypevalInCurrMethodContext (char * id);

//// CHECKING
static int isVarFinalInGlobalContext(char * id);
static int isVarFinalInCurrMethodContext(char * id);

//// STRLIST
static StrNode * createStrNode(char * str);
static StrNode * getIdInStrList(char * id);
static void freeStrList();


/*************** GLOBAL VARIABLES ***************/
ClassContext * classContext = NULL;
StrNode * strList = NULL;
MethodNode * calledMethods = NULL;
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


static MethodNode * getMethod(char * idName){
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
}



/*************** SEMANTIC CHECK FUNCTIONS ***************/

/*
 * STATIC FUNCTIONS
 */

static int isVarFinalInCurrMethodContext(char * id){
	int result = INEXISTANT_ID_IN_CONTEXT;
	VarNode * node = getVarNodeInList(getCurrentMethod()->varNodes, id);

	if (node != NULL){
		result = node->isFinal;
	}
	return result;
}

static int isVarFinalInGlobalContext(char * id){
	int result = INEXISTANT_ID_IN_CONTEXT;
	VarNode * node = getVarNodeInList(classContext->varsContext, id);

	if (node != NULL){
		result = node->isFinal;
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

void checkEqualMethodSignature(){
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

