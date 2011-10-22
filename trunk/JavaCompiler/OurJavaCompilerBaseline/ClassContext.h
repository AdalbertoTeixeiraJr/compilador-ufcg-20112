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

//// FREEING
void freeClassContext();

//// DISPLAYING
void displayClassContext();

/*************** STRING NODE FUNCTIONS ***************/
//// INSERTING
void insertStringToStrList(char * id);

/*************** SEMANTIC CHECK FUNCTIONS ***************/
void checkStaticClassId(char * id);
void checkEqualMethodSignature();
void checkEqualityArrayLevel(int declaredLevel, int definedLevel);

#endif /* CLASSCONTEXT_H_ */
