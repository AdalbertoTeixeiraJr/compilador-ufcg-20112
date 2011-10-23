#include <stdio.h>
#include <stdlib.h>

#include "ClassContext.h"

int main(){

	setCurrentContext(GLOBAL_CONTEXT);

	createClassContext("Classe A");

	insertStringToStrList("a");
	insertStringToStrList("b");
	insertStringToStrList("c");

	insertVarListInGlobalContext("STRING", NO, 0);

	insertMethod("MethodA", "INT", 0);
	addParamInCurrMethod("Param1", "LONG", 0);
	addParamInCurrMethod("Param2", "LONG", 0);
	addParamInCurrMethod("Param3", "LONG", 0);

	checkEqualityCurrentMethodSignature();

	setCurrentContext(LOCAL_CONTEXT);

		insertStringToStrList("d");
		insertVarListInCurrMethodContext("DOUBLE", NO, 0);

	setCurrentContext(GLOBAL_CONTEXT);

	insertMethod("MethodB", "INT", 0);
	checkEqualityCurrentMethodSignature();

	insertMethod("MethodC", "INT", 0);

	addParamInCurrMethod("Param1", "LONG", 0);
	addParamInCurrMethod("Param2", "LONG", 0);
	addParamInCurrMethod("Param3", "LONG", 0);

	checkEqualityCurrentMethodSignature();

	setCurrentContext(LOCAL_CONTEXT);

		insertStringToStrList("d");
		insertStringToStrList("e");
		insertStringToStrList("f");

		insertVarListInCurrMethodContext("FLOAT", YES, 1);

		checkEqualityArrayLevel(1, 2);
		checkEqualityTypeval("CHAR", "CHAR");

	displayClassContext();

	printf("Tipo de A na Classe: %s\n", getVarTypevalInGlobalContext ("a"));
	printf("ArrayLevel de A na Classe: %d\n", getVarArrayLevelInGlobalContext("a"));

	addCalledMethod("MethodB");
	addArgsToCalledMethod("LONG", 0);
	addArgsToCalledMethod("LONG", 0);
	addArgsToCalledMethod("LONG", 0);
	finishCalledMethod();

	freeClassContext();

	return 0;
}

int yyerror(char *msg){
	fprintf(stderr,"%s\n",msg);
//	exit(1);

	return 1;
}
