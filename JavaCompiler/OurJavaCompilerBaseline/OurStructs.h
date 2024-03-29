/*
 ============================================================================
 Name        : OurStructs.c
 Author      : Andrey Menezes, Adalberto Teixeira e Augusto Queiroz
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#ifndef OURSTRUCTS_H_
#define OURSTRUCTS_H_

#include "OurConstants.h"

/****************** STRUCT DEFINITIONS *****************/

/*
 * VARNODE STRUCT
 */
typedef struct VARNODE VarNode;
struct VARNODE{
	char * id;
	char * typeval;
	int isFinal;
	int wasUpdated;
	int arrayLevels;
	VarNode *nextNode;
};

/*
 * LABEL STRUCT
 */
typedef struct LABELSTRUCT LabelStruct;
struct LABELSTRUCT{
	char* name;
	LabelStruct * next;
};


/*
 * METHOD STRUCT
 */
typedef struct METHODNODE MethodNode;
struct METHODNODE{
	char * idName;
	char * returnType;
	int arrayLevels;
	LabelStruct * labels;
	VarNode * params;
	VarNode * varNodes;
	MethodNode * next;
};

/*
 * STR STRUCT
 */
typedef struct STRNODE StrNode;
struct STRNODE{
	char* str;
	int wasUpdated;
	StrNode * next;
};

/***************** FUNCTION DECLARATIONS *****************/

VarNode * createVarNode(char * id, char * typeval, int wasUpdated, int isFinal, int arrayLevels);
VarNode * insertVarInVarNodeList(VarNode * nodeList, char * id, int wasUpdated, char * typeval, int isFinal, int arrayLevels);
VarNode * getVarNodeInList (VarNode * nodeList, char * id);
void freeVarNodeList(VarNode * list);
void displayVarNodeList(VarNode * list);
int isVarNodeEqual(VarNode * var, char * newId);

MethodNode * createMethodNode(char * idName, char * typeReturn, int arrayLevels);
MethodNode * addParamInMethod(MethodNode * method, char * id, char * typeval, int arrayLevels);
MethodNode * getMethodNodeInList (MethodNode * nodeList, char * idName);
MethodNode * getLastMethodNodeInList (MethodNode * nodeList);
void freeMethodList(MethodNode * list);
void displayMethodNodeList(MethodNode * list);
int isMethodEqual(MethodNode * method1, MethodNode * method2);

LabelStruct * createLabel(char * name);

#endif /* OURSTRUCTS_H_ */
