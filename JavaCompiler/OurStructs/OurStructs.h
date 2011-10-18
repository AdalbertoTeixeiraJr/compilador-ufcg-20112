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

// ERROR TYPE CONSTANTS
#define CLASS_CONTEXT_CREATION_ERROR_INSUFFICIENT_MEMORY	-1
#define ID_ALREADY_EXISTS									-2
#define MALLOC_ERROR_INSUFFICIENT_MEMORY					-3
#define INEXISTANT_ID_IN_CONTEXT							-4

/****************** STRUCT DEFINITIONS *****************/

/*
 * VARNODE STRUCT
 */
typedef struct VAR_NODE VarNode;
struct VAR_NODE{
	char * id;
	char * typeval;
	int isFinal;
	VarNode *nextNode;
};

/*
 * METHOD STRUCT
 */
typedef struct METHOD_NODE MethodNode;
struct METHOD_NODE{
	char * idName;
	char * typeReturn;
	VarNode *varNodes;
	MethodNode * nextMethod;
};

/*
 * STR STRUCT
 */
typedef struct STR_NODE StrNode;
struct STR_NODE{
	char* str;
	StrNode * next;
};

/***************** FUNCTION DECLARATIONS *****************/

VarNode * createVarNode(char * id, char * typeval, int isFinal);
VarNode * insertVarInVarNodeList(VarNode * nodeList, char * id, char * typeval, int isFinal);
VarNode * getVarNodeInList (VarNode * nodeList, char * id);

MethodNode * createMethodNode(char * idName, char * typeReturn);
MethodNode * getMethodNodeInList (MethodNode * nodeList, char * idName);


#endif /* OURSTRUCTS_H_ */
