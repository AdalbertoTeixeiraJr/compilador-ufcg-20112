#ifndef OURSTRUCTS_H_
#define OURSTRUCTS_H_

/*
 * CONSTANT DEFINITIONS
 */
#define MAX_ID_SIZE 128
#define MAX_TYPEVAL_SIZE 20

#define OK	1

#define YES	1
#define NO	0

// ERROR TYPE CONSTANTS
#define VARS_CONTEXT_CREATION_ERROR_INSUFFICIENT_MEMORY	-1
#define CLASS_CONTEXT_ID_ALREADY_EXISTS					-2
#define MALLOC_ERROR_INSUFFICIENT_MEMORY				-3

/*
 * STRUCT DECLARATIONS
 */

typedef struct VAR_NODE varNode;
struct VAR_NODE{
	char* id;
	char* typeval;
	varNode *nextNode;
};


typedef struct VARS_CONTEXT VarsContext;
struct VARS_CONTEXT{
	char* name;
	int listLength;
	varNode * varListStart;
	varNode * varListEnd;
};

/*
 * FUNCTION DECLARATIONS
 */
// CLASS CONTEXT SPECIFIC FUNCTIONS
int createClassContext(char * className);
VarsContext * getClassContext();

// BLOCK CONTEXT FUNCTIONS
VarsContext * createBlockContext(char * name);

/*
 * CONTEXT VAR LIST FUNCTIONS
 */

VarsContext * createContext(char * name);
int addVarInContext(VarsContext * context, char * id, char * typeval);
int hasIdInContextList(VarsContext * context, char * id);
char * getTypevalInContextList (VarsContext * context, char * id);
void freeContext(VarsContext * context);
void displayValuesByNode(VarsContext * context, char * id);

#endif /* OURSTRUCTS_H_ */
