#include <stdio.h>
#include <stdlib.h>

#include "ClassContext.h"

int main(){

	setCurrentContext(GLOBAL_CONTEXT);

	createClassContext("Classe A");

	insertStringToStrList("a");
	insertStringToStrList("b");
	insertStringToStrList("c");

	insertVarListInGlobalContext("STRING", NO);

	insertMethod("MethodA", "INT");
	checkEqualMethodSignature();

	setCurrentContext(LOCAL_CONTEXT);

		insertStringToStrList("d");
		insertVarListInCurrMethodContext("DOUBLE", 0);

	setCurrentContext(GLOBAL_CONTEXT);

	insertMethod("MethodB", "INT");
	checkEqualMethodSignature();

	insertMethod("MethodC", "INT");

	addParamInCurrMethod("Param1", "LONG");
	addParamInCurrMethod("Param2", "LONG");
	addParamInCurrMethod("Param3", "LONG");

	checkEqualMethodSignature();

	setCurrentContext(LOCAL_CONTEXT);

		insertStringToStrList("d");
		insertStringToStrList("e");
		insertStringToStrList("f");

		insertVarListInCurrMethodContext("FLOAT", 1);

	displayClassContext();

	freeClassContext();

	return 0;
}

int yyerror(char *msg){
	fprintf(stderr,"%s\n",msg);
//	exit(1);

	return 1;
}
