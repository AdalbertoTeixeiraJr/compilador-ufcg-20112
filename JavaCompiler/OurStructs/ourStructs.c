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

VarsContext * classContext = NULL;
StrNode * strList = NULL;

static VarsContext * createContext(char * name);
static int addVarInContext(VarsContext * context, char * id, char * typeval, int isFinal);
static varNode * getVarNodeInContextList (VarsContext * context, char * id);
static StrNode * createStrNode(VarsContext * context, char * id);

/*
 * =============== VARSCONTEXT FUNCTION DEFINITIONS
 */

/*
 * STATIC FUNCTIONS
 */

static VarsContext * createContext(char * name){

	VarsContext * context = (VarsContext*) malloc(sizeof(VarsContext));

	if (context != NULL){
		context->name = (char *) malloc(sizeof(char) * MAX_ID_SIZE);
		if (context->name != NULL){
			strcpy(context->name, name);
		}else{
			context = NULL;
		}
		context->listLength = 0;
		context->varListStart = NULL;
		context->varListEnd = NULL;
	}else{
		context = NULL;
	}
	return context;
}

static int addVarInContext(VarsContext * context, char * id, char * typeval, int isFinal){
	int result = OK;

	varNode * node = (varNode*) malloc(sizeof(varNode));

	if(node != NULL){

		// Allocate and copy the id char value
		node->id = (char *) malloc(sizeof(char) * MAX_ID_SIZE);
		if(node->id != NULL){
			strcpy(node->id, id);

			// Allocate and copy the typeval char value
			node->typeval = (char *) malloc(sizeof(char) * MAX_TYPEVAL_SIZE);
			if (node->typeval != NULL){
				strcpy(node->typeval, typeval);
			}else{
				result = MALLOC_ERROR_INSUFFICIENT_MEMORY;
			}

		}else{
			result = MALLOC_ERROR_INSUFFICIENT_MEMORY;
		}

		// Set the isFinal field
		node->isFinal = isFinal;

		// Insert the node into the class context struct
		if (context->listLength <= 0){
			context->varListStart = node;
			context->varListEnd = node;
		}else{
			context->varListEnd->nextNode = node;
			context->varListEnd = node;
		}
		// Update the list length
		context->listLength++;


	}else{
		result = MALLOC_ERROR_INSUFFICIENT_MEMORY;
	}

	return result;
}

static varNode * getVarNodeInContextList (VarsContext * context, char * id){
	int i;
	varNode * node = context->varListStart; // This is the list AND the initial node

	for (i = 0; i < context->listLength; i++){
		if (strcmp(node->id, id) == 0){
			break;
		}
		node = node->nextNode;
	}
	return node;
}

void freeStrList(){
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

//// CREATING

int createClassContext(char * className){
	classContext = createContext(className);
	return (classContext != NULL)?
			OK :
			VARS_CONTEXT_CREATION_ERROR_INSUFFICIENT_MEMORY;
}

VarsContext * createBlockContext(char * name){
	return createContext(name);
}

//// INSERTING

int addVarListInContext(VarsContext * context, char * typeval, int isFinal){
	int result = OK;
	StrNode * strNode = strList;
	while(strNode != NULL){
		result = addVarInContext(context, strNode->str, typeval, isFinal);
		if (result != OK){
			break;
		}else{
			strNode = strNode->next;
		}
	}
	freeStrList();
	return result;
}

//// CHECKING

int hasIdInContextList(VarsContext * context, char * id){
	int i;
	int result = NO;

	varNode * varNode = context->varListStart; // This is the list and the initial node

	for (i = 0; i < context->listLength; i++){
		if (strcmp(varNode->id, id) == 0){
			result = YES;
			break;
		}
		varNode = varNode->nextNode;
	}
	return result;
}

int isVarFinal(VarsContext * context, char * id){
	int result = INEXISTANT_ID_IN_CONTEXT;
	varNode * node = getVarNodeInContextList(context, id);

	if (node != NULL){
		result = node->isFinal;
	}
	return result;
}


//// GETTING

VarsContext * getClassContext(){
	return classContext;
}

StrNode * getStrList(){
	return strList;
}

char * getTypevalInContextList (VarsContext * context, char * id){
	char * result = NULL;
	varNode * node = getVarNodeInContextList(context, id);

	if (node != NULL){
		result = node->typeval;
	}
	return result;
}

//// FREEING

void freeContext(VarsContext * context){
	free(context->name);
	free(context);
}

//// DISPLAYING

void displayAllVarsOfContext(VarsContext * context){

	int i;
	varNode * node = context->varListStart;

	printf("VarsContext Name: %s\n", context->name);
	for (i = 0; i < context->listLength; i++){
		printf("ID: %s; Typeval: %s\n", node->id, node->typeval);
		node = node->nextNode;
	}
}

/*
 * =============== STRING NODE FUNCTION DEFINITIONS
 */

/*
 * STATIC FUNCTIONS
 */

static StrNode * createStrNode(VarsContext * context, char * id){

	StrNode * node;
	if (hasIdInContextList(context, id) == NO){

		node = (StrNode*) malloc(sizeof(StrNode));

		if (node != NULL){
			node->str = (char *) malloc(sizeof(char) * MAX_ID_SIZE);
			if (node->str != NULL){
				strcpy(node->str, id);
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


/*
 * PUBLIC FUNCTIONS
 */

int addStringToNode(VarsContext * context, char * id){
	int result = OK;
	StrNode * node = strList;

	if (node != NULL){
		while(node->next != NULL){
			node = node->next;
		}
		node->next = createStrNode(context, id);
		if (node->next == NULL){
			result = CONTEXT_ID_ALREADY_EXISTS;
		}
	}else{
		strList = createStrNode(context, id);
		if (strList == NULL){
			result = MALLOC_ERROR_INSUFFICIENT_MEMORY;
		}
	}
	return result;
}

