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

/*************** CLASSCONTEXT FUNCTIONS ***************/
//// CREATING
int createClassContext(char * className);

//// INSERTING
int insertVarListInGlobalContext(char * typeval, int isFinal); //, int arrayLevels
int insertMethod(char * idName, char * typeReturn); //, int arrayLevels

//// GETTING
MethodNode * getMethod(char * idName);
VarNode * getVarInGlobalContext(char * id);
char * getVarTypevalInGlobalContext (char * id);

//// FREEING
void freeClassContext();

//// DISPLAYING
void displayClassContext();

/***************** METHOD FUNCTIONS ******************/
//// INSERTING
int addParamInCurrMethod(char * id, char * typeval);//, int arrayLevels
int finishCurrMethodSignCreation();
int insertVarListInCurrMethodContext(char * typeval, int isFinal);//, int arrayLevels

//// GETTING
VarNode * getVarInCurrMethodContext(char * id);
char * getVarTypevalInCurrMethodContext (char * id);

/*************** CALLED METHODS FUNCTIONS ***************/
int addCalledMethod(char * idName, char * typeReturn);//, int arrayLevels
int addArgsToCurrCalledMethod(char * id, char * typeval); //, int arrayLevels
int setLineCollumnOfCalledMethod(int line, int collumn);
void freeCalledMethodList();

/*************** STRING NODE FUNCTIONS ***************/
//// INSERTING
int insertStringToStrList(char * id);

/*************** SEMANTIC CHECK FUNCTIONS ***************/
void checkStaticClassId(char * id);
int checkCalledAndRealMethodsCorrespondence();

// NOT USED EXTERNALLY
int isVarFinalInGlobalContext(char * id);
int isVarFinalInCurrMethodContext(char * id);

#endif /* CLASSCONTEXT_H_ */
