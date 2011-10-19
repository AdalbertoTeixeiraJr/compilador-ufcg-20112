/*
 ============================================================================
 Name        : OurStructs.c
 Author      : Andrey Menezes, Adalberto Teixeira e Augusto Queiroz
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

#ifndef CLASSCONTEXT_H_
#define CLASSCONTEXT_H_

#include "OurStructs.h"

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
int insertVarListInGlobalContext(char * typeval, int isFinal);
int insertMethod(char * idName, char * typeReturn);

//// CHECKING
int isVarFinalInGlobalContext(char * id);

//// GETTING
MethodNode * getMethod(char * idName);
VarNode * getVarInGlobalContext(char * id);
char * getVarTypevalInGlobalContext (char * id);

//// FREEING
void freeClassContext();

//// DISPLAYING
void displayClassContext();


/***************** METHOD FUNCTIONS ******************/
int insertVarListInCurrMethodContext(char * typeval, int isFinal);

//TODO!
int isVarFinalInMethodContext(char * id);
VarNode * getVarInMethodContext(char * id);
char * getVarTypevalInMethodContext (char * id);

/*************** STRING NODE FUNCTIONS ***************/
//// INSERTING
int insertStringToStrList(char * id);

#endif /* CLASSCONTEXT_H_ */
