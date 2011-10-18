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
typedef struct CLASS_CONTEXT ClassContext;
struct CLASS_CONTEXT{
	char* name;
	VarNode * varsContext;
	MethodNode * methodContext;
};

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
int isVarFinalInClassContext(char * id);
//// GETTING
MethodNode * getMethodInClassContext(char * idName);
VarNode * getVarInClassContext(char * id);
char * getVarTypevalInClassContext (char * id);
//// FREEING
void freeClassContext();
//// DISPLAYING
void displayClassContext();


/*************** STRING NODE FUNCTIONS ***************/
//// INSERTING
int insertStringToStrList(char * id);

#endif /* CLASSCONTEXT_H_ */
