#include <stdio.h>

#include "ClassContext.h"

int main(){

	setCurrentContext(CLASS_CONTEXT);

	if (createClassContext("Classe A") != OK){
		printf("Error 1!\n");
	}


	if (insertStringToStrList("a") != OK){
		printf("Error 2!\n");
	}
	if (insertStringToStrList("b") != OK){
		printf("Error 3!\n");
	}
	if (insertStringToStrList("c") != OK){
		printf("Error 4!\n");
	}


	if (insertVarListInGlobalContext("STRING", NO) != OK){
		printf("Error 5!\n");
	}

	setCurrentContext(METHOD_CONTEXT);

	if(insertMethod("MethodA", "INT") != OK){
		printf("Error 6!\n");
	}
	if (insertStringToStrList("d") != OK){
		printf("Error 7!\n");
	}
	insertVarListInCurrMethodContext("DOUBLE", 0);


	if(insertMethod("MethodB", "INT") != OK){
		printf("Error 8!\n");
	}
	if(insertMethod("MethodC", "INT") != OK){
		printf("Error 9!\n");
	}

	if(addParamInCurrMethod("Param1", "LONG") != OK){
		printf("Error 10!\n");
	}
	if(addParamInCurrMethod("Param1", "LONG") != OK){
		printf("Error 11!\n");
	}
	if(addParamInCurrMethod("Param2", "LONG") != OK){
		printf("Error 12!\n");
	}

	if (finishCurrMethodSignCreation() != OK){
		printf("Error 13!\n");
	}

	if (insertStringToStrList("d") != OK){
		printf("Error 14!\n");
	}
	if (insertStringToStrList("e") != OK){
		printf("Error 15!\n");
	}
	if (insertStringToStrList("f") != OK){
		printf("Error 16!\n");
	}

	insertVarListInCurrMethodContext("FLOAT", 1);

	displayClassContext();

	freeClassContext();

	return 0;
}

int yyerror(char *msg){
	fprintf(stderr,"%s\n",msg);
	return 1;
}
