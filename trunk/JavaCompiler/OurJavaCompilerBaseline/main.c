#include <stdio.h>
#include <stdlib.h>

#include "ClassContext.h"

int main(){

	setCurrentContext(GLOBAL_CONTEXT);

	createClassContext("Classe A");

	insertStringToStrList("a", GLOBAL_CONTEXT);
	insertStringToStrList("b", GLOBAL_CONTEXT);
	insertStringToStrList("c", GLOBAL_CONTEXT);

	insertVarListInGlobalContext("STRING", NO, GLOBAL_CONTEXT);

	setCurrentContext(LOCAL_CONTEXT);

	insertMethod("MethodA", "INT");

	insertStringToStrList("d", LOCAL_CONTEXT);
	insertVarListInCurrMethodContext("DOUBLE", 0);

	insertMethod("MethodB", "INT");
	insertMethod("MethodC", "INT");

	addParamInCurrMethod("Param1", "LONG");
	addParamInCurrMethod("Param1", "LONG");
	addParamInCurrMethod("Param2", "LONG");

	finishCurrMethodSignCreation();

	insertStringToStrList("d", LOCAL_CONTEXT);
	insertStringToStrList("e", LOCAL_CONTEXT);
	insertStringToStrList("f", LOCAL_CONTEXT);

	insertVarListInCurrMethodContext("FLOAT", 1);

	//  Add called method
	//	addCalledMethod("MethodC", "INT");
	//	addArgsToCurrCalledMethod("OPA", "LONG");
	//	addArgsToCurrCalledMethod("OPA", "LONg");
	//	setLineCollumnOfCalledMethod(1,2);

	//	checkCalledAndRealMethodsCorrespondence();

	displayClassContext();

	freeClassContext();

	return 0;
}

int yyerror(char *msg){
	fprintf(stderr,"%s\n",msg);
//	exit(1);

	return 1;
}
