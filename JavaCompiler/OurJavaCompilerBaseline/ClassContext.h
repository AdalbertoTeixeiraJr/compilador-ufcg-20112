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

////GETTING
char * getVarTypevalInGlobalContext (char * id);
char * getVarTypevalInMethodContext (char * id);
char * getVarTypevalInMethodContext (char * id);
int getVarArrayLevelInGlobalContext (char * id);
int getVarArrayLevelInBothContexts (char * id);
char * getVarTypevalInBothContexts (char * id);
int isVarFinalInGlobalContext(char * id);
int isVarFinalInCurrMethodContext(char * id);
int isVarFinalInBothContexts(char * id);
int isParamInCurrMethodContext(char * id);

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

/*************** LABEL FUNCTIONS ***************/
void addLabel(char * name);
void checkLabelInCurrMethod(char * name);

/*************** SEMANTIC CHECK FUNCTIONS ***************/
void checkStaticClassId(char * id);
void checkRepeatedCurrentMethodSignature();
void checkEqualsArrayLevel(int declarationLevel, int definitionLevel);
void checkEqualsTypeval(char * declarationType, char * definitionType);
void checkIsBoolean(char * type);
void checkIncrementDecrement(char * varType, char * operType, int isFinal);
int checkNumericalType(char * type);

void checkAssignConversion(char * typeFrom, char * typeTo);
void checkCastingConversion(char * actualType, char * castType);
char * checkMethodConversion();
int checkMethodLevelsAfterConversion();
void checkArrayCreationExpression(char * type);
void checkIsEmptyOrBool(char* typeval);
void checkIsSwitchExpression(char* typeval);
void checkReturnTypeAndLevelInCurrMethod(char * returnedType, int returnedLevel);
void checkHasReturn(int hasReturn);
void checkFinalUpdate(int finalUpdate);

// BINARY COMPARISONS
char * checkBinaryExpressionResultType(char * leftType, char * rightType);
char * checkShiftOperator(char * leftType, char * shiftDistanceType);
char * checkEqualityOperator(char * leftType, char * rightType);
char * checkBitwiseLogicalOperator(char * leftType, char * rightType);
char * checkConditionalAndOrOperator(char * leftType, char * rightType);
char * checkRelationalOperator(char * leftType, char * rightType);
char * checkQuestionMarkOperator(char * leftType, char * rightType);

// AUXILIAR OPERATOR CHOOSER
char * chooseBinaryOperation(char * leftType, char * rightType, char * oper);

#endif /* CLASSCONTEXT_H_ */
