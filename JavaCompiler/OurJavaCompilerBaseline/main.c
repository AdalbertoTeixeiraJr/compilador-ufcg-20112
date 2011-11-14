#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ClassContext.h"

int main(){

	setCurrentContext(GLOBAL_CONTEXT);

	createClassContext("Classe A");

	insertStringToStrList("a");
	insertStringToStrList("b");
	insertStringToStrList("c");

	insertVarListInGlobalContext("STRING", NO, 0);

	insertMethod("MethodA", "t_long", 0);
	addParamInCurrMethod("Param1", "t_long", 0);
	addParamInCurrMethod("Param2", "t_long", 0);
	addParamInCurrMethod("Param3", "t_long", 0);

	checkRepeatedCurrentMethodSignature();

	setCurrentContext(LOCAL_CONTEXT);

		insertStringToStrList("d");
		insertStringToStrList("e");
		insertStringToStrList("Param1");
		insertStringToStrList("g");
		insertStringToStrList("y");
		insertStringToStrList("1");
		insertStringToStrList("8");
		insertStringToStrList("e");
		insertStringToStrList("s");
		insertStringToStrList("a");
		insertStringToStrList("yx");
		insertStringToStrList("1xxx");
		insertStringToStrList("8alkl");
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

		insertStringToStrList("d");
		insertStringToStrList("e");
		insertStringToStrList("f");
		insertStringToStrList("g");
		insertStringToStrList("y");
		insertStringToStrList("1");
		insertStringToStrList("8");

		insertVarListInCurrMethodContext("FLOAT", YES, 1);

		checkEqualsArrayLevel(1, 2);
		checkEqualsTypeval("CHAR", "CHAR");

	checkReturnTypeAndLevelInCurrMethod("t_string", 0);
	checkReturnTypeAndLevelInCurrMethod("t_double", 0);
	checkReturnTypeAndLevelInCurrMethod("t_short", 0);
	checkReturnTypeAndLevelInCurrMethod("t_int", 1);
	checkReturnTypeAndLevelInCurrMethod("t_long", 0);

	checkHasReturnType(NO);

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
