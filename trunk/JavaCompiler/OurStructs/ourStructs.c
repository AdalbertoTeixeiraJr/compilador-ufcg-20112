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

#include "ourStructs.h"

ClassContext * classContext = NULL;
StrNode * strList = NULL;

static VarNode * createVarNode(char * id, char * typeval, int isFinal);
static VarNode * insertVarInVarNodeList(VarNode * nodeList, char * id, char * typeval, int isFinal);
static VarNode * getVarNodeInList (VarNode * nodeList, char * id);

static MethodNode * createMethodNode(char * idName, char * typeReturn);

static StrNode * createStrNode(VarNode * nodeList, char * str);
static void freeStrList();

/*
 * =============== VARNODE FUNCTION DEFINITIONS
 */

static VarNode * createVarNode(char * id, char * typeval, int isFinal){

	VarNode * node = (VarNode*) malloc(sizeof(VarNode));

	if(node != NULL){
		// Set the isFinal field
		node->isFinal = isFinal;

		// Allocate and copy the id char value
		node->id = (char *) malloc(sizeof(char) * MAX_ID_SIZE);
		if(node->id != NULL){
			strcpy(node->id, id);

			// Allocate and copy the typeval char value
			node->typeval = (char *) malloc(sizeof(char) * MAX_TYPEVAL_SIZE);
			if (node->typeval != NULL){
				strcpy(node->typeval, typeval);
			}else{
				node = NULL;
			}
		}else{
			node = NULL;
		}
	}
	return node;
}

static VarNode * insertVarInVarNodeList(VarNode * nodeList, char * id, char * typeval, int isFinal){

	VarNode * node = createVarNode(id, typeval, isFinal);
	VarNode * nodeListTmp = nodeList;

	if (node != NULL){
		if (nodeListTmp == NULL){
			nodeList = node;	
		}else{
			while(nodeListTmp->nextNode != NULL){
				nodeListTmp = nodeListTmp->nextNode;
			}
			nodeListTmp->nextNode = node;
		}
	}else{
		nodeList = NULL;
	}	
	return nodeList;
}

static VarNode * getVarNodeInList (VarNode * nodeList, char * id){

	while(nodeList != NULL){
		if (strcmp(nodeList->id, id) == 0){
			break;
		}
		nodeList = nodeList->nextNode;
	}
	return nodeList;
}

static MethodNode * createMethodNode(char * idName, char * typeReturn){

	MethodNode * node = (MethodNode*) malloc(sizeof(MethodNode));

	if(node != NULL){

		// Allocate and copy the id char value
		node->idName = (char *) malloc(sizeof(char) * MAX_ID_SIZE);
		if(node->idName != NULL){
			strcpy(node->idName, idName);

			// Allocate and copy the typeval char value
			node->typeReturn = (char *) malloc(sizeof(char) * MAX_TYPEVAL_SIZE);
			if (node->typeReturn != NULL){
				strcpy(node->typeReturn, typeReturn);
			}else{
				node = NULL;
			}
		}else{
			node = NULL;
		}
	}
	return node;
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

	MethodNode * newMethod = createMethodNode(idName, typeReturn);
	MethodNode * methodList = classContext->methodContext;

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

	return result;
}

//// CHECKING

int hasVarIdInClassContext(char * id){
	int result = NO;

	VarNode * node = classContext->varsContext;
	StrNode * strNode = strList;

	while(node != NULL){
		if (strcmp(node->id, id) == 0){
			result = YES;
			break;
		}
		node = node->nextNode;
	}

	while(strNode != NULL){
		if (strcmp(strNode->str, id) == 0){
			result = YES;
			break;
		}
		strNode = strNode->next;
	}

	return result;
}

int isVarFinalInClassContext(char * id){
	int result = INEXISTANT_ID_IN_CONTEXT;
	VarNode * node = getVarNodeInList(classContext->varsContext, id);

	if (node != NULL){
		result = node->isFinal;
	}
	return result;
}


//// GETTING

char * getTypevalInClassContext (char * id){
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
 * =============== STRING NODE FUNCTION DEFINITIONS
 */

/*
 * STATIC FUNCTIONS
 */

static StrNode * createStrNode(VarNode * nodeList, char * str){

	StrNode * node;
	if (hasVarIdInClassContext(str) == NO){

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
			result = CONTEXT_ID_ALREADY_EXISTS;
		}
	}else{
		strList = createStrNode(classContext->varsContext, id);
		if (strList == NULL){
			result = MALLOC_ERROR_INSUFFICIENT_MEMORY;
		}
	}
	return result;
}

