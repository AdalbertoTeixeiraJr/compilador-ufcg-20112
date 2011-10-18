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
		}else{
			node = NULL;
		}
	}
	return node;
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
