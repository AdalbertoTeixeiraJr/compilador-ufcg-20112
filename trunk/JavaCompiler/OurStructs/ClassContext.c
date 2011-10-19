/*
 ============================================================================
 Name        : OurStructs.c
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

ClassContext * classContext = NULL;
StrNode * strList = NULL;
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
			result = CLASS_CONTEXT_CREATION_ERROR_INSUFFICIENT_MEMORY;
		}
		classContext->varsContext = NULL;
		classContext->methodContext = NULL;
	}else{
		result = CLASS_CONTEXT_CREATION_ERROR_INSUFFICIENT_MEMORY;
	}

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
			result = MALLOC_ERROR_INSUFFICIENT_MEMORY;
			break;
		}
	}
	freeStrList();
	return result;
}

int insertMethod(char * idName, char * typeReturn){
	int result = OK;

	MethodNode * newMethod;
	MethodNode * methodList = classContext->methodContext;

	if (getMethod(idName) == NULL){
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
			result = MALLOC_ERROR_INSUFFICIENT_MEMORY;
		}
	}else{
		result = ID_ALREADY_EXISTS;
	}
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
	MethodNode * methodNode = classContext->methodContext;

	while(methodNode->nextMethod != NULL){
		methodNode = methodNode->nextMethod;
	}
	return methodNode;
}

/*
 * PUBLIC FUNCTIONS
 */

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
			result = MALLOC_ERROR_INSUFFICIENT_MEMORY;
			break;
		}
	}
	freeStrList();

	return result;
}

void addParamInCurrMethod(char * id, char * typeval){
	MethodNode * curMethod = getCurrentMethod();
	curMethod = addParamInMethod(curMethod, id, typeval);
}

int finishCurrMethodSignCreation(){
	int result = YES;

	// NOW WE CHECK FOR EQUALITY
	MethodNode * methodList = classContext->methodContext;
	MethodNode * curMethod = getCurrentMethod();
	while (methodList != NULL){
		if (isMethodEqual(methodList, curMethod) == YES){
			result = NO;
			break;
		}
		methodList = methodList->nextMethod;
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
			result = ID_ALREADY_EXISTS;
		}
	}else{
		if (getVarInGlobalContext(id) != NULL || getIdInStrList(id) != NULL){
			result = ID_ALREADY_EXISTS;
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
				result = MALLOC_ERROR_INSUFFICIENT_MEMORY;
			}
		}else{
			strList = createStrNode(id);
			if (strList == NULL){
				result = MALLOC_ERROR_INSUFFICIENT_MEMORY;
			}
		}
	}
	return result;
}

