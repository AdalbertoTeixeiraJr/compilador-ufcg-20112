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

VarNode * createVarNode(char * id, char * typeval, int wasUpdated, int isFinal, int arrayLevels){

	VarNode * node = (VarNode*) malloc(sizeof(VarNode));

	if(node != NULL){
		// Set the fields
		node->isFinal = isFinal;
		node->wasUpdated = wasUpdated;
		node->arrayLevels = arrayLevels;

		// Allocate and copy the id char value
		node->id = (char *) malloc(sizeof(char) * MAX_ID_SIZE);
		if(node->id != NULL){
			strncpy(node->id, id, MAX_ID_SIZE);

			// Allocate and copy the typeval char value
			node->typeval = (char *) malloc(sizeof(char) * MAX_TYPEVAL_SIZE);
			if (node->typeval != NULL){
				strncpy(node->typeval, typeval, MAX_TYPEVAL_SIZE);
			}else{
				node = NULL;
			}
		}else{
			node = NULL;
		}
	}
	return node;
}

VarNode * insertVarInVarNodeList(VarNode * nodeList, char * id, int wasUpdated, char * typeval, int isFinal, int arrayLevels){

	VarNode * node = createVarNode(id, typeval, wasUpdated, isFinal, arrayLevels);
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
		printf("\tID: %s; Typeval: %s; wasUpdated: %d; IsFinal: %d; ArrayLevels: %d\n", varNodeList->id, varNodeList->wasUpdated, varNodeList->typeval, varNodeList->isFinal, varNodeList->arrayLevels);
		varNodeList = varNodeList->nextNode;
	}
	printf("\n");
}

/*
 * =============== METHOD FUNCTION DEFINITIONS
 */

MethodNode * createMethodNode(char * idName, char * typeReturn, int arrayLevels){

	MethodNode * node = (MethodNode*) malloc(sizeof(MethodNode));

	if(node != NULL){

		// Allocate and copy the id char value
		node->idName = (char *) malloc(sizeof(char) * MAX_ID_SIZE);
		if(node->idName != NULL){
			strncpy(node->idName, idName, MAX_ID_SIZE);

			// Allocate and copy the typeval char value
			node->returnType = (char *) malloc(sizeof(char) * MAX_TYPEVAL_SIZE);
			if (node->returnType != NULL){
				strncpy(node->returnType, typeReturn, MAX_TYPEVAL_SIZE);
			}else{
				node = NULL;
			}

			node->arrayLevels = arrayLevels;
			node->labels = NULL;
			node->params = NULL;
			node->varNodes = NULL;
			node->next = NULL;
		}else{
			node = NULL;
		}
	}
	return node;
}

MethodNode * addParamInMethod(MethodNode * method, char * id, char * type, int arrayLevels){
	VarNode * params = method->params;
	if (params != NULL){
		while(params->nextNode != NULL){
			params = params->nextNode;
		}
		params->nextNode = createVarNode(id, type, NO, NO, arrayLevels);
	}else{
		method->params = createVarNode(id, type, NO, NO, arrayLevels);
	}
	return method;
}

MethodNode * getMethodNodeInList (MethodNode * nodeList, char * idName){
	MethodNode * method = nodeList;
	while(method != NULL){
		if (strcmp(method->idName, idName) == 0){
			break;
		}
		method = method->next;
	}
	return method;
}

MethodNode * getLastMethodNodeInList (MethodNode * methodList){
	MethodNode * method = methodList;
	if (method != NULL){
		while(method->next != NULL){
			method = method->next;
		}
	}
	return method;
}

void freeMethodList(MethodNode * list){
	MethodNode * listTmp = list;
	while(listTmp != NULL){
		list = listTmp;
		listTmp = listTmp->next;
		free(list->idName);
		free(list->returnType);
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
				if(strcmp(params->typeval, newParams->typeval) != 0
						|| params->arrayLevels != newParams->arrayLevels){
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
		if (result == YES && newParams != NULL){
			result = NO;
		}
	}else{
		result = NO;
	}
	return result;
}

void displayMethodNodeList(MethodNode * methodNodeList){
	while(methodNodeList != NULL){
		printf("Name: %s, Return Type: %s, ArrayLevels: %d\n", methodNodeList->idName, methodNodeList->returnType, methodNodeList->arrayLevels);
		printf("===> params:\n");
		displayVarNodeList(methodNodeList->params);
		printf("===> local vars:\n");
		displayVarNodeList(methodNodeList->varNodes);

		methodNodeList = methodNodeList->next;
	}
}


LabelStruct * createLabel(char * name){
	LabelStruct * label = (LabelStruct *) malloc(sizeof(LabelStruct));

	if (label != NULL){
		label->name = (char *) malloc(MAX_ID_SIZE);
		strncpy(label->name, name, MAX_ID_SIZE);
		label->next = NULL;
	}
	return label;
}

