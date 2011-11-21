#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ClassContext.h"

int main(){

	setCurrentContext(GLOBAL_CONTEXT);

	createClassContext("Classe A");

	insertStringToStrList("a",NO);
	insertStringToStrList("b",NO);
	insertStringToStrList("c",NO);

	insertVarListInGlobalContext("STRING", NO, 0);

	insertMethod("MethodA", "t_long", 0);
	addParamInCurrMethod("Param1", "t_long", 0);
	addParamInCurrMethod("Param2", "t_long", 0);
	addParamInCurrMethod("Param3", "t_long", 0);

	checkRepeatedCurrentMethodSignature();

	setCurrentContext(LOCAL_CONTEXT);

		insertStringToStrList("d",NO);
		insertStringToStrList("e",YES);
		insertStringToStrList("Param1", NO);
		insertStringToStrList("g",YES);
		insertStringToStrList("y",YES);
		insertStringToStrList("1",YES);
		insertStringToStrList("8",YES);
		insertStringToStrList("e",YES);
		insertStringToStrList("s",YES);
		insertStringToStrList("a",YES);
		insertStringToStrList("yx",NO);
		insertStringToStrList("1xxx",NO);
		insertStringToStrList("8alkl",NO);
		insertVarListInCurrMethodContext("DOUBLE", NO, 0);

		addLabel("01");
		addLabel("02");
		addLabel("03");

		checkLabelInCurrMethod("01");
		checkLabelInCurrMethod("02");
		checkLabelInCurrMethod("03");

	setCurrentContext(GLOBAL_CONTEXT);

	insertMethod("MethodB", "INT", 0);
	checkRepeatedCurrentMethodSignature();

	insertMethod("MethodC", "t_int", 0);

	addParamInCurrMethod("Param1", "t_int", 0);
	addParamInCurrMethod("Param2", "t_int", 0);

	checkRepeatedCurrentMethodSignature();

	setCurrentContext(LOCAL_CONTEXT);

		insertStringToStrList("d",NO);
		insertStringToStrList("e",NO);
		insertStringToStrList("f",NO);
		insertStringToStrList("g",NO);
		insertStringToStrList("y",NO);
		insertStringToStrList("1",YES);
		insertStringToStrList("8",YES);

		insertVarListInCurrMethodContext("FLOAT", YES, 1);

		checkEqualsArrayLevel(1, 2);
		checkEqualsTypeval("CHAR", "CHAR");

	checkReturnTypeAndLevelInCurrMethod("t_string", 0);
	checkReturnTypeAndLevelInCurrMethod("t_double", 0);
	checkReturnTypeAndLevelInCurrMethod("t_short", 0);
	checkReturnTypeAndLevelInCurrMethod("t_int", 1);
	checkReturnTypeAndLevelInCurrMethod("t_long", 0);

	checkHasReturn(NO);

	displayClassContext();

	printf("Tipo de A na Classe: %s\n", getVarTypevalInGlobalContext ("a"));
	printf("ArrayLevel de A na Classe: %d\n", getVarArrayLevelInGlobalContext("a"));

	addCalledMethod("MethodA");
	addArgsToCalledMethod("t_int", 0);
	addArgsToCalledMethod("t_int", 0);
	addArgsToCalledMethod("t_int", 0);
	checkMethodConversion();

	checkIsBoolean(NULL);

	checkIncrementDecrement("t_string", "t_int", NO);

	checkBinaryExpressionResultType("t_short", "t_string");
	checkShiftOperator("t_short", "t_string");

	freeClassContext();

	return 0;
}

int yyerror(char *msg){
	fprintf(stderr,"%s\n",msg);
//	exit(1);

	return 1;
}
