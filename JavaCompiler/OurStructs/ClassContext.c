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

static StrNode * createStrNode(VarNode * nodeList, char * str);
static StrNode * getIdInStrList(char * id);
static void freeStrList();

ClassContext * classContext = NULL;
StrNode * strList = NULL;


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

int insertVarListInClassContext(char * typeval, int isFinal){
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

int insertMethodInClassContext(char * idName, char * typeReturn){
	int result = OK;

	MethodNode * newMethod;
	MethodNode * methodList = classContext->methodContext;

	if (getMethodInClassContext(idName) == NULL){
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

int isVarFinalInClassContext(char * id){
	int result = INEXISTANT_ID_IN_CONTEXT;
	VarNode * node = getVarNodeInList(classContext->varsContext, id);

	if (node != NULL){
		result = node->isFinal;
	}
	return result;
}


//// GETTING

VarNode * getVarInClassContext(char * id){
	return getVarNodeInList(classContext->varsContext, id);
}


char * getVarTypevalInClassContext (char * id){
	char * result = NULL;
	VarNode * node = getVarNodeInList(classContext->varsContext, id);

	if (node != NULL){
		result = node->typeval;
	}
	return result;
}

MethodNode * getMethodInClassContext(char * idName){
	return getMethodNodeInList(classContext->methodContext, idName);
}

//// FREEING

void freeClassContext(){
	free(classContext->name);
	free(classContext);
}

//// DISPLAYING

void displayClassContext(){
	VarNode * varNode = classContext->varsContext;
	MethodNode * methodNode = classContext->methodContext;

	printf("ClassContext Name: %s\n\n", classContext->name);
	printf("VarsContext:\n");
	while(varNode != NULL){
		printf("\tID: %s; Typeval: %s; IsFinal: %d\n", varNode->id, varNode->typeval, varNode->isFinal);
		varNode = varNode->nextNode;
	}

	printf("\nMethodContext:\n");
	while(methodNode != NULL){
		printf("\tIDName: %s; TypeReturn: %s\n", methodNode->idName, methodNode->typeReturn);
		methodNode = methodNode->nextMethod;
	}
}

/*
 * == AUXILIAR ===== STRING NODE FUNCTION DEFINITIONS
 */

/*
 * STATIC FUNCTIONS
 */

static StrNode * createStrNode(VarNode * nodeList, char * str){

	StrNode * node;
	if (getVarInClassContext(str) == NULL && getIdInStrList(str) == NULL){

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

	if (node != NULL){
		while(node->next != NULL){
			node = node->next;
		}
		node->next = createStrNode(classContext->varsContext, id);
		if (node->next == NULL){
			result = ID_ALREADY_EXISTS;
		}
	}else{
		strList = createStrNode(classContext->varsContext, id);
		if (strList == NULL){
			result = MALLOC_ERROR_INSUFFICIENT_MEMORY;
		}
	}
	return result;
}

