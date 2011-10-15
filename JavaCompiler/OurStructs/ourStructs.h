#ifndef OURSTRUCTS_H_
#define OURSTRUCTS_H_


/*****************************************************/
/**************** CONSTANT DEFINITIONS ***************/
/*****************************************************/

#define MAX_ID_SIZE 128
#define MAX_TYPEVAL_SIZE 20

#define OK	1

#define YES	1
#define NO	0

// ERROR TYPE CONSTANTS
#define VARS_CONTEXT_CREATION_ERROR_INSUFFICIENT_MEMORY	-1
#define CLASS_CONTEXT_ID_ALREADY_EXISTS					-2
#define MALLOC_ERROR_INSUFFICIENT_MEMORY				-3
#define INEXISTANT_ID_IN_CONTEXT						-4


/*****************************************************/
/***************** STRUCT DECLARATIONS ***************/
/*****************************************************/

typedef struct VAR_NODE varNode;
struct VAR_NODE{
	char * id;
	char * typeval;
	int isFinal;
	varNode *nextNode;
};

typedef struct VARS_CONTEXT VarsContext;
struct VARS_CONTEXT{
	char* name;
	int listLength;
	varNode * varListStart;
	varNode * varListEnd;
};

typedef struct STR_NODE StrNode;
struct STR_NODE{
	char* str;
	StrNode * next;
};

/*****************************************************/
/*************** FUNCTION DECLARATIONS ***************/
/*****************************************************/

/*************** VARSCONTEXT FUNCTIONS ***************/
//// CREATION
int createClassContext(char * className);
VarsContext * createBlockContext(char * name);
//// INSERTION
int addVarListInContext(VarsContext * context, StrNode * node, char * typeval, int isFinal);
//// CHECKING
int hasIdInContextList(VarsContext * context, char * id);
int isVarFinal(VarsContext * context, char * id);
//// GETTING
VarsContext * getClassContext();
char * getTypevalInContextList (VarsContext * context, char * id);
//// FREEING
void freeContext(VarsContext * context);
//// DISPLAYING
void displayVar(VarsContext * context, char * id);
void displayAllVarsOfContext(VarsContext * context);

/*************** STRING NODE FUNCTIONS ***************/
StrNode * createStrNode();
int addStringToNode(VarsContext * context, StrNode * firstNode, char * id);

#endif /* OURSTRUCTS_H_ */
