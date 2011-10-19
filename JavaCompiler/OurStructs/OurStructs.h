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


/**************** CONSTANT DEFINITIONS ***************/

#define MAX_ID_SIZE 128
#define MAX_TYPEVAL_SIZE 20

#define OK	1

#define YES	1
#define NO	0

#define METHOD_CONTEXT	10
#define CLASS_CONTEXT	20

// ERROR TYPE CONSTANTS
#define CLASS_CONTEXT_CREATION_ERROR_INSUFFICIENT_MEMORY	-1
#define ID_ALREADY_EXISTS									-2
#define MALLOC_ERROR_INSUFFICIENT_MEMORY					-3
#define INEXISTANT_ID_IN_CONTEXT							-4

/****************** STRUCT DEFINITIONS *****************/

/*
 * VARNODE STRUCT
 */
typedef struct VARNODE VarNode;
struct VARNODE{
	char * id;
	char * typeval;
	int isFinal;
	VarNode *nextNode;
};

/*
 * METHOD STRUCT
 */
typedef struct METHODNODE MethodNode;
struct METHODNODE{
	char * idName;
	char * typeReturn;
	VarNode *varNodes;
	MethodNode * nextMethod;
};

/*
 * STR STRUCT
 */
typedef struct STRNODE StrNode;
struct STRNODE{
	char* str;
	StrNode * next;
};

/***************** FUNCTION DECLARATIONS *****************/

VarNode * createVarNode(char * id, char * typeval, int isFinal);
VarNode * insertVarInVarNodeList(VarNode * nodeList, char * id, char * typeval, int isFinal);
VarNode * getVarNodeInList (VarNode * nodeList, char * id);
void freeVarNodeList(VarNode * list);
void displayVarNodeList(VarNode * list);

MethodNode * createMethodNode(char * idName, char * typeReturn);
MethodNode * getMethodNodeInList (MethodNode * nodeList, char * idName);
void freeMethodList(MethodNode * list);
void displayMethodNodeList(MethodNode * list);

#endif /* OURSTRUCTS_H_ */
