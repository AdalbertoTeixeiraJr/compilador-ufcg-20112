/*
 ============================================================================
 Name        : ClassContext.h
 Author      : Andrey Menezes, Adalberto Teixeira e Augusto Queiroz
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#ifndef CLASSCONTEXT_H_
#define CLASSCONTEXT_H_

#include "OurStructs.h"

#define CHECK_RESULT(id) treatErrorResults(id)

#define CHECK_GLOBAL_CONTEXT(context) if(context != GLOBAL_CONTEXT) return;
#define CHECK_LOCAL_CONTEXT(context) if(context != LOCAL_CONTEXT) return;

/*
 * CLASSCONTEXT STRUCT
 */
typedef struct CLASSCONTEXT ClassContext;
struct CLASSCONTEXT{
	char* name;
	VarNode * varsContext;
	MethodNode * methodContext;
};

/*
 * AUXILIAR TYPE STRUCT
 */
typedef struct TYPESTRUCT TypeStruct;
struct TYPESTRUCT{
	char* streval;
	char* typeval;
	int isFinal;
	int levels;
};

/*****************************************************/
/*************** FUNCTION DECLARATIONS ***************/
/*****************************************************/
void setCurrentContext(int context);

//// CREATING
void createClassContext(char * className);

//// INSERTING
void insertVarListInGlobalContext(char * typeval, int isFinal, int arrayLevels);
void insertMethod(char * idName, char * typeReturn, int arrayLevels);
void addParamInCurrMethod(char * id, char * typeval, int arrayLevels);
void insertVarListInCurrMethodContext(char * typeval, int isFinal, int arrayLevels);

////GETTING
char * getVarTypevalInGlobalContext (char * id);
int getVarArrayLevelInGlobalContext (char * id);

//// FREEING
void freeClassContext();

//// DISPLAYING
void displayClassContext();

/*************** STRING NODE FUNCTIONS ***************/
//// INSERTING
void insertStringToStrList(char * id);

/*************** CALLED METHODS FUNCTIONS ***************/
void addCalledMethod(char * idName);
void addArgsToCalledMethod(char * typeval, int arrayLevels);

/*************** SEMANTIC CHECK FUNCTIONS ***************/
void checkStaticClassId(char * id);
void checkEqualityCurrentMethodSignature();
void checkEqualityArrayLevel(int declarationLevel, int definitionLevel);
void checkEqualityTypeval(char * declarationType, char * definitionType);

void checkAssignmentConversion(char * actualType, char * assignType);
void checkCastingConversion(char * actualType, char * castType);
char * checkMethodConversion();

/*************** SEMANTIC CHECK FUNCTIONS ***************/

TypeStruct * createTypeStruct();

#endif /* CLASSCONTEXT_H_ */
