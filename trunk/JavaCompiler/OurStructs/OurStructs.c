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

#include "OurStructs.h"

/*
 * =============== VARNODE FUNCTION DEFINITIONS
 */

VarNode * createVarNode(char * id, char * typeval, int isFinal){

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

VarNode * insertVarInVarNodeList(VarNode * nodeList, char * id, char * typeval, int isFinal){

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

VarNode * getVarNodeInList (VarNode * nodeList, char * id){

	while(nodeList != NULL){
		if (strcmp(nodeList->id, id) == 0){
			break;
		}
		nodeList = nodeList->nextNode;
	}
	return nodeList;
}

void freeVarNodeList(VarNode * list){
	VarNode * listTmp = list;
	while(listTmp != NULL){
		list = listTmp;
		listTmp = listTmp->nextNode;
		free(list->id);
		free(list->typeval);
		free(list);
	}
}

int isVarNodeEqual(VarNode * var, char * newId){
	return (strcmp(var->id, newId) == 0) ? YES : NO;
}

void displayVarNodeList(VarNode * varNodeList){
	while(varNodeList != NULL){
		printf("\tID: %s; Typeval: %s; IsFinal: %d\n", varNodeList->id, varNodeList->typeval, varNodeList->isFinal);
		varNodeList = varNodeList->nextNode;
	}
	printf("\n");
}

/*
 * =============== METHOD FUNCTION DEFINITIONS
 */

MethodNode * createMethodNode(char * idName, char * typeReturn){

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

			node->params = NULL;
			node->varNodes = NULL;
			node->nextMethod = NULL;
		}else{
			node = NULL;
		}
	}
	return node;
}

MethodNode * addParamInMethod(MethodNode * method, char * id, char * type){
	VarNode * params = method->params;
	if (params != NULL){
		while(params->nextNode != NULL){
			params = params->nextNode;
		}
		params->nextNode = createVarNode(id, type, NO);
	}else{
		method->params = createVarNode(id, type, NO);
	}
	return method;
}

MethodNode * getMethodNodeInList (MethodNode * nodeList, char * idName){

	while(nodeList != NULL){
		if (strcmp(nodeList->idName, idName) == 0){
			break;
		}
		nodeList = nodeList->nextMethod;
	}
	return nodeList;
}

void freeMethodList(MethodNode * list){
	MethodNode * listTmp = list;
	while(listTmp != NULL){
		list = listTmp;
		listTmp = listTmp->nextMethod;
		free(list->idName);
		free(list->typeReturn);
		freeVarNodeList(list->varNodes);
		free(list);
	}
}

int isMethodEqual(MethodNode * method1, MethodNode * method2){
	int result = YES;
	VarNode * params = method1->params;
	VarNode * newParams = method2->params;

	if(strcmp(method1->idName, method2->idName) == 0){
		while(params != NULL){
			if (newParams != NULL){
				if(strcmp(params->typeval, newParams->typeval) != 0){
					result = NO;
					break;
				}
			}else{
				result = NO;
				break;
			}
			params = params->nextNode;
			newParams = newParams->nextNode;
		}
	}else{
		result = NO;
	}
	return result;
}

void displayMethodNodeList(MethodNode * methodNodeList){
	while(methodNodeList != NULL){
		printf("%s %s\n", methodNodeList->typeReturn, methodNodeList->idName);
		printf("===> params:\n");
		displayVarNodeList(methodNodeList->params);
		printf("===> local vars:\n");
		displayVarNodeList(methodNodeList->varNodes);

		methodNodeList = methodNodeList->nextMethod;
	}
}
