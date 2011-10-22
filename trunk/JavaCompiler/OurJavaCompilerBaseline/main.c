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

	checkEqualMethodSignature();

	setCurrentContext(LOCAL_CONTEXT);

		insertStringToStrList("d");
		insertVarListInCurrMethodContext("DOUBLE", NO, 0);

	setCurrentContext(GLOBAL_CONTEXT);

	insertMethod("MethodB", "INT", 0);
	checkEqualMethodSignature();

	insertMethod("MethodC", "INT", 0);

	addParamInCurrMethod("Param1", "LONG", 0);
	addParamInCurrMethod("Param2", "LONG", 0);
	addParamInCurrMethod("Param3", "LONG", 0);

	checkEqualMethodSignature();

	setCurrentContext(LOCAL_CONTEXT);

		insertStringToStrList("d");
		insertStringToStrList("e");
		insertStringToStrList("f");

		insertVarListInCurrMethodContext("FLOAT", YES, 0);

	displayClassContext();

	freeClassContext();

	return 0;
}

int yyerror(char *msg){
	fprintf(stderr,"%s\n",msg);
//	exit(1);

	return 1;
}
