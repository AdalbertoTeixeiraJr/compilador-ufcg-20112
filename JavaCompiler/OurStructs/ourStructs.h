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
#define CLASS_CONTEXT_CREATION_ERROR_INSUFFICIENT_MEMORY	-1
#define CONTEXT_ID_ALREADY_EXISTS							-2
#define MALLOC_ERROR_INSUFFICIENT_MEMORY					-3
#define INEXISTANT_ID_IN_CONTEXT							-4


/*****************************************************/
/***************** STRUCT DECLARATIONS ***************/
/*****************************************************/

/*
 * VARSCONTEXT STRUCTS
 */

typedef struct VAR_NODE VarNode;
struct VAR_NODE{
	char * id;
	char * typeval;
	int isFinal;
	VarNode *nextNode;
};

typedef struct STR_NODE StrNode;
struct STR_NODE{
	char* str;
	StrNode * next;
};

/*
 * METHOD STRUCTS
 */
typedef struct METHOD_NODE MethodNode;
struct METHOD_NODE{
	char * idName;
	char * typeReturn;
	VarNode *varNodes;
	MethodNode * nextMethod;
};

typedef struct METHOD_CONTEXT VarsContext;
struct VARS_CONTEXT{
	int listLength;
	MethodNode * methodListStart;
};

/*
 * CLASSCONTEXT STRUCT
 */
typedef struct CLASS_CONTEXT ClassContext;
struct CLASS_CONTEXT{
	char* name;
	VarNode * varsContext;
	MethodNode * methodContext;
};

/*
 * EXISTE UM CLASS CONTEXT QUE TEM :
 * * UM NOME
 * * UM PONTEIRO PARA UMA LISTA DE VAR_NODES
 * * OUTRO PARA UMA LISTA DE METHOD_NODES
 *
 * EXISTE UM VAR NODE QUE TEM:
 * * ID
 * * TIPO
 * * IS FINAL
 * * O PROXIMO VAR NODE
 *
 * EXISTE UM METHOD NODE QUE TEM:
 * * ID_NAME
 * * TIPO_RETORNO
 * * UMA LISTA DE VAR_NODES
 *
 * TODOS OS ALGORITMOS ITERAM COMPLETAMENTE NA LISTA ATEH ENCONTRAREM UM NULL
 *
TODO: O DISPLAY DEVE MOSTRAR SE A VARIAVEL EH FINAL OU NAO

 */

/*****************************************************/
/*************** FUNCTION DECLARATIONS ***************/
/*****************************************************/

/*************** CLASSCONTEXT FUNCTIONS ***************/
//// CREATING
int createClassContext(char * className);
//// INSERTING
int insertVarListInClassContext(char * typeval, int isFinal);
int insertMethodInClassContext(char * idName, char * typeReturn);
//// CHECKING
int hasVarIdInClassContext(char * id);
int isVarFinalInClassContext(char * id);
//// GETTING
char * getTypevalInClassContext (char * id);
//// FREEING
void freeClassContext();
//// DISPLAYING
void displayClassContext();


/*************** STRING NODE FUNCTIONS ***************/
//// INSERTING
int insertStringToStrList(char * id);

/*************** METHODNODE FUNCTIONS ***************/
/*************** METHODCONTEXT FUNCTIONS ***************/


#endif /* OURSTRUCTS_H_ */
